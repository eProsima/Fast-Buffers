#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "Performance_100.pb.h"

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
        performance.set_m41(count + 41);
        performance.set_m42(count + 42);
        performance.set_m43(count + 43);
        performance.set_m44(count + 44);
        performance.set_m45(count + 45);
        performance.set_m46(count + 46);
        performance.set_m47(count + 47);
        performance.set_m48(count + 48);
        performance.set_m49(count + 49);
        performance.set_m50(count + 50);
        performance.set_m51(count + 51);
        performance.set_m52(count + 52);
        performance.set_m53(count + 53);
        performance.set_m54(count + 54);
        performance.set_m55(count + 55);
        performance.set_m56(count + 56);
        performance.set_m57(count + 57);
        performance.set_m58(count + 58);
        performance.set_m59(count + 59);
        performance.set_m60(count + 60);
        performance.set_m61(count + 61);
        performance.set_m62(count + 62);
        performance.set_m63(count + 63);
        performance.set_m64(count + 64);
        performance.set_m65(count + 65);
        performance.set_m66(count + 66);
        performance.set_m67(count + 67);
        performance.set_m68(count + 68);
        performance.set_m69(count + 69);
        performance.set_m70(count + 70);
        performance.set_m71(count + 71);
        performance.set_m72(count + 72);
        performance.set_m73(count + 73);
        performance.set_m74(count + 74);
        performance.set_m75(count + 75);
        performance.set_m76(count + 76);
        performance.set_m77(count + 77);
        performance.set_m78(count + 78);
        performance.set_m79(count + 79);
        performance.set_m80(count + 80);
        performance.set_m81(count + 81);
        performance.set_m82(count + 82);
        performance.set_m83(count + 83);
        performance.set_m84(count + 84);
        performance.set_m85(count + 85);
        performance.set_m86(count + 86);
        performance.set_m87(count + 87);
        performance.set_m88(count + 88);
        performance.set_m89(count + 89);
        performance.set_m90(count + 90);
        performance.set_m91(count + 91);
        performance.set_m92(count + 92);
        performance.set_m93(count + 93);
        performance.set_m94(count + 94);
        performance.set_m95(count + 95);
        performance.set_m96(count + 96);
        performance.set_m97(count + 97);
        performance.set_m98(count + 98);
        performance.set_m99(count + 99);
        performance.set_m100(count + 100);

        if(!performance.SerializeToArray(buffer, BUFFER_SIZE))
            printf("ERROR: serialization\n");

        if(!performance2.ParseFromArray(buffer, performance.ByteSize()))
            printf("ERROR: deserialization\n");
    }

    free(buffer);
    return 0;
}