#include<bits/stdc++.h>
using namespace std;

vector<pair<bool, int>> seg;

bool update(int idx, int l, int r, int pos){

    if(l == r) {
        seg[idx].second = 1;

        if(seg[idx].first && seg[idx].second > (r - l + 1) / 2) return true;
        return false;
    }

    int mid = (l + r) >> 1;

    bool check = false;

    if(pos <= mid) check = update(2*idx, l, mid, pos);
    else check = update(2*idx + 1, mid + 1, r, pos);

    seg[idx].second = seg[2*idx].second + seg[2*idx + 1].second;

    cout << pos << " " << r - l + 1 << " " << seg[idx].second << '\n';
    cout << seg[idx].first << '\n';

    if(seg[idx].first && seg[idx].second > (r - l + 1) / 2) return true;

    return check;
}

void build(int idx, int l, int r, set<pair<int, int>>& s) {

    int mid = (l + r) >> 1;

    if(l == 1 && r == 3) cout << "flag" << '\n';

    if(s.find({l, r}) != s.end()) {
        //cout << "hi" << '\n';

        seg[idx].first = true;
        seg[idx].second = 0;
    }
    else seg[idx].first = false;

    if(l == r) return;

    build(2*idx, l, mid, s);
    build(2*idx + 1, mid + 1, r, s);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    //cout << "flag" << '\n';

    int t;
    cin >> t;
    while(t--) {
       int n,m;
       cin >> n >> m;

       //cout << "flag" << '\n';

       vector<vector<int>> interval;

       for(int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;

        interval.push_back({u, v});
       }

       int q;
       cin >> q;

       vector<int> vec(q);

       for(int i = 0; i < q; i++) cin >> vec[i];

       int l = 0, r = q;
       bool flag2 = false;

       while(l < r) {
        int mid = (l + r) >> 1;

        vector<int> pre(n + 1);

        for(int i = 0; i <= mid; i++) pre[vec[i]] = 1;

        for(int i = 1; i <= n; i++) pre[i] += pre[i-1];

        bool flag = false;

        for(int i = 0; i < m; i++) {

            int sum = (pre[interval[i][1]] - pre[interval[i][0]]);

            if((interval[i][0] == 0 && pre[interval[i][0]] == 1) || (pre[interval[i][0]] == 1 + pre[interval[i][0] - 1])) sum += 1;

            int l = interval[i][1] - interval[i][0] + 1;

            if(sum > (l >> 1)) {
                flag = true;
                flag2 = true;
                break;
            }
        }

        if(flag == false) l = mid + 1;
        else r = mid; 
       }

       if(flag2 == false) cout << -1 << '\n';
       else cout << l + 1 << '\n';
    }
    return 0;
}