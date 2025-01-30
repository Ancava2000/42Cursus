#include "flood_fill.h"

void fill(char **tab, t_point size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)   // row = begin.y ; col = begin.x
        return ;
    if (tab[row][col] != target || tab[row][col] == 'F')
        return ;
    tab[row][col] = 'F';
    fill(tab, size, target, row -1, col);
    fill(tab, size, target, row +1, col);
    fill(tab, size, target, row, col -1);
    fill(tab, size, target, row, col +1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
    char target = tab[begin.y][begin.x];         // we create a char with the starting tiles (y and x of the char **tab) (begin = {8, 2}, tab[8][2])
    fill(tab, size, target, begin.y, begin.x);    // parameters: the char **, the size of the char **, the starting point, the y and x of the begin point in char **tab)
}


/*
char **tab =
1111111
10X0001
1000001
1111111

size = {4, 7}
begin = {2, 3}
begin.y = 2
begin.x = 3
*/
