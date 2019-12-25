using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;

namespace DotNetCoreComServer.StringTests
{
	[ComVisible(true)]
	[Guid("AC65770F-2F38-4F3A-ABD4-697E53EB8482")]

	public class StringTests : IStringTests
	{
		public StringTests() { }

		#region Get a value from the server with no parameters
		[return: MarshalAs(UnmanagedType.BStr)]
		public string GetBStrFromComServer()
		{
			return GetStringFromComServer() + " as BStr";
		}

		[return: MarshalAs(UnmanagedType.LPStr)]
		public string GetLPStrFromComServer()
		{
			return GetStringFromComServer() + " as LPStr";
		}

		[return: MarshalAs(UnmanagedType.LPWStr)]
		public string GetLPWStrFromComServer()
		{
			return GetStringFromComServer() + " as LPWStr";
		}

		[return: MarshalAs(UnmanagedType.LPUTF8Str)]
		public string GetLPUTF8StrFromComServer()
		{
			return GetStringFromComServer() + " as LPUTF8Str";
		}
		#endregion

		#region Pass in a value to the com server with no return
		public void PassInBStr([MarshalAs(UnmanagedType.BStr)] string bStr)
		{
			PassInString(bStr, "BString");
		}

		public void PassInLPStr([MarshalAs(UnmanagedType.LPStr)] string lpstr)
		{
			PassInString(lpstr, "LPStr");
		}

		public void PassInLPWStr([MarshalAs(UnmanagedType.LPWStr)] string lpwstr)
		{
			PassInString(lpwstr, "LPWStr");
		}

		public void PassInLPUTF8Str([MarshalAs(UnmanagedType.LPUTF8Str)] string lputf8str)
		{
			PassInString(lputf8str, "LPUTF8Str");
		}
		#endregion

		public void PassInByRefBStr([MarshalAs(UnmanagedType.BStr)] ref string bStr)
		{
			PassInByRefString(ref bStr);
		}

		public void PassInByRefLPStr([MarshalAs(UnmanagedType.LPStr)] ref string lpstr)
		{
			PassInByRefString(ref lpstr);
		}

		public void PassInByRefLPWStr([MarshalAs(UnmanagedType.LPWStr)] ref string lpwstr)
		{
			PassInByRefString(ref lpwstr);
		}

		public void PassInByRefLPUTF8Str([MarshalAs(UnmanagedType.LPUTF8Str)] ref string lputf8str)
		{
			PassInByRefString(ref lputf8str);
		}


		#region Pass in and return a value from the server
		[return: MarshalAs(UnmanagedType.BStr)]
		public string ReverseBStr([MarshalAs(UnmanagedType.BStr)] string bStr)
		{
			return ReverseString(bStr);
		}

		[return: MarshalAs(UnmanagedType.HString)]
		public string ReverseHString([MarshalAs(UnmanagedType.HString)]string hString)
		{
			return ReverseString(hString);
		}

		[return: MarshalAs(UnmanagedType.LPStr)]
		public string ReversLPStr([MarshalAs(UnmanagedType.LPStr)] string lpstr)
		{
			return ReverseString(lpstr);
		}

		[return: MarshalAs(UnmanagedType.LPWStr)]
		public string ReverseLPWStr([MarshalAs(UnmanagedType.LPWStr)] string lpwstr)
		{
			return ReverseString(lpwstr);
		}

		[return: MarshalAs(UnmanagedType.LPUTF8Str)]
		public string ReverseLPUTF8Str([MarshalAs(UnmanagedType.LPUTF8Str)] string lputf8str)
		{
			return ReverseString(lputf8str);
		}
		#endregion

		#region Common implementations
		private string ReverseString(string parameter, [CallerMemberName]string callerMemberName = default)
		{
			Console.WriteLine($"ComServer: COM Client passed in \"{parameter}\" from {callerMemberName}. Reversing string.");
			char[] charArray = parameter.ToCharArray();
			Array.Reverse(charArray);
			return new string(charArray);
		}

		private string GetStringFromComServer()
		{
			return "Hello from the COM Server!";
		}

		private void PassInString(string parameter, string parameterTpe)
		{
			Console.WriteLine($"ComServer: COM Client passed in {parameter} as a {parameterTpe}.");
		}

		private void PassInByRefString(ref string parameter, [CallerMemberName] string callerMemberName = default)
		{
			Console.WriteLine($"ComServer: Com Client passed in \"{parameter}\" from {callerMemberName}. Modifying string.");
			parameter = $"String was modified by the com server from {callerMemberName}";
		}
		#endregion

	}
}
