This example guides you in how you have to generate the example serialization library
and how you can link it with the example application.

First step is to generate the example serialization library using the IDL file HelloWorld.idl.
Use the generation tool fastbuffers for this purpose. And example:

   $ fastbuffers HelloWorld.idl

Second step is to compile the given solution in this example for you. This
solution will create the library that serialize the types in the IDL file HelloWorld.idl
and the example application.
