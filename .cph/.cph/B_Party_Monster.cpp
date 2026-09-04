#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
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

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') count++;
            else count--;
        }

        //cout << count << " ";

        if(count == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}