#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int n;
    cin >> n;
    int a[n], max_doi = 0, max_lung = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int old_state = -1;
    int new_state = -1;

    int pick[n][2] = {}, index_pick = 0;
    pick[0][0] = 0;
    pick[0][1] = 2;
    for(int i = 1; i < n; i++) {
        old_state = new_state;
        if(a[i - 1] < a[i]) {
            new_state = 0;
        } else if(a[i - 1] > a[i]) {
            new_state = 1;
        } else {
            new_state = 2;
        }

        if(new_state == 1 && old_state == 0) {
            pick[++index_pick][0] = i - 1;
            pick[index_pick][1] = 0;
        } else if(new_state == 0 && old_state == 1) {
            pick[++index_pick][0] = i - 1;
            pick[index_pick][1] = 1;
        } else if(new_state == 2) {
        	pick[++index_pick][0] = i - 1;
            pick[index_pick][1] = 2;
        }
        if(i == n - 1) {
        	pick[++index_pick][0] = i;
            pick[index_pick][1] = 2;
        } 
        if(pick[index_pick - 1][1] != pick[index_pick][1]) {
            int s = pick[index_pick - 2][0];
            int j = pick[index_pick - 1][0];
            int k = pick[index_pick][0];

            int h = min(j - s, k - j);
        
            if(pick[index_pick - 1][1] == 0) {
                max_doi = max(max_doi, h);
            } else if(pick[index_pick - 1][1] == 1) {
                max_lung = max(max_lung, h);
            }
            
        }
    }

    cout << max_doi << " " << max_lung;
	return 0;
}