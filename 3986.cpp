//3986 좋은 단어
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

char input[100010];
int main(void)
{
	int num, cnt=0, flag=1, len=0;
	stack<char> st;
	scanf("%d", &num);

	while(num--){
		flag = 1;
		scanf("%s", input);

		len = strlen(input);

		for(int i=0; i<len; i++){
			if(!st.empty() && st.top() == input[i])
				st.pop();
			else
				st.push(input[i]);
		}

		if(!st.empty()){
		}
		else{
			cnt++;
		}

		while(!st.empty()){
			st.pop();
		}
	}

	printf("%d\n", cnt);
}
