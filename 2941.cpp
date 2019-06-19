//2941 크로아티아 알파벳
#include <cstdio>
#include <cstring>

int main(void)
{
	char input[110];
	int cnt=0;

	scanf("%s",  input);

	for(int i=0; i<strlen(input); i++){
		if(input[i] == 'c'){
			if(input[i+1] == '=' || input[i+1] == '-'){
				i++;
				cnt++;
			}
			else
				cnt++;
		}
		else if(input[i] == 'd'){
			if(input[i+1] == '-'){
				i++;
				cnt++;
			}
			else if(input[i+1] == 'z' && input[i+2] == '='){
				i+=2;
				cnt++;
			}
			else{
				cnt++;
			}
		}
		else if(input[i] == 'l'){
			if(input[i+1] == 'j'){
				i++;
				cnt++;
			}
			else{
				cnt++;
			}
		}
		else if(input[i] == 'n'){
			if(input[i+1] == 'j'){
				i++;
				cnt++;
			}
			else
				cnt++;
		}
		else if(input[i] == 's'){
			if(input[i+1] == '='){
				i++;
				cnt++;
			}
			else
				cnt++;
		}
		else if(input[i] == 'z'){
			if(input[i+1] == '='){
				i++;
				cnt++;
			}
			else
				cnt++;
		}
		else{
			cnt++;
		}
	}

	printf("%d\n", cnt);
}

