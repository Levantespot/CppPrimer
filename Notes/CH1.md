# Chapter 1: Getting Started

## 1.1 Write a simple cpp program

>Every C++ program contains one or more **functions 函数**, one of which must be named `main`. The operating system runs a C++ program by calling `main`. Here is a simple version of main that does nothing but return a value to the operating system:  
>
>```c++
>int main()
>{
>    return 0;
>}
>```
>
>A **function definition 函数定义** has four elements: a **return type 返回类型**, a **function name 函数名**, a (possibly empty) **parameter list 形参列表** enclosed in parentheses, and a **function body 函数体**. Although main is special in some ways, we define `main` the same way we define any other function.  
>
>The final part of a function definition, the function body, is a **block of statements 语句块** starting with an open curly brace 左花括号 and ending with a close curly brace 右花括号.

**Variable Type 变量类型** defines two things:

- the contents of a data element
- the operations that are possible on those data.

> When the type of a variable named v is T, we often say that "v has type T" or, interchangeably, that "v is a T."  

### 1.1.1 Compiling and Executing using command line

I choose to use MSVC complier on Windows 10.

```powershell
> cl /?	# get help documents
> cl [ option... ] filename... [ /link linkoption... ]
```

Typically, to compile a program with only one code file:

```powershell
> cl /EHsc foo.cpp
```

To compile a program that has additional source code files, enter them all on the command line, like:

```powershell
> cl /EHsc file1.cpp file2.cpp file3.cpp
```

When you supply additional source files, the compiler uses the *first* input file to create the program name. In this case, it outputs a program called file1.exe. To change the name to program1.exe, add an `/out` linker option (add `/ link` ahead):

```
> cl /EHsc file1.cpp file2.cpp file3.cpp /link /out:program1.exe
```

We can use `echo $?` to obtain status of our program after running it.

## 1.2 A First Look at Input/Output

> The C++ language does not define any statements to do input or output (IO). Instead, C++ includes an extensive **standard library** that provides IO (and many other facilities).  
>
> Fundamental to the `iostream` library are two types named `istream` and `ostream`, which represent input and output streams, respectively. A **stream** is a sequence of characters read from or written to an IO device. The term **stream** is intended to suggest that the characters are generated, or consumed, sequentially over time.

Four IO objects in library iostream:

- cin: an object of type istream, also called **standard input 标准输入**
- cout: an object of type ostream, also called **standard output 标准输出**
- cerr: an object of type ostream, also called **standard error 标准错误**
- clog: an object of type ostream, for general information about the execution of the program.

iostream 库定义了两种 type : istream & ostream，根据前文 type 定义的两种东西，则它俩又分别定义了其数据元素的内容（流）和可行的操作、运算 (>> & <<)。而 cin, cout, cerr, clog 又是库中定义的四个对象 (object)，类型 (type) 是 istream, ostream 之一。

疑问：对象和类型之间是什么关系？查阅资料如下：

> An object, in C++, has 
>
> - size (can be determined with sizeof);
> - alignment requirement (can be determined with alignof);
> - storage duration (automatic, static, dynamic, thread-local);
> - lifetime (bounded by storage duration or temporary);
> - **type**;
> - value (which may be indeterminate, e.g. for default-initialized non-class types);
> - optionally, a name.
>
> The following entities are not objects: value, reference, function, enumerator, type, non-static class member, template, class or function template specialization, namespace, parameter pack, and `this`.

似乎这里的对象和类 (class) 实例化后的对象不一样。

### A Program that Uses the IO Library

```c++
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    std::cout << "..." << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
			  << " is " << v1 + v2 << std::endl;
    return 0;
}
```

> The name inside angle brackets (`iostream` in this case) refers to a **header**. Every program that uses a library facility must include its associated header. The `#include` directive must be written on a single line—the name of the header and the `#include` must appear on the same line. In general, `#include` directives must appear outside any function. Typically, we put all the #include directives for a program at the beginning of the source file.  

### Writing to a Stream

