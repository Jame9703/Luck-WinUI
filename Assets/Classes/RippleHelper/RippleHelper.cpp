#include "pch.h"
#include "RippleHelper.h"
#include "winrt/Windows.UI.Composition.h"

using namespace winrt::Microsoft::UI::Xaml::Input;
using namespace winrt::Microsoft::UI::Composition;
//
//Compositor RippleHelper::compositor /*= > Window.Current.Compositor*/;
//ExpressionAnimation RippleHelper::_SizeBind;
//CompositionEasingFunction RippleHelper::_EaseOut;
//ScalarKeyFrameAnimation RippleHelper::_OpacityAnimation;
//Vector3KeyFrameAnimation RippleHelper::_ScaleAnimation;
//CompositionAnimationGroup RippleHelper::_RippleAnimationGroup;
//CompositionPropertySet RippleHelper::_PropSet;
//CompositionBrush RippleHelper::_Mask;

ExpressionAnimation RippleHelper::SizeBind()
{

	//if (_SizeBind == null) _SizeBind = compositor.CreateExpressionAnimation("hostVisual.Size");
	return  0;
}
