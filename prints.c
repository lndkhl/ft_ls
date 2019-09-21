#include "tinker.h"

int         print_node(ls **node)
{
    if (!(*node->name))
    {
        perror("print node");
        return (-1);
    }
    ft_putendl(temp->name);
    return (1);
}

int         print_basic(ls **list)
{
    ls      *temp;

    if (!(*list))
    {
        perror("print basic");
        return (-1);
    }
    temp = *list;
    while (temp)
    {
        if (!(print_node(temp)))
            return (0);
        temp = temp->next;
        return (1);
    }
}

int         print_rev(ls **list)
{
    ls      *temp;

    if (!(*list))
    temp = seek_end(list);
    while (temp)
    {
        if (!(print_node(temp)))
            return (0);
        temp = temp->prev;
        return (1);
    }
}

int         print_rec(ls **list)
{
    ls      *temp;
    ls      *crsr;

    if (!(*list))
    {
        perror("list");
        return (-1);
    }
    crsr = *list;
    temp = crsr;
    while (temp)
    {
        print_node(temp);
        if (temp->left)
            temp = temp->left;
    }
    while (crsr)
    {
        if (is_dir(crsr))
            print_rec(crsr);
        crsr = crsr->left;
    }

}

int         print_long(ls **list)
{

}