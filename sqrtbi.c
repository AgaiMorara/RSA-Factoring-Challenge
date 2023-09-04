#include <stdio.h>
#include <math.h>

int countDigits(unsigned long int  n) {
    int count = 0;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

unsigned long int power(int base, int exponent)
{
	int i, result;

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return (result);
}

unsigned long int _sqrt(long int n)
{

	int numDigits;
	unsigned long int lowerBound, upperBound, mid, square;

    if (n <= 1) {
        return n;
    }

     numDigits = countDigits(n);

    if (numDigits % 2 == 0) {
        lowerBound = power(10, numDigits / 2 - 1);
    } else {
        lowerBound = power(10, (numDigits - 1) / 2);
    }

    upperBound = lowerBound * 10;

    while (lowerBound < upperBound) {
        mid = (lowerBound + upperBound) / 2;
        square = mid * mid;

        if (square == n) {
            return mid;
        } else if (square < n) {
            lowerBound = mid + 1;
        } else {
            upperBound = mid;
        }
    }

    return lowerBound - 1;
}
