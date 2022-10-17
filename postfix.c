//	Write a C program to evaluate an arithmetic expression in Postfix form.
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
		printf("stack underflow \n");
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
	char expr[100];
	printf("Enter the postfix epxression \n");
	scanf("%s",expr);
	int length=strlen(expr);
	
	create (&s1);
	int i=0;
	for(i=0;i<length;i++)
	{
		if(isdigit(expr[i]))
		{
			push(&s1,expr[i]-48);
		}
		else
		{
			int result;
			char op=expr[i];
			int x=pop(&s1);
			int y=pop(&s1);
			switch (op)
			{
				case '+':
					{
						result=x+y;
						break;
					}
					case '-':
						{
							result=y-x;
							break;
						}
						case '*':
							{
								result=x*y;
								break;
							}
							case '/':
								{
									result = y/x;
									break;
								
								}
								case '^':
									{
										result=(int)pow(y,x);
										break;
									}
			}
			push(&s1,result);
		}
	}
	printf("the result of expression %s is : %d \n",expr,pop(&s1));
}

