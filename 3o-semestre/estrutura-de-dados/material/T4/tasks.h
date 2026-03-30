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
    int task_qt;
    int capacity;
} TaskList ;

TaskList * CreateList(int startingCapacity);
void DestroyList(TaskList * list);
int AddTask(TaskList * list, Task * t);
int RemoveTask(TaskList * list, int index);
Task * GetTask(TaskList * list, int index);
int UpdateTaskStatus(TaskList * list, int index, int NovoStatus);
int UpdateProgress(TaskList * list, int index, float NovoProgresso);
int UpdateRating(TaskList * list, int index, int NovaAvaliacao);
int CountByStatus(const TaskList * list, int Status);
float RatingAVG(const TaskList * list);
char * StatusText(int Status);
void PrintList(const TaskList * list);