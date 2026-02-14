#include <stdio.h>

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUB 31
#define DIV 32
#define MUL 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

void printWelcome();
void loadProgram(int memory[100]);
void printComputerDump(int accumulator, int instructionCounter,
                       int instructionRegister, int operationCode, int operand,
                       int memory[100]);
void executeProgram(int memory[100], int *accumulator, int *instructionRegister,
                    int *operationCode, int *operand, int *instructionCounter);

int main() {
  printWelcome();
  int memory[100] = {0};
  int accumulator = 0;
  int instructionCounter = 0;
  int operationCode = 0;
  int operand = 0;
  int instructionRegister = 0;
  loadProgram(memory);
  executeProgram(memory, &accumulator, &instructionRegister, &operationCode,
                 &operand, &instructionCounter);
  printComputerDump(accumulator, instructionCounter, instructionRegister,
                    operationCode, operand, memory);
}

void executeProgram(int memory[100], int *accumulator, int *instructionRegister,
                    int *operationCode, int *operand, int *instructionCounter) {
  while (1) {
    *instructionRegister = memory[*instructionCounter];
    *operationCode = *instructionRegister / 100;
    *operand = *instructionRegister % 100;

    (*instructionCounter)++;

    printf(
        "instruction = %d, instructionCounter = %d, opCode = %d, operand = "
        "%d\n",
        *instructionRegister, *instructionCounter, *operationCode, *operand);

    if (*operationCode == HALT) {
      printf("*** Simpletron execution terminated ***\n");
      break;
    }

    switch (*operationCode) {
      case READ:
        printf("Insert a number: ");
        scanf("%d", &memory[*operand]);
        break;
      case WRITE:
        printf("%d\n", memory[*operand]);
        break;
      case LOAD:
        *accumulator = memory[*operand];
        break;
      case STORE:
        memory[*operand] = *accumulator;
        break;
      case ADD:
        *accumulator += memory[*operand];
        break;
      case SUB:
        *accumulator -= memory[*operand];
        break;
      case DIV:
        if (memory[*operand] == 0) {
          printf(
              "*** Attempt to divide by zero ***\n*** Simpletron execution "
              "abnormally terminated ***\n");
          *operationCode = 43;
          break;
        }
        *accumulator /= memory[*operand];
        break;
      case MUL:
        *accumulator *= memory[*operand];
        break;
      case HALT:
        printf("*** Simpletron execution terminated ***\n");
        break;
      case BRANCH:
        *instructionCounter = *operand;
        break;
      case BRANCHNEG:
        if (*accumulator < 0) {
          *instructionCounter = *operand;
        }
        break;
      case BRANCHZERO:
        if (*accumulator == 0) {
          *instructionCounter = *operand;
        }
        break;
      default:
        printf("*** Unknown OpCode %d at address %02d ***\n", *operationCode,
               *instructionCounter);
        return;
    }
    if (*instructionCounter < 0 || *instructionCounter >= 100) break;
  }
}

void printComputerDump(int accumulator, int instructionCounter,
                       int instructionRegister, int operationCode, int operand,
                       int memory[100]) {
  FILE *fPtr = fopen("simpletron_output.txt", "w");
  fprintf(fPtr, "REGISTERS:\n");
  printf("REGISTERS:\n");
  fprintf(fPtr, "%-30s%+05d\n", "accumulator", accumulator);
  printf("%-30s%+05d\n", "accumulator", accumulator);
  fprintf(fPtr, "%-33s%02d\n", "instructionCounter", instructionCounter);
  printf("%-33s%02d\n", "instructionCounter", instructionCounter);
  fprintf(fPtr, "%-30s%+05d\n", "instructionRegister", instructionRegister);
  printf("%-30s%+05d\n", "instructionRegister", instructionRegister);
  fprintf(fPtr, "%-33s%02d\n", "operationCode", operationCode);
  printf("%-33s%02d\n", "operationCode", operationCode);
  fprintf(fPtr, "%-33s%02d\n", "operand", operand);
  printf("%-33s%02d\n", "operand", operand);
  fprintf(fPtr, "MEMORY:\n");
  printf("MEMORY:\n");
  fprintf(fPtr, "%10d", 0);
  printf("%10d", 0);
  for (size_t i = 1; i < 10; i++) {
    fprintf(fPtr, "%8ld", i);
    printf("%8ld", i);
  }
  fprintf(fPtr, "\n");
  printf("\n");
  for (size_t i = 0; i < 100; i += 10) {
    fprintf(fPtr, "%2ld", i);
    printf("%2ld", i);
    for (size_t j = 0; j < 10; j++) {
      fprintf(fPtr, "   %+05d", memory[i + j]);
      printf("   %+05d", memory[i + j]);
    }
    fprintf(fPtr, "\n");
    printf("\n");
  }
  printf("You can also check all this data within the simpletron_output.txt\n");
  fclose(fPtr);
}

void printWelcome() {
  printf(
      "*** Welcome to Simpletron! ***\n*** Please enter your program one "
      "instruction ***\n*** (or data word) at a time. I will type the ***\n*** "
      "locatio number and a question mark (?).  ***\n*** You then type the "
      "word for that location. ***\n*** Type the sentinel -99999 to stop "
      "entering ***\n*** your program. ***\n");
}

void loadProgram(int memory[100]) {

  FILE *fPtr;
  printf("Please, specify the complete file name to read the instructions from: (example instructions.txt) ");
  char fileName[100];
  scanf("%s", fileName);
  if ((fPtr = fopen(fileName, "r")) == NULL) {
    printf("Error opening the file\n");
  }
  int instruction = 0;
  int counter = 0;
  while (instruction != -99999 && counter != 100) {
    //printf("%02d ? ", counter);
    fscanf(fPtr, "%d", &instruction);
    while (instruction != -99999 &&
           (instruction < -9999 || instruction > 9999)) {
      //printf("Invalid operation, try inserting again: (-99999 to terminate)\n");
      //printf("%02d ? ", counter);
      fscanf(fPtr, "%d", &instruction);
    }
    memory[counter] = instruction;
    counter++;
  }
  fclose(fPtr);
}
