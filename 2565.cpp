//2565 전깃줄
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> line[510];
int dp[110];
int main(void)
{
	int n, a,b, result=0;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d %d", &line[i].first, &line[i].second);
	}

	sort(line, line+n+1);

	for(int i=1; i<=n; i++){
		for(int j=0; j<=i; j++){
			if(line[i].second > line[j].second && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
				result = max(dp[i], result);
			}
		}
	}

	printf("%d\n", n-result);
}
