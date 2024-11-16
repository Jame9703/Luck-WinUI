#include "pch.h"
#include "MainPage.xaml.h"
#include "Assets/Views/SettingsPage.xaml.h"
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

	// ��������ȡ���ڲ������� this_AppWindow �С�
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
			MessageBox(NULL, L"���ش��󣬴��ڴ���ʧ�ܡ�\n", ERROR_TITLE, MB_OK);
			abort();
		}


	}

	void MainPage::Button_Click(IInspectable const& sender, RoutedEventArgs const& args)
	{
		using namespace Microsoft::UI::Xaml::Controls;
		LuckSet::SelectedNumber = 1;


		TextBlock name, dialogContent;
		name.Text(L"���");

		ContentDialog dialog;
		dialog.XamlRoot(this->XamlRoot());
		dialog.Title(name);
		dialog.DefaultButton(ContentDialogButton::Primary);


		switch (LuckSet::JudgePrize())
		{
		case 0: 
			dialogContent.Text(L"��ѡ�������������");
			break;
		case 1: 
			dialogContent.Text(L"��ϲ��鵽һ�Ƚ�"); 
			break;
		case 2: 
			dialogContent.Text(L"��ϲ��鵽���Ƚ�"); 
			break;
		case 3:
			dialogContent.Text(L"��ϲ��鵽���Ƚ�");
			break;
		case -1:
			dialogContent.Text(L"���н�����ѳ���"); 
			break;
		default:
			break;
		}
		dialog.Content(dialogContent);
		dialog.PrimaryButtonText(L"�õ�");
		dialog.SecondaryButtonText(L"����");
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
		//xaml_typenameδ����
		//winrt::Microsoft::UI::Xaml::Controls::Frame rootFrame = Microsoft::UI::Xaml::Controls::Frame();
		//rootFrame.Navigate(xaml_typename<SettingsPage>());
	}
}
