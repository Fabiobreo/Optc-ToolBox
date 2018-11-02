#include <filterWidget.h>
#include "ui_filterWidget.h"
#include <conditionWidget.h>
#include <QTabWidget>

FilterWidget::FilterWidget(Utility* _utility, QWidget *_parent) :
    QWidget(_parent),
    ui(new Ui::FilterWidget),
    utility(_utility)
{
    ui->setupUi(this);
    buttonStyleSheet = "color: #333; border: 2px solid #555; border-radius: 10px; border-style: outset; background: qradialgradient( cx: 0.3, cy: -0.4, fx: 0.3, fy: -0.4, radius: 1.35, stop: 0 #ffffff, stop: 1 #bbb); font: 12pt; Text-align: bottom;";
    buttonSize = QSize(20, 20);

    ui->addConditionButton->setStyleSheet(buttonStyleSheet);
    ui->addConditionButton->setMinimumSize(buttonSize);
    ui->addConditionButton->setMaximumSize(buttonSize);
    connect(ui->addConditionButton, SIGNAL(pressed()), this, SLOT(addCondition()));

    ConditionWidget* conditionWidget = new ConditionWidget(_utility, this);
    ui->filterLayout->addWidget(conditionWidget, 0, 0, 1, 1);

    ui->addConditionButton->pressed();
}

FilterWidget::~FilterWidget()
{
    int i = 0;
    for (; ; ++i)
    {
        QLayoutItem* widgetToRemove = ui->filterLayout->itemAtPosition(i, 0);
        QLayoutItem* buttonToRemove = ui->filterLayout->itemAtPosition(i, 1);

        if (widgetToRemove != nullptr)
        {
            QWidget* removeWidget = static_cast<QWidget*>(widgetToRemove->widget());
            ui->filterLayout->removeWidget(removeWidget);
            delete removeWidget;
        }

        if (buttonToRemove != nullptr)
        {
            QWidget* removeButton = static_cast<QWidget*>(buttonToRemove->widget());
            ui->filterLayout->removeWidget(removeButton);
            delete removeButton;
        }

        if (widgetToRemove == nullptr && buttonToRemove == nullptr)
        {
            break;
        }
    }
    delete ui;
}

void FilterWidget::removeCondition()
{
    // Get row and column of clicked button
    int index = ui->filterLayout->indexOf(static_cast<QWidget*>(sender()));
    int row, column, rowSpan, columnSpan;
    ui->filterLayout->getItemPosition(index, &row, &column, &rowSpan, &columnSpan);

    // Remove condition
    QWidget* conditionToRemove = ui->filterLayout->itemAtPosition(row, 0)->widget();
    ui->filterLayout->removeWidget(conditionToRemove);
    delete conditionToRemove;

    // Remove clicked button
    QWidget* removeButtonToRemove = ui->filterLayout->itemAtPosition(row, column)->widget();
    ui->filterLayout->removeWidget(removeButtonToRemove);
    delete removeButtonToRemove;

    // Shift up the rest
    int i = row + 1;
    for (; ; ++i)
    {
        QLayoutItem* widgetToMove = ui->filterLayout->itemAtPosition(i, 0);
        QLayoutItem* buttonToMove = ui->filterLayout->itemAtPosition(i, 1);

        if (widgetToMove != nullptr)
        {
            QWidget* widgetToCopy = static_cast<QWidget*>(widgetToMove->widget());
            ui->filterLayout->addWidget(widgetToCopy, i - 1, 0, 1, 1);
        }

        if (buttonToMove != nullptr)
        {
            QPushButton* buttonToCopy = static_cast<QPushButton*>(buttonToMove->widget());
            ui->filterLayout->addWidget(buttonToCopy, i - 1, 1, 1, 1);
        }

        if (widgetToMove == nullptr && buttonToMove == nullptr)
        {
            break;
        }
    }
}

