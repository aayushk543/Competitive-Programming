#include<bits/stdc++.h>
using namespace std;
#define llmax(a,b) max((long long)(a), (long long)(b))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long n;
        int m;

        cin >> n >> m;

        vector<long long> arr(m, 0);

        for(int i = 0; i < m; i++) cin >> arr[i];

        long long count = 0;

        bool c = true;

        deque <pair<long long,long long>> ans;

        for(int i = 0; i < m; i++){
            
            long long f = (arr[i]-count);
            count++;
            
            long long b = (arr[i]+count);

            while(i < m-1 && arr[i+1]-count >= b) {
                b = arr[i+1] + count; 
                i++;
                if(i == m-1){
                    c = false;
                    
                }
            }

            count++;

            if(c) ans.push_back({f,b});

            if(i == m-1 && b >= n) {
                ans[ans.size()-1].second = n;
                ans.push_front({1,b%(n+1) + 1});
            }
        }

        count = 0;

        long long prev_st = ans[0].first;
        long long prev_end = ans[0].second;

        vector<vector<long long>> ans2;

        ans2.push_back({prev_st, prev_end});

        for(int i = 1; i < ans.size(); i++){
            long long curr_st = ans[i].first;
            long long curr_end = ans[i].second;

            int l = ans2.size();

            if(curr_st <= prev_end){
                ans2[l-1][1] = max(curr_end, prev_end);
            } 
            else ans2.push_back({curr_st, curr_end});

            prev_st = ans2[l-1][0];
            prev_end = ans2[l-1][1];
    
        }

        long long co = 0;
        for(int i = 0; i < ans2.size(); i++){
            co += ans2[i][1] - ans2[i][0];
            
        }

        cout << co << '\n';


    }
    return 0;
}