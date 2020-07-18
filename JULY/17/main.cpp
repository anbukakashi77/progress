#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii              pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
//#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b) 		for(int i=a;i<b;i++)
#define repb(i,a,b) 	for(int i=a;i>=b;i--)
#define endl			"\n"
#define m(a)		    memset(a,0,sizeof(a))
#define all(x)                          begin(x), end(x)

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

void file(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	#endif
}

int bs(int a[] , int s , int e, int x){
	if(s<=e){
		int m = (s+e)/2;
		if(a[m]==x)
			return m;
		else if(a[m] > x)
			return bs(a,s,m-1,x);
		else return bs(a,m+1,e,x);
	}
	return -1;
}

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl
#define deba(a) for(auto &x:a) cout<<x<<" ";

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b ,int mod){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

void solveA(){
	int n; sd(n);
	int a[n];
	fill(a,a+n ,1);
	rep(i,0,n) cout << a[i] <<" ";
	cout << endl;
}

void solveB(){
	int n; sd(n);
	if(n&1){
		//find the factors of the number..
		for(int i=2 ; i*i<=n ; ++i){
			if(n%i==0){
				//cout << n/i <<" " << n-(n/i) << endl;
				cout << i <<" " << n-i << endl;
				return;
			}
		}
		cout << 1 << " " << n-1 << endl;
	}
	else{
		cout << n/2 << " " << n/2 << endl;
	}
}

//extended euclids algo...
/*
	returns the combination(x,y) where Ax + By = gcd
	x = y1; y = x1-y1*floor(a/b), (x1,y1) is the new (x,y) when we write gcd(a,b) = gcd(b,a%b);
*/
int gcd , x , y;
void ext_gcd(int a , int b){
	if(b==0){
		x=1;
		y=0;
		gcd = a;
	}
	else{
		ext_gcd(b,a%b);
		int temp=x;
		x=y;
		y = temp-y*floor(a/b);
	}
}

//applications of extended gcd..
//1. modinverse..
/*
	1. modInv of A exists only when A and M are coprime
	2. in the ext_gcd(a,b), set b => mod..
*/
int modInv(int a , int M){
	ext_gcd(a,M);
	return (x%M + M)%M;
}
//modInv using fermats little thrm..only when M is prime..

void solve3(){
	int n; sd(n);
	int dif = inf;
	for(int i=1 ; i*i <=n ; ++i){
		if(n%i==0){
			if(i == n/i){
				cout << 0 << endl; return;
			}
			dif = min(dif , abs(i-n/i));
		}
	}
	tr(dif);
}
		
void solve4(){
	int n; sd(n);
	int s=0;
	for(int i=1 ; i*i <=n ; i++){
		if(!(n%i)){
			if(i==n/i){
				s+=i;
				//cout << i << " ";
			}
			else{
				s+=i; s+=(n/i);
			//	cout << i<< " " << n/i <<" ";
			}
		}
	}
	cout << s << endl;
}

void solve1(){
	int n;sd(n); int a[n]; rep(i,0,n) sd(a[i]);
	int f=0;
	for(int i=0 ; i<n-1; ++i)
	{
		if(a[i+1] > a[i] and !f){
			for(int j=i+2 ; j<n ; j++){
				if(a[j] < a[i+1]){
					f=1;
					cout << "YES" << endl;
					cout << i+1 << " " << i+2 <<" " << j+1 << endl;
					return;
				}
			}
		}
	}
		if(!f){
			cout << "NO" << endl; return;
		}
}

void solve5(){
	string s; cin >> s;
	map<char,int>m;	
	for(int i=0; i<s.length() ; ++i){
		m[s[i]]++;
	}
	int am = m.begin()->ss;
	char c = m.begin()->ff;
	for(auto itr : m){
		if(itr.ss > am){
			am = itr.ss;
			c = itr.ff;
		}
	}
	char f;
	if(c=='R') f='P';
	else if(c=='P') f ='S';
	else f='R';
	string ans = "";
	rep(i,0,s.length()) ans+=f;
	cout << ans << endl;
}

void solve6(){
	//a[i+1] > a[i] and a[i+1] < a[i]..
	//i.e a[i+1] > 0 and a[i] < 0 => if i&1 a[i] > 0, else a[i] < 0;
	int n; sd(n); int a[n];
	for(int i=0 ; i<n ; i++){
		sd(a[i]);
		if(i&1){
			if(a[i] < 0) a[i]*=-1;
		}
		else{
			if(a[i] > 0) a[i]*=-1;
		}
		cout << a[i]<< " ";
	}
	cout << endl;
}

void solve(){
	int n,m; cin >> n>>m; int a[n][m]; 
	int f=0;
	rep(i,0,n){
		rep(j,0,m){
			int neighbors=0;
			if(i>0) ++neighbors;
			if(i<n-1) ++neighbors;
			if(j>0) ++neighbors;
			if(j<m-1) ++neighbors;
			sd(a[i][j]);
			if(a[i][j] > neighbors){
				f=1;
			}
		}
	}
	if(f){
		cout << "NO" << endl; return;
	}
	else{
			cout << "YES" << endl;
		for(int i=0 ; i<n ; ++i){
			for(int j=0; j<m;++j){	
				int neighbors=0;
				if(i>0) ++neighbors;
				if(i<n-1) ++neighbors;
				if(j>0) ++neighbors;
				if(j<m-1) ++neighbors;
				cout << neighbors<< " ";
			}
			cout << endl;
		}
	}
}

int32_t main(){
	file();
	w(t){
		solve();
	}
	return 0;
}

