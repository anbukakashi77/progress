/*	Author
@ Pranjal Walia
IIIT Bangalore
*/

// dates 17 and 16

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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
 

void PSHOT(){
    //codechef
w(t){
        int n; cin >> n;
        string s; cin >> s;
        int i;

        int s1=0;
        int s2=0;
        int m2;
        int m1=m2=s.length()/2;
        int x=0;

        for(i=0 ; i<s.length() ; i++){
            if(i%2==0){
                m1--;
                if(s[i]=='1')
                    s1++;
            }
            else{
                m2--;
                if(s[i]=='1')
                    s2++;
            }
            if(s1-s2 > m2 || s2-s1 > m1){
                x=1;break;
            }
        }
        if(x==1)
            cout << i+1 << endl;
        else cout << i << endl;
    }
    
}

int findmin(vi v,int n){
    int m = v[0];
    int idx=0;
    rep(i , 0 , n){
        if(v[i] < m){
            m = v[i];
            idx=i;
        }
    }
    return idx;
}

void STUPMACH(){
    //codechef
    //partial correct
    w(t){
        int n; cin >> n;
        vi v(n); rep(i , 0 , n)cin >> v[i];
        int ans=0;
        int idx = findmin(v,n);
        ans += (n * v[idx]);
        rep(i , 0 , n){
            v[i]-=v[idx];
        }
        while(1){
            if(findmin(v,idx)==0){
                ans+=v[0];
                break;
            }
            idx = findmin(v,idx);
            ans+=((idx+1)*v[idx]);
            rep(i , 0 , idx){
                v[i]-=v[idx];
            }
        }
        cout << ans << endl;        
    }
}

void COMPILER(){
    //codechef
w(t){
        string str; cin >> str;
        int ops=0;
        int r=0;
        int ans=0;

        rep(i , 0 , str.length()){
            if(str[i]=='<')
                ops++;
            else ops--;
            if(ops<0)
                break;
            if(ops==0){
                ans = i+1;
            }    
        }
        cout << ans << endl;
    }    
}

void CARSELL(){
    //codechef
    w(t){
        int n; cin >> n;
        vi v(n);
        rep(i , 0 , n)
            cin >> v[i];
        int ans=0;
        rsortv(v);
        rep(i , 0 , n){
            if(v[i]-i<=0)
                continue;
            ans+=((v[i]-(i))%mod);
        }
        cout << ans%mod << endl;
    } 
}

void UNITGCD(){
    //codecehf
w(t){
        int n; cin >> n;
        if(n==1){
            cout << 1 << endl; cout << "1 1" << endl;
            continue;
        }
        if(n==2){
         cout << 1 << endl; cout << 2 << " 1 2" << endl;
            continue;
        }

        else if(n%2==0){
            cout << n/2 << endl;
            int curr = 1;
            rep(i , 1 , n/2+1){
                cout << "2 " << curr << " " << curr+1 << endl;
                curr+=2;
            }
        }
        else if(n%2!=0){
            cout << n/2 << endl;
            int curr=1;
            rep(i , 0 , n/2+1 ){
                if(i==0){
                    cout << "3 " << curr << " " << curr+1<< " " << curr+2 << " "<< endl;
                        curr+=3;
                }
                else{
                    cout << "2 " << curr<< " " << curr+1<<" " << endl;
                        curr+=2;
                }
            }
        }
    }
}

void CF_PI_D2_A(){
    //cf + imp
 int n; cin >> n; int a[n+1];
    rep(i ,0 , n) cin >> a[i];

    cout << abs(a[0]-a[1]) << " " << abs(a[n-1]-a[0]) << endl;
    rep(i , 1 , n-1){
        cout << min(abs(a[i-1]-a[i]) , abs(a[i+1]-a[i])) << " "
        << max(abs(a[i]-a[0]) , a[n-1]-a[i]) << endl;
    }
    cout << abs(a[n-1]-a[n-2]) << " " << abs(a[n-1]-a[0]) << endl;
}

bool comp(pii a , pii b){
    return a.ss < b.ss;
}

void CF_PI_B(){
    set<int>s;
    int ans=0;
    int curr=0;

    int n; cin >> n;
    while(n--){
        char c; int x;
        cin >> c >> x;
        if(c=='+'){
            s.insert(x);
            curr++;
            ans = max(ans,curr);
        }
        else{
            if(s.count(x)){
                s.erase(x);
                curr--;
            }
            else{
                ans++;
            }
        }
    }    
    tr(ans);
}

bool func(int x,int n,int m){
    int t = x;
    if(x > 20){
        while(n--){
        t = (int)(floor(t/2))+10;
        if(t<=0)
            return true;
    }
    while(m--){
        t-=10;
        if(t<=0)
            return true;
    }
    return false;
    }
    else{
     while(m--){
        t-=10;
        if(t<=0)
            return true;
    }
        return false;
    }
}

void CF_635_D2_B(){
w(t){
        int x,n,m;
        cin >> x >> n >> m;
        if(func(x,n,m))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

void CF_635_D2_A(){
w(t){
        int a,b,c,d; cin >> a >> b >> c >> d;
        tr3(b,c,c);    
    }
}

int32_t main(){
    
    return 0;
}
