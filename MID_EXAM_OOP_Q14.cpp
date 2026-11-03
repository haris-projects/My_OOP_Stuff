#include<iostream>
using namespace std;


class A{
    private:
    int *num;
   public:
   A(int a){
    num=new int ;
    *num=a;
   }
   A(const A &other){
    num=new int ;
    *num=*other.num;
   }
   void setter(int ax){
    
    *num=ax;

   }
   int getter(){
    return *num;
   }
   ~A(){
    delete num;
    num=nullptr;
   }
   
};

int main(){

   A a1(4);
   A a2(a1);
   
  cout<<a1.getter()<<endl;
  a2.setter(90);
  cout<<a2.getter()<<endl;  
  cout<<a1.getter()<<endl;
  cout<<a1.getter()<<endl; 
    return 0 ;
}



