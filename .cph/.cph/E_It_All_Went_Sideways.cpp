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

        int ans = 0;

        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] < prev) {

            }
            else {
                prev -= 1;
                prev = max(0, prev);

                int curr = 0;

                //cout << i << '\n';

                while(arr[i] >= prev) {

                    //cout << arr[i] << " ";
                    curr += (arr[i] - prev);
                    i--;
                }

                ans = max(ans, curr);
            }

            prev = arr[i];
        }

        cout << ans << '\n';
    }
    return 0;
}