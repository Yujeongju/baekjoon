//12738 가장 긴 증가하는 부분 수열3
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000100];
vector<int> vt;
int main(void)
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	vt.push_back(arr[0]);
	for(int i=1; i<n; i++){
		if(arr[i] > vt[vt.size()-1]){
			vt.push_back(arr[i]);
		}
		else{
			int idx = lower_bound(vt.begin(), vt.end(), arr[i]) - vt.begin();
			vt[idx] = arr[i];
		}
	}

	printf("%d\n", vt.size());
}
