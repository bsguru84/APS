#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char str1[1000], str2[1000];

unsigned int Min2(int a,int b)
{
	return (a < b) ? a : b;
}

int Min3(int x, int y, int z)
{
	return Min2(Min2(x, y), z);
}

unsigned int EditDistance(char *str1, char *str2, unsigned int m, unsigned int n)
{
	int *dp = (int*)malloc(sizeof(int)*(m+1)*(n+1));
	int ans;
	memset(dp, 0x0, sizeof(int)*(m + 1)*(n + 1));
	

	for (int i = 0; i <= n;i++)
	{
		if (i == 3)
			i=i;
		for (int j = 0; j <= m; j++)
		{
			if (i == 0)
			{
				dp[(n+1)*j +  i] = j;
				//printf("%d  ", dp[(n + 1)*j + i]);
				continue;
			}

			if (j == 0)
			{			
				dp[(n+1)* j + i] = i;
				//printf("%d  ", dp[(n + 1)*j + i]);
				continue;
			}

			if (str1[j - 1] == str2[i - 1])
			{
				dp[(n+1)*j + i] = dp[(n+1)*(j - 1) + i - 1];
			}
			else
				dp[(n + 1)*j + i] = 1 + Min3(dp[(n + 1)*j + i-1], dp[(n + 1)*(j-1) + i], dp[(n + 1)*(j - 1) + i - 1]);

			//printf("%d  ", dp[(n + 1)*j + i]);
		}
		//printf("\n");
	}

	ans = dp[(n + 1)*m + n];
	free(dp);

	return ans;
}

void main()
{
	unsigned int T;//Test Cases
	unsigned int i;
	unsigned int ans;
	
	FILE *fp = freopen("Input.txt", "r", stdin);
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		scanf("%s", str1);
		scanf("%s", str2);

		ans = EditDistance(str1, str2, strlen(str1), strlen(str2));

		printf("%d\n", ans);
	}


}