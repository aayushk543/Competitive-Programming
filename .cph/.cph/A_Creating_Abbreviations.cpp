#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>

int f(char c) {
    return c - 'A';
}

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m;
       cin >> n >> m;

       vector<int> v(26, 0);

       for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s[0] >= 'a') v[s[0] - 'a']++;
        else v[f(s[0])]++;
       }

       bool flag = true;

       for(int i = 0; i < m; i++) {
        string curr;
        cin >> curr;

        for(int j = 0; j < curr.length(); j++) {
            int curr_num = 0;

            if(curr[j] >= 'a') curr_num = curr[j] - 'a';
            else curr_num = f(curr[j]);

            if(v[curr_num] == 0) {
                flag = false;
                break;
            } 
        }

       }

       if(flag) cout << "YES" << '\n';
       else cout << "NO" << '\n';
    }
    return 0;
}