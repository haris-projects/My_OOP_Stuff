#include<iostream>
using namespace std;
 
struct product{
 
    string name;
    int price ;
    int quantity;
};

int totalstock(product *p,int  size){

    int total=0 ;
    int i ;
    for(i=0 ; i<size ; i++){
        total+=p->price+p->quantity;
    }

    return total ;
}

int main(){
    int size , i ;
    cout<<"Enter size of the structure Array  ";
    cin>>size ;

    product p1[size];
    string name ;
    int price ;
    int quantity;
   cout<<"Enter the product Array Elements "<<endl;
    for(i=0 ; i<size ; i++){
        
        cin.ignore();
        cout<<"Enter "<<i+1<<" Product Name :";
        getline(cin,p1[i].name);
        cout<<"Enter "<<i+1<<" Product Price :";
        cin>>p1[i].price;
        cout<<"Enter "<<i+1<<" Product Quantity :";
        cin>>p1[i].quantity;
    }
    
    cout<<"The Total is :"<<totalstock(p1 , size)<<endl;

    return 0 ;
}