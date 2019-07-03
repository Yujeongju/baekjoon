//11651 좌표 정렬하기2
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, int> input[100100];

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second > b.second)
		return false; 
	else if(a.second < b.second){
		return true;;
	}
	else{
		if(a.first > b.first)
			return false;
		else
			return true;
	}
}

int main(void)
{
	int num;
	scanf("%d", &num);

	for(int i=0; i<num; i++){
		scanf("%d %d", &input[i].first, &input[i].second);
	}

	sort(input, input+num, comp);

	for(int i=0; i<num; i++){
		printf("%d %d\n", input[i].first, input[i].second);
	}

}
