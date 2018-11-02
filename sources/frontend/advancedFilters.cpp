#include "advancedFilters.h"
#include "ui_advancedFilters.h"
#include <filterWidget.h>
#include <QPushButton>
#include <QSpacerItem>
#include <QStyle>
#include <QDesktopWidget>

AdvancedFilters::AdvancedFilters(Utility* _utility, QWidget* _parent) :
    QMainWindow(_parent),
    ui(new Ui::AdvancedFilters),
    utility(_utility)
{
    ui->setupUi(this);
    connect(this, SIGNAL(advancedFiltersColor(bool)), _parent, SLOT(change_advancedFilters_color(bool)));
    connect(this, SIGNAL(advancedFiltersSet(Filter)), _parent, SLOT(advancedFilters_set(Filter)));
    connect(this, SIGNAL(advancedFiltersReset()), _parent, SLOT(advancedFilters_reset()));

    FilterWidget* filter = new FilterWidget(utility, this);
    QSpacerItem* spacer = new QSpacerItem(1, 1, QSizePolicy::Fixed, QSizePolicy::Expanding);

    ui->gridLayout->addWidget(filter, 0, 0);
    ui->gridLayout->addItem(spacer, 1, 0, 1, 1);
}

AdvancedFilters::~AdvancedFilters()
{
    delete ui;
}

void AdvancedFilters::on_clearFiltersButton_clicked()
{
    // Remove current filters
    FilterWidget* filters = static_cast<FilterWidget*>(ui->gridLayout->itemAtPosition(0, 0)->widget());
    ui->gridLayout->removeWidget(filters);
    delete filters;

    // Add default filters
    FilterWidget* filter = new FilterWidget(utility, this);
    ui->gridLayout->addWidget(filter, 0, 0);

    emit advancedFiltersColor(false);
    emit advancedFiltersReset();
}

void AdvancedFilters::on_cancelButton_clicked()
{
    on_clearFiltersButton_clicked();
    hide();
}

void AdvancedFilters::on_okButton_clicked()
{
    FilterWidget* filter = static_cast<FilterWidget*>(ui->gridLayout->itemAtPosition(0, 0)->widget());
    Filter filtered = filter->getFilter();
    emit advancedFiltersSet(filtered);
    if (!(filtered.andConditions.empty() && filtered.orConditions.empty()))
    {
        emit advancedFiltersColor(true);
    }
    else
    {
        emit advancedFiltersColor(false);
    }
    hide();
}
