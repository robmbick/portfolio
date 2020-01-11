/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnetschu <bnetschu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:38:15 by okherson          #+#    #+#             */
/*   Updated: 2019/01/30 15:48:41 by bnetschu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_relations(char **matrix, int y, int x)
{
	int		relat;

	relat = 0;
	if (y - 1 >= 0 && matrix[y - 1][x] == '#')
		relat++;
	if (x - 1 >= 0 && matrix[y][x - 1] == '#')
		relat++;
	if (y + 1 < 4 && matrix[y + 1][x] == '#')
		relat++;
	if (x + 1 < 4 && matrix[y][x + 1] == '#')
		relat++;
	return (relat);
}

int			check_grill(char **matrix)
{
	int		r;
	int		k;
	int		grill;
	int		relation;

	k = 0;
	grill = 0;
	relation = 0;
	while (k < 4)
	{
		r = 0;
		while (r < 4)
		{
			if (matrix[k][r] == '#')
			{
				grill++;
				relation = relation + ft_relations(matrix, k, r);
			}
			r++;
		}
		k++;
	}
	if (grill == 4 && (relation == 6 || relation == 8))
		return (1);
	return (0);
}
