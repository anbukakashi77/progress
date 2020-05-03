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
#define FOR(i,a,b)	   					for(int i=a;i<b;i++)
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

void atcoder_dp_D(){
    int n,w; sd2(n,w);
    int wt[n];
    int val[n];
    FOR(i ,0 , n) sd2(wt[i] , val[i]);
    int dp[n+1][w+1];

    for(int i=0 ; i<=n ; i++) dp[i][0]=0;
    for(int i=0 ; i<=w ; i++) dp[0][i]=0;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<= w ; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    tr(dp[n][w]);
}

int32_t main(){
    __;
    w(t){
        int n; sd(n);
        int a[n];
        FOR(i ,0 ,n) sd(a[i]);
        int ans1=numeric_limits<int>::max();
        int c=1;
        int ans2=0;
        int g=0;

        for(int i=0 ; i<n-1 ;i++){
            if(a[i+1]-a[i] <=2){
                c++; ans2 = max(ans2,c);
            }
            else{
                ans2 = max(ans2,c);
                c=1;   
            }
        }
        ans2 = max(ans2,c);
        c=1;

        pqs pq;
    for(int i=0 ; i<n-1 ; i++){
        if(a[i+1]-a[i] <= 2){
            c++;
             g = max(g,c);
        }   
        else{
            g = max(g,c);
            pq.push(g);
            c=1;
        }
        // cout << g << " ";
        // pq.push(g);
    }
    g = max(g,c);
    pq.push(g);
    // cout << pq.top() << endl;
        
        tr2(pq.top(),ans2);
    }
    return 0;
}