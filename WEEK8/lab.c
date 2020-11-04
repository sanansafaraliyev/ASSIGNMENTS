#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
        char data[256];
        struct Node *next;
};

int pushend();

int printlist();

int removeName();

int luckycustomer();

int main()
{


        struct Node* head=(struct Node*)malloc(sizeof(struct Node));


        strcpy(head->data,"Turgut");
        head->next=NULL;

        // adding names of people to the queue

        pushend(head,"Nazrin");
        pushend(head,"Nigar");
        pushend(head,"Kamran");
        pushend(head,"Eljan");

        printlist(head);

        char input[256];
        bool quit =0;

        while (!quit)
        {
                printf("\nEnter a command: ");
                scanf("%s",input);

                if(strcmp(input,"quit") == 0)
                {
                        quit=1;
                }

 		else if (strcmp(input,"admit") == 0)
                {
                        removeName(&head);
                        printlist(head);
                }
                else
                {
                        luckycustomer(&head,input);
                        printlist(head);
                }
        }
        free(head);
        head=NULL;
}

int pushend(struct Node *p, char *data)
{
        while (p->next !=NULL)
        {
                p=p->next;
        }
        p->next=(struct Node*)malloc(sizeof(struct Node));
	strcpy(p->next->data,data);
	p->next->next=NULL;
}

int printlist(struct Node *n)
{
        printf("queue: ");
        while (n !=NULL)
        {
                printf("%s ",n->data);
                n=n->next;
        }
}

int removeName(struct Node **head)
{

        struct Node *next_node=NULL;

        if (*head == NULL)
        {
                return -1;
        }

 	next_node = (*head)->next;
	printf("\n%s was admitted\n",(*head)->data);
        free(*head);
        *head=next_node;


}

int luckycustomer(struct Node** head, char *key)
{
	struct Node *temp=(*head), *prev;

	if (temp !=NULL && temp->data == key)
	{
		*head=temp->next;
	}
	else
	{
		while (temp !=NULL && strcmp(temp->data,key) != 0)
		{
			prev=temp;
			temp=temp->next;
		}
		
		if (temp==NULL)
		{
			printf("There is no such customer.\n");
		}
		prev->next=temp->next;
	}

	struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
	struct Node *last=*head;

	strcpy(new_node->data,temp->data);
	new_node->next=NULL;

	while (last->next !=NULL)
		last=last->next;

	last->next=new_node;
	free(temp);
	
}















