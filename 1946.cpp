//1946 신입사원
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> data[100010];

bool comp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main(void)
{
	int t;
	scanf("%d", &t);

	int num, paper, face;
	int cnt=1, min = 0;
	while(t--){
		cnt = 1;
		memset(data, 0, sizeof(data));
		scanf("%d", &num);

		for(int i=0; i<num; i++){
			scanf("%d %d", &paper, &face);
			data[i] = make_pair(paper, face);
		}
		
		sort(data, data+num, comp);
		min = data[0].second;
		for(int i=1; i<num; i++){
			if(data[i].second < min){
				min = data[i].second;
				cnt++;
			}
		}

		printf("%d\n", cnt);
		
	}
}
