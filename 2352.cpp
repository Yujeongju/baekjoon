//2352 반도체 설계
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int input[40010];
vector<int> arr;
int main(void)
{
	int n, result=0, num;
	scanf("%d", &n);

	for(int i=1; i<=n; i++){
		scanf("%d", &input[i]);
	}

	arr.push_back(-1);
	for(int i=1; i<=n; i++){
		if(input[i] > arr[arr.size()-1]){
			arr.push_back(input[i]);
		}
		else{
			arr[lower_bound(arr.begin(), arr.end(), input[i])-arr.begin()] = input[i];
		}
	}


	printf("%d\n", arr.size()-1);
}
