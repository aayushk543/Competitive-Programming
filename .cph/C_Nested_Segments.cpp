#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //int t;
    //cin >> t;
    //cout << "yes" << '\n';
    if(1) {
       int n;
       cin >> n;

       //cout << "yes" << '\n';

       vector<vector<long long>> vec(n, vector<long long>(3));
       map<vector<long long>, int> mp;
       //priority_queue<tuple<long long, int, int>> pq;

       bool flag = false;

       for(int i = 1; i <= n; i++) {
        cin >> vec[i - 1][0] >> vec[i - 1][2];
        vec[i - 1][1] = vec[i - 1][2] - vec[i - 1][0] + 1;

        if(mp.find(vec[i - 1]) != mp.end() && flag == false) {
            flag = true;
            cout << i << " " << mp[vec[i - 1]] << '\n';
        }
        else mp[vec[i - 1]] = i;
       }

       //cout << "yes" << '\n';
       if(flag) return 0;

       //vector<vector<long long>> vec2 = vec;

       sort(vec.begin(), vec.end());

       //sort(vec2.begin(), vec2.end(), greater<long long>());

       for(int i = 0; i < n; i++) {
        vector<long long> curr = vec[i];
        int small_st = vec[i][0];
        int small_len = vec[i][1];
        int small_end = vec[i][2];

        int j = i;

        while(i < n && small_st == vec[i][0]) {
            if(i != j && vec[i][2] >= small_end) {
                flag = true;
                cout << mp[curr] << " " << mp[vec[i]] << '\n';
                return 0;
            }
            i++;
        }

        
        if(i == n) break;

        if(vec[i][2] <= small_end && flag == false) {
            flag = true;
            cout << mp[vec[i]] << " " << mp[curr] << '\n';
            return 0;
        }
        else i--;

        if(i == n - 1) break;
       }

       //cout << flag << '\n';

       if(flag == false) {
        cout << -1 << " " << -1 << '\n';
       }

    }
    return 0;
}