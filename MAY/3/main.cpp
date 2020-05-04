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

void LECANDY(){
    w(t){
        int n,c; sd2(n,c);
        int a[n]; FOR(i ,0 ,n)sd(a[i]);
        int f=0;
        FOR(i ,0 ,n){
            c-=(a[i]);
        }
        if(c<0)
            f=1;
        if(f)
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}

void CNOTE(){
w(t){
        int x,y,n,k; sd4(x,y,k,n);
        int p[n];
        int c[n];
        FOR(i,0,n) sd2(p[i] , c[i]);
        int pr = x-y;
        int f=0;
        for(int i=0 ; i<n ; i++){
            if(p[i] >= pr && c[i] <= k){
                f=1;
            }
        }
        if(f)
            cout << "LuckyChef" << endl;
        else cout << "UnluckyChef" << endl;
    }	
}

const int N = 1e5+5;
vi g[N];
int vis[N];
int dis[N];

void dfs(int node){
    vis[node]=1;
    for(auto child : g[node]){
        if(!vis[child])
            dfs(child);
    }   
}

void connected_compo_graph(){
    int n,e;
    sd2(n,e);
    FOR(i ,0, e){
        int u,v; sd2(u,v);
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    int c=0;
    FOR(i ,0 , n){
        if(!vis[i]){
            dfs(i); c++;
        }
    }
    tr(c);
}

void dfsd(int node , int d){        //modified dfs for the sssp tree
    vis[node] = 1;
    dis[node] = d;
    for(auto child : g[node]){
        if(!vis[child])
            dfsd(child , dis[node]+1);
    }
}

void Q2_SSSP(){
int n;sd(n);
    FOR(i ,0 , n-1){
        int u,v; sd2(u,v);
        g[u].pb(u);
        g[v].pb(v);
    }   
    dfsd(1 , 0);
    
    int ans = -1;
    int min_dist = inf;
    int q; sd(q);
    while(q--){
        int id; sd(id);
        if(dis[id] < min_dist){
            min_dist = dis[id];
            ans = id;
        }
        else{
            if(dis[id]==min_dist && id < ans){
                ans = id;
            }
        }
    }
    cout << ans << endl;
}

void PT07Y_spoj(){
    /* for a graph to be a tree:    
        1. edges = nodes-1 i.e there doesnt exist any cycle
        2. there is a single connected component
    */
    int n,e; sd2(n,e);
    if(e!=n-1){
        cout << "NO" << endl;
        return;
    }
    for(int i=0 ; i<e ; i++){
        int u,v;sd2(u,v);
        u--; v--;
        g[v].pb(u); g[u].pb(v);
    }
    int c=0;
    FOR(i ,0 , n){
        if(!vis[i]){
            dfs(i); c++;
        }
    }
    if(c==1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

bool dfs_cyc(int node , int par){
    vis[node] = 1;
    for(auto child : g[node]){
        if(vis[child]==0){
            if(dfs_cyc(child , node)==1)
                return true;
        }
        else{
            if(child != par)
                return true;
        }
    }
    return false;
}

void cycle_detect(){
    int n,e; sd2(n,e);
    FOR(i ,0 ,e){
        int u,v; sd2(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    cout << dfs_cyc(1,-1) << endl;
}

int32_t main(){
    __; 
    
    return 0;
}