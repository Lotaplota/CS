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

void DisplayTitles(TaskList * list)
{
    for (int i = 0; i < list->qt_tasks; i++)
    {
        printf("%i. %s\n", i, list->data[i].title);
    }
}

void DisplayTasks(TaskList * list)
{
    for (int i = 0; i < list->qt_tasks; i++)
    {
        printf("Task[%i]\n\tTitle: %s\n\tSubject: %s\n\tStatus: %i\n\tProgress: %f\n\tRating: %i\n",
            i,
            list->data[i].title,
            list->data[i].subject,
            list->data[i].status,
            list->data[i].progress,
            list->data[i].rating);
    }
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

int RemoveTask(TaskList * list, int index)
{
    if (index > list->qt_tasks - 1)
    {
        perror("Index out of range\n");
        return -1;
    }

    int nOfMovingTasks = list->qt_tasks - index -1;

    for (int i = 0; i < nOfMovingTasks; i++) { list->data[i + index] = list->data[i + index + 1]; }

    list->qt_tasks--; // do i have to delete the data of the previous last task?
    return 0;
}

void DestroyList(TaskList * list)
{
    // Free both allocated spaces
}