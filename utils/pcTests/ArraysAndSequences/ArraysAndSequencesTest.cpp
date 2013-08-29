#include "ArraysAndSequencesSer.h"

#include <unistd.h>
#include <malloc.h>
#include <iostream>

bool FMainTest()
{
    MainTest::ArraysAndSequences as;

    // Fill the arrays.
    for(int count = 0; count < 100; ++count)
    {
        as.ocarray().at(count) = (uint8_t)count;
        as.charray().at(count) = (char)count;
        as.usharray().at(count) = (uint16_t)count;
        as.sharray().at(count) = (int16_t)count;
        as.ularray().at(count) = (uint32_t)count;
        as.larray().at(count) = (int32_t)count;
        as.ullarray().at(count) = (uint64_t)count;
        as.llarray().at(count) = (int64_t)count;
        as.farray().at(count) = (float)count;
        as.darray().at(count) = (double)count;
    }

    // Fill the sequences.
    for(int count = 0; count < 50; ++count)
    {
        as.ocseq().push_back((uint8_t)count);
        as.chseq().push_back((char)count);
        as.ushseq().push_back((uint16_t)count);
        as.shseq().push_back((int16_t)count);
        as.ulseq().push_back((uint32_t)count);
        as.lseq().push_back((int32_t)count);
        as.ullseq().push_back((uint64_t)count);
        as.llseq().push_back((int64_t)count);
        as.fseq().push_back((float)count);
        as.dseq().push_back((double)count);
    }

    // Create the serializer object.
    char *buffer = (char*)calloc(1, as.getMaxSerializedSize());
    eProsima::FastBuffer fbuffer(buffer, as.getMaxSerializedSize());
    ArraysAndSequencesSer serializer(fbuffer);

    // Serialize structure.
    try
    {
        serializer << as;
    }
    catch(eProsima::Exception &ex)
    {
        std::cout << "TEST FAILED<FMainTest>: Serialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Reset serializer object.
    serializer.reset();

    // Object used to deserialize the data.
    MainTest::ArraysAndSequences asres;

    // Deserialize structure.
    try
    {
        serializer >> asres;
    }
    catch(eProsima::Exception &ex)
    {
        std::cout << "TEST FAILED<FMainTest>: Deserialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Compare data.
    bool compareOK = true;

    // Compare arrays
    for(int count = 0; compareOK && count < 100; ++count)
    {
        compareOK &= asres.ocarray().at(count) == (uint8_t)count;
        compareOK &= asres.charray().at(count) == (char)count;
        compareOK &= asres.usharray().at(count) == (uint16_t)count;
        compareOK &= asres.sharray().at(count) == (int16_t)count;
        compareOK &= asres.ularray().at(count) == (uint32_t)count;
        compareOK &= asres.larray().at(count) == (int32_t)count;
        compareOK &= asres.ullarray().at(count) == (uint64_t)count;
        compareOK &= asres.llarray().at(count) == (int64_t)count;
        compareOK &= asres.farray().at(count) == (float)count;
        compareOK &= asres.darray().at(count) == (double)count;
    }

    if(!compareOK)
    {
        std::cout << "TEST FAILED<FMainTest>: Wrong values in arrays" << std::endl;
        free(buffer);
        return false;
    }

    // compare sequences.
    for(int count = 0; compareOK && count < 50; ++count)
    {
        compareOK &= asres.ocseq().at(count) == (uint8_t)count;
        compareOK &= asres.chseq().at(count) == (char)count;
        compareOK &= asres.ushseq().at(count) == (uint16_t)count;
        compareOK &= asres.shseq().at(count) == (int16_t)count;
        compareOK &= asres.ulseq().at(count) == (uint32_t)count;
        compareOK &= asres.lseq().at(count) == (int32_t)count;
        compareOK &= asres.ullseq().at(count) == (uint64_t)count;
        compareOK &= asres.llseq().at(count) == (int64_t)count;
        compareOK &= asres.fseq().at(count) == (float)count;
        compareOK &= asres.dseq().at(count) == (double)count;
    }

    if(!compareOK)
    {
        std::cout << "TEST FAILED<FMainTest>: Wrong values in sequences" << std::endl;
        free(buffer);
        return false;
    }

    free(buffer);

    return true;
}

bool FBug94Test()
{
    Bug94Test::outerStructComplex2 ox2;

    ox2.short_value(32);
    ox2.char_value(43);
    ox2.is1_value().char_value(112);
    ox2.is1_value().string_value("Hola a todos caballeros");
    for(int32_t count = 0; count < 5; ++count)
    {
        ox2.is1_value().array_long().at(count) = count;
    }
    ox2.is2_value().char_value(34);
    ox2.is2_value().string_value("Que tal va eso?");
    for(int32_t count = 0; count < 34; ++count)
    {
        ox2.is2_value().short_seq().push_back((int16_t)count);
    }
    ox2.isc2_value().longlong_value(-34534);
    ox2.isc2_value().float_value(3.12);
    ox2.isc2_value().double_value(432.434);
    ox2.isc2_value().iis_value().char_value(35);
    ox2.isc2_value().iis_value().string_value("No nos podemos quejar");
    for(int32_t count = 0; count < 12; ++count)
    {
        ox2.isc2_value().iis_value().short_seq().push_back((int16_t)count);
    }
    ox2.isc2_value().ulong_value((uint32_t)345564);

    // Create the serializer object.
    char *buffer = (char*)calloc(1, ox2.getMaxSerializedSize());
    eProsima::FastBuffer fbuffer(buffer, ox2.getMaxSerializedSize());
    ArraysAndSequencesSer serializer(fbuffer);

    // Serialize structure.
    try
    {
        serializer << ox2;
    }
    catch(eProsima::Exception &ex)
    {
        std::cout << "TEST FAILED<FBug94Test>: Serialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Reset serializer object.
    serializer.reset();

    // Object used to deserialize the data.
    Bug94Test::outerStructComplex2 ox2res;

    // Deserialize structure.
    try
    {
        serializer >> ox2res;
    }
    catch(eProsima::Exception &ex)
    {
        std::cout << "TEST FAILED<FBug94Test>: Deserialization. " << ex.what() << std::endl;
        free(buffer);
        return false;
    }

    // Compare data.
    bool compareOK = true;

    // Compare data
    compareOK &= ox2.short_value() == ox2res.short_value();
    compareOK &= ox2.char_value() == ox2res.char_value();
    compareOK &= ox2.is1_value().char_value() == ox2res.is1_value().char_value();
    compareOK &= ox2.is1_value().string_value() == ox2res.is1_value().string_value();
    for(int32_t count = 0; count < 5; ++count)
    {
        compareOK &= ox2.is1_value().array_long().at(count) == ox2res.is1_value().array_long().at(count);
    }
    compareOK &= ox2.is2_value().char_value() == ox2res.is2_value().char_value();
    compareOK &= ox2.is2_value().string_value() == ox2res.is2_value().string_value();
    for(int32_t count = 0; count < 34; ++count)
    {
        compareOK &= ox2.is2_value().short_seq().at(count) == ox2res.is2_value().short_seq().at(count);
    }
    compareOK &= ox2.isc2_value().longlong_value() == ox2res.isc2_value().longlong_value();
    compareOK &= ox2.isc2_value().float_value() == ox2res.isc2_value().float_value();
    compareOK &= ox2.isc2_value().double_value() == ox2res.isc2_value().double_value();
    compareOK &= ox2.isc2_value().iis_value().char_value() == ox2res.isc2_value().iis_value().char_value();
    compareOK &= ox2.isc2_value().iis_value().string_value() == ox2res.isc2_value().iis_value().string_value();
    for(int32_t count = 0; count < 12; ++count)
    {
        compareOK &= ox2.isc2_value().iis_value().short_seq().at(count) == ox2res.isc2_value().iis_value().short_seq().at(count);
    }
    compareOK &= ox2.isc2_value().ulong_value() == ox2res.isc2_value().ulong_value();

    if(!compareOK)
    {
        std::cout << "TEST FAILED<FBug94Test>: Wrong values in arrays" << std::endl;
        free(buffer);
        return false;
    }
    
    return true;
}

int main()
{
    bool results = true;

    results &= FMainTest();
    results &= FBug94Test();

    if(!results)
    {
        std::cout << "TEST FAILED" << std::endl;
        _exit(-1);
    }

    std::cout << "TEST SUCCESSFULLY" << std::endl;

    _exit(0);
    return 0;
}
