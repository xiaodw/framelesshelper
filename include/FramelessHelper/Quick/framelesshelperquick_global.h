/*
 * MIT License
 *
 * Copyright (C) 2022 by wangwenx190 (Yuhang Zhao)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

#include <framelesshelpercore_global.h>
#if __has_include(<QtQml/qqmlregistration.h>)
#  include <QtQml/qqmlregistration.h>
#endif

#ifndef FRAMELESSHELPER_QUICK_API
#  ifdef FRAMELESSHELPER_QUICK_STATIC
#    define FRAMELESSHELPER_QUICK_API
#  else
#    ifdef FRAMELESSHELPER_QUICK_LIBRARY
#      define FRAMELESSHELPER_QUICK_API Q_DECL_EXPORT
#    else
#      define FRAMELESSHELPER_QUICK_API Q_DECL_IMPORT
#    endif
#  endif
#endif

#ifndef FRAMELESSHELPER_QUICK_ENUM_VALUE
#  define FRAMELESSHELPER_QUICK_ENUM_VALUE(Enum, Value) \
     Value = static_cast<int>(FRAMELESSHELPER_PREPEND_NAMESPACE(Global)::Enum::Value),
#endif

#ifndef FRAMELESSHELPER_ENUM_CORE_TO_QUICK
#  define FRAMELESSHELPER_ENUM_CORE_TO_QUICK(Enum, Value) \
     static_cast<FRAMELESSHELPER_PREPEND_NAMESPACE(QuickGlobal)::Enum>(static_cast<int>(Value))
#endif

#ifndef FRAMELESSHELPER_ENUM_QUICK_TO_CORE
#  define FRAMELESSHELPER_ENUM_QUICK_TO_CORE(Enum, Value) \
     static_cast<FRAMELESSHELPER_PREPEND_NAMESPACE(Global)::Enum>(static_cast<int>(Value))
#endif

#ifndef FRAMELESSHELPER_FLAGS_CORE_TO_QUICK
#  define FRAMELESSHELPER_FLAGS_CORE_TO_QUICK(Enum, Value, In, Out) \
     if (In & FRAMELESSHELPER_PREPEND_NAMESPACE(Global)::Enum::Value) { \
         Out |= FRAMELESSHELPER_PREPEND_NAMESPACE(QuickGlobal)::Enum::Value; \
     }
#endif

#ifndef FRAMELESSHELPER_FLAGS_QUICK_TO_CORE
#  define FRAMELESSHELPER_FLAGS_QUICK_TO_CORE(Enum, Value, In, Out) \
     if (In & FRAMELESSHELPER_PREPEND_NAMESPACE(QuickGlobal)::Enum::Value) { \
         Out |= FRAMELESSHELPER_PREPEND_NAMESPACE(Global)::Enum::Value; \
     }
#endif

FRAMELESSHELPER_BEGIN_NAMESPACE

[[maybe_unused]] static constexpr const char FRAMELESSHELPER_QUICK_URI[] = "org.wangwenx190.FramelessHelper";

struct FRAMELESSHELPER_QUICK_API QuickGlobal
{
    enum class Option
    {
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, ForceHideWindowFrameBorder)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, ForceShowWindowFrameBorder)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontDrawTopWindowFrameBorder)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, EnableRoundedWindowCorners)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, TransparentWindowBackground)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, MaximizeButtonDocking)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, CreateStandardWindowLayout)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, BeCompatibleWithQtFramelessWindowHint)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontTouchQtInternals)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontTouchWindowFrameBorderColor)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontInstallSystemMenuHook)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DisableSystemMenu)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, NoDoubleClickMaximizeToggle)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DisableResizing)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DisableDragging)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontTouchCursorShape)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontMoveWindowToDesktopCenter)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontTreatFullScreenAsZoomed)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontTouchHighDpiScalingPolicy)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontTouchScaleFactorRoundingPolicy)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontTouchProcessDpiAwarenessLevel)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, DontEnsureNonNativeWidgetSiblings)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Option, SyncNativeControlsThemeWithSystem)
    };
    Q_ENUM(Option)
    Q_DECLARE_FLAGS(Options, Option)
    Q_FLAG(Options)

    enum class SystemTheme
    {
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemTheme, Unknown)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemTheme, Light)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemTheme, Dark)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemTheme, HighContrast)
    };
    Q_ENUM(SystemTheme)

    enum class SystemButtonType
    {
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemButtonType, Unknown)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemButtonType, WindowIcon)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemButtonType, Help)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemButtonType, Minimize)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemButtonType, Maximize)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemButtonType, Restore)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(SystemButtonType, Close)
    };
    Q_ENUM(SystemButtonType)

    enum class ResourceType
    {
        FRAMELESSHELPER_QUICK_ENUM_VALUE(ResourceType, Image)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(ResourceType, Pixmap)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(ResourceType, Icon)
    };
    Q_ENUM(ResourceType)

    enum class DwmColorizationArea
    {
        FRAMELESSHELPER_QUICK_ENUM_VALUE(DwmColorizationArea, None_)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(DwmColorizationArea, StartMenu_TaskBar_ActionCenter)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(DwmColorizationArea, TitleBar_WindowBorder)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(DwmColorizationArea, All)
    };
    Q_ENUM(DwmColorizationArea)

    enum class Anchor
    {
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Anchor, Top)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Anchor, Bottom)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Anchor, Left)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Anchor, Right)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Anchor, HorizontalCenter)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Anchor, VerticalCenter)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(Anchor, Center)
    };
    Q_ENUM(Anchor)

    enum class ButtonState
    {
        FRAMELESSHELPER_QUICK_ENUM_VALUE(ButtonState, Unspecified)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(ButtonState, Hovered)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(ButtonState, Pressed)
        FRAMELESSHELPER_QUICK_ENUM_VALUE(ButtonState, Clicked)
    };
    Q_ENUM(ButtonState)

private:
    Q_GADGET
#ifdef QML_NAMED_ELEMENT
    QML_NAMED_ELEMENT(FramelessHelper)
#endif
#ifdef QML_UNCREATABLE
    QML_UNCREATABLE("The FramelessHelper namespace is not creatable, you can only use it to access it's enums.")
#endif
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QuickGlobal::Options)

FRAMELESSHELPER_END_NAMESPACE
