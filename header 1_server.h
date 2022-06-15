#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#define LOGFILE "/home/cguser13/project/log/serverlog.log"
#define port 8013
void server();
void registration ();
void login ();
void takeinput (char ch[50]);
char generateUsername (char email[50], char username[50]);