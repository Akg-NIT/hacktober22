#include <stdio.h>
#include <stdlib.h>


int s1[100], s2[100];
int top1 = -1, top2 = -1; 
int count = 0; 

//Function to create a queue
void create_queue()
{
    top1 = top2 = -1;
}

//Function to push the element in 1st stack
void push1(int data)
{
    s1[++top1] = data;
}

//Function to delete element from 1st stack
int pop1()
{
    return (s1[top1--]);
}

//Function to push an element in 2nd stack
void push2(int data)
{
    s2[++top2] = data;
}

//Function to delete an element from 2nd stack
int pop2()
{
    return (s2[top2--]);
}


void enqueue()
{
    int data, i;

    printf("Enter the element to be inserted into queue");
    scanf("%d", &data);
    push1(data);
    count++;
}

//Function to delete an element from the queue using stack operations
void dequeue()
{
    int i;

    for (i = 0; i <= count; i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0; i <= count; i++)
    {
        push1(pop2());
    }
}

//Function to display the elements in the stack/
void display()
{
    int i;

    for (i = 0; i <= top1; i++)
    {
        printf(" %d ", s1[i]);
    }
}

void main()
{
    int ch;

    printf("Choose 1 to enter an element into queue\n");
    printf("Choose 2 to delete an element from front of queue\n");
    printf("Choose 3 to display the elements in queue\n");
    printf("Choose 4 to exit\n");
    create_queue();
    while (1)
    {
        printf("\nEnter your choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}