> The first **statement 语句** in the body of `main` executes an **expression 表达式**. In C++ an expression yields a result and is composed of one or more operands and (usually) an operator. The expressions in this statement use the **output operator 输出运算符** (the `<<` operator) to print a message on the standard output:
>
> ```c++
> std::cout << "Enter two numbers:" << std::endl;
> ```
>
> The `<<` operator takes two operands: The left-hand operand must be an `ostream` object; the right-hand operand is a value to print. The operator writes the given value on the given `ostream`.  
>
> Output operator `<<` returns its left-hand operand. And the result of the first operator becomes the left-hand operand of the second. As a result, we can chain together output requests. Thus, our expression is equivalent to
>
> ```c++
> (std::cout << "Enter two numbers:") << std::endl;
> # or
> std::cout << "Enter two numbers:";
> std::cout << std::endl;
> ```
>
> The first output operator prints a message to the user. That message is a **string literal 字符串字面常量**, which is a sequence of characters enclosed in double quotation marks.  
>
> The second operator prints `endl`, which is a special value called a **manipulator 操纵符**, Writing `endl` has the effect of ending the current line and flushing the buffer associated with that device.  Flushing the buffer ensures that all the output the program has generated so far is actually written to the output stream, rather than sitting in memory waiting to be written.  

### Using Names from the Standard Library

> The prefix `std::` indicates that the names `cout` and `endl` are defined inside the **namespace 命名空间** named `std`. Namespaces allow us to avoid inadvertent collisions between the names we define and uses of those same names inside a library. All the names defined by the standard library are in the std namespace.
>
> Writing `std::cout` uses the **scope operator 作用域运算符** (the `::` operator) to say that we want to use the name `cout` that is defined in the namespace `std`.  

### Reading from a Stream

>We start by **defining 定义** two **variables 变量** named `v1` and `v2` to hold the input:  
>
>```c++
>int v1 = 0, v2 = 0;
>```
>
>We define these variables as type `int`, which is a built-in type representing integers. We also **initialize 初始化** them to 0. When we initialize a variable, we give it the indicated value at the same time as the variable is created.
>
>```c++
>std::cin >> v1 >> v2;
>```
>
>reads the input. The **input operator 输入运算符** (the `>>` operator) behaves analogously to the output operator. It takes an `istream` as its left-hand operand and an object as its right-hand operand. It reads data from the given `istream` and stores what was read in the given object. Like the output operator, the input operator returns its left-hand operand as its result.

### Completing the Program

>The interesting part in this example is that the operands are not all the same kinds of values. Some operands are **string literals**, such as "The sum of ". Others are **int** values, such as `v1`, `v2`, and the result of evaluating the arithmetic expression `v1 + v2`. The library defines versions of the input and output operators that handle operands of each of these differing types. 详见「函数重载」。

## 1.3 A Word about Comments

There are two kinds of comments in C++: single-line 单行注释 and paired 界定符对注释.

- A single-line comment starts with a double slash (`//`) and ends with a newline.  A comment of this kind can contain any text, including additional double slashes.  Thus, single-line comment do **nest**.
- The other kind of comment begin with a `/*` and end with the next `*/`. These comments can include anything that is not a `*/`, including newlines.  Thus, comment pairs **do not nest**. Comment pairs can span multiple lines of a program but are not required to do so. Our style is to begin each line in the comment with an asterisk (`*`), thus indicating that the entire range is part of a multiline comment.

Programs typically contain a mixture of both comment forms. Comment pairs generally are used for multi-line explanations, whereas double-slash comments tend to be used for half-line and single-line remarks:

```c++
#include <iostream>
/*
 * Simple main function:
 * Read two numbers and write their sum
 */
int main()
{
	// prompt user to enter two numbers
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;   // variables to hold the input we read
	std::cin >> v1 >> v2; // read input
	std::cout << "The sum of " << v1 << " and " << v2
	<< " is " << v1 + v2 << std::endl;
	return 0;
}
```

We often need to comment out a block of code during debugging. Because that code might contain nested comment pairs, the best way to comment a block of code is to insert single-line comments at the beginning of each line in the section we want to ignore:

```c++
// /*
//  * everything inside a single-line comment is ignored
//  * including nested comment pairs
//  */  
```

## 1.4 Flow of Control

Statements normally execute sequentially: The first statement in a block is executed first, followed by the second, and so on.  

### 1.4.1 The *while* Statement

A **while** statement repeatedly executes a section of code so long as a given condition is true. A **while** has the form:

```c++
while (condition) {
	statement    
}
```

A condition is an expression that yields a result that is either true or false.

### 1.4.2 The *for* Statement

Each *for* statement has two parts: 

- A header 循环头
  - The header controls how often the body is executed. The header itself consists of three parts:
  - An init-statement 初始化语句
    - The init-statement is executed only **once**, on entry to the *for*.
    - Variables defined in init-statement only exist inside the *for*.
  - A condition 循环条件
    - The *for* body will be executed right after the condition successes.
  - An expression 表达式
    - The expression will be the next one to execute after the body.
