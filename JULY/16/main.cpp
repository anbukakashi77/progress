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
#define mod             1000000007
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

int mypow(int a, int b){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

bool isprime(int n){
	if(n<=1) return false;
	for(int i=2 ; i*i <= n ; ++i){
		if(n%i==0) return false;
	}
	return true;
}

bool check(int n){
	if(n==1) return false;
	int k = sqrt(n);
	return (k*k == n and isprime(k));
}

void solve1(){
	int n; sd(n); int a[n]; rep(i,0,n) sd(a[i]);
	rep(i,0,n){
		if(check(a[i])) cout <<"YES" << endl;
		else cout <<"NO" << endl;
	}
}

void solve2(){
	//anton and exchange rates..
	string s; cin >> s;
	int f=0; int l = s.length();
	rep(i,0,l){
		int cur = s[i]-'0';
		if(!(cur&1))
		{
			f=1; break;
		}
	}
	if(!f){
		cout << -1 << endl;
	}
	else{
		int unit = s[l-1]-'0';
		//check from the left for curr < unit..
		int done=0;
		rep(i,0,l){
			int cur = s[i]-'0';
			if(cur < unit and !(cur&1)){
				swap(s[i] , s[l-1]);
				done=1; break;
			}
		}
		if(done){
			cout << s << endl; return;
		}
		else{
		//check from the right for curr > unit (because no remaining even that is lessesr and even)..
			for(int i=l-2 ; i>=0 ; i--){
				int cur = s[i]-'0';
				if(!(cur&1) and unit < cur){
					swap(s[i] , s[l-1]);
					break;
				}
			}
			cout << s << endl; return;
		}

	}	
}

void solve3()
{
	//dzy loves strings..
	string s; cin >> s;
	int k; sd(k);
	int ans=0;
	int f[26];
	int c=0; 
	rep(i,0,26){
		sd(f[i]);
		c=max(c,f[i]);
	}
	rep(i,0,s.length()){
		ans+=((i+1)*f[s[i]-'a']);
	}
	rep(i,0,k){
		ans+=((s.length()+i+1)*c);
	}
	tr(ans);
}

bool check(vi a , int i , int j){
	for(int k=i ; k<=j ; k++){
		if(a[k+1] < a[k]) return false;
	}
	return true;
}

void solve(){
	int n,x; sd2(n,x); int a[n]; rep(i,0,n) sd(a[i]);
	sort(a,a+n);
	int p=0;
	int ans=0;
	while(p<n and 2*a[p] <= x){
		p++;
		ans++;
	}
	while(p<n){
		ans++;
		if(x < a[p] and 2*(a[p]-x) > a[p]){
			x*=2;
			continue;
		}
		if(x>=a[p]){
			x = a[p];
			p++;
		}
		x*=2;
	}
	tr(ans);
}

int32_t main(){	
	__;
	file();
	w(t)
	{
		solve();
	}
	return 0;
}




