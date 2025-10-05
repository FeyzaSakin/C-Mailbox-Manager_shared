#ifndef EMAIL_CLIENT_SUPPORT_INCLUDED
#define EMAIL_CLIENT_SUPPORT_INCLUDED

#define MAILBOX_SIZE 2000
#define ADDRESS_SIZE 50
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
#define user_email "Personal"

//	Declaring Email struct
struct Email
{
	char sender[ADDRESS_SIZE];
	char receiver[ADDRESS_SIZE];
	char subject[SUBJECT_SIZE];	
	char body[BODY_SIZE];
	struct sent_date
	{
		int month;
		int day;
		int year;

	}date; 
	int ID; 
};

//	Declaring Mailbox struct
struct Mailbox
{

	struct Email* emails;
	int size;

};

///////////////////////////////////////////////////////////////////////////////
// This is a sample comment for the initialize function
// You should include a similar comment for each function declared within the 
// 	.h file
//
// Function     : initialize
// Description  : Initializes the database for the project manually by
//                entering the records using create_email function
// Inputs       : struct Mailbox *ib - pointer to the database
// Outputs      : void
void initialize(struct Mailbox *ib);

//Function	: create_email
//Description	: With strcpy, it stores and sorts the mail's information into the 
//		sender's email address, the receiver's email address, the subject 
//		of the mail, and the month, the day, and the year the mail was 
//		received. Assigns ID numbers to each mail.
//Inputs	: char* email_add - pointer to the email address of the mail sender, 
//		char* rec_email - the pointer to the mail receiver, 
//		char* email_sub - the pointer to the subject of the mail, 
//		char* content - the pointer to the body of the mail, 
//		int d_month - the month the mail was sent, 
//		int d_day - the day the mail was sent, 
//		int d_year - the year the mail was sent, 
//		struct Mailbox *ib - pointer to the database
//Output	: none
void create_email(char* email_add, char* rec_email, char* email_sub, char* content, int d_month, int d_day, int d_year, struct Mailbox* ib);

//Function      : show_inbox 
//Description   : Prints out the stored information the database as an inbox 
//		with the mail's ID number, sender and receiver email addresses, the 
//		date it was received, and its subject.
//Inputs        : struct Mailbox *ib - pointer to the database
//Output	: strings and integers
void show_inbox(struct Mailbox* ib);

//Function	:show_ID
//Description	:Asks the user to type the ID number. Then compares the given ID
//		number in the stored ID numbers. When the ID number is same as the 
//		stored ID numbers, it shows the email address of the ID number, its 
//		subject, and the date it was received on.
//Inputs	:struct Mailbox *ib - pointer to the database
//		int read_ID - an integer input for the asked mail's ID	
//Output	:string and integers
void show_ID(struct Mailbox* ib);

//Function	:sort_sender
//Description	:Compares the initial of the sender email address' with strcmp. 
//		When strcmp is bigger than 0, the current email address' 
//		initial is after than the next email address' initial in the 
//		alphabet. So, it stores the current mail address in struct Email temp. 
//		It writes the next mail into the current mail. Finally, it writes the 
//		current mail into the next mail's previous place.
//Inputs	:struct Mailbox *ib - pointer to the database
//Output	:none
void sort_Sender(struct Mailbox* ib);

//Function      :sort_ID
//Description   :Compares the ID number of the mails in the inbox with strcmp. When
//		strcmp is bigger than 0, the current ID number is bigger
//		than the ID number of the next mail. So, it stores the current mail in 
//		struct Email temp. It writes the next mail into the current mail address. 
//		Finally, it writes the current mail into the next mail's previous
//		place.
//Inputs        :struct Mailbox *ib - pointer to the database
//Output        :none
void sort_ID(struct Mailbox* ib);

//Function	:keyword_search
//Description	:Asks the keyword the user is searching for. Then it compares the string
//		through the stored mail subjects, mail senders, and mail contents. It
//		prints out the mails that contain the asked keyword with them in their 
//		subject, content, and the email addresses.
//Inputs	:struct Mailbox *ib - pointer to the database
//		char* keyword - pointer to word that needs to be searched
//Output	:string and integers
void keyword_search(struct Mailbox* ib);

//Function	:delete
//Description	:Asks the user to type the asked mail's ID number. Then it compares all
//		the stored IDs with the input. The mail with the same ID gets placed 
//		with the mail after her, and other mails shifts to left. The 
//		size is increased. Finally, the function prints out that the asked mail
//		is deleted while stating its ID.
//Inputs	:struct Mailbox *ib - pointer to the database
//		int delete_ID - the integer input for the asked mail's ID
//Output	:string and integer
void delete(struct Mailbox* ib);

//Function	:exit_inbox
//Description	:Exits the program using exit(0) after printing out "Exiting e-mail client - Good Bye!"
//Inputs	:struct Mailbox *ib - pointer to the database
//Output	:string
void exit_inbox(struct Mailbox* ib); 

#endif // EMAIL_CLIENT_SUPPORT_INCLUDED