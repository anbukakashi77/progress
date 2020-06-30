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

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b ){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

/*
	NUMBER THEORY 1
	1. Modular Arith
	2. Exponentiation
	3. GCD euclidian
	4. Extended euclidian
	5. Mod inverse
*/

/*
~ MOD Arithematic..
	1. (a-b)%mod = (a%mod -b%mod + mod)%mod;
	2. x%mod lies in [0 , mod-1];

~ MOD exponentiation..

	mod(int x , int y){
		res=1;
		while(y > 0){
			if(y => odd)	res = (res*x)%mod;
			else if(y => even)	x = (x*x)%mod and y = y/2;
			return res
		}
	}

~ GCD...

	1. gcd(x,y) < x && gcd(x,y) < y

	2. 	NAIVE...
		for(int i = min(x,y) ; i>=1 ; i--)
			if(x%i==0 && y%i==0) gcd = i;
		return gcd;
		
		NOTE: gcd(x,y)<=min(x,y)

	3.	gcd(x,y) = gcd(y,x%y) and gcd(x,0) = x;
		

~ EXTENDED GCD..
	1. GCD(A,B) = Ax + By, find x and y;
	2. {d,x,y} = {gcd, coeff(A) , coeff(B)};


~ MOD INV..
	1. apply extended gcd , ext_gcd(x , mod) and return x(may be -ve)
	2. Apply fermats little theorem, only if mod is prime.
*/

int d,x,y;
void extend_gcd(int a , int b){
	if(b==0){
		d=a;
		x=1;
		y=0;
	}
	else{
		extend_gcd(b , a%b);
		int temp = x;
		x = y;
		y = temp-(a/b)*y;
	}
}

int modInverse(int a ,int mod){
	extend_gcd(a , mod);
	return (x%mod + mod)%mod;
}

int modinv(int a , int mod){
	// using fermats little theorem, when mod is prime
	return mypow(a , mod-2);
}

int32_t main(){
	__;
	return 0;
}




