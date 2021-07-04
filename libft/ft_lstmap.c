/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 14:02:13 by pdruart       #+#    #+#                 */
/*   Updated: 2020/11/29 11:05:02 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*beginning;

	if (lst == NULL || f == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (NULL);
	beginning = result;
	lst = lst->next;
	while (lst != NULL)
	{
		if (result == NULL)
		{
			ft_lstclear(&beginning, del);
			return (NULL);
		}
		result->next = ft_lstnew(f(lst->content));
		result = result->next;
		lst = lst->next;
	}
	return (beginning);
}
