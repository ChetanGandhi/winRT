//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace EventHandler;
using namespace Platform;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;


/*
using namespace Windows::Foundation;
using namespace Windows::System;
*/

MainPage::MainPage()
{
    InitializeComponent();
    Window::Current->CoreWindow->KeyDown += ref new TypedEventHandler<CoreWindow ^, KeyEventArgs ^>(this, &MainPage::OnkeyDown);
}

void MainPage::OnkeyDown(CoreWindow ^sender, Windows::UI::Core::KeyEventArgs ^args)
{
    if(args->VirtualKey != VirtualKey::Space && args->VirtualKey != VirtualKey::Enter)
    {
        tb->Text = args->VirtualKey.ToString();
    }
}

void MainPage::OnOkButtonClicked(Object^ sender, RoutedEventArgs^ e)
{
    if(tb->Text == "Hello World")
    {
        tb->Text = "Good bye";
    }
    else
    {
        tb->Text = "Hello World";
    }
}

