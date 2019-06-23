//11053 가장 긴 증가하는 부분 수열
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1010], arr[1010];
int main(void)
{
	int n;
	int result = 0;

	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	for(int i=1; i<=n; i++){ //i번째 arr 원소
		for(int j=0; j<=i; j++){ //앞에서부터 다시 탐색
			if(arr[i] > arr[j] && dp[i]<dp[j]+1){ //더 클 때 && 수열이 더 길 때
				dp[i] = dp[j]+1; //더 긴 길이 저장
				result = max(dp[i], result); //max값을 result에 저장
			}
		}
	}

	//최대값 출력
	printf("%d\n", result);
	
}
