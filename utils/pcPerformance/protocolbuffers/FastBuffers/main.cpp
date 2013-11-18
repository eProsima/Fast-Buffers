#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "PerformanceSer.h"

#define STRING "Esto es una prueba: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" \
    "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb" \
    "ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc" \
    "ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"

int main()
{
    char *buffer = (char*)calloc(BUFFER_SIZE, sizeof(char));

    boost::timer::auto_cpu_timer t;

    eprosima::FastBuffer cdrbuffer(buffer, BUFFER_SIZE);
    PerformanceSer cdr(cdrbuffer);
    performance::Performance performance;

    PerformanceSer cdr2(cdrbuffer);
    performance::Performance performance2;

    for(int count = 0; count < NUMBER_OF_LOOPS; ++count)
    {
        performance.mf().m1(count);
        performance.mf().m2(count + 1);
        performance.mf().m3(count + 2);
        performance.mf().m4(count + 3);
        performance.mf().m5(count + 4);
        performance.mf().m6(count + 5);
        performance.mf().m7(count + 6);
        performance.mf().m8(count + 7);
        performance.mf().m9(count + 8);

        performance.md().m1(count);
        performance.md().m2(count + 1);
        performance.md().m3(count + 2);
        performance.md().m4(count + 3);
        performance.md().m5(count + 4);
        performance.md().m6(count + 5);
        performance.md().m7(count + 6);
        performance.md().m8(count + 7);
        performance.md().m9(count + 8);

        performance.msf3().m1(count);
        performance.msf3().m2(count + 1);
        performance.msf3().m3(count + 2);
        performance.msf3().m4(count + 3);
        performance.msf3().m5(count + 4);
        performance.msf3().m6(count + 5);
        performance.msf3().m7(count + 6);
        performance.msf3().m8(count + 7);
        performance.msf3().m9(count + 8);

        performance.msf6().m1(count);
        performance.msf6().m2(count + 1);
        performance.msf6().m3(count + 2);
        performance.msf6().m4(count + 3);
        performance.msf6().m5(count + 4);
        performance.msf6().m6(count + 5);
        performance.msf6().m7(count + 6);
        performance.msf6().m8(count + 7);
        performance.msf6().m9(count + 8);

        performance.mf3().m1(count);
        performance.mf3().m2(count + 1);
        performance.mf3().m3(count + 2);
        performance.mf3().m4(count + 3);
        performance.mf3().m5(count + 4);
        performance.mf3().m6(count + 5);
        performance.mf3().m7(count + 6);
        performance.mf3().m8(count + 7);
        performance.mf3().m9(count + 8);

        performance.mf6().m1(count);
        performance.mf6().m2(count + 1);
        performance.mf6().m3(count + 2);
        performance.mf6().m4(count + 3);
        performance.mf6().m5(count + 4);
        performance.mf6().m6(count + 5);
        performance.mf6().m7(count + 6);
        performance.mf6().m8(count + 7);
        performance.mf6().m9(count + 8);


        performance.mstr().m1(STRING);
        performance.mstr().m2(STRING);
        performance.mstr().m3(STRING);
        performance.mstr().m4(STRING);
        performance.mstr().m5(STRING);
        performance.mstr().m6(STRING);
        performance.mstr().m7(STRING);
        performance.mstr().m8(STRING);
        performance.mstr().m9(STRING);

		try
		{
			cdr.serialize(performance);
		}
        catch(eprosima::Exception &ex)
		{
			std::cout << "ERROR: " << ex.what() << std::endl;
		}

        try
		{
			cdr2.deserialize(performance2);
		}
        catch(eprosima::Exception &ex)
		{
			std::cout << "ERROR: " << ex.what() << std::endl;
		}

        cdr.reset();
        cdr2.reset();
    }

    free(buffer);
    return 0;
}