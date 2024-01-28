#include <stdio.h>
#include <stdlib.h>
#include "..\Header\StringHelper.h"

int CalculateWordLength(const char * word)
{
  int length = 0;

  while(word[length] != '\0')
  {
    length++;
  }

  return length; 
}

void CopyWord(char * word01, const char * word02)
{
  /*Calculates the length of word 02...*/
  int word02Length = CalculateWordLength(word02);
 
  /*Inserts the letters from word02 to word01...*/
  int i = 0;
  while( i < word02Length)
  {
    word01[i] = word02[i];
    i++;
  }

  /*Adds a null terminator at the end...*/
  word01[i] = '\0';

  return;  
}

//concatenates two words and returns a char pointer...
char * ConnectWords(const char * word01, const char * word02)
{
  int stringLength01 = CalculateWordLength(word01);
  int stringLength02 = CalculateWordLength(word02);    
  
  //Calculate the size of word01 and 02...
  char * connectWord = malloc((stringLength01 + stringLength02 + 1) * sizeof(char));
  
  //iterate through word01 and copy it in ConnectWord...
  int i = 0;
  while(i < stringLength01)
  {
    connectWord[i] = word01[i];
    i++;
  }
 
  //Add space between two words...
  connectWord[i] = ' ';
  
  //iterate through word02 and appends it in ConnectWord...
  int j = 0;
  while (j < stringLength02)
  {
    connectWord[j + stringLength01+1] = word02[j];
    j++;
  }
  
  //Adds null terminator at the end of the string...
  connectWord[stringLength01 + stringLength02+1] = '\0';

  return connectWord;
  
}

//Clears buffer by consuming them using getchar...
void ClearBuffer()
{
	char c;
	c = getchar();
	while (c!='\n' && c!= '\0')
	{
		printf("Buffer cleared!!!\n");
	}
}

//Compares two words and returns 0 = false or 1 = true...
int CompareWords(const char * word01, const char * word02)
{
  int word01Length = CalculateWordLength(word01);
  int word02Length = CalculateWordLength(word02);

  if (word01Length != word02Length) return FALSE;
  
  int i = 0;

  while( i <= word01Length)
    {
      //printf("word01[%c] = word02[%c]\n", word01[i], word02[i]);
      if (word01[i] != word02[i]) 
        { 
           return FALSE;
        }
        else 
            {
               i++;
            }    
     }
  return TRUE;
}




