#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define repF(i,a,n) for(int i = (a); i <= (n); ++i)
#define repB(i,a,n) for(int i = (a); i >= (n); --i)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define all(z) z.begin(),z.end()
using namespace std;
using ll = long long;
int main() {
    fast;
    ll n;
    cin>>n;
    vector<ll> arr(n),sum(n);
    rep(i,n){
        cin>>arr[i];
    }
    sort(all(arr));
    rep(i,n){
        if(i!=0)
        sum[i]=sum[i-1]+arr[i];
        else
        sum[i]=arr[i];
    }
    bool flag=false;
    ll h=*max_element(all(arr));
    ll l=2,mid;
    while(l<h) {
        mid=l+(h-l)/2;
        ll i1=lower_bound(all(arr),mid)-arr.begin();
        ll i2=upper_bound(all(arr),mid)-arr.begin();
        ll lv;
        if(i1>0)
        lv=sum[i1-1];
        else
        lv=0;
        ll rv=sum[n-1]-sum[i2-1];
       // cout<<lv<<" "<<rv<<'\n';
        if(lv==rv)
        {
            flag=true;
            break;
        }
        else if(lv<rv)
        l=mid+1;
        else
        h=mid-1;
    }
    if(flag)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
