#include <cstdio>

int main(void)
{
	int num, num2;
	int arr[10000];

	scanf("%d %d", &num, &num2);

	for(int i=0; i<num; i++)
	{
		scanf("%d",&arr[i]); 
	}

	for(int i=0; i<num; i++)
	{
		if(arr[i]<num2)
			printf("%d ", arr[i]);
	}
	
	return 0;
}
