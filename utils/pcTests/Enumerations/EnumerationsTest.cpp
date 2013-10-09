#include "EnumerationsSer.h"

#ifdef __linux
#include <unistd.h>
#endif

#include <malloc.h>
#include <iostream>

bool FBug96Test()
{
    Bug96Test::simpleStruct_6 si;

    si.en(Bug96Test::GREEN);

    // Create the serializer object.
    char *buffer = (char*)calloc(1, si.getMaxSerializedSize());
    eProsima::FastBuffer fbuffer(buffer, si.getMaxSerializedSize());
    EnumerationsSer serializer(fbuffer);

    // Serialize structure.
    try
    {
        serializer << si;
    }
    catch(eProsima::Exception &ex)
    {
        std::cout << "TEST FAILED<FBug96Test>: Serialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Reset serializer object.
    serializer.reset();

    // Object used to deserialize the data.
    Bug96Test::simpleStruct_6 sires;

    // Deserialize structure.
    try
    {
        serializer >> sires;
    }
    catch(eProsima::Exception &ex)
    {
        std::cout << "TEST FAILED<FBug95Test>: Deserialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Compare data.
    bool compareOK = true;

    compareOK &= si.en() == sires.en();

    if(!compareOK)
    {
        std::cout << "TEST FAILED<FBug96Test>: Wrong values" << std::endl;
        free(buffer);
        return false;
    }

    return true;
}

int main()
{
    bool results = true;

    results &= FBug96Test();

    if(!results)
    {
        std::cout << "TEST FAILED" << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESSFULLY" << std::endl;

    _exit(0);
    return 0;
}
