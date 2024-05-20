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
***
<a id="About"></a>
## About 🚀
```The aim of this project is to code a C library regrouping usual functions that you’ll be allowed to use in all your other projects.```

```C programming can be very tedious when one doesn’t have access to those highly useful standard functions. This project gives you the opportunity to re-write those functions, understand them, and learn to use them. This library will help you for all your future C projects.``` 

In this project, you'll have to learn about memory allocation, malloc anD free functions and how structs work. I recommend doing the bonus part (structs) because you'll use these type of functions in future projects. Lastly, you should add bit by bit every function that you are going to code, so you can create a pretty complete library in C. :comet:GOOD LUCK!:comet:
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
   - [**Memset**]()

| **Function Name**     | ft_memset                                                                                                                                                                    |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**             | ```void *memset(void *dest, int c, size_t n);```                                                                                                        |
| **Parameters**            | ```*dest:``` Pointer to destination. <br /> ```c:``` Character to set. <br /> ```n:``` Number of bytes to be set to the value. |
| **Return Value**        | The memset() function returns a pointer to the memory area s.   |
| **Description**           | The memset() function fills the first n bytes of the memory area pointed to by s with the constant byte c. |

   - [bzero]
   - [memcpy]
   - [memccpy]
   - [memmove]
   - [memchr]
   - [memcmp]
   - [strlen]
   - [strlcpy]
   - [strlcat]
   - [strchr]
   - [strrchr]
   - [strnstr]
   - [strncmp]
   - [atoi]
   - [isalpha]
   - [isdigit]
   - [isalnum]
   - [isascii]
   - [isprint]
   - [toupper]
   - [tolower]
   - [calloc]
   - [strdup]

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

Thanks for watching my libft project!! <sub>I'll appreciate every comment or message about it 🚀</sub>

![Texto alternativo](https://giphy.com/stickers/Mightyhands-mighty-thanks-a-bunch-hands-Z98f0dveCP2nEELmw5)
