#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // vector<pair<int, int>> plant;
    // plant.push_back({1, 4});
    // plant.push_back({0, 8});
    // sort(plant.begin(), plant.end());
    // for (pair<int, int> a : plant)
    // {
    //     cout << a.first << a.second << endl;
    // }
    int d, n;
    vector<pair<int, int>> a;
    vector<array<int, 3>> b;
    cin >> d >> n;
    vector<pair<int, int>> plant;
    vector<int> sumVec;
    for (int i = 0; i < n; i++)
    {
        int xAxis, yAxis, ratAmount;
        cin >> xAxis >> yAxis >> ratAmount;
        b.push_back({xAxis, yAxis, ratAmount});
    }

    for (int i = 0; i < b.size(); i++)
    {
        plant.push_back({max(b[i][0] - d, 1), min(b[i][1] + d, 100)});
        plant.push_back({max(b[i][0] - d, 1), max(b[i][1] - d, 1)});
        plant.push_back({min(b[i][0] + d, 100), min(b[i][1] + d, 100)});
        plant.push_back({min(b[i][0] + d, 100), max(b[i][1] - d, 1)});
    }
    std::sort(plant.begin(), plant.end());
    for (int i = 0; i < plant.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < b.size(); j++)
        {
            if (max(abs(plant[i].first - b[j][0]), abs(plant[i].second - b[j][1])) <= d)
            {
                sum += b[j][2];
            }
        }
        sumVec.push_back(sum);
    }
    for (int index = 0; index < sumVec.size(); index++)
    {
        bool isLargest = true;
        for (int k = index + 1; k < sumVec.size(); k++)
        {
            if (sumVec[index] < sumVec[k])
            {
                isLargest = false;
                break;
            }
        }
        if (isLargest)
        {
            cout << plant[index].first << endl;
            cout << plant[index].second << endl;
            cout << sumVec[index] << endl;
            // cout << plant[index].first << plant[index].second << sumVec[index] << endl;
            break;
        }
    }
}
