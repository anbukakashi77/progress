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

const int N = 1e5;
int a[N];
int st[4*N];


//min
void build(int n){

	for(int i=0; i<n ; i++){
		st[n+i-1] = i;
	}

	for(int i=n-2 ; i>=0 ; i--){
		if(a[st[2*i+1]] > a[st[2*i+2]]){
			st[i] = st[2*i+2];
		}
		else st[i]=st[2*i+1];
	}
}


int rmq(int i , int j , int s , int e ,int p){
    if(j<s || e<i){
        return inf;
    }else if(i<=s && j>=e){
        return st[p];
    }
    int m = (s + e)/2;
    int l1 = rmq(i , j , s , m , 2 *p + 1);
    int l2 = rmq(i , j , m+1 , e , 2 * p + 2);

    if(a[l1]<a[l2]){
        return l1;
    }else{
        return l2;
    }
}

void update(int n , int i , int x){
	a[i]=x;
	i = (n-1 + i-1)/2;

	while(i >=0){
		if(a[st[2*i+1]] > a[st[2*i+2]]){
			st[i] = st[2*i+2];
		}
		else st[i] = st[2*i+1];

		if(i < 1) break;

		i = (i-1)/2;
	}
}

int32_t main(){	
	__;
	file();
	int n; sd(n);
	fill(a , a+N , inf);

	rep(i , 0,n) sd(a[i]);

	if(log2(n)-n != 0){
		n = pow(2 , (int)ceil(log2(n)));
	}
	build(n);
	cout <<"built"<< endl;
	/*
	cout << "build" << endl;
	cout << rmq(0,0,n-1,0,n-1) << endl;
	update(n , 0 , inf);
	cout << rmq(0 , 0 , n-1 , 0, n-1) << endl;
	*/
	cout << rmq(0 ,0 ,n-1,3 ,5) << endl;
	return 0;
}




