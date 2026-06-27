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

            mp[(m - (num % m)) % m]++;
        }

        cout << mp.size() << '\n';


    }
    return 0;
}