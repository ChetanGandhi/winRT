using namespace Platform;
using namespace Windows::UI::Xaml;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Text;
using namespace Windows::UI;

ref class HelloWorldBackToCommandLine sealed : public Application
{
public:
    virtual void OnLaunched(LaunchActivatedEventArgs ^args) override;
};

int main(Array<String ^> ^args)
{
    Application::Start(ref new ApplicationInitializationCallback(
        [](ApplicationInitializationCallbackParams ^params)
    {
        HelloWorldBackToCommandLine ^helloWorldBackToCommandLine = ref new HelloWorldBackToCommandLine();
    }));

    return 0;
}

void HelloWorldBackToCommandLine::OnLaunched(LaunchActivatedEventArgs ^args)
{
    Page ^page = ref new Page();
    Grid ^grid = ref new Grid();
    grid->Background = ref new SolidColorBrush(Colors::Black);

    TextBlock ^textBlock = ref new TextBlock();
    textBlock->Text = "Back To Command Line";
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
