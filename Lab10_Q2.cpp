#include<iostream>
using namespace std;

class PaymentMethod{
    protected:
    string audit;
    PaymentMethod(string a):audit(a){
        cout<<"[Base Class Constructor] Instiallised"<<endl;
     }
    public:
    virtual void transcational_audit()=0;
    
    virtual~PaymentMethod(){
        cout<<"Base Class Destroyed"<<endl;
    }
};
class CreditPayment:public PaymentMethod{
    private:
    string *str;
    public:
    CreditPayment(string info):PaymentMethod("Derived class Call"+info){
        cout<<"[CreditPayment] Constructor Is Call"<<endl;
        str=new string(audit);
    }
    void transcational_audit(){
        cout<<*str<<endl;
    }
    ~CreditPayment(){
        delete str ;
        cout<<"[CreditPayment] is destroyed"<<endl;
    }
};
class PayPalPayment:public PaymentMethod{
    private:
    string *strr;
   public:
   PayPalPayment(string info):PaymentMethod(info+"PayPalPayment Created"){
    cout<<"PayPalPayment Class Create"<<endl;
    strr=new string (audit);
   }
    void transcational_audit(){
        cout<<*strr<<endl;
    }
   
   ~PayPalPayment(){
    cout<<"PayPalPayment is Destroyed"<<endl;
    delete strr;
   }

};
int main(){

    cout<<"MAIN CREATED"<<endl;
PaymentMethod *p[2];
p[0]=new CreditPayment("XYZ ALPHA");
p[1]=new PayPalPayment("XYZ BETA");
int i ;
for(i=0 ; i<2 ; i++){
    p[i]->transcational_audit();
}
for(i=0 ; i<2 ; i++){
    delete p[i];
}
cout<<"MAIN DESTROYED"<<endl;
    return 0 ;
}