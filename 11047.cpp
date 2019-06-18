//11047 동전0
#include <cstdio>
#include <iostream>

int main(void)
{
	int N, K, cnt=0;

	scanf("%d %d", &N, &K);
	
	int *arr = new int[N];

	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	
	for(int i=N-1; i>=0; i--){
		if(arr[i] > K)
			continue;
		else{
			K -= arr[i];
			i++;
			cnt++;
			continue;
		}
	}

	printf("%d\n", cnt);

}
