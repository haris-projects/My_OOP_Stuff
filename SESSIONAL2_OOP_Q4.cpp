#include<iostream>
using namespace std;

class Cart{
    private:
    int *capicity;
    static int count;
    string name;
    static int getAlive();
    public:
    void additems();
    void updateItems(int index , int newPrice);
    int total() const;
    Cart(string name, int cap){
         capicity=new int[cap];
         this->name=name;
    }


    // deep copy constructor
    Cart(Cart const&other){

    }

    ~Cart(){
        delete capicity;
        capicity=nullptr;
        cout<<" Cart no "<<count<<" Deleted"<<endl;
    }
};
void Cart::additems(){
    int i ;
    for()
}
int Cart::count=0;
void applyCoupon(Cart c);
void applyCoupenRef(Cart &c);
int main(){



    return 0 ;
}