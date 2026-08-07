#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        
        //arr[i] -= (i + 1);
    }

    map<int, vector<int>> mp;

    for(int i = 0; i < n; i++) {
        mp[arr[i] - i].push_back(i);
    }

    long long ans = 0;

    for(auto it = mp.begin(); it != mp.end(); it++) {

        vector<int> curr = it->second;
        long long sum = 0;

        for(int i = 0; i < curr.size(); i++) {
            sum += arr[curr[i]];
        }

        ans = max(ans, sum);
    }

    

    cout << ans << '\n';
}   