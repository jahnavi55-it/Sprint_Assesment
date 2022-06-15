#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"registration.h"


void registration ()
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