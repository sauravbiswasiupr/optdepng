// [OptDePng]
// SIMD optimized "PNG Reverse Filter" implementation.
//
// [License]
// Zlib - See LICENSE.md file in the package.

// [Guard]
#ifndef _OPTGLOBALS_H
#define _OPTGLOBALS_H

// ============================================================================
// [Dependencies]
// ============================================================================

#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if defined(_WIN32)
#include <windows.h>
#else
#include <sys/time.h>
#endif

// ============================================================================
// [Instructions]
// ============================================================================

// SSE.
#include <xmmintrin.h>

// SSE2.
#if defined(USE_SSE2)
#include <emmintrin.h>
#endif // USE_SSE2

// SSSE3.
#if defined(USE_SSSE3)
#include <tmmintrin.h>
#endif // USE_SSE3

// ============================================================================
// [Portability]
// ============================================================================

#if defined(_MSC_VER)
# define OPT_INLINE __forceinline
#else
# define OPT_INLINE inline
#endif

// ============================================================================
// [Helpers]
// ============================================================================

template<typename T>
static bool OPT_INLINE OptIsAligned(T p, uint32_t alignment) {
  uint32_t mask = alignment - 1;
  return ((uintptr_t)p & mask) == 0;
}

template<typename T>
static uint32_t OPT_INLINE OptAlignDiff(T p, uint32_t alignment) {
  uint32_t mask = alignment - 1;
  return (alignment - static_cast<uint32_t>((uintptr_t)p & mask)) & mask;
}

// ============================================================================
// [OptTimer]
// ============================================================================

struct OptTimer {
  OPT_INLINE OptTimer() : _cnt(0) {}

  OPT_INLINE uint32_t get() const { return _cnt; }
  OPT_INLINE void start() { _cnt = _getTime(); }
  OPT_INLINE void stop() { _cnt = _getTime() - _cnt; }

  static OPT_INLINE uint32_t _getTime() {
#if defined(_WIN32)
    return GetTickCount();
#else
    timeval ts;
    gettimeofday(&ts,0);
    return (uint32_t)(ts.tv_sec * 1000 + (ts.tv_usec / 1000));
#endif
  }

  uint32_t _cnt;
};

// [Guard]
#endif // _OPTGLOBALS_H
