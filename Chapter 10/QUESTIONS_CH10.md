## 10.1
* **a)** structure
* **b)** union
* **c)** bitwise AND (`&`)
* **d)** members
* **e)** bitwise Inclusive OR (`|`)
* **f)** `struct`
* **g)** `typedef`
* **h)** bitwise Exclusive OR (`^`)
* **i)** mask
* **j)** union
* **k)** tag name
* **l)** `.` (structure member) or `->` (structure pointer)
* **m)** `<<` (left-shift operator) `>>` (right-shift operator)
* **n)** enumeration

---

### 10.2
* **a)** **False.** A structure may contain variables of different data types.
* **b)** **False.** Unions cannot be compared directly because the "unused" bytes in memory might contain undefined garbage data, making a bitwise comparison unreliable.
* **c)** **True.**
* **d)** **False.** Different structures can have members with the same names without conflict.
* **e)** **False.** `typedef` is used to create an alias for an existing data type, not a new type.
* **f)** **False.** In C, structures are passed to functions by value (a copy is made) unless a pointer is used.
* **g)** **True.**

---

### 10.3
* **a)**
struct part {
    unsigned int partNumber;
    char partName[25];
};
* **b)** `typedef struct part Part;`
* **c)** `Part a; struct part b[10]; struct part *ptr;`
* **d)** `scanf("%u%24s", &a.partNumber, a.partName);`
* **e)** `b[3] = a;`
* **f)** `ptr = b;`
* **g)** `printf("%u %s\n", (ptr + 3)->partNumber, (ptr + 3)->partName);`

---

### 10.4
* **a)** **Error:** Using both `*` and `->` to access the value. **Correction:** Use `(*cPtr).face` or `cPtr->face`.
* **b)** **Error:** Missing `[]` to print the array element 10. **Correction:** Use `hearts[10].face`.
* **c)** **Error:** Initializing a union with a value which is different from its first member data type.
* **d)** **Error:** Missing `;` at the end of the `struct` definition.
* **e)** **Error:** Missing the `struct` keyword to declare person. **Correction:** Use `struct person d;`.
* **f)** **Error:** Trying to assign `c`, a different struct type, to `p`.

---

### 10.5
* **a)**
```c
struct inventory {
    char partName[30];
    int partNumber;
    float price;
    int stock;
    int reorder;
};
```
* **b)**
```c
union data {
    char c;
    short s;
    long b;
    float f;
    double d;
};
```
* **c)**
```c
struct address {
     char streetAddress[25];
     char city[20];
     char state[3];
     char zipCode[6];
};
```
* **d)**
```c
struct student {
     char firstName[15];
     char lastName[15];
     struct address homeAddress;
};
```
* **e)**
```c
struct test {
     unsigned int a : 1;
     unsigned int b : 1;
     unsigned int c : 1;
     unsigned int d : 1;
     unsigned int e : 1;
     unsigned int f : 1;
     unsigned int g : 1;
     unsigned int h : 1;
     unsigned int i : 1;
     unsigned int j : 1;
     unsigned int k : 1;
     unsigned int l : 1;
     unsigned int m : 1;
     unsigned int n : 1;
     unsigned int o : 1;
     unsigned int p : 1;
};
```

---

### 10.6
* **a)** `customerRecord.lastName;`
* **b)** `customerPtr->lastName;`
* **c)** `customerRecord.firstName;`
* **d)** `customerPtr->firstName;`
* **e)** `customerRecord.customerNumber;`
* **f)** `customerPtr->customerNumber;`
* **g)** `customerRecord.personal.phoneNumber;`
* **h)** `customerPtr->personal.phoneNumber;`
* **i)** `customerRecord.personal.address;`
* **j)** `customerPtr->personal.address;`
* **k)** `customerRecord.personal.city;`
* **l)** `customerPtr->personal.city;`
* **m)** `customerRecord.personal.state;`
* **n)** `customerPtr->personal.state;`
* **o)** `customerRecord.personal.zipCode;`
* **p)** `customerPtr->personal.zipCode;`
