/*	Author
@ Pranjal Walia --> trying out CLion
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

#define ff              				first
#define ss              				second
#define int             				long long
#define pb              				push_back
#define mp              				make_pair
#define pii             				pair<int,int>
#define vi              				vector<int>
#define mii             				map<int,int>
#define pqb             				priority_queue<int>
#define pqs             				priority_queue<int,vi,greater<int> >
#define setbits(x)      				__builtin_popcountll(x)
#define zrobits(x)      				__builtin_ctzll(x)
#define mod             				1000000007
#define inf             				1e18
#define mem(a,x,n)					memset(a,x,sizeof(a))		//initialise only 0 ans -1 with memset
#define ps(x,y)         				fixed<<setprecision(y)<<x
#define mk(arr,n,type)  				type *arr=new type[n];
#define w(x)            				int x; cin>>x; while(x--)
#define sortv(v)        				sort(v.begin() , v.end())
#define rsortv(v)       				sort(v.rbegin() , v.rend())
#define pw(b,p)         				pow(b,p) + 0.1
#define __          	   				ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b)	   					for(int i=a;i<b;i++)
#define repb(i,a,b) 	   				for(int i=a;i>=b;i--)
#define endl			   				"\n"

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

void anton_exchange_rates(){
    string s; cin >> s;
    int f=0;
    int f1=0;
    rep(i ,0 ,s.length()){
        if((s[i]-'0')%2==0){
            f=1; break;
        }
    }
    if(!f){
        cout << -1 << endl; return;
    }
    else{
        int l = s.length();
        int unit = s[l-1]-'0';
        rep(i, 0, l){
            int curr = s[i]-'0';
            if(curr < unit && curr%2==0){

            }
        }
        if(f1){
            cout << s << endl; return;
        }
        else{
            rep(i ,0 ,l){
                int curr = s[i]-'0';
                if(curr < unit && curr%2==0){
                    swap(s[i],s[l-1]);
                    f1=1; break;
                }
            }
            if(f1) cout << s << endl;
            else{
                for(int i=l-2 ; i>=0 ; i--){
                    int curr = s[i]-'0';
                    if(curr%2==0 && curr > unit){
                        swap(s[i], s[l-1]);
                        cout << s << endl; return;
                    }
                }
            }
        }
    }
}

void DZY_loves_strings(){
    string s; cin >> s;
    int k; sd(k);
    int ans=0;
    int f[26];
    int c=0;
    rep(i ,0, 26){
        sd(f[i]);
        c = max(c , f[i]);
    }

    for(int i=0 ; i<s.length() ; i++){
        ans += ((i+1)*(f[s[i]-'a']));
    }
    for(int i=0 ; i<k ; i++){
        ans += (c*(s.length()+i+1));
    }
    tr(ans);
}

void sort_by_shift(){
    int n; sd(n);
    int a[n]; rep(i ,0,n) sd(a[i]);
    int ans=0;
    int mark;
    int c=0;
    int f=0;
    rep(i ,0, n-1){
        if(a[i+1] < a[i]) {
            f=1;
            c++;
            mark = i + 1;
        }
    }
    if(!f){
        cout << 0 << endl; return;
    }
    if(c > 1){
        cout << -1 << endl; return;
    }
    else if(c==1){
        if(a[n-1] <= a[0]){
            cout << n-mark << endl;
        }
        else cout << -1 << endl;
    }
}

void roadside(){
int n; sd(n);
    int a[n]; rep(i ,0, n)sd(a[i]);
    int ans=0;
    ans+=(a[0]+1);
    for(int i=1 ; i<n ; i++){
        ans+=(a[i-1]-min(a[i-1],a[i])+1);
        if(a[i]==min(a[i-1],a[i])) ans++;
        else{
            ans+=(a[i]-a[i-1]+1);
        }
    }
    tr(ans);
}

const int N = 1e5+5;
int dp[N];

int f(int n ,int x , int y){
    if(n==1) return x;
    if(n==2) return y;
    return (mod + f(n-1 , x , y)-f(n-2 , x , y))%mod;
}

void CF257_D2_B(){
    int x,y;
    sd2(x,y);
    int n; sd(n);
    n = n%6;

    if(n==1) cout << (x%mod+mod)%mod << endl;
    else if(n==2) cout << (y%mod+mod)%mod << endl;
    else if(n==3) cout << ((y-x)%mod+mod)%mod << endl;  
    else if(n==4) cout << ((-x)%mod + mod)%mod << endl;
    else if(n==5) cout << ((-y)%mod+mod)%mod << endl;
    else cout << ((x-y)%mod+mod)%mod << endl;
}

int32_t main(){
    __;
    file();
    
    return 0; 
}
