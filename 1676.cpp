//1676 팩토리얼의 0의 개수 
//
#include <cstdio>

int main(void)
{
	int num, cnt=0;
	long long temp=1;

	scanf("%d", &num);

	for(int i=1; i<=num; i++){
		if(i%5 == 0)
			cnt++;
		if(i%25 == 0)
			cnt++;
		if(i%125 == 0)
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
