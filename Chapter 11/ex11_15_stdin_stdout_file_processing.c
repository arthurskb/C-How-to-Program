// Fig. 8.11: fig08_11.c
#include <stdio.h>
#define SIZE 80

void clearBuffer();

int main(void)
{
  int c;
  char sentence[SIZE];
  int i = 0;
  FILE *fPtr;
  fputs("Would you like to read/write from/to the standard input or from/to a specified file? (0 - stdin or 1 - specified file) ", stdout);
  int choice;
  scanf("%d", &choice);

  if (choice) {

    fputs("Insert the name of the file with the proper extension to read: (example: file.txt) ", stdout);
    char fileName[SIZE];
    scanf("%s", fileName);
    if ((fPtr = fopen(fileName, "r")) == NULL) {
      printf("Failed to open the file\n");
      return 1;
    }
    while ((i < SIZE - 1) && (c = fgetc(fPtr)) != '\n' && c != EOF) {
       sentence[i++] = c;
    }
    sentence[i] = '\0'; // terminate string
    fputs("Insert the name of the file with the proper extension to write: (example: file.txt) ", stdout);
    scanf("%s", fileName);
    if((fPtr = fopen(fileName, "wx")) == NULL) {
      printf("Failed to open the file\n");
      return 1;
    }
    fputs(sentence, fPtr);

  } else {

    fputs("Enter a line of text:\n", stdout);
    clearBuffer();
    while ((i < SIZE - 1) && (c = fgetc(stdin)) != '\n') {
       sentence[i++] = c;
    }
    sentence[i] = '\0'; // terminate string
    fputs("The line entered was: ", stdout);
    fputs(sentence, stdout);
    fputs("\n", stdout);

  }

}

void clearBuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
