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
		return (NULL);
	crsr = files;
	behemoth = (t_lust *)malloc(sizeof(t_lust));
	list = init_ls_node(crsr->name, crsr->name);
	while (crsr->next)
	{
		crsr = crsr->next;
		list = add_node(init_ls_node(crsr->name, crsr->name), list, flags);
	}
	behemoth->list = list;
	behemoth->prev = NULL;
	behemoth->next = NULL;
	clean_cont(files);
	return (behemoth);
}

t_lust	*init_directories(t_cont *directories, t_lust *behemoth, int *flags)
{
	t_cont	*crsr;
	t_ls	*list;
	t_lust	*temp;

	if (!(directories))
		return (behemoth);
	crsr = directories;
	while (crsr)
	{
		temp = (t_lust *)malloc(sizeof(t_lust));
		temp->next = NULL;
		temp->prev = NULL;
		list = init_list(crsr->name, flags);
		temp->list = list;
		behemoth = add_dir(temp, behemoth);
		temp = NULL;
		crsr = crsr->next;
	}
	clean_cont(directories);
	return (behemoth);
}

t_lust	*init(int *flags, t_cont *files, t_cont *directories, t_lust *behemoth)
{
	behemoth = init_files(files, behemoth, flags);
	behemoth = init_directories(directories, behemoth, flags);
	if (!(behemoth))
	{
		behemoth = (t_lust *)malloc(sizeof(t_lust));
		behemoth->list = init_cwd(flags);
		behemoth->prev = NULL;
		behemoth->next = NULL;
		return (behemoth);
	}
	return (behemoth);
}