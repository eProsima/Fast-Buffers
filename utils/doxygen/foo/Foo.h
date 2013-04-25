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
     */
    class user_cpp_DllExport Foo
    {
    public:
        Foo();
        ~Foo();
        Foo(const Foo &x);
        Foo(Foo &&x);
        Foo& operator=(const Foo &x);
        Foo& operator=(Foo &&x);
        
        inline void id(int32_t _id)
        {
            m_id = _id;
        }

        inline int32_t id() const
        {
            return m_id;
        }

        inline int32_t& id()
        {
            return m_id;
        }
        inline void message(const std::string &_message)
        {
            m_message = _message;
        }

        inline void message(std::string &&_message)
        {
            m_message = std::move(_message);
        }

        inline const std::string& message() const
        {
            return m_message;
        }

        inline std::string& message()
        {
            return m_message;
        }
        
    private:
        int32_t m_id;
        std::string m_message;
    };
}

#endif // _Foo_H_