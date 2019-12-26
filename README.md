# DotNetToCppCom

Recently I needed to have an unmanaged c++ project (not CLI/CLR) access a newer .net core library. I also needed this access to be registration free. Finding information on the internet was tedious. .Net core started supporting COM in version 3.1 which was released in November 2019. At the time most of the information on the internet involved .Net Framework. In addition most samples and troubleshooting assume you are using regasm. 

I created this repository to help others who specifically need .Net Core and registration free com from an unmanaged C++ project.

It aims to provide useful easy to follow samples with multiple scenarios. This is not production level code and there is little to no safety checking done. It is also not all encompassing in terms of COM usage. But, it should help get you started.

The COM server contains classes which are named to show specifically the kind of samples they contain. The COM Client will also contain classes which should share a similar name to the COM server call that they test. The IDL file also tries to stay as close to the COM server definition as possible. Where there are differences I tried to leave a comment pointing out why. Also, the COM Client contains comments in sections where the behavior differs from other samples.

**Note**: If you wanted to use these samples with a registered com server pretty much everything should be the same as far as code goes. You will just need to register the server with regasm and make the calls that way. Also, you shouldn't need the unmanaged manifest file.

As more samples are added I will continue to update this README.

## Scenarios

### Mmarshalling various data types from .net core to unmanaged c++.
* **Strings**
	*  There are samples for pretty much all of the strings you should need. BSTR, HString, UTF-8 char* and wchar* 

### Using COM in an unmanaged dll being used by an unmanaged exe. (NOT IMPLEMENTED YET)
If you have an exe that references multiple dll's you can use the COM Server within those dll's without any additional work beyond generating the manifest for the exe.

### Calling a non-COM exposed dll from the COM server. (NOT IMPLEMENTED YET)
This scenario would be for times when you have a .Net Core dll that you are unable to modify, and instead, must create a COM Server wrapper around. It works as you would expect it to, in that the COM server would reference the dll and make calls into it like normal. The additional calls do not need to be exposed to COM.


## Requirements
.Net Core support for COM is windows only.


### .Net Core
Using .Net Core as a COM server requires version 3.1 or higher.


### Unmanaged C++ Client
There are no special requirements in terms of c++ version. As long as it supports COM it should support a .Net Core COM server.

## Additional Notes

There are pre-build steps in the C++ projects as well as post-build steps in the C# projects. This is to make it easier to run the sample out of the box. In your own project you will either need to do these steps manually, or create similar build steps.

These include copying files to the output directories as well as automatically running the midl.exe to generate the files needed for the C++ executable.

You can find additional information on the midl executable here - https://docs.microsoft.com/en-us/windows/win32/midl/using-the-midl-compiler-2. 

A tutorial that was helpful in setting up the COM server (especially the idl file) is here http://progtutorials.tripod.com/COM.htm.

### IDL File

I have placed the IDL file next to the UnmanagedComClient.vcxproj. I did this because it makes it easier to use the output files from midl.exe. Keep in mind, the IDL file is actually a description of the COM server not the client.
