#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int mini_before_n = n;
        int mini_after_n = n;

        bool flag = true;

        vector<int> arr(n);
        vector<vector<int>> vp;

        for(int i = 0; i < n; i++) cin >> arr[i];

        int i = 0;

        while(i < n - 1) {
            bool flag = (arr[i] > arr[i + 1]);

            int curr = arr[i];
            while(i < n - 1 && arr[i] < arr[i + 1]) {
                i++;
            }
            if(flag == false) vp.push_back({curr, arr[i]});

            while(i < n - 1 && arr[i] > arr[i + 1] && flag) {
                i++;
            }
            if(flag == true) vp.push_back({curr, arr[i]});

        }

        cout << vp.size() + 1 << '\n';

        for(int i = 0; i < vp.size(); i++) cout << vp[i][0] << " ";

        cout << vp[vp.size() - 1][1] << '\n';

    }
    return 0;
}