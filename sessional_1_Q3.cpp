#include<iostream>
using namespace std;

struct  Publication{
    int Year ;
    float price ;
};
struct Book{

    string title;
    string author;
    Publication p1;
};

int main(){
    int n , i , count=0;
    cout<<"Enter value of N : ";
    cin>>n ;
    Book *b1=new Book[n];

for(i=0 ; i<n ; i++){
    cin.ignore();
    cout<<"Enter Book "<<i+1<< " title "<<endl;
    getline(cin,b1[i].title);
    cout<<"Enter Book "<<i+1<<" Author "<<endl;
    getline(cin,b1[i].author);

    cout<<"Enter Book "<<i+1<<" Published Date"<<endl;
    cin>>b1[i].p1.Year;
    cout<<"Enter Price of the "<<i+1<<" Book"<<endl;
    cin>>b1[i].p1.price;
}

for(i=0 ; i<n ; i++){
if(b1[i].p1.Year>2015)
    count++;
}
for(i=0 ; i<n ; i++){
    cout<<"The Book "<<i+1<< " title : "<<b1[i].title<<endl;
    
    cout<<"The Book "<<i+1<<" Author : "<<b1[i].author<<endl;
    

    cout<<"The Book "<<i+1<<" Published Date : "<<b1[i].p1.Year<<endl;
    
    cout<<"The Price of the "<<i+1<<" Book : " <<b1[i].p1.price<<endl;
}

cout<<"The total no of Books That are Published after 2015 : "<<count<<endl;

delete [] b1;
b1=nullptr;

    return 0 ;
}