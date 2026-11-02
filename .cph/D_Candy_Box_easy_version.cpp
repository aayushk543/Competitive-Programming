#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    //cout << "yes" << '\n';
    while(q--) {
       int n;
       cin >> n;

       vector<int> arr(n);

       map<int, int> mp;

       for(int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
       }

       map<int, int> mp2;

       for(auto it = mp.begin(); it != mp.end(); it++) {
        mp2[it->second]++;
       }

       long long ans = 0;

       long long curr = 0;
       long long count = 0;

       for(auto it = mp2.begin(); it != mp2.end(); it++) {
        long long num = it->first;
        long long occur = min(num, (long long)it->second);

        long long second = num - occur;

        long long sum = ((second)*(second + 1)) >> 1;
        long long sum2 = ((num)*(num + 1)) >> 1;

        ans += sum2 - sum;

        curr = num;
        count = occur;
       }

       cout << ans << '\n';

    }
    return 0;
}