#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n, k;
       cin >> n >> k;
       
       string s;
       cin >> s;

      
       int count_W = 0;
       

       for(int i = 0; i < k; i++) {
        if(s[i] == 'W') count_W++;
       }

       int i = k;
       int cost = count_W;
       int j = 0;

       while(i < n){
        if(s[j] == 'W') count_W--;
        if(s[i] == 'W') count_W++;

        cost = min(cost, count_W);
        i++;
        j++;
       }

       cout << cost << '\n';

    }
    return 0;
}