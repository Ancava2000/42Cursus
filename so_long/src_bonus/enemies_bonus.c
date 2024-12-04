/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarro-v <acarro-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:44:28 by acarro-v          #+#    #+#             */
/*   Updated: 2024/11/19 12:59:17 by acarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void check_player_collision_with_aliens(t_map *map)
{
    t_alien *current_alien = map->aliens; 
    while (current_alien != NULL)
    {

        if (current_alien->instances->x == map -> img -> player -> instances -> x / 64 &&
            current_alien->instances->y == map -> img -> player -> instances -> y / 64)
        {
            map -> img -> player -> instances -> enabled = false;
            map -> c_moves++;
		    ft_moves(map);
			mlx_close_window(map -> mlx);
		    ft_printf(CYAN "OH NO\n"RESET);
        }
        current_alien = current_alien->next;
    }
}
t_alien *create_alien(int x, int y) 
{
    t_alien *new_alien = (t_alien *)malloc(sizeof(t_alien));
    if (!new_alien)
        return NULL; 
    new_alien->instances = (t_instance *)malloc(sizeof(t_instance));
    if (!new_alien->instances)
    {
        free(new_alien);
        return NULL;
    }
    new_alien->instances->x = x;
    new_alien->instances->y = y;
    new_alien->next = NULL;
    return new_alien;
}

void add_alien(t_alien **aliens, int x, int y) 
{
    t_alien *new_alien = create_alien(x, y);
    if (!new_alien) 
        return;
    if (*aliens == NULL)
        *aliens = new_alien;
    else 
    {
        t_alien *current = *aliens;
        while (current->next != NULL) 
            current = current->next;
        current->next = new_alien;
    }
}
int total_alien(t_map *map, t_instance **alien_positions)
{
    int y;
    int x;
    int count;
    int pos_count;

    if (map == NULL || map->array == NULL)
        return 0;
    pos_count = 0;
    y = 0;
    while (map -> array[y]) 
    {
        x = 0;
        while (map->array[y][x]) 
        {
            if (map->array[y][x] == 'A')
            {
                pos_count++;
            }
            x++;
        }
        y++;
    }
    *alien_positions = malloc(sizeof(t_instance) * pos_count);
    if (*alien_positions == NULL)
        return -1;
    y = 0;
    count = 0;
    while (map -> array[y]) 
    { 
        x = 0;
        while (map->array[y][x])
        { 
            if (map->array[y][x] == 'A')
            {
                (*alien_positions)[count].y = y;
                (*alien_positions)[count].x = x;
                count++;
            }
            x++;
        }
        y++;
    }
    return count;
}

void initialize_aliens(t_map *map)  
{
    int i;
    int total;
    t_instance *alien_positions;

    map->aliens = NULL;
    alien_positions = NULL;
    i = 0;
    total = total_alien(map, &alien_positions);
    while (i < total)
    {
        add_alien(&map->aliens, alien_positions[i].x, alien_positions[i].y); 
        i++;
    }
    free(alien_positions);
}

