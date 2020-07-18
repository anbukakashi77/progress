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

void file(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	#endif
}

#define tr(x) cout<<x<<endl;
#define sd(x) cin >> x;

//SEE THE HACKEREARTH TUTORIAL ON BIT MANIPULATIONS...

//basic bit manipulations..
void odd_or_even(int n){
	//check odd and even..
	//(n&1) => odd
	//(!(n&1)) => even
	//((n&1)^1) => even
}

void count_set_bit_dont_use(int n){	//better way is to use bitset..
	//dry run this..count the number of set bits in a number..
	int count=0;
	while(n>0){
		if(n&1){
			count++;
		}
		n>>1;
	}
}

int count_setbit(int n){
	int c=0;
	while(n){
	// in each cycle, the lsb is dropped...
		c++;
		n=n&(n-1);	
		// n&(n-1) => drops the last set bit (lsb)..	
		// eg: 14(1110) => 12(1100)
	}
	return c;
}

bool check_kth_bit(int n , int k){
	return (n&(1<<k));
}

int set_kth(int n ,int k){
	//usage => int x = set_kth(n,k);
	return (n|(1<<k));
}

int unset_kth(int n, int k){
	return (n & ~(1<<k));
}

int flip_kth(int n , int k){
	return (n^(1<<k));
}
//==================================================================//
int lsb(int n){
	int k = (n&(-n));
	return log2(k);
}

bool check_power_of2(int n){
	if(n<=0) return 0;
	if(n&(n-1)==0) return 1;
	else return 0;
}

//=================================================================//
//Imp: a^a = 0 ;  a^0 = a;

void unique_in_vector(){
	//find the unique element in the vector..
	vi v = {5,15,5,3,5,15}; int x=v[0];
	rep(i ,1,v.size()){	
		x^=v[i];
	}
	tr(x);
}

void find_duplicate(){
	vi v = { 23 , 21 , 24 , 27 , 22 , 27 , 26 , 25 };
	/*
		Algo: use the facts that n^n=0 and n^0=n.
		1. find the min and max in the array => O(N).
		2. find the xor of all integers in range [min,max] => x = min^(min+1)^....^(max).
		3. find the xor of all elements in the array => y = a[0]^a[1]^a[2]...^a[n-1].
		4. ans = x^y;
	*/    
}
//=================================================================//

int32_t main(){	
	__;
	file();
	return 0;
}




