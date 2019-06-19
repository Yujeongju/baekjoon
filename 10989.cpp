//10989 수정렬하기3
//counting sort
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100001];
int main(void)
{
	int input, num, max=0;
	scanf("%d", &input);

	for(int i=0; i<input; i++){
		scanf("%d", &num);
		arr[num]++;
		if(num > max)
			max = num;
	}

	for(int i=0; i<=max; i++){
		if(arr[i] > 0){
			for(int j=0; j<arr[i]; j++){
				printf("%d\n", i);
			}
		}
	}
}
