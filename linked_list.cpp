#include <bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node *next;
}*stnode;


void insertLast(){
struct node *p;
p = (struct node *)malloc(sizeof(struct node));
int n;
printf("enter element to enter");
scanf("%d",&n);
p->data = n;
p->next = NULL;
if(stnode == NULL){
stnode = p;
}
else{
struct node *tmp = stnode;
while(tmp->next != NULL){
tmp = tmp->next;
}
tmp->next = p;
}
cout<<"Node inserted at the end...\n";
}
void bdelete(){  
        struct node *ptr;
        struct node *prev;
        if(stnode == NULL)  
        {  
            cout<<"\nList is empty";  
        }  
        else  
        {  
            int find;
            printf("Enter element to delete");
            scanf("%d",&find);
            ptr = stnode;
            prev = NULL;
            while(ptr!=NULL){
                if(ptr->data==find){
                    prev->next = ptr->next;
                    ptr->next = NULL;
                    break;
                }
                else{
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
            free(ptr);  
            cout<<"Node deleted  ...\n";  
        }  
    }  

int main() {
int n,um;
cout<<"Enter number of nodes:-";
cin>>n;
create(n);
display();
insertLast();
display();
bdelete();
display();
return 0;
}
