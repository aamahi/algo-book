#include<stdio.h>
#include<stdlib.h>
struct aNode
{
	int val;
	struct aNode *next;
};
struct aNode *head;
void appendNode(int nodevalue)
{
	struct aNode *temp,*current;
	temp=(struct aNode*)malloc(sizeof(struct aNode));
	temp->val=nodevalue;
	temp->next=NULL;
	if(!head)
	{
		head=temp;
		return;
	}
	for(current=head;current->next;current=current->next);
	current->next=temp;
	return;
}
void printlist()
{	struct aNode *current;
    int t=1;
	for(current=head;current;current=current->next)
	{
	    printf ("Value No.%d = %d\n",t,current->val);
	    t++;
	}
}
struct aNode *findNode(int searchval)
{

	struct aNode *current;
	for(current=head;current && current->val!=searchval;current=current->next);
	return current;

}
void insertNode(int pre_val,int nodevalue)
{
    if( head==NULL )
    {
        printf("Invalid insertion\n");
        return;
    }
	struct aNode *temp,*current;
	temp=(struct aNode *)malloc(sizeof(struct aNode));
	temp->val=nodevalue;
	temp->next=NULL;
    current=findNode(pre_val);
    if(current==NULL)
    {
        printf("There is no such previous value\n");
        return;
    }
    temp->next=current->next;
    current->next=temp;
    return;
}
void deleteNode(int value)
{
    if( !findNode(value) )printf("Nothing to delete\n");
    struct aNode *current;
    if( head->val==value)
    {
        head=head->next;
        return;
    }
    for( current=head ; current->next->val!=value ; current=current->next );
    current->next=current->next->next;
    return;
}
int main()
{
	head=NULL;

	struct aNode *pos;
	appendNode(100);
	appendNode(200);
	appendNode(300);
	printlist();
	insertNode(200,500);
	insertNode(500,50);
	insertNode(2,10);
	insertNode(500,650);
	appendNode(400);
	printlist();
	pos=findNode(200);
	if(pos) printf("found!\n");
	else printf("not found!\n");
	deleteNode(100);
	printlist();
	deleteNode(500);
	printlist();
	return 0;
}
