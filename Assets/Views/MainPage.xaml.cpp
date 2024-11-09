#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "Assets\Classes\RippleHelper\RippleHelper.h"
#include "Assets\Classes\Luck-Class\Luck.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace RippleHelper;

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

    void MainPage::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        //myButton().Content(box_value(L"Clicked"));
    }
    void MainPage::Button_Click(IInspectable const& sender, RoutedEventArgs const& args)
    {
        LuckSet::JudgePrize();
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

