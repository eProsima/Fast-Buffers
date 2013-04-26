This example guides you in how you have to generate the example serialization library
and how you can link it with the example application.

First step is to generate the example serialization library using the IDL file HelloWorld.idl.
Use the generation tool efastbuffers for this purpose. Also use this tool to generate the solution
you desire to compile the generated code. And example:

   $ efastbuffers -example x64Win64VS2010 HelloWorld.idl

Second step is to compile the solution that the tool efastbuffer creates for you. This will create
the library that serialize the types in the IDL file HelloWorld.idl.

At last open the solution for the example application and compile it.
