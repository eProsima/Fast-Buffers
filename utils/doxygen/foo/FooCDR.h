#ifndef _FooCDR_H_
#define _FooCDR_H_

#include "Foo.h"
#include "cpp/Cdr.h"

/*!
 * @brief This class offers an interface to serialize/deserialize the defined types in the user's IDL file  using a eProsima::CDRBuffer.
 * @ingroup FOOEXAMPLE
 */
class user_cpp_DllExport FooCDR : public eProsima::CDR
{ 
public:
    /*!
     * @brief This constructor creates a FooCDR object that could serialize/deserialize
     * the assigned buffer.
     *
     * @param cdrBuffer A reference to the buffer that contains or will contain the CDR representation.
     */
    FooCDR(eProsima::CDRBuffer &cdrBuffer);
    
    /*!
     * @brief This function serialize a type Foo::Foo.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the FooCDR object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    inline FooCDR& operator<<(const Foo::Foo &x){return serialize(x);}

    /*!
     * @brief This function serialize a type Foo::Foo.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the FooCDR object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    FooCDR& serialize(const Foo::Foo &x);

    /*!
     * @brief This function serialize a type Foo::Foo without alignment.
     * @param x Reference to a  that will be serialized in the buffer.
     * @return Reference to the FooCDR object.
     * @exception NotEnoughMemoryException This exception is thrown trying to serialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to serialize in an invalid value.
     */
    FooCDR& serializeFast(const Foo::Foo &x);

    /*!
     * @brief This function deserialize a type Foo::Foo.
     * @param x Reference to the variable that will store the Foo::Foo read from the buffer.
     * @return Reference to the FooCDR object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    inline FooCDR& operator>>(Foo::Foo &x){return deserialize(x);}

    /*!
     * @brief This function deserialize a type Foo::Foo.
     * @param x Reference to the variable that will store the Foo::Foo read from the buffer.
     * @return Reference to the FooCDR object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    FooCDR& deserialize(Foo::Foo &x);

    /*!
     * @brief This function deserialize a type Foo::Foo without alignment.
     * @param x Reference to the variable that will store the Foo::Foo read from the buffer.
     * @return Reference to the FooCDR object.
     * @exception NotEnoughMemoryException This exception is thrown trying to deserialize in a position that exceed the internal memory size.
     * @exception BadParamException This exception is thrown trying to deserialize in an invalid value.
     */
    FooCDR& deserializeFast(Foo::Foo &x);
};

#endif // _FooCDR_H_
