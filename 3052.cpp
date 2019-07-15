//3052 나머지
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[11], input[11];
int main(void)
{
	int cnt=1, check;
	for(int i=0; i<10; i++){
		scanf("%d", &arr[i]);
		input[i] = arr[i]%42;
	}

	sort(input, input+10);

	check = input[0];
	for(int i=1; i<10; i++){
		if(input[i] != check){
			cnt++;
			check = input[i];
		}
	}

	printf("%d\n", cnt);

}
