#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 2<<29
using namespace std;

int c, n, l;
int arr[1010], sum;
double result;
int main(void)
{
	scanf("%d", &c);
	while(c--){
		result = INF;
		memset(arr, 0, sizeof(arr));
		scanf("%d %d", &n, &l);
		for(int i=0; i<n; i++)
			scanf("%d", &arr[i]);

		int tmp_l = l;
		int j=0;
		for(int i=0; i<=n-tmp_l; i++){
			l = tmp_l;
			sum = 0;
			for(j=i; j<l+i; j++)
				sum += arr[j];
			
			result = min(result, (double)sum/l);
			for(; j<n; j++){
				sum += arr[j];
				l++;
				result = min(result, (double)sum/l);
			}
		}

		printf("%.10lf\n", result);
	}
}
