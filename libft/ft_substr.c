/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gouz <gouz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:07:54 by nmorandi          #+#    #+#             */
/*   Updated: 2023/01/25 05:48:47 by gouz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	long unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (NULL);
	while (i < len && s[start + i] != '\0')
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
