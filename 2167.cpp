//2167 배열의합
#include <cstdio>

int arr[310][310], dp[100100];
int main(void)
{
	int n,m;
	int k;
	int i, j, x, y;

	scanf("%d %d", &n, &m);

	for(int ii=1; ii<=n; ii++)
		for(int jj=1; jj<=m; jj++)
			scanf("%d", &arr[ii][jj]);

	scanf("%d", &k);

	int cnt = 0;
	while(k--){
		cnt = 0;
		for(int ii=0; ii<=10000; ii++)
			dp[ii] = 0;

		//(i,j) ~ (x,y)
		scanf("%d %d %d %d", &i, &j, &x, &y);

		for(int ii=i; ii<=x; ii++){
			for(int jj=j; jj<=y; jj++){
				dp[cnt+1] = dp[cnt]+arr[ii][jj];
				cnt++;
			}
		}

		printf("%d\n", dp[cnt]);
	}
}
