#include<iostream>
using namespace std;

struct Stock{
    int quantity;
    int shelfno;
};

struct Product{
    string name;
    int price ;
    Stock s1;
};

void ShowStock(Product*p1 , int n){
    int i ;
    cout<<"Low stock Products :"<<endl;
    for(i=0 ; i<n ; i++){
        if(p1[i].s1.quantity<5 && p1[i].s1.quantity>0){
         cout<<p1[i].name<<" , Qty : "<<p1[i].s1.quantity <<"  Shelf no : "<<p1[i].s1.shelfno<<endl;
        }
        else if(p1[i].s1.quantity>=5)
        cout<<" Proudct " << i << " are Sufficiently Stocked"<<endl;
        else if (p1[i].s1.quantity<=0){
            cout<<"ErrorR";
            exit;
        }

    }
}

int main(){
    int size;
    cout<<"Enter size ";
    cin>>size;
    Product *p1=new Product[size];
  cin.ignore();
   for (int i=0 ; i<size ; i++){
    
    cout<<"Enter Product Name : ";
    getline(cin,p1[i].name);
    cout<<"Enter Price of the Product : ";
    cin>>p1[i].price;
    cout<<"Enter Quantity of Product : ";
    cin>>p1[i].s1.quantity;
    cout<<"Enter Shelf no : ";
    cin>>p1[i].s1.shelfno;
    cin.ignore();
   }
   ShowStock(p1 , size);

   delete [] p1;
   p1=nullptr;

    return 0 ;
}