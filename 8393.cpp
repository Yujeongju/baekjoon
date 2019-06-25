//8393 합
#include <cstdio>

int main(void)
{
	int n, result=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		result += i;
	}

	printf("%d\n", result);
}
