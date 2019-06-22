//5397 키로거
#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

char input[1000100];
char result[1000100];
int main(void)
{
	stack<char> st, temp;
	int num, len, cnt=0;
	scanf("%d", &num);

	while(num--){
		scanf("%s", input);
		getchar();
		
		len = strlen(input);

		for(int i=0; i<len; i++){
			if(input[i] == '<'){
				if(!st.empty()){
					temp.push(st.top());
					st.pop();
				}
			}
			else if(input[i] == '>'){
				if(!temp.empty()){
					st.push(temp.top());
					temp.pop();
				}
			}
			else if(input[i] == '-'){
				if(!st.empty()){
					st.pop();
				}
			}
			else{
				st.push(input[i]);
			}
		}
		while(!temp.empty()){
			st.push(temp.top());
			temp.pop();
		}
		cnt = st.size();

		while(!st.empty()){
			result[st.size()-1] = st.top();
			st.pop();
		}
		result[cnt] = 0;

		printf("%s\n", result);
		result[0] = 0;
	}

}
