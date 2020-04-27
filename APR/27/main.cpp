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

// int a[100001];

void CF_637_D2_A(){
    w(t){
        int n,a,b,c,d;
        sd(n);
        sd4(a,b,c,d);
        int ans=1;
        if(n*(a+b) < c-d || n*(a-b) > c+d)
            ans=0;
         if(ans)
             cout <<"Yes" << endl;
         else cout << "No" << endl;
    }
// instead of looping, check if the values intersect by considering them as line segments    
}

int peak(int a[] , int i){
    if(a[i-1] < a[i] && a[i+1] < a[i])
        return 1;
    return 0;
}

void CVOTE(){
int n,m;
    sd2(n,m);
    unordered_map<string , string> countries;
    FOR(i, 0 , n){
        string s1,s2;
        cin >> s1 >> s2;
        countries.insert(make_pair(s1,s2));
    }
    int max_chef=0;
    int max_country=0;
    string chef;
    string country;
    unordered_map<string ,int > count_country;
    unordered_map<string , int> count_chef;
    FOR(i , 0 , m){
        string s; cin >> s;
        count_chef[s]++;
        string s1 = countries.find(s)->second; count_country[s1]++;
        if(count_chef[s] > max_chef || (count_chef[s]==max_chef && s < chef)){
            max_chef = count_chef[s];
            chef = s;
        }
        if(count_country[s1] > max_country || (count_country[s1]==max_country && s1 < country)){
            max_country = count_country[s1];
            country = s1;
        }
    }
    
    cout << country << endl;
    cout << chef << endl;

}


int32_t main(){
    __;	
    
    return 0;
}  