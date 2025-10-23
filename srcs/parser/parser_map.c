/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:58:35 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/23 20:06:48 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	store_map(t_ctx *cube, int *mapfd, char *temp)
// {
	

// }

// Store grid
// char	**map;
// 	int		map_height;
	
// 	map = malloc(sizeof(char *) * MAX_LINES)
// 	if (!map)
// 		return (MALLOC_ERROR);
// 	while (temp)
// 	{
// 		if (!ft_strcharset(temp, " 01NSWE\n"))
// 			return (INPUT_ERROR);
// 		map[map_height++] = ft_strdup(temp);
// 		free(temp);
// 		temp = get_next_line(mapfd);
// 	}
// 	map[map_height] = NULL;

// // Nomarlize line lenghts
// int max_len = 0;
// for (int i = 0; i < map_height; i++)
//     if ((int)ft_strlen(map[i]) > max_len)
//         max_len = ft_strlen(map[i]);

// // pad shorter lines with spaces
// for (int i = 0; i < map_height; i++) {
//     int len = ft_strlen(map[i]);
//     if (len < max_len)
//         map[i] = ft_strpad_right(map[i], max_len, ' '); // custom function
// }

// // Player position
// int player_count = 0;
// for (int y = 0; y < map_height; y++) {
//     for (int x = 0; x < max_len; x++) {
//         if (ft_strchr("NSEW", map[y][x])) {
//             cube->player.x = x;
//             cube->player.y = y;
//             cube->player.dir = map[y][x];
//             player_count++;
//         }
//     }
// }
// if (player_count != 1)
//     return (exit_parser(NULL, &mapfd, "Invalid number of players\n", INPUT_ERROR));

// // Validate map
// for (int y = 0; y < map_height; y++) {
//     for (int x = 0; x < max_len; x++) {
//         if (map[y][x] == '0' || ft_strchr("NSEW", map[y][x])) {
//             if (map[y-1][x] == ' ' || map[y+1][x] == ' ' ||
//                 map[y][x-1] == ' ' || map[y][x+1] == ' ')
//                 return (exit_parser(NULL, &mapfd, "Map not closed\n", INPUT_ERROR));
//         }
//     }
// }

