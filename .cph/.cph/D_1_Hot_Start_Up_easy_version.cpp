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

        vector<long long> in(n);

        for(int i = 0; i < n; i++) cin >> in[i];

        vector<long long> cold(k + 1);
        vector<long long> hot(k + 1);

        for(int i = 1; i <= k; i++) cin >> cold[i];

        for(int i = 1; i <= k; i++) cin >> hot[i];

        long long ans = 0;

        for(int i = 1; i < n; i++) {

            if(in[i - 1] == in[i]) continue;
            else ans += in[i];
        }

        if(n == 1 || in[1] != in[0]) ans += in[0];

        
    }
    return 0;
}