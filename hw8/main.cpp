#include<iostream>

using namespace std;

class node
{
	public:
		node();
		int data;
		node* next_node;
};

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		void append_node(int n);
		void del_node(int n);
		void show_list();
	private:
		node* head;
};

int main()
{
	LinkedList mylink;
	mylink.append_node(0);
	mylink.append_node(1);
	mylink.append_node(2);
	mylink.append_node(3);
	mylink.del_node(1);
	return 0;
}

node::node()
{
}

LinkedList::LinkedList()
{
	head=new node;
	head=NULL;
}

LinkedList::~LinkedList()
{
	node* temp=head;
	node* tmp;
	while(temp)
	{
		tmp=temp;
		temp=(*temp).next_node;
		cout<<"free(["<<(*tmp).data<<"]->";
		delete(tmp);
	}
	cout<<"null\n";
}

void LinkedList::append_node(int n)
{
	node* temp=head;
	node* tmp;
	while(temp)
	{
		tmp=temp;
		temp=(*temp).next_node;	
	}	
	temp=new node;
	if(head==NULL)
		head=temp;
	else
		(*tmp).next_node=temp;
	(*temp).data=n;
	(*temp).next_node=NULL;
	show_list();
}

void LinkedList::show_list()
{
	node* temp=head;
	while(temp)
	{
		cout<<"["<<(*temp).data<<"]->";
		temp=(*temp).next_node;
	}
	cout<<"null\n";
}

/*node_t* add_node(node_t* head, int new_data)
{
	node_t* new_node=allocate_node(new_data);
	new_node->next_node=head;
	return new_node;
}*/

void LinkedList::del_node(int n)
{
	node* temp=head;
	node* tmp;
	int c=0;
	while(c<n)
	{
		c=c+1;
		tmp=temp;
		temp=(*temp).next_node;
	}
	(*tmp).next_node=(*temp).next_node;
	delete(temp);
	show_list();
}
