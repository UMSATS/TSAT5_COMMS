#ifndef FRAME_CHECK_H
#define FRAME_CHECK_H


// The _bit, _byte, and _word routines return the CRC of the len bytes at mem,
// applied to the previous CRC value, crc. If mem is NULL, then the other
// arguments are ignored, and the initial CRC, i.e. the CRC of zero bytes, is
// returned. Those routines will all return the same result, differing only in
// speed and code complexity. The _rem routine returns the CRC of the remaining
// bits in the last byte, for when the number of bits in the message is not a
// multiple of eight. The low bits bits of the low byte of val are applied to
// crc. bits must be in 0..8.

#include <stddef.h>
#include <stdint.h>

// Compute the CRC a bit at a time.
uint16_t crc16kermit_bit(void const *data_in, size_t len);

// Compute the CRC of the low bits bits in val.
//uint16_t crc16kermit_rem(unsigned crc, unsigned val, unsigned bits);

// Compute the CRC a byte at a time.
uint16_t frame_check_byte(void const *data_in, size_t len);

// Compute the CRC a word at a time.
uint16_t crc16kermit_word(void const *data_in, size_t len);

#endif /* FRAME_CHECK_H */
