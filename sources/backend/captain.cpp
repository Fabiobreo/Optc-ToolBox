#include "captain.h"

Captain::Captain(std::string _description) :
    description(_description)
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
