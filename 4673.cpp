//4673 셀프넘버 구현
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int temp=0;
	int result=0;
	int arr[10100];
	int cnt=0, flag=0;

	for(int i=1; i<10000; i++)
	{
		result=0;
		temp = i;
		result += temp;
		while(1){
			if(temp/10 == 0){
				result += (temp%10);
				break;
			}
			result += (temp%10);
			temp/=10;
		}
		
		arr[cnt++] = result;
	}

	for(int k=1; k<10000; k++){
		flag=0;
		for(int i=0; i<cnt; i++){
			if(k==arr[i]){
				flag=1;
				break;
			}
		}

		if(!flag)
			printf("%d\n", k);
	}

	exit(0);
}
