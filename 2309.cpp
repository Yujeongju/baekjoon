//2309 일곱난쟁이
#include <cstdio>
#include <algorithm>

using namespace std;
int main(void)
{
	int arr[10], sum=0, temp=0,index1=0, index2=0;
	for(int i=0; i<9; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sort(arr, arr+9);
	for(int i=0; i<9; i++){
		temp = sum;
		for(int j=i; j<9; j++){
			if(temp - (arr[i]+arr[j]) == 100){
				index1 = i;
				index2 = j;
				break;
			}
		}

		if(index1 || index2)
			break;
	}

	for(int i=0; i<9; i++){
		if(i==index1 || i==index2)
			continue;
		
		printf("%d\n", arr[i]);
	}
}
