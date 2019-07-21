//1965 상자넣기
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[1010], dp[1010];
int main(void)
{
	int n, result=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);

	for(int i=1; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j] + 1;
				result = max(result, dp[i]);
			}
		}
	}

	printf("%d\n", result);
}
