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

void CF677_D2_A(){
    int n,h; cin >> n >> h;
    vi v(n);
    int count=0;

    rep(i , 0 ,n){
        cin >> v[i];
    }
    rep(i , 0 , n){
        if(v[i] > h)
            count+=2;
        else count++;
    }
    
    cout << count << endl;
}

void Cf734_D2_A(){
    int n; cin >> n;
    string s;
    cin >> s;
    int c1=0;
    int c2=0;
    rep(i , 0 , s.length()){
        if(s[i]=='A')
            c1++;
        else c2++;
    }
    if(c1==c2)
        cout << "Friendship" << endl;
    else{
        if(c1>c2)
            cout << "Anton" << endl;
        else cout << "Danik" << endl;
    }

}

int32_t main(){
    __;	
}