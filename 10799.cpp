//10799 쇠막대기
#include <cstdio>
#include <cstring>

using namespace std;

char input[100010];
int main(void)
{
	int result=0, cnt=0, temp=0, check=1;
	scanf("%s", input);

	for(int i=0; i<strlen(input); i++){
		if(input[i] == '('){
			cnt++;
		}
		else if(input[i] == ')'){
			cnt--;
			if(input[i-1]=='(')
				result += cnt;
			else if(input[i-1] == ')'){
				result += 1;
			}
		}
	}

	printf("%d\n", result);

}
