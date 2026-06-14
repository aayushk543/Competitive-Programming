#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,p;

        cin >> n >> p;

        vector<int> key(2*n,0);
        for(int i = 0; i < 2*n; i++){
            cin >> key[i];
        }
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++){
        v.push_back({key[i], key[i+n]});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second < b.second;
        });

        long long ans = 0;
        ans = p;
        int count = 1;
        int i = 0;

        while(count < n){
            if(p <= v[i].second){
                ans += (long long)p*(n - count);
                break;
            }
            else{
                ans += (long long)(v[i].second)*(min(v[i].first, n - count));
                count += v[i].first;
            }
            i++;
        }

        cout << ans << '\n';
    }
    return 0;
}