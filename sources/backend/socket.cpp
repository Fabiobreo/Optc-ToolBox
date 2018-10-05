#include <socket.h>

Socket::Socket(Socket::Type _type, short _value) :
type(_type),
value(_value)
{

}

short Socket::getValue()
{
    return value;
}

void Socket::setValue(short _value)
{
    if (_value <= MAXVALUE)
    {
        value = _value;
    }
}

Socket::Type Socket::getType()
{
    return type;
}
