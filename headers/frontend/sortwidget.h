#ifndef SORTWIDGET_H
#define SORTWIDGET_H

#include <QMainWindow>
#include <utility.h>

namespace Ui {
class SortWidget;
}

class SortWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit SortWidget(Utility* _utility, QWidget *parent = nullptr);
    ~SortWidget();

private slots:
    void on_primaryPriority_clicked();

    void on_secondaryPriority_clicked();

    void on_primaryComboBox_currentIndexChanged(const QString &_text);

    void on_secondaryComboBox_currentIndexChanged(const QString &_text);

    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_primaryIncludeLimit_stateChanged(int _state);

    void on_secondaryIncludeLimit_stateChanged(int _state);

signals:
    void sort();

private:
    Ui::SortWidget *ui;
    Utility* utility;

    std::vector<QString> possibleConditions;

    std::string primaryCondition;
    bool primaryAscendingOrder;
    bool primaryIncludeLimit;

    std::string secondaryCondition;
    bool secondaryAscendingOrder;
    bool secondaryIncludeLimit;
};

#endif // SORTWIDGET_H
