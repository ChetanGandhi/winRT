#using "WRLCOMServer.winmd"

using namespace Platform;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Text;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

using namespace WRLCOMServer;

ref class WRLCOMClient sealed : public Application
{
public:
    virtual void OnLaunched(LaunchActivatedEventArgs ^args) override;
};

int main(Array<String ^> ^args)
{
    Application::Start(ref new ApplicationInitializationCallback(
        [](ApplicationInitializationCallbackParams ^params)
    {
        WRLCOMClient ^wrlComClient = ref new WRLCOMClient();
    }));

    return 0;
}

void WRLCOMClient::OnLaunched(LaunchActivatedEventArgs ^args)
{
    MessageDialog ^dialog;
    CSumSubtract ^cSumSubtract;
    int numberOne = 300;
    int numberTwo = 200;
    int sum = 0;
    int subtraction = 0;

    Page ^page = ref new Page();
    Grid ^grid = ref new Grid();
    grid->Background = ref new SolidColorBrush(Colors::Black);

    TextBlock ^textBlock = ref new TextBlock();
    textBlock->FontFamily = ref new Media::FontFamily("Segoe UI");
    textBlock->FontSize = 40.0;
    textBlock->FontStyle = FontStyle::Oblique;
    textBlock->FontWeight = FontWeights::Bold;
    textBlock->Foreground = ref new Media::SolidColorBrush(Colors::Gold);
    textBlock->VerticalAlignment = VerticalAlignment::Center;
    textBlock->HorizontalAlignment = HorizontalAlignment::Center;

    grid->Children->Append(textBlock);
    page->Content = grid;
    Window::Current->Content = page;
    Window::Current->Activate();

    try
    {
        cSumSubtract = ref new CSumSubtract();

        sum = cSumSubtract->SumOfTwoInteger(numberOne, numberTwo);
        subtraction = cSumSubtract->SubtractionOfTwoInteger(numberOne, numberTwo);
        textBlock->Text = "Sun of " + numberOne + " and " + numberTwo + " is: " + sum + "\nSubtraction of " + numberOne + " and " + numberTwo + " is: "  + subtraction;
    }
    catch(Exception ^e)
    {
        dialog = ref new MessageDialog("WRLCOMServer", "Error: " + e->ToString());
        dialog->ShowAsync();
    }
}
