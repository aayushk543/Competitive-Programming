#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        int n,q;
        cin >> n >> q;

        map<int, deque<int>> md;

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            md[num].push_back(i);
        }



        for(int i = 1; i <= q; i++){
            int curr;
            cin >> curr;

            cout << md[curr][0] + i << " ";
            int out = md[curr][0];
            md[curr].pop_front();
            md[curr].push_front(1);
        }

        cout << '\n';
    
    return 0;
}