//
// BXLogger.h
// BaseTen
//
// Copyright (C) 2006-2008 Marko Karppinen & Co. LLC.
//
// Before using this software, please review the available licensing options
// by visiting http://basetenframework.org/licensing/ or by contacting
// us at sales@karppinen.fi. Without an additional license, this software
// may be distributed only in compliance with the GNU General Public License.
//
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License, version 2.0,
// as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
// $Id$
//


#import <Foundation/Foundation.h>
#import <stdarg.h>
#import <mach-o/dyld.h>


#ifndef BX_EXPORT
#ifdef __cplusplus
#define BX_EXPORT extern "C"
#else
#define BX_EXPORT extern
#endif
#endif


#define BX_LOG_ARGS __BASE_FILE__, __PRETTY_FUNCTION__, __builtin_return_address(0), __LINE__


//Note that " , ##__VA_ARGS__" tells the preprocessor to remove the comma if __VA_ARGS__ is empty.
#define BXLogDebug(message, ...)   do { if (BXLogLevel >= kBXLogLevelDebug)   BXLog (BX_LOG_ARGS, kBXLogLevelDebug,   message , ##__VA_ARGS__); } while (0)
#define BXLogInfo(message, ...)    do { if (BXLogLevel >= kBXLogLevelInfo)    BXLog (BX_LOG_ARGS, kBXLogLevelInfo,    message , ##__VA_ARGS__); } while (0)
#define BXLogWarning(message, ...) do { if (BXLogLevel >= kBXLogLevelWarning) BXLog (BX_LOG_ARGS, kBXLogLevelWarning, message , ##__VA_ARGS__); } while (0)
#define BXLogError(message, ...)   do { if (BXLogLevel >= kBXLogLevelError)   BXLog (BX_LOG_ARGS, kBXLogLevelError,   message , ##__VA_ARGS__); } while (0)
#define BXLogFatal(message, ...)   do { if (BXLogLevel >= kBXLogLevelFatal)   BXLog (BX_LOG_ARGS, kBXLogLevelFatal,   message , ##__VA_ARGS__); } while (0)

#define BXAssertLog(assertion, message, ...) \
	do { if (! (assertion)) { BXLog (BX_LOG_ARGS, kBXLogLevelError, message , ##__VA_ARGS__); BXAssertionDebug (); }} while (0)
#define BXAssertVoidReturn(assertion, message, ...) \
	do { if (! (assertion)) { BXLog (BX_LOG_ARGS, kBXLogLevelError, message , ##__VA_ARGS__); BXAssertionDebug (); return; }} while (0)
#define BXAssertValueReturn(assertion, retval, message, ...) \
	do { if (! (assertion)) { BXLog (BX_LOG_ARGS, kBXLogLevelError, message , ##__VA_ARGS__); BXAssertionDebug (); return (retval); }} while (0)


enum BXLogLevel
{
	kBXLogLevelOff = 0,
	kBXLogLevelFatal,
	kBXLogLevelError,
	kBXLogLevelWarning,
	kBXLogLevelInfo,
	kBXLogLevelDebug
};

//Do not use outside this file in case we decide to change the implementation.
BX_EXPORT enum BXLogLevel BXLogLevel;


BX_EXPORT void BXSetLogLevel (enum BXLogLevel level);
BX_EXPORT void BXLog (const char* fileName, const char* functionName, void* functionAddress, int line, enum BXLogLevel level, id messageFmt, ...);
BX_EXPORT void BXLog_v (const char* fileName, const char* functionName, void* functionAddress, int line, enum BXLogLevel level, id messageFmt, va_list args);

BX_EXPORT void BXAssertionDebug ();