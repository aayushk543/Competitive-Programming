#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        string s;
        cin >> s;

        int cost = 0;
        map<int, int> mp;

        int curr = 0;

        mp.insert(0, -1);

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '(') curr++;
            else curr--;

            if(mp.find(curr) != mp.end()) cost = max(cost, i - mp[curr]);
            else mp.insert(curr, i);
        }

        
    }
    
    return 0;
}