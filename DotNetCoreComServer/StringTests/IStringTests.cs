using System;
using System.Runtime.InteropServices;

namespace DotNetCoreComServer.StringTests
{
	[ComVisible(true)]
	[Guid("6F6B348B-CA71-4CF5-8F51-2CD2928273CB")]
	[InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
	public interface IStringTests
	{
		/// <summary>
		/// Prints the passed in string to the console window.
		/// </summary>
		void PassInBstr([MarshalAs(UnmanagedType.BStr)]string bStr);

		/// <summary>
		/// Gets a string from the server stored as BStr.
		/// </summary>
		[return: MarshalAs(UnmanagedType.BStr)]
		string GetBstrFromComServer();

		/// <summary>
		/// Takes in a string and returns the string reversed.
		/// </summary>
		[return: MarshalAs(UnmanagedType.BStr)]
		string ReverseBstr([MarshalAs(UnmanagedType.BStr)]string bStr);
	}
}
