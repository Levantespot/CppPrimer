# Getting Started

## Write a simple cpp program

> On most systems, the value returned from main is a status indicator. A return
> value of 0 indicates success. A nonzero return has a meaning that is defined by the system. Ordinarily a nonzero return indicates what kind of error occurred.  

**Variable Type** defines two things:

- the contents of a data element
- the operations that are possible on those data.

### Compiling and Executing using command line

I choose to use MSVC complier on Windows 10.

```powershell
> cl /?	# get help documents
> cl [ option... ] filename... [ /link linkoption... ]
```

To compile a program with only one code file:

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

iostream:

- Standard Input : cin
- Standard Output : cout
- Standard Error : cerr
- Standard Log : clog

**Writing to a Stream**

output operator `<<` returns its left-hand operand.

operator `endl` is a special value called a manipulator, Writing `endl `has the effect of ending the current line and flushing the buffer associated with that device.  Flushing the buffer ensures that all the output the program has generated so far is actually written to the output stream, rather than sitting in memory waiting to be written.  

scope operator `::` indicates the name is defined in a particular namespace (library).

**Reading from a Stream**

Initialize a variable = give it the indicated value at the same time as the variable is created.

the input operator `>>` returns its left-hand operand as its result.  

**Control Flow**

When we use an `istream` as a condition, the input operator (§ 1.2, p. 8) returns its left operand, which in this case is `std::cin`. Therefore, condition tests `std::cin`.  the effect is to test the state of the stream. If the stream is valid—that is, if the stream hasn’t encountered an error—then the test succeeds. An `istream` becomes invalid when we hit `end-of-file` or encounter an invalid input, such as reading a value that is not an integer. An `istream` that is in an invalid state will cause the condition to yield false.  

##  Exercises

### 1.1

```powershell
> cl /EHsc .\1.1.cpp
> .\1.1.exe
# nothing happened
> echo $?
True	# This is because our function returned zero, which means it runned and finished correctly.
```

### 1.2

```powershell
> cl /EHsc .\1.2.cpp
> .\1.2.exe
# nothing happened
> echo $?
False	# This is because our function returned -1, which means our program failed.
```

