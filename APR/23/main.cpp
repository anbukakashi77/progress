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

void ZCO12001(){
int n;sd(n);
    int dm=0;
    int d=0;
    int ans=0;
    vi v(n);
    rep(i , 0 , n)sd(v[i]);
    rep(i ,0 ,n){
        if(v[i]==1)
            d++;
        else d--;
        if(d > dm)
            ans = i+1;
        dm = max(dm,d);
    }
    int c=0;
    d=0;
    int max2=0;
    int pos=0;
    rep(i ,0 , n){
        if(v[i]==1)
            c++;
        else{
            d+=2; c--;
            if(c==0){
                if(d > max2){
                    max2 = d;
                    pos = i-d+2;
                }
                d=0;
            }
        }
    }
    tr4(dm,ans,max2,pos);
}


int dp[100][100];
int ks(int wt[], int val[],int w, int i) 
{ 
    if (i < 0) 
        return 0; 
    if (dp[i][w] != -1) 
        return dp[i][w]; 
  
    if (wt[i] > w) {   
        dp[i][w] = ks( wt, val, w, i - 1); 
        return dp[i][w]; 
    } 
    else { 
        dp[i][w] = max(val[i] + ks(wt, val,w - wt[i], i - 1), 
                       ks( wt, val, w , i - 1));   
        return dp[i][w]; 
    } 
} 
// int32_t main(){
//     __;
//     // mem(dp,-1,sizeof(dp));    
//     // int val[] = {10,20,30}; 
//     // int wt[] = {1,1,1}; 
//     // int w = 2; 
//     // int n = 3;
//     // cout << ks(wt,val,w,n);
//      return 0;
// }

int32_t main(){
    __;
    
    return 0;
}