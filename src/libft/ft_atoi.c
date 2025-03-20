/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:48:25 by acosi             #+#    #+#             */
/*   Updated: 2023/05/10 09:20:44 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	is_space(const char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f' || c == ' ')
		return (1);
	return (0);
}

static int	get_sign(const char *str)
{
	int	i;
	int	plus;
	int	minus;

	i = 0;
	plus = 0;
	minus = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ') && str[i] != '\0')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			plus++;
		else
			minus++;
		i++;
	}
	if (plus > 1 || minus > 1 || (plus + minus) > 1)
		return (0);
	if (minus == 1)
		return (-1);
	return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (get_sign(str) == 0)
		return (0);
	while (is_space(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (get_sign(str) == -1)
		result = -result;
	return (result);
}
