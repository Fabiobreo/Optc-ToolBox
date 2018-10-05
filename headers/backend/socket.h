/**
 * \class Socket
 * \brief This is a representation of a socket.
 * This class is a representation of a socket.
 * \author Fabio Brea
 * \version $Revision: 0.1 $
 * \date $Date: 2018/04/30 18:00:00 $
 */

#ifndef SOCKET_HPP
#define SOCKET_HPP

class Socket
{
public:

    /**
     * \brief Possible types of socket
     */
    enum class Type
    {
        Dmr, Cd, Bind, Despair, AH, Rcv, Slot, Poison, Map, Resilience, None
    };

    /**
     * \brief Create a socket _type with a _value
     * @param _type the type of the socket
     * @param _value the value of the socket
     */
    explicit Socket(Type _type, short _value);

    /**
     * \brief Get the value of the socket
     * @return the value of the socket
     */
    short getValue();

    /**
     * \brief Set the value of the socket to _value
     * @param _value the value of the socket
     */
    void setValue(short _value);

    /**
     * \brief Get the type of the socket
     * @return the type of the socket
     */
    Socket::Type getType();

    static const short MAXVALUE = 5;    ///< The maximum value of a socket

private:
    Type type;      ///< The type of the socket
    short value;    ///< The value of the socket
};

#endif //SOCKET_HPP
