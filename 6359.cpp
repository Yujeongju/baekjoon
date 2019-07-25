//6359 만취한 상범
#include <cstdio>
#include <algorithm>

using namespace std;

int box[110];
int main(void)
{
	int t, n, cnt;
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		fill(box, box+n+1, 1);
		cnt = 0;

		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j+=i){
				if(box[j] == 1){
					box[j] = 0;
				}
				else
					box[j] = 1;
			}
		}

		for(int i=1; i<=n; i++){
			if(box[i] == 0)
				cnt++;
		}

		printf("%d\n", cnt);

	}
}
