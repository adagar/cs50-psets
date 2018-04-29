//jpeg related data structures

#include <stdint.h>

typedef uint8_t  BYTE;

typedef struct
{
    BYTE part1;
    BYTE part2;
    BYTE part3;
    BYTE part4;
} __attribute__((__packed__))
JPEGHEADER;