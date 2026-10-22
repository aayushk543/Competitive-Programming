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

int cal(vector<int>& pos, vector<int>& time, double mid) {

    double ans = 0.0;

    for(int i = 0; i < pos.size(); i++) {
        ans = max(ans, time[i] + abs(mid - pos[i]));
    }

    return ans;
}

vector<int> vis(1001, -1);
vector<int> vis2(1001, -1);

//vector<vector<int>> dp;


// int f2(vector<int>& b, vector<int>& c, int index, int k, map<pair<int, int>, int>& mp) {
//     int n = b.size();

//     if(index == n) return 0;

//     //if(mp.find({index, k}) != mp.end()) return mp[{index, k}];

//     if(dp[index][k] != -1) return dp[index][k];

//     int take = 0;
    
//     if(k >= b[index]) take = c[index] + f2(b, c, index + 1, k - b[index], mp);

//     int skip = f2(b, c, index + 1, k, mp);

//     return dp[index][k]  = max(take, skip);
// }

void f(vector<int>& vec, int cycle) {

    vector<int> n_vec;

    for(int i = 0; i < vec.size(); i++) {

        int curr = vec[i];

        for(int i = 1; i <= curr; i++) {

            if(curr + (curr / i) <= 1000 && vis[curr + (curr / i)] == -1 && vis2[curr + (curr / i)] == -1) {

                vis2[curr + (curr / i)] = 1;
                vis[curr + (curr / i)] = cycle;
                n_vec.push_back(curr + (curr / i));
            }
        }
    }

    if(n_vec.size() == 0) return;

    f(n_vec, cycle + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    vector<int> start(1);
    start[0] = 1;
    vis[1] = 0;

    f(start, 1);


    int t;
    cin >> t;
    while(t--) {
       int n,k;
       cin >> n >> k;

       //dp.assign(n + 1, vector<int>(k + 1, -1));

       vector<int> b(n);
       vector<int> c(n);

       vector<pair<int, int>> vp;

       for(int i = 0; i < n; i++) {
        cin >> b[i];

        b[i] = vis[b[i]];

        //cout << b[i] << " ";
       }
       for(int i = 0; i < n; i++) {
        cin >> c[i];

        vp.push_back({b[i], c[i]});
       }

       sort(vp.begin(), vp.end());

       for(int i = 0; i < n; i++) {

        b[i] = vp[i].first;
        c[i] = vp[i].second;
       }

       int sum = 0;

       for(int i = 0; i < n; i++) sum += b[i];

       k = min(k, sum);

       //map<pair<int, int>, int> mp;

       //int ans = f2(b, c, 0, k, mp);

       int ans = 0;

       vector<int> dp(k + 1, 0);

       for(int i = 0; i < n; i++) {
        for(int j = k; j >= b[i]; j--) {

            dp[j] = max(dp[j], c[i] + dp[j - b[i]]);
        }
       }

       cout << dp[k] << '\n';
    }
    return 0;
}