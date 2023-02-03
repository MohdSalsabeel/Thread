#include<iostream>
#include<queue>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
#include<string>
using namespace std;

char getMaxOccurence(string s) {
	int arr[26]={0};
	for (int i = 0; i < s.size(); i++) {
		char ch = s[i];
		int number = 0;
		// lowercase
		if (ch >= 'a' && ch <= 'z') {
			number = ch - 'a';
		}
		else {
			number = ch - 'A';
		}
		arr[number]++;
	}
	// find maximum occurence character
	int maxi = -1, ans = -1;
	for (int i = 0; i < 26; i++) {
		if (maxi < arr[i]) {
			ans = i;
			maxi = arr[i];
		}
	}
	char finalAns = 'a' + ans;
	return finalAns;
}

string removeOccurence(string s, string part) {

	while (s.length() != 0 && s.find(part) < s.length()) {
		s.erase(s.find(part), part.length());
	}
	return s;
}


int main() {
	
	//string s = "Hello";
	//cout << getMaxOccurence(s);
	
	//cout << removeOccurence("name", "na");

	return 0;
}
