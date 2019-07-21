//1365 꼬인 전깃줄
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100100];
int lower_bound(vector<int> vt, int num){
	int low = 0, high = vt.size()-1;

	//이분탐색 -> num이 들어갈 위치를 찾는다.
	while(low < high){
		int mid = (low + high) / 2;
		if(vt[mid] >= num)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

int main(void)
{
	int n, cnt=1, num;
	vector<int> vt;

	scanf("%d", &n);
	vt.push_back(-1);
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	for(int i=0; i<n; i++){
		//앞의 값보다 크면 push
		if(arr[i] > vt[vt.size()-1])
			vt.push_back(arr[i]);
		//아니라면 lower_bound를 이용해 알맞은 위치에 push
		else
			vt[lower_bound(vt, arr[i])] = arr[i];
	}

	//자른 수를 구하는 것이므로 n-vt.size()+1
	printf("%lu\n", n-vt.size()+1);
}

