#include "FooCDR.h"
#include "cpp/exceptions/BadParamException.h"

FooCDR::FooCDR(eProsima::CDRBuffer &cdrBuffer) : CDR(cdrBuffer)
{
}

FooCDR& FooCDR::serialize(const Foo::Foo &x)
{
    CDR::serialize(x.id());

    CDR::serialize(x.message());

    
    return *this;
}

FooCDR& FooCDR::serializeFast(const Foo::Foo &x)
{
    CDR::serializeFast(x.id());

    CDR::serializeFast(x.message());

    
    return *this;
}

FooCDR& FooCDR::deserialize(Foo::Foo &x)
{  
    CDR::deserialize(x.id());
    CDR::deserialize(x.message());
    
    return *this;
}

FooCDR& FooCDR::deserializeFast(Foo::Foo &x)
{  
    CDR::deserializeFast(x.id());
    CDR::deserializeFast(x.message());
    
    return *this;
}