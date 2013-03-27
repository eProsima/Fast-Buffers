#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "Performance_40.pb.h"

int main()
{
    char *buffer = (char*)calloc(BUFFER_SIZE, sizeof(char));

    boost::timer::auto_cpu_timer t;

    performance::Performance performance;
    performance::Performance performance2;

    for(int count = 0; count < NUMBER_OF_LOOPS; ++count)
    {
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
        performance.set_m21(count + 21);
        performance.set_m22(count + 22);
        performance.set_m23(count + 23);
        performance.set_m24(count + 24);
        performance.set_m25(count + 25);
        performance.set_m26(count + 26);
        performance.set_m27(count + 27);
        performance.set_m28(count + 28);
        performance.set_m29(count + 29);
        performance.set_m30(count + 30);
        performance.set_m31(count + 31);
        performance.set_m32(count + 32);
        performance.set_m33(count + 33);
        performance.set_m34(count + 34);
        performance.set_m35(count + 35);
        performance.set_m36(count + 36);
        performance.set_m37(count + 37);
        performance.set_m38(count + 38);
        performance.set_m39(count + 39);
        performance.set_m40(count + 40);

        if(!performance.SerializeToArray(buffer, BUFFER_SIZE))
            printf("ERROR: serialization\n");

        if(!performance2.ParseFromArray(buffer, performance.ByteSize()))
            printf("ERROR: deserialization\n");
    }

    free(buffer);
    return 0;
}