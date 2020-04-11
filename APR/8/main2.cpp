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
#define rep(i,a,b)         for(int i=a;i<b;i++)
#define repb(i,a,b)     for(int i=a;i>=b;i--)
#define endl            "\n"
#define m(a)            memset(a,0,sizeof(a))

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

    string s;
    int ans, x , pos;
    char ch;

    int n,q;

const int MAX = 1000;
int BIT[MAX][30];

int query(int x, int j){
    int s=0;
    while(x>0){
        s+=BIT[x][j];
        x-=(x&-x);
    }
    return s;
}

int update(int x , char ch , int val){
    while(x <=n){
        BIT[x][ch-'a'] += val;
        x+=(x&-x);
    }
}


int32_t main(){    
    __;
    
    cin >> n >> q;
    cin >> s;
    s = '@'+s;
    for(int i=1 ; i<n+1 ; i++){
        update(i , s[i] , 1);
    }

    while(q--){
        cin >> x;
        if(x==0){
            cin >> pos >> ch;
            update(pos , s[pos] , -1);
            s[pos] = ch;
            update(pos , s[pos]  ,1);
        }
        else{
            ans=0;
            int l,r,k;
            cin >> l >> r >> k;

            if(r-l+1 <k){
                cout << "Out of range" << endl;
                continue;
            }

            else{
                for(int j=0 ; j<26;  j++){
                    ans += (query(r,j) - query(l-1,j));
                    if(ans>=k){
                        cout << char(j+'a') << endl;
                        break;
                    }
                }
            }
        }
    }
}