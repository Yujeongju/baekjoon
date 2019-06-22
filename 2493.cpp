//2493 탑
#include <cstdio>
#include <stack>

using namespace std;

int result[500010];
pair<int, int> arr[500010];
int main(void)
{
	int num, input, flag = 1;
	stack<pair<int, int> > st;
	pair<int, int> p;
	scanf("%d", &num);

	for(int i=0; i<num; i++){
		scanf("%d", &(arr[i].first));
		arr[i].second = i+1;
	}

	result[0] = 0;
	st.push(arr[0]);
	for(int i=1; i<num; i++){
		if(arr[i].first > st.top().first){
			result[i] = 0;
			st.pop();
			while(!st.empty()){
				if(arr[i].first <= st.top().first){
					result[i] = st.top().second;
					break;
				}
				else
					st.pop();
			}
			st.push(arr[i]);
		}
		else{
			result[i] = st.top().second;
			st.push(arr[i]);
		}
	}


	for(int i=0; i<num; i++)
		printf("%d ", result[i]);
}
