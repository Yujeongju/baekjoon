#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int c, n, m, cnt;
int arr[11][11];
void find_pair(int visit[])
{
	int index = -1;
	for(int i=0; i<n; i++){
		if(visit[i] == 0){
			index = i;
			break;
		}
	}

	if(index == -1){
		cnt++;
		return;
	}

	for(int i=index+1; i<n; i++){
		if(visit[i] == 0 && arr[index][i]){
			visit[index] = visit[i] = 1;
			find_pair(visit);
			visit[index] = visit[i] = 0;
		}
	}
}

int main(void)
{
	int a, b;
	int visit[11];
	scanf("%d", &c);
	while(c--){
		cnt = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		scanf("%d %d", &n, &m);
		for(int i=0; i<m; i++){
			scanf("%d %d", &a, &b);
			arr[a][b] = arr[b][a] = 1;
		}

		find_pair(visit);
		printf("%d\n", cnt);

	}
}
