//17298 오큰수
#include <cstdio>
#include <stack>
#include <algorithm>

#define INF 2<<29
using namespace std;

int N, arr[1000100], result[1000100];
stack<int> st;
int main(void)
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	st.push(INF);
	for(int i=N-1; i>=0; i--){
		while(st.top() <= arr[i])
			st.pop();

		if(st.top() >= INF)
			result[i] = -1;
		else
			result[i] = st.top();
		st.push(arr[i]);
	}

	for(int i=0; i<N-1; i++)
		printf("%d ", result[i]);
	printf("%d\n", result[N-1]);
}
