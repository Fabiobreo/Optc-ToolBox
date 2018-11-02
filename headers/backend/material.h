#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <QPixmap>

class Material
{
public:

    /**
     * @brief Type represents the possible material.
     */
    enum class Type
    {
        Manual, Tome, Skull, Booster
    };

    /**
     * @brief The skull enum represents the possible skulls.
     */
    enum class Skull
    {
        STR, DEX, QCK, PSY, INT,
        Luffy, Zoro, Nami, Usopp, Sanji, Chopper, Robin, Franky, Brook,
        Doffy, Judge, Reiju, Ichiji, Niji, Yonji, Higuma, Enel, SanjiLegend, FrankyLegend
    };

    /**
     * @brief Constructor of the material.
     * @param _name: the name of the material.
     * @param _type: the type of the material.
     */
    explicit Material(std::string _name, Type _type);

    /**
     * @brief Constructor of a skull material.
     * @param _name: the name of the material.
     * @param _type: the type of the material.
     * @param _skullType: the skull of the material.
     */
    explicit Material(std::string _name, Type _type, Skull _skullType);

    /**
     * @brief Set the name of the material.
     * @param _name: the name of the material.
     */
    void setName(std::string _name);

    /**
     * @brief Get the name of the material.
     * @return the name of the material.
     */
    std::string getName();

    /**
     * @brief Set the colored pixmap of the material.
     * @param _icon: the colored pixmap of the material.
     */
    void setColoredIcon(QPixmap* _icon);

    /**
     * @brief Get the colored pixmap of the material.
     * @return the colored pixmap of the material.
     */
    QPixmap* getColoredIcon();

    /**
     * @brief Set the grayscale pixmap of the material.
     * @param _icon: the grayscale pixmap of the material.
     */
    void setGrayIcon(QPixmap _icon);

    /**
     * @brief Get the grayscale pixmap of the material.
     * @return the grayscale pixmap of the material.
     */
    QPixmap* getGrayIcon();

private:

    std::string name;       ///< The name of the material.
    Type type;              ///< The type of the material.
    Skull skullType;        ///< The type of the skull.
    QPixmap* coloredIcon;   ///< The colored pixmap icon.
    QPixmap grayIcon;       ///< The grayscale pixmap icon.

};

#endif // MATERIAL_H
