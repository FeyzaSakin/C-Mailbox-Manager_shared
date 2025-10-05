///////////////////////////////////////////////
//	Program Description	: The program stores and sorts the pieces of information 
//				in the database. The informations are sorted into as 
//				sender's and receiver's email addresses, the mail's subject, 
//				mail's content, and the date it was received on. It also 
//				assigns ID numbers to each mail. With the program, the stored
//				mails can be be shown, shown by their mail ID's, sorted based 
//				on their ID's or sender email addresses, and deleted. Also, the
//				mails can be deleted with their ID numbers.
#include "email_client_support.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize(struct Mailbox *ib)
{
	//allocate memory for 2000 emails
	ib->emails = malloc(sizeof(struct Email) * MAILBOX_SIZE);
	ib->size = 0;

	create_email("random@mail.com", user_email, "Welcome to your inbox.",
			"Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.",
			11, 20, 2020, ib);
	create_email("mmartinez@mail.com", user_email, "Padding out your inbox.",
			"Yet another email just to pad out your inbox, have fun!",
			11, 30, 2020, ib);
	create_email("dboyle@mail.com", user_email, "3rd email!",
			"Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!",
			12, 2, 2020, ib);
	create_email("cbluer@mail.com", user_email, "4th email!",
			"Content of fourth email. More coding, more fun!",
			12, 8, 2020, ib);
	create_email("cboyle@mail.com", user_email, "5th email!",
			"Content of fifth email. Coding is fun-tastic!",
			12, 18, 2020, ib);
	create_email("sblack@mail.com", user_email, "6th email!",
			"Content of sixth email. Coding is fun-tastic!",
			1, 1, 2021, ib);
	create_email("sblack@mail.com", user_email, "7th email!",
			"Body of seventh email. Coding is fun-tastic!",
			1, 5, 2021, ib);
	create_email("sblack@mail.com", user_email, "8th email!",
			"Body of eighth email. Coding is fun-tastic!",
			2, 15, 2021, ib);
	create_email("sblack@mail.com", user_email, "9th email!",
			"Body of ninth email. Coding is fun-tastic!",
			2, 25, 2021, ib);
	create_email("dboyle@mail.com", user_email, "Last email!",
			"Body of tenth email. Coding is fun-tastic!",
			3, 15, 2021, ib);
}


void create_email(char* email_add, char* rec_email, char* email_sub, char* content, int d_month, int d_day, int d_year, struct Mailbox* ib){
	ib->emails[ib->size].ID = ib->size;;
	strcpy(ib->emails[ib->size].sender, email_add);
	strcpy(ib->emails[ib->size].receiver, rec_email);
	strcpy(ib->emails[ib->size].subject, email_sub);
	strcpy(ib->emails[ib->size].body, content);
	ib->emails[ib->size].date.month = d_month;
	ib->emails[ib->size].date.day = d_day;
	ib->emails[ib->size].date.year =  d_year;
	ib->size++;
}

