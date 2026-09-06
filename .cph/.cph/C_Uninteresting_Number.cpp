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
        string n;
        cin >> n;

        //cout << n << '\n';

        int count_2 = 0, count_9 = 0;
        map<int, int> mp;

        int n2 = 0;

        for(int i = 0; i < n.length(); i++) {
            int curr = n[i] - '0';
            n2 += curr;

            if(curr == 2) count_2++;
            else if(curr == 3) count_9++;

            mp[(count_9 * 6) % 9] += 1;
        }

        mp[0] += 1;
        mp[9] += 1;

        // for(auto it = mp.begin(); it != mp.end(); it++) {
        //     cout << it->first << " " << it->second << '\n';
        // }

        int rem = (n2 % 9);

        if(rem == 0) cout << "YES" << '\n';
        else {

            bool flag = true;

            for(int i = 0; i <= count_2; i++) {
                
                if(mp.find(9 - ((n2 + 2*i) % 9)) != mp.end()) {
                    flag = false;
                    cout << "YES" << '\n';
                    break;
                }
            }

            if(flag) cout << "NO" << '\n';

        }
    }
    return 0;
}