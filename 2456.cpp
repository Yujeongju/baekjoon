//2456 나는 학급회장이다
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> sum[4];
int num[4];
int main(void)
{
	int input, max_score=0;

	scanf("%d", &input);
	for(int i=1; i<=3; i++){
		sum[i].second = 1;
	}
	while(input--){
		scanf("%d %d %d", &num[1], &num[2], &num[3]);

		for(int i=1; i<=3; i++){
			sum[i].first += num[i];
			sum[i].second += (num[i]*num[i]);
		}
	}
	for(int i=1; i<=3; i++){
		max_score = max(max_score, sum[i].first);
	}

	//1 max
	if(sum[1] > sum[2] && sum[1]>sum[3]){
		printf("1 %d\n", sum[1].first);
	}
	//2 max
	else if(sum[2] > sum[1] && sum[2]>sum[3]){
		printf("2 %d\n", sum[2].first);
	}
	//3 max
	else if(sum[3]>sum[1] && sum[3]>sum[2]){
		printf("3 %d\n", sum[3].first);
	}
	else{
		printf("0 %d\n", max_score);
	}
}
