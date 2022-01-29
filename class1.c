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
	scanf("%s",getnode-name>);
	
	printf("Enter the dept:\n");
	scanf("%s",getnode->dept);
	
	printf("Enter the designation:\n");
	scanf("%s",getnode->designation);
	
	printf("Enter the salary:\n");
	scanf("%d",&getnode->sal);
	
	printf("Enter the phno:\n");
	scanf("%d",&getnode->phno);
	
	getnode->llink = NULL;
	get->rlink = NULL;
	
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
			node->llinl = temp;
		}
	}
}

int main()
{
	int ch;
	printf("Enter the choice as 1\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: create_list();
	}
}