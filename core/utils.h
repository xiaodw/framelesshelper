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

#include "framelesshelpercore_global.h"
#include <QtGui/qwindowdefs.h>

FRAMELESSHELPER_BEGIN_NAMESPACE

enum class SystemTheme : int
{
    Light = 0,
    Dark = 1,
    HighContrastLight = 2,
    HighContrastDark = 3
};
Q_ENUM_NS(SystemTheme)

enum class SystemButtonType : int
{
    WindowIcon = 0,
    Minimize = 1,
    Maximize = 2,
    Restore = 3,
    Close = 4
};
Q_ENUM_NS(SystemButtonType)

#ifdef Q_OS_WINDOWS
enum class DwmColorizationArea : int
{
    None = 0,
    StartMenu_TaskBar_ActionCenter = 1,
    TitleBar_WindowBorder = 2,
    All = 3
};
Q_ENUM_NS(DwmColorizationArea)
#endif

namespace Utils
{

[[nodiscard]] FRAMELESSHELPER_CORE_API Qt::CursorShape calculateCursorShape(const QWindow *window, const QPointF &pos);
[[nodiscard]] FRAMELESSHELPER_CORE_API Qt::Edges calculateWindowEdges(const QWindow *window, const QPointF &pos);
FRAMELESSHELPER_CORE_API void startSystemMove(QWindow *window);
FRAMELESSHELPER_CORE_API void startSystemResize(QWindow *window, const Qt::Edges edges);
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWindowFixedSize(const QWindow *window);
[[nodiscard]] FRAMELESSHELPER_CORE_API QIcon getSystemButtonIcon(const SystemButtonType type, const SystemTheme theme);

#ifdef Q_OS_WINDOWS
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWin8OrGreater();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWin8Point1OrGreater();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWin10OrGreater();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWin101809OrGreater();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWin11OrGreater();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isDwmCompositionEnabled();
FRAMELESSHELPER_CORE_API void triggerFrameChange(const WId winId);
FRAMELESSHELPER_CORE_API void updateWindowFrameMargins(const WId winId, const bool reset);
FRAMELESSHELPER_CORE_API void updateInternalWindowFrameMargins(QWindow *window, const bool enable);
[[nodiscard]] FRAMELESSHELPER_CORE_API QString getSystemErrorMessage(const QString &function);
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isFullScreen(const WId winId);
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWindowNoState(const WId winId);
FRAMELESSHELPER_CORE_API void syncWmPaintWithDwm();
FRAMELESSHELPER_CORE_API void showSystemMenu(const WId winId, const QPointF &pos);
[[nodiscard]] FRAMELESSHELPER_CORE_API QColor getDwmColorizationColor();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool shouldAppsUseDarkMode();
[[nodiscard]] FRAMELESSHELPER_CORE_API DwmColorizationArea getDwmColorizationArea();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isHighContrastModeEnabled();
[[nodiscard]] FRAMELESSHELPER_CORE_API quint32 getPrimaryScreenDpi(const bool horizontal);
[[nodiscard]] FRAMELESSHELPER_CORE_API quint32 getWindowDpi(const WId winId, const bool horizontal);
[[nodiscard]] FRAMELESSHELPER_CORE_API quint32 getResizeBorderThickness(const WId winId, const bool horizontal, const bool scaled);
[[nodiscard]] FRAMELESSHELPER_CORE_API quint32 getCaptionHeight(const WId winId, const bool scaled);
[[nodiscard]] FRAMELESSHELPER_CORE_API quint32 getTitleBarHeight(const WId winId, const bool scaled);
[[nodiscard]] FRAMELESSHELPER_CORE_API quint32 getFrameBorderThickness(const WId winId, const bool scaled);
[[nodiscard]] FRAMELESSHELPER_CORE_API QColor getFrameBorderColor(const bool active);
FRAMELESSHELPER_CORE_API void updateWindowFrameBorderColor(const WId winId, const bool dark);
FRAMELESSHELPER_CORE_API void fixupQtInternals(const WId winId);
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isWindowFrameBorderVisible();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isTitleBarColorized();
[[nodiscard]] FRAMELESSHELPER_CORE_API bool isFrameBorderColorized();
#endif // Q_OS_WINDOWS

} // namespace Utils

FRAMELESSHELPER_END_NAMESPACE
