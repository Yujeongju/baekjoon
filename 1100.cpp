//1100 하얀 칸
#include <cstdio>
#include <cstring>

using namespace std;

char arr[10][10];
int main(void)
{
	int white=1, cnt = 0;

	for(int i=0; i<8; i++){
		if(i % 2 == 0)
			white = 1;
		else
			white = 0;

		scanf("%s", arr[i]);
		getchar();

		for(int j=0; j<8; j++){
			if(white){
				if(arr[i][j] == 'F')
					cnt++;
				white = 0;
			}
			else
				white = 1;
		}
	}

	printf("%d\n", cnt);

}
