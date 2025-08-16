#include <stdio.h>
#include <string.h>
#include <windows.h>

// Unit of time, in milliseconds
int timeUnit = 1000;

typedef struct {
    int uptime;
    int downtime;
    int counter;
    BOOL isOn;
} Timer;

Timer pedestrians[] = {
    {6, 54, 6, TRUE},
    {42, 18, 6, TRUE},
    {42, 18, 24, TRUE},
    {42, 18, 42, TRUE}
};

Timer transits[] = {
    {18, 42, 6, FALSE},
    {18, 42, 24, FALSE},
    {18, 42, 42, FALSE}
};

int pCount = sizeof(pedestrians) / sizeof(pedestrians[0]);
int tCount = sizeof(transits) / sizeof(transits[0]);

void updateTimers(Timer[], int, Timer[], int);
void alter(BOOL);

int main (void) {
    printf("Program started\n");

    while (TRUE) {
        Sleep(6 * timeUnit);
        updateTimers(pedestrians, pCount, transits, tCount);
    }
}

void updateTimers(Timer p[], int pCount, Timer t[], int tCount) {
    for (int i = 0; i < pCount; i++) {
        p[i].counter -= 6;

        // Switches the signal's state if the counter has reached 0
        // Adds the signal's time values to the signal's counter
        if (p[i].counter == 0) {
            alter(p[i].isOn);

            // Prints the change made
            if (p[i].isOn) {
                printf("Turned P%i on\n", i);
            } else {
                printf("Turned P%i off\n", i);
            }
            printf("Changed P%i's state\n", i); // DONKEY
            
            // Adding time to the counter
            // Will add the signal's uptime if the signal turned on, and the downtime if turned off
            if (p[i].isOn) {
                p[i].counter = p[i].uptime;
                printf("Added %is of uptime to P%i's counter.", p[i].uptime, i); // DONKEY
            } else {
                p[i].counter = p[i].downtime;
                printf("Added %is of downtime to P%i's counter.", p[i].downtime, i); // DONKEY
            }
        }

    }

    // Does the same thing as above, but to the transits
    // Too lazy to create a function and messing with pointers :p
    for (int i = 0; i < tCount; i++) {
        t[i].counter -= 6;

        if (t[i].counter == 0) {
            alter(t[i].isOn);

            // Prints the change made
            if (p[i].isOn) {
                printf("Turned P%i on\n", i);
            } else {
                printf("Turned P%i off\n", i);
            }
            printf("Changed T%i's state\n", i); // DONKEY
            
            if (t[i].isOn) {
                t[i].counter = t[i].uptime;
                printf("Added %is of uptime to T%i's counter.", t[i].uptime, i); // DONKEY
            } else {
                t[i].counter = t[i].downtime;
                printf("Added %is of downtime to T%i's counter.", t[i].downtime, i); // DONKEY
            }
        }
    }
}

void alter(BOOL status) {
    if (status) {
        status = FALSE;
    } else {
        status = TRUE;
    }
}