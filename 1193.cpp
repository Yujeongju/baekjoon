//1193 분수찾기

#include <cstdio>

int main(void)
{
	int in, level=0;
	int sum=0;
	int temp, cnt=1;

	scanf("%d", &in);

	while(sum<in)
	{
		level++;
		sum+=level;
	}
	
	temp = level;
	
	for(int i=(sum-level)+1; i<in; i++)
	{
		level--;
		cnt++;
	}

	if(temp%2==0)
		printf("%d/%d", cnt, level);
	else
		printf("%d/%d", level, cnt);

	return 0;

}

