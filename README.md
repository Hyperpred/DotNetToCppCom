# DotNetToCppCom

Recently I needed to have an unmanaged c++ project (not CLI/CLR) access a newer .net core library. I also needed this access to be registration free. Finding information on the internet was tedious. .Net core started supporting COM in version 3.1 which was released in November 2019. At the time most of the information on the internet involved .Net Framework. In addition most samples and troubleshooting assume you are using regasm. 

I created this repository to help others who specifically need .Net Core and registration free com from an unmanaged C++ project.

It aims to provide useful easy to follow samples with multiple scenarios. This is not production level code and there is little to no safety checking done. It is also not all encompassing in terms of COM usage. But, it should help get you started.


##Scenarios

Samples for marshalling various data types from .net core to unmanaged c++.

Using COM in an unmanaged DLL being used by an unmanaged exe.

Calling a non-com exposed dll from the com server.

##Requirements
.Net Core support for COM is windows only.


###.Net Core


###Unmanaged C++ Client

##Additional Notes

There are pre-build steps in the C++ projects as well as post-build steps in the C# projects. This is to make it easier to run the sample out of the box. In your own project you will either need to do these steps manually, or create similar build steps.

These include copying files to the output directories as well as automatically running the midl.exe to generate the files needed for the C++ executable.

You can find additional information on the midl executable here - https://docs.microsoft.com/en-us/windows/win32/midl/using-the-midl-compiler-2. 

A tutorial that was helpful in setting up the com server (especially the idl file) is here http://progtutorials.tripod.com/COM.htm.

###IDL File

I have placed the IDL file next to the UnmanagedComClient.vcxproj. I did this because it makes it easier to use the output files from midl.exe. Keep in mind, the IDL file is actually a description of the COM server not the client.

###TLB File

