#include<iostream>
using namespace std;

void Showtotal(int**arr ,int stu ,int sub){
    int i , j ;
    
    for(i=0 ; i<stu ; i++){
        int total=0 ;
        float percentage=0.00;
        cout<<"Student "<<i+1<<" ";
        for(j=0 ; j<sub ; j++){
        total+=arr[i][j];
        }
        percentage=(float)total/(sub*100)*100;
        cout<<" , Total = "<<total <<" , Percentage = "<<percentage<<" % ";
        cout<<endl;
    }

}

int main(){

    int student;
    int subjects;
    cout<<"Enter Total no of Students ";
    cin>>student;

    cout<<"Enter Total no of Subjects ";
    cin>>subjects ;

    if(student<0 || subjects<0){
        cout<<"Error in Program"<<endl;
        return 0 ;
    }
    int i , j ;

    int **arr=new int *[student];
    for(i=0 ; i<student ; i++){
        arr[i]=new int[subjects];
    }

    for(i=0 ; i<student ; i++){
     cout<<"Enter Student "<<i+1<<" Marks : "<<endl;
        for(j=0 ; j<subjects ; j++){
           cin>>arr[i][j];

           while(arr[i][j]<0 || arr[i][j]>100){

            cout<<"Invalid marks ! Please Enter again "<<endl;
            cin>>arr[i][j];
           }

           cout<<endl;

        }
        
    }

    Showtotal(arr , student , subjects);

    for(i=0 ; i<student ; i++){
        delete[] arr[i];
    }
    delete [] arr;
    arr = nullptr;
    return 0;
}