// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 5
#define PLAYERS 2
#define TOTALCARDS 52

// prototypes
void shuffle(unsigned int wDeck[][FACES]);  // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], unsigned int pokerHandSuits[],
          unsigned int pokerHandFaces[], const unsigned int index,
          const unsigned int numberOfCards);
int checkHand(const unsigned int pokerHandSuits[],
              const unsigned int pokerHandFaces[]);
void printHand(const char *wFace[], const char *wSuit[],
               const unsigned int pokerHandSuits[],
               const unsigned int pokerHandFaces[],
               const unsigned int handResult);
void evaluateHand(unsigned int wDeck[][FACES], unsigned int pokerHandSuits[],
                  unsigned int pokerHandFaces[], const unsigned int result);
void sort(unsigned int pokerHandSuits[], unsigned int pokerHandFaces[]);
void checkResult(const unsigned int dealerResult,
                 const unsigned int playerResult,
                 const unsigned int pokerHandSuits[][CARDS],
                 const unsigned int pokerHandFaces[][CARDS]);

int main(void) {
  // initialize deck array
  unsigned int deck[SUITS][FACES] = {0};
  unsigned int pokerHandSuits[PLAYERS][CARDS] = {0};
  unsigned int pokerHandFaces[PLAYERS][CARDS] = {0};

  srand(time(NULL));  // seed random-number generator

  shuffle(deck);  // shuffle the deck

  // initialize suit array
  const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

  // initialize face array
  const char *face[FACES] = {"Ace",  "Deuce", "Three", "Four", "Five",
                             "Six",  "Seven", "Eight", "Nine", "Ten",
                             "Jack", "Queen", "King"};

  for (size_t i = 0; i < PLAYERS; i++) {
    deal(deck, pokerHandSuits[i], pokerHandFaces[i], 0, CARDS);
    sort(pokerHandSuits[i], pokerHandFaces[i]);
  }

  int playerResult[PLAYERS];

  for (size_t i = 0; i < PLAYERS; i++) {
    playerResult[i] = checkHand(pokerHandSuits[i], pokerHandFaces[i]);
  }

  evaluateHand(deck, pokerHandSuits[0], pokerHandFaces[0], playerResult[0]);

  printf("Welcome, you hand is:\n");
  printHand(face, suit, pokerHandSuits[1], pokerHandFaces[1], playerResult[1]);
  printf("Would you like to replace your cards?[y/n] ");
  char choice;
  choice = getchar();

  if (choice == 'y') {
    int aux = 0;
    for (size_t i = 0; i < 3; i++) {
      printf("Remaining replacements: %ld\n", 3 - i);
      printf(
          "Which card would you like to replace now? [1-5] or [0] to "
          "cancel/stop\n");
      scanf("%d", &aux);
      if (aux == 0) break;
      deal(deck, pokerHandSuits[1], pokerHandFaces[1], aux - 1, 1);
    }
    sort(pokerHandSuits[1], pokerHandFaces[1]);
    printf("Your new Hand is:\n");
    playerResult[1] = checkHand(pokerHandSuits[1], pokerHandFaces[1]);
    printHand(face, suit, pokerHandSuits[1], pokerHandFaces[1],
              playerResult[1]);
  }

  playerResult[0] = checkHand(pokerHandSuits[0], pokerHandFaces[0]);
  printf("Dealer's Hand is:\n");
  printHand(face, suit, pokerHandSuits[0], pokerHandFaces[0], playerResult[0]);
  checkResult(playerResult[0], playerResult[1], pokerHandSuits, pokerHandFaces);
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES]) {
  // for each of the cards, choose slot of deck randomly
  for (size_t card = 1; card <= TOTALCARDS; ++card) {
    size_t row;     // row number
    size_t column;  // column number

    // choose new random location until unoccupied slot found
    do {
      row = rand() % SUITS;
      column = rand() % FACES;
    } while (wDeck[row][column] != 0);  // end do...while

    // place card number in chosen slot of deck
    wDeck[row][column] = card;
  }
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], unsigned int pokerHandSuits[],
          unsigned int pokerHandFaces[], const unsigned int index,
          const unsigned int numberOfCards) {
  // deal each of the cards
  static size_t card = 1;
  for (size_t i = index; i < (index + numberOfCards); ++i, ++card) {
    // loop through rows of wDeck
    for (size_t row = 0; row < SUITS; ++row) {
      // loop through columns of wDeck for current row
      for (size_t column = 0; column < FACES; ++column) {
        // if slot contains current card, display card
        if (wDeck[row][column] == card) {
          *(pokerHandSuits + i) = row;
          *(pokerHandFaces + i) = column;
        }
      }
    }
  }
}

