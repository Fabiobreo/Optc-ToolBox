#ifndef CONDITIONWIDGET_H
#define CONDITIONWIDGET_H

#include <QWidget>
#include <filter.h>

namespace Ui {
class ConditionWidget;
}

class ConditionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConditionWidget(QWidget *_parent = nullptr);
    ~ConditionWidget();
    void enableWidget();
    Condition getCondition();

private slots:
    void on_targetBox_currentIndexChanged(const QString &_text);
    void on_secondaryTargetBox_currentIndexChanged(const QString &_text);
    void on_numericValueEdit_textChanged(const QString &_text);

private:
    Ui::ConditionWidget *ui;
    Condition* dummy;
};

#endif // CONDITIONWIDGET_H
