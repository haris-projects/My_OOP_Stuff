#include<iostream>
using namespace std;

int main(){
  int *p ;
  int *q ;
 p=new int(8);
 q=new int(9);
 q=p ;
 delete p ;
  cout<<*q<<endl;

    return 0 ;
}  