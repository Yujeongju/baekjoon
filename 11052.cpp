//11052 카드 구매하기
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int num;
	int arr[10010], dp[10010];
	scanf("%d", &num);
	for(int i=1; i<=num; i++){
		scanf("%d", &arr[i]);
	}

	for(int i=1; i<=num; i++){
		for(int j=1; j<=num; j++){
			if(j-i >= 0){
				dp[j] = max(dp[j], arr[i]+dp[j-i]);
			}
		}
	}

	printf("%d\n", dp[num]);

}
