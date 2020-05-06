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
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

void B1_ladder(){
       int n,t; sd2(n,t);
    string s; cin >> s;
    while(t--){
        for(int i=0 ; i<n-1 ; ){
            if(s[i+1]=='G' && s[i]=='B'){
                s[i+1]='B'; s[i]='G';
                i+=2;
            }
            else i++;
        }
    }
    cout << s << endl;
}

void CF_197_D2(){
    int n,m; sd2(n,m);
    int a[m];
    FOR(i , 0 ,m)sd(a[i]);
    int ans=0;
    ans+=(a[0]-1);
    
    FOR(i ,0 ,m-1){
        if(a[i+1] >= a[i]){
            ans+=(a[i+1]-a[i]);
        }
        else{
            ans+=(n-a[i]+a[i+1]);
        }
    }
    tr(ans);
}

void CF280_D2(){
int n,l;
    sd2(n,l);
    double a[n];
    FOR(i ,0 ,n)sd(a[i]);
    sort(a,a+n);
    double ans=0;
    double t=0;
    if(a[0]!=0){
        t = (a[0]);
        if(t > ans)
            ans = t;
    }
    if(a[n-1]!=l){
        t = (l-a[n-1]);
        if(t > ans )
            ans = t;
    }
    FOR(i ,0 ,n-1){
        t = (a[i+1]-a[i])/2;
        if(t > ans ){
            ans = t;
        }
    }
    printf("%.9lf\n" , ans);
}

void CF284_D2_B(){
    int n,m; sd2(n,m);
    map<string , string > ma;
    FOR(i ,0, m){
        string s1,s2; cin >> s1 >> s2;
        if(s1.length() <= s2.length())
            ma[s1] = s1;
        else ma[s1]=s2;
    }
    FOR(i ,0,n){
        string s; cin >> s;
        cout << ma[s] << " ";
    }
}

int32_t main(){
    __;	
    int n; sd(n);
    int a[n];
    FOR(i ,0 , n)sd(a[i]);
    FOR(i ,0, n){
        int c=2;
        for(int j=2 ; j<a[i] ; j++){
            if(!(a[i]%j))
                c++;
        }
        if(c==3)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}