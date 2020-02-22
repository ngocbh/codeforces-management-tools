<<<<<<< Updated upstream
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int fun(int n)
{
	if (n == 1) return 1;
	return (2 * fun(n - 1) + 2*(n-1));
}
int main()
{
	cin >> n;
	cout << fun(n);
//	system("pause");
=======
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int fun(int n)
{
	if (n == 1) return 1;
	return (2 * fun(n - 1) + 2*(n-1));
}
int main()
{
	cin >> n;
	cout << fun(n);
//	system("pause");
>>>>>>> Stashed changes
}