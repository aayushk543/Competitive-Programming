#include<bits/stdc++.h>
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

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            int curr = 0;

            for(int j = 30; j >= 0; j--) {

                if(arr[i] & (1 << j)) {
                    curr = j;
                    break;
                }
            }

            arr[i] = curr;

            //cout << curr << " ";
        }

        vector<int> arr2(31, 0);

        for(int i = 0; i < n; i++) arr2[arr[i]] += 1;

        long long total = 0;

        for(int i = 0; i < 31; i++) {

            total += (1LL * arr2[i] * (arr2[i] - 1)) / 2;
        }

        cout << total << '\n';

    }
    return 0;
}