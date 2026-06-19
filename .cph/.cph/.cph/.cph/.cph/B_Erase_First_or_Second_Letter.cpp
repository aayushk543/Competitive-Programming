#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        set<char> st;
        long long ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            st.insert(s[i]);
            ans += st.size();
        }

        cout << ans << '\n';
    }

    return 0;
}