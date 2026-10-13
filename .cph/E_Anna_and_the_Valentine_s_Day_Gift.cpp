#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n,m;
       cin >> n >> m;

       vector<int> num;
       int count2 = 0;

       for(int i = 1; i <= n; i++) {
        int u;
        cin >> u;

        int v = u;

        int count = 0;

        while(u % 10 == 0) {
            count++;
            u /= 10;
        }

        while(v > 0) {
            count2++;
            v /= 10;
        }

        if(count > 0) num.push_back(count);
       }

       sort(num.begin(), num.end(), greater<int>());

       int anna = 0, sasha = 0;

       for(int i = 0; i < num.size(); i++) {

        if(i % 2 == 0) anna += num[i];
        else sasha += num[i];
       }

       if(count2 - anna > m) cout << "Sasha" << '\n';
       else cout << "Anna" << '\n';


    }
    return 0;
}