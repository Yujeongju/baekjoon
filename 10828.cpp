#include <cstdio>
#include <cstring>

void push(int *, int);
void empty(int);
void top(int *, int);

int main(void)
{
	int arr[20000];
	char input[10];
	int cur=-1;
	int time=0;

	scanf("%d", &time);

	while(time>0)
	{
		scanf(" %s", input);
		if(strcmp(input,"push")==0)
		{
			++cur;
			push(arr,cur);
		}
		else if(strcmp(input,"pop")==0)
		{	
			if(cur>-1)
			{	
				printf("%d\n", arr[cur]);
				--cur;

			}
			else
				printf("-1\n");
		}
		else if(strcmp(input, "size")==0)	
			printf("%d\n", cur+1);

		else if(strcmp(input, "empty")==0)
			empty(cur);

		else if(strcmp(input, "top")==0)
			top(arr,cur);

		else
			printf("잘못된 출력\n");

		time--;
	}

}

void push(int *arr,int cur)
{
	int num;
	scanf("%d",&num); 
   	arr[cur] = num;
}

void empty(int cur)
{
	if(cur ==-1)
		printf("1\n");
	else
		printf("0\n");
}

void top(int *arr, int cur)
{
	if(cur==-1)
		printf("-1\n");
	else
		printf("%d\n", arr[cur]);
}

