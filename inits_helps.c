/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_helps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnkambul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:10:01 by lnkambul          #+#    #+#             */
/*   Updated: 2020/02/11 08:33:08 by lnkambul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tinker.h"

t_lust	*init_files(t_cont *files, t_lust *behemoth, int *flags)
{
	t_cont	*crsr;
	t_ls	*list;

	if (!(files))
		return (behemoth);
	crsr = files;
	behemoth = (t_lust *)malloc(sizeof(t_lust));
	list = init_ls_node(crsr->name, crsr->name, 0);
	while (crsr->next)
	{
		crsr = crsr->next;
		list = add_node(init_ls_node(crsr->name, crsr->name, 0), list, flags);
	}
	behemoth->list = list;
	behemoth->prev = NULL;
	behemoth->next = NULL;
	files = clean_cont(files);
	return (behemoth);
}

t_lust	*init_directories(t_cont *directories, t_lust *behemoth, int *flags)
{
	t_cont	*crsr;
	t_lust	*temp;

	if (!(directories))
		return (behemoth);
	crsr = directories;
	if (!(behemoth))
	{
		behemoth = (t_lust *)malloc(sizeof(t_lust));
		behemoth->list = init_list(crsr->name, flags);
		behemoth->next = NULL;
		behemoth->prev = NULL;
	}
	while (crsr->next)
	{
		crsr = crsr->next;
		temp = (t_lust *)malloc(sizeof(t_lust));
		temp->list = init_list(crsr->name, flags);
		temp->prev = NULL;
		temp->next = NULL;
		behemoth = add_dir(temp, behemoth);
		temp = NULL;
	}
	directories = clean_cont(directories);
	return (behemoth);
}

void	init(int *flags, t_cont *files, t_cont *directories, t_lust *behemoth)
{
	t_lust	*crsr;

	behemoth = init_files(files, behemoth, flags);
	behemoth = init_directories(sort_dirs(directories), behemoth, flags);
	if (!(behemoth))
	{
		behemoth = (t_lust *)malloc(sizeof(t_lust));
		behemoth->list = init_cwd(flags);
		behemoth->prev = NULL;
		behemoth->next = NULL;
		print(behemoth->list, flags);
		behemoth = clean(behemoth);
	}
	else
	{
		crsr = behemoth;
		while (crsr)
		{
			if (crsr->prev)
				ft_putchar('\n');
			print(crsr->list, flags);
			crsr = crsr->next;
		}
		behemoth = clean(behemoth);
	}
}
