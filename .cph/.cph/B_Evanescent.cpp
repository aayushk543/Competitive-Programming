#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>

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

       int count = 0;

       bool flag1 = false;
       bool flag2 = false;

       for(int i = 0; i < n; i++) {
        count++;

        char c = s[i];
        int index = i;
        while(i < n - 1 && c == s[i+1]) i++;

        if(index == i && index != 0 && index != n - 1) {
            flag1 = true;
            if(s[index - 1] == s[index + 1]) flag2 = true;
        }
       }

       if(flag1) count -= 1;
       if(flag2) count -= 1;

       cout << count << '\n';
    }
    return 0;
}