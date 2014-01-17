#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "Performance_20.pb.h"

int main()
{
    char *buffer = (char*)calloc(BUFFER_SIZE, sizeof(char));

    boost::timer::auto_cpu_timer t;

    for(int count = 0; count < NUMBER_OF_LOOPS; ++count)
    {
        performance::Performance performance;

        performance.set_m1(count + 1);
        performance.set_m2(count + 2);
        performance.set_m3(count + 3);
        performance.set_m4(count + 4);
        performance.set_m5(count + 5);
        performance.set_m6(count + 6);
        performance.set_m7(count + 7);
        performance.set_m8(count + 8);
        performance.set_m9(count + 9);
        performance.set_m10(count + 10);
        performance.set_m11(count + 11);
        performance.set_m12(count + 12);
        performance.set_m13(count + 13);
        performance.set_m14(count + 14);
        performance.set_m15(count + 15);
        performance.set_m16(count + 16);
        performance.set_m17(count + 17);
        performance.set_m18(count + 18);
        performance.set_m19(count + 19);
        performance.set_m20(count + 20);

        if(!performance.SerializeToArray(buffer, BUFFER_SIZE))
            printf("ERROR: serialization\n");

        performance::Performance performance2;

        if(!performance2.ParseFromArray(buffer, performance.ByteSize()))
            printf("ERROR: deserialization\n");
    }

    free(buffer);
    return 0;
}