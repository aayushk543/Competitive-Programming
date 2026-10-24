#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        int prev = arr[n-1];

        vector<vector<int>> vec;

        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] < prev) {
                prev = arr[i];
            }
            else {
                int prev1 = prev;
                int prev2 = prev;
                prev1 -= 1;

                prev1 = max(0, prev1);

                int curr1 = 0;
                int curr2 = 0;


                while(i >= 0 && arr[i] >= prev1) {

                    //cout << arr[i] << " ";
                    curr1 += (arr[i] - prev1);
                    curr2 += max(0, (arr[i] - prev2));
                    i--;
                }

                vec.push_back({curr1, curr2});
            }

            if(i >= 0) prev = arr[i];
        }
        

        sort(vec.begin(), vec.end());

        int ans = 0;

        bool flag = true;

        for(int i = vec.size() - 1; i >= 0; i--) {
            if(flag) {
                if(vec[i][0] > vec[i][1]) flag = false;

                ans += vec[i][0];
            }
            else ans += vec[i][1];
        }

        cout << ans << '\n';
    }
    return 0;
}