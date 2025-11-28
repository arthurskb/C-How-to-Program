// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 5
#define PLAYERS 2

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
        const char *wSuit[], unsigned int pokerHandSuits[], unsigned int pokerHandFaces[], int handNumber); // dealing doesn't modify the arrays
int checkHand(const unsigned int pokerHandSuits[], const unsigned int pokerHandFaces[]);

int main(void)
{
        // initialize deck array
        unsigned int deck[SUITS][FACES] = { 0 };
        unsigned int pokerHandSuits[PLAYERS][CARDS] = { 0 };
	unsigned int pokerHandFaces[PLAYERS][CARDS] = { 0 };

	srand(time(NULL)); // seed random-number generator

        shuffle(deck); // shuffle the deck

        // initialize suit array
        const char *suit[SUITS] =
                {"Hearts", "Diamonds", "Clubs", "Spades"};

        // initialize face array
        const char *face[FACES] =
                {"Ace", "Deuce", "Three", "Four",
                 "Five", "Six", "Seven", "Eight",
                 "Nine", "Ten", "Jack", "Queen", "King"};
	
	for (size_t i = 0; i < PLAYERS; i++) {
        	deal(deck, face, suit, pokerHandSuits[i], pokerHandFaces[i], i+1); // deal the deck
	}
	
	int playerResult[PLAYERS];
	for (size_t i = 0; i < PLAYERS; i++) {
		playerResult[i] = checkHand(pokerHandSuits[i], pokerHandFaces[i]);
	}
	
	if (playerResult[0] > playerResult[1]) {
		printf("%s", "Player 1 has a better hand!\n");
	}
	else if (playerResult[0] == playerResult[1]) {
		printf("%s", "Both hands are equal. It's a drawn.\n");
	}
	else {
		printf("%s", "Player 2 has a better hand!\n");
	}

}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
        // for each of the cards, choose slot of deck randomly
        for (size_t card = 1; card <= (CARDS*PLAYERS); ++card) {
                size_t row; // row number
                size_t column; // column number

                // choose new random location until unoccupied slot found
                do {
                        row = rand() % SUITS;
                        column = rand() % FACES;
                } while(wDeck[row][column] != 0); // end do...while

                // place card number in chosen slot of deck
                wDeck[row][column] = card;
        }
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
        const char *wSuit[], unsigned int pokerHandSuits[], unsigned int pokerHandFaces[], int handNumber)
{
        void sort(unsigned int pokerHandSuits[], unsigned int pokerHandFaces[]);
        
	printf("%s%d%s", "Player ", handNumber, " your hand is:\n");
        // deal each of the cards
	static size_t card = 1;
        for (size_t i = 0; i < CARDS; ++i, ++card) {
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
        sort(pokerHandSuits, pokerHandFaces);

	for (size_t i = 0; i < CARDS; i++) {		
		printf("%5s of %-8s\n", wFace[pokerHandFaces[i]], wSuit[pokerHandSuits[i]]);
	}

}

void sort(unsigned int pokerHandSuits[], unsigned int pokerHandFaces[]) {
	int holdSuits, holdFaces;
	for (size_t i = 1; i < CARDS; i++) {
		for (size_t j = 0; j < CARDS - 1; j++) {
			if(pokerHandFaces[j] > pokerHandFaces[j+1]) {
				holdSuits = pokerHandSuits[j];
				pokerHandSuits[j] = pokerHandSuits[j+1];
				pokerHandSuits[j+1] = holdSuits;
				holdFaces = pokerHandFaces[j];
				pokerHandFaces[j] = pokerHandFaces[j+1];
				pokerHandFaces[j+1] = holdFaces;
			}
		}
	}
}


int checkHand(const unsigned int pokerHandSuits[], const unsigned int pokerHandFaces[]) {
	int checkPair(const unsigned int pokerHandFaces[]);
	int checkTwoPairs(const unsigned int pokerHandFaces[]);
	int checkThree(const unsigned int pokerHandFaces[]);
	int checkFour(const unsigned int pokerHandFaces[]);
	int checkFlush(const unsigned int pokerHandSuits[]);
	int checkStraight(const unsigned int pokerHandFaces[]);

	if (checkFour(pokerHandFaces)) {
		//printf("%s", "Congratulations! You have a Four of a Kind!\n");
		return 6;
	}
	if (checkFlush(pokerHandSuits)) {
		//printf("%s", "Congratulations! You have a Flush!\n");
		return 5;
	}
	if (checkStraight(pokerHandFaces)) {
		//printf("%s", "Congratulations! You have a Straight!\n");
		return 4;
	}
	if (checkThree(pokerHandFaces)) {
		//printf("%s", "Congratulations! You have a Three of a Kind!\n");
		return 3;
	}
	if (checkTwoPairs(pokerHandFaces)) {
		//printf("%s", "Congratulations! You have Two Pairs!\n");
		return 2;
	}
	if (checkPair(pokerHandFaces)) {
		//printf("%s", "Congratulations! You have a Pair!\n");
		return 1;
	}
	//printf("%s", "Well... not this time champ.\n");
	
}


int checkPair(const unsigned int pokerHandFaces[]) {
	
	for (size_t i = 0; i < CARDS - 1; i++){
		if (pokerHandFaces[i] == pokerHandFaces[i+1]) return 1;
	}	
	return 0;

}


int checkTwoPairs(const unsigned int pokerHandFaces[]) {

	int count = 0;
	for (size_t i = 0; i < CARDS - 1; i++) {
		if (pokerHandFaces[i] == pokerHandFaces[i+1]) count++;
	}
	if (count == 2) return 1;
	else return 0;
	
}


int checkThree(const unsigned int pokerHandFaces[]) {
	
	for (size_t i = 0; i < CARDS - 2; i++) {
		if (pokerHandFaces[i] == pokerHandFaces[i+2]) return 1;
	}
	return 0;

}


int checkFour(const unsigned int pokerHandFaces[]) {
	
	for (size_t i = 0; i < CARDS - 3; i++) {
		if ((pokerHandFaces[i] == pokerHandFaces[i+3])) return 1;
	}
	return 0;

}


int checkFlush(const unsigned int pokerHandSuits[]) {
	
	int count = 1;
	for (size_t i = 1; i < CARDS; i++) {
		if (pokerHandSuits[0] == pokerHandSuits[i]) count++;
	}
	if (count == 5) return 1;
	else return 0;

}


int checkStraight(const unsigned int pokerHandFaces[]) {
	//AceException
	if ((pokerHandFaces[0] == 1) && (pokerHandFaces[4] == 12)) {
		for (size_t i = 1; i < CARDS - 2; i++) {
			if (pokerHandFaces[i] == (pokerHandFaces[i+1] + 1)) {}
			else return 0;	
		}
	}	
	else {
		for (size_t i = 0; i < CARDS - 1; i++) {
			if (pokerHandFaces[i] == (pokerHandFaces[i+1] + 1)) {}
			else return 0;	
		}	
	}
	return 1;

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

