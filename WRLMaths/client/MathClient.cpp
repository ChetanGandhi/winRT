#using "MathServer.winmd"

using namespace Platform;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI;
using namespace Windows::UI::Popups;
using namespace Windows::UI::Text;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Media;

using namespace MathServer;

ref class MathClient sealed : public Application
{
public:
	virtual void OnLaunched(LaunchActivatedEventArgs ^args) override;
};

int main(Array<String ^> ^args)
{
	Application::Start(ref new ApplicationInitializationCallback(
		[](ApplicationInitializationCallbackParams ^params)
	{
		MathClient ^client = ref new MathClient();
	}));

	return 0;
}

void MathClient::OnLaunched(LaunchActivatedEventArgs ^args)
{
	MessageDialog ^dialog;
	CMath ^math;
	int number = 2;
	int square = 0;
	int cube = 0;

	Page ^page = ref new Page();
	Grid ^grid = ref new Grid();
	grid->Background = ref new SolidColorBrush(Colors::Black);

	TextBlock ^textBlock = ref new TextBlock();
	textBlock->FontFamily = ref new Media::FontFamily("Segoe UI");
	textBlock->FontSize = 40.0;
	textBlock->FontWeight = FontWeights::Bold;
	textBlock->Foreground = ref new SolidColorBrush(Colors::White);
	textBlock->VerticalAlignment = VerticalAlignment::Center;
	textBlock->HorizontalAlignment = HorizontalAlignment::Center;

	grid->Children->Append(textBlock);
	page->Content = grid;
	Window::Current->Content = page;
	Window::Current->Activate();

	try
	{
		math = ref new CMath();
		square = math->SquareOfInteger(number);
		cube = math->CubeOfInteger(number);

		textBlock->Text = "Square of " + number + " is: " + square + "\nCube of " + number + " is: " + cube;

	}
	catch(Exception ^exception)
	{
		dialog = ref new MessageDialog("MathClient", "Error: " + exception->ToString());
		dialog->ShowAsync();
	}
}
