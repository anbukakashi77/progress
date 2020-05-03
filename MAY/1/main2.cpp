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

void CORUS(){
w(t){
        int n,q; sd2(n,q);
        string s; cin >> s;
        vi v(26,0);
        FOR(i ,0 ,n){
            v[s[i]-'a']++;
        }
        while(q--){
            int x; sd(x);
            int ans=0;
            FOR(i ,0 ,26){
                if(v[i] > x){
                    ans += (v[i]-x);
                }
            }
            tr(ans);
        }

    }
}

int left(int a[] ,int i , int n){
    if(i==0)
        return 0;
    int s=0;
    for(int j=i-1 ; j>=0; j--){
        if(abs(a[j+1]-a[j]) <= 2)
            s++;
        else break;
    }
    return s;
}


int right(int a[] ,int i , int n){
    if(i==n-1)
        return 0;
    int s=0;
    for(int j=i+1 ; j<n; j++){
        if(abs(a[j-1]-a[j]) <= 2)
            s++;
        else break;
    }
    return s;
}

void COVID19(){
     w(t){
        int ans1=numeric_limits<int>::max();
        int ans2=numeric_limits<int>::min();
        int n; sd(n);
        int a[n]; FOR(i ,0 ,n)sd(a[i]);
        
        for(int i=0; i<n ; i++){
            int tot=1;
            tot += (right(a,i,n) + left(a,i,n));
            ans1 = min(ans1 , tot);
            ans2 = max(ans2 , tot);
        }
        tr2(ans1,ans2);
    }
}

int32_t main(){
    __;
    
    return 0;
}