# Chapter 7: Review Questions

## 7.1
* **a)** Address
* **b)** `NULL`, `0`, and an address
* **c)** `0`

## 7.2
* **a)** False, a `void` pointer can't be dereferenced.
    > Reason: There is no way to know how many bytes of memory to dereference using a void pointer.
* **b)** False, if we use `void` pointers, they can assign and be assigned to different types of pointers without a cast operation.

## 7.3
* **a)** `float numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};`
* **b)** `float *nPtr;`
* **c)**
    ```c
    for (size_t i = 0; i < SIZE; i++) {
        printf("%.1f ", numbers[i]);
    }
    ```
* **d)**
    ```c
    nPtr = numbers;
    nPtr = &numbers[0];
    ```
* **e)**
    ```c
    for (size_t i = 0; i < SIZE; i++) {
        printf("%f ", *(nPtr+i));
    }
    ```
* **f)**
    ```c
    for (size_t i = 0; i < SIZE; i++) {
        printf("%f ", *(numbers+i));
    }
    ```
* **g)**
    ```c
    for (size_t i = 0; i < SIZE; i++) {
        printf("%f ", nPtr[i]);
    }
    ```
* **h)**
    * `numbers[4];`
    * `*(numbers + 4);`
    * `nPtr[4];`
    * `*(nPtr + 4);`
* **i)** Address calculation: `1002500 + 8*4 = 1002532`
    > Value: `8.8`
* **j)** Address calculation: `1002500 + 8*(5-4) = 1002504`
    > Value: `1.1`

## 7.4
* **a)** `float *fPtr;`
* **b)** `fPtr = &number1;`
* **c)** `printf("%f", *fPtr);`
* **d)** `number2 = *fPtr;`
* **e)** `printf("%f", number2);`
* **f)** `printf("%p", &number1);`
* **g)** `printf("%p", fPtr);`
    > Note: Yes, it should be the same value, since `fPtr` points to `number1` address.

## 7.5
* **a)** `void exchange(float *x, float *y) {`
* **b)** `void exchange(float *, float *);`
* **c)** `int evaluate(int x, int (*poly)(int)) {`
* **d)** `int evaluate(int, int (*poly)(int));`

## 7.6
* **a)** `zPtr` isn't pointing to array `z`. Worst, it's not even initialized.
* **b)** `zPtr` should be dereferenced for number to get first value of array.
* **c)** You can't use both pointer and index notation, choose one: `*(zPtr + 2)` or `zPtr[2]`.
* **d)** `i <= 5` would go out of `z` boundaries. It should be `i < 5`.
* **e)** `sPtr` is a `void` pointer type, which means it can't be dereferenced. We have to cast it to an integer pointer: `*((int *) sPtr)`.
* **f)** `z` is an array name, which means it should be a constant pointer to the beginning of array `z`. Trying to make pointer arithmetic with it is an error.

## 7.7
* **a)** `void`
* **b)** Constant
* **c)** `&` `*`

## 7.8
* **a)** False, it can be done, but it works slightly differently.
* **b)** True.

## 7.9
* **a)** `oddNum[SIZE] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};`
* **b)** `int *iPtr;`
* **c)**
    ```c
    for (i = 0; i < SIZE; i++){
        printf("%d ", oddNum[i]);
    }
    ```
* **d)**
    ```c
    iPtr = oddNum;
    iPtr = &oddNum[0];
    ```
* **e)**
    ```c
    for (i = 0; i < SIZE; i++){
        printf("%d ", *(iPtr+i));
    }
    ```
* **f)**
    ```c
    for (i = 0; i < SIZE; i++){
        printf("%d ", *(oddNum+i));
    }
    ```
* **g)**
    ```c
    for (i = 0; i < SIZE; i++){
        printf("%d ", iPtr[i]);
    }
    ```
* **h)**
    * `oddNum[3];`
    * `*(oddNum+3);`
    * `iPtr[3];`
    * `*(iPtr+3);`
* **i)** Address calculation: `2003800 + 4*5 = 2003820`
    > Value: `11`
* **j)** Address calculation: `2003800 + 4*(9-3) = 2003824`
    > Value: `13`

## 7.10
* **a)** `double *dPtr;`
* **b)** `dPtr = &value1;`
* **c)** `printf("%f ", &dPtr);`
* **d)** `value2 = *dPtr;`
* **e)** `printf("%f ", value2);`
* **f)** `printf("%p", &value1);`
* **g)** `printf("%p", dPtr);`
    > Note: Yes, it should be the same value.

## 7.11
* **a)** `int addNumbers(long int numList[], int size) {`
* **b)** `int addNumbers(long int, int);`
* **c)** `void sort(int n[], const int size, int (*f)(int, int)) {`
* **d)** `void sort(int, const int, int (*f)(int, int));`

## 7.19
* This program concatenates string2 into string1, as long as it doesnt hit the SIZE char limit.

## 7.20
* This program calculates and outputs the length of the string.

