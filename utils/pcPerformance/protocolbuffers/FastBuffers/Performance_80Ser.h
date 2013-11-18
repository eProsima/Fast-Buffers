#ifndef _Performance_80SER_H_
#define _Performance_80SER_H_

#include "Performance_80.h"
#include "cpp/FastCdr.h"

/*!
 * @brief This class offers an interface to serialize/deserialize the defined types in the user's IDL file  using a eprosima::FastBuffer.
 */
class user_cpp_DllExport Performance_80Ser : public eprosima::FastCdr
{ 
public:
    /*!
     * @brief This constructor creates a Performance_80Ser object that could serialize/deserialize
     * the assigned buffer.
     *
     * @param buffer A reference to the buffer that contains or will contain the CDR representation.
     */
    Performance_80Ser(eprosima::FastBuffer &buffer);
    
    /*!
     * @brief This function serialize a type performance::Performance.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the Performance_80Ser object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline Performance_80Ser& operator<<(const performance::Performance &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::Performance.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the Performance_80Ser object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    Performance_80Ser& serialize(const performance::Performance &x);

    /*!
     * @brief This function deserialize a type performance::Performance.
     * @param x Reference to the variable that will store the performance::Performance read from the buffer.
     * @return Reference to the Performance_80Ser object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline Performance_80Ser& operator>>(performance::Performance &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::Performance.
     * @param x Reference to the variable that will store the performance::Performance read from the buffer.
     * @return Reference to the Performance_80Ser object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    Performance_80Ser& deserialize(performance::Performance &x);
};

#endif // _Performance_80SER_H_