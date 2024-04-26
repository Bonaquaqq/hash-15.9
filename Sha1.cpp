
#include <cstring>
#include "Sha1.h"

uint cycle_shift_left(uint val, int bit_count) {
    return (val << bit_count | val >> (32 - bit_count));
}

uint bring_to_human_view(uint val) {
    return ((val & 0x000000FF) << 24) | ((val & 0x0000FF00) << 8) | ((val & 0x00FF0000) >> 8) | ((val & 0xFF000000) >> 24);
}

uint* sha1(char* message, uint msize_bytes) {
    // Implementation...
    return nullptr; // Placeholder return
}

uint* sha1(char* message, uint msize_bytes)
{
    return nullptr;
}
