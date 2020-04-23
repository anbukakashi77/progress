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

void GCDQ(){
w(t){
    int n,q; sd2(n,q);
    int a[n]; rep(i ,1 , n+1) sd(a[i]);
    int p[n+100];
    int s[n+100];

    p[0]=0;
    rep(i , 1 , n+1){
        p[i] = __gcd(a[i] , p[i-1]);
    }

    s[n+1]=0;
    for(int i=n ; i>=1 ; i--){
        s[i] = __gcd(s[i+1],a[i]);
    }

    while(q--){
        int l,r; sd2(l,r);
        cout << __gcd(p[l-1] , s[r+1]) << endl;
    }
    
    }
    
}

void A(){
    w(t){
        int n; sd(n);
        for(int i=2 ; ; i++){
            int x = pow(2,i);
            if(n%(x-1)==0){
                cout << n/(x-1) << endl;
                break;
            }
        }
    }
}

void B(){
    w(t){
        int n; sd(n);
        int a[n+1];
        int b[n+1];
        int s1=0;
        int s2=0;
        int f=0;
        for(int i=1 ; i<=n/2 ; i++){
            a[i] = 2*i;
            s1+=a[i];
        }
        for(int i=1 ; i<=n/2 ; i++){
            if(i==n/2){
                b[i]=(s1-s2);
                if(b[i]%2==0){
                    f=1;
                    break;
                }
            }
            else{
                b[i] = 2*i-1;
                s2+=b[i];
            }
        }
        if(f){
            cout <<"NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i=1 ; i<=n/2 ; i++)
                cout << a[i] << " ";
            for(int i=1 ; i<=n/2 ; i++)
                cout << b[i] <<" ";
                cout << endl;
        }
    }
}

int fast_expo(int x, unsigned int y, int p){ 
	int res = 1;	  
	x = x % p; 
	if (x == 0) return 0;                   //call fast_expo(2,5,mod)
	while (y > 0){ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;							//y = y/2 
		x = (x*x) % p; 
	} 
	return res; 
} 
void CF383_D2_A(){
    int n; sd(n);
    cout << fast_expo(8,n,10) << endl;    
}

int power(int x, int y , int p)
{
	int res = 1;	  
	x = x % p; 
	if (x == 0) return 0;                   //call fast_expo(2,5,mod)
	while (y > 0){ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;							//y = y/2 
		x = (x*x) % p; 
	} 
	return res;
}

int GCD(int A , int B , int n)
{
	if(A == B)
	{
		return (power(A , n , mod) + power(B , n , mod)) % mod;
	}
	
	int cnd = 1;
	int num = A - B;
	
	for(int i=1;i*i<=num;i++)
	if(num % i == 0)
	{
		int temp = (power(A , n , i) + power(B , n , i)) % i;
		
		if(temp == 0) cnd = max(cnd , i);
		
		temp = (power(A , n , num/i) + power(B , n , num/i)) % (num/i);
		if(temp == 0) cnd = max(cnd , num / i);
	}
	
	return cnd % mod;
}

int32_t main(){
    __;
    w(t){
        int a,b,n; sd3(a,b,n);
        cout << GCD(a,b,n) << endl;
    }
    return 0;
}