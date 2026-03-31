/*
NAME		: V.V.DURGADEVI
DATE		: 6 JAN 2026
DESCRIPTION : This project is an Address Book application in C that allows users to add, search, edit, delete, and display contacts.
			  It loads contact data from a CSV file at startup and saves updates back to the file before exiting.
*/
#include "addressbook.h"                                                // Include address book header file

int phone_unique(struct AddressBook *addressBook, char *phone)          // Check phone number uniqueness
{
    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].phone, phone) == 0)          // Compare stored phone with input phone
        {
            return 1;                                                   //not unique
        }
    }
    return 0;                                                           //unique
}
int email_unique(struct AddressBook *addressBook, char *email)          // Check email is uniqueness
{
    for(int i = 0; i < addressBook->contactCount; i++) 
    {
        if(strcmp(addressBook->contacts[i].email, email) == 0)          //Compare stored email with input email
        {
            return 1;                                                   //not unique
        }
    }
    return 0;                                                           //unique
}
int valid_phone(char *phone)                                            // Validate phone number
{
    if(strlen(phone)!=10)                                               //checking length is 10 or not
        return 1;
    else if(phone[0]<'6' || phone[0]>'9')                               //checking the first digit
        return 1;
    int i=0;
    while(phone[i])
    {
        if(phone[i]>='0' && phone[i]<='9')                              //checking the digits
            i++;
        else
            return 1;
    }
    return 0;
}
char *valid_email(char *email)                                           // Validate email
{
    if((email[0]=='\0' || email[0]=='@'))
        return NULL;
    char *res1=strstr(email,"@gmail.com");                               //checking the @gmail.com is present or not
    if(res1==NULL)
        return NULL;
    if(strcmp(res1,"@gmail.com")!=0)                                    //checking the after the @gmail.com any characters or digits present or not
        return NULL;
    return res1;
}
void add_contact(struct AddressBook *addressBook)                       // To add contact
{
    char name[50],phone[15],email[50];
    int flag=0;
    printf("enter the name : ");                                        //contact name
    scanf(" %[^\n]",name);
    int res;
    do                                                                  //phone_validation
    {
        if(flag)
            printf("Invalid or not unique phone number !! \n");
        printf("enter the phone : ");
        scanf("%s",phone);
        res=valid_phone(phone);                                          //check phone number is valid or not
        if(res == 0 && phone_unique(addressBook, phone))                //res==0 phone is valid and phone_unique returns 0 when it is unique number
            res = 1; 
        flag=1;
    }while(res);
    flag=0;
    email[0]='\0';
    char *res1;
    do                                                                  //email_validation
    {
        if(flag)
            printf("Invalid email or not unique!! \n");
        printf("enter the email : ");
        scanf("%s",email);
        res1=valid_email(email);                                         //check email is valid or not
        if(res1 && email_unique(addressBook, email))                     //res has address email is valid and email_unique returns 0 when it is unique email
            res1 = NULL; 
        flag=1;
    }while(res1==NULL);
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);     //print name,phone,email
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);
    addressBook->contactCount++;                                            // Increment contact count
}
void search_name(struct AddressBook *addressBook)                           //search name for search contact
{
    char name[50];

    printf("Enter Name to search: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].name, name) == 0)                //checking the name in contacts list or not
        {
            addressBook->index_record[addressBook->ir_size] = i;
            addressBook->ir_size++;
        }
    }
}
void search_phone(struct AddressBook *addressBook)                          //search phone for search contact
{
    char phone[15];
    int flag=0;
    int res;
    do
    {
        if(flag)
            printf("Invalid Number\n ");
        printf("Enter the Phone No: ");
        scanf("%s",phone);
        res=valid_phone(phone);
        flag=1;
        }while(res);
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].phone,phone) == 0)             //checking the phone number present in contact list or not
            {
                addressBook->index_record[addressBook->ir_size] = i;
                addressBook->ir_size++;
                break;
            }
        }
}
void search_email(struct AddressBook *addressBook)                            //search email for search contact
{
    char email[50];
    int flag=0;
    char* res;
    do
    {
        if(flag)
            printf("Invalid  email\n ");
        printf("Enter the email: ");
        scanf(" %s",email);
        res=valid_email(email);
        flag=1;
        }while(res==NULL);
        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(strcmp(addressBook->contacts[i].email,email) == 0)           //checking the email is present in contact list or not
            {
                addressBook->index_record[addressBook->ir_size] = i;
                addressBook->ir_size++;
                break;
            }
        }
}
void search_contact(struct AddressBook *addressBook)
{
    int option;
    do
    {
        addressBook->ir_size = 0;                                            //reseting  for choosing another option
        printf("\n1.Search by Name\n");
        printf("2.Search by Phone No\n");
        printf("3.Search by Email\n");
        printf("Please select one option: ");
        scanf("%d", &option);
        getchar();
        switch(option)
        {
            case 1:
                search_name(addressBook);
                break;
            case 2:
                search_phone(addressBook);
                break;
            case 3:
                search_email(addressBook);
                break;
            default:
                printf("Invalid option Please try again !!!\n");
                continue;
        }
        if(addressBook->ir_size == 0)
            printf("Contact not found\n");
        else
        {
            for(int i = 0; i < addressBook->ir_size; i++)
            {
                int k=addressBook->index_record[i];
                printf("%d %s %s %s\n",(i+1),addressBook->contacts[k].name,addressBook->contacts[k].phone,addressBook->contacts[k].email);
            }
        }return;
        

    } while(option != 4);
}
void edit_contact(struct AddressBook *addressBook)                          //to edit contact the details
{
    search_contact(addressBook);                                            //first the contact what you have to edit
    if(addressBook->ir_size == 0)
        return;
    int choice;
    do
    {
        printf("please select contact you want to edit : ");
        scanf("%d",&choice);
        if(choice>addressBook->ir_size)
            printf("Invalid choice\n");
    }while(choice>addressBook->ir_size);
    int i=addressBook->index_record[choice-1];
    printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    int option;                   
    do
    {
        printf("\nSelect one option you want to edit:\n");
	    printf("1.edit name\n");
	    printf("2.edit mobile\n");
	    printf("3.edit email\n");
	    printf("4. exit\n");
	    printf("enter the option you want edit : ");
        scanf("%d",&option);
        getchar();
        switch(option)
        {
            case 1:                                                            //for editing the name
                char new_name[50];
                printf("enter the new name : ");
                scanf(" %[^\n]",new_name);
                strcpy(addressBook->contacts[addressBook->index_record[choice-1]].name,new_name);
                break;
            case 2:                                                            //for editing the phone number
                int res,flag=0;
                char new_phone[15];
                do                                                             //phone_validation
                {
                    if(flag)
                        printf("Invalid phone number !! \n");
                    printf("enter the new phone : ");
                    scanf("%s",new_phone);
                    res=valid_phone(new_phone);
                    if(res == 0 && phone_unique(addressBook, new_phone))       //res==0 phone is valid and phone_unique returns 0 when it is unique number
                        res = 1;
                    flag=1;
                }while(res);
                strcpy(addressBook->contacts[addressBook->index_record[choice-1]].phone,new_phone);
                break;
            case 3:                                                             //for editing the email address
                flag=0;
                char new_email[15],*res1;
                new_email[0]='\0';
                do                                                              //email_validation
                {
                    if(flag)
                        printf("Invalid email !! \n");
                    printf("enter the email : ");
                    scanf("%s",new_email);
                    res1=valid_email(new_email);
                    if(res1 && email_unique(addressBook, new_email))            //res has address email is valid and email_unique returns 0 when it is unique email
                        res1 = NULL;
                    flag=1;
                }while(res1==NULL);
                strcpy(addressBook->contacts[addressBook->index_record[choice-1]].email,new_email);
                break;
            case 4:
            return;
            default:
                printf("please choose valid option\n");
                continue;
        }
        int i=addressBook->index_record[choice-1];
        printf("after edit contact : %s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }while (option!=4);                   
}
void delete_contact(struct AddressBook *addressBook)                            //delete the contact
{
    search_contact(addressBook);                                                //first search the contact
    if(addressBook->ir_size == 0)
        return;
    int choice;
    do
    {
        printf("please select contact you want to delete : ");
        scanf("%d",&choice);
        if(choice>addressBook->ir_size)
            printf("Invalid choice");
    }while(choice>addressBook->ir_size);
    int i=addressBook->index_record[choice-1];
    printf("%s %s %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    int option;                   
    printf("\nare you sure to delete \n");
    printf("1.Yes\n");
    printf("2.No\n");
    printf("select one option : ");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            int i=addressBook->index_record[choice-1];
            for(i; i < addressBook->contactCount-1;i++)                     //after delete squeezing the array
            {
                addressBook->contacts[i]=addressBook->contacts[i+1];
            }
            addressBook->contactCount--;
            printf("contact deleted successfully\n");
            break;
        case 2:
            break;
    }               
}
void list_contacts(struct AddressBook *addressBook)                        //display all the contacts
{
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%s,",addressBook->contacts[i].name);
        printf("%s,",addressBook->contacts[i].phone);
        printf("%s\n",addressBook->contacts[i].email);
    }
}
void pull_file_data(struct AddressBook * addressBook,char *file_name)       //load data from csv file
{
    FILE *fp=fopen(file_name,"r");
    int i=0;
    addressBook->contactCount = 0;
    fseek(fp, 0, SEEK_END);
    if(ftell(fp) != 0)
    {
        rewind(fp);
        while(!feof(fp))
        {
            fscanf(fp,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            i++;
        }
    }
    addressBook->contactCount=i;
    fclose(fp);
}
void push_data_to_file(struct AddressBook * addressBook,char *file_name)        //save data to csv file
{
    FILE *fp=fopen(file_name,"w");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        fprintf(fp,"%s,",addressBook->contacts[i].name);
        fprintf(fp,"%s,",addressBook->contacts[i].phone);
        fprintf(fp,"%s\n",addressBook->contacts[i].email);
    }
    fclose(fp);
}