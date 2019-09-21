#include "tinker.h"

int         print_node(ls **node)
{
    if (!(*node->name))
    {
        perror("name");
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
        perror("list");
        return (-1);
    }
    temp = *list;
    while (temp)
    {
        if (!(print_node(temp)))
            return (0);
        temp = temp->left;
        return (1);
    }
}

int         print_rev(ls **list)
{
    ls      *temp;

    if (!(*list))
    {
        perror("list");
        return (-1);
    }
    temp = *list;
    while (temp->left)
        temp = temp->left;
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

}

int         print_long(ls **list)
{

}