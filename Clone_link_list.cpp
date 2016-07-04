#include<iostream>
using namespace std;
struct list
{
	int data;
	struct list *next,*random;
};

struct list *create(int data)
{
struct list *newnode = new (struct list);
newnode->data=data;
newnode->next=NULL;
newnode->random=NULL;
return newnode;
}
struct list *insert(struct list *head,int data)
{
	struct list *newnode = create(data);
	if(head==NULL)
	return newnode;
	else
	{
	struct list *tmp = head;
	while(tmp->next!=NULL)
	tmp=tmp->next;
	tmp->next = newnode;
	return head;
	}
}
void display_next(struct list *head)
{
	struct list *a = head;
	while(a!=NULL)
	{
	cout<<a->data<<"-->";
	a = a->next;
	}

}
void display_random(struct list *head)
{
	struct list *a = head;
	while(a!=NULL)
	{
	cout<<a->data<<"-->";
	a = a->random;
	}

}


struct list *copy(struct list *head,struct list *clone)
{
	struct list *root = head,*tmp; 
while(root!=NULL)
	{
		struct list *copy = new(struct list);
		copy->data = root->data;
		tmp=root->next;
		root->next = copy;
		copy->next = tmp;
		root=root->next->next;
	}
root = head;
while(root!=NULL)
	{
	root->next->random = root->random;	
	root=root->next->next;
	}

root = head;
tmp = root->next;

while(tmp->next!=NULL)
	{
		tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
tmp->next = NULL;
struct list *ans = root->next;


return ans;
}
	
int main()
{
struct list *head=NULL,*clone=NULL;
head = insert(head,1);
head = insert(head,2);
head = insert(head,3);
head = insert(head,4);
head = insert(head,5);

head->random = head->next->next;
head->next->random = head->next->next->next;
head->next->next->random = head->next->next->next->next;
head->next->next->next->random = NULL;
head->next->next->next->next->random = head->next;


cout<<"\nHead List (next) \n";
display_next(head);
cout<<"\nHead List (Random) \n";
display_random(head);

clone = copy(head,clone);

cout<<"\nClone List (next) \n";
display_next(clone);
cout<<"\nClone List (Random) \n";
display_random(clone);
}
