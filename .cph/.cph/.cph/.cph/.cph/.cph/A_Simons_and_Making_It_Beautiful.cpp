#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<tuple<ll,ll,ll>> a(n);
    vector<ll> b(n);

    for(int i = 0; i < n; i++){
        ll m,n;
        cin >> m >> n;

        a[i] = {m,n,i};
    }

    sort(a.begin(), a.end());

    int rcount = 0;
    vector<ll> ans(n);

    priority_queue <pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;

    for(int i = 0; i < n; i++){
        ll start = get<0>(a[i]);
        ll end = get<1>(a[i]);
        ll ind = get<2>(a[i]);
        
        if(!pq.empty() && pq.top().first < start){
            pair<ll,ll> top = pq.top();
            pq.pop();

            int room = top.second;

            ans[ind] = room;
            pq.push({end,room});
        }
        else {
            rcount++;
            ans[ind] = rcount;
            pq.push({end, rcount});
        }
    }

    cout << rcount << '\n';

    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << '\n';



    return 0;
}