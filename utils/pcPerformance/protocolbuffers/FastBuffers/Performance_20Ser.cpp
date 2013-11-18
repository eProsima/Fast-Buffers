#include "Performance_20Ser.h"
#include "cpp/exceptions/BadParamException.h"

Performance_20Ser::Performance_20Ser(eprosima::FastBuffer &buffer) : FastCdr(buffer)
{
}

Performance_20Ser& Performance_20Ser::serialize(const performance::Performance &x)
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

    
    return *this;
}

Performance_20Ser& Performance_20Ser::deserialize(performance::Performance &x)
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
    
    return *this;
}