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
        int n,q;
        cin >> n >> q;

        vector<long long> arr(n);
        vector<int> q_arr(q);

        for(int i = 0; i < n; i++) cin >> arr[i];
        for(int i = 0; i < q; i++) cin >> q_arr[i];

        int mini = 31;

        for(int i = 0; i < q; i++) {
            if(q_arr[i] >= mini) continue;
            long long val = pow(2, q_arr[i]);

            for(int j = 0; j < n; j++) {
                if(arr[j] % val == 0) arr[j] += val / 2;
            }

            mini = min(mini, q_arr[i]);
        }

        for(int i = 0; i < n; i++) cout << arr[i] << " ";

        cout << '\n';
    }
    return 0;
}