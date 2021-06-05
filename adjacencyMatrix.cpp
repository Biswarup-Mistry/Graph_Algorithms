#include<iostream>
using namespace std;

class matrix{
    private :
    int **a;
    public :
    int n;
    matrix(int size);
    void insert();
    void delet(int a,int b);
    void display();
};

matrix :: matrix(int size){
    n=size;
    a=new int*[n];
}

void matrix :: insert(){
    cout<<"Enter the Values Now ==>>"<<endl;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<"Enter the value of a["<<i<<"]["<<j<<"] ==>>"<<endl;
            cin>>a[i][j];
        }
    }
}

void matrix :: delet(int a1,int b1){
    int i=a1;
    int j=b1;
    a[i][j]=0;
}

void matrix :: display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"a["<<i<<"]["<<j<<"] ==>>"<<a[i][j]<<endl;
        }
    }
}

int main(){
    system("cls");
    int opt,size,a,b;
    cout<<"***Welcome to the Adjacency Matrix Programme***"<<endl;
    cout<<"Enter the total number of nodes present into the Graph ==>>"<<endl;
    cin>>size;
    matrix m(size);
    do{
        cout<<"\tMenu"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Insert data into the Adjacency Matrix"<<endl;
        cout<<"2. Delete a data From the Matrix"<<endl;
        cout<<"3. Display"<<endl;
        cin>>opt;
        switch(opt){
            case 0:
            break;
            case 1:
            m.insert();
            break;
            case 2:
            cout<<"Enter the Row (i) ==>>"<<endl;
            cin>>a;
            cout<<"Enter the Column(j) ==>>"<<endl;
            cin>>b;
            m.delet(a,b);
            break;
            case 3:
            m.display();
            break;
            default:
            cout<<"Wrong Choise... Choose Again..."<<endl;
            break;
        }
    }while(opt!=0);
    return(0);
}