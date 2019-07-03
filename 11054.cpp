//11054 가장 긴 바이토닉 부분 수열
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int up_dp[1010], down_dp[1010], arr[1010];
int main(void)
{
	int input, result=1;
	scanf("%d", &input);

	for(int i=1; i<=input; i++){
		scanf("%d", &arr[i]);
		down_dp[i] = up_dp[i] = 1;
	}

	for(int i=1; i<=input; i++){
		for(int j=0; j<=i; j++){
			if(arr[i] > arr[j] && up_dp[i] < up_dp[j]+1){
				up_dp[i] = up_dp[j]+1;
			}
		}
	}

	//가장 긴 감소수열을 하면 안 되는 이유는
	//가장 큰 수가 시작점이 되어버려서 1이 되기 때문에
	//뒤에서부터 LIS를 구해야한다.
	for(int i=input; i>=1; i--){
		for(int j=input+1; j>=i; j--){
			if(arr[i] > arr[j] && down_dp[i] < down_dp[j]+1){
				down_dp[i] = down_dp[j]+1;
			}
		}
	}

	for(int i=1; i<=input; i++){
		result = max(result, up_dp[i]+down_dp[i]);	
	}

	printf("%d\n", result-1);
}
