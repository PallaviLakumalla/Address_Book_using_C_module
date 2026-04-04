/*
NAME		: V.V.DURGADEVI
DATE		: 6 JAN 2026
DESCRIPTION : This project is an Address Book application in C that allows users to add, search, edit, delete, and display contacts.
			  It loads contact data from a CSV file at startup and saves updates back to the file before exiting.
*/
#include "addressbook.h"				// Include address book header file
int main() 
{
    int choice;

    struct AddressBook addressBook;						// Declare AddressBook structure variable
	pull_file_data(&addressBook,"database.csv");		// Load existing contacts from CSV file into structure
    do 													// Display menu 
    {
	printf("\nAddress Book Menu:\n");
	printf("1. Add/Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	
	scanf("%d", &choice);
	getchar();
	switch (choice) 
	{
	    case 1:
		add_contact(&addressBook);
		break;
	    case 2:
		search_contact(&addressBook);
		break;
	    case 3:
		edit_contact(&addressBook);
		break;
	    case 4:
		delete_contact(&addressBook);
		break;
	    case 5:
		list_contacts(&addressBook);
		break;
	    case 6:
		printf("Saving and Exiting...\n");
		push_data_to_file(&addressBook,"database.csv");			// Save data to CSV file
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);

    return 0;
}
