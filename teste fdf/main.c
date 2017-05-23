#include "libft.h"

int main ()
{
    t_list *first;
    t_list *temp_list;
    int i = 10;

    first = malloc(sizeof(t_list));
    first->next = NULL;
    temp_list = first;
    
    while(i)
    {
        temp_list->next = malloc(sizeof(t_list));
        temp_list->size = i;
        i--;
        temp_list = temp_list->next;
    }
    temp_list->next = NULL;
    temp_list = first;
    while(temp_list != NULL)
    {
        ft_putnbr((int)temp_list->size);
        temp_list = temp_list->next;
    }
    return 1;
}