#include<bits/stdc++.h>
using namespace std;

/*
~ tutorial problem
	https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/
*/

#define __              ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void file(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	#endif
}

#define sd(x) cin >> x;
#define sd2(x,y) cin >> x >> y;
#define sd3(x,y,z) cin >> x >> y >> z;
#define sd4(w,x,y,z) cin >> w >> x >> y >> z;

bool is_pal(string s) {return equal(all(s), s.rbegin());}

int mypow(int a, int b , int mod){        //(logn) fast exponentiation
    int res = 1;            // call int x = mypow(2,5);
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return (res%mod);
}

/*
	NUMBER THEORY 1
	1. Modular Arith
	2. Exponentiation
	3. GCD euclidian
	4. Extended euclidian
	5. Mod inverse
*/

/*
MOD Arithematic..
	1. (a-b)%mod = (a%mod -b%mod + mod)%mod;
	2. x%mod lies in [0 , mod-1];

Mod Inverse:


MOD exponentiation..

	mod(int x , int y){
		res=1;
		while(y > 0){
			if(y => odd)	res = (res*x)%mod;
			else if(y => even)	x = (x*x)%mod and y = y/2;
			return res
		}
	}

GCD...

	1. gcd(x,y) < x && gcd(x,y) < y

	2. 	NAIVE...
		for(int i = min(x,y) ; i>=1 ; i--)
			if(x%i==0 && y%i==0) gcd = i;
		return gcd;
		
		NOTE: gcd(x,y)<=min(x,y)

	3.	gcd(x,y) = gcd(y,x%y) and gcd(x,0) = x;
		
EXTENDED GCD..
	1. GCD(A,B) = Ax + By, find x and y;
	2. {d,x,y} = {gcd, coeff(A) , coeff(B)};

MOD INV
	1. apply extended gcd , ext_gcd(x , mod) and return x(may be -ve)
	2. Apply fermats little theorem, only if mod is prime.
*/

int d,x,y;
void extend_gcd(int a , int b){
	if(b==0){
		d=a;
		x=1;
		y=0;
	}
	else{
		extend_gcd(b , a%b);
		int temp = x;
		x = y;
		y = temp-(a/b)*y;
	}
}

int modInverse(int a ,int mod){
	extend_gcd(a , mod);
	return (x%mod + mod)%mod;
}

int modinv(int a , int mod){
	// using fermats little theorem, when mod is prime
	return mypow(a , mod-2 , mod);
}

int32_t main(){
	__;
	file();
	int a,b,c,m; sd4(a , b ,c ,m);
	int ans1 = mypow(a , b , m)%m;
	int ans2 = modInverse(c , m)%m;
	cout << (ans1*ans2)%m << endl;
	return 0;
}




