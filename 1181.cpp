//1181 단어 정렬
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct data{
	char word[60];
	int length;
}Data;

bool comp(Data data1, Data data2){
	if(data1.length == data2.length){
		for(int i=0; i<data1.length; i++){
			if(data1.word[i] == data2.word[i])
				continue;
			else if(data1.word[i] < data2.word[i])
				return 1;
			else
				return 0;
		}
	}

	return data1.length < data2.length;
}

Data input[20010];
int main(void)
{
	int t;
	char temp[60] = "";
	scanf("%d", &t);

	for(int i=0; i<t; i++){
		scanf("%s", input[i].word);
		input[i].length = strlen(input[i].word);
	}

	sort(input, input+t, comp);

	printf("%s\n", input[0].word);
	for(int i=1; i<t; i++){
		if(strcmp(input[i].word, input[i-1].word) == 0)
			continue;
		printf("%s\n", input[i].word);
	}

	return 0;
}
