#include <stdio.h>

int main()
{
	int tab[] = {1,4,10,49,10};
	int n = 5;
	int bestV = tab[0];
	int bestI = 0;
	for(int i = 0; i < n; i++ )
	{
		if (tab[i]>bestV)
		{
			bestV = tab[i];
			bestI = i;
		}
	}

	printf("Index : %d", bestI);
}
