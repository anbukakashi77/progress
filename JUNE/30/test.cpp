#include<bits/stdc++.h>
using namespace std;

namespace test{
	//to overload functions and
	//seperate them using namespaces..
	//std::cout is different from test::cout..
//	int cout(){
//		return 1+2;
//	}
}

//templatising..=> overloading data types..
template<typename T>
void swap(T &x , T &y){
	T temp = x;
	x=y;
	y = temp;
}

//structs..
struct Pranjal{
	int x;
	//constructor..=> all things are public by default..
	Pranjal(){
		x=10;
	}
	//put the shit below in main to instantiate constructor..
	//Pranjal test;
	//cout << test.x << endl;
};

//classes..
class Pranjal_class{
	//class => all members are private by default..
public:
	int x=10;
	int y=10;
};

int main(){
	Pranjal_class p1;
	cout << p1.x << endl;
	return 0;
}

