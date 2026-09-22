#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <set>
#include <map>
#include <stack>
#include <bitset>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;

        vector<bitset<32>> vec;
        vector<int> modify(q);

        for(int i = 0; i < n; i++) {
            long long num;
            cin >> num;

            vec.push_back(bitset<32>(num));
        }
        bitset<32> b;
        long long 

        for(int i = 0; i < q; i++) {
            int curr;
            cin >> curr;


        }


    }
    return 0;
}