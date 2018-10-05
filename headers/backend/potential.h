#include <enums.h>

#ifndef POTENTIAL_HPP
#define POTENTIAL_HPP

#include <vector>
#include <map>

class Potential
{
public:

    enum class Type
    {
        StartPotential, Enrage, NoHealing, CriticalHit, SlotBind, BarrierPenetration, PinchHealing, DMRSTR, DMRQCK, DMRDEX, DMRPSY, DMRINT, CDR, DoubleSpecial, None
    };

    /**
     * Create a Potential Ability socket
     * @param _type the type of the potential ability
     * @param _value the value of the potential ability
     */
    explicit Potential(Potential::Type _type, short _value);

    /**
     * Get the value of the potential ability
     * @return the value of the potential ability
     */
    short getValue();

    /**
     * Set the value of the potential ability to _value
     * @param _value the value to set
     */
    void setValue(short _value);

    /**
     * Get the type of the potential ability
     * @return the type of the potential ability
     */
    Potential::Type getType();

    std::vector<std::string> getDescriptions();
    void addDescription(std::string _description);

    std::string getDescriptionFromType(Potential::Type _potential);
    Potential::Type getTypeFromDescription(std::string _potential);


    static const short MAXVALUE = 5;    ///< The maximum value of the potential ability

private:
    Type type;
    std::vector<std::string> descriptions;
    std::map<std::string, Type> descriptionToType;
    std::map<Type, std::string> typeToDescription;
    short value;
};

#endif //POTENTIAL_HPP
