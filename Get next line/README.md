<p align="center">
  <img width="560" height="200" src="https://github.com/user-attachments/assets/ceaa65db-4445-442c-856d-5a8381426b61">
</p>

## Table of Contents 🔖
1. [About](#About)
2. [Functions](#Fun)
   - [Static Variables](#Stat)
   - [Macros](#Mac)
3. [Structure](#Struct)
4. [Usage](#Us)
5. [Resources](#Res)
***
<a id="About"></a>
## About 🚀
This project is about programming a function that returns a line read from a file descriptor. You will learn new concepts like static variables and a BUFFER SIZE macro.
The prototype of get_next_line() is:
```c
char *get_next_line(int fd);
```
```Reading a line from a fd is way too tedious. This project will not only allow you to add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in C programming: static variables.```
<a id="Fun"></a>
## Functions 🧾
**External Functions**
| **Function Name**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **read();** | To read nbyte bytes from the file associated with the open file descriptor. |
| **malloc();** | To allocate memory for the lines. |
| **free();** | To free the memory and in the case of an error. |

**Auxiliary Functions**
| **Function Name**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| void	ft_bzero(void *s, size_t n); | The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area. |
| void	*ft_calloc(size_t count, size_t size); | The calloc() function shall allocate unused space for an array of count elements each of whose size in bytes is size. The space shall be initialized to all bits 0. |
| size_t	ft_strlen(char *s); | The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0'). |
| char	*ft_strchr(char *s, int c); | The strchr() function returns a pointer to the first occurrence of the character c in the string s. |
| char	*ft_strjoin(char *s1, char *s2); | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’. |

In this project we find a new function called read(). ```The read() function is a low-level file manipulation function used to perform read operations on a file. It can be accessed by using the unistd.h library provided by C.``` The syntax of the read function is:
```c
int read(int fileDescriptor, void *buffer, size_t bytesToRead)
```
- ```fileDescriptor:``` The function needs a file descriptor to read the lines. Previously, to be able to read the file,, we should have opened the file with the function open(). For example ```fd = open("aaa.txt", O_RDONLY);```
- ```buffer*:``` A pointer to the buffer in which the read data will be stored.
- ```*bytesToRead*:``` The numbers of bytes we want to read from the file in each loop.

For example, in my get next line I used:
```c
i = read(fd, temp, BUFFER_SIZE);
```
I read a number of bytes in the fd according to the BUFFER_SIZE (established in get_next_line.h), storing all of them in a temp variable.
Finally, in regard of the return value:
- if the line is read and shown the behavior is correct ✅.
- if the value is NULL there is nothing else to read, or an error occurred ❌. 
<a id="Stat"></a>
### Static Variables
The static variable have the ability to preserve its previous value in its previous scope without initializing in each loop. The variable only initializes one time. This type of variable is used in the project to preserve the number of bytes read in each loop. Due to this, we don't continually store the same letters in each loop, but we continue the byte count from the previous position.

<img width="590" height="420" src= "https://github.com/user-attachments/assets/ada82a40-06e3-43c6-a8e6-640a984475e5">

<a id="Mac"></a>
### Macros
Macros in C are powerful tools that allow developers to define reusable code snippets. They are defined using preprocessor directives and primarily used for code substitution and generation. Macros provide a convenient way to write concise and efficient code, improving the readability and maintainability of C programs.

Specifically, the preprocessor directive used in macros is the ```#define``` directive. It associates a name with a value or an expression, so whenever the compiler encounters a macro in a program, it will replace it with the macro value.
In the case of get next line, I define a macro named BUFFER_SIZE with a value of 42 in the library.
```c
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
```

<a id="Struct"></a>
## Structure 🗃️
Project Functions:
| **Function Name**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **get_next_line** | Reads from ```fd``` and returns the ```line``` or ```NULL``` |
| **read_file** | Allocates enough memory in a ```temp``` variable to stored the content of the ```BUFFER_SIZE```. In a loop the ```fd``` is read and stored in ```temp```. The content of ```temp``` is copied to the ```buffer``` variable. If the ```\n``` is found in the ```temp```, the loop is broken. Returns ```buffer``` (all the read string) and free ```temp```  |
| **buffer_copy** | In a loop, the ```i``` variable stores the number of characters in the ```buffer``` until ```\0``` or ```\n```. With that count the function allocates enough memory in the ```line``` variable to stored the characters of the ```buffer``` until ```\0``` or ```\n```. The content of ```buffer``` is copied in the ```line``` variable until ```\n```. Returns ```line``` (the string before \n) |
| **buffer_rest** | In a loop, the ```i``` variable stores the number of characters in the ```buffer``` until ```\0``` or ```\n```. With that count the function allocates enough memory in the ```temp``` variable, subtracting the count from the buffer length, to stored the characters of the ```buffer``` after ```\n```. The content of ```buffer``` is copied in the ```temp``` variable until ```\0```. Returns ```temp``` (the string after /n) |
| **ft_free** | Joins the contents of ```temp``` and ```buffer``` into a new variable called ```joined```. Used in ```read_file``` to stored ```buffer``` with all the content |

<p align="left">
	<img  width="740" height="500" src= "https://github.com/user-attachments/assets/6779f51c-4815-40f3-bbca-877d446775ee">
</p>

<a id="Us"></a>
## Usage
Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read().
You will compile your code as follows (a buffer size of 42 is used as an example): 
```c
clang -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
./a.out
```
If your main indicates the name of the file to read, you have to create a file with that name. For example:
```c
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("aaa.txt", O_RDONLY);
	while (i > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free (line);
	}
	close(fd);
	return (0);
```
In the case your main doesn't indicates the file name, when you execute the program you have to also write the name of the file:
```c
./a.out aaa.txt
```

<a id="Res"></a>
## Resources 📹
- **Static variables:** [geeksforgeeks](https://www.geeksforgeeks.org/static-variables-in-c/) and [PrepBytes Blog](https://www.prepbytes.com/blog/c-programming/static-variable-in-c/)
- **Macros:** [geeksforgeeks](https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/)
- **Understanding get next line:** The great Oceano's video [get_next_line explained : develop a function that reads a file line by line](https://www.youtube.com/watch?v=8E9siq7apUU) and nikito's video [comprendre get_next_line](https://www.youtube.com/watch?v=-Mt2FdJjVno)
- **Testers:** [Tripouille](https://github.com/Tripouille/gnlTester) 

Thanks for watching my get next line project!! <sub>I'll appreciate every comment or message about it 🚀</sub>

![Alt text](https://i.giphy.com/media/v1.Y2lkPTc5MGI3NjExZWU4dnNxcDNtNXd1dWh5enNqc2dwNjIzYzk2MGR5ZXduaWlybGp0ayZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/13GIgrGdslD9oQ/giphy.gif)
