//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;

namespace EventHandler
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

    private:
        void OnOkButtonClicked(Object ^sender, RoutedEventArgs ^args);
        void OnkeyDown(CoreWindow ^sender, KeyEventArgs ^args);
    };
}
