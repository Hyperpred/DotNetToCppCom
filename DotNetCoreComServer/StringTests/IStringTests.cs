using System;
using System.Runtime.InteropServices;

namespace DotNetCoreComServer.StringTests
{
	[ComVisible(true)]
	[Guid("6F6B348B-CA71-4CF5-8F51-2CD2928273CB")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IStringTests
	{
		[return: MarshalAs(UnmanagedType.BStr)]
		public string GetBStrFromComServer();

		[return: MarshalAs(UnmanagedType.LPStr)]
		public string GetLPStrFromComServer();

		[return: MarshalAs(UnmanagedType.LPWStr)]
		public string GetLPWStrFromComServer();

		[return: MarshalAs(UnmanagedType.LPUTF8Str)]
		public string GetLPUTF8StrFromComServer();

		public void PassInBStr([MarshalAs(UnmanagedType.BStr)] string bStr);
		public void PassInLPStr([MarshalAs(UnmanagedType.LPStr)] string lpstr);
		public void PassInLPWStr([MarshalAs(UnmanagedType.LPWStr)] string lpwstr);
		public void PassInLPUTF8Str([MarshalAs(UnmanagedType.LPUTF8Str)] string lputf8str);

		public void PassInByRefBStr([MarshalAs(UnmanagedType.BStr)] ref string bStr);
		public void PassInByRefLPStr([MarshalAs(UnmanagedType.LPStr)] ref string lpstr);
		public void PassInByRefLPWStr([MarshalAs(UnmanagedType.LPWStr)] ref string lpwstr);
		public void PassInByRefLPUTF8Str([MarshalAs(UnmanagedType.LPUTF8Str)] ref string lputf8str);

		[return: MarshalAs(UnmanagedType.BStr)]
		public string ReverseBStr([MarshalAs(UnmanagedType.BStr)] string bStr);

		[return: MarshalAs(UnmanagedType.LPStr)]
		public string ReversLPStr([MarshalAs(UnmanagedType.LPStr)] string lpstr);

		[return: MarshalAs(UnmanagedType.LPWStr)]
		public string ReverseLPWStr([MarshalAs(UnmanagedType.LPWStr)] string lpwstr);

		[return: MarshalAs(UnmanagedType.LPUTF8Str)]
		public string ReverseLPUTF8Str([MarshalAs(UnmanagedType.LPUTF8Str)] string lputf8str);
	}
}
