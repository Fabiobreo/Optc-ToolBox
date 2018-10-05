#ifndef MYCHARACTERFORM_H
#define MYCHARACTERFORM_H

#include <QWidget>
#include <mycharacter.h>

namespace Ui {
class MyCharacterForm;
}

class MyCharacterForm : public QWidget
{
    Q_OBJECT

public:
    explicit MyCharacterForm(Character* _character, MyCharacter* _myCharacter, bool _editMode, QWidget *parent = nullptr);
    ~MyCharacterForm();

private slots:
    void editModeChanged();

    void on_levelEdit_textChanged(const QString &_level);

    void on_skillLevelEdit_textChanged(const QString &_skillLevel);

    void on_lbUnlockedEdit_textChanged(const QString &_lbUnlockedNodes);

    void on_trainingPointsEdit_textChanged(const QString &_trainingPoints);

    void on_cottonHpEdit_textChanged(const QString &_ccHp);

    void on_cottonAtkEdit_textChanged(const QString &_ccAtk);

    void on_cottonRcvEdit_textChanged(const QString &_ccRcv);

    void on_firstPotentialValueEdit_textChanged(const QString &_potentialLevel);

    void on_secondPotentialValueEdit_textChanged(const QString &_potentialLevel);

    void on_thirdPotentialValueEdit_textChanged(const QString &_potentialLevel);

    void on_firstSocketEdit_textChanged(const QString &_socketLevel);

    void on_secondSocketEdit_textChanged(const QString &_socketLevel);

    void on_thirdSocketEdit_textChanged(const QString &_socketLevel);

    void on_fourthSocketEdit_textChanged(const QString &_socketLevel);

    void on_fifthSocketEdit_textChanged(const QString &_socketLevel);

    void acceptedSelection(int _row, int _column, Socket::Type _type);

    void on_firstDesiredSocket_clicked();

    void on_secondDesiredSocket_clicked();

    void on_thirdDesiredSocket_clicked();

    void on_fourthDesiredSocket_clicked();

    void on_fifthDesiredSocket_clicked();

    void on_firstCurrentSocket_clicked();

    void on_secondCurrentSocket_clicked();

    void on_thirdCurrentSocket_clicked();

    void on_fourthCurrentSocket_clicked();

    void on_fifthCurrentSocket_clicked();

    void on_lbUnlockedEdit_editingFinished();

    void on_cottonHpEdit_editingFinished();

    void on_cottonAtkEdit_editingFinished();

    void on_cottonRcvEdit_editingFinished();

    void on_firstSocketEdit_editingFinished();

    void on_secondSocketEdit_editingFinished();

    void on_thirdSocketEdit_editingFinished();

    void on_fourthSocketEdit_editingFinished();

    void on_fifthSocketEdit_editingFinished();

    void on_levelEdit_editingFinished();

    void on_skillLevelEdit_editingFinished();

    void on_firstPotentialValueEdit_editingFinished();

    void on_secondPotentialValueEdit_editingFinished();

    void on_thirdPotentialValueEdit_editingFinished();

    void on_wantToFinishLevel_stateChanged(int _state);

    void on_wantToFinishCotton_stateChanged(int _state);

    void on_wantToFinishSkill_stateChanged(int _state);

    void on_wantToFinishSocket_stateChanged(int _state);

    void on_wantToFinishLimit_stateChanged(int _state);

private:

    /**
     * @brief refresh
     */
    void refresh();

    /**
     * @brief prepareSocketPixmap
     */
    void prepareSocketPixmap();

    /**
     * @brief openSocketSelection
     * @param _row
     * @param _column
     */
    void openSocketSelection(int _row, int _column);

    /**
     * @brief getFramedPixmap
     * @param _base
     * @param _overlay
     * @return
     */
    QPixmap* getFramedPixmap(QPixmap* _base, QPixmap* _overlay);

    /**
     * @brief getFrameFromSocket
     * @param _type
     * @return
     */
    QPixmap* getFrameFromSocket(Socket::Type _type);

    /**
     * @brief getFrameFromPotential
     * @param _type
     * @return
     */
    QPixmap* getFrameFromPotential(Potential::Type _type);

    std::map<std::string, QPixmap*> socketPixmap;
    Ui::MyCharacterForm *ui;
    Character* templateCharacter;
    MyCharacter* myCharacter;
    bool editMode;
};

#endif // MYCHARACTERFORM_H
