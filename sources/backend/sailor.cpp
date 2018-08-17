#include "sailor.h"

Sailor::Sailor()
{

}

Sailor::Sailor(std::string _description) :
    description(_description)
{

}

Sailor::~Sailor()
{

}

std::string Sailor::getDescription() const
{
    return description;
}

void Sailor::setDescription(std::string _description)
{
    description = _description;
}
