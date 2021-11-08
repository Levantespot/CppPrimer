# Chapter 4: Expressions





##  Exercises

### Exercises Section 4.1.2

4.1 pass

4.2 pass

### Exercises Section 4.1.3

4.3 pass

### Exercises Section 4.2

4.4 pass

4.5 pass

4.6 pass

4.7 pass

### Exercises Section 4.3

4.8

```
逻辑与 > 相等性 > 逻辑或
```

4.9

```c++
if (cp != nullptr) {
	if (*cp != 0) {
		...
	}
}
```

4.10

4.11

```poweshell
1 2 3 4
False.
5 4 2 1
True! a > b > c > d
```

4.12

```c++
i!=(j<k)
```



### Exercises Section 4.4

4.13

```c++
int i; double d;
(a) d = i = 3.5; // i = 3, d = 3.0
(b) i = d = 3.5; // d = 3.5, i = 3
```

4.14 pass

4.15 

```c++
double dval; int ival; int *pi;
dval = ival = 0;
pi = 0;
```

4.16

```c++
(a) if (p = getPtr() != 0) -> if ((p = getPtr()) != 0)
(b) if (i = 1024) -> if (i == 1024)
```

### Exercises Section 4.5

4.17 pass

4.18 pass

4.19 pass

### Exercises Section 4.6

4.20

```c++
(a) *iter++; 		// *iter; ++iter;
(b) (*iter)++; 		// string does not define ++ operator or a conversion to a string
(c) *iter.empty()	// Error. Revised as (*iter).empty()
(d) iter->empty();	// Legal
(e) ++*iter;		// Not legal, string does not define ++ operator or a conversion to a string
(f) iter++->empty();	// iter->empty(); iter++;
```

### Exercises Section 4.7

4.21

```
1 2 3 4 5 6 7
^Z
2 2 6 4 10 6 14
```

4.22

```
5
fail
55
fail
65
low pass
75
low pass
80
pass
90
pass
100
high pass
```

4.23

```c++
string s = "word";
string pl = s + s[s.size() - 1] == ’s’ ? "" : "s" ;
// ->
string pl = s + ((s[s.size() - 1] == ’s’) ? "" : "s" );
```

4.24 pass

### Exercises Section 4.8

4.25 pass

4.26 pass

4.27

```c++
unsigned long ul1 = 3, ul2 = 7; // 011, 111
(a) ul1 & ul2	// 011
(b) ul1 | ul2	// 111
(c) ul1 && ul2 	// true
(d) ul1 || ul2	// true
```

### Exercises Section 4.9

4.28

```c++
bool:           1 bytes

char:           1 bytes
wchar_t:        2 bytes
char16_t:       2 bytes
char32_t:       4 bytes

short:          2 bytes
int:            4 bytes
long:           4 bytes
long long:      8 bytes

float:          4 bytes
double:         8 bytes
long double:    8 bytes
```

4.29 pass

4.30 pass

### Exercises Section 4.10

4.31 pass

4.32 pass

4.33

```c++
(someValue ? ++x, ++y : --x), --y;

// equals to
if (someValue is True) {
    ++x;
    return ++y;
} else {
    return --x;
}
--y;
```

### Exercises Section 4.11.1

4.34

```c++
(a) if (fval) 			// float -> bool
(b) dval = fval + ival; // int -> float -> double
(c) dval + ival * cval;	// char -> int -> double
```

4.35

```c++
(a) cval = ’a’ + 3; 			// char -> int -> char
(b) fval = ui - ival * 1.0;		// int -> double, unsigned -> double, double -> float
(c) dval = ui * fval; 			// unsigned -> float -> double
(d) cval = ival + fval + dval;	// int -> float, float -> double, double -> char
```





### Exercises Section 4.11.3

4.36

4.37

```c++
int i; double d; const string *ps; char *pc; void *pv;
(a) pv = (void*)ps; 	// pv = static_cast<void*>(const_cast<string*>(ps));
(b) i = int(*pc);		// i = static_cast<int>(*pc);
(c) pv = &d; 			// pv = static_cast<void*>(&d);
(d) pc = (char*) pv;	// pv = reinterpret_cast<char*>(pv);
```

4.38

```
(j/i) is a `int`, then cast to double.
```





### Exercises Section x.y.z

x.1

```powershell
```


