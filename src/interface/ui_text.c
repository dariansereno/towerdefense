/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** ui_text
*/

#include "game.h"

const char *nb_in_text(int number)
{
    char *str = malloc(sizeof(char) * 10);
    int increment = 0;

    for (; number > 0; increment++) {
        str[increment] = (number % 10) + 48;
        number /= 10;
    }
    str[increment] = '\0';
    my_revstr(str);
    return (str);
    free(str);
}

// sfVector2f text_position(st_global *global)
// {

// }

void ui_text_bars(st_global *global, sfRenderWindow *window)
{
    // text_position();
    sfText_setString(global->ui->money_text, nb_in_text(1));
    sfText_setString(global->ui->heal_text, nb_in_text(1));
    sfText_setPosition(global->ui->money_text, (sfVector2f){1725, 46});
    sfText_setPosition(global->ui->heal_text, (sfVector2f){1725, 125});
    sfText_setFont(global->ui->money_text, global->ui->font);
    sfText_setFont(global->ui->heal_text, global->ui->font);
    sfText_setCharacterSize(global->ui->money_text, 26);
    sfText_setCharacterSize(global->ui->heal_text, 26);
    sfText_setColor(global->ui->money_text, sfWhite);
    sfText_setColor(global->ui->heal_text, sfWhite);
    sfText_setOutlineColor(global->ui->money_text, sfBlack);
    sfText_setOutlineColor(global->ui->heal_text, sfBlack);
    sfText_setOutlineThickness(global->ui->money_text, 3);
    sfText_setOutlineThickness(global->ui->heal_text, 3);
    sfRenderWindow_drawText(window, global->ui->money_text, NULL);
    sfRenderWindow_drawText(window, global->ui->heal_text, NULL);
}