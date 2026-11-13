#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> p(n+1),left(n+1,0),right(n+1,0);
    for(int i=1;i<=n;i++) cin>>p[i];

    stack<int> s; s.push(1);

    long long lowerBound=LLONG_MIN;
    for(int i=2;i<=n;i++) {
        if(p[i]<lowerBound) {
            cout<<"NO\n"<<i<<"\n";
            return 0;
        }

        if(!s.empty() && p[i]<p[s.top()]) left[s.top()]=i;
        else {
            int parent=0;
            while(!s.empty() && p[s.top()]<p[i]) {
                parent=s.top();
                lowerBound=p[parent];
                s.pop();
            }
            right[parent]=i;
        }
        s.push(i);
    }

    stack<int> s1,s2; s1.push(1);
    while(!s1.empty()) {
        int u=s1.top();
        s1.pop(); s2.push(u);
        if(left[u]!=0) s1.push(left[u]);
        if(right[u]!=0) s1.push(right[u]);
    }

    cout<<"YES\n";
    while(!s2.empty()) {
        cout<<p[s2.top()]<<" ";
        s2.pop();
    }
    cout<<"\n";
    return 0;
}
