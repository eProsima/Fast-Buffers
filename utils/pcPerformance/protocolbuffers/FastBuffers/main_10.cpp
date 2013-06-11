#include <stdio.h>
#include <malloc.h>

#include <boost/timer/timer.hpp>

#include "../Definitions.h"
#include "Performance_10Ser.h"

int main()
{
    char *buffer = (char*)calloc(BUFFER_SIZE, sizeof(char));

    boost::timer::auto_cpu_timer t;

	eProsima::FastBuffer cdrbuffer(buffer, BUFFER_SIZE);
	Performance_10Ser cdr(cdrbuffer);
	performance::Performance performance;

	Performance_10Ser cdr2(cdrbuffer);
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

		try
		{
			cdr.serialize(performance);
		}
		catch(eProsima::Exception &ex)
		{
            std::cout << "ERROR: " << ex.what() << std::endl;
		}

		try
		{
			cdr2.deserialize(performance2);
		}
		catch(eProsima::Exception &ex)
		{
            std::cout << "ERROR: " << ex.what() << std::endl;
		}

		cdr.reset();
		cdr2.reset();
    }

    free(buffer);
    return 0;
}