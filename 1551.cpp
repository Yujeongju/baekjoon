//1551 수열의 변화
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vt, arr;
int main(void)
{
	int n, k, t;
	scanf("%d %d", &n, &k);

	for(int i=0; i<n; i++){
		scanf("%d,", &t);
		arr.push_back(t);
	}

	if(k==0){
		for(int i=0; i<n-1; i++){
			printf("%d,", arr[i]);
		}
		printf("%d\n", arr[n-1]);
		return 0;
	}

	for(int i=0; i<k; i++){
		vt.clear();
		for(int j=0; j<arr.size()-1; j++){
			vt.push_back(arr[j+1]-arr[j]);
		}

		arr.clear();
		for(int j=0; j<vt.size(); j++)
			arr.push_back(vt[j]);
	}

	for(int i=0; i<vt.size()-1; i++){
		printf("%d,", vt[i]);
	}

	printf("%d\n", vt[vt.size()-1]);
}
