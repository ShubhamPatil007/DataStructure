#include <stdio.h>
#include <stdlib.h>

void createNode();
void display();

struct Node{
	int data;
	struct Node* next;
};
struct Node* start = NULL;

int main(){
	int choice;
	while(1){
		printf("\n1.Create Node\n2.Display List\n>>");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				createNode();
			break;
			case 2:
				display();
			break;
			default:
				printf("\nWrong Choice...\n");
				exit(0);
				break;
		}
	}
}

void createNode(){
	struct Node *temp, *trav;
	temp = (struct Node*)malloc(sizeof(struct Node));
	if(temp == NULL){
		printf("\nInsufficient Memory Space...");
		exit(0);
	}

	printf("\nEnter Data: ");
	scanf("%d", &temp->data);
	temp->next = NULL;

	if(start == NULL)
		start = temp;
	else{
		trav = start;
		while(trav->next != NULL){
			trav = trav->next;
		}
		trav->next = temp;
	}
}
void display(){
	struct Node* trav;
	if(start == NULL)
		printf("\nEmpty List...");
	else{
		trav = start;
		printf("\nList: \n");
		while(trav != NULL){
			printf("%d  ", trav->data);
			trav = trav->next;
		}
		printf("\n");
	}
}


