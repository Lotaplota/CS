#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"

TaskList * CreateList(int startingCapacity)
{
    TaskList * ptr = malloc(sizeof(Task));
    if (!ptr)
    {
        perror("Error allocating memory for task list.\n");
        free(ptr);
        return NULL;
    }
    
    ptr->data = malloc(startingCapacity * sizeof(Task));
    if (!ptr->data) 
    {
        perror("Error allocating memory for task list data.\n");
        free(ptr->data);
        return NULL;
    }
    
    ptr->capacity = startingCapacity;
    ptr->qt_tasks = 0;

    return ptr;
}

int AddTask(TaskList * list, Task * t)
{
    if (list->capacity == list->qt_tasks)
    {
        char errMsg[32];
        sprintf(errMsg, "List at max capacity (%i tasks)\n", list->qt_tasks);
        perror(errMsg);
        return -1;
    }

    if (!list || !t) {perror("Error adding task: invalid list pointer or task pointer.\n"); return -1;}

    list->data[list->qt_tasks] = *t;
    list->qt_tasks++;

    return list->capacity;
}