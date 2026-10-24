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

        vector<int> arr(26, 0);
        map<int, int> mp;
        int empty = 0;

        for(int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
            if(arr[s[i] - 'a'] == 1) empty++;
        }

        for(int i = 0; i < 26; i++) mp[arr[i]] += 1; 

        empty = 26 - empty;

        vector<int> divisor;

        for(int i = 1; i*i <= n; i++) {

            if(n % i == 0) divisor.push_back(i);
        }

        divisor.push_back(n);

        int ans = INT_MAX;
        string ans_s;

        for(int i = 0; i < divisor.size(); i++) {
            if(divisor[i] == 1 && n <= 26) {
                if(n - mp[1] <= empty) {
                    ans = n - mp[1];

                }
            }
            else {

                if(n - divisor[i]*mp[i] < ans) {
                    ans = n - divisor[i]*mp[i];

                }
            }
        }

        cout << ans << '\n';

    }
    return 0;
}