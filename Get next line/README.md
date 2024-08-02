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
| **void	ft_bzero(void *s, size_t n);*** | The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area. |
| **void	*ft_calloc(size_t count, size_t size);*** | The calloc() function shall allocate unused space for an array of count elements each of whose size in bytes is size. The space shall be initialized to all bits 0. |
| **size_t	ft_strlen(char *s);*** | The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0'). |
| **char	*ft_strchr(char *s, int c);**** | The strchr() function returns a pointer to the first occurrence of the character c in the string s. |
| **char	*ft_strjoin(char *s1, char *s2);***** | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’. |

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

<a id="Struct"></a>
## Structure 🗃️

<a id="Us"></a>
## Usage
<a id="Res"></a>
Because you will have to read files in get_next_line(), add this option to your compiler call: -D BUFFER_SIZE=n. It will define the buffer size for read().
You will compile your code as follows (a buffer size of 42 is used as an example): 
```c
clang -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
./a.out
```
If your main indicates the name of the file, you have to create a file with that name. 
## Resources 📹
