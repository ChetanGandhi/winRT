//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

// My Namespaces
using namespace Platform; // for String class
using namespace Windows::Foundation; // for IAsyncOperation interface
using namespace Windows::Storage; // for StorageFile class
using namespace Windows::Storage::Streams; // for IRandomAccessStream
using namespace Windows::UI::Popups; // for MessageDialog class, IUICommand interface

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
		// My Public Methods
		void OnPickSingleFileAsyncCompleted(IAsyncOperation<StorageFile^>^ asyncOperation, AsyncStatus asyncStatus);
		void OnFileOpenPickerCancelDispatcherCallback(void);
		void OnOpenReadAsyncCompleted(IAsyncOperation<IRandomAccessStream^>^ asyncOperation, AsyncStatus asyncStatus);
		void OnLoadAsyncCompleted(IAsyncOperation<UINT> ^asyncOperation, AsyncStatus asyncStatus);
		void OnLoadAsyncCompletedDispatcherCallback(void);
		void OnShowAsyncCompleted(IAsyncOperation<IUICommand^>^ asyncOperation, AsyncStatus asyncStatus);
		void OnShowAsyncCompletedDispatcherCallback(void);
	};
}
