#include<iostream>
using namespace std;

  class Car{
  	public:
  	static int totalcars;
  	Car(){
  		totalcars++;
	  }
	 void  show(){
	  	cout<<"show Total Cars : "<<totalcars<<endl;
	  }
  	
  };
  int Car::totalcars=0 ;


int main(){
	
	cout<<"The total Cars is : "<<Car::totalcars<<endl;
	Car c1;
	Car c2;
	Car c3;
		cout<<"The total Cars is : ";
		c1.show();

	
	return 0;
}
