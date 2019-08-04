//1568 새
#include <cstdio>

int N, bird, result;
int main(void)
{
	scanf("%d", &N);
	bird = N;
	int sing = 0;
	while(bird != 0){
		result++;

		if(sing >= bird)
			sing = 0;
		bird -= (++sing);

	}

	printf("%d\n", result);
}
