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

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
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
#define sortv(v)        sort(v.begin() , v.end())
#define rsortv(v)       sort(v.rbegin() , v.rend())
#define pw(b,p)         pow(b,p) + 0.1
#define __          	   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i,a,b)	   for(int i=a;i<b;i++)
#define repb(i,a,b) 	   for(int i=a;i>=b;i--)
#define endl			   "\n"    

void file(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    #endif
}


const int N = 100000;
int a[N];
int st[4*N];

void Build_min(int si , int ss , int se){
    if(ss==se){
        st[si] = a[ss];
        return;
    }

    int mid = (ss+se)/2;

    Build_min(2*si+1 , ss , mid);
    Build_min(2*si + 2 , mid+1 , se);

    st[si] = max(st[2*si+1] , st[2*si+2]);
}


int rmq(int si , int ss , int se , int qs , int qe){
    if(qs > se || qe < ss)      //completely outside
        return INT_MIN;

    if(ss >= qs && se <= qe)    //completely inside
        return st[si];

    int mid = (ss+se)/2;
    int l = rmq(2*si+1, ss , mid , qs , qe);
    int r = rmq(2*si+2 , mid+1 , se , qs , qe);

    return max(l,r);
}


void caravans(){
    // https://www.codechef.com/LRNDSA01/problems/CARVANS
     w(t){
        int n; cin >> n;
        vi v(n); rep(i , 0 , n) cin >> v[i];
        int c=1;
        if(n==1){
            cout << c << endl;
            continue;
        }
        else{
            rep(i , 0 , n-1){
                if(v[i+1] > v[i]){
                    v[i+1]=v[i];
                }
                else c++;
            }
        }
        cout << c << endl;
    }    
}

void fctrl(){
    // https://www.codechef.com/LRNDSA01/problems/FCTRL
    w(t){
        int n; cin >> n;
        int c=0;
        int x=n;
        int f=0;
        for(int i=1 ; ; i++){
            c+=(floor(x/pow(5,i)));
            if(x/pow(5,i) == 0)
                break;
        }
        cout << c << endl;
    }
}

void CONFLIP(){
    w(t){
    int N; cin >> N;
    while(N--){
        // 0 - H and 1-T
        int s,n,q; cin >> s >> n >> q;
        int h;
        if(s==1){
            h = n-(n+1)/2;
        }
        else{
            h = (n+1)/2;
        }
        if(q==1){
            cout << h << endl;
        }
        else cout << n-h << endl;
    }    
    }
}

void LADDU(){
    w(t){
        int n; cin >> n; string s; cin >> s;
        int l=0;
        while(n--){
            string s1;
            cin >> s1;
            if(s1=="CONTEST_WON"){
                int r; cin >> r;
                if(r>=20)
                    l+=300;
                else l += 300+(20-r);
            }
            else if(s1=="TOP_CONTRIBUTOR"){
                l+=300;
            }
            else if(s1=="BUG_FOUND"){
                int sev; cin >> sev;
                l+=sev;
            }
            else if(s1=="CONTEST_HOSTED"){
                l+=50;
            }
        }
        int c=0;
        if(s=="INDIAN"){
            cout << floor(l/200) << endl;                           
        }
        else{
            cout << floor(l/400) << endl;
        }
    }
}

void CF427_D2_A(){
    //did i just see 70 test cases ??
    int n; cin >> n;
    vi v(n);
    rep(i , 0 , n)
        cin >> v[i];
    stack<int>s;
    int cops=0;
    int ans=0;

    rep(i , 0 , n){
        if(v[i]!=-1){
            cops+=v[i];
        }

        if(v[i]==-1 && cops > 0){
            cops--;
        }
        else if(v[i]==-1 && cops <= 0){
            ans++;
        }    
    }
    cout << ans << endl;
}

void IIITD_Mtech(){
    //didnt realise that ill have to reg
    w(t){
        int n,q; cin >> n >> q;
        rep(i , 0 , n) cin >> a[i];
        Build_min(0,0,n-1);
        while(q--){
            int x; cin >> x;
            cout << rmq(0,0,n-1,0,x-1) << endl;
        }
    }
}

void STFOOD(){
    //read the problem better fool
    w(t){
        int n; cin >> n;
        int ans=0;
        rep(i , 0 , n){
            int s,v,p;
            cin >> s >> p >>v;
            ans = max(ans , v*(int)floor(p/(s+1)));
        }
        cout << ans << endl;
    }
}

int32_t main(){
    __;
    
    return 0;
}