# Chapter 6: Review Questions

## 6.1
* **a)** Arrays
* **b)** Index
* **c)** *Original thought:* forgot the right name lol, #define, maybe its definition or constant im not sure.
    > **Correction:** A SYMBOLIC CONSTANT
* **d)** Sorting
* **e)** Searching
* **f)** Two dimensional

## 6.2
* **a)** False, only on same type.
* **b)** False, it has to be an integer.
* **c)** False, it initializes the remaining elements as 0.
* **d)** True
* **e)** False, since its passed as copy of the value `a[i]`

## 6.3
* **a)** `#define SIZE 10`
* **b)** `double array[SIZE] = {0};`
* **c)** `array[4];`
* **d)** `array[9] = 1.667;`
* **e)** `array[6] = 3.333;`
* **f)** `printf("%.2f %.2f", array[6], array[9]);` -> Output: `1.67` and `3.33`
* **g)** `for(size_t i = 0; i < SIZE; i++) printf("%f ", array[size]);`
    > Output: `0 0 0 0 0 0 3.333 0 0 1.667`

## 6.4
* **a)** `int table[SIZE][SIZE];`
* **b)** 9 elements.
    ```c
    int t = 0;
    for (size_t i = 0; i < SIZE; i++){
        for (size_t j = 0; j < SIZE; j++){
            t++;
        }
    }
    printf("Total elements value is %d", t);
    ```
* **c)**
    ```c
    for (size_t x = 0; x < SIZE; x++){
        for (size_t y = 0; y < SIZE; y++){
            table[x][y] = x+y;
        }
    }
    ```
* **d)** Nested loop like above, would show: `1 8 0 2 4 66 5 0 0`

## 6.5
* **a)** No need for `;`
* **b)** No type for `SIZE`
* **c)** *Original thought:* probably wrong cuz it will initiate `b[10] = i`, when there is no `i`, cuz of comma operator usage.
    > **Correction:** WRONG answer: it works as intended (careful with comma understanding). The error is **out of boundaries array access**.
* **d)** No need for `;`
* **e)** `a[1][1]` would be the correct, since `[1, 1]` is an error.
* **f)** `=` is wrong.

## 6.6
* **a)** rigid, persistent, defined. -> **STATIC**
* **b)** contiguous type
* **c)** `0` `array[0]`
* **d)** `[]` index
* **e)** Address
* **f)** Boundaries checking
* **g)** `=`
* **h)** end `\0`
* **i)** `5` `7` `5*7`
* **j)** `array[2][3]`

## 6.7
* **a)** False, it will be 0 for the remaining.
* **b)** True.
* **c)** True.
* **d)** False, it will be the same number of elements from the list.
* **e)** True.
* **f)** False, they are passed by value.

## 6.8
* **a)**
    ```c
    array[4] *= 3; 
    printf("%d", array[4]);
    ```
* **b)**
    ```c
    int total = 0;
    for (size_t i = 0; i < 10; i++) total += n[i];
    ```
* **c)**
    ```c
    for (size_t i = 0; i < 3; i++) {
        for(size_t j = 0; j < 3; j++) {
            m[i][j] = 3;
        }
    }
    ```
* **d)**
    ```c
    int largest = sales[0][0], smallest = sales[0][0];
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 5; j++) {
            if (sales[i][j] > largest) largest = sales[i][j];
            if (sales[i][j] < smallest) smallest = sales[i][j];
        }
    }
    ```
* **e)**
    ```c
    for (size_t i = 0; i < 100; i++){
        array2[i+99] = array1[i];
    }
    ```
* **f)**
    ```c
    for(size_t i = 0; i < 100; i++){
        sum[i] = d1[i] + d2[i];
        difference[i] = d1[i] - d2[i];
    }
    ```

## 6.9
* **a)** `int grade[5][20];`
* **b)** 5 rows
* **c)** 20 rows
* **d)** 100 elements
* **e)** `grades[][0]`
* **f)** `grades[2][1]`
* **g)** `grades[0][1] = 100;`
* **h)**
    ```c
    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 20; j++){
            scanf_s("%d", &grades[i][j], 1);
        }
    }
    ```
* **i)**
    ```c
    for (size_t i = 0; i < 5; i++){
        for(size_t j = 0; j < 20; j++){
            grades[i][j] = 0;
        }
    }
    ```
* **j)** `for (size_t i = 0; i < 20; i++) grades[0][i] = mathGrades[i];`
* **k)**
    ```c
    int highest = grades[0][0];
    for (size_t i = 0; i < 20; i++){
        if (grades[0][i] > highest) highest = grades[0][i];
    }
    printf("%s%d", "Highest grade is ", highest);
    ```
* **l)**
    ```c
    for (size_t i = 0; i < 5; i++){
        printf("%d ", grades[i][2]);
    }
    ```
* **m)**
    ```c
    int avrg = 0;
    for (size_t i = 0; i < 20; i++) {
        avrg += grade[0][i];
    }
    avrg /= 20;
    ```
* **n)** fvck padding

## 6.13
* **a)** No `&` for address.
* **b)** Error: trying to access `[3]`, it should be `0`, `1`, `2`.
* **c)** Use `,` inside `{}`.
* **d)** `d[2][4]` is the correct syntax.

## 6.16
All columns in row 0 are initialized, then row 1, then row 2.

## 6.17
Calculates **6!** (Factorial).

## 6.18
Prints the array `p` values multiplied by 5, backwards.
> Output: `40`, `30` and so on...
