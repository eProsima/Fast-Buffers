#ifndef _FooCDR_H_
#define _FooCDR_H_

#include "Foo.h"
#include "cpp/Cdr.h"

/*!
 * @brief This class offers an interface to serialize/deserialize the defined types in the user's IDL file.
 * @ingroup FOOEXAMPLE
 */
class user_cpp_DllExport FooCDR : public eProsima::CDR
{ 
public:
    FooCDR(eProsima::CDRBuffer &cdrBuffer);
    
    /*!
     * @brief This function serialize type Foo::Foo.
     */
    inline bool operator<<(const Foo::Foo &x){return serialize(x);}

    /*!
     * @brief This function serialize type Foo::Foo.
     */
    bool serialize(const Foo::Foo &x);

    /*!
     * @brief This function deserialize type Foo::Foo.
     */
    inline bool operator>>(Foo::Foo &x){return deserialize(x);}

    /*!
     * @brief This function deserialize type Foo::Foo.
     */
    bool deserialize(Foo::Foo &x);
};

#endif // _FooCDR_H_
