#include <cstdio>

int main(void)
{
	int C;
	int N, arr[1000];
	int sum=0, ave, count=0;
	double result;

	scanf("%d", &C);

	while(C--)
	{
		sum=0;
		count=0;

		scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			scanf("%d", &arr[i]);
			sum+=arr[i];
		}

		ave = (double)sum/N;

		for(int i=0; i<N; i++)
		{
			if(arr[i]>ave)
				count++;
		}

		result = (double)count/N * 100;

		printf("%.3lf%%\n", result);

	}

	return 0;
}
