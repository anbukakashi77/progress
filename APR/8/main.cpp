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

void LAPIN(){
	w(t){
		int ans=0;

		string s;
		cin >> s;
		int l = s.length();
		if(l%2==0){
			string s1 = s.substr(0 , l/2);
			string s2= s.substr(l/2 , l/2);
			sort(s1.begin() , s1.end());
			sort(s2.begin() , s2.end());
			ans = s1.compare(s2);		
		}
		else{
			string s1 = s.substr(0 , l/2);
			string s2 = s.substr((l+1)/2 , l/2);
			sort(s1.begin() , s1.end());
			sort(s2.begin() , s2.end());
			ans = s1.compare(s2);
		}
	if(ans==0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	}
}	

int32_t main(){	
	__;
	int t; fastscan(t);
	while(t--){
		int n; fastscan(n);
		int a[n];
		rep(i , 0 , n){
			fastscan(a[i]);
		}
		int c=1;
		int m = a[0];
		rep(i ,0 , n-1){
			
		}
	}
	
}
