#include<iostream>
using namespace std;
class Book{
    private :
    string title;
    string author;
    string isbn;
    int num ;
    int khan(){
        return  num+3 ;
    }

    public:
    Book(int n){
    num=n ;
    }
    int nm(){
        return khan()+5;
    }
    
};

int main(){

Book b1(12);
cout<<b1.nm()<<endl;

    return 0 ;
}