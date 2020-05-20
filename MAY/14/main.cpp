/*	Author --> @Pranjal Walia :P   */
// IIIT Bangalore
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
#define ps(x,y)         				fixed<<setprecision(y)<<x
#define mk(arr,n,type)  				type *arr=new type[n];
#define w(x)            				int x; cin>>x; while(x--)
#define all(x)                       begin(x), end(x)
#define rall(x) 						rbegin(x), rend(x)
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

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int power(int a, int b){	//(logn) --> faster than recursive --> binary expo
    int res = 1;            // call int x = power(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

void covid()
{
w(t){
    int n; sd(n);
    int a[n]; rep(i, 0,n)sd(a[i]);
    int mini=inf;
    int maxi =-inf;
    
    rep(i ,0, n){
        int t=1;
        int c1=0;
        int c2=0;
        //left
        for(int j=i-1 ; j>-1 ; j--){
            if(i==0)
                break;
            if(a[j+1]-a[j] <= 2){
                c1++;
            }
            else break;
        }

        //right
        for(int j=i+1 ; j<n ; j++){
            if(i==n-1)
                break;
            if(abs(a[j-1]-a[j]) <= 2)
                c2++;
            else break;
        }

        t+=(c1+c2);
        maxi = max(t , maxi);
        mini = min(t,mini);
    }
        tr2(mini , maxi);
    }
}

void CORUS(){
    w(t){
        int n,q; sd2(n,q);
        string s; cin >> s;
        int f[26];
        fill(f, f+26 , 0);
        rep(i ,0 ,s.length()){
            f[s[i]-'a']++;
        }
        // rep(i, 0, s.length()) cout << f[i] << " ";
        while(q--){
            int ans=0;
            int x; sd(x);
            rep(i ,0, 26){
                if(f[i]-x > 0){
                    ans+=(f[i]-x);
                }
            }
            tr(ans);
        }
    }
}

const int N = 1e5+5;
vi g[N];
int vis[N];
int ter[N];
int dis[N];

int32_t main(){
    __;	
    file();
    w(t){
        set<int>s;
        int e; sd(e);
        rep(i ,0 ,e){
            int x,y; cin >> x >> y;
        }
    }
    return 0;
}