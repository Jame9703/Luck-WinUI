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

    // 导航，获取窗口并储存在 this_AppWindow 中。
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
            MessageBox(NULL, L"严重错误，窗口处理失败。\n", L"Luck错误", MB_OK);
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
        MessageDialog dialog(L"抽奖中...");
        switch (LuckSet::JudgePrize())
        {
        case 0:
        {
            dialog.Content(L"请选择你的幸运数字");
            dialog.ShowAsync();
        }
        break;
        case 1:
        {
            dialog.Content(L"恭喜你抽到一等奖");
            dialog.ShowAsync();
        }
        break;
        case 2:
        {
            dialog.Content(L"恭喜你抽到二等奖");
            dialog.ShowAsync();
        }
        break;
        case 3:
        {
            dialog.Content(L"恭喜你抽到三等奖");
            dialog.ShowAsync();
        }
        break;
        case -1:
        {
            dialog.Content(L"所有奖项均已抽完");
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

        // ����һ��ȫ��
        //HWND hWnd = GetActiveWindow();
        //if (hWnd != nullptr)
        //{
        //    // ��ȡ��Ļ�ߴ�
        //    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
        //    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

        //    // ���ô���λ�úʹ�СΪȫ��
        //    SetWindowPos(hWnd, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_SHOWWINDOW);
        //}

        //��ʽ�����
        HWND hWnd = GetActiveWindow();
        if (hWnd != nullptr)
        {
            //// ��ȡ��Ļ�ߴ�
            //int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            //int screenHeight = GetSystemMetrics(SM_CYSCREEN);

            //// ���ش��ڱ�����
            //LONG_PTR style = GetWindowLongPtr(hWnd, GWL_STYLE);
            //style &= ~WS_CAPTION;
            //SetWindowLongPtr(hWnd, GWL_STYLE, style);

            //// ���ô���λ�úʹ�СΪȫ��
            //SetWindowPos(hWnd, HWND_TOP, 0, 0, screenWidth, screenHeight, SWP_SHOWWINDOW);
            AppWindow appWindow = AppWindow::GetFromWindow(hWnd);
            if (appWindow)
            {
                // ��ȡ��Ļ�ߴ�
                int screenWidth = GetSystemMetrics(SM_CXSCREEN);
                int screenHeight = GetSystemMetrics(SM_CYSCREEN);

                appWindow.Resize({ screenWidth, screenHeight });
                appWindow.Move({ 0,0 });
            }
        }
        // ����Ӧ�����У�������Ը���ʵ������޸��߼�
        // ���磬��������һ����Ϣѭ����
        //CoreWindow::GetForCurrentThread().Dispatcher().ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
    }
    void MainPage::SettingsButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

    }
}
