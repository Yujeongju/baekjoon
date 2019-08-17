//2740 행렬 곱셈
#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF 2<<29

using namespace std;

int n, m, k;
int result[110][110], mat1[110][110], mat2[110][110];
int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &mat1[i][j]);

	scanf("%d %d", &m, &k);
	for(int i=0; i<m; i++)
		for(int j=0; j<k; j++)
			scanf("%d", &mat2[i][j]);

	for(int i=0; i<n; i++)
		for(int j=0; j<k; j++)
			for(int k=0; k<m; k++)
				result[i][j] += mat1[i][k] * mat2[k][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}
}
