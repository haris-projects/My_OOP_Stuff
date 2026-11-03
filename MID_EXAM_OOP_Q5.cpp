#include<iostream>
using namespace std;

class Box {
private:
int *data;
int size;
public:
Box(int s){
    
   
    int i ;
    if(s==0 || s<0){
     size=0 ;
     data=nullptr;
    }
   
    if(s>0){
      data=new int[s];
       size=s; 
    for(i=0 ; i<s ; i++)
        data[i]=(i+1)*10;  
}  }

void display();
int getsum();

~Box(){
    delete [] data;
    cout<<"box destroyed"<<endl;
    data=nullptr ;

}

};
void Box::display(){
    int i ;
    if(size==0)
    cout<<"Box empty"<<endl;
    else {
        for(i=0 ; i<size ; i++){
            cout<<" "<<data[i]<<" ";
        }
        cout<<endl;
    }    
}
int Box::getsum(){
    int i ;
    int sum=0;
    if(size==0)
    return 0 ;
    else {
        for(i=0 ; i<size ; i++){
        sum+=data[i];
        }
        return sum;
    }
}

int main(){

Box b1(4);
Box b2(-2);
b1.display();
cout<<"Sum of the Box 1 : "<<b1.getsum()<<endl;
b2.display();
if(b2.getsum()==0){
    cout<<"Box 2 sum is : 0"<<endl;
}

    return 0 ;
}