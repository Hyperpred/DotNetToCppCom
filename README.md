# DotNetToCppCom

Recently I needed to have an unmanaged c++ project (not CLI/CLR) access a newer .net core library. I also needed this access to be registration free. Finding information on the internet was tedious. .Net core started supporting COM in version 3.1 which was released in November 2019. At the time most of the information on the internet involved .Net Framework. In addition most samples and troubleshooting assume you are using regasm. 

I created this repository to help others who specifically need .Net Core and registration free com from an unmanaged C++ project.

It aims to provide useful easy to follow samples with multiple scenarios. This is not production level code and there is little to no safety checking done. It is also not all encompassing in terms of COM usage. But, it should help get you started.



