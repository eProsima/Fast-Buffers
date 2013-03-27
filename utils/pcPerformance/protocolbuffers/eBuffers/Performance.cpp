#include "Performance.h"

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

performance::mfloats::mfloats(const performance::mfloats &x)
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

performance::mfloats::mfloats(performance::mfloats &&x)
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

performance::mfloats& performance::mfloats::operator=(const performance::mfloats &x)
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

performance::mfloats& performance::mfloats::operator=(performance::mfloats &&x)
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

performance::mdoubles::mdoubles(const performance::mdoubles &x)
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

performance::mdoubles::mdoubles(performance::mdoubles &&x)
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

performance::mdoubles& performance::mdoubles::operator=(const performance::mdoubles &x)
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

performance::mdoubles& performance::mdoubles::operator=(performance::mdoubles &&x)
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

performance::msfixed32s::msfixed32s(const performance::msfixed32s &x)
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

performance::msfixed32s::msfixed32s(performance::msfixed32s &&x)
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

performance::msfixed32s& performance::msfixed32s::operator=(const performance::msfixed32s &x)
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

performance::msfixed32s& performance::msfixed32s::operator=(performance::msfixed32s &&x)
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

performance::msfixed64s::msfixed64s(const performance::msfixed64s &x)
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

performance::msfixed64s::msfixed64s(performance::msfixed64s &&x)
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

performance::msfixed64s& performance::msfixed64s::operator=(const performance::msfixed64s &x)
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

performance::msfixed64s& performance::msfixed64s::operator=(performance::msfixed64s &&x)
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

performance::mfixed32s::mfixed32s(const performance::mfixed32s &x)
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

performance::mfixed32s::mfixed32s(performance::mfixed32s &&x)
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

performance::mfixed32s& performance::mfixed32s::operator=(const performance::mfixed32s &x)
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

performance::mfixed32s& performance::mfixed32s::operator=(performance::mfixed32s &&x)
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

performance::mfixed64s::mfixed64s(const performance::mfixed64s &x)
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

performance::mfixed64s::mfixed64s(performance::mfixed64s &&x)
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

performance::mfixed64s& performance::mfixed64s::operator=(const performance::mfixed64s &x)
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

performance::mfixed64s& performance::mfixed64s::operator=(performance::mfixed64s &&x)
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

performance::mstrings::mstrings(const performance::mstrings &x)
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

performance::mstrings::mstrings(performance::mstrings &&x)
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

performance::mstrings& performance::mstrings::operator=(const performance::mstrings &x)
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

performance::mstrings& performance::mstrings::operator=(performance::mstrings &&x)
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

performance::Performance::Performance(const performance::Performance &x)
{
    m_mf = x.m_mf;
    m_md = x.m_md;
    m_msf3 = x.m_msf3;
    m_msf6 = x.m_msf6;
    m_mf3 = x.m_mf3;
    m_mf6 = x.m_mf6;
    m_mstr = x.m_mstr;
}

performance::Performance::Performance(performance::Performance &&x)
{
    m_mf = std::move(x.m_mf);
    m_md = std::move(x.m_md);
    m_msf3 = std::move(x.m_msf3);
    m_msf6 = std::move(x.m_msf6);
    m_mf3 = std::move(x.m_mf3);
    m_mf6 = std::move(x.m_mf6);
    m_mstr = std::move(x.m_mstr);
}

performance::Performance& performance::Performance::operator=(const performance::Performance &x)
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

performance::Performance& performance::Performance::operator=(performance::Performance &&x)
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