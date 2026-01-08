// IMPORTANT NOTE 1: The program was changed to use WORDS 5 digits long to be
// expressed in hexadecimal with 1000 memory locations. IMPORTANT NOTE 2:
// Instead of storing ASCII characters as decimal, the program is using
// hexadecimals for convenience.

#include <stdio.h>
#include <string.h>

// Format: 0xOOAAA (OO = Opcode, AAA = Address 000-999)
#define READ 0x10
#define WRITE 0x11
#define NEWL 0x12
#define READSTR 0x13
#define WRITESTR 0x14
#define LOAD 0x20
#define STORE 0x21
#define ADD 0x30
#define SUB 0x31
#define DIV 0x32
#define MUL 0x33
#define REM 0x34
#define EXP 0x35
#define BRANCH 0x40
#define BRANCHNEG 0x41
#define BRANCHZERO 0x42
#define HALT 0x43

void printWelcome();
void loadProgram(int memory[1000]);
void printComputerDump(float accumulator, int instructionCounter,
                       int instructionRegister, int operationCode, int operand,
                       int memory[1000]);
void executeProgram(int memory[1000], float *accumulator,
                    int *instructionRegister, int *operationCode, int *operand,
                    int *instructionCounter);
int checklength(char *string);

int main() {
  printWelcome();
  int memory[1000] = {0};
  float accumulator = 0;
  int instructionCounter = 0;
  int operationCode = 0;
  int operand = 0;
  int instructionRegister = 0;

  loadProgram(memory);
  executeProgram(memory, &accumulator, &instructionRegister, &operationCode,
                 &operand, &instructionCounter);
  printComputerDump(accumulator, instructionCounter, instructionRegister,
                    operationCode, operand, memory);
  return 0;
}

void executeProgram(int memory[1000], float *accumulator,
                    int *instructionRegister, int *operationCode, int *operand,
                    int *instructionCounter) {
  while (1) {
    *instructionRegister = memory[*instructionCounter];
    *operationCode = *instructionRegister / 0x1000;
    *operand = *instructionRegister % 0x1000;

    int holdCurrentInstruction, length;
    (*instructionCounter)++;

    printf("IC: %03d | IR: %05X | Op: %02X | Operand: %03X\n",
           *instructionCounter, *instructionRegister, *operationCode, *operand);

    if (*operationCode == HALT) {
      printf("*** Simpletron execution terminated ***\n");
      break;
    }
    if (*operand >= 0x3E8) {
      printf("*** FATAL: Invalid memory location ***");
      break;
    }

    switch (*operationCode) {
      case READ:
        printf("Insert a number: ");
        scanf("%f", ((float *)&memory[*operand]));
        break;
      case WRITE:
        printf("%f\n", *((float *)&memory[*operand]));
        break;
      case NEWL:
        printf("\n");
        break;
      case READSTR:
        char string[101] = "";
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        length = 0;

        do {
          printf("Insert a string (max 100 chars): ");
          fgets(string, sizeof(string), stdin);
          length = checklength(string);
        } while (length == 0);

        int boundaries = *operand + (length / 2) + 1;
        if (boundaries >= 1000) {
          printf("*** FATAL: String exceeds memory limits ***\n");
          *operationCode = HALT;
          break;
        }

        memory[*operand] = (length * 256) + (int)string[0];
        int memIndex = *operand + 1;
        for (size_t i = 1; i < length; i++) {
          if (i % 2 != 0) {
            memory[memIndex] = (int)string[i] * 256;
          } else {
            memory[memIndex] = memory[memIndex] + (int)string[i];
            memIndex++;
          }
        }
        break;
      case WRITESTR:
        length = memory[*operand] / 256;
        if (length > 0) printf("%c", (char)(memory[*operand] % 256));

        memIndex = *operand + 1;
        for (size_t i = 1; i < length; i++) {
          if (i % 2 != 0) {
            printf("%c", (char)(memory[memIndex] / 256));
          } else {
            printf("%c", (char)(memory[memIndex] % 256));
            memIndex++;
          }
        }
        printf("\n");
        break;
      case LOAD:
        *accumulator = *((float *)&memory[*operand]);
        break;
      case STORE:
        memory[*operand] = *((float *)&memory[*operand]);
        break;
      case ADD:
        *accumulator += *((float *)&memory[*operand]);
        break;
      case SUB:
        *accumulator -= *((float *)&memory[*operand]);
        break;
      case DIV:
        if (memory[*operand] == 0) {
          printf("*** FATAL: Divide by zero ***\n");
          *operationCode = HALT;
          break;
        }
        *accumulator /= *((float *)&memory[*operand]);
        break;
      case MUL:
        *accumulator *= *((float *)&memory[*operand]);
        break;
      case REM:
        if (memory[*operand] == 0) {
          printf("*** FATAL: Remainder by zero ***\n");
          *operationCode = HALT;
          break;
        }
        *accumulator = ((int)*accumulator) % memory[*operand];
        break;
      case EXP:
        if (memory[*operand] == 0) {
          *accumulator = 1;
        } else {
          float base = *accumulator;
          int exp = memory[*operand];
          for (int i = 1; i < exp; i++) *accumulator *= base;
        }
        break;
      case BRANCH:
        *instructionCounter = *operand;
        break;
      case BRANCHNEG:
        if (*accumulator < 0) *instructionCounter = *operand;
        break;
      case BRANCHZERO:
        if (*accumulator == 0) *instructionCounter = *operand;
        break;
      default:
        printf("*** Unknown OpCode %02X at address %03d ***\n", *operationCode,
               *instructionCounter);
        return;
    }

    if (*instructionCounter < 0 || *instructionCounter >= 1000) {
      printf("*** FATAL: Instruction counter out of bounds ***\n");
      break;
    }
  }
}

