<p align="center">
  <img width="560" height="200" src="https://github.com/user-attachments/assets/02a15ab1-4a67-45a9-8707-fd52b1cd11b2">
</p>

## Table of Contents 🔖
1. [About](#About)
2. [Functions](#Fun)
   - [PID](#PID)
   - [Signals](#Signals)
   - [Bits](Bits)
3. [Structure](#Struct)
4. [Usage](#Us)
5. [Resources](#Res)
***

<a id="About"></a>
## About 🚀
Minitalk is a project that involves creating a client and a server that send messages to each other via two (Unix) signals: SIGUSR1 and SIGUSR2.
This communication is initiated and maintained via a PID.

```With minitalk you will learn two important concepts for other future projects: UNIX signals and PIDs.```
<a id="Fun"></a>
## Functions 🧾
**External Functions**
| **Function Name**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [**getpid(void);**](https://man7.org/linux/man-pages/man2/getpid.2.html) | getpid() returns the process ID (PID) of the calling process. |
| [**signal(int sig, void(*func));**](https://www.ibm.com/docs/es/i/7.5?topic=functions-signal-handle-interrupt-signals) | The signal() function allows a program to choose one of several ways (like your own function) to handle an interrupt signal from the operating system. |
| [**kill(pid_t pid, int sig);**](https://man7.org/linux/man-pages/man2/kill.2.html) | Signals can also be sent using the kill() function. |
| [**usleep(useconds_t usec);**](https://man7.org/linux/man-pages/man3/usleep.3.html) | The usleep() function suspends execution of the calling thread for (at least) usec microseconds. |
| [**pause(void);**](https://man7.org/linux/man-pages/man2/pause.2.html) |  pause() causes the calling process (or thread) to sleep until a signal is delivered that either terminates the process or causes the invocation of a signal-catching function. |

**Auxiliary Functions**
| **Function Name**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **void	ft_putnbr(long nbr);** | The ft_putnbr() function converts numbers to characters. |
| **int	ft_atoi(const char *str);*** | The ft_atoi() function converts characters to numbers. |

<a id="PID"></a>
### PID
```Every process on the system has a unique process ID number, known as the pid. This is simply an integer. You can get the pid for a process via the getpid system call.```

In this project, we're looking for a client terminal to communicate with a server terminal. To do this, the path that connects them is the server's PID. Later, we'll see how the server obtains its PID so the client can use it in its functions to send signals to the server's single process.
An example C program to get an PID:
```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t pid = getpid();

  printf("pid: %lu\n", pid);
}
```
```c
$ gcc getpid.c -o s && ./s
pid: 7108
```

<a id="Signals"></a>
### Signals
The main concept of Minitalk is signals. Messages are sent and received through signals. Two signals are used for this purpose:
  - ```SIGUSR1:``` This is intended for use by user applications. In my case, this signal represents 0.
  - ```SIGUSR2:``` This is intended for use by user applications. In my case, this signal represents 1.

With the ```signal()``` function, I have the server interpret these two signals, taking as arguments the signal number and the name of the function that interprets them (handle_signal).

On the other hand, with the ```kill()``` function, the client terminal sends one of the two signals to the server, communicating via the PID.

Finally, it's important to highlight the difference between ```usleep()``` and ```pause()```.
  - ```usleep()``` suspends program execution until the specified number of microseconds has elapsed. Therefore, it's a function that requires a specified pause time.
  - ```pause()``` stops executing the program until it receives a signal, without having to specify any time interval.

<a id="Bits"></a>
### Bits
In Minitalk, we're not sending the entire message to the server, but rather it's being sent character by character.
Keep in mind that what is being sent are 0s and 1s, i.e., bits, since each character in ASCII is made up of 8 bits. To transfer bit by bit, you must use operations called bitwise. In this case, two:
- The << (left shift) in C takes two numbers; it shifts the bits of the first operand to the left, and the second operand decides the number of places to shift.
- The >> (right shift) in C takes two numbers; it shifts the bits of the first operand to the right, and the second operand decides the number of places to shift.

For example, the character 'a' is = 01100001. If the operation 'a' << 1 is used:

![VdeosinttuloHechoconClipchamp-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/86da1f96-c261-4fb8-abd9-01d3be645b00)

We can see that the bits are moved one position to the left. Therefore, the first bit is discarded and the second is now the most significant bit. Also the eighth empty space is replaced with a zero. In the case of 'a' = >> 1, the bits are shifted to the right, discarding the previous LSB and replacing the first bit with a 0.

<a id="Struct"></a>
## Structure 🗃️
Project Functions:
| **Function Name**         | Description                                                                                                                                                                 |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **int	main(void)** (server) | Obtains and displays the process's PID after converting it to string with ft_putnbr. Then, it uses the signal function with each signal and handle_signal to interpret the signals. Finally, it uses usleep() to keep the program running until no more signals are received. |
| **int	main(int argc, char **argv)**** (client) | The client converts the PID to a number for use. As long as there is a message, the client sends it to the server using the send_signal function. |
| **void	send_signal(int pid, unsigned char character)** | Each character is iterated bit by bit until i (8) equals 0. If the bit is 0 (temp_char % 2 == 0), it is sent with the kill function SIGUSR1, and if it is 1, SIGUSR2 is sent. After each bit is sent, use sleep to prevent the program from crashing.  |
| **void	handle_signal(int signal)** | In this function, one of two signals is received. If it's SIGUSR1, nb is equal to 0, and if it's SIGUSR2, it's equal to 1. After this, these 0s and 1s are added to the current_char position by position, until it reaches 8. When this happens, the character is written and all variables are reset to zero, starting over with the next character. |

<a id="Us"></a>
## Usage
It's compiled with clang and the flags -Wall -Wextra -Werror. Thanks to the makefile, you only need to enter make + server or client.

First, run the server to obtain the PID.

```c
./server
```
In another terminal, run the client followed by the PID and the message. Once sent, the message should be visible on the server.
```c
./client 1234 "Hello world!"
```

<a id="Res"></a>
## Resources 📹
