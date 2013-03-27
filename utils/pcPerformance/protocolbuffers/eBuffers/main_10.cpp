#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "Performance_10CDR.h"

int main()
{
    char *buffer = (char*)calloc(BUFFER_SIZE, sizeof(char));

    boost::timer::auto_cpu_timer t;

    for(int count = 0; count < NUMBER_OF_LOOPS; ++count)
    {
        eProsima::CDRBuffer cdrbuffer(buffer, BUFFER_SIZE);
        Performance_10CDR cdr(cdrbuffer);
        performance::Performance performance;

        performance.m1(count + 1);
        performance.m2(count + 2);
        performance.m3(count + 3);
        performance.m4(count + 4);
        performance.m5(count + 5);
        performance.m6(count + 6);
        performance.m7(count + 7);
        performance.m8(count + 8);
        performance.m9(count + 9);
        performance.m10(count + 10);

        if(!cdr.serialize(performance))
            printf("ERROR: serialization\n");

        eProsima::CDRBuffer cdrbuffer2(buffer, BUFFER_SIZE);
        Performance_10CDR cdr2(cdrbuffer2);
        performance::Performance performance2;

        if(!cdr2.deserialize(performance2))
            printf("ERROR: deserialization\n");
    }

    free(buffer);
    return 0;
}