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
#define mem(a,x,n)      				memset(a,x,sizeof(a))
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

int mypow(int a, int b){	//(logn) --> faster than recursive --> binary expo
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

const int N = 1000001;
int isprime[N];

void sieve(){
    int maxn = N-1;
    for(int i=1 ; i<= maxn ; i++) isprime[i] = 1;
    isprime[0] = isprime[1] = 0;

    for(int i=2 ; i<= sqrt(maxn) ; i++){
        if(isprime[i]){
            for(int j=i*i;  j<= maxn ; j+=i)
                isprime[j]=0;
        }
    }
}

int cumsum[N-1];

void micro_and_primeprime_hackerearth(){
    sieve();
    cumsum[0]=0;
    cumsum[1]=0;
    cumsum[2]=1;
    for(int i=3 ; i<=N-1 ; i++){
        if(isprime[i]){
            cumsum[i] = 1+cumsum[i-1];
        }
        else cumsum[i] = cumsum[i-1];
    }
    w(t){
        int l,r; cin >> l >> r;
        int ans=0;
        for(int i=l; i<=r ; i++){
            if(isprime[cumsum[i]])
                ans++;
        }
        tr(ans);
    }
}

void CF_634_D3(){
w(t){
        int n,a,b; sd3(n,a,b);
        int i=0;
        string s = "";
        rep(i ,1 ,b+1){
            s+=(char)(i+96);
        }
        string s1 = s.substr(0,b);
        rep(i , 0 , 2000)
            s+=s1;
        cout << s.substr(0,n) << endl;
    }
}


int32_t main(){
    __;	
    w(t){
        int n; sd(n);
        map<int,int>m;
        set<int>s;

        int a[n]; rep(i , 0 , n){
            sd(a[i]);
            s.insert(a[i]);
            m[a[i]]++;
        }
        int same=0;
        for(auto itr: m){
            if(itr.ff>1)
                same++;
        }
        int dist = s.size()-1;
        if(n==1){
            tr(0);
            continue;
        }
        bool f = true;
        for(auto itr : m){
            if(itr.ss > 1)
                f = false;
        }
        if(f){
            cout << 1 << endl;
            continue;
        }
        int ans=0;

        ans = max(min(dist-1 , same) , min(dist , same-1));
        tr(ans);
    }
    return 0;
}