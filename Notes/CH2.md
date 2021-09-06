# Chapter 2: Variables and Basic Types

**Types** determine the meaning of the data and operations in our programs.

## 2.1 Primitive Built-in Types

- arithmetic types
  - can represent: characters, integers, boolean values, and floating-point values.
- void type

### 2.1.1 Arithmetic Types

| Type        | Meaning                                  | Minimum Size          |
| ----------- | ---------------------------------------- | --------------------- |
| `bool`      | boolean                                  | NA                    |
| `char`      | character                                | 8 bits                |
| `wchar_t`   | wide character                           | 16 bits               |
| `char16_t`  | Unicode character                        | 16 bits               |
| `char32_t`  | Unicode character                        | 32 bits               |
| `short`     | short integer                            | 16 bits               |
| `int`       | integer                                  | 16 bits               |
| `long`      | long integer                             | 32 bits               |
| `long long` | long integer                             | 64 bits               |
| `float`     | single-precision floating-point          | 6 significant digits  |
| `double`    | double-precision floating-point          | 10 significant digits |
| `long`      | double extended-precision floating-point | 10 significant digits |

Note: The size of the arithmetic types varies across machine. The standard guarantees minimum sizes only.

#### Signed and Unsigned Types

1. Except for `bool` and the extended character types, the integral types may be `signed` or `unsigned`.
2. The types `int`, `short`, `long`, and `long long` are all signed. We obtain the corresponding unsigned type by adding `unsigned` to the type, such as `unsigned long`.
3. `unsigned` alone is an abbreviation for `unsigned int`.
4. `char`, `signed char`, and `unsigned char` are three distinct types. The (plain) `char` type uses one of two representations, `signed char` and `unsigned char`, depending on complier.

#### Advice: deciding which typed to use.

- Use an unsigned type when you know that the values cannot be negative.
- Use `int` for integer arithmetic. `short` is usually too small and, in practice, `long` often has the same size as `int`.
- Do not use plain `char` or `bool` in arithmetic expressions. Use them only to hold characters or truth values.
- Use `double` for floating-point computations; `float` usually does not have enough precision, and the cost of double-precision calculations versus single-precision is negligible.

### 2.1.2 Type conversions

| Target(below) | bool                                         | integer                                  | float-point                                                  |
| ------------- | -------------------------------------------- | ---------------------------------------- | ------------------------------------------------------------ |
| bool          | -                                            | False, if integer is 0; True, otherwise. | False, if float-point is 0; True, otherwise.                 |
| integer       | 1, if bool is True; 0, if bool is False.     | -                                        | Truncated, i.e., only the part before the decimal point will remain. |
| float-point   | 1.0, if bool is True; 0.0, if bool is False. | The fraction part is 0.                  | -                                                            |

Note: When assign a integer to a float-point number, precision may be lost if the integer has more bits than the floating-point object can accommodate.

| Target(below) | unsigned                                                     | signed                                                       |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| unsigned      | -                                                            | The result is the remainder of the value mod the size the target type can hold. |
| signed        | If we assign an out-of-range value to an object of signed type, the result is undefined. The program might appear to work, it might crash, or it might produce garbage values. | -                                                            |

Examples:

```c++
// Assume that char is 8-bit. signed char can hold [-128, 127].
// out-of-range situation:
unsigned char c = -1; // c = -1 mod 256 = 255
signed char c = 128; // undefined. On my computer, it complied successfully, but printing €.
```

#### Expression Involving Unsigned Types

```c++
// Wrong code below: u can never be less than 0; 
// The condition will always succeed because an unsigned cannot be less than zero.
// When u = 0, --u equals the calculation: -1 mode 2^32 = 4294967295
for (unsigned u = 10; u >= 0; --u)
	std::cout << u << std::endl;
```



## 2.2 Variables

## 2.3 Compund Types

## 2.4 const Qualifier

## 2.5 Dealing with  Types

## 2.6 Defining Our Own Data Structures



---

##  Exercises

### Exercises Section 2.1.1

2.1

|              | short       | int                | long                   | long long        |
| ------------ | ----------- | ------------------ | ---------------------- | ---------------- |
| bits         | 16          | 16 or 32           | 32                     | 64               |
| size ranking | short ≤ int | short ≤ int ≤ long | int ≤ long ≤ long long | long ≤ long long |

|             | signed                                                       | unsigned            |
| ----------- | ------------------------------------------------------------ | ------------------- |
| differences | Can be negative. But the maximum positive number it can express is less than the unsigned ones. | Always be positive. |
| e.g. char   | [-128, ... ,127]                                             | [0, ... 255]        |

|      | float | double |
| ---- | ----- | ------ |
| bits | 32    | 64     |

2.2

|        | rate            | principal       | payment         |
| ------ | --------------- | --------------- | --------------- |
| choice | unsigned double | unsigned double | unsigned double |



### Exercises Section 2.1.2

2.3

```powershell
```

### Exercises Section x.y.z

x.1

```powershell

```

### Exercises Section x.y.z

x.1

```powershell

```

