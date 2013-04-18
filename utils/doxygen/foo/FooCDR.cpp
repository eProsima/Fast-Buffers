#include "FooCDR.h"

FooCDR::FooCDR(eProsima::CDRBuffer &cdrBuffer) : CDR(cdrBuffer)
{
}

bool FooCDR::serialize(const Foo::Foo &x)
{
    bool returnedValue = true;
    
    returnedValue &= CDR::serialize(x.id());

    returnedValue &= CDR::serialize(x.message());

    
    return returnedValue;
}

bool FooCDR::deserialize(Foo::Foo &x)
{
    bool returnedValue = true;
    
    returnedValue &= CDR::deserialize(x.id());
    returnedValue &= CDR::deserialize(x.message());
    
    return returnedValue;
}