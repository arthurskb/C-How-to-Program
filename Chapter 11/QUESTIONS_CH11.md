### 11.1
* **a)** `fclose`
* **b)** `fscanf`
* **c)** `fgetc`
* **d)** `fgets`
* **e)** `fopen`
* **f)** `fread`
* **g)** `fseek`

---

### 11.2
* **a)** False, it can be used to read data from `stdin`.
* **b)** False, all those streams are opened by the program process.
* **c)** False, it mustn't be done explicitly, but it is recommended.
* **d)** False, both `fseek` and `rewind` could be used to read from the beginning of the file by (re)setting the file position pointer.
* **e)** True.
* **f)** False, it depends on how the file is opened.
* **g)** True.
* **h)** False, records are all of uniform length in random-access files.
* **i)** False, it can seek from the beginning, current position, and end of file.

---

### 11.3
* **a)** `FILE *ofPtr = fopen("oldmast.dat", "r");`
* **b)** `FILE *tfPtr = fopen("trans.dat", "r");`
* **c)** `FILE *nfPtr = fopen("newmast.dat", "wx");`
* **d)** `fscanf(ofPtr, "%d%s%f", &accountNum, name, &currentBalance);`
* **e)** `fscanf(tfPtr, "%d%f", &account, &dollarAmount);`
* **f)** `fprintf(nfPtr, "%d %s %f", &accountNum, name, currentBalance);`

---

### 11.4
* **a)** `fPtr` wasn't initialized as a pointer to `"payables.dat"` using `fopen`. `FILE *fPtr = fopen("payables.dat", " ");` where the second argument depends on what it is intended to do.
* **b)** There's no `open` function, use `fopen`.
* **c)** There are 2 errors: one is using `recPtr` as 1st argument, it should be `payPtr`. Two is using `scanf` instead of `fscanf`.
* **d)** The error is opening with `"w"`, since it will discard current data. Use `"r+"` or `"a"` or `"a+"`.
* **e)** The error is opening with `"w+"`, since it will discard current data. To append use `"a"` or `"a+"`.i

---

### 11.5
* **a)** Files
* **b)** Record
* **c)** Record key
* **d)** Field
* **e)** `stdin`, `stdout` and `stderr`
* **f)** `fputc`
* **g)** `fputs`
* **h)** `fwrite`
* **i)** `rewind`

---

### 11.6
* **a)** True.
* **b)** False, people prefer to manipulate characters and fields as they are more human-readable. Bits are highly prone to error.
* **c)** True.
* **d)** True.
* **e)** False, we progress from bits to characters to fields and so on.
* **f)** False, a record key field is used to identify an unique record.
* **g)** False, most companies use lots of different and organized files stored in databases.
* **h)** False, the C program refers to it using a file pointer.
* **i)** True.

---

11.11 -
* **a)**
```c
//assuming something like this FILE *fPtr = fopen("nameage.dat", "wx");
struct person blankPerson = {"unassigned", "", "0"};
for (size_t i = 1; i <= 100; i++) {
  fwrite(&blankPerson, sizeof(struct person), 1, fPtr);
}
```
* **b)**
```c
struct person person;
for (size_t i = 0; i < 10; i++) {
  printf("Insert last name, first name and age: \n");
  scanf("%14s %14s %3s", person.lastName, person.firstName, person.age);
  fwrite(&person, sizeof(struct person), 1, fPtr);
}
```
* **c)**
```c
printf("Enter account to update from 1 to 100\n");
unsigned int acc;
scanf("%u", &acc);
fseek(fPtr, (acc-1) * sizeof(struct person), SEEK_SET);
struct person current;
fread(&current, sizeof(struct person), 1, fPtr);
if(strcmp(current.firstName == "unassigned") == 0) {
  printf("No info\n");
} else {
  printf("Current data:\nLast name: %s\nFirst name: %s\nAge: %s\n", current.lastName, current.firstName, current.age);
  printf("Insert new last name, first name and age to be updated: \n");
  scanf("%14s %14s %3s, current.lastName, current.firstName, current.age);
  fseek(fPtr, (acc-1) * sizeof(struct person), SEEK_SET);
  fwrite(&current, sizeof(struct person), 1, fPtr);
}
```
* **d)**
```c
printf("Enter account to update from 1 to 100\n");
unsigned int acc;
scanf("%u", &acc);
fseek(fPtr, (acc-1) * sizeof(struct person), SEEK_SET);
struct person blankPerson = {"unassigned", "", "0"};
fwrite(&blankPerson, sizeof(struct person), 1, fPtr);
```
