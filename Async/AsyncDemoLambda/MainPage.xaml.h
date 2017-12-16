//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

// My Namespaces
using namespace Platform; // for String class
using namespace Windows::Storage; // for StorageFile class
using namespace Windows::Storage::Streams; // for DataReader class

namespace AsyncDemo
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
		// My Private Data
	private:
		StorageFile^ m_File;
		DataReader^ m_DataReader;
		String^ m_szFileData;
	public:
		MainPage();
	};
}
