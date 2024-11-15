#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "Assets\Classes\RippleHelper\RippleHelper.h"
#include "Assets\Classes\Luck-Class\Luck.h"
#include <winrt/Windows.UI.Popups.h>
#include <microsoft.ui.xaml.window.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::UI::Popups;
using namespace winrt::Microsoft::UI;
using namespace winrt::Microsoft::UI::Windowing;

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

    // å¯¼èˆªï¼Œè·å–çª—å£å¹¶å‚¨å­˜åœ¨ this_AppWindow ä¸­ã€‚
    void MainPage::OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs e)
    {
        using namespace winrt::Microsoft::UI::Xaml;

        
        try
        {
            Window w_window = e.Parameter().try_as<Window>();
            if (w_window) __debugbreak();
            this_AppWindow = w_window.AppWindow();
        }
        catch (winrt::hresult_error const& ex)
        {
            winrt::hresult hr = ex.code(); 
            winrt::hstring message = ex.message(); 

            __debugbreak();
            MessageBox(NULL, L"ä¸¥é‡é”™è¯¯ï¼Œçª—å£å¤„ç†å¤±è´¥ã€‚\n", L"Lucké”™è¯¯", MB_OK);
            abort();
        }

        
    }



    void MainPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        //myButton().Content(box_value(L"Clicked"));
    }
    void MainPage::Button_Click(IInspectable const& sender, RoutedEventArgs const& args)
    {
        LuckSet::SelectedNumber = 1;
        MessageDialog dialog(L"³é½±ÖĞ...");
        switch (LuckSet::JudgePrize())
        {
            case 0:
            {
                dialog.Content(L"ÇëÑ¡ÔñÄãµÄĞÒÔËÊı×Ö");
                dialog.ShowAsync();
            }
            break;
            case 1:
            {
                dialog.Content(L"¹§Ï²Äã³éµ½Ò»µÈ½±");
                dialog.ShowAsync();
            }
            break;
            case 2:
            {
                dialog.Content(L"¹§Ï²Äã³éµ½¶şµÈ½±");
                dialog.ShowAsync();
            }
            break;
            case 3:
            {
                dialog.Content(L"¹§Ï²Äã³éµ½ÈıµÈ½±");
                dialog.ShowAsync();
            }
            break;
            case -1:
            {
                dialog.Content(L"ËùÓĞ½±Ïî¾ùÒÑ³éÍê");
                dialog.ShowAsync();
            }
            break;
        }
        MessageDialog dialog1(L"");
        /*co_await*/ dialog1.ShowAsync();
    }
    void MainPage::ExitButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

        Application::Current().Exit();
    }
    void MainPage::RenewButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

        //Get access to IWindowNativewinrt::com_ptr<::IWindowNative>windowNative= warningWindow_create.as<IWindowNative>()
        // Get the HWND for the XAML Window
                //Get access to IWindowNative
        auto window = Window::Current();
        winrt::com_ptr<::IWindowNative> windowNative = window as<IWindowNative>();
        HWND hWnd;
        windowNative->get_WindowHandle(&hWnd);
        WindowId id = GetwindowIdFromwindow(hWnd);
        winrt::Microsoft::UI::Windowing::AppWindow appwind = winrt::Microsoft::UI::Windowing::AppWindow::GetFromWindowId(id);
        appwind.SetPresenter(AppWindowPresenterKind::FullScreen);
    }
    void MainPage::SettingsButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

    }
}

