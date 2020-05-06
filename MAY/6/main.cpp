#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define ii              pair<int,int>
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

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

void file(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
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

const int N = 1e6+7;
int spf[N];

void sof(){
	spf[1] = 0;
	for(int i=2 ; i<N ; i++)
		spf[i]=i;
	for(int i=4; i<=N ; i+=2)
		spf[i]=2;

	for(int i=3 ;i*i <= N ; i++){
		if(spf[i]==i){
			for(int j=i*i ; j<N ; j+=i){
				if(spf[j]==j){
					spf[j] = i;
				}
			}
		}
	}
}

void tprimes_CF142_D2_B(){
	sof();
	int n; cin >> n;
	int a[n];
	rep(i ,0, n)cin>> a[i];
	rep(i ,0, n){
		// a[i] must be a perfect sqaure of a prime nummber to be tprime
		int x = sqrt(a[i]);
		if((x*x) != a[i])	//check if a[i] is a perfect square or not
			cout << "NO" << endl;		
		else{
			if(spf[x]==x)	// perfect square + prime 
				cout << "YES" << endl;
			else cout <<"NO" << endl;	// prefect square + not prime
		}
	}
}

void anton_CF288_D2_B(){
	string s; cin >> s;
	int f=0;
	int f1=0;
	int l = s.length();
	rep(i ,0 ,s.length()){
		if((s[i]-'0')%2==0){
			f=1;break;
		}
	}
	if(!f){
		cout << -1 << endl; return 0;
	}
	else{
		int unit = s[l-1]-'0';
		rep(i ,0, l){
			if((s[i]-'0')%2==0 && (s[i]-'0')<unit){
				f1=1;
				char t = s[i]; s[i]=s[l-1]; s[l-1]=t;
				break; 
			}	
		}
		if(f1){
			cout << s << endl; return 0;
		}
		else{
			for(int i=l-2 ; i>=0 ; i--){
				int curr = s[i]-'0';
				if(curr%2==0 && curr > unit){
					f1=1;
					char t = s[i]; s[i]=s[l-1] ; s[l-1]=t;
					break;
				}
			}
			if(f1){
				cout << s << endl; return 0;
			}
		}
	}
}

int32_t main(){	
	__;
}