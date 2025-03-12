#include "../include/tasks.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *get_status(int status)
{
    switch (status)
    {
        case 0:
            return "TODO";
        case 1:
            return "DOING";
        case 2:
            return "DONE";
        default:
            return "Status inválido";
    }
}

void registre_tasks()
{
    char id_buffer[10];
    FILE *file;
    file = fopen("tasks.txt", "a");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Task task;
    task.description = (char *)malloc(100 * sizeof(char));

    printf("Digite o id da tarefa: ");
    fgets(id_buffer, 10, stdin);
    id_buffer[strcspn(id_buffer, "\n")] = 0;
    task.id = atoi(id_buffer);

    printf("Digite a descrição da tarefa: ");
    fgets(task.description, 100, stdin);
    task.description[strcspn(task.description, "\n")] = 0;

    printf("Digite o status da tarefa (0 - TODO, 1 - DOING, 2 - DONE): ");
    fgets(id_buffer, 10, stdin);
    id_buffer[strcspn(id_buffer, "\n")] = 0;
    task.tasks_status = atoi(id_buffer);
    fprintf(file, "%d;%s;%d\n", task.id, task.description,
            *get_status(task.tasks_status));

    fclose(file);
    free(task.description);
}

void list_tasks()
{
    FILE *file;
    file = fopen("tasks.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Task task;
    task.description = (char *)malloc(100 * sizeof(char));
    char status[10];
    while (fscanf(file, "%d;%[^;];%d\n", &task.id, task.description,
                  &task.tasks_status) != EOF)
    {
        printf("ID: %d\nDescrição: %s\nStatus: %s\n\n", task.id,
               task.description, get_status(task.tasks_status));
    }
    fclose(file);
    free(task.description);
}

void update_tasks()
{
    FILE *file;
    file = fopen("tasks.txt", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    int id;
    char id_buffer[10];
    printf("Digite o id da tarefa que deseja atualizar: ");
    fgets(id_buffer, 10, stdin);
    id_buffer[strcspn(id_buffer, "\n")] = 0;
    id = atoi(id_buffer);

    Task task;
    task.description = (char *)malloc(100 * sizeof(char));
    char status[10];
    while (fscanf(file, "%d;%[^;];%d\n", &task.id, task.description,
                  &task.tasks_status) != EOF)
    {
        if (task.id == id)
        {
            printf("Digite a nova descrição da tarefa: ");
            fgets(task.description, 100, stdin);
            task.description[strcspn(task.description, "\n")] = 0;

            printf("Digite o novo status da tarefa (0 - TODO, 1 - DOING, 2 - "
                   "DONE): ");
            fgets(id_buffer, 10, stdin);
            id_buffer[strcspn(id_buffer, "\n")] = 0;
            task.tasks_status = atoi(id_buffer);
            break;
        }
    }
    fclose(file);
    free(task.description);
}