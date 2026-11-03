#include<iostream>
using namespace std;
struct vitals {
    int heartrate;
    float temp;
};
struct medicalinfo{
string bloodgroup;

vitals vv;
};

struct patient{

string name ;
int patient_id;
int age;
medicalinfo mm;


};

int main(){
    int N , i ; 
    int temp_count=0;
cout<<"Enter value of N ";
cin>>N ;
patient *p1=new patient[N];
// medicalinfo m1;
// vitals vv;

cout<<"Enter Detail of Patients "<<endl;

for(i=0 ; i<N ; i++){
    cin.ignore();
    cout<<"Enter "<<i+1<<" Patient Name \n";
    getline(cin,p1[i].name);
    cout<<"Enter "<<i+1<<" Patients ID\n";
    cin>>p1[i].patient_id;
     cout<<"Enter "<<i+1<<" Patients age\n";
    cin>>p1[i].age;

    cout<<"Enter "<<i+1<<" Patients BloodGroup \n";
    cin>>p1[i].mm.bloodgroup;

    cout<<"Enter "<<i+1<<" Patients Hearte Rate \n";
    cin>>p1[i].mm.vv.heartrate;

    cout<<"Enter "<<i+1<<" Patients Temperature \n";
    cin>>p1[i].mm.vv.temp;

}

for(i=0 ; i<N ; i++){
p1[i].mm.vv.temp;
 temp_count++;
}


for(i=0 ; i<N ; i++){
    cout<<"\nthe "<<i+1<<" Patient Name :";
    cout<<p1[i].name;
    cout<<"\nThe "<<i+1<<" Patients ID :";
    cout<<p1[i].patient_id;
     cout<<" \nThe "<<i+1<<" Patients age :";
    cout<<p1[i].age;

    cout<<"\nThe "<<i+1<<" Patients BloodGroup :";
    cout<<p1[i].mm.bloodgroup;

    cout<<"\nThe "<<i+1<<" Patients Hearte Rate :";
    cout<<p1[i].mm.vv.heartrate;

    cout<<"\nthe "<<i+1<<" Patients Temperature :";
    cout<<p1[i].mm.vv.temp;

}
   cout<<"\nThe Total Number of Patients Whose Tempersture is : "<<temp_count;

    return 0 ;
}