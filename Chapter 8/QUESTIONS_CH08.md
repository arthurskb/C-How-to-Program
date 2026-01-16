### 8.1
* **a)** `c = toupper(c);`
* **b)** `isdigit(c) ? printf("%c is a digit\n", c) : printf("%c is not a digit\n", c);`
* **c)** `iscntrl(c) ? printf("%c is a control char\n", c) : printf("%c is not a control char\n", c);`
* **d)** `fgets(s1, 100, stdin);`
* **e)** `puts(s1);`
* **f)** `ptr = strrchr(s1, c);`
* **g)** `putchar(c);`
* **h)** `isalpha(c) ? printf("%c is a letter\n", c) : printf("%c is not a letter.\n", c);`
* **i)** `c = getchar();`
* **j)** `ptr = strstr(s1, s2);`
* **k)** `isprint(c) ? printf("%c is a printing char\n", c) : printf("%c is not a printing char\n", c);`
* **l)** `sscanf("1.27 10.3 9.432", "%f%f%f", &d, &e, &f);`
* **m)** `strcpy(s1, s2);`
* **n)** `ptr = strpbrk(s1, s2);`
* **o)** `printf("%d", strcmp(s1, s2));`
* **p)** `ptr = strchr(s1, c);`
* **q)** `sprintf(s1, "%7d%7d%7d", x, y, z);`
* **r)** `strncat(s1, s2, 10);`
* **s)** `printf("%u", strlen(s1));`
* **t)** `ptr = strtok(s2, ",");`

### 8.2
char vowel[] = "AEIOU";
char vowel[] = {'A', 'E', 'I', 'O', 'U', '\0'};

### 8.3
* **a)** Jack
* **b)** jill
* **c)** jack and jill
* **d)** 8
* **e)** 13

### 8.4
* **a)** "hello" has length of 5, so `strncpy` wont be able to write a terminating null character to `s`, the 3rd argument of `strncpy` has to be 6.
* **b)** `%s` is incorrect to read a char, it should be `%c`.
* **c)** `s` is not large enough, it has to be `s[13]` so it can store the char `'\0'`.
* **d)** The `if` should check for equality with 0 which would mean the strings are equals, or it will never work like intended.

### 8.22
* **a)** True
* **b)** False
* **c)** True
* **d)** True
* **e)** False
