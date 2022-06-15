//THIS IS THE PROGRAM WHERE MENU FOR INSTANT CHATTERS AND MAIN PAGE OF APPLICATION
/**********************************************************************************************
 ** FILENAME   :   server.c
 **

 **
 ********************************************************************************************************************************************************************************************HEADER FILES
 *********************************************************************************************/


#include "header2.h"
struct user
{
        char fullName[50];
        char email[50];
        char password[50];
        char username[50];
        char phone[50];
};
void registration ();
void login ();
void takeinput (char ch[50]);
char generateUsername (char email[50], char username[50]);

// main function
//Menu for Instant Chatters Requirements
int main ()
{

        int opt;

        printf
                ("\n\t\t\t\t-------------Welcome to Instant Chatters ---------------");
        printf ("\nPlease choose your operation");
        printf ("\n1.Registration");
        printf ("\n2.Login using Credentials");
        printf ("\n3.Sign-Out");
        do
        {
                printf ("\n\n Enter your choice:\t"); //Enter the choice of user
                scanf ("%d", &opt);
                fgetc (stdin);// selecting according to  the conditions given
                switch (opt)
                {
                        case 1:
                                registration ();// new user
                                break;

                        case 2:
                                login ();// new user or existing user login
                                break;
                        case 3:
                                printf ("\t\t\tBye Bye :)\n");//terminates
                                exit (0);
                                return 0;
                        default:
                                printf ("Invalid Choice");// Invalid
                }
        }
        while (opt <= 3);



        return 0;
}