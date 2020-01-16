#include <stdio.h>
#include <stdlib.h>

void createNode();	//insert node at last position
void display();
void deleteLast();
void insertFirst();
void deleteFirst();

struct Node{
	int data;
	struct Node* next;
};
struct Node* start = NULL;

int main(){
	int choice;
	while(1){
		printf("\n1.Create Node\n2.Display List\n3.Delete Last Node\n4.Insert Node at Fist position\n5.Delete First Node\n>>");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				createNode();
			break;
			case 2:
				display();
			break;
			case 3:
				deleteLast();
			break;
			case 4:
				insertFirst();
			break;
			case 5:
				deleteFirst();				
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
void deleteLast(){
	struct Node *temp, *trav;
	if(start == NULL)
		printf("List is Empty\n");
	else if(start->next == NULL){
			trav = start;
			start = NULL;
			printf("%d deleted\n", trav->data);
			free(trav);
	}
	else{
		trav = start;
		while(trav->next != NULL){
			temp = trav;
			trav = trav->next;
		}
		temp->next = NULL;
		printf("%d deleted\n", trav->data);
		free(trav);
	}
}

void insertFirst(){
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
		start = temp;
		temp->next = trav;
	}
}
void deleteFirst(){
	struct Node *trav;
	if(start == NULL)
		printf("List is Empty\n");
	else if(start->next == NULL){
		trav = start;
		start = NULL;
	}
	else{
		trav = start;
		start = start->next;
	}
	printf("%d deleted\n",trav->data);
	free(trav);
}


