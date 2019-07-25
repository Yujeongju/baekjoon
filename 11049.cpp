//11049 행렬 곱셈 순서
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

#define INF 2<<28
using namespace std;

int arr[510][510];
int d[510];
int main(void)
{
	int n, t;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d %d", &d[i], &t);
	}
	d[n] = t;

	for(int i=1; i<=n; i++)
		arr[i][i] = 0;

	for(int len=1; len<=n-1; len++){
		for(int i=1; i<=n-len; i++){
			int j = len+i;
			arr[i][j] = INF;
			for(int k=i; k<=j-1; k++){
				arr[i][j] = min(arr[i][j], arr[i][k]+arr[k+1][j]+(d[i-1]*d[k]*d[j]));
			}
		}
	}

	printf("%d\n", arr[1][n]);

}
