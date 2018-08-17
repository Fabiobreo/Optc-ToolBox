#ifndef CAPTAIN_HPP
#define CAPTAIN_HPP

#pragma once
#include <iostream>

class Captain
{
public:
    Captain();
    explicit Captain(std::string _description);
    ~Captain();

    void setDescription(std::string _description);

    std::string getDescription() const;

private:
    std::string description;
};

#endif //CAPTAIN_HPP