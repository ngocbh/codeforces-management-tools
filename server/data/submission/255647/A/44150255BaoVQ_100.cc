#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main(){
	string arr;
	getline(std::cin, arr);
	
	for (int i = 0; i < arr.length()-1; i++){
		if (arr[i] == arr[i + 1]){
			arr.erase(i, 1);
			i--;
		}
	}
	//arr.erase(0, 1);
	cout << arr;
}