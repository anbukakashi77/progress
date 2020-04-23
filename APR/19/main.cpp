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

void CF463_D2_B(){
    int n; sd(n);
        vi v(n+1);
        v[0]=0;
        int ans=0;
        int e=0;
        rep(i , 1 , n+1)
            sd(v[i]);
        rep(i , 0, n){
            if(e + v[i]-v[i+1] < 0){
                ans+=(abs(e+v[i]-v[i+1]));
                e=0;
            }
            else e += (v[i]-v[i+1]);
        }
        tr(ans);
    
}

int dig(int n){
    int s=0;
    while(n >0 ){
        s+=(n%10);
        n/=10;
    }
    return s;
}

int cnt(int n){
    int c=0; while(n > 0){
        c++; n/=10;
    }
    return c;
}

void CF102_D2_B(){
int ans=0;
    string s; cin >> s;
    if(s.size()<=1){
        tr(0); return;
    }
    int sum=0;
    rep(i , 0 , s.length()){
        sum+=s[i]-'0';
    }
     ans++;
    // if(cnt(sum) <= 1){
    //     tr(ans); return 0;
    // }
    
        while(cnt(sum) > 1){
            sum = dig(sum);
            ans++;
        }
    
    tr(ans);
}

const int N = 1000001;
bool isprime[N];
void sieve(){
    int maxN = N-1;
    isprime[0]=isprime[1] = 0;
    for(int i=2 ; i<=sqrt(maxN); i++)
        isprime[i]=1;
    for(int i=2 ; i<= sqrt(maxN) ; i++){
        if(isprime[i]){
            for(int j=i*i;  j<= maxN ; j+=i)
                isprime[j]=0;
        }
    }
}
int divSum(int num) 
{ 
    int result = 0; 
    for (int i=2; i<=sqrt(num); i++) 
    { 
        if (num%i==0) 
        { 
            if (i==(num/i)) 
                result += i; 
            else
                result += (i + num/i); 
        } 
    }  
    return (result + 1); 
} 
vector<pii>factors;
void primeFact(int N){
    for(int i=2 ; i<=sqrt(N) ; i++){
        if(N%i==0){
            int count=0;
            while(N%i==0){
                count++;
                N/=i;
            }
            factors.pb(mp(i,count));
            // cout << i << "^" << count << endl;
        }
    }
    if(N>1){
        factors.pb(mp(N,1));
        // cout << N << "^" << 1 << endl;
    }
}
  
bool check(int x){
    string s = "";
    while(x>0){
        s+=((x%10)+'0');
        x/=10;
    }
    rep(i , 0 , s.length()/2+1){
        if(s[i]!=s[s.length()-i-1])
            return false;
    }
    return true;

}

void CHFQUEUE(){
     int n,k; sd2(n,k);
    int a[n]; rep(i , 0 ,n)sd(a[i]);
    int p[n];
    rep(i , 0 , n) p[i]=1;
    int ans=1;
    bool f;
    rep(i , 0 , n){
        f = false;
        rep(j , i+1 , n){
            if(a[j] < a[i] && f==false){
                p[i] = (j-i+1)%mod;
                f = true;
            }
            else continue;
        }
        ans= (ans * (p[i]%mod))%mod;
    }
    // rep(i , 0 , n) cout << p[i] << " ";
     tr(ans);
}

int32_t main(){
    __;
    int n,m; sd2(n,m);
    int a[n]; int b[m];
    rep(i , 0 ,n) sd(a[i]);
    rep(i , 0 ,m) sd(b[i]);
    set<int>s;
    int c=0;
    rep(i , 0 , n){
        rep(j , 0 , m){
            if(s.count(a[i]+b[j])){
                continue;
            }
            else{
                c++;
                s.insert(a[i]+b[j]);
                tr2(i,j);
                if(c == n-m-1)
                    return 0;
            }
        }
    }

    return 0;
}