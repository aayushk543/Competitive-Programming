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

        vector<long long> arr(n);

        bool zero = false;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            if(arr[i] == 0) zero = true;
        }

        if(zero) {
            cout << n << '\n';
            continue;
        }

        long long mini = LLONG_MAX;
        long long maxi = LLONG_MIN;

        bool flag = false;
        int length = 0;

        for(int i = 0; i < n; i++) {

            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);

            length++;

            if(mini < length) {
                flag = true;
                break;
            }
        }

        if(flag) cout << n << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}