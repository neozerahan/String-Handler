#include <stdio.h>
#include <stdlib.h>
#include "..\Header\StringHelper.h"
#include "..\Header\Constants.h"

//Calculates the lenth of a word...
int CalculateWordLength(const char * word)
{
  int length = 0;

  while(word[length] != '\0')
  {
    length++;
  }

  return length; 
}

//Copy Word02 -> Word01...
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

//Concatenates two words and returns a char pointer...
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

//Convert all letters in a word to upper-case...
char * ConvertToUpperCase(const char * word)
{
  int isUpper = TRUE;
  //Find length of the word...
  int wordLength = CalculateWordLength(word);

  //Assign memmory using malloc...
  char * captilizedWord = malloc((wordLength + 1) * sizeof(char));

  AssignLowerOrUpperCharCase(isUpper, captilizedWord, word, wordLength);
  
  return captilizedWord;
}

//Convert all letters in a word to lower-case...
char * ConvertToLowerCase(const char * word)
{
  int convertToUpperCase = FALSE;
  //Find length of the word...
  int wordLength = CalculateWordLength(word);

  //Assign memmory using malloc...
  char * lowercaseWord = malloc((wordLength + 1) * sizeof(char));

  AssignLowerOrUpperCharCase(convertToUpperCase, lowercaseWord, word, wordLength);
  
  return lowercaseWord;
}

/*Helper method that is used in ConvertToUpperCase & ConvertToLowerCase */
void AssignLowerOrUpperCharCase(const int isConvertToUpperCase, char * wordToBeConverted, const char * word, const int wordLength)
{
  int i = 0;
  int wordASCIValue = 0;
  int asciiTableBase  = 0;
  int asciiTableCeil  = 0;

  //Check if convert case to upper or lower...
  if (isConvertToUpperCase == TRUE)
  {
    asciiTableBase = LOWERCASE_ASCII_TABLE_BASE;
    asciiTableCeil = LOWERCASE_ASCII_TABLE_CEIL;
  } 
  else 
  {
    asciiTableBase = UPPERCASE_ASCII_TABLE_BASE;
    asciiTableCeil = UPPERCASE_ASCII_TABLE_CEIL;
  } 

  while ( i < wordLength)
  {
    //Check if the word needs to capitalized or lower-cased...
    if (word[i] >= asciiTableBase && word[i] <= asciiTableCeil)
    {
      wordASCIValue = word[i];
      if (isConvertToUpperCase == TRUE)
      {
        //Convert to upper-case by subtracting the ASCII value of the character...
        wordToBeConverted[i] = wordASCIValue - CONVERT_TO_LOWER_CASE;
      }
      else
      {
        //Convert to lower-case by adding the ASCII value of the character...
        wordToBeConverted[i] = wordASCIValue + CONVERT_TO_LOWER_CASE;
      }
    }
     else
     {
      wordToBeConverted[i] = word[i];
     }
    i++;
  }
  wordToBeConverted[wordLength] = '\0';
}