void printHand(const char *wFace[], const char *wSuit[],
               const unsigned int pokerHandSuits[],
               const unsigned int pokerHandFaces[],
               const unsigned int handResult) {
  for (size_t i = 0; i < CARDS; i++) {
    printf("%ld - %5s of %-8s\n", i + 1, wFace[pokerHandFaces[i]],
           wSuit[pokerHandSuits[i]]);
  }
  switch (handResult) {
    case 6:
      printf("%s", "It is a Four of a Kind!\n");
      break;
    case 5:
      printf("%s", "It is a Flush!\n");
      break;
    case 4:
      printf("%s", "It is a Straight!\n");
      break;
    case 3:
      printf("%s", "It is a Three of a Kind!\n");
      break;
    case 2:
      printf("%s", "It is a Double Pair!\n");
      break;
    case 1:
      printf("%s", "It is a Pair!\n");
      break;
    case 0:
      printf("%s", "Well... it is nothing.\n");
      break;
  }
}

void sort(unsigned int pokerHandSuits[], unsigned int pokerHandFaces[]) {
  int holdSuits, holdFaces;
  for (size_t i = 1; i < CARDS; i++) {
    for (size_t j = 0; j < CARDS - 1; j++) {
      if (pokerHandFaces[j] > pokerHandFaces[j + 1]) {
        holdSuits = pokerHandSuits[j];
        pokerHandSuits[j] = pokerHandSuits[j + 1];
        pokerHandSuits[j + 1] = holdSuits;
        holdFaces = pokerHandFaces[j];
        pokerHandFaces[j] = pokerHandFaces[j + 1];
        pokerHandFaces[j + 1] = holdFaces;
      }
    }
  }
}

int checkHand(const unsigned int pokerHandSuits[],
              const unsigned int pokerHandFaces[]) {
  int checkPair(const unsigned int pokerHandFaces[]);
  int checkTwoPairs(const unsigned int pokerHandFaces[]);
  int checkThree(const unsigned int pokerHandFaces[]);
  int checkFour(const unsigned int pokerHandFaces[]);
  int checkFlush(const unsigned int pokerHandSuits[]);
  int checkStraight(const unsigned int pokerHandFaces[]);

  if (checkFour(pokerHandFaces)) {
    return 6;
  }
  if (checkFlush(pokerHandSuits)) {
    return 5;
  }
  if (checkStraight(pokerHandFaces)) {
    return 4;
  }
  if (checkThree(pokerHandFaces)) {
    return 3;
  }
  if (checkTwoPairs(pokerHandFaces)) {
    return 2;
  }
  if (checkPair(pokerHandFaces)) {
    return 1;
  }
  return 0;
}

int checkPair(const unsigned int pokerHandFaces[]) {
  for (size_t i = 0; i < CARDS - 1; i++) {
    if (pokerHandFaces[i] == pokerHandFaces[i + 1]) return 1;
  }
  return 0;
}

int checkTwoPairs(const unsigned int pokerHandFaces[]) {
  int count = 0;
  for (size_t i = 0; i < CARDS - 1; i++) {
    if (pokerHandFaces[i] == pokerHandFaces[i + 1]) count++;
  }
  if (count == 2)
    return 1;
  else
    return 0;
}

int checkThree(const unsigned int pokerHandFaces[]) {
  for (size_t i = 0; i < CARDS - 2; i++) {
    if (pokerHandFaces[i] == pokerHandFaces[i + 2]) return 1;
  }
  return 0;
}

int checkFour(const unsigned int pokerHandFaces[]) {
  for (size_t i = 0; i < CARDS - 3; i++) {
    if ((pokerHandFaces[i] == pokerHandFaces[i + 3])) return 1;
  }
  return 0;
}

