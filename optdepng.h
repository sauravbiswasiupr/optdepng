// [OptDePng]
// SIMD optimized "PNG Reverse Filter" implementation.
//
// [License]
// Zlib - See LICENSE.md file in the package.

// [Guard]
#ifndef _OPTDEPNG_H
#define _OPTDEPNG_H

#include <stdint.h>

enum PngFilterType {
  kPngFilterNone  = 0,
  kPngFilterSub   = 1,
  kPngFilterUp    = 2,
  kPngFilterAvg   = 3,
  kPngFilterPaeth = 4,
  kPngFilterCount = 5
};

typedef void (*OptDePngFilterFunc)(uint8_t* p, uint32_t h, uint32_t bpp, uint32_t bpl);

void OptDePngFilterRef(uint8_t* p, uint32_t h, uint32_t bpp, uint32_t bpl);
void OptDePngFilterOpt(uint8_t* p, uint32_t h, uint32_t bpp, uint32_t bpl);
void OptDePngFilterSSE2(uint8_t* p, uint32_t h, uint32_t bpp, uint32_t bpl);

// [Guard]
#endif // _OPTDEPNG_H
