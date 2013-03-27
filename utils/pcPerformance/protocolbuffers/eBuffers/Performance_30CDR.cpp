#include "Performance_30CDR.h"

Performance_30CDR::Performance_30CDR(eProsima::CDRBuffer &cdrBuffer) : CDR(cdrBuffer)
{
}

bool Performance_30CDR::serialize(const performance::Performance &x)
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

    returnedValue &= CDR::serialize(x.m21());

    returnedValue &= CDR::serialize(x.m22());

    returnedValue &= CDR::serialize(x.m23());

    returnedValue &= CDR::serialize(x.m24());

    returnedValue &= CDR::serialize(x.m25());

    returnedValue &= CDR::serialize(x.m26());

    returnedValue &= CDR::serialize(x.m27());

    returnedValue &= CDR::serialize(x.m28());

    returnedValue &= CDR::serialize(x.m29());

    returnedValue &= CDR::serialize(x.m30());

    
    return returnedValue;
}

bool Performance_30CDR::deserialize(performance::Performance &x)
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
    returnedValue &= CDR::deserialize(x.m21());
    returnedValue &= CDR::deserialize(x.m22());
    returnedValue &= CDR::deserialize(x.m23());
    returnedValue &= CDR::deserialize(x.m24());
    returnedValue &= CDR::deserialize(x.m25());
    returnedValue &= CDR::deserialize(x.m26());
    returnedValue &= CDR::deserialize(x.m27());
    returnedValue &= CDR::deserialize(x.m28());
    returnedValue &= CDR::deserialize(x.m29());
    returnedValue &= CDR::deserialize(x.m30());
    
    return returnedValue;
}