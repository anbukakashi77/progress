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

const int N = 1e5+9;
int vis[N];
vi g[N];
int subsize[N];
int dis[N];

int cc;
int curr_size;
int max_size;
int d_max;
int max_node;
int col[N];

int dfs(int node){
	vis[node]=1;
	curr_size++;
	for(int child : g[node]){
		if(!vis[child]){
			dfs(child);
		}
	}
}

void test_firesc(){
	w(t){
		max_size=0;
		//init
		int n,e; cin >> n >> e;
		rep(i ,0, n+1){
			vis[i]=0; g[i].clear();
		}
		int res=1;
		int cc=0;
		curr_size=0;
		for(int i=0 ; i<e ; i++){
			int u,v; cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
		}
		rep(i , 1 ,n+1){
			if(!vis[i]){
				curr_size=0;
				dfs(i); cc++;
				cout << curr_size << endl;
				res = (res*curr_size)%mod;
				max_size = max(max_size , curr_size);
			}
		}
//		cout << cc << " " << res << " " << max_size << endl;
	}
}

void dfs_d(int node , int d){
	vis[node]=1;
	if(d > d_max){
		d_max = d;
		max_node = node;
	}
	for(int child : g[node]){
		if(!vis[child]){
			dfs_d(child , d+1);
		}
	}
}	

void diameter_rev(){
int n; cin >> n;
	rep(i ,0, n-1){
		int u,v; cin >> u >> v;
		g[u].pb(v); g[v].pb(u);		
	}
	d_max = -1;
	dfs_d(1 , 0);
	rep(i,0,n+1)vis[i]=0;
	d_max=-1;
	dfs_d(max_node , 0);
	cout << d_max << endl;
}

int sub_dfs(int node){
	int curr_size=1;
	vis[node]=1;
	for(int child : g[node]){
		if(!vis[child]){
			curr_size += sub_dfs(child);
		}
	}
	subsize[node] = curr_size;
	return curr_size;
}

void subtree_size(){
	int n; cin >> n;
	rep(i ,0, n-1){
		int u,v; cin >> u >> v;
		g[u].pb(v); g[v].pb(u);		
	}
	sub_dfs(1);
	rep(i ,1 , n+1)
		cout << i << " " << subsize[i] << endl;
}

void bfs(int src){
	queue<int>q;
	q.push(src);
	vis[src]=1;
	dis[src]=0;

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		for(int child : g[curr]){
			if(!vis[child]){
				q.push(child);
				dis[child] = dis[curr]+1;
				vis[child]=1;
			}
		}
	}
}

void SSSP_BFS(){
	w(t){
		int n,e; cin >> n >> e;
		rep(i ,0 ,n+1){
			vis[i]=0; g[i].clear();
		}
		rep(i ,0, e){
			int u,v; cin >> u >> v;
			g[u].pb(v); g[v].pb(u);		
		}
		bfs(1);
		cout << dis[n] << endl;
	}
}

bool dfs_bpg(int node , int c){
	vis[node]=1;
	col[node]=c;

	for(int child : g[node]){
		if(!vis[child]){
			if(dfs_bpg(child , c^1)==false)
				return false;
		}
		else{
			if(col[child]==col[node])
				return false;
		}
	}
	return true;
}

void test_bpg(){
	int n,e; cin >> n>>e;
	rep(i ,	0, e){
		int u,v; cin >> u >> v;
		g[u].pb(v); g[v].pb(u);		
	}
	cout << dfs_bpg(1,1) << endl;
}

void bugslife_spoj()
{
	int t; cin >> t;
	for(int tc=1 ; tc<=t ;tc++){
		int n,e; cin >> n>>e;
		rep(i ,0, n+1)
		{
			vis[i]=0;
			g[i].clear();
		}
		rep(i ,	0, e){
			int u,v; cin >> u >> v;
			g[u].pb(v); g[v].pb(u);		
		}	
		int f=1;
		rep(i ,1 ,n+1){
			if(!vis[i]){
				bool res = dfs_bpg(i , 1);
				if(!res){
					f=0;break;
				}
			}
		}
		cout << "Scenario #" << tc << ":" << endl;
		if(!f){
			cout << "Suspicious bugs found!" << endl;
		}
		else cout << "No suspicious bugs found!" << endl;
	}
}

int32_t main(){	
	__;
	file();
}