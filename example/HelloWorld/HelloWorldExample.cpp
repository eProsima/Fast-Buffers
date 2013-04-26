#include "HelloWorldCDR.h"
#include "cpp/exceptions/Exception.h"

#include <iostream>

using namespace eProsima;

#define BUFFER_LENGTH 200

int main()
{
    CDRBuffer cdrbuffer;
    HelloWorldCDR helloCDR_ser(cdrbuffer);

    // Structure to serialize.
    HelloWorld hello_ser;
    hello_ser.message("Hello World");

    // Serialization.
    helloCDR_ser << hello_ser;

    // Reset the reading position in the buffer to start deserialization.
    cdrbuffer.reset();
    HelloWorldCDR helloCDR_des(cdrbuffer);

    // The buffer will be deserialized in the next structure.
    HelloWorld hello_des;

    // Deserialization.
    helloCDR_des >> hello_des;

    std::cout << hello_des.message();

    return 0;
}