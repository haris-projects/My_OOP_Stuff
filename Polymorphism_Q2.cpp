#include<iostream>
using namespace std;

   class Animal{
    private:
    string name;
    public:
    virtual void Speak()=0 ;
    Animal(){ 
        cout<<"Animal Obj Created"<<name<<endl;
    }

     virtual ~Animal(){
        cout<<"Animal obj Destroye"<<endl;
    }
};
class Dog : public Animal{
    private:
    string nam;
    public:
    Dog(string n):nam(n){
        cout<<"Dog Child is created"<<endl;
    }
    void Speak(){
        cout<<"Dog Name : "<<nam<<endl;
    }
    ~Dog(){
        cout<<"Dog Destroyed"<<endl;
    }
};
class Cat:public Animal{
    private:
    string na;
    public:
    Cat(string n) : na(n) { 
        cout<<"cat Obj Created"<<endl;
     }
    void Speak(){
        cout<<"Cat Name : "<<na<<endl;
    }
    ~Cat(){
        cout<<"Cat Destroyed"<<endl;
    }
};




int main(){
    
    Animal *a1=new Dog("Rex");
    Animal *a2=new Cat("Tom");
    a1->Speak();
     a2->Speak();
    delete a1;
    delete a2;
} 