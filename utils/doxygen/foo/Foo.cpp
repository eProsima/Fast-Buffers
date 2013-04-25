#include "Foo.h"

#include <utility>

Foo::Foo::Foo()
{
    m_id = 0;

}

Foo::Foo::~Foo()
{
}

Foo::Foo::Foo(const Foo &x)
{
    m_id = x.m_id;
    m_message = x.m_message;
}

Foo::Foo::Foo(Foo &&x)
{
    m_id = x.m_id;
    m_message = std::move(x.m_message);
}

Foo::Foo& Foo::Foo::operator=(const Foo &x)
{
    m_id = x.m_id;
    m_message = x.m_message;
    
    return *this;
}

Foo::Foo& Foo::Foo::operator=(Foo &&x)
{
    m_id = x.m_id;
    m_message = std::move(x.m_message);
    
    return *this;
}