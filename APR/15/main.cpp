/*	Author
@ Pranjal Walia
IIIT Bangalore
*/
#include<bits/stdc++.h>
using namespace std;

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define sortv(v)        sort(v.begin() , v.end())
#define rsortv(v)       sort(v.rbegin() , v.rend())
#define pw(b,p)         pow(b,p) + 0.1
#define __          	   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b)	   for(int i=a;i<b;i++)
#define repb(i,a,b) 	   for(int i=a;i>=b;i--)
#define endl			   "\n"    

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

void CF431_D2_A(){
    int a[5];
    for(int i=0 ; i<4 ; i++){
        cin >> a[i];
    }
    int ans=0;
    string s; cin >> s;
    rep(i, 0 , s.length()){
        int x = s[i]-'0';
        ans+=a[x-1];
    }
    cout << ans << endl;
}

void CF680_D2_B(){
    int n,a; cin >> n >> a;
    vi v(n+1);
    rep(i , 1 , n+1){
        cin >> v[i];
    }
    int ans=0;

    rep(i , 1 , n+1){
        if(v[i]==1){
            int d = i-a;
            int j = a-d;
            if(v[i]==v[j] || j<1 || j > n)
                ans++;
        }
    }
    cout << ans << endl;
}

bool comp(pii &a , pii &b){
    return a.ss > b.ss;
}

void CF16_D2_B(){
    int n,m; cin >> n >> m;
    vector<pii>v;

    rep(i , 0 , m){
        int x,y; cin >> x>>y;
        v.pb(mp(x,y));
    }
    sort(v.begin(),v.end(),comp);
    int ans=0;

    rep(i , 0 , m){
        if(v[i].ff <= n){
            ans+=((v[i].ff)*(v[i].ss));
            n-=(v[i].ff);
        }
        else{
            ans+=(n*(v[i].ss));
            break;
        }
        if(n<=0)
            break;
    }
    cout << ans << endl;
}

int32_t main(){
    __;
    return 0;
}