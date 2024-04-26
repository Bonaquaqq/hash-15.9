#pragma once

typedef unsigned int uint;

#define one_block_size_bytes 64
#define one_block_size_uints 16
#define block_expend_size_uints 80

#define SHA1HASHLENGTHBYTES 20
#define SHA1HASHLENGTHUINTS 5

uint cycle_shift_left(uint val, int bit_count);
uint bring_to_human_view(uint val);

uint* sha1(char* message, uint msize_bytes);
