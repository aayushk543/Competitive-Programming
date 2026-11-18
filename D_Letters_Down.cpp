#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> freq(26, 0);

        for(int i = 0; i < n/2; i++) {
            int j = n - i - 1;

            if(s[i] != s[j]) {
                int curr1 = min(s[i] - 'a', s[j] - 'a');
                int curr2 = max(s[i] - 'a', s[j] - 'a');

                for(int index = curr1; index < curr2; index++) {
                    freq[index]++;
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < 26; i++) {
            int maxi = -1, mini = -1;

            if(freq[i] == 0) continue;

            int j = i;

            while(i < 26 && freq[i] > 0) {
                maxi = i;
                if(mini == -1) mini = i;

                i++;
            }

            ans += (maxi - mini + 1);
        }

        cout << ans << '\n';
    }
    return 0;
}