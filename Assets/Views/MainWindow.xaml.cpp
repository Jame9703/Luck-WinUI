#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <Windows.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Luck::implementation
{
    //MainWindow::MainWindow()
    //{
    //    auto appWindow = winrt::Windows::UI::WindowManagement::AppWindow::GetFromWindowId(winrt::Windows::UI::WindowManagement::AppWindow::GetWindowIdForCurrentWindow());
    //    appWindow.TitleBar().ExtendsContentIntoTitleBar(false);

    //    auto presenter = AppWindow().Presenter().as<Microsoft::UI::Windowing::OverlappedPresenter>();
    //    presenter.IsMaximizable(false);
    //    presenter.IsMinimizable(false);
    //    presenter.SetBorderAndTitleBar(true, false);
    //}
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }

}
