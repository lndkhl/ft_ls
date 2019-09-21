#include "tinker.h"

ls          *seek_end(ls **list)
{
   ls       *temp;

   if (!(*list))
   {
       perror("list end-seek");
       return (NULL);
   }
   temp = *list;
   while (temp->next)
       temp = temp->next;
   return(temp);
}
