#include<iostream>
using namespace std;
struct Memory{
    long long ssd;
    long long ram;
};
struct Laptop{
    string brand;
    double price;
    int warranty;
    Memory memory;
};
 
 Laptop *getBestDeal(Laptop* lp,int n){
    int i;
    Laptop *i2;
    float num=0;
    float ratio=0 ;
   
    
    for(i=0 ; i<n ; i++){
    ratio=lp[i].memory.ssd/lp[i].price;
    if(lp[i].warranty>=2){
        if(ratio>num)
        i2=&i ;
    }
    else {
        return nullptr;
    }
     
    }
    return i2 ;
 }

int main(){
    int n ;
    cout<<"Enter n value : ";
    cin>>n ;
Laptop *lp=new Laptop[n];

int i ;

for(i=0 ;i<n ; i++){
    cout<<"Enter Laptop Brand";
    getline(cin,lp[i].brand);
    cout<<"Enter Price of Laptop : ";
    cin>>lp[i].price;
    cout<<"Enter Latop Warranty ";
    cin>>lp[i].warranty;
    cout<<"Enter Laptop SSD : ";
    cin>>lp[i].memory.ssd;
    cout<<"Enter Laptop RAM : ";
    cin>>lp[i].memory.ram;
}

Laptop*p=getBestDeal(lp,n);

cout<<"Best Deal: "<<lp[]





    return 0 ;
}