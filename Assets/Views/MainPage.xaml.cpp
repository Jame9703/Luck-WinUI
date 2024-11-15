#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI;
using namespace Xaml;
using namespace Windowing;


// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Luck::implementation
{
	int32_t MainPage::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void MainPage::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	// 导航，获取窗口并储存在 this_AppWindow 中。
	void MainPage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs e)
	{
		using namespace winrt::Microsoft::UI::Xaml;

		try
		{
			Window w_window = e.Parameter().try_as<Window>();
			if (!w_window) __debugbreak();
			this_AppWindow = w_window.AppWindow();
		}
		catch (winrt::hresult_error const& ex)
		{
			winrt::hresult hr = ex.code();
			winrt::hstring message = ex.message();

			__debugbreak();
			MessageBox(NULL, L"严重错误，窗口处理失败。\n", ERROR_TITLE, MB_OK);
			abort();
		}


	}



	void MainPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
	{
		//myButton().Content(box_value(L"Clicked"));
	}
	void MainPage::Button_Click(IInspectable const& sender, RoutedEventArgs const& args)
	{
		using namespace Microsoft::UI::Xaml::Controls;
		LuckSet::SelectedNumber = 1;


		TextBlock name, dialogContent;
		name.Text(L"结果");

		ContentDialog dialog;
		dialog.XamlRoot(this->XamlRoot());
		dialog.Title(name);
		dialog.DefaultButton(ContentDialogButton::Primary);


		switch (LuckSet::JudgePrize())
		{
		case 0: 
			dialogContent.Text(L"请选择你的幸运数字");
			break;
		case 1: 
			dialogContent.Text(L"恭喜你抽到一等奖"); 
			break;
		case 2: 
			dialogContent.Text(L"恭喜你抽到二等奖"); 
			break;
		case 3:
			dialogContent.Text(L"恭喜你抽到三等奖");
			break;
		case -1:
			dialogContent.Text(L"所有奖项均已抽完"); 
			break;
		default:
			break;
		}
		dialog.Content(dialogContent);
		dialog.PrimaryButtonText(L"好的");
		dialog.SecondaryButtonText(L"不好");
		dialog.ShowAsync();

	}
	void MainPage::ExitButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
	{

		Application::Current().Exit();
	}
	void MainPage::RenewButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
	{
		using namespace Microsoft::UI::Windowing;
		if (this_AppWindow.Presenter().Kind() == AppWindowPresenterKind::FullScreen)
			this_AppWindow.SetPresenter(AppWindowPresenterKind::Default);
		else this_AppWindow.SetPresenter(AppWindowPresenterKind::FullScreen);
	}
	void MainPage::SettingsButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
	{

	}
}