- A body 循环体

### 1.4.3 Reading an Unknown Number of Inputs

When it's time that we won't know how many numbers to add, we can use an object of type istream as a condition to evaluate:

```c++
while (std::cin >> value)
	sum += value; // equivalent to sum = sum + value
```

>When we use an istream as a condition, the effect is to test the state of the stream. If the stream is valid—that is, if the stream hasn’t encountered an error—then the test succeeds. An istream becomes invalid when we hit **end-of-file 文件结束符** or encounter an invalid input (e.g. value is a int, but we receive a string), such as reading a value that is not an integer. An istream that is in an invalid state will cause the condition to yield false.  On Windows systems we enter an end-of-file by typing a `control-z`. On UNIX systems, including on Mac OS X machines, end-of-file is usually `control-d`.

#### Common errors when compiling

A compiler cannot detect whether a program does what its author intends, but it can detect errors in the *form* of the program: 

1. Syntax errors 语法错误: Wrong punctuations and grammatical errors.
2. Type errors 类型错误: The types of value and variable mismatch when assigning.
3. Declaration errors 声明错误: Failure to declare a name when using it.

### 1.4.4 The *if* Statement

*if* statement is for conditional execution.

```c++
if (condition) {
    statement 1
} else {
    statement 2
}
```

If the condition is true, we execute the statement 1 that immediately follows the condition, otherwise statement 2.

| operator | meaning      | opposite operator | meaning                  |
| -------- | ------------ | ----------------- | ------------------------ |
| `==`     | equal to     | `!=`              | not equal to             |
| `>`      | greater than | `<=`              | less than or equal to    |
| `<`      | less than    | `>=`              | greater than or equal to |

## 1.5 Introducing Classes

> In C++ we define our own **data structures 数据结构** by defining a **class 类**. A class defines a type along with a collection of operations that are related to that type. As we’ve seen, to use a library facility, we must include the associated header. Similarly, we use headers to access classes defined for our own applications. Conventionally, header file names are derived from the name of a class defined in that header. Header files that we write usually have a suffix of .h, but some programmers use .H, .hpp, or .hxx. The standard library headers typically have no suffix at all. Compilers usually don’t care about the form of header file names, but IDEs sometimes do.  

### 1.5.1 The *Sales_item* Class

>For our bookstore problem, we’ll assume that the class is named *Sales_item*, which represent the total revenue, number
>of copies sold, and average sales price for a book. How these data are stored or computed is not our concern for now.
>
>Every class defines a type. The type name is the same as the name of the class. Hence, our *Sales_item* class defines a type named *Sales_item*. As with the built-in types, we can define a variable of a class type. When we write:
>
>```c++
>Sales_item item;
>```
>
>we are saying that item is an object of type Sales_item. We often contract the phrase "an object of type Sales_item" to "a Sales_item object" or even more simply to "a Sales_item".  

To use a class we need to know three things:

- What is its name?
- Where is it defined?
- What operations does it support?

#### Reading and Writing *Sales_items*

```c++
Sales_item book;
// read ISBN, number of copies sold, and sales price
std::cin >> book;
// write ISBN, number of copies sold, total revenue, and average price
std::cout << book << std::endl;
```

If the input to this program is `0-201-70353-X 4 24.99`, then the output will be `0-201-70353-X 4 99.96 24.99`.

#### Adding *Sales_items*

```c++
Sales_item item1, item2;
std::cin >> item1 >> item2; // read a pair of transactions
std::cout << item1 + item2 << std::endl; // print their sum
```

If we give this program the following input `0-201-78345-X 3 20.00`, `0-201-78345-X 2 25.00`, our output is `0-201-78345-X 5 110 22`.

> What makes this similarity noteworthy is that instead of reading and printing the sum of two integers, we’re reading and printing the sum of two Sales_item objects. Moreover, the sum has a new meaning—result of adding the components of two Sales_item objects.  

#### Using File Redirection

It can be tedious to repeatedly type these transactions as input to the programs you are testing. Most operating systems support file redirection, which lets us associate a named file with the standard input and the standard output:

```bash
$ addItems <infile >outfile # Bash for Unix
> cat infile | addItem > outfile # PowerShell for Windows
```

Assuming `>` or `$` is the system prompt and our addition program has been compiled into an executable file named addItems.exe), this command will read transactions from a file named `infile` and write its output to a file named `outfile` in the current directory.

