#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    // vector<int> a;
    vector<int> sumVec;
    int result = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int ele;
        cin >> ele;
        sum = sum + ele;
        sumVec.push_back(sum % K);
    }
    for (int i = 0; i < sumVec.size(); i++)
    {
        if (sumVec[i] % K == 0)
        {
            result++;
        }
        for (int j = i + 1; j < sumVec.size(); j++)
        {
            if (sumVec[i] == sumVec[j])
            {
                result++;
            }
        }
    }
    cout << result << endl;
}