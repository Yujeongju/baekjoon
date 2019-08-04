//1668 트로피 진열
#include <cstdio>

int N, arr[60], result=1;
int main(void)
{
	int tmp;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	tmp = arr[0];
	for(int i=1; i<N; i++){
		if(arr[i] > tmp){
			tmp = arr[i];
			result++;
		}
	}
	printf("%d\n", result);

	result = 1;
	tmp = arr[N-1];
	for(int i=N-2; i>=0; i--){
		if(arr[i] > tmp){
			tmp = arr[i];
			result++;
		}
	}

	printf("%d\n", result);
}
