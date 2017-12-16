//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace AsyncDemo;

// My Namespaces
using namespace Windows::Foundation; // for IAsyncOperation interface
using namespace Windows::UI::Popups; // for MessageDialog class
using namespace Windows::UI::Xaml::Media; // for SolidColorBrush class
using namespace concurrency; // for task

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();

	// My Code
	// class variable initializations
	m_File = nullptr;
	m_DataReader = nullptr;
	m_szFileData = nullptr;

	// setup FileOpenPicker members
	Pickers::FileOpenPicker^ filePicker = ref new Pickers::FileOpenPicker();
	filePicker->SuggestedStartLocation = Windows::Storage::Pickers::PickerLocationId::DocumentsLibrary;
	filePicker->FileTypeFilter->Append(".txt");
	// display FileOpenPicker
	task<StorageFile^> fileOpenPickerTask(filePicker->PickSingleFileAsync());
	fileOpenPickerTask.then(
		[=](StorageFile^ file)->IAsyncOperation<IRandomAccessStream^>^
	{
		// code
		if (file)
		{
			m_File = file;
			return(m_File->OpenAsync(FileAccessMode::Read));
		}
		else
		{
			msgTextBlock->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Red);
			msgTextBlock->Text = "Cancelled !!!";
			throw task_canceled();
		}
	}
	).then(
		[=](IRandomAccessStream^ readStream)->DataReaderLoadOperation^
	{
		// code
		m_DataReader = ref new DataReader(readStream);
		return(m_DataReader->LoadAsync((UINT)readStream->Size));
	}
	).then(
		[=](UINT readBytes)->IAsyncOperation<IUICommand^>^
	{
		// code
		m_szFileData = m_DataReader->ReadString(readBytes);
		// display MessageDialog with file content data string and file name
		MessageDialog^ msgDlg = ref new MessageDialog(m_szFileData, m_File->Name);
		return(msgDlg->ShowAsync());
	}
	).then(
		[=](IUICommand^)
	{
		// code
		msgTextBlock->Foreground = ref new SolidColorBrush(Windows::UI::Colors::LimeGreen);
		msgTextBlock->Text = "Done !!!";
	}
	);
}
