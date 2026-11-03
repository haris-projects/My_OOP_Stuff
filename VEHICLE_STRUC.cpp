#include<iostream>
using namespace std;
struct Duration{
    int startday ;
    int endDay;
    int duration;

};
struct Rentinfo {
    string onwername;
    Duration r1;
};
struct Vehicle{
    int plateno;
    Rentinfo f1;
};
int main(){
int N ;
cout<<"Enter total no of Vehicle : "<<endl;
cin>>N;
int maximum =0 ;
    Vehicle *v1=new Vehicle[N];
    Vehicle *v2=new Vehicle[N]; 
    int i ;
    for(i=0 ; i<N ; i++){
        cout<<"Enter Plateno of Vehicle :"<<i+1<<endl;
        cin>>v1[i].plateno;
        cout<<"Enter Onwer name "<<i+1<<endl;
        getline(cin, v1[i].f1.onwername);
   cout<<"Enter Duration Start Day : "<<i+1<<endl;
        cin>>v1[i].f1.r1.startday;

        cout<<"Enter Duration End Day : "<<i+1<<endl;
        cin>>v1[i].f1.r1.endDay;

    } 
     int n , m ;

    for(i=0 ; i<N ; i++){
        cout<<"The Plateno of Vehicle is : "<<i+1<<endl;
        cout<<v1[i].plateno<<endl;
        cout<<"The Onwer name "<<i+1<<endl;
        cout<< v1[i].f1.onwername<<endl;
        cout<<"The Duration Start Day : "<<i+1<<endl;
        cout<<v1[i].f1.r1.startday<<endl;
        // n=v1[i].f1.r1.startday;
        cout<<"The Duration End Day : "<<i+1<<endl;
        cout<<v1[i].f1.r1.endDay<<endl;
        // m=v1[i].f1.r1.endDay;
        v2[i].f1.r1.duration=v1[i].f1.r1.startday-v1[i].f1.r1.endDay;
        if(v2[i].f1.r1.duration>maximum);

    }



    delete [] v1;

    return 0 ;
}