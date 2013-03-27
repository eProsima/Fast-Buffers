#include "Performance_10CDR.h"

Performance_10CDR::Performance_10CDR(eProsima::CDRBuffer &cdrBuffer) : CDR(cdrBuffer)
{
}

bool Performance_10CDR::serialize(const performance::Performance &x)
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

    
    return returnedValue;
}

bool Performance_10CDR::deserialize(performance::Performance &x)
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
    
    return returnedValue;
}