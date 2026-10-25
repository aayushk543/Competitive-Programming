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

        for(int i = 0; i < 26; i++) if(arr[i] > 0) mp[arr[i]]++; 

        empty = 26 - empty;

        vector<int> divisor;

        for(int i = 2; i*i <= n; i++) {

            if(n % i == 0 && (mp[i] != 0 || mp[n / i] != 0)) {
                if(mp[i] != 0) divisor.push_back(i);
                if(mp[n / i] != 0) divisor.push_back(n / i);

                //cout << i << " " << n / i << '\n';
            }
        }

        divisor.push_back(n);

        int ans = INT_MAX;
        //if()
        if(n <= 26) ans = n - (26 - empty);
        string ans_s = s;
        int sol = 1;

        for(int i = 0; i < divisor.size(); i++) {
            int curr = divisor[i];
            int curr_score = 0, curr_score2 = 0;
            vector<int> rem;

            //cout << curr << '\n';

            for(auto it = mp.begin(); it != mp.end(); it++) {

                int now = (it->first * it->second) % curr;
                curr_score += now;

                if(now != 0) rem.push_back(now);
            }

            //cout << curr_score2 << " " << curr_score << '\n';

            sort(rem.begin(), rem.end());

            int l = 0, r = rem.size() - 1;

            while(l < r) {

                int sum = rem[l] + rem[r];

                if(sum >= curr) 
            }

            if(curr_score < ans) {
                ans = curr_score;
                sol = curr;
            }
        }

        cout << ans << '\n';

    }
    return 0;
}