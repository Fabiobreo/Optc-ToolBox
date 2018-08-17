#ifndef SAILOR_HPP
#define SAILOR_HPP

#pragma once
#include <iostream>

class Sailor
{
public:
    Sailor();
    explicit Sailor(std::string _description);
    ~Sailor();

    void setDescription(std::string _description);

    std::string getDescription() const;

private:
    std::string description;
};

#endif //SAILOR_HPP
