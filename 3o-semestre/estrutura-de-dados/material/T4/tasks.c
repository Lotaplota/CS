#include <stdio.h>
#include <stdlib.h>

#include "tasks.h"

TaskList * CreateList(int startingCapacity)
{
    TaskList * ptr = malloc(sizeof(Task));
    if (!ptr)
    {
        perror("Error allocating memory for task list");
        free(ptr);
        return NULL;
    }
    
    ptr->data = malloc(startingCapacity * sizeof(Task));
    if (!ptr->data) 
    {
        perror("Error allocating memory for task list data");
        free(ptr->data);
        free(ptr);
        return NULL;
    }
    
    ptr->capacity = startingCapacity;
    ptr->qt_tasks = 0;

    return ptr;
}

void DisplayTitles(TaskList * list)
{
    if (!list) { perror("List pointer null"); return; }

    for (int i = 0; i < list->qt_tasks; i++)
    {
        printf("%i. %s\n", i, list->data[i].title);
    }
}

void DisplayTasks(TaskList * list)
{
    if (list == NULL) { perror("List pointer null"); return; }

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
        sprintf(errMsg, "List already at max capacity (%i tasks)\n", list->qt_tasks);
        perror(errMsg);
        return -1;
    }

    if (!list || !t) {perror("Error adding task: invalid list pointer or task pointer"); return -1;}

    list->data[list->qt_tasks] = *t;
    list->qt_tasks++;

    return list->capacity;
}

int RemoveTask(TaskList * list, int index)
{
    if (index > list->qt_tasks - 1)
    {
        perror("Index out of range");
        return -1;
    }

    int nOfMovingTasks = list->qt_tasks - index -1;

    for (int i = 0; i < nOfMovingTasks; i++) { list->data[i + index] = list->data[i + index + 1]; }
    
    // way better solution below...
    // for (int i = index; i < list->qt_tasks - 1; i++) { list->data[i] = list->data[i + 1]; }

    list->qt_tasks--; // do i have to delete the data of the previous last task?
    return 0;
}

TaskList * DestroyList(TaskList * list)
{
    free(list->data);
    free(list);

    return NULL;
}

int UpdateTaskStatus(TaskList * list, int index, int newStatus)
{
    if (!list) { perror("List pointer null"); return -1; }
    if (index > list->qt_tasks - 1) { perror("Index out of range"); return -1; }
    if (newStatus < TODO || newStatus > DONE) { perror("Invalid status"); return -1; }

    list->data[index].status = newStatus;

    return 0;
}

int UpdateProgress(TaskList * list, int index, float newProgress)
{
    if (!list) { perror("List pointer null"); return -1; }
    if (index > list->qt_tasks - 1) { perror("Index out of range"); return -1; }
    if (newProgress < 0 || newProgress > 1) { perror("Invalid progress"); return -1; }
    
    list->data[index].progress = newProgress;
    
    return 0;
}

int UpdateRating(TaskList * list, int index, int newRating)
{
    if (!list) { perror("List pointer null"); return -1; }
    if (index > list->qt_tasks - 1) { perror("Index out of range"); return -1; }
    if (newRating < 0 || newRating > 5) { perror("Invalid rating"); return -1; }
    
    list->data[index].rating = newRating;
    
    return 0;
}

// TODO:
int CountByStatus(TaskList * list) // DONKEY CONTINUE
{
    if (!list) { perror("List pointer null"); return -1; }

    int TODO_qt = 0;
    int DOING_qt = 0;
    int DONE_qt = 0;
    
    for (int i = 0; i < list->qt_tasks; i++)
    {
        int curStatus = list->data[i].status;

        if (curStatus == TODO)
            TODO_qt++;
        else if (curStatus == DOING)
            DOING_qt++;
        else if (curStatus == DONE)
            DONE_qt++;
        else
        {
            char errMsg[64];
            sprintf(errMsg, "Invalid status at index %i\n", i);
            perror(errMsg);
            return -1;
        }
    }
    
    printf("Your tasklist has %i TODOs, %i DOINGs, and %i DONEs.\n");
    return 0;
}

float RatingAVG(TaskList * list);

