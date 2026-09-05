#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,k;

        cin >> n >> k;

        string s;
        cin >> s;
        int count = 0;

        for(int i = 0; i < n; i += k) {

            int mini = 1;

            for(int j = i; j < i + k; j++) {
                if(s[j] == '0') mini = 0;
            }

            if(mini == 1) count++;
        }

        cout << count << '\n';
    }
    return 0;
}