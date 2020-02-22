<<<<<<< Updated upstream
#include <iostream>
#include <vector>
#define MAX 10000
 
using namespace std;
 
int N, M;
vector<int> G[MAX];
// result of solution
// int x[MAX];
 
struct edge
{
	int u, v;
};
 
vector<edge> V = { {-1, -1} };
int x[MAX];
int result = 0;
 
 
void init();
/**
 * tim tong so luong cay khung
 *
 * y tuong:
 *      - cay khung cua 1 do thi n dinh gom n - 1 canh
 *      - các bước làm:
 *          + từ m cạnh cho trước chọn ra n - 1 cạnh
 *          + với mỗi lựa chọn =>  kiểm tra chu trình có trong tập cạnh được chọn ra
 */
 
int r[MAX];    // rank of node
int p[MAX];    // parent of node
 
/**
 * Make x become root of new Set
 */
void makeSet(int x) {
	r[x] = 0;   // rank of root = 0
	p[x] = x;   // parent of root is root
}
 
/**
 * Find root of Set have node u
 * @param u : index of node u
 */
int findSet(int x) {
	if (p[x] != x)
	{
		return findSet(p[x]);
	}
	else
	{
		return x;
	}
}
 
/**
 * link 2 Set have node u and Set have node v
 * @param u : index of node u
 * @param v : index of node v
 */
void link(int u, int v) {
	int a = findSet(u);
	int b = findSet(v);
 
	if (r[a] > r[b])
	{
		p[b] = a;
	}
	else
	{
		p[a] = b;
		if (r[a] == r[b])
		{
			r[b]++;
		}
	}
}
 
/*
	
*/
bool check_edge(int x[]) {
	init();
	for (int i = 1; i <= N - 1; i++)
	{
		edge temp = V[x[i]];
		if (findSet(temp.u) == findSet(temp.v))
		{
			return false;
		}
		else {
			link(temp.u, temp.v);
		}
	}
	return true;
}
 
/**
 * input from console
 */
void input() {
	int n;
	cin >> n;

	N = 2 * n;
	M = 1 + (n - 1) * 3;

	// cin >> N >> M;
	::V.push_back({1 , 2});
	for (int i = 2; i <= N; i++)
	{
		int u = 2 * i - 1;
		int v = 2 * i;
		::V.push_back({ u, v });
		::V.push_back({ u, u - 2 });
		::V.push_back({ v, v - 2 });
	}
}


 
int z = 0;
 
void print() {
	for (int i = 1; i <= N - 1; i++)
	{
		cout << x[i] << " ";
	}
	cout <<":" << z++ << endl;
}

void printv() {
	for (int i = 1; i <= M; i++)
	{
		cout << ::V.at(i).u << " " << ::V.at(i).v << endl;
	}
	
}
/*
	solution with n - 1 edges finded
*/
void solution() {
	//print();
	if (check_edge(x))
	{
		result++;
	}
}
 
 
/*
	check in backtracking
*/
bool check(int v, int k) {
	for (int i = 0; i < k; i++)
	{
		if (v == x[i])
		{
			return false;
		}
	}
	return true;
}
 
/**
 * backtracking get n - 1 edges in m edges
 */
void TRY(int k) {
	for (int v = x[k - 1] + 1; v <= M; v++)
	{
		x[k] = v;
		if (k == N - 1)
		{
			solution();
		}
		else
		{
			TRY(k + 1);
		}
	}
}
 
/*
*	init
*/
 
void init() {
	for (int i = 0; i < N; i++)
	{
		makeSet(i);
	}
}
 
/**
 * main function
 */
int main() {
	x[0] = 0;
	input();
	// printv();
	TRY(1);
	cout << result;
	return 0;
=======
#include <iostream>
#include <vector>
#define MAX 10000
 
using namespace std;
 
int N, M;
vector<int> G[MAX];
// result of solution
// int x[MAX];
 
struct edge
{
	int u, v;
};
 
vector<edge> V = { {-1, -1} };
int x[MAX];
int result = 0;
 
 
void init();
/**
 * tim tong so luong cay khung
 *
 * y tuong:
 *      - cay khung cua 1 do thi n dinh gom n - 1 canh
 *      - các bước làm:
 *          + từ m cạnh cho trước chọn ra n - 1 cạnh
 *          + với mỗi lựa chọn =>  kiểm tra chu trình có trong tập cạnh được chọn ra
 */
 
int r[MAX];    // rank of node
int p[MAX];    // parent of node
 
/**
 * Make x become root of new Set
 */
void makeSet(int x) {
	r[x] = 0;   // rank of root = 0
	p[x] = x;   // parent of root is root
}
 
/**
 * Find root of Set have node u
 * @param u : index of node u
 */
int findSet(int x) {
	if (p[x] != x)
	{
		return findSet(p[x]);
	}
	else
	{
		return x;
	}
}
 
/**
 * link 2 Set have node u and Set have node v
 * @param u : index of node u
 * @param v : index of node v
 */
void link(int u, int v) {
	int a = findSet(u);
	int b = findSet(v);
 
	if (r[a] > r[b])
	{
		p[b] = a;
	}
	else
	{
		p[a] = b;
		if (r[a] == r[b])
		{
			r[b]++;
		}
	}
}
 
/*
	
*/
bool check_edge(int x[]) {
	init();
	for (int i = 1; i <= N - 1; i++)
	{
		edge temp = V[x[i]];
		if (findSet(temp.u) == findSet(temp.v))
		{
			return false;
		}
		else {
			link(temp.u, temp.v);
		}
	}
	return true;
}
 
/**
 * input from console
 */
void input() {
	int n;
	cin >> n;

	N = 2 * n;
	M = 1 + (n - 1) * 3;

	// cin >> N >> M;
	::V.push_back({1 , 2});
	for (int i = 2; i <= N; i++)
	{
		int u = 2 * i - 1;
		int v = 2 * i;
		::V.push_back({ u, v });
		::V.push_back({ u, u - 2 });
		::V.push_back({ v, v - 2 });
	}
}


 
int z = 0;
 
void print() {
	for (int i = 1; i <= N - 1; i++)
	{
		cout << x[i] << " ";
	}
	cout <<":" << z++ << endl;
}

void printv() {
	for (int i = 1; i <= M; i++)
	{
		cout << ::V.at(i).u << " " << ::V.at(i).v << endl;
	}
	
}
/*
	solution with n - 1 edges finded
*/
void solution() {
	//print();
	if (check_edge(x))
	{
		result++;
	}
}
 
 
/*
	check in backtracking
*/
bool check(int v, int k) {
	for (int i = 0; i < k; i++)
	{
		if (v == x[i])
		{
			return false;
		}
	}
	return true;
}
 
/**
 * backtracking get n - 1 edges in m edges
 */
void TRY(int k) {
	for (int v = x[k - 1] + 1; v <= M; v++)
	{
		x[k] = v;
		if (k == N - 1)
		{
			solution();
		}
		else
		{
			TRY(k + 1);
		}
	}
}
 
/*
*	init
*/
 
void init() {
	for (int i = 0; i < N; i++)
	{
		makeSet(i);
	}
}
 
/**
 * main function
 */
int main() {
	x[0] = 0;
	input();
	// printv();
	TRY(1);
	cout << result;
	return 0;
>>>>>>> Stashed changes
}