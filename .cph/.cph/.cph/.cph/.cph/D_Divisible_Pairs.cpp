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

        long long x,y;
        cin >> x >> y;

        map <pair<long long, long long>, int> mp;
        long long count = 0;

        for(int i = 0; i < n; i++) {
            long long m;
            cin >> m;
            
            count += mp[{(x - (m % x)) % x, m % y}];

            mp[{m % x, m % y}]++;
        }

        cout << count << '\n';
    }
    return 0;
}   