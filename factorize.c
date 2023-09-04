#include <stdlib.h>
#include "factor.h"

void factorize(unsigned long n) {
    unsigned long search, j, ans;
    int odd, i;

    if (n % 2 == 0)
    {
        printf("%lu=%lu*2\n", n, n/2);
    }
    else
    {
        j = _sqrt(n);
        ans = j * j;
        if (ans == n)
	{
		printf("%lu=%lu*%lu\n", n, j, j);
        }
	else
	{
		i = 1;
		search = 1;
		odd = 3;
		while (n + search != (j + i) * (j + i) && search < 10000)
		{
			search += odd;
			odd += 2;
			if (n + search > (j + i) * (j + i))
				i++;
		}
		printf("%lu=%lu*%lu\n", n, j + i + _sqrt(search), j + i - _sqrt(search));
	}
    }
}

int main(int argc, char *argv[]) {

    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (argc != 2)
    {
	    printf("consult usage doc");
	    return 0;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        int num = atoi(line);
	factorize(num);
    }

    fclose(file);
    if (line) {
        free(line);
    }


    return 0;
}
