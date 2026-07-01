#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;

        cin >> n >> m;

        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;

            mp[num % m]++;
        }

        int count = 0;

        if(mp[0] != 0) count += 1;
        //cout << count << '\n';

        for(int i = 1; i <= m/2; i++) {
            if(i == m-i) {
                if(mp[i] != 0) count += 1;
                //cout << count << '\n';
                continue;
            }
            if(mp[i] == 0 && mp[m-i] == 0) continue;
            if(mp[i] == 0) {
                count += mp[m-i];
            }
            else if(mp[m-i] == 0) {
                count += mp[i];
            }
            else {
                int value = abs(mp[m-i] - mp[i]);

                if(value == 0) count += 1;
                else count += 1 + max(0, abs(value - 1));

                //cout << count << '\n';
            }
        }

        cout << count << '\n';
    }
    return 0;
}