void FilterWidget::addCondition()
{
    // Get row and column of clicked button
    int index = ui->filterLayout->indexOf(static_cast<QWidget*>(sender()));
    int row, column, rowSpan, columnSpan;
    ui->filterLayout->getItemPosition(index, &row, &column, &rowSpan, &columnSpan);

    // Enable corresponding condition
    ConditionWidget* condition = static_cast<ConditionWidget*>(ui->filterLayout->itemAtPosition(row, 0)->widget());
    condition->enableWidget();

    // Remove clicked button
    QWidget* addButtonToRemove = ui->filterLayout->itemAtPosition(row, column)->widget();
    ui->filterLayout->removeWidget(addButtonToRemove);
    delete addButtonToRemove;

    // Add remove button
    QPushButton* removeButton = new QPushButton("-");
    removeButton->setStyleSheet(buttonStyleSheet);
    removeButton->setMinimumSize(buttonSize);
    removeButton->setMaximumSize(buttonSize);
    ui->filterLayout->addWidget(removeButton, row, column, 1, 1, Qt::AlignRight);
    connect(removeButton, SIGNAL(pressed()), this, SLOT(removeCondition()));

    // Get index of first free row
    int i = row + 1;
    for (; ; ++i)
    {
        QLayoutItem* item = ui->filterLayout->itemAtPosition(i, 0);

        if (item == nullptr)
        {
            break;
        }
    }

    // Shift elements between row and first free row down
    while (i > row + 1)
    {
        QLayoutItem* conditionToMove = ui->filterLayout->itemAtPosition(i - 1, 0);
        QWidget* conditionToCopy = conditionToMove->widget();
        ui->filterLayout->addWidget(conditionToCopy, i, 0, 1, 1);
        --i;
    }

    // Add new condition, not enabled
    ConditionWidget* conditionWidget = new ConditionWidget(utility, this);
    ui->filterLayout->addWidget(conditionWidget, row + 1, 0, 1, 1);

    // Add add button
    QPushButton* addButton = new QPushButton("+");
    addButton->setStyleSheet(buttonStyleSheet);
    addButton->setMinimumSize(buttonSize);
    addButton->setMaximumSize(buttonSize);
    ui->filterLayout->addWidget(addButton, row + 1, column, 1, 1, Qt::AlignRight);
    connect(addButton, SIGNAL(pressed()), this, SLOT(addCondition()));
}

void FilterWidget::on_addFilterButton_clicked()
{
    // Search first free row
    int i = 0;
    for (; ; ++i)
    {
        QLayoutItem* item = ui->filterLayout->itemAtPosition(i, 0);

        if (item == nullptr)
        {
            break;
        }
    }

    QTabWidget* tabWidget = qobject_cast<QTabWidget*>(ui->filterLayout->itemAtPosition(i - 1, 0)->widget());

    if (!tabWidget)
    {
        // Create tab widget
        tabWidget = new QTabWidget(this);
        tabWidget->setTabsClosable(true);
        connect(tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(removeTab(int)));
        ui->filterLayout->addWidget(tabWidget, i, 0, 1, 1);
    }

    // Add tab
    FilterWidget* filter = new FilterWidget(utility, this);
    tabWidget->addTab(filter, "Filter " + QString::number(tabWidget->count()));
}

void FilterWidget::removeTab(int _index)
{
    // Remove tab
    QTabWidget* tabWidget = static_cast<QTabWidget*>(sender());
    delete tabWidget->widget(_index);

    // Change other tabs name
    for (int i = _index; i <= tabWidget->count(); ++i)
    {
        tabWidget->setTabText(i, "Filter " + QString::number(i));
    }

    // Delete tab widget if there are no tab left
    if (tabWidget->count() == 0)
    {
        delete tabWidget;
    }
}


Filter FilterWidget::getFilter()
{
    Filter filter(utility);
    filter.setId("Advanced Filters");
    for (int i = 0; ; ++i)
    {
        QLayoutItem* item = ui->filterLayout->itemAtPosition(i, 0);
        if (item != nullptr)
        {
            ConditionWidget* conditionWidget = qobject_cast<ConditionWidget*>(item->widget());
            if (conditionWidget)
            {
                filter.addAndCondition(conditionWidget->getCondition());
            }
            else
            {
                QTabWidget* tabWidget = qobject_cast<QTabWidget*>(item->widget());
                if (tabWidget)
                {
                    for (int k = 0; k < tabWidget->count(); ++k)
                    {
                        FilterWidget* filterWidget = static_cast<FilterWidget*>(tabWidget->widget(k));
                        filter.addOrCondition(filterWidget->getFilter());
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
    return filter;
}
