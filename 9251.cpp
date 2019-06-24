//9251 LCS
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int main(void)
{
	char str1[1010], str2[1010];
	int dp[1010][1010]={0}, max_len, min_len;

	scanf("%s", str1);
	scanf("%s", str2);

	max_len = strlen(str1);
	min_len = strlen(str2);

	for(int i=0; i<max_len; i++){ //str1에서의 부분집합을 찾아야함
		for(int j=0; j<min_len; j++){ //str1의 길이만큼 반복
			if(str1[i] == str2[j]){ //두 개가 같으면
				dp[i+1][j+1] = dp[i][j]+1; //좌측 상단에 +1한 값을 가져옴
			}
			else{
				//같지 않으면 상단과 좌측 중 max값을 가져옴
				dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}

	printf("%d\n", dp[max_len][min_len]);
}
