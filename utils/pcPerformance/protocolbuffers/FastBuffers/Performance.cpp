#include "Performance.h"
#include "cpp/exceptions/BadParamException.h"

#include <utility>

performance::mfloats::mfloats()
{
    m_m1 = 0.0;
    m_m2 = 0.0;
    m_m3 = 0.0;
    m_m4 = 0.0;
    m_m5 = 0.0;
    m_m6 = 0.0;
    m_m7 = 0.0;
    m_m8 = 0.0;
    m_m9 = 0.0;
}

performance::mfloats::~mfloats()
{
}

performance::mfloats::mfloats(const mfloats &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mfloats::mfloats(mfloats &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mfloats& performance::mfloats::operator=(const mfloats &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}

performance::mfloats& performance::mfloats::operator=(mfloats &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}
performance::mdoubles::mdoubles()
{
    m_m1 = 0.0;
    m_m2 = 0.0;
    m_m3 = 0.0;
    m_m4 = 0.0;
    m_m5 = 0.0;
    m_m6 = 0.0;
    m_m7 = 0.0;
    m_m8 = 0.0;
    m_m9 = 0.0;
}

performance::mdoubles::~mdoubles()
{
}

performance::mdoubles::mdoubles(const mdoubles &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mdoubles::mdoubles(mdoubles &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mdoubles& performance::mdoubles::operator=(const mdoubles &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}

performance::mdoubles& performance::mdoubles::operator=(mdoubles &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}
performance::msfixed32s::msfixed32s()
{
    m_m1 = 0;
    m_m2 = 0;
    m_m3 = 0;
    m_m4 = 0;
    m_m5 = 0;
    m_m6 = 0;
    m_m7 = 0;
    m_m8 = 0;
    m_m9 = 0;
}

performance::msfixed32s::~msfixed32s()
{
}

performance::msfixed32s::msfixed32s(const msfixed32s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::msfixed32s::msfixed32s(msfixed32s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::msfixed32s& performance::msfixed32s::operator=(const msfixed32s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}

performance::msfixed32s& performance::msfixed32s::operator=(msfixed32s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}
performance::msfixed64s::msfixed64s()
{
    m_m1 = 0;
    m_m2 = 0;
    m_m3 = 0;
    m_m4 = 0;
    m_m5 = 0;
    m_m6 = 0;
    m_m7 = 0;
    m_m8 = 0;
    m_m9 = 0;
}

performance::msfixed64s::~msfixed64s()
{
}

performance::msfixed64s::msfixed64s(const msfixed64s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::msfixed64s::msfixed64s(msfixed64s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::msfixed64s& performance::msfixed64s::operator=(const msfixed64s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}

performance::msfixed64s& performance::msfixed64s::operator=(msfixed64s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}
performance::mfixed32s::mfixed32s()
{
    m_m1 = 0;
    m_m2 = 0;
    m_m3 = 0;
    m_m4 = 0;
    m_m5 = 0;
    m_m6 = 0;
    m_m7 = 0;
    m_m8 = 0;
    m_m9 = 0;
}

performance::mfixed32s::~mfixed32s()
{
}

performance::mfixed32s::mfixed32s(const mfixed32s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mfixed32s::mfixed32s(mfixed32s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mfixed32s& performance::mfixed32s::operator=(const mfixed32s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}

performance::mfixed32s& performance::mfixed32s::operator=(mfixed32s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}
performance::mfixed64s::mfixed64s()
{
    m_m1 = 0;
    m_m2 = 0;
    m_m3 = 0;
    m_m4 = 0;
    m_m5 = 0;
    m_m6 = 0;
    m_m7 = 0;
    m_m8 = 0;
    m_m9 = 0;
}

performance::mfixed64s::~mfixed64s()
{
}

performance::mfixed64s::mfixed64s(const mfixed64s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mfixed64s::mfixed64s(mfixed64s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mfixed64s& performance::mfixed64s::operator=(const mfixed64s &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}

performance::mfixed64s& performance::mfixed64s::operator=(mfixed64s &&x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}
performance::mstrings::mstrings()
{









}

performance::mstrings::~mstrings()
{
}

performance::mstrings::mstrings(const mstrings &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
}

performance::mstrings::mstrings(mstrings &&x)
{
    m_m1 = std::move(x.m_m1);
    m_m2 = std::move(x.m_m2);
    m_m3 = std::move(x.m_m3);
    m_m4 = std::move(x.m_m4);
    m_m5 = std::move(x.m_m5);
    m_m6 = std::move(x.m_m6);
    m_m7 = std::move(x.m_m7);
    m_m8 = std::move(x.m_m8);
    m_m9 = std::move(x.m_m9);
}

performance::mstrings& performance::mstrings::operator=(const mstrings &x)
{
    m_m1 = x.m_m1;
    m_m2 = x.m_m2;
    m_m3 = x.m_m3;
    m_m4 = x.m_m4;
    m_m5 = x.m_m5;
    m_m6 = x.m_m6;
    m_m7 = x.m_m7;
    m_m8 = x.m_m8;
    m_m9 = x.m_m9;
    
    return *this;
}

performance::mstrings& performance::mstrings::operator=(mstrings &&x)
{
    m_m1 = std::move(x.m_m1);
    m_m2 = std::move(x.m_m2);
    m_m3 = std::move(x.m_m3);
    m_m4 = std::move(x.m_m4);
    m_m5 = std::move(x.m_m5);
    m_m6 = std::move(x.m_m6);
    m_m7 = std::move(x.m_m7);
    m_m8 = std::move(x.m_m8);
    m_m9 = std::move(x.m_m9);
    
    return *this;
}
performance::Performance::Performance()
{







}

performance::Performance::~Performance()
{
}

performance::Performance::Performance(const Performance &x)
{
    m_mf = x.m_mf;
    m_md = x.m_md;
    m_msf3 = x.m_msf3;
    m_msf6 = x.m_msf6;
    m_mf3 = x.m_mf3;
    m_mf6 = x.m_mf6;
    m_mstr = x.m_mstr;
}

performance::Performance::Performance(Performance &&x)
{
    m_mf = std::move(x.m_mf);
    m_md = std::move(x.m_md);
    m_msf3 = std::move(x.m_msf3);
    m_msf6 = std::move(x.m_msf6);
    m_mf3 = std::move(x.m_mf3);
    m_mf6 = std::move(x.m_mf6);
    m_mstr = std::move(x.m_mstr);
}

performance::Performance& performance::Performance::operator=(const Performance &x)
{
    m_mf = x.m_mf;
    m_md = x.m_md;
    m_msf3 = x.m_msf3;
    m_msf6 = x.m_msf6;
    m_mf3 = x.m_mf3;
    m_mf6 = x.m_mf6;
    m_mstr = x.m_mstr;
    
    return *this;
}

performance::Performance& performance::Performance::operator=(Performance &&x)
{
    m_mf = std::move(x.m_mf);
    m_md = std::move(x.m_md);
    m_msf3 = std::move(x.m_msf3);
    m_msf6 = std::move(x.m_msf6);
    m_mf3 = std::move(x.m_mf3);
    m_mf6 = std::move(x.m_mf6);
    m_mstr = std::move(x.m_mstr);
    
    return *this;
}