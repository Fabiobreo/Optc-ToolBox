#ifndef CAPTAIN_HPP
#define CAPTAIN_HPP

#include <iostream>

class Captain
{
public:

    /**
     * @brief Void constructor
     */
    Captain() = default;

    /**
     * @brief Create a Captain ability with the given description
     * @param _description: the description of the captain ability
     */
    explicit Captain(std::string _description);

    /**
     * @brief Destructor
     */
    ~Captain() = default;

    /**
     * @brief Set _description as the description for the captain ability
     * @param _description: the description of the captain ability
     */
    void setDescription(std::string _description);

    /**
     * @brief Get the description of the captain ability
     * @return the description of the captain ability
     */
    std::string getDescription() const;

private:

    std::string description;    ///< Description of the captain ability
};

#endif //CAPTAIN_HPP
