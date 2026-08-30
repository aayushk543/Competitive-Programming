#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m;

       cin >> n >> m;

       vector<int> arr(n);
       map<int,int> mp;

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;

        if(arr[i] % 2 == 0) {
            mp[arr[i] / 2] += 0;
        }
       }


       int maxi = 0;
       int count = n;

       for(auto it = mp.begin(); it != mp.end(); it++) {
        int curr = it->first;
        maxi = max(maxi, count + mp[curr * 2]); 
        count -= it->second;       
       }

       cout << maxi << '\n';




    }
    return 0;
}