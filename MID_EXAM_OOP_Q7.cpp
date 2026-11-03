#include<iostream>
using namespace std;

class Parcel{
    private:
    double weight;
    double rate;
    double calcCost()const{
        return weight*rate;
    }
    public:
    void setWeight(double weight);
    void setRate(double rate) ;
    void ShowBill()const;
};
void Parcel::setWeight(double weight){
    if(weight<0){
        cout<<"Error: Invalid weight!"<<endl;
    }
    else 
   this->weight=weight;
}
void Parcel::setRate(double rate){
     if(rate<0){
        cout<<"Error: Invalid Rate!"<<endl;
    }
    else 
    this->rate=rate;
}

void Parcel::ShowBill()const {
    cout<<"Total Weight : "<<weight<<" kg"<<endl;
    cout<<"Total Rate : "<<rate<<" per/kg"<<endl;
    cout<<"Total Cost : "<<calcCost()<<" Ruppess"<<endl;
}

int main(){

    Parcel *p=new Parcel;
    p->setWeight(10);
    p->setRate(40);
    p->ShowBill();

    p->setWeight(-3);
    p->ShowBill();

    delete p;
    p=nullptr;

    return 0 ;
}