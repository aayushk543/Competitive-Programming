#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;

        vector<int> arr(n);
        map<int, int> mp_st;
        map<int,int> mp_end;

        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            if(mp_st.find(arr[i]) == mp_st.end()) {
                mp_st[arr[i]] = i;
                mp_end[arr[i]] = i;
            }
            else mp_end[arr[i]] = i;
        }

        for(int i = 1; i <= k; i++) {
            int p,q;
            cin >> p >> q;

            int st_p = -1, end_p = -1, st_q = -1, end_q = -1;

            if(mp_st.find(p) != mp_st.end()) {
                st_p = mp_st[p];
                end_p = mp_end[p];
            }
            else {
                cout << "NO" << '\n';
                continue;
            }

            if(mp_st.find(q) != mp_st.end()) {
                st_q = mp_st[q];
                end_q = mp_end[q];
            }
            else {
                cout << "NO" << '\n'; 
                continue;
            }

            if(st_p <= end_q) cout << "YES" << '\n';
            else cout << "NO" << '\n';

        }
    }
    
    return 0;
}