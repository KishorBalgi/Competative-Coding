// https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1

int findLength(Node* node){
    Node* ptr=node;
    int len=0;
    while(ptr){
        ptr=ptr->next;
        len++;
    }
    return len;
}
bool findGrt(Node* a,Node* b){
    while(a){
        if(a->data>b->data) return true;
        else if(a->data<b->data) return false;
        else {
            a=a->next;
            b=b->next;
        }
    }
    return true;
}
Node* balanceLst(Node* head,int m,int n){
    int k=n-m;
    while(k--){
        Node * newNode=new Node(0);
        newNode->next=head;
        head=newNode;
    }
    return head;
}
void subtract(Node* a,Node* b,int& c){
    if(!a && !b) return;
    subtract(a->next,b->next,c);
    
    if(c==1){
        if(a->data!=0){
            a->data--;
            c=0;
        }else{
            a->data+=9;
        }
    }
    if(a->data<b->data){
        c=1;
        a->data+=10;
    }
    
    a->data=a->data-b->data;
    
    return;
}
Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    int m=findLength(l1);
    int n=findLength(l2);
    
    if(m>n){
        l2=balanceLst(l2,n,m);
    }
    else {
        l1=balanceLst(l1,m,n);
    }
    
    Node * a,* b;
    
    if(findGrt(l1,l2)){
        a=l1;
        b=l2;
    }else{
        a=l2;
        b=l1;
    }

    int c=0;
    subtract(a,b,c);
    
    while(a->next && a->data==0){
        a=a->next;
    }
    
    return a;
}