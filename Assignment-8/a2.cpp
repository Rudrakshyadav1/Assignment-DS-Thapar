#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(vector<ll>& dp, int n){
    dp[0]=dp[1]=1;
    for(ll i=2;i<=n;i++){
        for(ll j=1;j<=i;j++){
            dp[i]+=dp[i-j]*dp[j-1];
        }
    }
    return dp[n]; 
}
int main() {
    int n;cin >> n;
    vector<ll> dp(n + 1,0);
    cout << solve(dp, n) << endl;

}
