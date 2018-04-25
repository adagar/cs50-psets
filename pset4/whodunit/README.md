# Questions

## What's `stdint.h`?

Library of BMP-related data types. Specifically they are a set of exact-width integer types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Fixes data within certain allowed values. For example, the red-value of a pixel can only be between 0-255.
256 is meaningless, so using a data type that doesn't support meaningless information makes programs
potentially less prone to breaking or taking in bad information.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE - 1
DWORD - 4
LONG - 4
WORD - 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII - BM

## What's the difference between `bfSize` and `biSize`?

bfSize is image size INCLUDING header, whereas biSize is only the image data

## What does it mean if `biHeight` is negative?

Image data is laid out top to bottom

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If filename being opened from or saved to are invalid, empty, or too big

## Why is the third argument to `fread` always `1` in our code?

The third argument of fread is number of elements being read from stream. Since we're copying one pixel or header section at a time,
we're only ever having one item being read.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

fseek sets the file position of the stream to the given offset

## What is `SEEK_CUR`?

set file pointer position to given location
