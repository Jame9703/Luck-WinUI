#pragma once

#include "App.xaml.g.h"

namespace winrt::Luck::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
        winrt::Microsoft::UI::Windowing::AppWindow this_AppWindow = winrt::Microsoft::UI::Windowing::AppWindow(nullptr);
    };
}
