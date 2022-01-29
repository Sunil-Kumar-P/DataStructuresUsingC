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

poly sum_poly(poly head1, poly head2, poly head3)
{
	poly p1, p2;
	int c, c1, c2, x1, x2, y1, y2, z1, z2, flag;
	
	p1 = head1->link;
	
	while(p1!=head1)
	{
		c1 = p1->coeff;
		x1 = p1->x;
		y1 = p1->y;
		z1 = p1->z;
		
		p2 = head2->link;
		flag=0;
		
		while(p2 != head2)
		{
			c2 = p2->coeff;
			x2 = p2->x;
			y2 = p2->y;
			z2 = p2->z;
			
			if((x1==x2)&&(y1==y2)&&(z1==z2))
			{
				head3 = insert(head3, c1+c2, x1, y1, z1);
				p2->coeff = 0;
				
				flag=1;
				break;
			}
			else
				p2=p2->link;
		}
		if(flag==0)
			head3 = insert(head3, c1, x1, y1, z1);
			
		p1 = p1->link;
	}
	p2 = head2->link;
	
	while(p2 != head2)
	{
		if(p2->coeff!=0)
		{
			head3 = insert(head3, p2->coeff, p2->x, p2->y, p2->z);
			p2 = p2->link;
		}
		return head3;
	}
}

int main()
{
	poly head1, head2, head3;
	
	head1 = create();
	head1->link = head1;
	
	head2 = create();
	head2->link = head2;
	
	head3 = create();
	head3->link = head3;
	
	printf("\nEnter the polynomials:");
	head1 = input_polynomial(head1);
	printf("\nThe given polynomial is:");
	display(head1);
	
	printf("\nEnter the polynomials:");
	head2 = input_polynomial(head2);
	printf("\nThe given polinomial is:");
	display(head2);
	
	head3 = sum_poly(head1, head2, head3);
	printf("\n--------------------\n");
	printf("The sum of two polynomials is");
	display(head3);
	
	return(0);
	
}
