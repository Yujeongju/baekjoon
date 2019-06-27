//5622 다이얼
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;
int main(void)
{
	pair<char, int> arr[50];
	int cnt=3;
	for(int i='A'; i<='Z'; i++){
		if(i=='D' || i=='G' || i=='J' || i=='M' || i=='P' || i=='T' || i=='W')
			cnt++;
		arr[i-'A'] = make_pair(i, cnt);
	}

	char input[30];
	scanf("%s", input);
	input[strlen(input)] = 0;

	cnt=0;
	for(int i=0; i<strlen(input); i++){
		for(int j='A'; j<='Z'; j++){
			if(input[i] == arr[j-'A'].first){
				cnt += arr[j-'A'].second;
				break;
			}
		}
	}

	printf("%d\n", cnt);
}
