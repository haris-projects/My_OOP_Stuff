#include<iostream>
using namespace std;

 class GYM{
    private:
    string name;
    static int count;
    static int totalfee;
    public:
    void show();
    GYM(string n , int t): name(n) {
        count++;
        totalfee+=t;
    }
 };

 int GYM::count=0;
 int GYM::totalfee=0;

  void GYM::show(){
     cout<<"Show total no of partucipents : "<<count<<endl;
    cout<<"Name of the Participent : "<<name<<endl;
    cout<<"Show total fee of GYM : "<<totalfee<<endl;
    cout<<endl;
  }

int main(){
GYM g1("HARIS IQBAL",3000);
g1.show();
GYM g2("ABDUL MUNIM",3300);
g2.show();
GYM g3("KHAN",3400);
g3.show();
GYM g4("AKBAR KHAN",3450);
g4.show();







    return 0 ;
}