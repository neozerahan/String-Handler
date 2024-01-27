#include <stdio.h>
#include <stdlib.h>
#include "..\Header\StringHelper.h"

int main(void)
{
  char word01[50];
  char word02[50];
  char * word03;

  printf("Enter Word01: ");
  scanf("%s", word01);
  
  printf("Enter Word02: ");
  scanf("%s", word02);
  word03 = ConnectWords(word01, word02);
  CopyWord(word01, word02);
  

  printf("Word01: %s\n", word01);
  printf("Word03: %s\n", word03);

}

