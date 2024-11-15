#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "Assets\Classes\RippleHelper\RippleHelper.h"
#include "Assets\Classes\Luck-Class\Luck.h"
#include <winrt/Windows.UI.Popups.h>
#include <microsoft.ui.xaml.window.h>
#include <windows.h>
#include <winrt/Windows.UI.Core.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Windows::UI::Popups;
using namespace winrt::Microsoft::UI;
using namespace winrt::Microsoft::UI::Windowing;
using namespace Windows::UI::Core;

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

    // å¯¼èˆªï¼ŒèŽ·å–çª—å£å¹¶å‚¨å­˜åœ?this_AppWindow ä¸­ã€?
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
        MessageDialog dialog(L"æŠ½å¥–ä¸?..");
        switch (LuckSet::JudgePrize())
        {
        case 0:
        {
            dialog.Content(L"è¯·é€‰æ‹©ä½ çš„å¹¸è¿æ•°å­—");
            dialog.ShowAsync();
        }
        break;
        case 1:
        {
            dialog.Content(L"æ­å–œä½ æŠ½åˆ°ä¸€ç­‰å¥–");
            dialog.ShowAsync();
        }
        break;
        case 2:
        {
            dialog.Content(L"æ­å–œä½ æŠ½åˆ°äºŒç­‰å¥–");
            dialog.ShowAsync();
        }
        break;
        case 3:
        {
            dialog.Content(L"æ­å–œä½ æŠ½åˆ°ä¸‰ç­‰å¥–");
            dialog.ShowAsync();
        }
        break;
        case -1:
        {
            dialog.Content(L"æ‰€æœ‰å¥–é¡¹å‡å·²æŠ½å®?);
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
        //auto window = Window::Current();
        //winrt::com_ptr<::IWindowNative> windowNative = window as<IWindowNative>();
        //HWND hWnd;
        //windowNative->get_WindowHandle(&hWnd);
        //WindowId id = GetwindowIdFromwindow(hWnd);
        //winrt::Microsoft::UI::Windowing::AppWindow appwind = winrt::Microsoft::UI::Windowing::AppWindow::GetFromWindowId(id);
        //appwind.SetPresenter(AppWindowPresenterKind::FullScreen);

        // ÏñÊÇÒ»¸öÈ«ÆÁ
        //HWND hWnd = GetActiveWindow();
        //if (hWnd != nullptr)
        //{
        //    // »ñÈ¡ÆÁÄ»³ß´ç
        //    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        //    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

        //    // ÉèÖÃ´°¿ÚÎ»ÖÃºÍ´óÐ¡ÎªÈ«ÆÁ
        //    SetWindowPos(hWnd, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_SHOWWINDOW);
        //}

        //ÑùÊ½ºÜÆæ¹Ö
        HWND hWnd = GetActiveWindow();
        if (hWnd != nullptr)
        {
            //// »ñÈ¡ÆÁÄ»³ß´ç
            //int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            //int screenHeight = GetSystemMetrics(SM_CYSCREEN);

            //// Òþ²Ø´°¿Ú±êÌâÀ¸
            //LONG_PTR style = GetWindowLongPtr(hWnd, GWL_STYLE);
            //style &= ~WS_CAPTION;
            //SetWindowLongPtr(hWnd, GWL_STYLE, style);

            //// ÉèÖÃ´°¿ÚÎ»ÖÃºÍ´óÐ¡ÎªÈ«ÆÁ
            //SetWindowPos(hWnd, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_SHOWWINDOW);
            AppWindow appWindow = AppWindow::GetFromWindow(hWnd);
            if (appWindow)
            {
                // »ñÈ¡ÆÁÄ»³ß´ç
                int screenWidth = GetSystemMetrics(SM_CXSCREEN);
                int screenHeight = GetSystemMetrics(SM_CYSCREEN);

                appWindow.Resize({ screenWidth, screenHeight });
                appWindow.Move({ 0,0 });
            }
        }
        // ±£³ÖÓ¦ÓÃÔËÐÐ£¬ÕâÀï¿ÉÒÔ¸ù¾ÝÊµ¼ÊÇé¿öÐÞ¸ÄÂß¼­
        // ÀýÈç£¬¿ÉÒÔÌí¼ÓÒ»¸öÏûÏ¢Ñ­»·µÈ
        //CoreWindow::GetForCurrentThread().Dispatcher().ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
    }
    void MainPage::SettingsButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

    }
}
