#include "HelloWorldSer.h"
#include "cpp/storage/FastBuffer.h"
#include "cpp/exceptions/Exception.h"

#include <iostream>

using namespace eProsima;
using namespace eProsima::storage;

#define BUFFER_LENGTH 200

int main()
{
    FastBuffer fastbuffer;
    HelloWorldSer hellocdr_ser(fastbuffer);

    // Structure to serialize.
    HelloWorld hello_ser;
    hello_ser.message("Hello World");

    // Serialization.
    hellocdr_ser << hello_ser;

    // Reset the reading position in the serializer object to start deserialization.
    hellocdr_ser.reset();

    // The buffer will be deserialized in the next structure.
    HelloWorld hello_des;

    // Deserialization.
    hellocdr_ser >> hello_des;

    std::cout << hello_des.message() << std::endl;

    return 0;
}
