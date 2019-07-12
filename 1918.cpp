//1918 후위표기식
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

char input[110], result[110];
int main(void)
{
	int length, cnt=0;
	stack<char> st;
	scanf("%s", input);
	length = strlen(input);
	
	for(int i=0; i<length; i++){
		if(input[i] >= 'A' && input[i] <= 'Z'){
			result[cnt++] = input[i];
		}
		else{
			if(input[i] == '('){
				st.push(input[i]);
			}
			else if(input[i] == ')'){
				while(st.top() != '('){
					result[cnt++] = st.top();
					st.pop();
				}
				st.pop();
			}
			else if(input[i] == '*' || input[i] == '/'){
				while(!st.empty() && (st.top() == '*' || st.top() == '/')){
					result[cnt++] = st.top();
					st.pop();
				}
				st.push(input[i]);
			}
			else if(input[i] == '+' || input[i] == '-'){
				while(!st.empty() && st.top() != '('){
					result[cnt++] = st.top();
					st.pop();
				}
				st.push(input[i]);
			}
		}
	}

	while(!st.empty()){
		result[cnt++] = st.top();
		st.pop();
	}

	result[cnt] = 0;

	printf("%s\n", result);

}
