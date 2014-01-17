#include "Performance_60Ser.h"
#include "cdr/exceptions/BadParamException.h"

Performance_60Ser::Performance_60Ser(eprosima::FastBuffer &buffer) : FastCdr(buffer)
{
}

Performance_60Ser& Performance_60Ser::serialize(const performance::Performance &x)
{
    FastCdr::serialize(x.m1());

    FastCdr::serialize(x.m2());

    FastCdr::serialize(x.m3());

    FastCdr::serialize(x.m4());

    FastCdr::serialize(x.m5());

    FastCdr::serialize(x.m6());

    FastCdr::serialize(x.m7());

    FastCdr::serialize(x.m8());

    FastCdr::serialize(x.m9());

    FastCdr::serialize(x.m10());

    FastCdr::serialize(x.m11());

    FastCdr::serialize(x.m12());

    FastCdr::serialize(x.m13());

    FastCdr::serialize(x.m14());

    FastCdr::serialize(x.m15());

    FastCdr::serialize(x.m16());

    FastCdr::serialize(x.m17());

    FastCdr::serialize(x.m18());

    FastCdr::serialize(x.m19());

    FastCdr::serialize(x.m20());

    FastCdr::serialize(x.m21());

    FastCdr::serialize(x.m22());

    FastCdr::serialize(x.m23());

    FastCdr::serialize(x.m24());

    FastCdr::serialize(x.m25());

    FastCdr::serialize(x.m26());

    FastCdr::serialize(x.m27());

    FastCdr::serialize(x.m28());

    FastCdr::serialize(x.m29());

    FastCdr::serialize(x.m30());

    FastCdr::serialize(x.m31());

    FastCdr::serialize(x.m32());

    FastCdr::serialize(x.m33());

    FastCdr::serialize(x.m34());

    FastCdr::serialize(x.m35());

    FastCdr::serialize(x.m36());

    FastCdr::serialize(x.m37());

    FastCdr::serialize(x.m38());

    FastCdr::serialize(x.m39());

    FastCdr::serialize(x.m40());

    FastCdr::serialize(x.m41());

    FastCdr::serialize(x.m42());

    FastCdr::serialize(x.m43());

    FastCdr::serialize(x.m44());

    FastCdr::serialize(x.m45());

    FastCdr::serialize(x.m46());

    FastCdr::serialize(x.m47());

    FastCdr::serialize(x.m48());

    FastCdr::serialize(x.m49());

    FastCdr::serialize(x.m50());

    FastCdr::serialize(x.m51());

    FastCdr::serialize(x.m52());

    FastCdr::serialize(x.m53());

    FastCdr::serialize(x.m54());

    FastCdr::serialize(x.m55());

    FastCdr::serialize(x.m56());

    FastCdr::serialize(x.m57());

    FastCdr::serialize(x.m58());

    FastCdr::serialize(x.m59());

    FastCdr::serialize(x.m60());

    
    return *this;
}

Performance_60Ser& Performance_60Ser::deserialize(performance::Performance &x)
{  
    FastCdr::deserialize(x.m1());
    FastCdr::deserialize(x.m2());
    FastCdr::deserialize(x.m3());
    FastCdr::deserialize(x.m4());
    FastCdr::deserialize(x.m5());
    FastCdr::deserialize(x.m6());
    FastCdr::deserialize(x.m7());
    FastCdr::deserialize(x.m8());
    FastCdr::deserialize(x.m9());
    FastCdr::deserialize(x.m10());
    FastCdr::deserialize(x.m11());
    FastCdr::deserialize(x.m12());
    FastCdr::deserialize(x.m13());
    FastCdr::deserialize(x.m14());
    FastCdr::deserialize(x.m15());
    FastCdr::deserialize(x.m16());
    FastCdr::deserialize(x.m17());
    FastCdr::deserialize(x.m18());
    FastCdr::deserialize(x.m19());
    FastCdr::deserialize(x.m20());
    FastCdr::deserialize(x.m21());
    FastCdr::deserialize(x.m22());
    FastCdr::deserialize(x.m23());
    FastCdr::deserialize(x.m24());
    FastCdr::deserialize(x.m25());
    FastCdr::deserialize(x.m26());
    FastCdr::deserialize(x.m27());
    FastCdr::deserialize(x.m28());
    FastCdr::deserialize(x.m29());
    FastCdr::deserialize(x.m30());
    FastCdr::deserialize(x.m31());
    FastCdr::deserialize(x.m32());
    FastCdr::deserialize(x.m33());
    FastCdr::deserialize(x.m34());
    FastCdr::deserialize(x.m35());
    FastCdr::deserialize(x.m36());
    FastCdr::deserialize(x.m37());
    FastCdr::deserialize(x.m38());
    FastCdr::deserialize(x.m39());
    FastCdr::deserialize(x.m40());
    FastCdr::deserialize(x.m41());
    FastCdr::deserialize(x.m42());
    FastCdr::deserialize(x.m43());
    FastCdr::deserialize(x.m44());
    FastCdr::deserialize(x.m45());
    FastCdr::deserialize(x.m46());
    FastCdr::deserialize(x.m47());
    FastCdr::deserialize(x.m48());
    FastCdr::deserialize(x.m49());
    FastCdr::deserialize(x.m50());
    FastCdr::deserialize(x.m51());
    FastCdr::deserialize(x.m52());
    FastCdr::deserialize(x.m53());
    FastCdr::deserialize(x.m54());
    FastCdr::deserialize(x.m55());
    FastCdr::deserialize(x.m56());
    FastCdr::deserialize(x.m57());
    FastCdr::deserialize(x.m58());
    FastCdr::deserialize(x.m59());
    FastCdr::deserialize(x.m60());
    
    return *this;
}