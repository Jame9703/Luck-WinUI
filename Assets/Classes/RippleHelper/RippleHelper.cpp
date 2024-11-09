#include "pch.h"
#include "RippleHelper.h"
#include "winrt/Windows.UI.Composition.h"
using namespace winrt::Microsoft::UI::Xaml::Input;
using namespace winrt::Microsoft::UI::Composition;
namespace RippleHelper
{
	class RippleHelper
	{
		private:
			//static  PointerEventHandler pointerEventHandler(Ele_PointerReleased);
			static  Compositor compositor /*= > Window.Current.Compositor*/;
			static  ExpressionAnimation _SizeBind;
		    static CompositionEasingFunction _EaseOut;
		    static ScalarKeyFrameAnimation _OpacityAnimation;
		    static Vector3KeyFrameAnimation _ScaleAnimation;
		    static CompositionAnimationGroup _RippleAnimationGroup;
		    static CompositionPropertySet _PropSet;
		    static CompositionBrush _Mask;
			static ExpressionAnimation SizeBind()
			{
				//if (_SizeBind == nullptr) _SizeBind = compositor.CreateExpressionAnimation("hostVisual.Size");
				return _SizeBind;
			}

	   public:
		   enum RippleHelperState
		   {
			   Pressed, Released, None
		   };
	};
}