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

int mypow(int a, int b , int m){//(logn) --> faster than recursive --> binaryexpo
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%m;
        a = (a * a)%m;
        b >>= 1;
    }
}

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}

void CF_233A(){
    int n;sd(n);
    int a[n];
    FOR(i , 1 , n+1)
        a[i]=i;
    if(n%2!=0){
        cout << -1 << endl;
        return ;
    }
    int j=1;
    while(2*j <= n){
        swap(a[2*j] , a[j*2-1]);
        j++;
    }
    FOR(i , 1, n+1){
        cout << a[i] << " ";
    }
}

void CF146_D1(){
int n;sd(n);
    int ans=1;
    if(n ==1 || n==2)
        ans = n;
    else{
        if(n%2==1){
            ans = n*(n-1)*(n-2);
        }
        else{
            if(n%3==0){
                ans= (n-1)*(n-2)*(n-3);
            }
            else{
                ans = (n)*(n-1)*(n-3);
            }
        }
    }
    tr(ans);    
}

void CF224A(){
int n=3;
    int a[n];
    FOR(i, 0 , n) sd(a[i]);
    sort(a,a+n);
    int x=0,y=0,z=0;
    x = sqrt((a[1]*a[2])/a[0]);
    y = sqrt((a[0]*a[2])/a[1]);
    z = sqrt((a[1]*a[0])/a[2]);
    cout << 4*(x+y+z) << endl;
}

void CF_200B(){
int n; sd(n);
    double a[n]; FOR(i, 0, n)sd(a[i]);
    double ans;
    double t=0;
    FOR(i , 0, n){
        t += (a[i]/100);
    }
    ans = (t/n)*100;
    printf("%.8lf\n" , ans);
}

int32_t main(){
    __;
    return 0;
}