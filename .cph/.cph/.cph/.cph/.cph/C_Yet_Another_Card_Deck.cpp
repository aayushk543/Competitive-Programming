#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int n,q;
        cin >> n >> q;

        map<int, pair<int, int>> mp;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            if(mp.find(num) == mp.end()) {
                mp[num] = {i+1, 1};
            }
        }



        for(int i = 1; i <= q; i++){
            int curr;
            cin >> curr;

            auto [index, timestamp] = mp[curr];

            cout << index + (i - timestamp) << " ";
            mp[curr] = {0, i};
        }

        cout << '\n';
    
    return 0;
}