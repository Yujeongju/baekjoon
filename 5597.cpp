//5597 과제 안 내신 분..?
#include <cstdio>
#include <algorithm>

using namespace std;

int result[50];
int main(void)
{
	int a, cnt=0;
	for(int i=0; i<28; i++){
		scanf("%d", &a);
		result[a] = 1;
	}

	for(int i=1; i<=30; i++){
		if(result[i]==0 && cnt<2){
			cnt++;
			printf("%d\n", i);
		}
	}

}
