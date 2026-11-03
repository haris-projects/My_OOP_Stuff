#include<iostream>
#include<string>
using namespace std;

struct Employee{
    string name;
    int id;
    float salary[3];
    float totalSalary=0;
    float AverageSalary=0;
    string bonus;
};

void CalculateSalary(Employee*e1){
    int i ;
    for(i=0 ; i<3 ; i++){
        e1->totalSalary+=e1->salary[i];
    }
    e1->AverageSalary=e1->totalSalary/i;
    if(e1->AverageSalary>50000)
    e1->bonus="Elagible";
    else 
    e1->bonus="Not Elagible";
}

int main(){
    Employee e1;
    cout<<"Enter name of the Employee : ";
    getline(cin,e1.name);
    cout<<"Enter ID of the Employee : ";
    cin>>e1.id;
    for(int i=0 ; i<3 ; i++){
        cout<<"Enter Salary of Month "<< i+1 << " ";
        cin>>e1.salary[i];
    }
    CalculateSalary(&e1);

    cout<<"The name of the Employee is : "<<e1.name<<endl;
    cout<<"The ID of the Employee is : "<<e1.id<<endl;
    cout<<"The  Total Salary of the Employee is : "<<e1.totalSalary<<endl;
    cout<<"The  Average Salary the Employee is : "<<e1.AverageSalary<<endl;
    cout<<"The  Bonus Eligability of the Employee is : "<<e1.bonus<<endl;

    return 0 ;
}