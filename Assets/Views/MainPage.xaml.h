#pragma once

#include "MainPage.g.h"

namespace winrt::Luck::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void  OnNavigatedTo(winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs e);


        void myButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void Button_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void ExitButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void RenewButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void SettingsButton_Click(IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    
    
    private:
        winrt::Microsoft::UI::Windowing::AppWindow this_AppWindow = winrt::Microsoft::UI::Windowing::AppWindow(nullptr);
    };
}

namespace winrt::Luck::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
