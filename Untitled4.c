#include<stdio.h>

struct Node
{
    int data;
};


int main()
{
    struct Node obj;

    obj.data = 299;

    printf("%d",obj.data);



    return 0;
}
