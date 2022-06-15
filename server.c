// THIS IS THE PROGRAM WHERE ALL THE SOCKET CREATION,BINDING  ACCEPTING THE CLIENTS AND MESSAGE SENDING AND RECEIVING MESSAGES WILL HAPPEN
/***************************************************************
 ** FILENAME     :    functions.c
 **
 ** DESCRIPTION  :    chat between two clients
 **

 **************************************************************/
/*************************************************************
                           HEADER FILES
 ****************************************************************/
#include"header1.h"
int compare_strings(char a[], char b[]);
struct user
{
        char fullName[50];
        char email[50];
        char password[50];
        char username[50];
        char phone[50];
};
//listing functions
void server();
void registration ();
void login ();
void takeinput (char ch[50]);
char generateUsername (char email[50], char username[50]);
// Registration function
// new user can register using functions
void registration()
{
        FILE *fp;

        char password2[50];
        struct user user;
        printf ("\nEnter your full name:\t");
        takeinput (user.fullName);
        printf ("\nEnter your email:\t");
        takeinput (user.email);
        printf ("\nEnter your contact number:\t");
        takeinput (user.phone);
        printf ("\nEnter your password:\t");
        takeinput (user.password);
        printf ("\nConfirm your password:\t");
        takeinput (password2);
        if (!strcmp (user.password, password2))
        {
                generateUsername (user.email, user.username);
                fp = fopen ("user.data", "a+");
                fwrite (&user, sizeof (struct user), 1, fp);
                if (fwrite != 0)
                {
                        printf ("\n\n User regisration success,Your username is %s",
                                        user.username);

                }
                else
                {
                        printf ("\n\nSorry! Something went wrong:(");

                }
                fclose (fp);

        }
        else
        {
                printf ("\nPassword do not matched");


        }
}
// Login Functions
void login ()
{
        FILE *fp;
        int usrFound = 0;
        char username[50], pword[50];
        struct user usr;
        printf ("\nEnter your username:\t");
        takeinput (username);
        printf ("Enter your password:\t");
        takeinput (pword);


        fp = fopen ("user.data", "r");
        // User data input
        while (fread (&usr, sizeof (struct user), 1, fp))
        {
                if (!strcmp (usr.username, username))
                {
                        if (!strcmp (usr.password, pword))
                        {
                                printf ("\n\t\t\t\t\t\t\t\t\t Welcome %s\n", usr.fullName);
                                printf
                                        ("\n-------------------------------------------------------------------------------------------------------------------------------\n");
                                printf ("\n|Full Name:\t%s", usr.fullName);
                                printf ("\n|Email:\t\t%s", usr.email);
                                printf ("\n|Username:\t%s", usr.username);
                                printf ("\n|Contact no:\t%s", usr.phone);

                        }
                        else
                        {
                                printf ("\nInvalid Password!!!");

                        }
                        usrFound = 1;
                        server();

                }

        }
        if (!usrFound)
        {
                printf ("\n\nUser is not registered");

        }
        fclose (fp);
}
void takeinput (char ch[50])
{
        fgets (ch, 50, stdin);
        ch[strlen (ch) - 1] = 0;
}

char generateUsername (char email[50], char username[50])
{
        for (int i = 0; i < strlen (email); i++)
        {
                if (email[i] == 'g')
                        break;
                else
                        username[i] = email[i];
        }
}

// Server functions
void server()
{
        int welcomeSocket, Client1, Client2;// declaration of variables
        struct sockaddr_in serverAddr; //servAddr is a variable of type struct sockaddr_in which is predifined
        struct sockaddr_storage serverStorage;// serverStorage is a variable of type struct sockaddr_storage which stores info about socket address
        socklen_t addr_size;  //addr_size is a variable of type socklen_t
        char buffer[1024];
        welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
        if(welcomeSocket==-1){
                printf("Socket creation failed..\n");
                exit(1);
        }
        printf("Socket successfully connected..\n");
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.01");
        memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
        if( bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr))!=0){
                printf("Socket binding failed");
                exit(1);
        }
        printf("Socket successfully binded..\n");
        if (listen(welcomeSocket,5)==0)
                printf("Listening\n");
        else
                printf("Error\n");
        addr_size = sizeof serverStorage;
        Client1 = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
        if(Client1==-1){
                printf("server accept failed..\n");
                exit(1);
        }
        printf("Server accepted client1..\n");
        Client2 = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
        if(Client2==-1){
                printf("server accept failed..\n");
                exit(1);
        }
        printf("Server accepted client2..\n");
        int cmdEXIT = 0;
        while (cmdEXIT == 0)
        {
                recv(Client1, buffer, 1024, 0);
                printf ("%s\nmessage to Client2\n", buffer);
                send(Client2,buffer,1024,0);
                if (compare_strings(buffer, "bye")==0)
                {
                        cmdEXIT = 1;
                }
                else
                {
                        memset(&buffer[0], 0, sizeof(buffer));
                        recv(Client2, buffer, 1024, 0);
                        printf ("%s\nmessage to client1\n", buffer);
                        send(Client1,buffer,1024,0);
                        if (compare_strings(buffer, "bye")==0)
                        {
                                cmdEXIT = 1;
                        }
                }
        }
        close(client1);
        close(client2);
        close(welcomeSocket);


}
// compare functions
int compare_strings(char a[], char b[])
{
        int c = 0;
        while (a[c] == b[c])
        {
                if (a[c] == '\0' || b[c] == '\0')
                        break;
                c++;
        }
        if (a[c] == '\0' && b[c] == '\0')
                return 0;
        else
                return -1;
}