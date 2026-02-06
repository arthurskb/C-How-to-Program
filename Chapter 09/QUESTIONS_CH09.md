### 9.1
* **a)** streams
* **b)** (standard) input
* **c)** (standard) output
* **d)** `printf`
* **e)** conversion specifiers, flags, field widths, precisions, and literals
* **f)** `%d` or `%i`
* **g)** `%o`, `%u` and `%x`
* **h)** `h` and `l`
* **i)** `%e`
* **j)** `L`
* **k)** 6
* **l)** `%c` and `%s`
* **m)** `'\0'` null character
* **n)** `*`
* **o)** `-`
* **p)** `+`
* **q)** `scanf`
* **r)** `[]` scan set
* **s)** `%i`
* **t)** `%le`, `%lE`, `%lf`, `%lg`, `%lG`, `%lf`
* **u)** `*` assignment suppression character
* **v)** field width

---

### 9.2
* **a)** The conversion specifier has to be `%c` for a character.
* **b)** One `%` is missing; it should be appended after the last one to print a literal percent sign.
* **c)** The conversion specifier has to be `%.1s` (or using field width) for printing only the first character of a string.
* **d)** The escape `\` is missing before both `"` quotes.
* **e)** The format string double quotes are missing from the `printf` first argument.
* **f)** A character is represented with single quotes instead of double quotes: `'x'`.
* **g)** A string is represented with double quotes instead of single quotes: `"Richard"`.

---

### 9.3
* **a)** `printf("%10d\n", 1234);`
* **b)** `printf("%+.3e", 123.456789);`
* **c)** `scanf("%lf", &number);`
* **d)** `printf("%#o", 100);`
* **e)** `scanf("%s", string);`
* **f)** `scanf("%[0123456789]", n);`
* **g)** `printf("%*.*f", x, y, 87.4573);`
* **h)** `scanf("%f%%", &percent);`
* **i)** `printf("%+20.3f", 3.333333);`

---

### 9.4
* **a)** `printf("%-15.8u", 40000);`
* **b)** `scanf("%x", &hex);`
* **c)** `printf("%d", 200); printf("%+d", 200);`
* **d)** `printf("%#x", 100);`
* **e)** `scanf("%[^p]", s);`
* **f)** `printf("%09f", 1.234);`
* **g)** `scanf("%d%*c%d%*c%d", &hour, &minute, &second);`
* **h)** `scanf("\"%[^\"]\"", s);`
* **i)** `scanf("%d:%d:%d", &hour, &minute, &second);`

---

### 9.5
* **a)** `100000`
* **b)** Incorrect, it has to be `%s` instead of `%c` to print a string.
* **c)** `1024.987`
* **d)** `021`, `0x11`, `1.008837e+03`
* **e)** Incorrect, the constant arguments need an `L` suffix (e.g., `100L`) to match `long` specifiers.
* **f)** `4.45E+02`
* **g)** `444.94`
* **h)** Incorrect, argument `10.987` is a double; it should use `%f` or `%lf` instead of `%d`.

---

### 9.6
* **a)** The error is the usage of single quotes for a string; change it to double quotes `""`.
* **b)** The error is that `'Hello'` is not a character; change the specifier to `%s` and the quotes to `""`.
* **c)** The error is trying to print a string with `%c`; change it to `%s`.
* **d)** The error is the missing escape character to print quotes; use `\"s\"` instead.
* **e)** The error is trying to print a character with `%s`; use `%c` or pass the string pointer `day` instead of `day[3]`.
* **f)** The error is the usage of single quotes for a string; change it to double quotes `""`.
* **g)** The error is the missing double quotes in the format string; use `"%f"`.
* **h)** The error is the usage of `%s` to print a character; use `%c`.
* **i)** The error is trying to print an uninitialized character; assign a value to `s[7]` before printing.
