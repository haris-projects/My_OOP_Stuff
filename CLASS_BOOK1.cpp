#include<iostream>
using namespace std;
class Book{
    private:
    int pages;
    float price;
    public:
    Book(int p , float pr) : pages(p) , price(pr){
    }
    void display();
    ~Book(){
        cout<<"Book Object Destroyed"<<endl;
    }
};
void Book::display(){
    cout<<"Total Pages are : "<<pages<<endl;
    cout<<"Total Price of the Book is : "<<price<<endl;
}


int main(){

int page;
float pri;
cout<<"Enter Total no of pages ";
cin>>page;

cout<<"Enter Total Price ";
cin>>pri;

Book *b1=new Book(page,pri);
b1->display();

delete b1;
b1=nullptr;

    return 0 ;
}