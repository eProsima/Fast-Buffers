#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "Performance.pb.h"

#define STRING "Esto es una prueba: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" \
    "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" \
    "ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"

int main()
{
    char *buffer = (char*)calloc(BUFFER_SIZE, sizeof(char));

    boost::timer::auto_cpu_timer t;

    performance::Performance performance;
    performance::Performance performance2;

    for(int count = 0; count < NUMBER_OF_LOOPS; ++count)
    {
        performance.mutable_mf()->set_m1(count);
        performance.mutable_mf()->set_m2(count + 1);
        performance.mutable_mf()->set_m3(count + 2);
        performance.mutable_mf()->set_m4(count + 3);
        performance.mutable_mf()->set_m5(count + 4);
        performance.mutable_mf()->set_m6(count + 5);
        performance.mutable_mf()->set_m7(count + 6);
        performance.mutable_mf()->set_m8(count + 7);
        performance.mutable_mf()->set_m9(count + 8);

        performance.mutable_md()->set_m1(count);
        performance.mutable_md()->set_m2(count + 1);
        performance.mutable_md()->set_m3(count + 2);
        performance.mutable_md()->set_m4(count + 3);
        performance.mutable_md()->set_m5(count + 4);
        performance.mutable_md()->set_m6(count + 5);
        performance.mutable_md()->set_m7(count + 6);
        performance.mutable_md()->set_m8(count + 7);
        performance.mutable_md()->set_m9(count + 8);

        performance.mutable_msf3()->set_m1(count);
        performance.mutable_msf3()->set_m2(count + 1);
        performance.mutable_msf3()->set_m3(count + 2);
        performance.mutable_msf3()->set_m4(count + 3);
        performance.mutable_msf3()->set_m5(count + 4);
        performance.mutable_msf3()->set_m6(count + 5);
        performance.mutable_msf3()->set_m7(count + 6);
        performance.mutable_msf3()->set_m8(count + 7);
        performance.mutable_msf3()->set_m9(count + 8);

        performance.mutable_msf6()->set_m1(count);
        performance.mutable_msf6()->set_m2(count + 1);
        performance.mutable_msf6()->set_m3(count + 2);
        performance.mutable_msf6()->set_m4(count + 3);
        performance.mutable_msf6()->set_m5(count + 4);
        performance.mutable_msf6()->set_m6(count + 5);
        performance.mutable_msf6()->set_m7(count + 6);
        performance.mutable_msf6()->set_m8(count + 7);
        performance.mutable_msf6()->set_m9(count + 8);

        performance.mutable_mf3()->set_m1(count);
        performance.mutable_mf3()->set_m2(count + 1);
        performance.mutable_mf3()->set_m3(count + 2);
        performance.mutable_mf3()->set_m4(count + 3);
        performance.mutable_mf3()->set_m5(count + 4);
        performance.mutable_mf3()->set_m6(count + 5);
        performance.mutable_mf3()->set_m7(count + 6);
        performance.mutable_mf3()->set_m8(count + 7);
        performance.mutable_mf3()->set_m9(count + 8);

        performance.mutable_mf6()->set_m1(count);
        performance.mutable_mf6()->set_m2(count + 1);
        performance.mutable_mf6()->set_m3(count + 2);
        performance.mutable_mf6()->set_m4(count + 3);
        performance.mutable_mf6()->set_m5(count + 4);
        performance.mutable_mf6()->set_m6(count + 5);
        performance.mutable_mf6()->set_m7(count + 6);
        performance.mutable_mf6()->set_m8(count + 7);
        performance.mutable_mf6()->set_m9(count + 8);


        performance.mutable_mstr()->set_m1(STRING);
        performance.mutable_mstr()->set_m2(STRING);
        performance.mutable_mstr()->set_m3(STRING);
        performance.mutable_mstr()->set_m4(STRING);
        performance.mutable_mstr()->set_m5(STRING);
        performance.mutable_mstr()->set_m6(STRING);
        performance.mutable_mstr()->set_m7(STRING);
        performance.mutable_mstr()->set_m8(STRING);
        performance.mutable_mstr()->set_m9(STRING);

        if(!performance.SerializeToArray(buffer, BUFFER_SIZE))
            printf("ERROR: serialization\n");

        if(!performance2.ParseFromArray(buffer, performance.ByteSize()))
            printf("ERROR: deserialization\n");
    }

    free(buffer);

    return 0;
}