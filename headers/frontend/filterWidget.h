#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>
#include <filter.h>

namespace Ui {
class FilterWidget;
}

class FilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilterWidget(Utility* _utility, QWidget *_parent = 0);
    ~FilterWidget();

    Filter getFilter();

private slots:
    void addCondition();

    void removeCondition();

    void on_addFilterButton_clicked();

    void removeTab(int _index);

private:
    Ui::FilterWidget *ui;
    Utility* utility;
    QString buttonStyleSheet;
    QSize buttonSize;
};

#endif // FILTERWIDGET_H
