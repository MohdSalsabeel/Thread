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

int compressor(vector<char>& chars) {
	int i = 0;
	int ansIndex = 0;
	int n = chars.size();

	while (i < n) {
		int j = i + 1;
		while (chars[i] == chars[j] && j < n) {
			j++;
		}
		// yaha kab ayega
		// ya vector pura traverse karke
		// ye fir new/different vector encounter karke

		chars[ansIndex++] = chars[i];

		int count = j - i;
		if (count > 1) {
			// converting count into string and saving count with single digit
			string cnt = to_string(count);
			for (char ct : cnt) {
				chars[ansIndex++] = ct;
			}
		}
		// moving to new characters
		i = j;
	}
	return ansIndex;
}


int main() {
	
	vector<char> chars = { 'a','a','b','b','c','c','c' };
	cout << compressor(chars);

	return 0;
}
