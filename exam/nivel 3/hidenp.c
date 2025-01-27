#include <unistd.h>

int main(int argc, char **argv)
{
  int i = 0;
  int j = 0;
  
  if (argc == 3)
  {
    while (argv[2][j] != '\0')
    {
      if (argv[2][j] == argv[1][i])
        i++;
      if (argv[1][i] == '\0')
      {
        write (1, "1", 1);
        return (0);
      }
      j++;
    }
    write (1, "0", 1);
  }
  write (1, "\n", 1);
  return (0);
}
