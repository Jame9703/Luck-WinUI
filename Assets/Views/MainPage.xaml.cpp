#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

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

    }
    void MainPage::ExitButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

    }
    void MainPage::RenewButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

    }
    void MainPage::SettingsButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {

    }
}

