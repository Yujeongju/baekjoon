//3943 헤일스톤 수열
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[100100], T, n;
int main(void)
{
	long long num=0, result=1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		num = n;
		result = num;
		while(num != 1){
			if(num % 2 == 0)
				num /= 2;
			else
				num = num * 3 + 1;

			if(num > result)
				result = num;
		}

		printf("%lld\n", result);
	}
}
