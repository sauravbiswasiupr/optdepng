OptDePng
========

A SIMD Optimized PNG Reverse Filter
-----------------------------------

Official Repository: https://github.com/kobalicek/optdepng

Support the Project: [![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_LG.gif)](
  https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=QDRM6SRNG7378&lc=EN;&item_name=rgbhsv&currency_code=EUR)

Introduction
------------

This is an attempt to write SIMD optimizations that can be used to apply a reverse filter to a PNG filtered scanline (or the whole image). The code contains a reference implementation in C++, template based implementation that parametrizes each BPP, and SIMD implementation trying to beat the previous implementations by taking advantage of SSE2. This repository has been used to experiment with various approaches, to validate them, and to select the best one that can be used by [Blend2d](http://blend2d.com).

