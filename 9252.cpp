//9252 LCS2
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char str1[1010], str2[1010];
vector<char> result;
int dp[1010][1010];
int main(void)
{
	int len1, len2, cnt = 0;
	scanf("%s %s", str1, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);

	for(int i=1; i<=len2; i++){
		for(int j=1; j<=len1; j++){
			if(str1[j-1] == str2[i-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int i = len2-1;
	int j = len1-1;
	while(1){
		if(i < 0 || j < 0)
			break;

		if(str1[j] == str2[i]){
			result.insert(result.begin(), str1[j]);
			i--;
			j--;
		}
		else{
			if(dp[i+1][j+1] == dp[i][j+1])
				i--;
			else
				j--;
		}
	}


	printf("%d\n", dp[len2][len1]);
	for(int i=0; i<result.size(); i++){
		printf("%c", result[i]);
	}
	printf("\n");

}
