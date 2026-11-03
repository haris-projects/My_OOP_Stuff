#include<iostream>
using namespace std;

void findMinum(int**ma1 ,int** ma2 ,int** res , int r , int c){
int i , j ;

for(i=0 ; i<r ; i++){
    for(j=0 ; j<c ; j++){
        if(ma1[i][j]<ma2[i][j])
        res[i][j]=ma1[i][j];

        else if(ma2[i][j]<ma1[i][j])
        res[i][j]=ma2[i][j];
        
        else if(ma1[i][j]==ma2[i][j])
        res[i][j]=ma1[i][j];
    }
}
}

void countSource(int**ma1 ,int** ma2  , int & fromA ,int & fromB ,int & ties , int r , int c){
int i , j ;

for(i=0 ; i<r ; i++){
    for(j=0 ; j<c ; j++){
        if(ma1[i][j]<ma2[i][j])
        fromA++;

        else if(ma2[i][j]<ma1[i][j])
        fromB++;
        
        else if(ma1[i][j]==ma2[i][j])
        ties++;
    }
}

}

int main(){

int row , col ;
int fromA=0 , fromB=0 , ties=0;
cout<<"Enter Rows of both Matrices : ";
cin>>row;

cout<<"Enter Col of both Matrices : ";
cin>>col;

int **matrix1=new int*[row];
int **matrix2=new int*[row];
int **result=new int*[row];

for(int i=0 ; i<row ; i++){
    matrix1[i]=new int[col];
    matrix2[i]=new int[col];
    result[i]=new  int[col];
}
int i , j ;
cout<<"Enter Matrix 1 Elements"<<endl;
for(i=0 ; i<row ; i++){
    for(j=0 ; j<col ; j++){
        cin>>matrix1[i][j];  
    }
}

cout<<"Enter Matrix 2 Elements"<<endl;
for(i=0 ; i<row ; i++){
    for(j=0 ; j<col ; j++){
        cin>>matrix2[i][j];  
    }
}
findMinum(matrix1 , matrix2 , result , row , col);

countSource(matrix1 , matrix2 ,fromA , fromB , ties , row , col) ;

cout<<"Minimum matrix : "<<endl;

for(i=0 ; i<row ; i++){
    for(j=0 ; j<col ; j++){
        cout<<" "<<result[i][j]<<" ";
    }
    cout<<endl;
}
cout<<"From Matrix 1 : "<<fromA<<endl;
cout<<"From Matrix 2 : "<<fromB<<endl;
cout<<" Ties : "<<ties<<endl;

for(i=0 ; i<row ; i++){
    delete[]matrix1[i];
    delete[]matrix2[i];
    delete[]result[i];
}
delete[]matrix1;
delete[]matrix2;
delete[]result;

matrix1=nullptr;
matrix2=nullptr;
result=nullptr;

    return 0;
}