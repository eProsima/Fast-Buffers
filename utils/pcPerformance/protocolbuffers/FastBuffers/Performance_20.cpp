#include "Performance_20.h"
#include "cdr/exceptions/BadParamException.h"

#include <utility>

performance::Performance::Performance()
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
    m_m10 = 0;
    m_m11 = 0;
    m_m12 = 0;
    m_m13 = 0;
    m_m14 = 0;
    m_m15 = 0;
    m_m16 = 0;
    m_m17 = 0;
    m_m18 = 0;
    m_m19 = 0;
    m_m20 = 0;
}

performance::Performance::~Performance()
{
}

performance::Performance::Performance(const Performance &x)
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
    m_m10 = x.m_m10;
    m_m11 = x.m_m11;
    m_m12 = x.m_m12;
    m_m13 = x.m_m13;
    m_m14 = x.m_m14;
    m_m15 = x.m_m15;
    m_m16 = x.m_m16;
    m_m17 = x.m_m17;
    m_m18 = x.m_m18;
    m_m19 = x.m_m19;
    m_m20 = x.m_m20;
}

performance::Performance::Performance(Performance &&x)
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
    m_m10 = x.m_m10;
    m_m11 = x.m_m11;
    m_m12 = x.m_m12;
    m_m13 = x.m_m13;
    m_m14 = x.m_m14;
    m_m15 = x.m_m15;
    m_m16 = x.m_m16;
    m_m17 = x.m_m17;
    m_m18 = x.m_m18;
    m_m19 = x.m_m19;
    m_m20 = x.m_m20;
}

performance::Performance& performance::Performance::operator=(const Performance &x)
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
    m_m10 = x.m_m10;
    m_m11 = x.m_m11;
    m_m12 = x.m_m12;
    m_m13 = x.m_m13;
    m_m14 = x.m_m14;
    m_m15 = x.m_m15;
    m_m16 = x.m_m16;
    m_m17 = x.m_m17;
    m_m18 = x.m_m18;
    m_m19 = x.m_m19;
    m_m20 = x.m_m20;
    
    return *this;
}

performance::Performance& performance::Performance::operator=(Performance &&x)
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
    m_m10 = x.m_m10;
    m_m11 = x.m_m11;
    m_m12 = x.m_m12;
    m_m13 = x.m_m13;
    m_m14 = x.m_m14;
    m_m15 = x.m_m15;
    m_m16 = x.m_m16;
    m_m17 = x.m_m17;
    m_m18 = x.m_m18;
    m_m19 = x.m_m19;
    m_m20 = x.m_m20;
    
    return *this;
}