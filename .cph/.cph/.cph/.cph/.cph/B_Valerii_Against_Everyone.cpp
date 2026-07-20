#include<iostream>
#include<set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;

       set<long long> s;

       for(int i = 0; i < n; i++) {
        long long m;
        cin >> m;

        s.insert(m);
       }

       if(s.size() < n) cout << "YES" << '\n';
       else cout << "NO" << '\n';


    }
    return 0;
}