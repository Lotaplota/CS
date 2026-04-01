#define TITLE_LENGTH 96
#define NAME_LENGTH 48

// Definições de Status
#define TODO 0
#define DOING 1
#define DONE 2

// --- Task structure ---
typedef struct
{
    char title[TITLE_LENGTH];
    char subject[NAME_LENGTH];
    int status;     /* TO_DO, DOING, or DONE */
    float progress; /* 0.0 to 1.0 */
    int rating;     /* 0 to 5 */
} Task;

// --- Task list structure ---
typedef struct
{
    Task * data;
    int capacity;
    int qt_tasks;
} TaskList;

TaskList * CreateList(int);
TaskList * DestroyList(TaskList *);
int AddTask(TaskList *, Task *);
int RemoveTask(TaskList * list, int index);
Task * GetTask(TaskList * list, int index);
int UpdateTaskStatus(TaskList * list, int index, int newStatus);
int UpdateProgress(TaskList *, int, float);
int UpdateRating(TaskList * list, int index, int NovaAvaliacao);
int CountByStatus(TaskList * list);
float RatingAVG(TaskList * list);
char * StatusText(int Status);
void PrintList(TaskList * list);

void DisplayTasks(TaskList *); // DEBUG
void DisplayTitles(TaskList *); // DEBUG