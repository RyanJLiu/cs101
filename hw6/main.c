#include<stdio.h>
#include<stdlib.h>

int g_mem[10];

typedef struct node
{
	int data;
	struct node* next_node;
}node_t;

node_t* allocate_node(int data)
{
	node_t* p=(node_t*)calloc(1, sizeof(node_t));
	p->data=data;
	p->next_node=NULL;
	return p;
}

void show_list(node_t* head)
{
	while(head)
	{
		printf("[%d]->",head->data);
		head=head->next_node;
	}
	printf("null\n");
}

node_t* append_node(node_t* head, int new_data)
{
	node_t* new_node=allocate_node(new_data);
	if(head)
	{
		node_t* p=head;
		while(p->next_node)
		{
			p=p->next_node;
		}
		p->next_node=new_node;
	}
	else
	{
		head=new_node;
	}
	return head;
}

void free_all_node(node_t* head)
{
	node_t* p=NULL;
	while(head)
	{
		p=head;
		head=head->next_node;
		printf("free([%d])->",p->data);
		free(p);
	}
	printf("null\n");
}

node_t* add_node(node_t* head, int new_data)
{
	node_t* new_node=allocate_node(new_data);
	new_node->next_node=head;
	return new_node;
}

node_t* del_node(node_t* head, int n)
{
	node_t* temp=head;
	node_t* p=NULL;
	int c=0;
	while(head&&c<n)
	{
		p=head;
		head=head->next_node;
		c=c+1;
	}
	p->next_node=head->next_node;
	free(head);
	return temp;
}

int main()
{
	node_t* head = NULL;
	head = append_node(head, 0);
	show_list(head);
	head = append_node(head, 1);
	show_list(head);
	head = add_node(head, -1);
	show_list(head);
	head = del_node(head, 1);
	show_list(head);
	free_all_node(head);
	return 0;
}
