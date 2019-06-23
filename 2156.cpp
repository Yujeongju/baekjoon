//2156 포도주 시식
#include <cstdio>
#include <algorithm>

using namespace std;
int main(void)
{
	int num;
	int arr[10010], dp[10010];
	scanf("%d", &num);
	
	for(int i=1; i<=num; i++)
		scanf("%d", &arr[i]);

	dp[0] = 0; //물이 없을 때
	dp[1] = arr[1]; //1잔만 있을 때
	dp[2] = arr[1]+arr[2]; //2잔만 있을 때

	for(int i=3; i<=num; i++){ 
		//이전 잔을 마셨거나 안 마셨거나.
		//n-1잔을 마셨다면 n-2는 마실 수 없으므로 n-3까지의 최대와 n-1, n을 더함.
		//n-1잔을 마시지 않았다면 n-2까지의 최대와 n을 더함
		//둘을 비교하여 최대값 찾음
		dp[i] = max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);

		//연속으로 두 잔 마시지 않은 경우가 있기 때문에
		//이전까지의 최대와 현재 최대를 비교하여 값을 도출
		dp[i] = max(dp[i-1], dp[i]);

	}

	printf("%d\n", dp[num]);

}
