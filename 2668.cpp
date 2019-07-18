//2668 숫자고르기
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, arr[110], save[110];
int visit[110], cnt;
vector<int> result;
int max_cnt=0;
void dfs(int i, int num){
	if((visit[i] == 1 && num != save[0]) || num == i){
		return;
	}

	if(cnt > N){
		cnt = 0;
		return;
	}

	//사이클 생성
	if(num == save[0]){
		max_cnt += cnt;
		for(int j=0; j<cnt; j++){
			visit[save[j]] = 1;
			result.push_back(save[j]);
		}
		return;
	}

	save[cnt++] = num;
	dfs(num, arr[num]);
	
}

int main(void)
{
	scanf("%d", &N);

	for(int i=1; i<=N; i++){
		scanf("%d", &arr[i]);
	}

	for(int i=1; i<=N; i++){
		memset(save, 0 , sizeof(save));
		cnt = 0;
		if(visit[i] == 0)
			dfs(i, arr[i]);
	}

	for(int i=1; i<=N; i++){
		cnt = 0;
		if(i == arr[i]){
			for(int j=0; j<max_cnt; j++){
				if(result[j] == arr[i]){
					cnt++;
					break;
				}
			}
			
			if(!cnt){
				max_cnt++;
				result.push_back(i);
			}
		}
	}
	sort(result.begin(), result.end());
	printf("%d\n", max_cnt);
	
	for(int i=0; i<max_cnt; i++){
		printf("%d\n", result[i]);
	}
}
