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
using namespace Windows::UI::Core; // CoreDispatcherPriority enum
using namespace Windows::UI::Xaml::Media; // for SolidColorBrush class

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
	IAsyncOperation<StorageFile^>^ storageFileAsyncOperation = filePicker->PickSingleFileAsync(); // 'auto' should be used
	// set FileOpenPicker::PickSingleFileAsync() method's completion handeler method pointer
	storageFileAsyncOperation->Completed = ref new AsyncOperationCompletedHandler<StorageFile^>
		([=](IAsyncOperation<StorageFile^>^ asyncOperation, AsyncStatus asyncStatus)
	{
		// code
		// get chosen file StorageFile object
		m_File = asyncOperation->GetResults();
		if (m_File) // if user selcts a file and then presses "Open" button of FileOpenPicker
		{
			// open the chosen file
			IAsyncOperation<IRandomAccessStream^>^ randomAccessStreamAsyncOperation = m_File->OpenAsync(FileAccessMode::Read); // 'auto' should be used
			// set StorageFile::OpenAsync() method's completion handeler method pointer
			randomAccessStreamAsyncOperation->Completed = ref new AsyncOperationCompletedHandler<IRandomAccessStream^>
				([=](IAsyncOperation<IRandomAccessStream^>^ asyncOperation, AsyncStatus asyncStatus)
			{
				// code
				// get open file's read stream interface
				IRandomAccessStream^ readStream = asyncOperation->GetResults(); // 'auto' should be used

				// get DataReader object for above read stream
				m_DataReader = ref new DataReader(readStream);
				// load the read file content data into memory
				DataReaderLoadOperation^ readData = m_DataReader->LoadAsync((UINT)readStream->Size); // 'auto' should be used

				// set DataReader::LoadAsync() method's completion handeler method pointer
				readData->Completed = ref new AsyncOperationCompletedHandler<UINT>
					([=](IAsyncOperation<UINT>^ asyncOperation, AsyncStatus asyncStatus)
				{
					// code
					// get number of read bytes
					UINT readBytes = asyncOperation->GetResults(); // 'auto' should be used
					// read memory loaded file content data as string
					m_szFileData = m_DataReader->ReadString(readBytes);

					IAsyncAction^ asyncAction = this->Dispatcher->RunAsync(CoreDispatcherPriority::Normal,
						ref new DispatchedHandler([=]()
					{
						// code
						// display MessageDialog with file content data string and file name
						MessageDialog^ msgDlg = ref new MessageDialog(m_szFileData, m_File->Name); // 'auto' should be used
						IAsyncOperation<IUICommand^>^ showAsyncOperation = msgDlg->ShowAsync();

						// after pressing "Ok" of MessageDialog
						// set MessageDialog::ShowAsync() method's completion handeler method pointer
						showAsyncOperation->Completed = ref new AsyncOperationCompletedHandler<IUICommand^>
							([=](IAsyncOperation<IUICommand^>^ asyncOperation, AsyncStatus asyncStatus)
						{
							// code
							// actually following variable is not used anywhere, but it is to show the demo of action to take on MessageDialog's button press
							IUICommand^ pressedMessageDialogButton = asyncOperation->GetResults(); // 'auto' should be used

							IAsyncAction^ asyncAction = this->Dispatcher->RunAsync(CoreDispatcherPriority::Normal,
								ref new DispatchedHandler([=]()
							{
								// code
								msgTextBlock->Foreground = ref new SolidColorBrush(Windows::UI::Colors::LimeGreen);
								msgTextBlock->Text = "Done !!!";
							}));
						});
					}));
				});
			});
		}
		else // if user presses "Cancel" button of FileOpenPicker
		{
			IAsyncAction^ asyncAction = this->Dispatcher->RunAsync(CoreDispatcherPriority::Normal,
				ref new DispatchedHandler([=]()
			{
				// code
				msgTextBlock->Foreground = ref new SolidColorBrush(Windows::UI::Colors::Red);
				msgTextBlock->Text = "Cancelled !!!";
			}));
		}
	});
}
