//1966 프린터큐
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
	return a>b;
}
int main(void)
{
	queue<pair<int, int> > data;
	int save[100];
	int t, paper, input, p_num;
	int cnt=0, arr_cnt=0;
	scanf("%d", &t);

	while(t--){
		while(!data.empty()){
			data.pop();
		}
		memset(save, 0, 100);
		cnt = 0;
		arr_cnt = 0;
		scanf("%d %d", &paper, &input);

		for(int i=0; i<paper; i++){
			scanf("%d", &p_num);
			save[i] = p_num;
			if(i == input)
				data.push(make_pair(p_num, 1));
			else
				data.push(make_pair(p_num, 0));
		}

		sort(save, save+paper, desc);

		while(!data.empty()){
			if(data.front().first == save[arr_cnt]){
				arr_cnt++;
				cnt++;
				if(data.front().second == 1){
					printf("%d\n", cnt);
					break;
				}
				else{
					data.pop();
				}
			}
			else{
				data.push(data.front());
				data.pop();
			}
		}

	}
}
