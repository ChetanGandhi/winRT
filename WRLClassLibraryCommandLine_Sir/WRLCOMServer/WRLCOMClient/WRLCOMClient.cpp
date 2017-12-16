using namespace Platform; // for "Array", "String"
using namespace Windows::UI; // For "Colors"
using namespace Windows::UI::Xaml; // For "Application", "ApplicationInitializationCallback" And "ApplicationInitializationCallbackParams"
using namespace Windows::UI::Xaml::Controls; // For "TextBlock"
using namespace Windows::UI::Xaml::Media; // For "FontFamily" And "SolidColorBrush"

// COM Server's namespace
#using "WRLCOMServer.winmd"
using namespace WRLCOMServer;

ref class WRLCOMClient sealed : public Windows::UI::Xaml::Application
{
public:
	virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs) override;
};

int main(Array<String^>^ args)
{
	Application::Start(ref new ApplicationInitializationCallback([](ApplicationInitializationCallbackParams^ params)
	{
		WRLCOMClient^ app = ref new WRLCOMClient();
	}));
}

void WRLCOMClient::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ pArgs)
{
	// code
    // create main Grid
	Grid^ myGrid = ref new Grid();

	// create Heading TextBlock
	TextBlock^ headingTextBlock = ref new TextBlock();
	headingTextBlock->Text = "Calculator";
	Thickness thickness(0, 60, 0, 0);
	headingTextBlock->Margin = Thickness(0, 60, 0, 0);
	headingTextBlock->FontSize = 96;
	headingTextBlock->FontFamily = ref new FontFamily("Segoe UI");
	headingTextBlock->FontWeight = Windows::UI::Text::FontWeights::Bold;
	headingTextBlock->Foreground = ref new SolidColorBrush(Colors::Yellow);
	headingTextBlock->HorizontalAlignment = HorizontalAlignment::Center;
	headingTextBlock->VerticalAlignment = VerticalAlignment::Top;

	// use sever services
	int a = 75;
	int b = 25;

	// create object of imported C++ component
	auto myComServer = ref new CSumSubtract();
	int sum = myComServer->SumOfTwoIntegers(a, b);
	int sub = myComServer->SubtractionOfTwoIntegers(a, b);

	// create Sum TextBlock
	TextBlock^ sumTextBlock = ref new TextBlock();
	sumTextBlock->Text = "Sum Of " + a + " And " + b + " = " + sum.ToString();
	sumTextBlock->Margin = Thickness(0, 100, 0, 0);
	sumTextBlock->FontSize = 64;
	sumTextBlock->FontFamily = ref new FontFamily("Segoe UI");
	sumTextBlock->Foreground = ref new SolidColorBrush(Colors::Cyan);
	sumTextBlock->HorizontalAlignment = HorizontalAlignment::Left;
	sumTextBlock->VerticalAlignment = VerticalAlignment::Center;

	// create Subtract TextBlock
	TextBlock^ subTextBlock = ref new TextBlock();
	subTextBlock->Text = "Sub Of " + a + " And " + b + " = " + sub.ToString();
	subTextBlock->Margin = Thickness(0, 180, 0, 0);
	subTextBlock->FontSize = 64;
	subTextBlock->FontFamily = ref new FontFamily("Segoe UI");
	subTextBlock->Foreground = ref new SolidColorBrush(Colors::Yellow);
	subTextBlock->HorizontalAlignment = HorizontalAlignment::Left;
	subTextBlock->VerticalAlignment = VerticalAlignment::Center;

	// add above 3 TextBlocks to Grid as children
	myGrid->Children->Append(headingTextBlock);
	myGrid->Children->Append(sumTextBlock);
	myGrid->Children->Append(subTextBlock);

	Window::Current->Content = myGrid;
	Window::Current->Activate();
}
