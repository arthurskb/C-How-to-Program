### 13.1
* **a)** #
* **b)** #elif and #else
* **c)** #define
* **d)** comments and whitespace
* **e)** #undef
* **f)** #ifdef and #ifndef
* **g)** conditional compilation
* **h)** assert
* **i)** #include
* **j)** ##
* **k)** #
* **l)** \
* **m)** #line

---

### 13.2
printf("%s%d", "The __LINE__ definition is ", __LINE__);
printf("%s%s", "The __FILE__ definition is ", __FILE__);
printf("%s%s", "The __DATE__ definition is ", __DATE__);
printf("%s%s", "The __TIME__ definition is ", __TIME__);
printf("%s%d", "The __STDC__ definition is ", __STDC__);

---

### 13.3
* **a)** #define YES 1
* **b)** #define NO 0
* **c)** #include "common.h"
* **d)** #line 3000
* **e)** #if defined(TRUE)
     #undef TRUE
     #define TRUE 1
   #endif
* **f)** #ifdef TRUE
     #undef TRUE
     #define TRUE 1
   #endif
* **g)** #if TRUE
     FALSE 0
   #else
     FALSE 1
   #endif
* **h)** #define CUBE_VOLUME(x) ((x) * (x) * (x))

