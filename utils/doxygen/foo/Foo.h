#ifndef _Foo_H_
#define _Foo_H_

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

#if defined(WIN32)
#if defined(USER_CPP_DLL_EXPORT)
#define user_cpp_DllExport __declspec( dllexport )
#else
#define user_cpp_DllExport
#endif
#else
#define user_cpp_DllExport
#endif

namespace Foo
{
    /*!
     * @brief This class represents the structure Foo defined by the user in the IDL file.
     * @ingroup FOOEXAMPLE
     */
    class user_cpp_DllExport Foo
    {
    public:

        /*!
         * @brief Default constructor.
         */
        Foo();
        
        /*!
         * @brief Default destructor.
         */
        ~Foo();
        
        /*!
         * @brief Copy constructor.
         * @param x Reference to the object Foo::Foo that will be copied.
         */
        Foo(const Foo &x);
        
        /*!
         * @brief Move constructor.
         * @param x Reference to the object Foo::Foo that will be copied.
         */
        Foo(Foo &&x);
        
        /*!
         * @brief Copy assignment.
         * @param x Reference to the object Foo::Foo that will be copied.
         */
        Foo& operator=(const Foo &x);
        
        /*!
         * @brief Move assignment.
         * @param x Reference to the object Foo::Foo that will be copied.
         */
        Foo& operator=(Foo &&x);
        
        /*!
         * @brief This function sets a value in member id
         * @param _id New value for member id
         */
        inline void id(int32_t _id)
        {
            m_id = _id;
        }

        /*!
         * @brief This function returns the value of member id
         * @return Value of member id
         */
        inline int32_t id() const
        {
            return m_id;
        }

        /*!
         * @brief This function returns a reference to member id
         * @return Reference to member id
         */
        inline int32_t& id()
        {
            return m_id;
        }
        /*!
         * @brief This function copies the value in member message
         * @param _message New value to be copied in member message
         */
        inline void message(const std::string &_message)
        {
            m_message = _message;
        }

        /*!
         * @brief This function moves the value in member message
         * @param _message New value to be moved in member message
         */
        inline void message(std::string &&_message)
        {
            m_message = std::move(_message);
        }

        /*!
         * @brief This function returns a constant reference to member message
         * @return Constant reference to member message
         */
        inline const std::string& message() const
        {
            return m_message;
        }

        /*!
         * @brief This function returns a reference to member message
         * @return Reference to member message
         */
        inline std::string& message()
        {
            return m_message;
        }
        
        /*!
         * @brief This function calculates the space needed to serialize a type Foo::Foo.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSize() { return 263;}
         
         /*!
         * @brief This function calculates the space needed to serialize a type Foo::Foo without alignment.
         *        For all types with a variable size (strings, sequences) and without a maximum limit, this function uses
         *        255 as maximum limit.
         */
         inline
         size_t getMaxSerializedSizeWithoutAlign(){ return 263;}
        
    private:
        int32_t m_id;
        std::string m_message;
    };
}

#endif // _Foo_H_
