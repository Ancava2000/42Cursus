#include "flood_fill.h"

void fill(char **tab, t_point size, char target, int row, int col)
{
    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
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
    char target = tab[begin.y][begin.x];
    fill(tab, size, target, begin.y, begin.x);
}
