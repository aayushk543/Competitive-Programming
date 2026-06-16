#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        static char buf[100005];
        scanf("%s", buf);

        bool seen[26] = {false};
        long long cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int c = buf[i] - 'a';
            if (!seen[c]) { seen[c] = true; cnt++; }
            ans += cnt;
        }
        printf("%lld\n", ans);
    }
}