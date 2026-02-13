#include <stdio.h>

typedef struct {
  int accountNumber;
  char *name;
  float balance;
} Master;

typedef struct {
  int accountNumber;
  float dollarAmount;
} Transaction;

int main() {
  Master accounts[4];
  Transaction transactions[4];
  accounts[0].accountNumber = 100;
  accounts[0].name = "Alan Jones";
  accounts[0].balance = 348.17;
  transactions[0].accountNumber = 100;
  transactions[0].dollarAmount = 27.14;
  accounts[1].accountNumber = 300;
  accounts[1].name = "Mary Smith";
  accounts[1].balance = 27.19;
  transactions[1].accountNumber = 300;
  transactions[1].dollarAmount = 62.11;
  accounts[2].accountNumber = 500;
  accounts[2].name = "Samp Sharp";
  accounts[2].balance = 0;
  transactions[2].accountNumber = 400;
  transactions[2].dollarAmount = 100.56;
  accounts[3].accountNumber = 700;
  accounts[3].name = "Suzy Green";
  accounts[3].balance = -14.22;
  transactions[3].accountNumber = 900;
  transactions[3].dollarAmount = 82.17;

  FILE *mPtr = fopen("MasterFile.txt", "wx");
  if (mPtr == NULL) {
    printf("Error opening the file\n");
    return 1;
  }
  fprintf(mPtr, "%-20s%-30s%s\n", "Account Number", "Name", "Balance");
  for (size_t i = 0; i < 4; i++) {
    fprintf(mPtr, "%-20d%-30s%f\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
  }

  FILE *tPtr = fopen("TransactionFile.txt", "wx");
  if (tPtr == NULL) {
    printf("Error opening the file\n");
    return 1;
  }
  fprintf(tPtr, "%-20s%s\n", "Account Number", "Dollar Amount");
  for (size_t i = 0; i < 4; i++) {
    fprintf(tPtr, "%-20d%f\n", transactions[i].accountNumber, transactions[i].dollarAmount);
  }
  fclose(mPtr);
  fclose(tPtr);
}
