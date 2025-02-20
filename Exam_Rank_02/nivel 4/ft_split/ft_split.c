#include <stdlib.h>

char		**ft_split(char *str)
{
	int		i;
	int		word;
	int		chars;
	char	**split;

	i = 0;
	chars = 0;
	if (!(split = (char **)malloc(sizeof(char *) * 256))) //numero de palabras
		return (NULL);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') // saltarse espacios del principio
		i++;
	while (str[i])
	{
		chars = 0;
		if (!(split[word] = (char *)malloc(sizeof(char) * 4096))) //numero de caracteres en cada palabra
			return (NULL);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			split[word][chars++] = str[i++]; //se copia los caracteres de la palabra
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') // se saltan espacios hasta llegar a la siguiente palabra
			i++;
		split[word][chars] = '\0'; //se termina la palabra en nulo
		word++; // se pasa a la siguiente palabra
	}
	split[word] = NULL;
	return (split);
}

/*
void print_split(char **split)
{
    int i = 0;
    while (split[i] != NULL)
    {
        printf("Word %d: %s\n", i + 1, split[i]);
        i++;
    }
}

int main()
{
    char str[] = "  Hello World  and hello        42 !!";
    char **result = ft_split(str);
    printf("Split words:\n");
    print_split(result);
    return (0);
}
*/
