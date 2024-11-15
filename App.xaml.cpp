#include "pch.h"
#include "App.xaml.h"
#include "Assets/Views/MainWindow.xaml.h"
#include "Assets\Classes\Luck-Class\Luck.h"
#include <winrt/Windows.Storage.h>
#include <windows.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Luck::implementation
{
	/// <summary>
	/// Initializes the singleton application object.  This is the first line of authored code
	/// executed, and as such is the logical equivalent of main() or WinMain().
	/// </summary>
	App::App()
	{
		// Xaml objects should not call InitializeComponent during construction.
		// See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
		UnhandledException([](IInspectable const&, UnhandledExceptionEventArgs const& e)
			{
				if (IsDebuggerPresent())
				{
					auto errorMessage = e.Message();
					__debugbreak();
				}
			});
#endif
	}

	/// <summary>
	/// Invoked when the application is launched.
	/// </summary>
	/// <param name="e">Details about the launch request and process.</param>
	void App::OnLaunched([[maybe_unused]] LaunchActivatedEventArgs const& e)
	{
		window = make<MainWindow>();
		window.ExtendsContentIntoTitleBar(true);//将内容延伸到标题栏区域
		//// 获取窗口句柄
		//DesktopWindowXamlSource desktopSource{ nullptr };
		//desktopSource = DesktopWindowXamlSource::GetForCurrentView();
		//HWND hwnd = reinterpret_cast<HWND>(desktopSource.GetWindowHandle());

		//// 修改窗口样式以隐藏标题栏按钮
		//LONG_PTR style = GetWindowLongPtr(hwnd, GWL_STYLE);
		//style &= ~(WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CAPTION);
		//SetWindowLongPtr(hwnd, GWL_STYLE, style);
		window.Activate();
		Windows::Storage::ApplicationDataContainer localSettings = Windows::Storage::ApplicationData::Current().LocalSettings();
		if (localSettings.Values().HasKey(L"FirstPrizeCount")
			&& localSettings.Values().HasKey(L"SecondPrizeCount")
			&& localSettings.Values().HasKey(L"ThirdPrizeCount")
			&& localSettings.Values().HasKey(L"FirstPrizeProbability")
			&& localSettings.Values().HasKey(L"SecondPrizeProbability")
			&& localSettings.Values().HasKey(L"ThirdPrizeProbability"))
		{
			int firstPrizeCount = unbox_value<int>(localSettings.Values().Lookup(L"FirstPrizeCount"));
			int secondPrizeCount = unbox_value<int>(localSettings.Values().Lookup(L"SecondPrizeCount"));
			int thirdPrizeCount = unbox_value<int>(localSettings.Values().Lookup(L"ThirdPrizeCount"));
			int firstPrizeProbability = unbox_value<int>(localSettings.Values().Lookup(L"FirstPrizeProbability"));
			int secondPrizeProbability = unbox_value<int>(localSettings.Values().Lookup(L"SecondPrizeProbability"));
			int thirdPrizeProbability = unbox_value<int>(localSettings.Values().Lookup(L"ThirdPrizeProbability"));
			LuckSet::Setup(firstPrizeCount, secondPrizeCount, thirdPrizeCount);
			LuckSet::SetPrizeProbability(firstPrizeProbability, secondPrizeProbability, thirdPrizeProbability);
		}
		else
		{
			LuckSet::Setup(10, 90, 400);
			LuckSet::SetPrizeProbability(10, 30, 60);
			localSettings.Values().Insert(L"FirstPrizeCount", box_value(10));
			localSettings.Values().Insert(L"SecondPrizeCount", box_value(90));
			localSettings.Values().Insert(L"ThirdPrizeCount", box_value(400));
			localSettings.Values().Insert(L"FirstPrizeProbability", box_value(10));
			localSettings.Values().Insert(L"SecondPrizeProbability", box_value(30));
			localSettings.Values().Insert(L"ThirdPrizeProbability", box_value(60));
		}
		// 导航到 mainpage
		winrt::Microsoft::UI::Xaml::Controls::Frame rootFrame = Microsoft::UI::Xaml::Controls::Frame();
		window.Content(rootFrame);
		rootFrame.Navigate(xaml_typename<MainPage>(), window);
	}
}
