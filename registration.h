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