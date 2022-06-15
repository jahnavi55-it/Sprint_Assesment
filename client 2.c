//THIS IS THE CLIENT PROGRAM WHERE CONNECTING TO SERVER AND SENDING MESSAGES TO SERVER HAPPENS
/**********************************************************************************************
 ** FILENAME   :   client2.c
 **
 ** DESCRIPTION  :  sending message to server
 **
 ** REVISION HISTORY  : V_1.3
 ********************************************************************************************************************************************************************************************
                                  HEADER FILES
 *********************************************************************************************/
#include "header1.h"
int main() {

        //declaration of variables
        int clientSocket;
        char buffer[1024];
        //serverAddr is a structure of type struct sockaddr_in
        struct sockaddr_in serverAddr;
        //addr_size is a variable of socklen_t
        socklen_t addr_size;
        //initialising cmdexit to 0
        int cmdEXIT = 0;
        //socket parameters
        int compare_strings(char a[],char b[]);
        clientSocket = socket(PF_INET, SOCK_STREAM, 0);
        //initialising struct servAddr members
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //setting sin_zero to '\0'
        memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
        //initialising addr_size to size of serverAddr
        addr_size = sizeof serverAddr;
        //initialising addr_size to size of serverAddr
        connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
        // messages
        //terminating statement "bye"
        while (cmdEXIT == 0)
        {
                //declaration and assigning  of recvValue
                int recvValue = recv(clientSocket, buffer, sizeof buffer - 1, 0);
                //recvValue =1 it means that there is no message received ,the line is free and the client can type his own msg,otherwise he has to display the msg and only after that he can send his own text
                if (recvValue != 1)
                {
                        //comparing buffer  with "bye"
                        if (compare_strings(buffer, "bye")==-1)
                        {
                                //displaying the message of client1
                                printf("Client 1 : ");
                                printf("%s\n", buffer);
                                //setting buffer to '\0'
                                memset(&buffer[0], 0, sizeof(buffer));
                        }
                        else cmdEXIT = 1;
                }
                else
                {
                        //message from Client2
                        printf("Client 2 : ");
                        //reading buffer from keyboard
                        scanf(" %[^\n]s", buffer);
                        send(clientSocket,buffer,sizeof buffer - 1,0);
                        // "bye"
                        //compare buffer with "bye"
                        if (compare_strings(buffer, "bye")==-1)
                        {
                                //settting to buffer to 0
                                memset(&buffer[0], 0, sizeof(buffer));
                        }
                        else cmdEXIT = 1;
                }
        }
        close(clientSocket);
        return 0;
}