 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Byte swapping functions
  *
  * Copyright 2019 Frode Solheim
  */

#ifndef UAE_BYTESWAP_H
#define UAE_BYTESWAP_H

#if 0
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#endif

#ifdef _MSC_VER

#include <stdlib.h>
#define uae_bswap16 _byteswap_ushort
#define uae_bswap32 _byteswap_ulong
#define uae_bswap64 _byteswap_uint64

#else

#define uae_bswap16 __builtin_bswap16
#define uae_bswap32 __builtin_bswap32
#define uae_bswap64 __builtin_bswap64

#endif

#if 0

#ifdef _WIN32
#include <stdlib.h>
#define uae_bswap16 _byteswap_uint16
#define uae_bswap32 _byteswap_uint32
#define uae_bswap64 _byteswap_uint64
#elif defined(__APPLE__)
#include <libkern/OSByteOrder.h>
#define uae_bswap16 OSSwapInt16
#define uae_bswap32 OSSwapInt32
#define uae_bswap64 OSSwapInt64
#else
#include <byteswap.h>
#define uae_bswap16 bswap_16
#define uae_bswap32 bswap_32
#define uae_bswap64 bswap_64
#endif

// Using builtin byteswap functions where possible. In many cases, the
// compiler may use optimized byteswap builtins anyway, but better to
// not risk using slower function calls.

#ifdef HAVE___BUILTIN_BSWAP16
#undef uae_bswap16
#define uae_bswap16 __builtin_bswap16
#endif
#ifdef HAVE___BUILTIN_BSWAP32
#undef uae_bswap32
#define uae_bswap32 __builtin_bswap32
#endif
#ifdef HAVE___BUILTIN_BSWAP64
#undef uae_bswap64
#define uae_bswap64 __builtin_bswap64
#endif

#endif

#endif /* UAE_BYTESWAP_H */
