#include "ft_printf.h"

void print_node(t_lst *node)
{
    printf("flags: %s", node->flags);
    printf("%s", "\n");
    printf("%s", "width: ");
    if (node->width)
        printf("%s", node->width);
    printf("%s", "\n");
    printf("%s", "precision: ");
    if (node->precision)
        printf("%s", node->precision);
    printf("%s", "\n");
    printf("length: %s\n", node->length);
    printf("type: %c\n", node->type);
    printf("%s", "\n");
    printf("next pos: %d\n", node->next_pos);
}