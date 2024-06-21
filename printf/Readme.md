<p align="center">
  <img width="560" height="200" src="https://github.com/Ancava2000/42Cursus/assets/160865430/362d1dfc-8589-4397-b09d-3d3568e2bdb7">
</p>

## Table of Contents 🔖
1. [About](#About)
2. [Variadic Functions](#Var)
3. [Formats](#Form)
4. [Structure](#Struct)
5. [Makefile](#Make)
   - [Commands](#Comm)
6. [Resources](#Res)
***
<a id="About"></a>
## About 🚀
This project consists of reprogramming the ```printf()``` function from the libc library. Your function will be compared with the original printf. It should be noted that it is not necessary to implement the buffer management of the original printf and that it will handle various conversion formats. The prototype of ft_printf() is:
```c
int ft_printf(char const *, ...);
```
```You are going to discover a very famous and versatile C function: printf(). This exercise is a great opportunity to improve your programming skills. It is a moderately difficult exercise. You will also discover variadic functions in C. The key to succeeding in ft_printf is having well-structured and extensible code.```
<a id="Var"></a>
## Variadic Functions
The main complexity of this function lies in: **dealing with an indeterminate number and type of parameters** (pointed by the elipsis in the parameters of the prototype) and **returning an ```int``` type.**
The first problem is a function named variadic function, which consists of at least one fixed variable and then an ellipsis(…) as the last parameter. To handle this we use the macros of the stdarg.h library:

| **Function Name**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **va_list** <sub>(typedef)<sub>       | Holds the information needed by va_start, va_arg, va_end, and va_copy. Ex: ```va_list ptr``` \\\ Declaring pointer to the argument list \\\     |
| **va_start** <sub>(macro)<sub>        | Enables access to variadic function arguments. Ex: ```va_start(ptr, n)``` \\\ Initializing argument to the list pointer \\\ |
| **va_arg** <sub>(macro)<sub>          | Accesses the next variadic function argument. Ex: ```sum += va_arg(ptr, int)``` \\\ Accessing current variable and pointing to next one \\\ |
| **va_end** <sub>(macro)<sub>          | Ends traversal of the variadic function arguments. Ex: ```va_end(ptr)``` \\\ Ending argument list traversal \\\ |

To solve the integer problem, an ```int count``` variable is initialized in the prototype function. This variable stores the value of the function based on the format used in printf. Finally, count is the variable that is returned. Example:
```c
int	ft_printf(char const *str, ...)
{
	va_list	ap;
	int	count;

	count = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_format(*str, ap);
		}
		else
			count += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (count);
}
```

<a id="Form"></a>
## Formats
In your printf you must be able to use the following formats:

| **Format**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **%c**  | Prints a character. ```char```  |
| **%s**  | Prints a string. ```char *``` |
| **%p**  | Prints a ```void pointer``` in hexadecimal format |
| **%d**  | Prints a decimal number (10 base) |
| **%i**  | Prints an integer (10 base). ```ìnt```|
| **%u**  | Prints an ```unsigned integer``` (10 base) |
| **%x**  | Prints an hexadecimal numer in lowercase (16 base)|
| **%X**  | Prints an hexadecimal numer in uppercase (16 base) |
| **%%**  | Prints the % symbol |

<a id="Struct"></a>
## Structure
