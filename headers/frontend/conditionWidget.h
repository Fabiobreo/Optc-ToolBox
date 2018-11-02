#ifndef CONDITIONWIDGET_H
#define CONDITIONWIDGET_H

#include <QWidget>
#include <filter.h>
#include <utility.h>
#include <map>

namespace Ui {
class ConditionWidget;
}

class ConditionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConditionWidget(Utility* _utility, QWidget *_parent = nullptr);

    ~ConditionWidget();

    void enableWidget();

    Condition getCondition();

private slots:

    void on_primaryTargetBox_currentIndexChanged(const QString &_text);

    void on_secondaryTargetBox_currentIndexChanged(const QString &_text);

    void on_terziaryTargetBox_currentIndexChanged(const QString &_text);

    void on_numericValueEdit_textChanged(const QString &_text);

    void loadIcons();

    void on_secondaryNumericValueEdit_textChanged(const QString &arg1);

private:
    Ui::ConditionWidget *ui;
    Utility* utility;
    Condition* dummy;

    std::map<Type, QIcon> typeToIcon;
    std::map<Class, QIcon> classToIcon;
    std::map<Potential::Type, QIcon> potentialToIcon;
};

#endif // CONDITIONWIDGET_H
