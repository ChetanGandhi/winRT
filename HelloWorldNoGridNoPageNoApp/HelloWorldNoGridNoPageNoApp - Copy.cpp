#include "pch.h"

using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Text;
using namespace Windows::UI;

ref class App sealed : public Application
{
public:
    virtual void OnLaunched(LaunchActivatedEventArgs ^args) override;
};

int main(Array<String ^> ^args)
{
    Application::Start(ref new ApplicationInitializationCallback(
        [](ApplicationInitializationCallbackParams ^params)
    {
        App ^app = ref new App();
    }));

    return 0;
}

void App::OnLaunched(LaunchActivatedEventArgs ^args)
{
    Page ^page = ref new Page();
    Grid ^grid = ref new Grid();
    grid->Background = ref new SolidColorBrush(Colors::Black);

    TextBlock ^textBlock = ref new TextBlock();
    textBlock->Text = "Hello World No Grid No Page No App";
    textBlock->FontFamily = ref new Media::FontFamily("Segoe UI");
    textBlock->FontSize = 60.0;
    textBlock->FontStyle = FontStyle::Oblique;
    textBlock->FontWeight = FontWeights::Bold;
    textBlock->Foreground = ref new Media::SolidColorBrush(Colors::Gold);
    textBlock->VerticalAlignment = VerticalAlignment::Center;
    textBlock->HorizontalAlignment = HorizontalAlignment::Center;

    grid->Children->Append(textBlock);
    page->Content = grid;
    Window::Current->Content = page;
    Window::Current->Activate();
}
