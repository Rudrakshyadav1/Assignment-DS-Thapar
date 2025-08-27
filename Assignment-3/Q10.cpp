#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    ll  t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++)cin>>a[i];
        vector<ll>temp(a.begin(),a.end());
        sort(temp.begin(),temp.end());
        ll s=0;
        ll i=0;
        vector<ll>ans;
        stack<ll>st;
        while(s<n && i<n){
            if(a[i]==temp[s]){
                ans.push_back(a[i]);
                s++;
                i++;
            }
            else if(!st.empty()){
                if(st.top()==temp[s]){
                    ans.push_back(st.top());
                    s++;
                    st.pop();
                }
            }
            else{
                st.push(a[i]);
                i++;
            }
        }
        while(!st.empty() && st.top() == temp[s]){
            ans.push_back(st.top());
            st.pop();
            s++;
        }
        cout<<((ans==temp)?"YES":"NO")<<endl;
    }
}
