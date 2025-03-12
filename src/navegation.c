#include "../include/navegation.h"
#include "../include/colors.h"
#include "../include/tasks.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void navegation()
{
    CLEAR_SCREEN();
    int nav = 0;
    char nav_buffer[10];
    do
    {
        printf(YELLOW "-------MENU-------" RESET "\t\n1 - Create Task"
                      "\t\n2 - List Tasks"
                      "\t\n3 - Update Task"
                      "\t\n4 - Delete Task"
                      "\t\n0 - Exit\n" GREEN
                      "\nDigite a opção desejada: " RESET);
        fgets(nav_buffer, 10, stdin);
        nav_buffer[strcspn(nav_buffer, "\n")] = 0;
        nav = atoi(nav_buffer);

        switch (nav)
        {
            case 1:
                printf("Create Task\n");
                registre_tasks();
                break;
            case 2:
                printf("List Tasks\n");
                list_tasks();
                break;
            case 3:
                printf("Update Task\n");
                break;
            case 4:
                printf("Delete Task\n");
                break;
            default:
                puts("Opção inválida");
                break;
        }

    } while (nav != 0);
    return;
}