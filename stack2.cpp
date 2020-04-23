#include <stdio.h>
#include <cstring>
#include <cstdlib>

struct Stack
{
    char name[25];
    Stack *next;
};

Stack *top;
char s[25];

void push(char[]);
void display();
char *pop();

int main()
{
    int choice{};
    do
    {
        printf("1.Push\t2.Pop\t3.Display\t4.Quit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            while (getchar() != '\n');
            printf("Input a name: ");
            fgets(s, 25, stdin);
            push(s);
            break;
        }
        case 2:
        {
            char *t = pop();
            if (!t)
                printf("Stack is empty\n");
            else
                printf("REmoved element: %s", t);
            break;
        }
        case 3:
        {
            display();
            break;
        }
        }
    } while (choice != 4);
    return 0;
}

void push(char s[])
{
    Stack *p = (Stack*)malloc(sizeof(Stack));
    strcpy(p->name, s);
    p->next = top;
    top = p;
}

char* pop()
{
    if(!top)
    {
        return NULL;
    }
    else
    {
        strcpy(s,top->name);
        top = top->next;
    }
    return s;
}

void display()
{
    if(!top)
    {
        printf("Stack is empty\n");
        return;
    }
    for(Stack *p = top; p != NULL; p = p->next)
    {
        printf("%s",p->name);
    }
}