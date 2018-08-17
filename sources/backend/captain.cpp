#include "captain.h"

Captain::Captain()
{

}

Captain::Captain(std::string _description) :
    description(_description)
{

}

Captain::~Captain()
{

}

std::string Captain::getDescription() const
{
    return description;
}

void Captain::setDescription(std::string _description)
{
    description = _description;
}