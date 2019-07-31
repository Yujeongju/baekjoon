//2644 촌수계산
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, p1, p2, e, result, visit[110];
vector<int> vt[110];

int bfs(int v)
{
	visit[v] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(v, 0));

	while(!q.empty()){
		int tmp = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(tmp == p2){
			return cnt;
		}

		for(int i=0; i<vt[tmp].size(); i++){
			int nxt = vt[tmp][i];
			if(visit[nxt] == 0){
				visit[nxt] = 1;
				q.push(make_pair(nxt, cnt+1));
			}
		}
	}

	return -1;
}

int main(void)
{
	int from, to;
	scanf("%d", &n);
	scanf("%d %d", &p1, &p2);
	scanf("%d", &e);
	for(int i=0; i<e; i++){
		scanf("%d %d", &from, &to);
		vt[from].push_back(to);
		vt[to].push_back(from);
	}


	printf("%d\n", bfs(p1));
}
