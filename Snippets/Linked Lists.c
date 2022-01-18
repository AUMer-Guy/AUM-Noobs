#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//	declare struct patient contains the following fields
typed struct
{
	int file_num;
	char p_name[60];
	float p_bill;
	struct NODE *next;
}NODE;

//function declarations
void Display(struct node *head);
char* Look_num(struct node *head, int FN);
void Lowest(struct node *head);

int main()
{
	struct node *head = NULL;	//first node
	struct node *temp;			//new node
	struct node *p = NULL;		//walking pointer
	char* result = NULL;		//result of the function call
	int N;						//the number of nodes
	int i;						// loop counter
	int option;					//user option continue or stop
	int FN;						//file number

								//Ask the user to enter the number patients
	printf("How many patients? ");
	scanf("%d", &N);

	//	cinitialize and create the linked list
	for (i = 1; i <= N; i++)
	{
		//create a new node
		temp = (struct node *) malloc(sizeof(struct node));
		if (temp == NULL)
		{
			printf("Error allocating memory");
			exit(100);
		}
		temp->next = NULL;

		//Fill the fields of the new node
		printf("\nEnter the patient %d (file number, name and bill): ", i);
		scanf("%d %s %f", &temp->file_num, temp->p_name, &temp->p_bill);

		if (head == NULL)	//first node
			head = temp;
		else				//all nodes except first one
			p->next = temp;		//add the temp to the end of the linked list

		p = temp;	// for next addition

		if (i < N)	// check end or not yet
		{
			// validate the option 1 or 0
			do {
				//ask the user if he/she wants to continue adding or to stop
				printf("\nDo you want to continue (1: Continue,   0: Stop) [1/0]: ");
				scanf("%d", &option);

				if (option == 1 || option == 0)
					break;
				else
					printf("\nError input! [1/0]\n");
			} while (option < 0 || option > 1);

			if (option == 0)	// exit the for loop
				break;
		}
	}
	// print the linked list
	Display(head);

	//ask user to enter a file number
	printf("\nEnter the file number to look for: ");
	scanf("%d", &FN);

	//search for the entered file number
	result = Look_num(head, FN);
	if (strcmp(result, "-1") != 0)
		printf("\nPatient number: %d \t Name: %s is found\n", FN, result);
	else
		printf("\nPatient number: %d is not found\n", FN);

	// find the Lowest
	Lowest(head);

	system("pause");
	return 0;
}
// Display the linked list
void Display(struct node *head)
{
	//to navigate through the linked list nodes
	struct node *p = head;

	printf("------------------------------------------------------------------------\n");

	// print till the end of the linked list
	while (p != NULL)
	{
		printf("Patient: File number: %d \t Name: %s \t Bill: %.2f\n", p->file_num, p->p_name, p->p_bill);
		p = p->next;		//go next
	}
}
//search for a patient by its file number
char* Look_num(struct node *head, int FN)
{
	struct node *p = head;

	//search till the end of the linked list
	while (p != NULL)
	{
		//FN found in the current node
		if (p->file_num == FN)
			return p->p_name;

		p = p->next;	//go to next node
	}
	return (char*) "-1";		//-1 means the file number is not found
}
//	prints the name of patient having the lowest bill to be paid
void Lowest(struct node *head)
{
	struct node *p = head;
	struct node *MinPatient = head;

	// find lowest till the end of the linked list
	while (p != NULL)
	{
		if (p->p_bill < MinPatient->p_bill)
			MinPatient = p;

		p = p->next;		//go to next node
	}
	printf("\nThe name of patient having the lowest bill to be paid is: %s\n", MinPatient->p_name);
}
