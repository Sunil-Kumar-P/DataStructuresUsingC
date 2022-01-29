#include<stdio.h>
#include<Stdlib.h>

struct Employee{
	char ssn[20];
	char name[20];
	char dept[20];
	char designation[20];
	int sal[10];
	int phno[10];
	struct Employee *llink;
	struct Employee *rlink;
};

typedef struct Employee *e;
e start=NULL;
e create()
{
	e getnode;
	getnode = (e)malloc(sizeof(struct Employee));
	if(getnode == NULL)
	{
		printf("\nMemory cant be allocated!");
		return;
	}
	printf("Enter the details of Employee");
	printf("Enter the ssn:\n");
	scanf("%s",getnode->ssn);
	
	printf("Enter the name:\n");
	scanf("%s",getnode->name);
	
	printf("Enter the dept:\n");
	scanf("%s",getnode->dept);
	
	printf("Enter the designation:\n");
	scanf("%s",getnode->designation);
	
	printf("Enter the salary:\n");
	scanf("%d",&getnode->sal);
	
	printf("Enter the phno:\n");
	scanf("%d",&getnode->phno);
	
	getnode->llink = NULL;
	getnode->rlink = NULL;
	
	return(getnode);
} 

void create_list()
{
	int i,n;
	e node, temp;
	
	printf("Enter the number of employees:\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		node = create();
		
		if(start == NULL)
		{
			start = node;
		}
		else
		{
			temp=start;
			
			while(temp->rlink!=NULL)
			{
				temp = temp->rlink;
			}
			temp->rlink = node;
			node->llink = temp;
		}
	}
}

void status()
{
	e temp;
	int count = 0;
	if(start == NULL)
	{
		printf("\n list is empty!!");
		return;
	}
	temp = start;
	printf("\nThe Employee details are:");
	while(temp != NULL)
	{
		printf("\n%s\n%s\n%s\n%d\%d\n%d\n",temp->ssn, temp->name, temp->dept, temp->designation, temp->sal, temp->phno);
		temp =temp->rlink;
		count++;
	}
	printf("\nThe number of nodes are:%d", count);
}

void insert_front()
{
	e node;
	node = create();
	
	if(start==NULL)
	{
		start=node;
	}
	else
	{
		node->rlink = start;
		start->llink = node;
		start = node;
	}
}

int main()
{
	int ch;
	for(;;)
	{
		printf("Enter the choice 1,2,3,4\n");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1: create_list();
				break;
			
			case 2: status();
				break;
			
			case 3: insert_front();
				break;
				
			case 4: return;
			
			default:printf("\nInvalid Chocie!!");
		}
	}
	
}
