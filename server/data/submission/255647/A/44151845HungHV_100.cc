#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	getline(cin, a);
	int l = a.length();
	for (int i = 0; i < l - 1; i++) {
		if (a[i] == a[i + 1]) {
			a.erase(i, 1);
			i = i - 1;
			l = l - 1;
		}
	}
	cout << a;
	//system("pause");
	return 0;
}