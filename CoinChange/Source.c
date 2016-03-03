#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/


int count(unsigned int *coins, int m, int target)
{
	if (target == 0)
		return 1;

	if (target < 0)
		return 0;

	if (target > 0 && m <= 0)
		return 0;

	return count(coins, m - 1, target) + count(coins, m, target - coins[m-1]);


}

void main()
{
	unsigned int T,N;//Test Cases
	unsigned int i,j;
	unsigned int ans = 0, target = 0;
	unsigned int *coins = NULL;

	FILE *fp = freopen("Input.txt", "r", stdin);
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%d", &N);
		coins = (unsigned int*)calloc(1,sizeof(unsigned int)*N);

		for (j = 0; j < N; j++)
			scanf("%d", &coins[j]);

		scanf("%d", &target);

		ans = count(coins, N, target);

		printf("%d\n", ans);
	}


}