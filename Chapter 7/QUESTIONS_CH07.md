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