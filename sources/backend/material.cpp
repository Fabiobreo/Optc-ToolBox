#include <material.h>

Material::Material(std::string _name, Type _type) :
    name(_name),
    type(_type)
{

}
Material::Material(std::string _name, Type _type, Skull _skullType) :
    name(_name),
    type(_type),
    skullType(_skullType)
{

}

void Material::setName(std::string _name)
{
   name = _name;
}

std::string Material::getName()
{
    return name;
}

void Material::setColoredIcon(QPixmap* _icon)
{
    coloredIcon = _icon;
}

QPixmap* Material::getColoredIcon()
{
    return coloredIcon;
}

void Material::setGrayIcon(QPixmap _icon)
{
    grayIcon = _icon;
}

QPixmap* Material::getGrayIcon()
{
    return &grayIcon;
}
