//14002 가장 긴 증가하는 부분수열4
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

int dp[1010], save[1010], arr[1010];
int result_arr[1010];
int main(void)
{
	int input, result=1, cnt=1, index=1;
	scanf("%d", &input);

	for(int i=1; i<=input; i++){
		scanf("%d", &arr[i]);
		dp[i] = 1;
	}

	for(int i=1; i<=input; i++){
		for(int j=0; j<=i; j++){
			if(arr[i] > arr[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
				save[cnt] = j;
				if(result < dp[i]){
					result = dp[i];
					index = i;
				}
			}
		}
		cnt++;
	}
	cnt = 1;
	result_arr[cnt++] = arr[index];
	while(1){
		index = save[index];
		if(index == 0)
			break;
		result_arr[cnt++] = arr[index];
	}
	sort(result_arr, result_arr+cnt);

	printf("%d\n", result);

	for(int i=1; i<cnt; i++)
		printf("%d ", result_arr[i]);
	printf("\n");
}
