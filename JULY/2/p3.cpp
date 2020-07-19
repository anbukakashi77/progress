#include<bits/stdc++.h>
using namespace std;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii              pair<int,int>
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
#define all(x)                          begin(x), end(x)

void fastscan(int &x){
bool neg = false;register int c;
x = 0;c = getchar();
if(c=='-'){neg = true;c = getchar();}
for(; (c>47 && c<58); c=getchar()){x = x *10 + c - 48;}
if(neg){x *= -1;}}

void file(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
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

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
#define deb3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<endl

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

void print_1(){
cout << "........" << endl;
cout << "........" << endl;
cout<<"........"<<endl;
cout<<".XXX...."<<endl;
cout<<".XOX...."<<endl;
cout << ".XXX...."<<endl;
cout << "........"<<endl;
cout << "........"<<endl;
cout << endl;
}

void print_5(){	
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"XXX....."<<endl;
cout<<"..XX...."<<endl;
cout<<"O..X...."<<endl;
cout << endl;
}
void print_9(){
cout<<"........"<<endl;
cout<<".XXXXXXX"<<endl;
cout<<".X.O...X"<<endl;
cout<<".X...XXX"<<endl;
cout<<".XXX.X.."<<endl;
cout<<"...XXX.."<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout << endl;

}
void print_64(){
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"...O...."<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout<<"........"<<endl;
cout << endl;
}
int32_t main(){	
	__;
	file();
	w(t){
		int k;sd(k); int a[8][8];
		if(k==1) print_1();
		else if(k==5) print_5();
		else if(k==9) print_9();
		else if(k==64) print_64();
		else{
			int movable=k-1;
			for(int i=0 ; i<8; i++){
				for(int j=0 ; j<8 ; j++){
					if(!i and !j) cout <<"O";
					else{
						if(movable > 0){
						cout << "."; movable--;	
						} 
						else cout << "X";
					}
				}
				cout << endl;
			}
		cout << endl;
		}
	}
	return 0;
}




