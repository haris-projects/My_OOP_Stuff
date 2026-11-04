#include<iostream>
using namespace std;

struct Contactinfo{
    long long  phone;
    string city;
}; 
struct  Ownername{
    string name ;
Contactinfo c1;
};
 struct Account{
   
    int accountno;
    int balance ;
    Ownername o1;

 };

int main(){
    int n ;
    cout<<"Enter value of N ";
    cin>>n ;
Account *a1=new Account[n];
int count=0;

int i ;
for(i=0 ; i<n ;i++){
    cout<<"Enter Account no of Person "<<i+1<<endl;
    cin>>a1[i].accountno;
    cout<<"Enter Balance "<<endl;
    cin>>a1[i].balance;
    cin.ignore();
    cout<<"Enter "<<i+1<<" Owner name "<<endl;
    getline(cin,a1[i].o1.name);
    cout<<"Enter Owner "<<i+1<<" Phone No "<<endl;
    cin>>a1[i].o1.c1.phone;
    cout<<"Enter City of the Owner "<<i+1<<endl ;
    cin>>a1[i].o1.c1.city;
}

for(i=0 ; i<n ;i++){
    cout<<" Enter Account no of Person "<<i+1<<endl;
    cout<<a1[i].accountno<<endl;
    cout<<"Enter Balance "<<endl;
    cout<<a1[i].balance<<endl;
    cout<<"Enter "<<i+1<<" Owner name "<<endl;
    cout<<a1[i].o1.name<<endl;
    cout<<"Enter Owner "<<i+1<<" Phone No "<<endl;
    cout<<a1[i].o1.c1.phone<<endl;
    cout<<"Enter City of the Owner "<<i+1<<endl ;
    cout<<a1[i].o1.c1.city<<endl;
    if(a1[i].o1.c1.city=="lahore")
    count++;
}
cout<<"The total no of people that Belongs from Lahore is "<<count<<endl;
cout<<"==========================================================="<<endl;
delete [] a1;
a1=nullptr;


    return 0 ;
}