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

bool func(string s1 , string s2){
    int l1=10; int l2=5;
    rep(i , 0 , l1-l2){
        string s3 = s1.substr(i , l2);
        if(s3.compare(s2)==0)
            return true;
    }
    return false;
}

void spoj_SBSTR1(){
    int t = 24; cin >> t;
    while(t--){
        string s1,s2; cin >> s1 >> s2;
        if(func(s1,s2))
            cout << 1 << endl;
        else cout << 0 << endl;
    }
}

void CF112_D2_A(){
    string s1 , s2; cin >> s1 >> s2;
    rep(i , 0 , s1.length()){
        if(s1[i] < 97)
            s1[i]+=32;
        if(s2[i] < 97)
            s2[i]+=32;
    }   
    sort(s1.begin() , s1.end());
    sort(s2.begin() , s2.end());

    rep(i , 0 , s1.length()){
        if(s1[i] > s2[i]){
            cout << 1 << endl;
            break;
        }
        else if(s1[i] < s2[i]){
            cout << -1 << endl;
            break;
        }
        if(i==s1.length()-1){
            cout << 0 << endl;
            break;
        }
    }
}

void CF236_D2_A(){
    string s; cin >> s;
    set<char>d;
    rep(i , 0 ,s.length()){
        d.insert(s[i]);
    }

    if(d.size()%2==0){
        cout << "CHAT WITH HER!" << endl;
    }
    else cout << "IGNORE HIM!" << endl;
}

void CF59_D2_A(){
        string s; cin >> s;
    int c1=0;
    int c2=0;
    // A--65
    // a--97
    rep(i , 0 , s.length()){
        if(s[i] >= 97)
            c2++;
        else c1++;
    }
    if(c1 > c2){
        rep(i , 0 , s.length()){
            if(s[i] >= 97)
                s[i]-=32;
        }
    }
    else{
        rep(i , 0 , s.length()){
            if(s[i] > 65 && s[i] < 97 ){
                s[i] = s[i]+32;
            }
        }
    }
    cout << s << endl;    
}

void CF344_D2_A(){
    int n; cin >> n;
    string s = "";
    string s1;
    rep(i , 0 , n){
        cin >> s1;
        s+=s1;
    }
    int c=1;
    rep(i , 0 , s.length()-1){
        if(s[i+1]==s[i])
            c++;
    }
    cout << c << endl;
}



int32_t main(){
    __;	
   
}