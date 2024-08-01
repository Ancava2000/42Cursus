<p align="center">
  <img width="560" height="200" src="https://github.com/user-attachments/assets/ceaa65db-4445-442c-856d-5a8381426b61">
</p>

## Table of Contents 🔖
1. [About](#About)
2. [Functions](#Fun)
   - [Static Variables](#Stat)
   - [Macros](#Mac)
4. [Structure](#Struct)
5. [Makefile](#Make)
   - [Commands](#Comm)
   - [Usage](#Us)
6. [Resources](#Res)
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
int read(int fileDescriptor, void *buffer, size_t bytesToRead) y el output.
```
<a id="Stat"></a>
### Static Variables
<a id="Mac"></a>
### Macros
<a id="Struct"></a>
## Structure 🗃️
<a id="Make"></a>
## Makefile ♻️
<a id="Comm"></a>
### Commands
<a id="Us"></a>
### Usage
<a id="Res"></a>
## Resources 📹
