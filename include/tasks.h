#ifndef TASKS_H
#define TASKS_H

typedef union
{
    int TODO;
    int DOING;
    int DONE;
} tasks_status;

typedef struct
{
    int id;
    char *description;
    int tasks_status;
} Task;

const char *get_status(int status);
void registre_tasks();
void list_tasks();
void update_tasks();
void delete_tasks();
#endif