#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "Assets\Classes\RippleHelper\RippleHelper.h"
#include "Assets\Views\SettingsPage.xaml.h"
#include "Assets\Classes\Luck-Class\Luck.h"
#include <winrt/Windows.UI.Popups.h>
#include <microsoft.ui.xaml.window.h>
#include <windows.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Microsoft.UI.Xaml.Navigation.h>

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
            MessageBox(NULL, L"���ش��󣬴��ڴ���ʧ�ܡ�\n", L"Luck����", MB_OK);
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
        MessageDialog dialog(L"�齱������...");
        switch (LuckSet::JudgePrize())
        {
        case 0:
        {
            dialog.Content(L"��ѡ�������������");
            dialog.ShowAsync();
        }
        break;
        case 1:
        {
            dialog.Content(L"��ϲ��鵽һ�Ƚ�");
            dialog.ShowAsync();
        }
        break;
        case 2:
        {
            dialog.Content(L"��ϲ��鵽���Ƚ�");
            dialog.ShowAsync();
        }
        break;
        case 3:
        {
            dialog.Content(L"��ϲ��鵽���Ƚ�");
            dialog.ShowAsync();
        }
        break;
        case -1:
        {
            dialog.Content(L"���н�����ѳ���");
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
        using namespace Microsoft::UI::Windowing;
        if (this_AppWindow.Presenter().Kind() == AppWindowPresenterKind::FullScreen)
            this_AppWindow.SetPresenter(AppWindowPresenterKind::Default);
        else this_AppWindow.SetPresenter(AppWindowPresenterKind::FullScreen);
    }
    void MainPage::SettingsButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args)
    {
        using namespace Microsoft::UI::Xaml::Navigation;
        Frame.Navigate(winrt::xaml_typename<SettingsPage>());
    }
}
