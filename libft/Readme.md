WIP
# **42 LIBFT**
## Table of Contents
1. [About](#About)
2. [Functions](#Functions)

   - [Libc functions](#Libc_func)
   - [Additional functions](#Add_func)
   - [Bonus functions](#Bonus)

3. [Makefile](#Makefile)

   - [Commands]()
   - [Compile]()
4. [Resources](#Res)
***
<a id="About"></a>
## About 🚀
```The aim of this project is to code a C library regrouping usual functions that you’ll be allowed to use in all your other projects.```

```C programming can be very tedious when one doesn’t have access to those highly useful standard functions. This project gives you the opportunity to re-write those functions, understand them, and learn to use them. This library will help you for all your future C projects.``` 

In this project, you'll have to learn about memory allocation, malloc and free functions, and how structs work. I recommend doing the bonus part (structs) because you'll use these type of functions in future projects. Lastly, you should add bit by bit every function that you are going to code, so you can create a pretty complete library in C. :comet:GOOD LUCK!:comet:
***

<a id="Functions"></a>
## Functions
<a id="Libc_func"></a>
### Libc functions
```
memset, bzero, memcpy, memccpy, memmove, memchr, memcmp, strlen,
strlcpy, strlcat, strchr, strrchr, strnstr, strncmp, atoi, isalpha,
isdigit, isalnum, isascii, isprint, toupper, tolower, calloc, strdup
```
   - [**Memset**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_memset.c)

| **Function Name**         | ft_memset                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void *memset(void *dest, int c, size_t n);```                                                                                                        |
| **Parameters**            | ```*dest:``` Pointer to destination. <br /> ```c:``` Character to set. <br /> ```n:``` Number of bytes to be set to the value. |
| **Return Value**          | The memset() function returns a pointer to the memory area s.   |
| **Description**           | The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c. |

   - [**Bzero**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_bzero.c)

| **Function Name**         | ft_bzero                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void bzero(void* s, size_t n);```                               |
| **Parameters**            | ```*s:``` The starting address in the byte area.  <br /> ```n:``` The size of the data.   |
| **Return Value**          | None.  |
| **Description**           | The bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area. |
     
   - [**Memcpy**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_memcpy.c)

| **Function Name**         | ft_memcpy                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void *memcpy(void *s1, const void * s2, size_t n);```                   |
| **Parameters**            | ```*s1:``` New buffer. <br /> ```*s2:``` Buffer to copy from. <br /> ```n:``` Number of characters to copy.   |
| **Return Value**          | The memcpy() function returns a pointer to dest.  |
| **Description**           |  The memcpy() function copies n bytes from memory area src to memory area dest.  The memory areas must not overlap.  Use memmove(3) if the memory areas do overlap. |

   - [**Memmove**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_memmove.c)

| **Function Name**         | ft_memmove                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void *memmove(void *dest, const void *src, size_t n);```        |
| **Parameters**            | ```*dest:``` Pointer to destination where the content is to be copied. <br /> ```src:``` Pointer to source object to be copied. <br /> ```n:``` Number of characters to copy.   |
| **Return Value**          | The memmove() function shall return dest. No return value is reserved to indicate an error. |
| **Description**           |  The memmove() function copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as though the bytes in src are first copied into temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.|

   - [**Memchr**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_memchr.c)

| **Function Name**         | ft_memchr                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void *memchr(const void s, int c, size_t n);```        |
| **Parameters**            | ```*s:``` Pointer to buffer. <br /> ```c:``` Character to look for. <br /> ```n:``` Number of characters to check.   |
| **Return Value**          | The memchr() and memrchr() functions return a pointer to the matching byte or NULL if the character does not occur in the given memory area.|
| **Description**           | The memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.|

   - [**Memcmp**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_memcmp.c)

| **Function Name**         | ft_memcmp                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```int memcmp(const void *s1, const void *s2, size_t n);```        |
| **Parameters**            | ```*s1:``` First string. <br /> ```*s2:``` Second string. <br /> ```n:``` Number of characters to compare.   |
| **Return Value**          | The memcmp() function returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2. For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2. If n is zero, the return value is zero.|
| **Description**           | The memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.|

   - [**Strlen**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strlen.c)

| **Function Name**         | ft_strlen                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` size_t strlen(const char *s);```        |
| **Parameters**            | ```*s:``` Null-terminated string. |
| **Return Value**          | The strlen() function returns the number of bytes in the string pointed to by s.|
| **Description**           | The strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').|

   - [**Strlcpy**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strlcpy.c)

| **Function Name**         | ft_strlcpy                                                                                                                                                                   |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```size_t strlcpy(char *dst, const char *src, size_t n);```     |
| **Parameters**            | ```*dst:``` Pointer to the string to which the src is to be appended. <br /> ```*src:``` Pointer to source. <br /> ```n:``` Total number of characters to copy. |
| **Return Value**          | The strlcpy() function returns the total length of the string that would have been copied if there was unlimited space. This might or might not be equal to the length of the create string actually, depending on whether there was enough space. This means that you can call strlcpy() once to find out how much space is required, then allocate it if you do not have enough, and finally call strlcpy() a second time to do the required copy.|
| **Description**           | Declared in string.h, the strlcpy() function copies up to size-1 characters from the NUlL-terminated string src to dst.|

   - [**Strlcat**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strlcat.c)

| **Function Name**         | ft_strlcat                                                                                                                                                                   |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char strlcat(char *dst, const char *src, size_t n);```     |
| **Parameters**            | ```*dst:``` Pointer to the string to which the src is to be appended. <br /> ```*src:``` Pointer to source. <br /> ```n:```  Refers to the entire buffer where the string or character sequence is contained. |
| **Return Value**          | The strlcpy() function returns the length of the total string they tried to create.|
| **Description**           |These functions copy and catenate the input string into a destination string. If the destination buffer, limited by its size, isn't large enough to hold the copy, the resulting string is truncated (but it is guaranteed to be null-terminated).  |

   - [**Strchr**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strchr.c)

| **Function Name**         | ft_strchr                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char strchr(const char *s, int c);```     |
| **Parameters**            | ```*s:``` Null-terminated source string <br /> ```c:``` Character to be located. |
| **Return Value**          |The strchr() and strrchr() functions return a pointer to the matched character or NULL if the character is not found. The terminating null byte is considered part of the string, so that if c is specified as '\0', these functions return a pointer to the terminator.|
| **Description**           | The strchr() function returns a pointer to the first occurrence of the character c in the string s.|

   - [**Strrchr**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strrchr.c)

| **Function Name**         | ft_strrchr                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char strrchr(const char *s, int c);```     |
| **Parameters**            | ```*s:``` Null-terminated source string <br /> ```c:``` Character to be located. |
| **Return Value**          |The strchr() and strrchr() functions return a pointer to the matched character or NULL if the character is not found. The terminating null byte is considered part of the string, so that if c is specified as '\0', these functions return a pointer to the terminator.|
| **Description**           | The strrchr() function returns a pointer to the last occurrence of the character c in the string s.|

   - [**Strnstr**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strnstr.c)

| **Function Name**         | ft_strnstr                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char *strnstr(const char *haystack, const char *needle, size_t len);```     |
| **Parameters**            | ```*haystack:``` String where the first occurrence of needle is search. <br /> ```*needle:``` String to be compared. <br /> ```len:``` Number of character to be search. |
| **Return Value**          |If needle is an empty string, haystack is returned; if needle occurs nowhere in haystack, NULL is returned; otherwise a pointer to	the first character of the first occurrence of needle is returned.|
| **Description**           | The strnstr() function finds the first occurrence of the substring needle in the string haystack, where not more than len characters are	searched. The terminating null bytes ('\0') are not compared. |

   - [**Strncmp**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strncmp.c)

| **Function Name**         | ft_strncmp                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int strncmp(const char *s1, const char *s2, size_t n);```     |
| **Parameters**            | ```*s1:``` First string to be compared <br /> ```*s2:``` Second string to be compared. <br /> ```n:``` Maximum umber of character to be compared. |
| **Return Value**          | Upon successful completion, strncmp() shall return an integer greater than, equal to, or less than 0, if the possibly null-terminated array pointed to by s1 is greater than, equal to, or less than the possibly null-terminated array pointed to by s2 respectively.|
| **Description**           |The strncmp() function shall compare not more than n bytes (bytes that follow a NUL character are not compared) from the array pointed to by s1 to the array pointed to by s2.|

   - [**Atoi**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_atoi.c)

| **Function Name**         | ft_atoi                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int atoi(const char *str);```     |
| **Parameters**            | ```*str:``` This is the string representation of an integral number.|
| **Return Value**          | The converted value or 0 on error.|
| **Description**           | The atoi() function converts the initial portion of the string pointed to by str to int.|

   - [**Isalpha**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_isalpha.c)

| **Function Name**         | ft_isalpha                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int isalpha(int c);```     |
| **Parameters**            | ```c:``` Character to be checked.|
| **Return Value**          |The isalpha() function returns non-zero if c is an alphabetic character; otherwise returns 0.|
| **Description**           |The isalpha() function is used to check whether a character is an alphabet or not. The function is defined in the ctype.h header file.|

   - [**Isdigit**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_isdigit.c)

| **Function Name**         | ft_isdigit                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int isdigit(int c);```     |
| **Parameters**            | ```c:``` Character to be checked.|
| **Return Value**          |The isdigit() function returns non-zero if c is a digit; otherwise returns 0.|
| **Description**           |The isdigit() function is used to check whether a character is a digit or not. The function is defined in the ctype.h header file.|

   - [**Isalnum**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_isalnum.c)

| **Function Name**         | ft_isalnum                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int isalnum(int c);```     |
| **Parameters**            | ```c:``` Character to be checked.|
| **Return Value**          |The isdigit() function returns non-zero if c is a alphanumeric character; otherwise returns 0.|
| **Description**           |It checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c))|

   - [**Isascii**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_isascii.c)

| **Function Name**         | ft_isascii                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int isascii(int c);```     |
| **Parameters**            | ```c:``` Character to be checked.|
| **Return Value**          |The isascii() function returns non-zero if c fits into the ASCII character set; otherwise returns 0.|
| **Description**           |The isascii() function is used to check whether a character is a 7-bit unsigned char value that fits into the ASCII character set.|

   - [**Isprint**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_isprint.c)

| **Function Name**         | ft_isprint                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int isdigit(int c);```     |
| **Parameters**            | ```c:``` Character to be checked.|
| **Return Value**          |The isprint() function returns non-zero if c is a printable character; otherwise returns 0.|
| **Description**           |The isprint() functions is used to check for any printable character including space.|

   - [**Toupper**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_toupper.c)

| **Function Name**         | ft_toupper                                                                                                                                                                  |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int toupper(int c);```     |
| **Parameters**            | ```c:``` Character to be checked.|
| **Return Value**          |The toupper() function returns the converted letter, or c if the conversion was not possible.|
| **Description**           |If c is a lowercase letter, toupper() returns its uppercase equivalent, if an uppercase representation exists in the current locale.|

   - [**Tolower**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_tolower.c)

| **Function Name**         | ft_tolower                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` int tolower(int c);```     |
| **Parameters**            | ```c:``` Character to be checked.|
| **Return Value**          |The tolower() function returns the converted letter, or c if the conversion was not possible.|
| **Description**           |If c is a uppercase letter, tolower() returns its lowercase equivalent, if an lowercase representation exists in the current locale.|

   - [**Calloc**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_calloc.c)

| **Function Name**         | ft_calloc                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` void	*calloc(size_t count, size_t size);```     |
| **Parameters**            | ```count:``` This is the number of elements to be allocated. <br /> ```size:``` This is the size of elements.|
| **Return Value**          |  Upon successful completion with both count and size non-zero, calloc() shall return a pointer to the allocated space. If either count or size is 0, then either:* A null pointer shall be returned and errno may be set to an implementation-defined value, or * A pointer to the allocated space shall be returned. The application shall ensure that the pointer is not used to access an object. Otherwise, it shall return a null pointer and set errno to indicate the error.|
| **Description**           | The calloc() function shall allocate unused space for an array of count elements each of whose size in bytes is size. The space shall be initialized to all bits 0.|

   - [**Strdup**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strdup.c)

| **Function Name**         | ft_strdup                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ``` char	*strdup(const char *s1);```     |
| **Parameters**            | ```*s1:``` String to be duplicated.|
| **Return Value**          |  On success, the strdup() function returns a pointer to the duplicated string.  It returns NULL if insufficient memory was available, with errno set to indicate the error.|
| **Description**           | The strdup() function returns a pointer to a new string which is a duplicate of the string s.  Memory for the new string is obtained with malloc(3), and can be freed with free(3).|

<a id="Add_func"></a>
### Additional functions
```
substr, strjoin, strtrim, split, itoa, strmapi,
putchar_fd, putstr_fd, putendl_fd, putnbr_fd
```
   - [**Substr**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_substr.c)

| **Function Name**     | ft_substr                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char *ft_substr(char const *s, unsigned int start, size_t len);```                                                                                                        |
| **Parameters**            | ```s:``` The string from which to create the substring. <br /> ```start:``` The start index of the substring in the string ’s’. <br /> ```len:``` The maximum length of the substring. |
| **Return Value**        | The substring. NULL if the allocation fails.                                                                                                  |
| **Description**           | Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.             |

   - [**Strjoin**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strjoin.c)

| **Function Name**     | ft_strjoin                                                                                                                                                     |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char *ft_strjoin(char const *s1, char const *s2);```                                                                                                        |
| **Parameters**            | ```s1:``` The prefix string. <br /> ```s2:``` The suffix string.                                                                                              |
| **Return Value**        | The new string. <br /> NULL if the allocation fails.                                                                                                        |
| **Description**           | Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.                                             |

   - [**Strtrim**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strtrim.c)

| **Function Name**     | ft_strtrim                                                                                                                                                     |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char *ft_strtrim(char const *s1, char const *s2);```                                                                                                        |
| **Parameters**            | ```s1:``` The string to be trimmed. <br /> ```s2:``` The reference set of characters to trim.                                                     |
| **Return Value**          | The trimmed string.  <br /> NULL if the allocation fails.                                                                                                 |
| **Description**           | Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.             |

   - [**Split**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_split.c)

| **Function Name**     | ft_split                                                                                                                                                     |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char *ft_split(char const *s1, char const *s2);```                                                                                                        |
| **Parameters**            | ```s1:``` The string to be split. <br /> ```s2:``` The delimiter character.                                                                                |
| **Return Value**          | The array of new strings resulting from the split. <br /> NULL if the allocation fails.                                                                  |
| **Description**           | Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.  |

   - [**Itoa**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_itoa.c)

| **Function Name**     | ft_itoa                                                                                                                                                       |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char *ft_itoa(int n);```                                                                                                        |
| **Parameters**            | ```n:``` The integer to convert.                                                                                                                          |
| **Return Value**          | The string representing the integer. <br /> NULL if the allocation fails.                                                                  |
| **Description**           | Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled. |

   - [**Strmapi**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_strmapi.c)

| **Function Name**     | ft_strmapi                                                                                                                                                       |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```char *ft_strmapi(char const *s, char (*f)(unsigned int, char));```                                                                                         |
| **Parameters**            | ```s:``` The string on which to iterate. <br /> ```*f:``` The function to apply to each character.                                                           |
| **Return Value**          | The string created from the successive applications of ’f’. <br /> NULL if the allocation fails.                                                           |
| **Description**           | Applies the function ’f’ to each character of the string ’s’ to create a new string (with malloc(3)) resulting from successive applications of ’f’.           |

   - [**Putchar_fd**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_putchar_fd.c)

| **Function Name**     | ft_putchar_fd                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_putchar_fd(char c, int fd);```                                                                                         |
| **Parameters**            | ```c:``` The character to output. <br /> ```fd:``` The file descriptor on which to write.                                                           |
| **Return Value**          | None                                                           |
| **Description**           | Outputs the character ’c’ to the given file descriptor.           |

   - [**Putstr_fd**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_putstr_fd.c)

| **Function Name**     | ft_putstr_fd                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_putstr_fd(char *s, int fd);```                                                                                         |
| **Parameters**            | ```s:``` The string to output. <br /> ```fd:``` The file descriptor on which to write.                                                           |
| **Return Value**          | None                                                           |
| **Description**           | Outputs the string ’s’ to the given file descriptor.           |

   - [**Putendl_fd**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_putendl_fd.c)

| **Function Name**     | ft_putendl_fd                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_putendl_fd(char *s, int fd);```                                                                                         |
| **Parameters**            | ```s:``` The string to output. <br /> ```fd:``` The file descriptor on which to write.                                                           |
| **Return Value**          | None                                                           |
| **Description**           | Outputs the string ’s’ to the given file descriptor, followed by a newline |

   - [**Putnbr_fd**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_putnbr_fd.c)

| **Function Name**     | ft_putnbr_fd                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_putnbr_fd(int n, int fd);```                                                                                         |
| **Parameters**            | ```n:``` The integer to output. <br /> ```fd:``` The file descriptor on which to write.                                                           |
| **Return Value**          | None                                                           |
| **Description**           | Outputs the integer ’n’ to the given file descriptor.                                                        |

<a id="Bonus"></a>
### Bonus functions
```
lstnew, lstadd_front, lstsize, lstlast,
lstadd_back, lstdelone, lstclear, lstiter, lstmap
```
You’ll use the following structure to represent the elements of your list:
```c
typedef struct    s_list
{
   void          *content;
   struct s_list *next;
}                t_list;

- content : The data contained in the element. The void * allows to store any kind of data.
- next : The next element’s address or NULL if it’s the last element.
```

   - [**Lstnew**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstnew_bonus.c)

| **Function Name**     | ft_lstnew                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```t_list *ft_lstnew(void *content);```                                                                                         |
| **Parameters**            | ```content:``` The content to create the new element with.                                                         |
| **Return Value**          | The new element                                                           |
| **Description**           | Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL. |

   - [**Lstadd_front**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstadd_front_bonus.c)

| **Function Name**     | ft_lstadd_front                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_lstadd_front(t_list **lst, t_list *new);```                                                                                         |
| **Parameters**            | ```**lst:```  The address of a pointer to the first link of a list. <br /> ```*new:``` The address of a pointer to the element to be added to the list.      |
| **Return Value**          | None                                                  |
| **Description**           | Adds the element ’new’ at the beginning of the list. |

   - [**Lstsize**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstsize_bonus.c)

| **Function Name**     | ft_lstsize                                                                                                                                                    |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```int ft_lstsize(t_list *lst);```                                                              |
| **Parameters**            | ```*lst:```  The beginning of the list     |
| **Return Value**          | Length of the list                                                  |
| **Description**           | Counts the number of elements in a list. |

   - [**Lstlast**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstlast_bonus.c)

| **Function Name**     | ft_lstlast                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```t_list *ft_lstlast(t_list *lst);```                                                                                         |
| **Parameters**            | ```*lst:``` The beginning of the list.      |
| **Return Value**          | Last element of the list                                                  |
| **Description**           | Returns the last element of the list. |

   - [**Lstadd_back**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstadd_back_bonus.c)

| **Function Name**     | ft_lstadd_back                                                                                                                                                      |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_lstadd_back(t_list **lst, t_list *new);```                                                                                         |
| **Parameters**            | ```**lst:```  The address of a pointer to the first link of a list. <br /> ```*new:``` The address of a pointer to the element to be added to the list.      |
| **Return Value**          | None                                                  |
| **Description**           | Adds the element ’new’ at the end of the list. |

   - [**Lstdelone**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstdelone_bonus.c)

| **Function Name**     | ft_lstdelone                                                                                                                                                     |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_lstdelone(t_list *lst, void (*del)(void *));```                                                                                         |
| **Parameters**            | ```*lst:```  The element to free. <br /> ```*del:``` The address of the function used to delete the content.      |
| **Return Value**          | None                                                  |
| **Description**           | Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed. |

   - [**Lstclear**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstclear_bonus.c)

| **Function Name**     | ft_lstclear                                                                                                                                                     |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_lstclear(t_list **lst, void (*del)(void *));```                                                                                         |
| **Parameters**            | ```**lst:```  The adress of a pointer to an element. <br /> ```*del:``` The address of the function used to delete the content.      |
| **Return Value**          | None                                                  |
| **Description**           | Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL. |

   - [**Lstiter**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstiter_bonus.c)

| **Function Name**     | ft_lstiter                                                                                                                                                     |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void ft_lstiter(t_list *lst, void (*f)(void *));```                                                                                         |
| **Parameters**            | ```**lst:```  The adress of a pointer to an element. <br /> ```*del:``` The address of the function used to iterate on the list.      |
| **Return Value**          | None                              |
| **Description**           | Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed. |

   - [**Lstmap**](https://github.com/Ancava2000/42Cursus/blob/main/libft/ft_lstmap_bonus.c)

| **Function Name**     | ft_lstmap                                                                                                                                                     |
| ------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));```                                                                                         |
| **Parameters**            | ```*lst:```  The adress of a pointer to an element. <br /> ```*f:``` The address of the function used to iterate on the list. <br /> ```*del:``` The address of the function used to delete the content of an element if needed.      |
| **Return Value**          | The new list. NULL if the allocation fails.                               |
| **Description**           | Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL. |

<a id="Makefile"></a>
## Makefile


<a id="Res"></a>
## Resources

- Lists: 
- Libft tutorial: 
- ...

Thanks for watching my libft project!! <sub>I'll appreciate every comment or message about it 🚀</sub>

![Alt text](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExbHNidHh0cjl3bW9vamhoMmprb2NoemdoY241aWd5dDMzNm5semFkdSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/WfBZwNA6XSjphkYkzN/giphy.gif)
