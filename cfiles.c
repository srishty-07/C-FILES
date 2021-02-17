#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int info;
//   pointer to node
struct node *link;
};
int  main()
{
struct node *new, *start;
int data;
new= (struct node*)malloc(sizeof(struct node));
printf("\nEnter the data value to insert in first node\n");
scanf("%d",&data);
new->info=data;
new->link=start;
start=new;
return 0;
}
