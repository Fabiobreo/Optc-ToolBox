#ifndef ADVANCEDFILTERS_H
#define ADVANCEDFILTERS_H

#include <QMainWindow>
#include <filter.h>

namespace Ui {
class AdvancedFilters;
}

class AdvancedFilters : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdvancedFilters(Utility* _utility, QWidget* _parent = nullptr);
    ~AdvancedFilters();

signals:
    void advancedFiltersColor(bool);
    void advancedFiltersReset();
    void advancedFiltersSet(Filter filter);

private slots:
    void on_clearFiltersButton_clicked();

    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::AdvancedFilters *ui;
    Utility* utility;
};

#endif // ADVANCEDFILTERS_H
