#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>
#include<string.h>

struct Contact                      // Structure to store individual contact details
{
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook                  // Structure to manage multiple contacts
{
    struct Contact contacts[100];    // Array to store up to 100 contacts
    int contactCount;                // Variable to store number of contacts
    int index_record[100];           // Array to store index records for search
    int ir_size;                     // Variable to store size of index_record
};

void pull_file_data(struct AddressBook *, char *); // Function to load data from file
void push_data_to_file(struct AddressBook *, char *); // Function to save data to file
void add_contact(struct AddressBook *addressBook);    // Function to add a new contact
void search_contact(struct AddressBook *addressBook); // Function to search contacts
void edit_contact(struct AddressBook *addressBook);   // Function to edit contact details
void delete_contact(struct AddressBook *addressBook); // Function to delete a contact
void list_contacts(struct AddressBook *addressBook);  // Function to display all contacts
int valid_phone(char *);                              // Function to validate phone number
char *valid_email(char *);                            // Function to validate email ID
void search_name(struct AddressBook *);               // Function to search by name
void search_phone(struct AddressBook *);              // Function to search by phone number
void search_email(struct AddressBook *);              // Function to search by email ID
int phone_unique(struct AddressBook *, char *);       // Function to check phone number uniqueness
int phone_unique(struct AddressBook *, char *);       // Duplicate declaration (can be removed)

#endif
