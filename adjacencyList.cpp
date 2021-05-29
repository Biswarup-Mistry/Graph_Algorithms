/*
The time complexity of this programme is O(nk)
where n is the number of the node and k is the no. of 
adjacent vertices of node i [where i=1 to n]
*/

#include<iostream>
using namespace std;

struct node{
    public :
        int data;
    node *link;
};

class adjlst{
    private:
    node *a;
    public :
    int size;
    adjlst(int n){
        size=n;
        a=new node[size];
    }
    bool isEmpty(node *&head);
    node*& getnode(node *&head, node *&last , int data);
    node*& insert(node *&head, node *&last , int data);
    void list();
    void display();
};

bool adjlst :: isEmpty(node *&head){
    if (head==NULL)
        return(true);
    else
        return(false);
}

node*& adjlst :: getnode(node *&head, node *&last , int data){
    node *n=new node;
    n->data=data;
    n->link=NULL;
    head=n;
    last=n;
    return head;
}

node*& adjlst :: insert(node *&head, node *&last , int data){
    if(isEmpty(head)){
        head=getnode(head,last,data);
    }
    else{
        node *n=new node;
        n->data=data;
        n->link=head;
        head=n;
    }
    return head;
}

void adjlst :: list(){
    int k=0,d;
    node *head=NULL;
    node *last=NULL;
    
    for(int i=0;i<size;i++){
        cout<<"No. of the adjacent verteices for "<<i+1<<" th point ? ==>>"<<endl;
        cin>>k;
        node *v=new node;/*if this statement was written outside the for loop of 'i',
        then the address of the head inserted at the begining into the linked list 
        would lost after the insertion of the first node into the array of pointers.*/
        for(int j=1;j<=k;j++){
            cout<<"Enter the data for ("<<j<<") adjacent node -->>"<<endl;
            cin>>d;
            v=(insert(head,last,d));
            a[i]=node(*v);
        }
        free(v);//select;v;
        /*if it is written into the nested for loop, then at every iteration
        this "v" will be deleted and the after that a new node will be created with out the 
        last node's head's address.*/
        head=NULL;
        last=NULL;
    }
}

void adjlst :: display(){
    int i;
    for(i=0;i<size;i++){
        node *ptr=new node;
        ptr=&a[i];
        cout<<"[ "<<i+1<<" ]==>>";
        while(ptr!=NULL){
            cout<<"["<<ptr->data<<"]-->>";
			ptr=ptr->link;
        }
        cout<<"[/]"<<endl;
        free(ptr);//select;ptr;
    }
}

int main(){
    system("clear");
    int opt;
    int data,n;
    cout<<"******Welcome to the Adjacency List******"<<endl;
    cout<<"Enter the no. of nodes present in the Graph ==>>"<<endl;
    cin>>n;
    adjlst a(n);
    do{
        cout<<"\tMenu"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"1. Insert Node(s) into the Adjacency List"<<endl;
        cout<<"2. Display the Linked List"<<endl;
        cin>>opt;
        switch (opt){
        case 0:
            break;
        case 1:
            a.list();
            break;
        case 2:
            system("clear");
            a.display();
            break;
        default:
            cout<<"Wrong Choise... Choose Again..."<<endl;
            break;
        }
    }while(opt!=0);

    return (0);
}