int checkFlush(const unsigned int pokerHandSuits[]) {
  int count = 1;
  for (size_t i = 1; i < CARDS; i++) {
    if (pokerHandSuits[0] == pokerHandSuits[i]) count++;
  }
  if (count == 5)
    return 1;
  else
    return 0;
}

int checkStraight(const unsigned int pokerHandFaces[]) {
  // AceException
  if ((pokerHandFaces[0] == 1) && (pokerHandFaces[4] == 12)) {
    for (size_t i = 1; i < CARDS - 2; i++) {
      if (pokerHandFaces[i] == (pokerHandFaces[i + 1] + 1)) {
      } else
        return 0;
    }
  } else {
    for (size_t i = 0; i < CARDS - 1; i++) {
      if (pokerHandFaces[i] == (pokerHandFaces[i + 1] + 1)) {
      } else
        return 0;
    }
  }
  return 1;
}

void evaluateHand(unsigned int wDeck[][FACES], unsigned int pokerHandSuits[],
                  unsigned int pokerHandFaces[], const unsigned int result) {
  int saveIndex = 0;
  switch (result) {
    case 3:
      for (size_t i = 0; i < CARDS; i++) {
        if (pokerHandFaces[i] != pokerHandFaces[2]) {
          deal(wDeck, pokerHandSuits, pokerHandFaces, i, 1);
        }
      }
      sort(pokerHandSuits, pokerHandFaces);
      break;
    case 2:
      for (size_t i = 0; i < CARDS; i++) {
        int count = 0;
        for (size_t j = 0; j < CARDS; j++) {
          if (pokerHandFaces[i] == pokerHandFaces[j]) count++;
        }
        if (count < 2) {
          saveIndex = i;
          break;
        }
      }
      deal(wDeck, pokerHandSuits, pokerHandFaces, saveIndex, 1);
      sort(pokerHandSuits, pokerHandFaces);
      break;
    case 1:
      for (size_t i = 0; i < CARDS - 1; i++) {
        if (pokerHandFaces[i] == pokerHandFaces[i + 1]) {
          saveIndex = i;
          break;
        }
      }
      for (size_t i = 0; i < CARDS; i++) {
        if ((i != saveIndex) && (i != saveIndex + 1)) {
          deal(wDeck, pokerHandSuits, pokerHandFaces, i, 1);
        }
      }
      sort(pokerHandSuits, pokerHandFaces);
      break;
    case 0:
      deal(wDeck, pokerHandSuits, pokerHandFaces, 0, 3);
      sort(pokerHandSuits, pokerHandFaces);
      break;
  }
}

void checkResult(const unsigned int dealerResult,
                 const unsigned int playerResult,
                 const unsigned int pokerHandSuits[][CARDS],
                 const unsigned int pokerHandFaces[][CARDS]) {
  int saveIndex[2] = {0};
  if (dealerResult > playerResult) {
    printf("The dealer won!\n");
  } else if (playerResult > dealerResult) {
    printf("The player won!\n");
  } else {
    switch (playerResult) {
      case 5:
      case 4:
      case 0:
        if (pokerHandFaces[0][5] > pokerHandFaces[1][5]) {
          printf("The dealer won!(Higher Card)\n");
        } else if (pokerHandFaces[0][5] < pokerHandFaces[1][5]) {
          printf("The player won!(Higher Card)\n");
        } else {
          printf("DRAWN!\n");
        }
        break;
      default:
        for (size_t j = 0; j < PLAYERS; j++) {
          for (size_t i = CARDS - 1; i > 0; i--) {
            if (pokerHandFaces[j][i] == pokerHandFaces[j][i - 1]) {
              saveIndex[j] = i;
              break;
            }
          }
        }
        if (pokerHandFaces[0][saveIndex[0]] > pokerHandFaces[1][saveIndex[1]]) {
          printf("The dealer won!(Higher Card)\n");
        } else if (pokerHandFaces[0][saveIndex[0]] <
                   pokerHandFaces[1][saveIndex[1]]) {
          printf("The player won!(Higher Card)\n");
        } else {
          printf("DRAWN!\n");
        }
    }
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
