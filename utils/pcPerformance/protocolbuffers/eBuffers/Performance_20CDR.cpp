#include "Performance_20CDR.h"

Performance_20CDR::Performance_20CDR(eProsima::CDRBuffer &cdrBuffer) : CDR(cdrBuffer)
{
}

bool Performance_20CDR::serialize(const performance::Performance &x)
{
    bool returnedValue = true;
    
    returnedValue &= CDR::serialize(x.m1());

    returnedValue &= CDR::serialize(x.m2());

    returnedValue &= CDR::serialize(x.m3());

    returnedValue &= CDR::serialize(x.m4());

    returnedValue &= CDR::serialize(x.m5());

    returnedValue &= CDR::serialize(x.m6());

    returnedValue &= CDR::serialize(x.m7());

    returnedValue &= CDR::serialize(x.m8());

    returnedValue &= CDR::serialize(x.m9());

    returnedValue &= CDR::serialize(x.m10());

    returnedValue &= CDR::serialize(x.m11());

    returnedValue &= CDR::serialize(x.m12());

    returnedValue &= CDR::serialize(x.m13());

    returnedValue &= CDR::serialize(x.m14());

    returnedValue &= CDR::serialize(x.m15());

    returnedValue &= CDR::serialize(x.m16());

    returnedValue &= CDR::serialize(x.m17());

    returnedValue &= CDR::serialize(x.m18());

    returnedValue &= CDR::serialize(x.m19());

    returnedValue &= CDR::serialize(x.m20());

    
    return returnedValue;
}

bool Performance_20CDR::deserialize(performance::Performance &x)
{
    bool returnedValue = true;
    
    returnedValue &= CDR::deserialize(x.m1());
    returnedValue &= CDR::deserialize(x.m2());
    returnedValue &= CDR::deserialize(x.m3());
    returnedValue &= CDR::deserialize(x.m4());
    returnedValue &= CDR::deserialize(x.m5());
    returnedValue &= CDR::deserialize(x.m6());
    returnedValue &= CDR::deserialize(x.m7());
    returnedValue &= CDR::deserialize(x.m8());
    returnedValue &= CDR::deserialize(x.m9());
    returnedValue &= CDR::deserialize(x.m10());
    returnedValue &= CDR::deserialize(x.m11());
    returnedValue &= CDR::deserialize(x.m12());
    returnedValue &= CDR::deserialize(x.m13());
    returnedValue &= CDR::deserialize(x.m14());
    returnedValue &= CDR::deserialize(x.m15());
    returnedValue &= CDR::deserialize(x.m16());
    returnedValue &= CDR::deserialize(x.m17());
    returnedValue &= CDR::deserialize(x.m18());
    returnedValue &= CDR::deserialize(x.m19());
    returnedValue &= CDR::deserialize(x.m20());
    
    return returnedValue;
}