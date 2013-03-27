#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "Performance_70CDR.h"

int main()
{
    char *buffer = (char*)calloc(BUFFER_SIZE, sizeof(char));

    boost::timer::auto_cpu_timer t;

    eProsima::CDRBuffer cdrbuffer(buffer, BUFFER_SIZE);
    Performance_70CDR cdr(cdrbuffer);
    performance::Performance performance;

    eProsima::CDRBuffer cdrbuffer2(buffer, BUFFER_SIZE);
    Performance_70CDR cdr2(cdrbuffer2);
    performance::Performance performance2;

    for(int count = 0; count < NUMBER_OF_LOOPS; ++count)
    {
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
        performance.m11(count + 11);
        performance.m12(count + 12);
        performance.m13(count + 13);
        performance.m14(count + 14);
        performance.m15(count + 15);
        performance.m16(count + 16);
        performance.m17(count + 17);
        performance.m18(count + 18);
        performance.m19(count + 19);
        performance.m20(count + 20);
        performance.m21(count + 21);
        performance.m22(count + 22);
        performance.m23(count + 23);
        performance.m24(count + 24);
        performance.m25(count + 25);
        performance.m26(count + 26);
        performance.m27(count + 27);
        performance.m28(count + 28);
        performance.m29(count + 29);
        performance.m30(count + 30);
        performance.m31(count + 31);
        performance.m32(count + 32);
        performance.m33(count + 33);
        performance.m34(count + 34);
        performance.m35(count + 35);
        performance.m36(count + 36);
        performance.m37(count + 37);
        performance.m38(count + 38);
        performance.m39(count + 39);
        performance.m40(count + 40);
        performance.m41(count + 41);
        performance.m42(count + 42);
        performance.m43(count + 43);
        performance.m44(count + 44);
        performance.m45(count + 45);
        performance.m46(count + 46);
        performance.m47(count + 47);
        performance.m48(count + 48);
        performance.m49(count + 49);
        performance.m50(count + 50);
        performance.m51(count + 51);
        performance.m52(count + 52);
        performance.m53(count + 53);
        performance.m54(count + 54);
        performance.m55(count + 55);
        performance.m56(count + 56);
        performance.m57(count + 57);
        performance.m58(count + 58);
        performance.m59(count + 59);
        performance.m60(count + 60);
        performance.m61(count + 61);
        performance.m62(count + 62);
        performance.m63(count + 63);
        performance.m64(count + 64);
        performance.m65(count + 65);
        performance.m66(count + 66);
        performance.m67(count + 67);
        performance.m68(count + 68);
        performance.m69(count + 69);
        performance.m70(count + 70);
        
        if(!cdr.serialize(performance))
            printf("ERROR: serialization\n");

        if(!cdr2.deserialize(performance2))
            printf("ERROR: deserialization\n");

        cdrbuffer.reset();
        cdrbuffer2.reset();
    }

    free(buffer);
    return 0;
}