#include "Performance_80CDR.h"

Performance_80CDR::Performance_80CDR(eProsima::CDRBuffer &cdrBuffer) : CDR(cdrBuffer)
{
}

bool Performance_80CDR::serialize(const performance::Performance &x)
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

    returnedValue &= CDR::serialize(x.m31());

    returnedValue &= CDR::serialize(x.m32());

    returnedValue &= CDR::serialize(x.m33());

    returnedValue &= CDR::serialize(x.m34());

    returnedValue &= CDR::serialize(x.m35());

    returnedValue &= CDR::serialize(x.m36());

    returnedValue &= CDR::serialize(x.m37());

    returnedValue &= CDR::serialize(x.m38());

    returnedValue &= CDR::serialize(x.m39());

    returnedValue &= CDR::serialize(x.m40());

    returnedValue &= CDR::serialize(x.m41());

    returnedValue &= CDR::serialize(x.m42());

    returnedValue &= CDR::serialize(x.m43());

    returnedValue &= CDR::serialize(x.m44());

    returnedValue &= CDR::serialize(x.m45());

    returnedValue &= CDR::serialize(x.m46());

    returnedValue &= CDR::serialize(x.m47());

    returnedValue &= CDR::serialize(x.m48());

    returnedValue &= CDR::serialize(x.m49());

    returnedValue &= CDR::serialize(x.m50());

    returnedValue &= CDR::serialize(x.m51());

    returnedValue &= CDR::serialize(x.m52());

    returnedValue &= CDR::serialize(x.m53());

    returnedValue &= CDR::serialize(x.m54());

    returnedValue &= CDR::serialize(x.m55());

    returnedValue &= CDR::serialize(x.m56());

    returnedValue &= CDR::serialize(x.m57());

    returnedValue &= CDR::serialize(x.m58());

    returnedValue &= CDR::serialize(x.m59());

    returnedValue &= CDR::serialize(x.m60());

    returnedValue &= CDR::serialize(x.m61());

    returnedValue &= CDR::serialize(x.m62());

    returnedValue &= CDR::serialize(x.m63());

    returnedValue &= CDR::serialize(x.m64());

    returnedValue &= CDR::serialize(x.m65());

    returnedValue &= CDR::serialize(x.m66());

    returnedValue &= CDR::serialize(x.m67());

    returnedValue &= CDR::serialize(x.m68());

    returnedValue &= CDR::serialize(x.m69());

    returnedValue &= CDR::serialize(x.m70());

    returnedValue &= CDR::serialize(x.m71());

    returnedValue &= CDR::serialize(x.m72());

    returnedValue &= CDR::serialize(x.m73());

    returnedValue &= CDR::serialize(x.m74());

    returnedValue &= CDR::serialize(x.m75());

    returnedValue &= CDR::serialize(x.m76());

    returnedValue &= CDR::serialize(x.m77());

    returnedValue &= CDR::serialize(x.m78());

    returnedValue &= CDR::serialize(x.m79());

    returnedValue &= CDR::serialize(x.m80());

    
    return returnedValue;
}

bool Performance_80CDR::deserialize(performance::Performance &x)
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
    returnedValue &= CDR::deserialize(x.m31());
    returnedValue &= CDR::deserialize(x.m32());
    returnedValue &= CDR::deserialize(x.m33());
    returnedValue &= CDR::deserialize(x.m34());
    returnedValue &= CDR::deserialize(x.m35());
    returnedValue &= CDR::deserialize(x.m36());
    returnedValue &= CDR::deserialize(x.m37());
    returnedValue &= CDR::deserialize(x.m38());
    returnedValue &= CDR::deserialize(x.m39());
    returnedValue &= CDR::deserialize(x.m40());
    returnedValue &= CDR::deserialize(x.m41());
    returnedValue &= CDR::deserialize(x.m42());
    returnedValue &= CDR::deserialize(x.m43());
    returnedValue &= CDR::deserialize(x.m44());
    returnedValue &= CDR::deserialize(x.m45());
    returnedValue &= CDR::deserialize(x.m46());
    returnedValue &= CDR::deserialize(x.m47());
    returnedValue &= CDR::deserialize(x.m48());
    returnedValue &= CDR::deserialize(x.m49());
    returnedValue &= CDR::deserialize(x.m50());
    returnedValue &= CDR::deserialize(x.m51());
    returnedValue &= CDR::deserialize(x.m52());
    returnedValue &= CDR::deserialize(x.m53());
    returnedValue &= CDR::deserialize(x.m54());
    returnedValue &= CDR::deserialize(x.m55());
    returnedValue &= CDR::deserialize(x.m56());
    returnedValue &= CDR::deserialize(x.m57());
    returnedValue &= CDR::deserialize(x.m58());
    returnedValue &= CDR::deserialize(x.m59());
    returnedValue &= CDR::deserialize(x.m60());
    returnedValue &= CDR::deserialize(x.m61());
    returnedValue &= CDR::deserialize(x.m62());
    returnedValue &= CDR::deserialize(x.m63());
    returnedValue &= CDR::deserialize(x.m64());
    returnedValue &= CDR::deserialize(x.m65());
    returnedValue &= CDR::deserialize(x.m66());
    returnedValue &= CDR::deserialize(x.m67());
    returnedValue &= CDR::deserialize(x.m68());
    returnedValue &= CDR::deserialize(x.m69());
    returnedValue &= CDR::deserialize(x.m70());
    returnedValue &= CDR::deserialize(x.m71());
    returnedValue &= CDR::deserialize(x.m72());
    returnedValue &= CDR::deserialize(x.m73());
    returnedValue &= CDR::deserialize(x.m74());
    returnedValue &= CDR::deserialize(x.m75());
    returnedValue &= CDR::deserialize(x.m76());
    returnedValue &= CDR::deserialize(x.m77());
    returnedValue &= CDR::deserialize(x.m78());
    returnedValue &= CDR::deserialize(x.m79());
    returnedValue &= CDR::deserialize(x.m80());
    
    return returnedValue;
}