#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char source, char aux, char dest)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", source, dest);
		return;
	}
	towerOfHanoi(n-1, source, dest, aux);
	printf("\n Move disk %d from rod %c to rod %c", n, source, dest);
	towerOfHanoi(n-1, aux, source, dest);
}


