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
        vector<int> div;

        for(int i = 0; i < n; i++) cin >> arr[i];

        for(int i = 1; i * i <= n; i++) {
            if(n % i == 0) {
                div.push_back(i);
                div.push_back(n / i);
            }
        }

        sort(arr.begin(), arr.end());
        set<int> s;

        for(int i = 2; i <= arr[n - 1]; i++) {

            map<int, int> mp;

            for(int j = 0; j < n; j++) mp[arr[j] % i] += 1; 

            int rem = (mp.begin())->second;

            // cout << mp.size() << '\n';

            for(auto it = mp.begin(); it != mp.end(); it++) {
                rem = gcd(rem, it->second);
            }

            //cout << rem << " ";

            if(mp.size() == 1) s.insert(1);
            else if(rem != 1) {
                //cout << "sybau" << '\n';
                s.insert(rem);
            }
        }

        //for(auto it = s.begin(); it != s.end(); it++) cout << *it << " ";


        cout << s.size() << '\n';


    }
    return 0;
}