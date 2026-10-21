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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       vector<long long> pos(n);
       vector<long long> time(n);

       double l = 1000, r = 0;

       for(int i = 0; i < n; i++) {
        cin >> pos[i];
        l = min(l, (double)pos[i]);
        r = max(r, (double)pos[i]);
       }

       l = 0, r = LLONG_MAX;

       for(int i = 0; i < n; i++) cin >> time[i];

       double ans = 0;

       int i = 0;

       while(l <= r) {
        i++;
        double mid = (l + r) / 2.00;

        double curr_st = pos[0] - max(0.00, mid - time[0]);
        double curr_end = pos[0] + max(0.00, mid - time[0]);

        bool flag = true;

        // cout << mid << '\n';
        // cout << curr_st << " " << curr_end << '\n';

        for(int i = 1; i < n; i++) {
            double now_st = pos[i] - (mid - time[i]);
            double now_end = pos[i] + (mid - time[i]);

            if(now_st > now_end || curr_st > curr_end) flag = false;

            if(flag == false) break;

            curr_st = max(curr_st, now_st);
            curr_end = min(curr_end, now_end);
        }

        if(curr_st > curr_end) flag = false;

        //cout << curr_st << " " << curr_end << '\n';

        if(flag) {
            ans = (curr_st + curr_end) / 2.00;
            r = mid;
        }
        else {
            l = mid;
        }

        if(i > 60) break;
 

       }

       cout << fixed << setprecision(10) << ans << '\n';

    }
    return 0;
}