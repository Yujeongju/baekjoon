//1931 회의실배정
#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

pair<int, int> arr[100100];

bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main(void)
{
	int N, a, b, cnt=0;
	int min_fin, index=0;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		scanf("%d %d", &a, &b);
		arr[i] = make_pair(a, b);
	}

	sort(arr, arr+N, comp);
	min_fin = arr[0].second;

	for(int i=1; i<N; i++){
		if(min_fin > arr[i].second){
			min_fin = arr[i].second;
			index = i;
		}
	}

	cnt = 1;
	for(int i=index+1; i<N; i++){
		if(min_fin <= arr[i].first){
			min_fin = arr[i].second;
			cnt++;
		}
	}

	printf("%d\n", cnt);

}
