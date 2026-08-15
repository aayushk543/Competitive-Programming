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

       string s;
       cin >> s;

       unordered_map<char, int> mp;

       for(int i = 0; i < n; i++) {
        mp[s[i]]++;
       }

       int size = mp.size();

       vector<int> arr;
       int sum = 0;

       for(auto it = mp.begin(); it != mp.end(); it++) {
        arr.push_back(it->second);
        sum += it->second;
       }

       sort(arr.begin(), arr.end());

       int sz = arr.size();
       int prev = 0;
       int ans = INT_MAX;

       for(int i = 0; i < sz; i++) {
        sum -= arr[i];

        ans = min(ans, (i) * arr[i] - prev + sum - (sz - i - 1) * arr[i]);

        prev += arr[i];
       }

       cout << ans << '\n';


    }
    return 0;
}