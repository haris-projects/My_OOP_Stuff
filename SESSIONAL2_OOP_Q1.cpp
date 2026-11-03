#include<iostream>
using namespace std;

class Animals{
    protected:
    string name;
    double price;
    public:
    Animals(string n , double p):name(n),price(p){  }
};

class Dog: protected Animals{
    private:
    string breed;
    public:
    Dog(string breed , string na , double pr):Animals(na,pr){
        this->breed=breed;
    }
    void display();
};
void Dog::display(){
    cout<<"Animal Breed : "<<breed<<endl;
    cout<<"Animal name : "<<name<<endl;
    cout<<"Animal Price : "<<price<<endl;
}

class Bird:protected Animals{
    private:
    float wingspan;
    public:
    Bird(string nam , double pric , float wingspan):Animals(nam , pric){
        this->wingspan=wingspan;
    }
    void display();

};
void Bird::display(){
    cout<<"Bird Name : "<<name<<endl;
    cout<<" Bird Price : "<<price<<endl;
    cout<<"Bird Wingspan : "<< wingspan<<endl;
}
int main(){

    Dog d1("Pit bol"," Doggy" , 20000);
    d1.display();
    Bird b1("Falcon" , 300000 , 1.5);
    b1.display();



    return 0 ;
}