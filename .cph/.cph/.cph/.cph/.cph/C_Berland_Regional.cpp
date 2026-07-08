#include <iostream>
#include <vector>
#include <climits>
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

        unordered_map <int, vector<long long>> mp;

        vector<int> a1(n);
        vector<long long> a2(n);

        for(int i = 0; i < n; i++) {
            cin >> a1[i];
        }

        for(int i = 0; i < n; i++) cin >> a2[i];

        for(int i = 0; i < n; i++) {
            mp[a1[i]].push_back(a2[i]);
        }

        vector<long long> ans(n + 1, 0);

        for(auto it = mp.begin(); it != mp.end(); it++) {
            auto &t1 = it->second;

            sort(t1.begin(), t1.end());

            long long pref = t1[0];


            for(int i = 1; i < t1.size(); i++) {
                t1[i] += pref;
                pref = t1[i];
            }

            int size = t1.size();

            for(int i = 1; i <= size; i++) {
                
                int curr = (size % i);

                ans[i] += t1[size-1];

                if(curr != 0) ans[i] -= t1[curr - 1];
            }

        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";

        cout << '\n';

        
    }
    return 0;
}   