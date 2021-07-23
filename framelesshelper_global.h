/*
 * MIT License
 *
 * Copyright (C) 2021 by wangwenx190 (Yuhang Zhao)
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

#include <QtCore/qglobal.h>

#ifndef FRAMELESSHELPER_API
#ifdef FRAMELESSHELPER_STATIC
#define FRAMELESSHELPER_API
#else
#ifdef FRAMELESSHELPER_BUILD_LIBRARY
#define FRAMELESSHELPER_API Q_DECL_EXPORT
#else
#define FRAMELESSHELPER_API Q_DECL_IMPORT
#endif
#endif
#endif

#if defined(Q_OS_WIN) && !defined(Q_OS_WINDOWS)
#define Q_OS_WINDOWS
#endif

#ifndef Q_DISABLE_COPY_MOVE
#define Q_DISABLE_COPY_MOVE(Class) \
    Q_DISABLE_COPY(Class) \
    Class(Class &&) = delete; \
    Class &operator=(Class &&) = delete;
#endif

#if (QT_VERSION < QT_VERSION_CHECK(5, 7, 0))
#define qAsConst(i) std::as_const(i)
#endif

#if !defined(Q_OS_WINDOWS) || defined(FRAMELESSHELPER_TEST_UNIX)
#define FRAMELESSHELPER_USE_UNIX_VERSION
#endif

#if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
#define Q_NODISCARD [[nodiscard]]
#else
#define Q_NODISCARD
#endif

#ifndef FRAMELESSHELPER_NAMESPACE
#define FRAMELESSHELPER_NAMESPACE __flh_ns
#endif

#ifndef FRAMELESSHELPER_BEGIN_NAMESPACE
#define FRAMELESSHELPER_BEGIN_NAMESPACE namespace FRAMELESSHELPER_NAMESPACE {
#endif

#ifndef FRAMELESSHELPER_END_NAMESPACE
#define FRAMELESSHELPER_END_NAMESPACE }
#endif

#ifndef FRAMELESSHELPER_USE_NAMESPACE
#define FRAMELESSHELPER_USE_NAMESPACE using namespace FRAMELESSHELPER_NAMESPACE;
#endif

#ifndef FRAMELESSHELPER_PREPEND_NAMESPACE
#define FRAMELESSHELPER_PREPEND_NAMESPACE(X) ::FRAMELESSHELPER_NAMESPACE::X
#endif

FRAMELESSHELPER_BEGIN_NAMESPACE

namespace Constants
{

[[maybe_unused]] const char framelessMode_flag[] = "_FRAMELESSHELPER_FRAMELESS_MODE";
[[maybe_unused]] const char resizeBorderWidth_flag[] = "_FRAMELESSHELPER_RESIZE_BORDER_WIDTH";
[[maybe_unused]] const char resizeBorderHeight_flag[] = "_FRAMELESSHELPER_RESIZE_BORDER_HEIGHT";
[[maybe_unused]] const char titleBarHeight_flag[] = "_FRAMELESSHELPER_TITLE_BAR_HEIGHT";
[[maybe_unused]] const char hitTestVisibleInChrome_flag[] = "_FRAMELESSHELPER_HIT_TEST_VISIBLE_IN_CHROME";
[[maybe_unused]] const char useNativeTitleBar_flag[] = "_FRAMELESSHELPER_USE_NATIVE_TITLE_BAR";
[[maybe_unused]] const char preserveNativeFrame_flag[] = "_FRAMELESSHELPER_PRESERVE_NATIVE_WINDOW_FRAME";
[[maybe_unused]] const char forcePreserveNativeFrame_flag[] = "_FRAMELESSHELPER_FORCE_PRESERVE_NATIVE_WINDOW_FRAME";
[[maybe_unused]] const char windowFixedSize_flag[] = "_FRAMELESSHELPER_WINDOW_FIXED_SIZE";

}

FRAMELESSHELPER_END_NAMESPACE
