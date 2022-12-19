#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node      // create only for our data type
{
    public:
    int value;
    Node *next;
     Node()
     {
        next = NULL;
        value = 0;
     }
};
class LinkedList
{
    Node *Head ;
    public:
        LinkedList()
        {
            Head = NULL;
        }
    void Insert_Element(int number)
    {
          Node *temp = new Node();      // crate first node 
            temp->value = number ;
            // For First Node  :
            if(Head == NULL)
            {
                Head = temp ;
            }
            else {
                Node *s = Head;
                while(s->next != NULL)
                {
                    s = s->next;
                }
                s->next = temp ;
            }  
    }
            void Print_()
            {
                Node *temp = Head;
                while(temp != NULL)
                {
                    cout<<temp->value<<" ->  ";
                    temp = temp->next;
                   
                }
                delete temp;
            }
            void Insert_begin(int number)
            {
                Node *temp = new Node();
                temp ->value = number;
                if(Head == NULL)   // ye bas ye check karne k lya hai ki hmari linked list bni hai k nhi 
                {// agr condition nehi lgate to fir be chal jyaga 
                    Head = temp;   // if agr nhi bni hai to head k ander normal value dal denge 
                }
                // else
                temp->next = Head ;   // temp ka next yani jha pr user value raki hai use node mya head ka address assign kro to temp first ho jyaga
                Head = temp;  //  ab  hum temp ko second bna dege  
            }
            void Insert_Midlle(int v,int index)
            {
                Node *temp = new Node();
                temp->value = v;
                Node *s = Head ;
                if(index == 1)
                {
                    Insert_begin(v);
                }
                while(index>1)
                { 
                    index--;
                    if(s->next!=NULL){
                    s = s->next;  // yani Head jisko point kr reha tha uska next :
                    return ; }
                   // ye hume Position pr phucha dega jha pr insert karna hai :
                    else{
                        cout<<"Please Enter a Specifie Position : "<<endl;
                    }
                }
                temp->next= s->next;   // temp mya abi null hoga to s->next yani psoition address  temp mya chla gya 
                s->next = temp;  // s->next mya ab ye 
            }
            void Delete_(int n)
            {
                Node *temp = Head ;
                if(n==1)
                {
                    Head = Head->next;  // delete from begning 
                    cout<<temp->value<<" Delete "<<endl;
                    delete temp;
                }
               
                while(n > 0)
                {
                    n--;
                    if(temp->next->next!=NULL)
                    {
                        temp = temp->next;
                    } else { 
                        cout<<"Position NOt found ";
                        return;
                    }
                    Node *S = temp->next ;
                    //cout<<"S value is "<<S->value<<endl;
                    temp->next = S->next ; // S jis position vo point kr reha hai use next vala  dal to temp k next mya 
                    delete S;
                }
            }
            void Search_(int index)
            {
                Node *temp = Head;
                int i,r=0;
                if(Head== NULL)
                {
                    cout<<"List is Empty ";
                }
                else
                while(temp!=NULL)
                {
                     r++;
                    if(temp->value==index){
                    cout<<"\nValue is found at "<<r<<" Index \n";
                    }
                    temp= temp->next;
                }
                cout<<"Value Not found ";
            }


};
int main()
{
    LinkedList c;
    while(1)
    {
        cout<<"\n....................................................................\n";
        cout<<"1 For Insert Element \n";
        cout<<"2 For Insert Element in Begin \n";
     
        cout<<"3 For Insert Element in Any Position \n";
        cout<<"4 For Delete Any Element \n";
       
        cout<<"5 For Search Any Value \n";
        cout<<"6 For Print All Value \n";
        cout<<"7 For Exit \n";
        cout<<"\nEnter Your Choice \n";

        int choice,r,s;
        cin>>choice;
        switch(choice )
        {
            case 1: 
                 cout<<"Enter value ";
                 cin>>r;
                 c.Insert_Element(r);
            break;
            case 2:
                 cout<<"Enter value ";
                 cin>>r;
                 c.Insert_begin(r);
            break;
            case 3: 
                 cout<<"Enter value ";
                 cin>>r;
                 cout<<"Ok then enter position ";
                 cin>>s;
                 c.Insert_Midlle(r,s);
            break;
            case 4:
                 cout<<"Enter value \n";
                 cin>>r;
                 c.Delete_(r);
            break;
            case 5:
                 cout<<"Enter value ";
                 cin>>r;
                 c.Search_(r);
            break;
            case 6:
                 c.Print_();
            break;
            case 7:
                 exit(0);
            break;
            default:
                 cout<<"Please Enter a Valid Choice ";
            break;
        }

    }
}
