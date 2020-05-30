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

#define sd(x)           cin>>x            
#define sd2(x,y)        cin>>x>>y        
#define sd3(x,y,z)      cin>>x>>y>>z

#define tr(x)           cout<<x<<endl
#define tr2(x)          cout<<x<<" "<<y<<endl
#define tr3(x)          cout<<x<<" "<<y<<" "<<z<<endl
#define tr4(x)          cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl
#define tr5(x)          cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<" "<<endl

const int N = 1e5+5;
bool vis[N];
vi g[N];
int flag[N];
int child[N];

int dfs(int node){
	vis[node]=1;
	int c=1;
	for(int child: g[node]){
		if(!vis[child]){
			c+=dfs(child);
		}
	}
	return c;
}

void matt(){
	int n,k; sd2(n,k);
	rep(i , 0 ,k){
		int u,v; sd2(u,v);
		g[u].pb(v); g[v].pb(u);
	}	
	int x; sd(x);
	flag[x]=1;
	if(!flag[0]){

	}
//		dfs(0);
//	else dfs(1);
	bool ans=0;
	for(int i=0 ; i<n ; i++){
		if(flag[x]==1 && child[x]==0){
			ans=1;
			break;
		}
	}
	
	if(ans) cout << "Connected" << endl;
	else cout << "Not Connected" << endl;
    
    /*rep(i ,0 ,n){
    	cout << child[i] << " ";
    }
    */   
}

int32_t main(){
	__;
	file();
	int n,e; sd2(n,e);
	rep(i ,0, e){
		int u,v; sd2(u,v);
		g[u].pb(v); g[v].pb(v);
	}
	int ans=0;
	rep(i , 1, n+1){
		if(!vis[i]){
			int x = dfs(i);
			ans = max(ans , x-1);
		}
	}
	tr(ans);
	return 0;
}


