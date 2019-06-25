//2562 최댓값
#include <cstdio>

#define INF 2<<18
int main(void)
{
	int max=-(INF), index=0;
	int arr[10];
	for(int i=0; i<9; i++){
		scanf("%d", &arr[i]);
		if(arr[i] > max){
			max = arr[i];
			index = i+1;
		}
	}

	printf("%d %d\n", max, index);
}
