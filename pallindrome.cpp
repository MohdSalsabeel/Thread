#include<iostream>
#include<queue>
#include<vector>
#include<array>
#include<map>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

bool valid(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') && (ch >= '0' && ch <= '9')) {
		return 1;
	}
	return 0;
}

char toLowerCase(char ch) {
	if ((ch >= 'a' && ch <= 'z') && (ch >= '0' && ch <= '9')) {
		return ch;
	}
	else {
		char temp = ch - 'A' + 'a';
		return temp;
	}
}

bool checkPallin(string name) {
	int s = 0;
	int e = name.length() - 1;
	while (s < e) {
		if (name[s] != name[e]) {
			return false;
		}
		s++;
		e--;
	}
	return true;
}

bool checkPallindrome(char name[], int n) {
	int s = 0;
	int e = n - 1;
	while (s < e) {
		if (toLowerCase(name[s]) != toLowerCase(name[e])) {
			return false;
		}
		s++;
		e--;
	}
	return true;
}

int getLength(char name[]) {
	int cnt=0;
	for (int i = 0; name[i] != '\0'; i++) {
		cnt++;
	}
	return cnt;
}

void reverseString(char name[], int n) {
	
	int s = 0;
	int e = n - 1;
	while (s < e) {
		swap(name[s], name[e]);
		s++;
		e--;
	}
}

int main() {
	/*char ch[10];
	cin >> ch;
	ch[2] = '\t';
	cout << ch;*/

	//char name[10];
	//cin >> name;
	//cout << sizeof(name)/sizeof(name[0]);
	//cout << getLength(name) << endl;
	//reverseString(name,getLength(name));
	//cout <<"Reverse string is : "<< name<<endl;
	//cout << "Pallindrome or Not : " << checkPallindrome(name, getLength(name))<< endl;

	//cout << "Character: " << toLowerCase('B') << endl;
	/*string a = "abc";
	a.push_back('d');
	a.pop_back();
	cout << a.size()<<" "<<a<<endl;
	string b;
	cin >> b;
	cout << b<<endl;*/
	//char a[] = { 'a','b','c','d','\0'};
	//char a[] = "abcd";
	//cout << a << endl;
	//cout << sizeof(a)/sizeof(a[0]);

	// Faltu Character Hatao
	string ch = "noon";
	string temp = "";
	for (int j = 0; j < ch.length(); j++) {
		if (valid(ch[j])) {
			temp.push_back(ch[j]);
		}
	}

	// lowercase kardo
	for (int i = 0; i < temp.length(); i++) {
		temp[i] = toLowerCase(temp[i]);
	}

	// Check Pallindrome
	bool ans = checkPallin(temp);
	if (ans) {
		cout << "It is Pallindrome" << endl;
	}
	else {
		cout << "It is not Pallindrome" << endl;
	}

	return 0;
}
