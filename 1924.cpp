//1924 2007년 구현

#include <cstdio>

int main(void)
{
	int x, y;
	int arr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	for(int i=1; i<12; i++)
		arr[i]+=arr[i-1];

	scanf("%d %d", &x, &y);

	switch((arr[x-1]+y)%7)
	{
		case 0:printf("SUN\n");
			   break;
		case 1:printf("MON\n");
			   break;
		case 2:printf("TUE\n");
			   break;
		case 3:printf("WED\n");
			   break;
		case 4:printf("THU\n");
			   break;
		case 5:printf("FRI\n");
			   break;
		case 6:printf("SAT\n");
			   break;
	}

	return 0;
}
