#include <stdio.h>
#include <string.h>

typedef struct {
  int accountNumber;
  char firstName[15];
  char lastName[15];
  float balance;
} Master;

typedef struct {
  int accountNumber;
  float dollarAmount;
} Trans;

int main() {
  FILE *ofPtr = fopen("oldmast.txt", "r");
  FILE *tfPtr = fopen("trans.txt", "r");
  FILE *nfPtr = fopen("newmast.txt", "w");
  if (ofPtr == NULL || tfPtr == NULL || nfPtr == NULL) {
    printf("Error during file opening\n");
    return 1;
  }
  Master currAccount;
  Trans currTrans;
  char buffer[100];
  char name[30];
  fgets(buffer, sizeof(buffer), ofPtr);
  fgets(buffer, sizeof(buffer), tfPtr);
  fprintf(nfPtr, "%-20s%-30s%s\n", "Account Number", "Name", "Balance");
  float holdDollarAmount[1000] = {0};
  int auxTransAccounts[1000] = {0};
  while (fscanf(tfPtr, "%d%f", &currTrans.accountNumber, &currTrans.dollarAmount) == 2) {
    holdDollarAmount[currTrans.accountNumber] += currTrans.dollarAmount;
    auxTransAccounts[currTrans.accountNumber]++;
  }
  int auxMasterAccounts[1000] = {0};
  while (fscanf(ofPtr, "%d%s%s%f", &currAccount.accountNumber, currAccount.firstName, currAccount.lastName, &currAccount.balance) == 4) {
    currAccount.balance += holdDollarAmount[currAccount.accountNumber];
    auxMasterAccounts[currAccount.accountNumber]++;
    sprintf(name, "%s %s", currAccount.firstName, currAccount.lastName);
    fprintf(nfPtr, "%-20d%-30s%.2f\n", currAccount.accountNumber, name, currAccount.balance);
  }
  for (size_t i = 0; i < 1000; i++) {
    if (auxTransAccounts[i] > 0 && auxMasterAccounts[i] == 0) printf("Unmatched transaction record for account number %ld\n", i);
  }
  fclose(ofPtr);
  fclose(tfPtr);
  fclose(nfPtr);
}
