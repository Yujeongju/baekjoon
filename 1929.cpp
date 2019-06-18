//1929 소수 구하기
//에라토스테네스의 체
#include <cstdio>

int result[1000001];
int main(void)
{
	int min, max;
	
	scanf("%d %d", &min, &max);

	result[1] = 1;
	for(int i=2; i<=max; i++){
		for(int j=2; i*j <=max; j++){
			result[i*j] = 1;
		}
	}

	for(int i=min; i<=max; i++)
		if(!result[i])
			printf("%d\n", i);

	return 0;
		
}
