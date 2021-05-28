#pragma once

#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif 



// return 1 if dest size to small
//return 2 if empty input
int bin2hex(char *dest, size_t destSize, const unsigned char *src, size_t inputSize);

/**
 * inputData should have half the memory of inputLength allocated.
 * returns 0 on success
 * returns 1 on failure
 */
int hex2bin(unsigned char *outputData, const char *inputData,
			   size_t input_length);


#ifdef __cplusplus
}
#endif
