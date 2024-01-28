#include <stdio.h>
#include <stdlib.h>
#include "..\Header\StringHelper.h"
#include "..\Header\Constants.h"

int main(void)
{
  printf("-------------------String Handler Functions---------------------------\n");

  printf("\n");

  printf("This is a test application to demonstrate a custom helper code that...\n");
  printf("1. Checks if the words match.\n");
  printf("2. Copies Word01 to Word02\n");
  printf("3. Concatenates them.\n");
  printf("4. Converts letters to upper-case & lower-case.\n");
  
  printf("\n");

  printf("--------------------------------------------------------------------\n");
  printf("INPUT DATA:\n");
  
  printf("\n");
  
  char word01[50];
  char word02[50];
  char * word03;
  char * capitalizedWord01;
  char * lowercaseWord02;

  printf("Enter Word01: ");
  scanf("%s", word01);
  
  printf("Enter Word02: ");
  scanf("%s", word02);

  printf("\n");

  printf("--------------------------------------------------------------------\n");

  printf("OUTPUT:\n");

  printf("\n");

  int isSame = CompareWords(word01, word02);

  //Convert characters of Word02 to upper-cases...
  capitalizedWord01 = ConvertToUpperCase(word01);
  printf("-->Converts all letters to upper-case for Word 01: %s\n", capitalizedWord01);

  printf("\n");

  //Convert characters of Word02 to lower-cases...
  lowercaseWord02 = ConvertToLowerCase(word02);
  printf("-->Converts all letters to lower-case for Word 02: %s\n", lowercaseWord02);

  free(lowercaseWord02);
  free(capitalizedWord01);

  printf("\n");

  printf("-->Check if the words match: ");

  //Check if the words are same...
  if (isSame == FALSE)
  {
    printf("Match Failed!\n");
  } 
    else 
       {
         printf("Match Successfull!\n");
       }

  //Concantenate both words...
  word03 = ConnectWords(word01, word02);

  //Copy Word02 to Word01
  CopyWord(word01, word02);

  printf("\n");

  printf("-->Word02 has been copied to Word01. Word01 is now: %s\n", word01);
  
  printf("\n");

  printf("-->Word01 and Word02 has been concatenated: %s\n", word03);

  printf("\n");

  printf("Press any key to continue...\n");

  ClearBuffer();

  getchar();
}

