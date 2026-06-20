#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        long long a,b,x1,y1,x2,y2;

        cin >> a >> b >> x1 >> y1 >> x2 >> y2;

        set<pair<long long,long long>> st;

        st.insert({x1-a,y1-b});
        st.insert({x1+a,y1+b});
        st.insert({x1+a,y1-b});
        st.insert({x1-a,y1+b});

        st.insert({x2-a,y2-b});
        st.insert({x2+a,y2+b});
        st.insert({x2+a,y2-b});
        st.insert({x2-a,y2+b});

        st.insert({x1-b,y1-a});
        st.insert({x1+b,y1+a});
        st.insert({x1+b,y1-a});
        st.insert({x1-b,y1+a});

        st.insert({x2-b,y2-a});
        st.insert({x2+b,y2+a});
        st.insert({x2+b,y2-a});
        st.insert({x2-b,y2+a});

        if(a == b) cout << (16 - st.size())/2 << '\n';
        else cout << 16 - st.size() << '\n';
    }
    return 0;
}