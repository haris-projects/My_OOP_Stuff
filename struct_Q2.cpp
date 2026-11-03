#include<iostream>
using namespace std;
struct package {
  int id ;
  float weight;
  int destination;

};
int main(){

    package p1[1];
    package *p=p1;
    int i ;
    cout<<"give your inputs";
    for(i=0 ; i<1 ; i++){
        cin>>p->destination;
        cin>>p->id;
        cin>>p->weight;
    }


    cout<<"print your elements";
    for(i=0 ; i<1 ; i++){
         cout<<p->destination;
        cout<<p->id;
        cout<<p->weight;

    }


    return 0 ;
}