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

void NotAllFlavs(){
        int n,k;
    sd2(n,k);
    int a[n]; rep(i ,0 , n) sd(a[i]);
    int ans=0;
    int f=0;
    int c=0;
    map<int,int>m;

    rep(i , 0 ,n ){
        m[a[i]]++;
        c++;
        if(m.size()<k){
            ans = max(ans , c);
        }
        if(m.size()==k){
            auto itr = m.find(a[f]);
            m[a[f]]--;
            if(itr->ss ==0)
                m.erase(itr);
            f++;
            c--;
        }
    }
    tr(ans);
}

void CHFQUEUE(){
    int n,k;sd2(n,k);
    int a[n]; rep(i ,0 , n)sd(a[i]);
    int ans=1;
    stack<pii>s;
    rep(i ,0 , n){

        while(!s.empty() && s.top().ff > a[i]){
            ans = ans * (i-s.top().ss + 1)%mod;
            ans = ans%mod;
            s.pop();
        }
        s.push(mp(a[i],i));
    }
    tr(ans);
}

int func(int a[] , int n){
    int s=0;
    int ans=0;
    rep(i , 0 , n)
        s+=a[i];
    if(s%n!=0)
        return -1;
    else{
        rep(i , 0, n){
            if((s)/n - a[i] >= 0){
                ans+=((s)/n - a[i]);
            }
            else continue;
        }
        return ans;
    }
}

void HANGOVER(){
while(1){
        float x; cin >> x;
        if(x==0.00)
            break;
        
        float s=0.00;
        for(int i=1 ;  ; i++){
            float temp = s;
            s+=(1.00/(1.00+i));
            if(s >= x){
                cout << i << " card(s)" << endl;
                break;
            }
        }
    }
    
}

bool comp(pair<pair<int,int>,int> a1  , pair<pair<int,int>,int> a2){
    return a1.ss > a2.ss;
}

int32_t main(){
    __;
    return 0;
}