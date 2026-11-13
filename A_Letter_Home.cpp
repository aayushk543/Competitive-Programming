#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,s;
        cin >> n >> s;

        int st, end;

        for(int i = 1; i <= n; i++) {
            if(i == 1) {
                cin >> st;
                end = st;
            }
            else cin >> end;
        }

        if(s <= st) cout << end - s << '\n';
        else if(end <= s) cout << s - st << '\n';
        else cout << 2*min(s - st, end - s) + max(s - st, end - s) << '\n';
    }
    return 0;
}