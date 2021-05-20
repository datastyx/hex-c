#include "hex-c/hex.h"
#include <stdlib.h>

// return 1 if dest size to small
//return 2 if empty input
int bin2hex(unsigned char *dest, size_t destSize, const unsigned char *src, size_t inputSize)
{
	size_t i;
	if ((inputSize * 2) > destSize)
	{
		return 1;
	}
	if (src == NULL || inputSize == 0)
		return 2;

	for (i = 0; i < inputSize; i++)
	{
		dest[i * 2] = "0123456789ABCDEF"[src[i] >> 4];
		dest[i * 2 + 1] = "0123456789ABCDEF"[src[i] & 0x0F];
	}
	dest[inputSize * 2] = '\0';

	return 0;
}

/**
 * inputData should have half the memory of inputLength allocated.
 * returns 0 on success
 * returns 1 on failure
 */
int hex2bin(unsigned char *outputData, const char *inputData,
			   size_t input_length)
{
	if (input_length % 2 != 0)
	{
		return 1;
	}

	for (unsigned int i = 0, j = 0; i < input_length; i++)
	{
		int c;

		if ('0' <= inputData[i] && inputData[i] <= '9')
		{
			c = inputData[i] - '0';
		}
		else if ('A' <= inputData[i] && inputData[i] <= 'F')
		{
			c = inputData[i] - 'A' + 10;
		}
		else if ('a' <= inputData[i] && inputData[i] <= 'f')
		{
			c = inputData[i] - 'a' + 10;
		}
		else
		{
			return 1;
		}

		if ((i & 0x1) == 0)
		{
			outputData[j] = ((unsigned char)c << 4);
		}
		else
		{
			outputData[j++] |= (unsigned char)c;
		}
	}

	return 0;
}
