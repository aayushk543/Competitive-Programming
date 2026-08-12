#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       long long n,x;
       int m;
       cin >> n >> x >> m;

       bool c = false;
       int curr_st = -1, curr_end = -1;

       for(int i = 0; i < m; i++) {
        int u,v;
        cin >> u >> v;

        if(!c && u <= x && x <= v) {
            c = true;
            curr_st = u;
            curr_end = v;
        }
        else if(u <= curr_st && curr_st <= v) {
            curr_st = min(u, curr_st);
            curr_end = max(v, curr_end);
        }
        else if(u <= curr_end && curr_end <= v) {
            curr_st = min(u, curr_st);
            curr_end = max(v, curr_end);
        }

       }

       cout << curr_end - curr_st + 1 << '\n';
    }
    return 0;
}   