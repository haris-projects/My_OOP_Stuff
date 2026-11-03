#include<iostream>
using namespace std;

class Room{
    private:
    double length;
    double width;
    public:
    void setlength (double length);
    void setwidth(double width);

    double getlength()const{
        return length;
    }

    double getwidth()const{
        return width;
    }
    double getarea();
    void Display()const;
};
void Room::setlength(double length){
    if(length<=0){
        cout<<"Error! length"<<endl;
        return ;
    }
    else 
    this->length=length;
}
void Room::setwidth(double width){
    if(width<=0)
    cout<<"Error! Invalid width"<<endl;
    this->width=width;
}

double Room::getarea(){

    return length*width;

}
void Room::Display()const {
  cout<<"the Length is : "<<length<<endl;
  cout<<"THe Width is : "<<width<<endl;
}
int main(){

Room r1;
double length , width;
cout<<"Enter Length : ";
cin>>length;
cout<<"Enter Width : ";
cin>>width;

r1.setlength(length);
r1.setwidth(width);
r1.getlength();
r1.getwidth();
r1.Display();
cout<<"The area is "<<r1.getarea();
cout<<endl;
    return 0 ;
}