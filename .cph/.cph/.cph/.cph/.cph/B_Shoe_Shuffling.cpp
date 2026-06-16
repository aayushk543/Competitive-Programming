#include<bits/stdc++.h>
using namespace std;
#define llmax(a,b) max((long long)(a), (long long)(b))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<long long> arr(n);

        vector <pair<long long,long long>> vec;

        int i = 0, j = 0;

        bool c = true;

        for(i = 0; i < n; i++) {
            cin >> arr[i];
            if(i > 0 && arr[i-1] != arr[i]) {
                vec.push_back({j,i-1}); 
                if(j == i-1) c = false;
                j = i;
            }
        }

        if(j == i-1) c = false;

        vec.push_back({j,n-1});

        if(c == false) cout << -1;
        else {
            for(int i = 0; i < vec.size(); i++){
                long long st = vec[i].first;
                long long end = vec[i].second;

                cout << end + 1 << " ";

                for(int i = st+1; i <= end; i++){
                    cout << i << " ";
                }
            }
        }

        cout << '\n';

        


    }
    return 0;
}