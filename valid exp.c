#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define n 100
struct stack
{
	int top;
	char array[n];
};

void create(struct stack *s)
{
	s->top=-1;
}

void push(struct stack *s, char x)
{
	if(s->top==(n-1))
	{
		printf("Stack Overflow \n");
		exit(1);
	}
	else
	{
		s->top++;
		s->array[s->top]=x;
	}
}
char pop(struct stack*s)
{
	if(s->top==-1)
	{
		printf("INVALID EXPRESSION \n");
		exit(1);
	}
	else
	{
		return s->array[s->top--];
	}
}

void main()
{
	struct stack s1;
	char exp[100];
	printf("Enter the expression to be checked \n");
	scanf("%s",exp);
	int length=strlen(exp);
	create (&s1);
	int i=0;
	for (i=0;i<length;i++)
	{
		char c=exp[i];
		if(c=='(' || c=='{' || c=='[')
		push (&s1,c);
		else if(c==')' || c=='}' || c==']')
		{
			int m=pop(&s1);
			if ( (m=='('&& c==')' ) || (m=='{' && c=='}') || (m=='[' && c==']' ));
			else
			{
			
			printf("INVALID EXPRESSION \n");
			exit(1);
		}
	}
	}
	if(s1.top==-1)
	printf("VALID EXPRESSION \n");
	else
	printf("INVALID EXPRESSION \n");
}

