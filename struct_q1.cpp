<<<<<<< HEAD
=======
#include<iostream>
using namespace std;

struct book{
    string title ;
    string author ;
    float price ;

};

void apply_discount(book &b , float prct){
    cout<<"Enter percentage value : ";
    cin>>prct;

    prct=b.price*(prct/100);
    b.price-=prct ;

}

int main(){

 book b1 ;
 float prct;
 cout<<"========================================"<<endl;
 cout<<"Enter title of the book : ";
 getline(cin,b1.title);
 cout<<"Enter Author of the book : ";
 getline(cin,b1.author);
cout<<"Enter Price of the book : ";
cin>>b1.price;
cout<<"========================================"<<endl;
cout<<"The Title of the book is : "<<b1.title<<endl ;

cout<<"The  of  Author the book isM: "<<b1.author<<endl ;

cout<<"The Price  of the book before Discount : "<<b1.price<<endl ;

cout<<"========================================"<<endl;

apply_discount(b1,prct);

 cout<<"The Price  of the book After Discount : "<<b1.price<<endl ;

cout<<"========================================"<<endl;
cout<<"========================================"<<endl;
    return 0 ;
  
}
>>>>>>> b2f4a8f (New)
