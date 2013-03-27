#include "Performance_40.h"

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
    m_m21 = 0;
    m_m22 = 0;
    m_m23 = 0;
    m_m24 = 0;
    m_m25 = 0;
    m_m26 = 0;
    m_m27 = 0;
    m_m28 = 0;
    m_m29 = 0;
    m_m30 = 0;
    m_m31 = 0;
    m_m32 = 0;
    m_m33 = 0;
    m_m34 = 0;
    m_m35 = 0;
    m_m36 = 0;
    m_m37 = 0;
    m_m38 = 0;
    m_m39 = 0;
    m_m40 = 0;
}

performance::Performance::~Performance()
{
}

performance::Performance::Performance(const performance::Performance &x)
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
    m_m21 = x.m_m21;
    m_m22 = x.m_m22;
    m_m23 = x.m_m23;
    m_m24 = x.m_m24;
    m_m25 = x.m_m25;
    m_m26 = x.m_m26;
    m_m27 = x.m_m27;
    m_m28 = x.m_m28;
    m_m29 = x.m_m29;
    m_m30 = x.m_m30;
    m_m31 = x.m_m31;
    m_m32 = x.m_m32;
    m_m33 = x.m_m33;
    m_m34 = x.m_m34;
    m_m35 = x.m_m35;
    m_m36 = x.m_m36;
    m_m37 = x.m_m37;
    m_m38 = x.m_m38;
    m_m39 = x.m_m39;
    m_m40 = x.m_m40;
}

performance::Performance::Performance(performance::Performance &&x)
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
    m_m21 = x.m_m21;
    m_m22 = x.m_m22;
    m_m23 = x.m_m23;
    m_m24 = x.m_m24;
    m_m25 = x.m_m25;
    m_m26 = x.m_m26;
    m_m27 = x.m_m27;
    m_m28 = x.m_m28;
    m_m29 = x.m_m29;
    m_m30 = x.m_m30;
    m_m31 = x.m_m31;
    m_m32 = x.m_m32;
    m_m33 = x.m_m33;
    m_m34 = x.m_m34;
    m_m35 = x.m_m35;
    m_m36 = x.m_m36;
    m_m37 = x.m_m37;
    m_m38 = x.m_m38;
    m_m39 = x.m_m39;
    m_m40 = x.m_m40;
}

performance::Performance& performance::Performance::operator=(const performance::Performance &x)
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
    m_m21 = x.m_m21;
    m_m22 = x.m_m22;
    m_m23 = x.m_m23;
    m_m24 = x.m_m24;
    m_m25 = x.m_m25;
    m_m26 = x.m_m26;
    m_m27 = x.m_m27;
    m_m28 = x.m_m28;
    m_m29 = x.m_m29;
    m_m30 = x.m_m30;
    m_m31 = x.m_m31;
    m_m32 = x.m_m32;
    m_m33 = x.m_m33;
    m_m34 = x.m_m34;
    m_m35 = x.m_m35;
    m_m36 = x.m_m36;
    m_m37 = x.m_m37;
    m_m38 = x.m_m38;
    m_m39 = x.m_m39;
    m_m40 = x.m_m40;
    
    return *this;
}

performance::Performance& performance::Performance::operator=(performance::Performance &&x)
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
    m_m21 = x.m_m21;
    m_m22 = x.m_m22;
    m_m23 = x.m_m23;
    m_m24 = x.m_m24;
    m_m25 = x.m_m25;
    m_m26 = x.m_m26;
    m_m27 = x.m_m27;
    m_m28 = x.m_m28;
    m_m29 = x.m_m29;
    m_m30 = x.m_m30;
    m_m31 = x.m_m31;
    m_m32 = x.m_m32;
    m_m33 = x.m_m33;
    m_m34 = x.m_m34;
    m_m35 = x.m_m35;
    m_m36 = x.m_m36;
    m_m37 = x.m_m37;
    m_m38 = x.m_m38;
    m_m39 = x.m_m39;
    m_m40 = x.m_m40;
    
    return *this;
}