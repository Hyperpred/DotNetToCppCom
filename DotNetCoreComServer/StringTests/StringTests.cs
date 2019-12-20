using System;
using System.Runtime.InteropServices;

namespace DotNetCoreComServer.StringTests
{
	[ComVisible(true)]
	[Guid("AC65770F-2F38-4F3A-ABD4-697E53EB8482")]
	
	public class StringTests : IStringTests
	{
		public StringTests() { }

		[return: MarshalAs(UnmanagedType.BStr)]
		public string GetBstrFromComServer()
		{
			return "Hello from the COM Server!";
		}

		public void PassInBstr([MarshalAs(UnmanagedType.BStr)] string bStr)
		{
			Console.WriteLine($"ComServer: COM client passed in {bStr} as a BString");
		}

		[return: MarshalAs(UnmanagedType.BStr)]
		public string ReverseBstr([MarshalAs(UnmanagedType.BStr)] string bStr)
		{
			char[] charArray = bStr.ToCharArray();
			Array.Reverse(charArray);
			return new string(charArray);
		}
	}
}
