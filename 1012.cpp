//1012 유기농배추
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[55][55];
int cnt=0;
int weight, height, k;
void egg(int x, int y)
{
	arr[x][y] = 0;

	if(!(x+1<0 || y < 0 || x+1 >=weight || y>=height) && arr[x+1][y] == 1)
		egg(x+1, y);
	if(!(x-1<0 || y < 0 || x-1 >=weight || y>=height) && arr[x-1][y] == 1)
		egg(x-1, y);
	if(!(x<0 || y+1 < 0 || x >=weight || y+1>=height) && arr[x][y+1] == 1)
		egg(x, y+1);
	if(!(x<0 || y-1 < 0 || x >=weight || y-1>=height) && arr[x][y-1] == 1)
		egg(x, y-1);
}

int main(void)
{
	int t, x,y;
	scanf("%d", &t);

	while(t--){
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d %d %d", &weight, &height, &k);

		for(int i=0; i<k; i++){
			scanf("%d %d", &x, &y);
			arr[x][y] = 1;
		}

		for(int i=0; i<=weight-1; i++){
			for(int j=0; j<=height-1; j++){
				if(arr[i][j] == 1 && !visit[i][j]){
					egg(i,j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	}
}
