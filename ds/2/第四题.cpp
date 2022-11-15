#include<iostream>
using namespace std;

bool IsSymmetric(string str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	i--;

	for (int j = 0; i != j && i != (j + 1); i--, j++) {
		//cout << i<<':'<<str[i] << ' '<<j<<':' << str[j] << endl;
		if (str[i] != str[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	string a = "abcba";
	string b = "xyzzyx";
	string c = "acv";
	cout << IsSymmetric(a) << ' ' << IsSymmetric(b) << ' ' << IsSymmetric(c);

	return 0;
}