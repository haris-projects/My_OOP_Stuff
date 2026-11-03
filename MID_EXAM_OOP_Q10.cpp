#include<iostream>
using namespace std;
struct Student {

    string name ;
    int roll ;
    float marks[4];
    float higestmarks;
    float lowestmarks;
    float obtain;
    float average;
    char grade;
};
void calculateResult(Student *s1){
    int i ;
    s1->higestmarks=s1->marks[0];
    s1->lowestmarks=s1->marks[0];
    for(i=0 ; i<4 ; i++){
        s1->obtain+=s1->marks[i];
        
        if(s1->marks[i]>s1->higestmarks)
        s1->higestmarks=s1->marks[i];

        else if (s1->marks[i]<s1->lowestmarks)
        s1->lowestmarks=s1->marks[i];

    
    }
    s1->average=s1->obtain/i;

    if(s1->average>=85)
    s1->grade='A';

    else if(s1->average>=70 && s1->average<84.99)
    s1->grade='B';

    else if(s1->average>=55 && s1->average<69.99)
    s1->grade='C';

    else if (s1->average>=40 && s1->average<54.99)
    s1->grade='D';

    else if(s1->average<40)
    s1->grade='F';
    cout<<"Name : "<<s1->name<<endl;
    cout<<"Roll no : "<<s1->roll<<endl;
    cout<<"Highest : "<<s1->higestmarks<<endl;
    cout<<"Lowest : "<<s1->lowestmarks<<endl;
    cout<<"Average : "<<s1->average<<endl;
    
     for(i=0 ; i<4 ; i++){
        if(s1->marks[i]<33){
        s1->grade='F';
        cout<<"Grade : "<<s1->grade<<" (Failed in a subject) : "<<i+1<<endl;
        }
    }
    
}
int main(){
  Student s1;
  cout<<"Enter Student Name : ";
  getline(cin,s1.name);
  cout<<"Enter Student Roll no : ";
  cin>>s1.roll;
  cout<<"\n Enter SUb Marks : \n";
  for(int i=0 ; i<4 ; i++){
    cout<<"Enter Sub "<<i+1<<" Marks : ";
    cin>>s1.marks[i];
    while(s1.marks[i]<0 && s1.marks[i]>100)
    cin>>s1.marks[i];
  }
  calculateResult(&s1);

    return 0 ;
}