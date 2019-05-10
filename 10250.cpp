//10250 ACM 호텔 단순구현

#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int h, w, n;
	int input, cnt=0;

	scanf("%d", &input);
	
	for(int i=0; i<input; i++){
		scanf("%d %d %d", &h, &w, &n);
		cnt=0;
		for(int j=1; j<=w; j++){
			for(int k=1; k<=h; k++){
				if((++cnt) == n){
					printf("%d%02d\n", k, j);
				}
			}
		}
	}

	exit(0);
}
