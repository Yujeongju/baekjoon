//9251 LCS
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str1[1010], str2[1010];
int dp[1010][1010], str1_len, str2_len;
int main(void)
{
	scanf("%s", str1);
	scanf("%s", str2);

	str1_len = strlen(str1);
	str2_len = strlen(str2);

	for(int i=1; i<=str1_len; i++){
		for(int j=1; j<=str2_len; j++){
			if(str1[i-1] == str2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}

	printf("%d\n", dp[str1_len][str2_len]);
}
