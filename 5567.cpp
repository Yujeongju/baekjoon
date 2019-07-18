//5567 결혼식
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m;
vector<int> graph[510];
int visit[510], result[510];

void bfs(int x)
{
	queue<pair<int, int> > q;
	q.push(make_pair(x, 0));
	visit[x] = 1;

	while(!q.empty()){
		int tmp = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for(int i=0; i<graph[tmp].size(); i++){
			int nxtx = graph[tmp][i];
			if(visit[nxtx] == 0){
				visit[nxtx]=1;
				q.push(make_pair(nxtx, cnt+1));
				result[nxtx] = cnt+1;
			}
		}
	}
}

int main(void)
{
	int from, to, cnt=0;
	scanf("%d %d", &n, &m);

	for(int i=0; i<m; i++){
		scanf("%d %d", &from, &to);
		//친구 관계는 양방향이다... 혼자 친구할 수는 없잖아?
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for(int i=1; i<=n; i++){
		if(graph[i].size() != 0)
			bfs(i);
	}

	for(int i=2; i<=n; i++){
		if(result[i] <= 2 && result[i] > 0)
			cnt++;

	}

	printf("%d\n", cnt);
}
