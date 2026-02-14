#include <stdio.h>
#include <string.h>

#define SIZE 100

typedef struct {
  unsigned int rec;
  char name[25];
  unsigned int quant;
  double cost;
} Tool;

void clearBuffer();
void clearString(char str[]);
void checkRecordInitialization(FILE *fPtr, int size);
void inputData(FILE *fPtr);
void listTools(FILE *fPtr);
void deleteTool(FILE *fPtr);
void updateTool(FILE *fPtr);

int main() {

  FILE *fPtr = fopen("hardware.dat", "r+");
  if (fPtr == NULL) {
    fPtr = fopen("hardware.dat", "w+");
    if (fPtr == NULL) {
      printf("error opening the hardware.dat file\n");
      return 1;
    }
  }
  unsigned int choice;
  while(1) {
    rewind(fPtr);
    printf("Welcome, this is your menu: \n");
    printf("1 - (re)Initialize a blank hardware.dat(Be aware that this will erase all your current data)\n");
    printf("2 - Input new data\n");
    printf("3 - List all your tools\n");
    printf("4 - Delete record data\n");
    printf("5 - Update record data\n");
    printf("0 - End program\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        checkRecordInitialization(fPtr, SIZE);
        break;
      case 2:
        inputData(fPtr);
        break;
      case 3:
        listTools(fPtr);
        break;
      case 4:
        deleteTool(fPtr);
        break;
      case 5:
        updateTool(fPtr);
        break;
      default:
        return 0;
    }
  }
  fclose(fPtr);
}

void clearBuffer() {
  int c;
  while((c = getchar()) != '\n' && c != EOF) {
  }
}

void clearString(char str[]) {
  int i = 0;
  while (str[i] != '\n' && str[i] != EOF) {
    i++;
  }
  str[i] = '\0';
}

void checkRecordInitialization(FILE *fPtr, int size) {
  Tool blankTool = {0, "", 0, 0};
  for (size_t i = 0; i < size; i++) {
    blankTool.rec = i+1;
    fseek(fPtr, (i)*sizeof(Tool), SEEK_SET);
    fwrite(&blankTool, sizeof(Tool), 1, fPtr);
  }
}

void inputData(FILE *fPtr) {
  printf("Please, insert the following data: Record Number - Tool Name - Quantity - Cost\n");
  Tool data;
  printf("Record Number: ");
  scanf("%u", &data.rec);
  clearBuffer();
  printf("Tool Name: ");
  fgets(data.name, sizeof(data.name), stdin);
  clearString(data.name);
  printf("Quantity: ");
  scanf("%u", &data.quant);
  clearBuffer();
  printf("Cost: ");
  scanf("%lf", &data.cost);
  clearBuffer();
  printf("%-15u%-25s%-15u%.2lf\n", data.rec, data.name, data.quant, data.cost);
  fseek(fPtr, (data.rec-1)*sizeof(Tool), SEEK_SET);
  fwrite(&data, sizeof(Tool), 1, fPtr);
}

void listTools(FILE *fPtr) {
  Tool current;
  printf("%-15s%-25s%-15s%s\n", "Record #", "Tool Name", "Quantity", "Cost");
  while((fread(&current, sizeof(Tool), 1, fPtr) == 1)) {
    if (strcmp(current.name, "") != 0) printf("%-15u%-25s%-15u%.2lf\n", current.rec, current.name, current.quant, current.cost);
  }
}

void deleteTool(FILE *fPtr) {
  printf("Please, insert the Record # (Record number Identifier) from the tool you would like to delete: ");
  unsigned int num;
  scanf("%u", &num);
  Tool blankData = {num, "", 0, 0};
  fseek(fPtr, (num-1)*sizeof(Tool), SEEK_SET);
  fwrite(&blankData, sizeof(Tool), 1, fPtr);
}

void updateTool(FILE *fPtr) {
  printf("Please, insert the Record # (Record number Identifier) from the tool you would like to update: ");
  unsigned int num;
  scanf("%u", &num);
  Tool current;
  fseek(fPtr, (num-1)*sizeof(Tool), SEEK_SET);
  fread(&current, sizeof(Tool), 1, fPtr);
  printf("Current data: \n");
  printf("%-15s%-25s%-15s%s\n", "Record #", "Tool Name", "Quantity", "Cost");
  printf("%-15u%-25s%-15u%.2lf\n", current.rec, current.name, current.quant, current.cost);
  inputData(fPtr);
}
