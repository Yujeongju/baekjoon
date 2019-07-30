//2875 대회 or 인턴
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, K;
int main(void)
{
	scanf("%d %d %d", &N, &M, &K);

	for(int i=0; i<K; i++){
		if(N == 0 || M == 0)
			break;

		if(N/2 >= M)
			N--;
		else
			M--;
	}

	printf("%d\n", min(N/2, M));
}