void printComputerDump(float accumulator, int instructionCounter,
                       int instructionRegister, int operationCode, int operand,
                       int memory[1000]) {
  printf("\nREGISTERS:\n");
  printf("%-30s%+5.2f\n", "accumulator", accumulator);
  printf("%-33s%03d\n", "instructionCounter", instructionCounter);
  printf("%-30s%05X\n", "instructionRegister", instructionRegister);
  printf("%-33s%02X\n", "operationCode", operationCode);
  printf("%-33s%03X\n", "operand", operand);

  printf("\nMEMORY:\n");
  printf("%8s", " ");
  for (size_t i = 0; i < 10; i++) printf("%6ld", i);
  printf("\n");

  for (size_t i = 0; i < 1000; i += 10) {
    printf("%3ld", i);
    if (i < 100) printf(" ");
    for (size_t j = 0; j < 10; j++) {
      if ((i + j) < 1000) printf("  %05X", memory[i + j]);
    }
    printf("\n");
  }
}

void loadProgram(int memory[1000]) {
  int instruction = 0;
  int counter = 0;
  printf("*** Loading Program ***\n");
  while (instruction != -0x99999 && counter < 1000) {
    printf("%03d ? ", counter);
    scanf("%x", &instruction);

    while (instruction != -0x99999 &&
           (instruction < -0xFFFFF || instruction > 0xFFFFF)) {
      printf("Invalid operation, try again (-99999 to end): \n");
      printf("%03d ? ", counter);
      scanf("%x", &instruction);
    }

    if (instruction != -0x99999) {
      memory[counter] = instruction;
      counter++;
    }
  }
  printf("*** Program Loading Completed ***\n");
}

void printWelcome() {
  printf("*** Welcome to Simpletron (HEX Extended)! ***\n");
  printf("*** Enter instructions as 5-digit HEX (e.g., 1000A) ***\n");
  printf("*** -99999 to terminate loading ***\n\n");
}

int checklength(char *string) {
  int length = 0;
  while (string[length] != '\0') {
    length++;
  }
  if (length > 0 && string[length - 1] == '\n') {
    string[length - 1] = '\0';
    length--;
  }
  return length;
}
