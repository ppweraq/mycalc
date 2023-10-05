#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    double val;
    struct stack *next;
} stack;

void print(stack *list)
{
    for (stack *p = list; p != NULL; p = p->next)
    {
        printf("%f ", p->val);
    }
    printf("\n");
}

int check_empty(stack *list)
{
    return list == NULL;
}

void *init_stack(stack **plist, double val)
{
    stack *p_stack = malloc(sizeof(stack));
    p_stack->val = val;
    p_stack->next = *plist;
    *plist = p_stack;
    // return p_stack;
}

int pop(stack **list){
    stack *tmp = *list;
    double res = tmp->val;
    *list = tmp->next;
    free(tmp);
    return res;
}


int main()
{
    double test[] = {2, 3, 4};
    stack *list = NULL;
    printf("Empty: %s\n", check_empty(list) ? "YES" : "NO");
    for (size_t i = 0; i < sizeof(test)/sizeof(test[0]); i++)
    {
        init_stack(&list, test[i]);
        print(list);
    }
     printf("Empty: %s\n", check_empty(list) ? "YES" : "NO");

    while (!check_empty(list))
    {
        double data = pop(&list);
        printf("pop %f: ", data);
        print(list);
    }
         printf("Empty: %s\n", check_empty(list) ? "YES" : "NO");
    
    return 0;
}