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

       vector<pair<long long, int>> v;

       for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        v.push_back({x,i});
       }

       vector<int> ans(n);

       vector<pair<long long, int>> v2 = v;
       sort(v2.begin(), v2.end());

       long long prefix_sum = 0;

       for(int i = 0; i < n; i++){
            prefix_sum += v2[i].first;

            int k = i;
            long long prefix_sum2 = 0;

            if(k < n-1 && v2[k].first == v2[k+1].first) prefix_sum2 = prefix_sum;

            while(k < n-1 && v2[k].first == v2[k+1].first) {
                prefix_sum2 += v2[k+1].first;
                k++;
            }

            auto it = upper_bound(v2.begin(), v2.end(), make_pair(max(prefix_sum,prefix_sum2), INT_MAX));

            prefix_sum2 = 0;

            int index = (it - v2.begin()) - 1;

            ans[v2[i].second] = index; 
       }

       for(int i = 0; i < n; i++) cout << ans[i] << " ";
       cout << '\n';

       
    }
    return 0;
}