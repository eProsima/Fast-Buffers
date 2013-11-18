#ifndef _PerformanceSER_H_
#define _PerformanceSER_H_

#include "Performance.h"
#include "cpp/FastCdr.h"

/*!
 * @brief This class offers an interface to serialize/deserialize the defined types in the user's IDL file  using a eprosima::FastBuffer.
 */
class user_cpp_DllExport PerformanceSer : public eprosima::FastCdr
{ 
public:
    /*!
     * @brief This constructor creates a PerformanceSer object that could serialize/deserialize
     * the assigned buffer.
     *
     * @param buffer A reference to the buffer that contains or will contain the CDR representation.
     */
    PerformanceSer(eprosima::FastBuffer &buffer);
    
    /*!
     * @brief This function serialize a type performance::mfloats.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::mfloats &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::mfloats.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::mfloats &x);

    /*!
     * @brief This function deserialize a type performance::mfloats.
     * @param x Reference to the variable that will store the performance::mfloats read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::mfloats &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::mfloats.
     * @param x Reference to the variable that will store the performance::mfloats read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::mfloats &x);
    /*!
     * @brief This function serialize a type performance::mdoubles.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::mdoubles &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::mdoubles.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::mdoubles &x);

    /*!
     * @brief This function deserialize a type performance::mdoubles.
     * @param x Reference to the variable that will store the performance::mdoubles read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::mdoubles &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::mdoubles.
     * @param x Reference to the variable that will store the performance::mdoubles read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::mdoubles &x);
    /*!
     * @brief This function serialize a type performance::msfixed32s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::msfixed32s &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::msfixed32s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::msfixed32s &x);

    /*!
     * @brief This function deserialize a type performance::msfixed32s.
     * @param x Reference to the variable that will store the performance::msfixed32s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::msfixed32s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::msfixed32s.
     * @param x Reference to the variable that will store the performance::msfixed32s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::msfixed32s &x);
    /*!
     * @brief This function serialize a type performance::msfixed64s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::msfixed64s &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::msfixed64s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::msfixed64s &x);

    /*!
     * @brief This function deserialize a type performance::msfixed64s.
     * @param x Reference to the variable that will store the performance::msfixed64s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::msfixed64s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::msfixed64s.
     * @param x Reference to the variable that will store the performance::msfixed64s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::msfixed64s &x);
    /*!
     * @brief This function serialize a type performance::mfixed32s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::mfixed32s &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::mfixed32s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::mfixed32s &x);

    /*!
     * @brief This function deserialize a type performance::mfixed32s.
     * @param x Reference to the variable that will store the performance::mfixed32s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::mfixed32s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::mfixed32s.
     * @param x Reference to the variable that will store the performance::mfixed32s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::mfixed32s &x);
    /*!
     * @brief This function serialize a type performance::mfixed64s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::mfixed64s &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::mfixed64s.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::mfixed64s &x);

    /*!
     * @brief This function deserialize a type performance::mfixed64s.
     * @param x Reference to the variable that will store the performance::mfixed64s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::mfixed64s &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::mfixed64s.
     * @param x Reference to the variable that will store the performance::mfixed64s read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::mfixed64s &x);
    /*!
     * @brief This function serialize a type performance::mstrings.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::mstrings &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::mstrings.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::mstrings &x);

    /*!
     * @brief This function deserialize a type performance::mstrings.
     * @param x Reference to the variable that will store the performance::mstrings read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::mstrings &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::mstrings.
     * @param x Reference to the variable that will store the performance::mstrings read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::mstrings &x);
    /*!
     * @brief This function serialize a type performance::Performance.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline PerformanceSer& operator<<(const performance::Performance &x){return serialize(x);}

    /*!
     * @brief This function serialize a type performance::Performance.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    PerformanceSer& serialize(const performance::Performance &x);

    /*!
     * @brief This function deserialize a type performance::Performance.
     * @param x Reference to the variable that will store the performance::Performance read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline PerformanceSer& operator>>(performance::Performance &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type performance::Performance.
     * @param x Reference to the variable that will store the performance::Performance read from the buffer.
     * @return Reference to the PerformanceSer object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    PerformanceSer& deserialize(performance::Performance &x);
};

#endif // _PerformanceSER_H_