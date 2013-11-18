#include "NestedStructuresSer.h"

#ifdef __linux
#include <unistd.h>
#endif

#include <malloc.h>
#include <iostream>

bool FBug95Test()
{
    Bug95Test::outerStructComplex os;

    os.short_value(35);
    os.char_value(64);
    os.iis1_value().char_value(212);
    os.iis1_value().string_value("Como estan ustedes!!");
    os.iis1_value().ulonglong_value(212);
    os.iis1_value().ushort_value(2112);
    os.ushort_value(3421);
    os.double_value(934.34);
    os.iis2_value().char_value(212);
    os.iis2_value().string_value("De puta madre");
    os.iis2_value().ulonglong_value(212);
    os.iis2_value().ushort_value(2112);
    os.is2_value().longlongvalue(-342345);
    os.is2_value().longvalue(-34452);
    os.is2_value().char_value(64);
    os.is2_value().iis_value().char_value(112);
    os.is2_value().iis_value().string_value("Me alegro mucho");
    os.is2_value().iis_value().ulonglong_value(21234);
    os.is2_value().iis_value().ushort_value(1112);
    os.is2_value().ulong_value(64943);
    os.is2_value().float_value(64.34);
    os.is2_value().double_value(3400.34);
    os.is2_value().string_value("Gracias hombre");

    // Create the serializer object.
    char *buffer = (char*)calloc(1, os.getMaxSerializedSize());
    eprosima::FastBuffer fbuffer(buffer, os.getMaxSerializedSize());
    NestedStructuresSer serializer(fbuffer);

    // Serialize structure.
    try
    {
        serializer << os;
    }
    catch(eprosima::Exception &ex)
    {
        std::cout << "TEST FAILED<FBug95Test>: Serialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Reset serializer object.
    serializer.reset();

    // Object used to deserialize the data.
    Bug95Test::outerStructComplex osres;

    // Deserialize structure.
    try
    {
        serializer >> osres;
    }
    catch(eprosima::Exception &ex)
    {
        std::cout << "TEST FAILED<FBug95Test>: Deserialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Compare data.
    bool compareOK = true;

    compareOK &= os.short_value() == osres.short_value();
    compareOK &= os.char_value() == osres.char_value();
    compareOK &= os.iis1_value().char_value() == osres.iis1_value().char_value();
    compareOK &= os.iis1_value().string_value() == osres.iis1_value().string_value();
    compareOK &= os.iis1_value().ulonglong_value() == osres.iis1_value().ulonglong_value();
    compareOK &= os.iis1_value().ushort_value() == osres.iis1_value().ushort_value();
    compareOK &= os.ushort_value() == osres.ushort_value();
    compareOK &= os.double_value() == osres.double_value();
    compareOK &= os.iis2_value().char_value() == osres.iis2_value().char_value();
    compareOK &= os.iis2_value().string_value() == osres.iis2_value().string_value();
    compareOK &= os.iis2_value().ulonglong_value() == osres.iis2_value().ulonglong_value();
    compareOK &= os.iis2_value().ushort_value() == osres.iis2_value().ushort_value();
    compareOK &= os.is2_value().longlongvalue() == osres.is2_value().longlongvalue();
    compareOK &= os.is2_value().longvalue() == osres.is2_value().longvalue();
    compareOK &= os.is2_value().char_value() == osres.is2_value().char_value();
    compareOK &= os.is2_value().iis_value().char_value() == osres.is2_value().iis_value().char_value();
    compareOK &= os.is2_value().iis_value().string_value() == osres.is2_value().iis_value().string_value();
    compareOK &= os.is2_value().iis_value().ulonglong_value() == osres.is2_value().iis_value().ulonglong_value();
    compareOK &= os.is2_value().iis_value().ushort_value() == osres.is2_value().iis_value().ushort_value();
    compareOK &= os.is2_value().ulong_value() == osres.is2_value().ulong_value();
    compareOK &= os.is2_value().float_value() == osres.is2_value().float_value();
    compareOK &= os.is2_value().double_value() == osres.is2_value().double_value();
    compareOK &= os.is2_value().string_value() == osres.is2_value().string_value();

    if(!compareOK)
    {
        std::cout << "TEST FAILED<FBug95Test>: Wrong values" << std::endl;
        free(buffer);
        return false;
    }

    return true;
}

int main()
{
    bool results = true;

    results &= FBug95Test();

    if(!results)
    {
        std::cout << "TEST FAILED" << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESSFULLY" << std::endl;

    _exit(0);
    return 0;
}
