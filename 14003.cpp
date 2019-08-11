//14003 가장 긴 증가하는 부분 수열5
//vector로 하니까 시간초과 뜸...
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

int N, arr[1000100], vt[1000100];
pair<int, int> result[1000100];

int main(void)
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	int index = 0;
	vt[0] = arr[0];
	result[0] = make_pair(arr[0], 0);
	for(int i=1; i<N; i++){
		if(arr[i] > vt[index]){
			vt[++index] = arr[i];
			result[i] = make_pair(arr[i], index);
		}
		else{
			int num = lower_bound(vt, vt+index, arr[i]) - vt;
			vt[num] = arr[i];
			result[i] = make_pair(arr[i], num);
		}
	}

	int idx = index;
	printf("%d\n", index+1);

	stack<int> st;
	for(int i=N-1; i>=0; i--){
		if(result[i].second == idx){
			st.push(result[i].first);
			idx--;
		}
	}

	while(!st.empty()){
		printf("%d ", st.top());
		st.pop();
	}

	printf("\n");
}
