#include "ft_printf.h"

int main(void)
{
    char str[5];
    ft_printf("%13.*s\n", 3, "serebro");
//    printf("%s", "\n");
    printf("%13.*s\n", 3, "serebro");
//    printf("%s\n", align_width("abc", 8, ' ', 'l'));
//    fill_char(5, (char**)(&str));
    return (0);
}