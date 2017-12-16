//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace HelloWorldNoGrid;

MainPage::MainPage()
{
	InitializeComponent();
    //my code

    Windows::UI::Xaml::Controls::Grid^ grid = ref new Windows::UI::Xaml::Controls::Grid();
    grid->Background = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Black);

    Windows::UI::Xaml::Controls::TextBlock^ textBlock = ref new Windows::UI::Xaml::Controls::TextBlock();
    textBlock->Text = "Hello World No Grid!";
    textBlock->FontFamily = ref new Windows::UI::Xaml::Media::FontFamily("Segoe UI");
    textBlock->FontSize = 120.0;
    textBlock->FontStyle = Windows::UI::Text::FontStyle::Oblique;
    textBlock->FontWeight = Windows::UI::Text::FontWeights::Bold;
    textBlock->Foreground = ref new Windows::UI::Xaml::Media::SolidColorBrush(Windows::UI::Colors::Gold);
    textBlock->VerticalAlignment = Windows::UI::Xaml::VerticalAlignment::Center;
    textBlock->HorizontalAlignment = Windows::UI::Xaml::HorizontalAlignment::Center;

    grid->Children->Append(textBlock);
    this->Content = grid;
}