##  Exercises

### Exercises Section 1.1.1

1.1

```powershell
> cl /EHsc .\1.1.cpp
> .\1.1.exe
# nothing happened
> echo $?
True	# This is because our function returned zero, which means it runned and finished correctly.
```

1.2

```powershell
> cl /EHsc .\1.2.cpp
> .\1.2.exe
# nothing happened
> echo $?
False	# This is because our function returned -1, which means our program failed.
```

### Exercises Section 1.2

1.3

```powershell
> cl /EHsc .\1.3.cpp
> .\1.3.exe
Hello, World
```

1.4

```powershell
> cl /EHsc .\1.4.cpp
> .\1.4.exe
Enter two numbers:
4
5
The product of 4 and 5 is 20
```

1.5

```powershell
> cl /EHsc .\1.5.cpp
> .\1.5.exe
Enter two numbers:
4
5
The sum of 4 and 5 is 9
```

1.6

Not legal. Because `;` end a statement, which means `<<` in second and third statement don't have left-operand. To fix it, add `std::cout` at the head of 2nd & 3rd line like:

```c++
std::cout << "The sum of " << v1;
std::cout << " and " << v2;
std::cout << " is " << v1 + v2 << std::endl;
```

### Exercises Section 1.3

1.7

```powershell
> cl /EHsc .\1.7.cpp
1.7.cpp
1.7.cpp(5): warning C4138: '*/' found outside of comment
1.7.cpp(5): error C2059: syntax error: '/'
```

1.8

```c++
std::cout << "/*";	// correct
std::cout << "*/";  // correct
std::cout << /* "*/" */;	// incorrect
std::cout << /* "*/" /* "/*" */;	// correct
```

The 3rd one can be revised to: 

```c++
std::cout << "*/";
```

### Exercises Section 1.41

1.9

```c++
> .\1.9
The sum from 50 to 100 is 3825
```

1.10

```c++
> .\1.10
10 9 8 7 6 5 4 3 2 1 0
```

1.11

```c++
> .\1.11
Please input two different numbers, the 1st one is greater
5 1
5 4 3 2 1
```

### Exercises Section 1.42

1.12

The final value of sum is 0.

1.13

```c++
> .\1.13a
The sum from 50 to 100 is 3825
```

```c++
> .\1.13b
10 9 8 7 6 5 4 3 2 1 0
```

1.14

Theoretically, *for* and *while* are the same. But it will be more convenient to use *while* if you don't want to initialize a new variable. Otherwise the *for* statement can make your code much more compact.

1.15

```powershell
> cl /EHsc 1.15.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.29.30038.1 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

1.15.cpp
1.15.cpp(6): error C2440: '=': cannot convert from 'const char [6]' to 'int'
1.15.cpp(6): note: There is no context in which this conversion is possible
1.15.cpp(8): error C2065: 'b': undeclared identifier
1.15.cpp(10): error C2143: syntax error: missing ';' before ':'
1.15.cpp(10): error C2059: syntax error: ':'
```

### Exercises Section 1.43

1.16

```powershell
> .\1.16
Please input some integers, and this program will output their sum. (Input ctrl-z to end input.)
-1 4 5 6 2 ^Z
Sum is: 16
```

### Exercises Section 1.4.4

1.17

If the input values are all equal, we will get only one line for that value with its counting times. If there are no duplicated values, we will get each line for each value and corresponding count is all 1.

1.18

```powershell
> .\1.18
1 1 1 1 1 ^Z
1 occurs 5 times
> .\1.18
1 2 3 4 5 ^Z
1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
```

1.19

```powershell
> .\1.19
Please input two different numbers
1 6
1 2 3 4 5 6
> .\1.19
Please input two different numbers
6 1
1 2 3 4 5 6
```

### Exercises Section 1.5.1

1.20

```powershell
> cat 1.20.txt | .\1.20.exe
Please input every transaction with ISBN, number of copies sold, and sales price.
ISBN num_sold price_sum price_each
0-201-78341-X 1 20 20
ISBN num_sold price_sum price_each
0-201-78342-X 2 50 25
ISBN num_sold price_sum price_each
0-202-68341-X 3 60 20
ISBN num_sold price_sum price_each
0-202-68342-X 4 100 25
ISBN num_sold price_sum price_each
0-301-58341-X 5 100 20
ISBN num_sold price_sum price_each
0-301-58342-X 6 150 25
```





### Exercises Section X
