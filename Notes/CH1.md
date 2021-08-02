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

> When the type of a variable named v is T, we often say that “v has type T” or, interchangeably, that “v is a T.”  

### Compiling and Executing using command line

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

### The *while* Statement

A **while** statement repeatedly executes a section of code so long as a given condition is true. A **while** has the form:

```c++
while (condition) {
	statement    
}
```

A condition is an expression that yields a result that is either true or false.

### The *for* Statement

Each *for* statement has two parts: 

- A header 循环头
  - The header controls how often the body is executed. The header itself consists of three parts:
  - An init-statement 初始化语句
    - The init-statement is executed only once, on entry to the *for*.
    - Variables defined in init-statement only exist inside the *for*.
  - A condition 循环条件
    - The *for* body will be executed right after the condition successes.
  - An expression 表达式
    - After executing the body, the expression will be the next one to execute.
- A body 循环体

### Reading an Unknown Number of Inputs

When it's time that we won't know how many numbers to add, we can use an object of type istream as a condition to evaluate:

```c++
while (std::cin >> value)
	sum += value; // equivalent to sum = sum + value
```

>When we use an istream as a condition, the effect is to test the state of the stream. If the stream is valid—that is, if the stream hasn’t encountered an error—then the test succeeds. An istream becomes invalid when we hit **end-of-file 文件结束符** or encounter an invalid input (e.g. value is a int, but we receive a string), such as reading a value that is not an integer. An istream that is in an invalid state will cause the condition to yield false.  On Windows systems we enter an end-of-file by typing a control-z. On UNIX systems, including on Mac OS X machines, end-of-file is usually control-d.

##  Exercises

### 1.1 - 1.2

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

### 1.3 - 1.6

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

### 1.7 - 1.8

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

### 1.9 - 1.11

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
Please input two different numbers
1 12
1 2 3 4 5 6 7 8 9 10 11 12
```

### 1.12 - 1.15

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



