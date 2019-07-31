//1138 한 줄로 서기
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int N;
pair<int, int> arr[11];
vector<pair<int, int> > vt;
int main(void)
{
	int input;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &input);
		arr[i] = make_pair(input, i);
	}

	vt.push_back(arr[N]);
	for(int i=N-1; i>=1; i--){
		vt.insert(vt.begin()+arr[i].first, arr[i]);
	}

	for(int i=0; i<vt.size(); i++){
		printf("%d ", vt[i].second);
	}

}
