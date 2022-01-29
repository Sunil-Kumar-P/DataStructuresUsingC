//design, develop and implement a program in c for the following operation on
//Singly Circular Linked List (SCLL) with header nodes Represent and Evalute a
//Polynomial P(x,y,z) = 6x^2y^2z-4yz^5+3x^3yz+2xy^5z-2xyz^3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct polynomial
{
	int coeff, x, y, z;
	struct polynomial*link;
};
typedef struct polynomial * poly;

poly create()
{
	poly getnode;
	getnode = (poly)malloc(sizeof(struct polynomial));
	
	if(getnode==NULL)
	{
		printf("\nMemmory couldnt be allocated!!!");
		return;
	}
	return (getnode);
}
poly insert (poly head, int c, int px, int py, int pz)
{
	poly node, temp;
	node = create();
	node->coeff = c;
	node->x = px;
	node->y = py;
	node->z = pz;
	node->link = NULL;
	temp = head->link;
	while(temp->link != head)
	{
		temp = temp->link;
	}
	temp->link = node;
	node->link = head;
	return(head);
}

poly input_polynomial(poly head)
{
	int i, c, px, py, pz;
	for(i=1;;i++)
	{
		printf("\n Enter the coefficient%d:", i);
		scanf("%d", &c);
		if(c==999)
			break;
				
		printf("\n Enter the power of x:");
		scanf("%d",&px);
		printf("\n Enter the power of y:");
		scanf("%d",&py);
		printf("\n Enter the power of z:");
		scanf("%d",&pz);
		head = insert(head, c, px, py, pz);
	}
	return(head);
}
void display(poly head)
{
	poly temp;
	
	if(head->link == head)
	{
		printf("\n Polynomial doesnt exist!!!");
		return;
	}
	
	temp = head->link;
	
	while(temp!= head)
	{
		printf("%dx^%dy^%dz^%d", temp->coeff, temp->x, temp->y, temp->z);
		temp = temp->link;
	}
}
int  evaluate_polynomial(poly head)
{
	int px, py, pz, sum=0;
	poly temp;
	printf("\nEnter the value of x, y, z:");
	scanf("%d%d%d",&px,&py,&pz);
	temp = head->link;
	while(temp != head)
	{
		sum = sum + (temp->coeff * pow (px, temp->x) * pow (py, temp->y) * pow (pz, temp->z));
		temp = temp->link;
	}
	return (sum);
}
int main()
{
	poly head;
	int result;
	
	head = create();
	head->link = head;
	printf("\nEnter the polynomials:");
	head = input_polynomial(head);
	printf("\nThe given polinomial is:");
	display(head);
	
	result = evaluate_polynomial(head);
	printf("\nthe result of evaluation is %d", result);
	
	return(0);
	
}
