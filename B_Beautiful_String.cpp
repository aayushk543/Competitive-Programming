#include <iostream>
#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <string>
using namespace std;
using namespace std;

bool isNonDecreasing(const string &s) {
    for (int i = 1; i < (int)s.size(); i++)
        if (s[i] < s[i - 1]) return false;
    return true;
}

bool isPalindrome(const string &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        bool found = false;

        for (int mask = 0; mask < (1 << n); mask++) {
            string p = "", x = "";
            vector<int> idx;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    p += s[i];
                    idx.push_back(i + 1);
                } else {
                    x += s[i];
                }
            }

            if (isNonDecreasing(p) && isPalindrome(x)) {
                cout << (int)idx.size() << "\n";
                for (int i = 0; i < (int)idx.size(); i++)
                    cout << idx[i] << (i + 1 == (int)idx.size() ? "\n" : " ");
                found = true;
                break;
            }
        }

        if (!found) cout << -1 << "\n";
    }

    return 0;
}
