//1316 그룹 단어 체커
#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;
int main(void)
{
	stack<char> st;
	char input[110];
	int save[110]={0};
	int num, cnt=0, result=0;
	scanf("%d", &num);

	while(num--){
		cnt = 0;
		scanf("%s", input);
		st.push(input[0]);
		for(int i=1; i<strlen(input); i++){
			if(st.top() != input[i]){
				st.push(input[i]);
			}
		}

		while(st.size()){	
			save[st.top()-'a']++;
			st.pop();
		}

		for(int i='a'; i<='z'; i++){
			if(save[i-'a'] > 1)
				break;
			if(i=='z')
				result++;

		}

		for(int i='a'; i<='z'; i++){
			save[i-'a'] = 0;
		}
	}

	printf("%d\n", result);
}
