#include<bits/stdc++.h>
using namespace std;

bool check(vector<pair<long long, long long>>& vp, long long limit) {
    int l = vp.size();

    long long curr = 0;

    for(int i = 0; i < l; i++) {
        if(limit > vp[i].first - curr) return false;
        else curr = min(curr + limit, vp[i].second);

    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        
        map<int,int> mp;

        for(int i = 0; i < n; i++) {
            int m;
            cin >> m;

            mp[m]++;
        }

        long long sum = 0;
        int maxi = 0;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            sum += it->first;

            if(it->second > 1) maxi = it->first;
        }

        cout << sum + maxi << '\n';


    }
    return 0;
}   