#include <stdio.h>
#include <stdlib.h>
#include "..\Header\StringHelper.h"
#include "..\Header\Constants.h"

int main(void)
{
  printf("This is a test application to demonstrate a custom helper code that...\n");
  printf("1. Checks if the words match.\n");
  printf("2. Copies Word01 to Word02\n");
  printf("3. Concatenates them.\n");
   printf("--------------------------------------------------------------------");

  printf("\n");

  char word01[50];
  char word02[50];
  char * word03;

  printf("Enter Word01: ");
  scanf("%s", word01);
  
  printf("Enter Word02: ");
  scanf("%s", word02);

  int isSame = CompareWords(word01, word02);

  printf("\n");

  if (isSame == FALSE)
  {
    printf("The words don't match!\n");
  } 
    else 
       {
         printf("The words match!\n");
       }

  word03 = ConnectWords(word01, word02);

  CopyWord(word01, word02);

  printf("\n");

  printf("Word01 is now: %s\n", word01);
  
  printf("\n");

  printf("Connected Word: %s\n", word03);

  printf("\n");

  printf("Press any key to continue...\n");

  ClearBuffer();

  getchar();
}