//	Option 1 - Show Inbox	
void show_inbox(struct Mailbox* ib){

	printf	("\nID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
	printf	("--   --------------------   --/--/----   ---------------\n"); 

	int i;
	for(i=0; i<ib->size; i++){
		printf	("%02d -", ib->emails[i].ID);
		printf	(" %-20s - ", ib->emails[i].sender);
		printf	("%02d", ib->emails[i].date.month);
		printf	("/");
		printf	("%02d", ib->emails[i].date.day);
		printf	("/%d - %-15.15s\n", ib->emails[i].date.year, ib->emails[i].subject);
	}
}

//	Option 2 - Show Email by ID	
void show_ID(struct Mailbox* ib){
	int read_ID;
	printf	("\nEnter the ID of the email you want to read:");
	printf	("\n");
	scanf	("%d", &read_ID);
	printf	("\n");

	int i;
	for(i=0; i<ib->size; i++){
		if((ib->emails[i].ID == read_ID)){
			printf	("%s - %s", ib->emails[i].sender, ib->emails[i].subject);
			printf	("\nEmail Received on: ");
			printf	("%02d/%02d/%d\n", ib->emails[i].date.month, ib->emails[i].date.day, ib->emails[i].date.year);
			printf	("\n%s", ib->emails[i].body);
			printf	("\n\n");
		}
	}
}

//	Option 3 - Sort Inbox by Sender	
void sort_Sender(struct Mailbox* ib){
	int i;
	int j;
	for(i=0; i<ib->size; i++){
		for(j = i+1; j<ib->size; j++){
			if(strcmp(ib->emails[i].sender, ib->emails[j].sender)>0){
				struct Email temp = ib->emails[i];
				ib->emails[i]=ib->emails[j];
				ib->emails[j] = temp;
			}
		}
	}
}

//	Option 4 - Sort by ID
void sort_ID(struct Mailbox* ib){
	int i;
	int j;
	for(i=0; i<ib->size; i++){
		for(j = i+1; j<ib->size; j++){
			if(ib->emails[i].ID > ib->emails[j].ID){
				struct Email temp = ib->emails[i];
				ib->emails[i]=ib->emails[j];
				ib->emails[j] = temp;
			}
		}
	}
}

//	Option 5 - Searh Inbox by Keyword	
void keyword_search(struct Mailbox* ib){
	char* keyword[200];
	printf("\nEnter the keyword you are searching for:");
	printf("\n");
	scanf("%s", keyword);

	printf	("\nID   SENDER--------------   MM/DD/YYYY   SUBJECT--------\n");
	printf  ("--   --------------------   --/--/----   ---------------\n");

	int i;
	for(i=0; i<ib->size; i++){
		if((strstr((ib->emails[i].body), keyword) != NULL)|((strstr(ib->emails[i].sender, keyword))!=NULL)|(strstr((ib->emails[i].subject), keyword) != NULL))
		{
			printf  ("%02d -", ib->emails[i].ID);
			printf  (" %-20s - ", ib->emails[i].sender);
			printf  ("%02d", ib->emails[i].date.month);
			printf  ("/");
			printf  ("%02d", ib->emails[i].date.day);
			printf  ("/%d - %-15.15s\n", ib->emails[i].date.year, ib->emails[i].subject);
		}				
	}
	printf("\n");	
}			

//	Option 6 - Delete
void delete(struct Mailbox* ib){
	int delete_ID;
	printf	("\nID of the e-mail you want to delete:");
	printf("\n");
	scanf	("%d", &delete_ID);

	int i,j;
	for(i=0; i<ib->size; i++){
		if(ib->emails[i].ID == delete_ID){
			for(j=i; j<=ib->size; j++){
				ib->emails[j]=ib->emails[j+1];
			}
			ib->size--;
		}

	}
	printf("Email with ID = %d is deleted", delete_ID);
	printf  ("\n\n");
}

//	Option 7 - Exit Inbox	
void exit_inbox(struct Mailbox* ib){
	printf("\nExiting e-mail client - Good Bye!");
	printf("\n");
	printf("\n");
	exit(0);

}

void display_inbox_menu(struct Mailbox* ib){
	int option;	/* the option the user chooses*/
	printf("\n");
	while	(1){
		printf	("***************     %s INBOX     ***************", user_email);	
		printf	("\n");
		printf	("***************   Total Inbox: %04d  ***************", ib->size);
		printf	("\n\n");
		printf ("1. Show Inbox\n");
		printf ("2. Show Email by ID\n");
		printf ("3. Sort Inbox by Sender\n");
		printf ("4. Sort Inbox by ID\n");
		printf ("5. Search Inbox by Keyword\n");
		printf ("6. Delete\n");
		printf ("7. Exit Inbox\n");
		printf	("\n");
		/* The option the user chose from above*/
		scanf("%d", &option);
		switch (option)
		{
			printf("\n");
			case 1:show_inbox(ib);
			       printf("\n");
			       break;
			case 2:show_ID(ib);
			       printf("\n");
			       break;
			case 3:sort_Sender(ib);
			       printf("\n");
			       break;
			case 4:sort_ID(ib);
			       printf("\n");
			       break;
			case 5:keyword_search(ib);
			       break;
			case 6:delete(ib);
			       break;	
			case 7:exit_inbox(ib);
			default:printf("Invalid option\n");
		}
	}
}