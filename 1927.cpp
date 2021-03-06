//1927 최소 힙
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<int> arr;
int main(void)
{
	int t, input;
	scanf("%d", &t);
	priority_queue<pair<int, int> > pq;

	while(t--){
		scanf("%d", &input);
		
		if(input != 0){
			arr.push_back(input);
			pq.push(make_pair(-input, input));
		}
		else{
			if(pq.empty()){
				printf("0\n");
				continue;
			}

			int maxx = -pq.top().first;
			pq.pop();
			for(int i=0; i<arr.size(); i++){
				if(arr[i] == maxx){
					printf("%d\n", arr[i]);
					arr.erase(arr.begin()+i);
					break;
				}
			}
		}
	}
}