## 7.21
* **a)** The variable `number` is not initialized upon declaration. In C, local variables are not automatically zeroed out; they contain "garbage values" (whatever data was previously at that memory location).
* **b)** Incompatible pointer types (e.g., assigning an `int*` to a `char*`) require an explicit cast to function correctly and avoid compiler warnings or errors.
* **c)** If x is a pointer and y is a standard variable, the statement x = y incorrectly attempts to use the value of y as a memory address. To store the address of y in x, the address-of operator must be used: x = &y.
* **d)** When a variable s is initialized as an array (e.g., `char s[]`), the identifier s acts as a constant pointer to the first element. Because it is constant, its address cannot be reassigned to point elsewhere.
* **e)** A `void*` is a generic pointer type. Because the compiler does not know the size of the underlying data, you cannot perform pointer arithmetic or dereferencing directly without first casting it to a specific type (like `int*` or `char*`).
* **f)** The variable xPtr was likely declared as a standard variable rather than a pointer. To handle addresses, it must be declared using the pointer syntax: *xPtr.
* **g)** The identifier s was used or accessed before it was properly initialized or allocated memory.

## 7.26
* Considering both strings to have the same length, this program compares both strings to see if they are equals or differents.

## 7.27
* **a)**

| location  | number  | instruction             |
|-----------|---------|-------------------------|
|         0 | "+1012" | (Read B)                |
|         1 | "+2012" | (Load B)                |
|         2 | "+4110" | (Branch Negative to 10) |
|         3 | "+1011" | (Read A)                |
|         4 | "+2011" | (Load A)                |
|         5 | "+4109" | (Branch Negative to 9)  |
|         6 | "+3012" | (Adds B)                |
|         7 | "+2112" | (Store B)               |
|         8 | "+4003" | (Branch to 3)           |
|         9 | "+1112" | (Write B)               |
|        10 | "+4300" | (Halt)                  |
|        11 | "+0000" | (Variable A)            |
|        12 | "+0000" | (Variable B)            |

* **b)**

| location  | number  | instruction         |
|-----------|---------|---------------------|
|         0 | "+1021" | (Read E = 7)        |
|         1 | "+1022' | (Read A = 7)        |
|         2 | "+1025" | (Read D = 1)        |
|         3 | "+1023" | (Read B)            |
|         4 | "+2022" | (Load A)            |
|         5 | "+3125" | (Subs D)            |
|         6 | "+2122" | (Store A)           |
|         7 | "+1024" | (Read C)            |
|         8 | "+2023" | (Load B)            |
|         9 | "+3024" | (Adds C)            |
|        10 | "+2123" | (Store B)           |
|        11 | "+2022" | (Load A)            |
|        12 | "+3125" | (Subs D)            |
|        13 | "+4216" | (Branch Zero to 16) |
|        14 | "+2122" | (Store A)           |
|        15 | "+4007" | (Branch to 7)       |
|        16 | "+2023" | (Load B)            |
|        17 | "+3221" | (Divide E)          |
|        18 | "+2123" | (Store B)           |
|        19 | "+1123" | (Write B)           |
|        20 | "+4300" | (Halt)              |
|        21 | "+0000" | (Variable E) = 7    |
|        22 | "+0000" | (Variable A) = 7    |
|        23 | "+0000" | (Variable B)        |
|        24 | "+0000" | (Variable C)        |
|        25 | "+0000" | (Variable D) = 1    |

* **c)**

| location  | number  | instruction             |
|-----------|---------|-------------------------|
|         0 | "+1036" | (Read B = 1)            |
|         1 | "+1035" | (Read A)                |
|         2 | "+2035" | (Load A)                |
|         3 | "+4134" | (Branch Negative to 34) |
|         4 | "+4234" | (Branch Zero to 34)     |
|         5 | "+1037" | (Read C)                |
|         6 | "+3136" | (Subs B)                |
|         7 | "+4233" | (Branch Zero to 33)     |
|         8 | "+2135" | (Store A)               |
|         9 | "+2037" | (Load C)                |
|        10 | "+4123" | (Branch Negative to 23) |
|        11 | "+1038" | (Read D)                |
|        12 | "+2038" | (Load D)                |
|        13 | "+4127" | (Branch Negative to 27) |
|        14 | "+3137" | (Subs C)                |
|        15 | "+4128" | (Branch Negative to 28) |
|        16 | "+2038" | (Load D)                |
|        17 | "+2137" | (Store C)               |
|        18 | "+2035" | (Load A)                |
|        19 | "+3136" | (Subs B)                |
|        20 | "+4233" | (Branch Zero to 33)     |
|        21 | "+2135" | (Store A)               |
|        22 | "+4009" | (Branch to 9)           |
|        23 | "+1038" | (Read D)                |
|        24 | "+2038" | (Load D)                |
|        25 | "+4130" | (Branch Negative to 30) |
|        26 | "+4016" | (Branch to 16)          |
|        27 | "+4018" | (Branch to 18)          |
|        28 | "+2037" | (Load C)                |
|        29 | "+4017" | (Branch to 17)          |
|        30 | "+3137" | (Subs C)                |
|        31 | "+4128" | (Branch Negative to 28) |
|        32 | "+4016" | (Branch to 16)          |
|        33 | "+1137" | (Write C)               |
|        34 | "+4300" | (Halt)                  |
|        35 | "+0000" | (Variable A)            |
|        36 | "+0000" | (Variable B) = 1        |
|        37 | "+0000" | (Variable C)            |
|        38 | "+0000" | (Variable D)            |
