/*******************************************************************************/
//THIS IS CLIENT1 PROGRAM WHERE CONNECTING TO SERVER SOCKET AND MESSAGE SENDING TO SERVER HAPPENS
/************************************************************************************************FILENAME  :  client1.c
 **
 **DESCRIPTION  :  sending messages to server side
 **
 **REVISION HISTORY : v_1.3
 ***********************************************************************************************
 **********************************************************************************************
                                               HEADER FILES
 **********************************************************************************************/

#include"header1.h"
int main() {
        //declaration of variables
        int clientSocket;
        char buffer[1024];
        //serverAddr is a variable of type struct sockaddr_in
        struct sockaddr_in serverAddr;
        //addr_size is a variable of type of socklen_t
        socklen_t addr_size;
        int cmdEXIT = 0;
        int compare_strings(char a[],char b[]);
        //socket parameters
        //socket connection
        clientSocket = socket(PF_INET, SOCK_STREAM, 0);

        //initialising of  struct serverAddr members
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //setting of sin_zero to '\0'
        memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
        //initialising addr_size to sizeof serverAddr structure
        addr_size = sizeof serverAddr;

        //connection of server
        if( connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size)!=0)
        {
                printf("The Server connection was lost...\n");
                exit(1);
        }
        printf("Server is up and running..\n");

        //message from Client1
        printf("Client 1 : ");
        //reading buffer from the Client1(through keyboard)
        scanf(" %[^\n]s", buffer);
        //sending of that buffer to server
        send(clientSocket,buffer,sizeof buffer - 1,0);
        // messages
        //terminating statement "bye"
        //while loop terminates when cmdexit=1
        while (cmdEXIT == 0)
        {
                if (compare_strings(buffer, "bye")==-1)
                {
                        //setting buffer to 0
                        memset(&buffer[0], 0, sizeof(buffer));
                        //declaring recvValue for the purpose of type and displaying messages
                        int recvValue = recv(clientSocket, buffer, sizeof buffer - 1, 0);
                        //if recv=1,it means no msg is received ,the line is free and client can type his own msg , otherwise he has to display the received message
                        if (recvValue != 1)
                        {       // "bye"
                                        //as receive value is not 1 means some msg is received from the cient2 to server,so display the message
                                if (compare_strings(buffer, "bye")==-1)
                                {
                                        printf("Client 2 : ");
                                        printf("%s\n", buffer);
                                        memset(&buffer[0], 0, sizeof(buffer));
                                }
                                else cmdEXIT=1;
                        }
                         //recvValue = 1 means no message from server so client1 has to give the text
                        else
                        {
                                //reading the message from client1
                                printf("Client 1 : ");
                                scanf(" %[^\n]s", buffer);
                                //sending the buffer to server
                                send(clientSocket,buffer,sizeof buffer - 1,0);
                        }
                }
                else cmdEXIT=1;
        }
        close(clientSocket);

        return 0;
}