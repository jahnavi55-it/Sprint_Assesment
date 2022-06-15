#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"registration.h"

int
main ()
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
      printf ("\n\n Enter your choice:\t");
      scanf ("%d", &opt);
      fgetc (stdin);
      switch (opt)
        {
        case 1:
          registration ();
          break;

        case 2:
          login ();
          break;
        case 3:
          printf ("\t\t\tBye Bye :)\n");
          exit (0);
          return 0;
        default:
          printf ("Invalid Choice");
        }
    }
  while (opt <= 3);



  return 0;
}