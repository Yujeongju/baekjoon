//1697 숨바꼭질
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int result;
int visit[100010];

void bfs(int subin, int bro)
{
	queue< pair<int, int> > q;
	visit[subin] = 1;
	q.push(make_pair(subin, 0));
	
	while(!q.empty()){
		pair<int, int> tmp = q.front();
		q.pop();

		int new_dot = tmp.first;
		int new_tme = tmp.second;

		if(new_dot+1 == bro || new_dot-1 == bro || new_dot*2 == bro){
			result = new_tme+1;
			return;
		}
		
		if(new_dot+1 <= 100000 && visit[new_dot+1]==0){
			new_tme = tmp.second+1;
			visit[new_dot+1] = 1;
			q.push(make_pair(new_dot+1, new_tme));
		}
		
		if(new_dot-1 >= 0 && visit[new_dot-1]==0){
			new_tme = tmp.second+1;
			visit[new_dot-1] = 1;
			q.push(make_pair(new_dot-1, new_tme));
		}

		if(new_dot*2 <= 100000 && visit[new_dot*2] == 0){
			new_tme = tmp.second+1;
			visit[new_dot*2] = 1;
			q.push(make_pair(new_dot*2, new_tme));
		}

		result = new_tme;
	}
}

int main(void)
{
	int subin, bro;
	scanf("%d %d", &subin, &bro);

	if(subin == bro){
		printf("0\n");
		return 0;
	}

	bfs(subin, bro);

	printf("%d\n", result);
}
