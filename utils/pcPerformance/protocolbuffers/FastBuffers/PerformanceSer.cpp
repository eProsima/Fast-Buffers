#include "PerformanceSer.h"
#include "cdr/exceptions/BadParamException.h"

PerformanceSer::PerformanceSer(eprosima::FastBuffer &buffer) : FastCdr(buffer)
{
}

PerformanceSer& PerformanceSer::serialize(const performance::mfloats &x)
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

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::mfloats &x)
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
    
    return *this;
}
PerformanceSer& PerformanceSer::serialize(const performance::mdoubles &x)
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

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::mdoubles &x)
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
    
    return *this;
}
PerformanceSer& PerformanceSer::serialize(const performance::msfixed32s &x)
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

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::msfixed32s &x)
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
    
    return *this;
}
PerformanceSer& PerformanceSer::serialize(const performance::msfixed64s &x)
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

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::msfixed64s &x)
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
    
    return *this;
}
PerformanceSer& PerformanceSer::serialize(const performance::mfixed32s &x)
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

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::mfixed32s &x)
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
    
    return *this;
}
PerformanceSer& PerformanceSer::serialize(const performance::mfixed64s &x)
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

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::mfixed64s &x)
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
    
    return *this;
}
PerformanceSer& PerformanceSer::serialize(const performance::mstrings &x)
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

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::mstrings &x)
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
    
    return *this;
}
PerformanceSer& PerformanceSer::serialize(const performance::Performance &x)
{
    serialize(x.mf());

    serialize(x.md());

    serialize(x.msf3());

    serialize(x.msf6());

    serialize(x.mf3());

    serialize(x.mf6());

    serialize(x.mstr());

    
    return *this;
}

PerformanceSer& PerformanceSer::deserialize(performance::Performance &x)
{  
    deserialize(x.mf());
    deserialize(x.md());
    deserialize(x.msf3());
    deserialize(x.msf6());
    deserialize(x.mf3());
    deserialize(x.mf6());
    deserialize(x.mstr());
    
    return *this;
}