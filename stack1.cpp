#include <stdio.h>
#define MAX 2
struct Stack
{
    int number[MAX+1];
    int top;
};

void push(int);
int pop();
void display();

Stack s;

int main()
{
    s.top = 0;
    int n, choice;
    do
    {
        printf("1.Push\t2.Pop\t3.Display\t4.Quit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Input number: ");
            scanf("%d", &n);
            push(n);
            break;
        }
        case 2:
        {
            if (!s.top)
            {
                printf("Stack is empty\n");
                break;
            }
            int m = pop();
            printf("Removed element: %d\n", m);
            break;
        }
        case 3:
        {
            display();
            break;
        }
        }
    } while (choice != 4);
    printf("Exit the program\n");
    return 0;
}

void push(int n)
{
    if(s.top >= MAX)
        printf("Stack overflows, top = %d\n", s.top);
    else
    {
        s.top++;
        s.number[s.top] = n;
    }
}

int pop()
{
    int l = s.number[s.top];
    s.top--;
    return l;
}

void display()
{
    if(!s.top)
        printf("Stack is empty\n");
    for(int i = s.top; i >=1; i--)
    {
        printf("Element %d = %d\n",i,s.number[i]);
    }
}