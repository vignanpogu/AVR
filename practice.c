#include<stdio.h>
#include<stdlib.h>
struct node*  insert_big(struct node *head,int val);
struct node* insert_end(struct node* head,int val1);
void display(struct node *);
struct node* linear_search(struct node*,int ele);
struct node* delete_big(struct node *);
struct node{
	int a;
	struct node *next;
	}*head=NULL;

int main(void)
{
	while(10){
	int option,val,ele,val1;
	struct node *Head;
	printf("enter the option:\n 1.insert_big\n 2.display\n 3.linear search\n 4.delete_big\n 5.insert_end\n 6.exit\n");
	scanf("%d",&option);
	
	switch(option)
	{
	case 1:
		printf("enter the element\n");
		scanf("%d",&val);
		
		head=insert_big(head,val);
		break;
	case 2:
		display(head);
		break;
	case 3:
		printf("enter the element to search:\n");
		scanf("%d",&ele);
		Head=linear_search(head,ele);
		printf("\nelement is present at %p\n",Head);
		break;
	case 4:
		head=delete_big(head);
		break;
	case 5:
		printf("enter the value:\n");
		scanf("%d",&val1);
		head=insert_end(head,val1);
		break;
	case 6:
		exit(1);
	default:
		printf("wrong choice\n");
		break;
		}//switch
	}//while
}//main

struct node*  insert_big(struct node *head,int val)
{
	struct node *temp=NULL;
	temp=malloc(sizeof(struct node));
	temp->a=val;
	temp->next=NULL;
	if(head==NULL)
	     {
		 head=temp;
		return head;
	     }
	else
	  {
	      temp->next=head;
		head=temp;
		return head;
	   }
free(temp);
temp=NULL;
}

void display(struct node *head)
{
	while(head!=NULL)
	{
		printf("%d->",head->a);
		head=head->next;
	  }	
	printf("\n");
}

struct node* linear_search(struct node *head,int ele)
{

	while(head!=NULL)
	{
	     if(head->a == ele)
		{
		printf("%d found\n",head->a);
		return head;	
		}
	      head=head->next;
	}
}

struct node* delete_big(struct node *head)
{
	struct node *temp=NULL;
	temp=malloc(sizeof(struct node));
	temp=head;
	if(temp == NULL)
		printf("list is empty\n");
	else
		head=temp->next;
	free(temp);
	temp==NULL;
	return head;
}

struct node* insert_end(struct node *head,int val1)
{
	struct node *temp=NULL;
	temp=malloc(sizeof(struct node));
	temp->a=val1;
	temp->next=head;
	if (head==NULL)
	{
	temp->next=NULL;
	return temp;
	}//if end
	else
	{
	while(temp->next!=NULL)
	{
		temp->next=temp->next->next;
	}//end while
	temp->next->next=temp;
	temp->next=NULL;
	}
	free(temp);
	temp=NULL;
	return head;
}
