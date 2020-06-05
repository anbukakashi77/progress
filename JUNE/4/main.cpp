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

void func(){
	string s; cin >> s;
	int f[26] = {0};
	rep(i ,0 ,s.length()){
		f[s[i]-'a']++;
	}
	int x=0;
	int flag=0;
	rep(i ,0 ,26){
		if(f[i]%2==0){
			continue;
		}
		else{
			if(flag==0){
				if(f[i]%2!=0){
					flag=1;
				}
				else continue;
			}
			else{
				if(f[i]%2!=0){
					x^=1;
				}
				else continue;
			}
		}
	}
	//rep(i ,0 ,26) cout << f[i] <<" ";
	
	if(!x){
		cout << "First" << endl;
	}
	else cout << "Second" << endl;
}

void func1(){
	/*
	https://codeforces.com/problemset/problem/362/B

	Logic: Greedily search for a continuous segment of size>=3 that is marked
	Remember that if the start and end are marked, then NO always.
	if found: 
			tr(no)
	else if not_found:
			tr(yes)	
	*/
	int n,m; sd2(n,m);
	int a[m];
	rep(i ,0 ,m){
		sd(a[i]);
	}	
	int curr=0;
	sort(a,a+m);
	if(a[0]==1 || a[m-1]==n){
		cout << "NO" << endl; return ;
	}
	else{
		for(int i=0 ; i<m-2 ; i++){
			if(a[i+2]-a[i+1]==1 && a[i+1]-a[i]==1){
				cout << "NO" << endl;
				return ;
			}
			else continue;
		}
		cout <<"YES"<< endl;
	}
}

int32_t main(){	
	__;
	file();
	int n,t; sd2(n,t);
	int a[n];
	rep(i ,0 ,n){
		sd(a[i]);
	}
	int p[n];
	p[0] = a[0];
	rep(i ,1 ,n){
		p[i] = p[i-1]+a[i];
	}
	return 0;
}




