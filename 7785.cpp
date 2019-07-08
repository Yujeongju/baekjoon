//7785 회사에 있는 사람
#include <iostream>  
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
	scanf("%d", &n);
	set<string> string_set;
    
	for (int i=0; i<n; i++){
		string sub_name, sub_work;
		cin >> sub_name >> sub_work;
 
		if(sub_work == "enter" )
			string_set.insert(sub_name);
		else
			string_set.erase(sub_name);
	}

	for(auto iter = string_set.rbegin(); iter != string_set.rend(); iter++)
		cout << *iter << "\n"; 
	return 0;
}
