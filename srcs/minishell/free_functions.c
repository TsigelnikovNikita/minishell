/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imicah <imicah@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:52:25 by imicah            #+#    #+#             */
/*   Updated: 2020/09/14 18:52:28 by imicah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_double_array(char **array)
{
	char	*temp;
	char	**double_temp;

	double_temp = array;
	while (*array)
	{
		temp = *array;
		array++;
		free(temp);
	}
	free(double_temp);
}

void	free_arguments(void *arguments)
{
	t_arguments *commands;

	commands = (t_arguments*)arguments;
	free_double_array(commands->parameters);
	free(commands);
}

void	free_list(t_list *list)
{
	t_list	*temp_list;

	while (list)
	{
		temp_list = list;
		list = list->next;
		ft_lstdelone(temp_list, &free_arguments);
	}
}
