// Boolean variables to track user preferences
bool amountIsSet, weightIsSet, marksPerQuestionIsSet;

// Sets all preferences to false initially
SetPreferencesTo(false);

// Variables to store grading related information
int amountOfQuestions = 0; // Defines the quantity of questions that the test has
int marksPerQuestion = 0; // Defines the quantity of marks that each question can get
int[] weights = []; // Array that will store the questions' weights set by the user
int[] earnedMarks = []; // Array that will store the students earned marks in each question
float earnedGrade = 0; // Float that will store the student's calculated grade

// Main loop to prompt the user to set their preferences
while (true)
{
    // Prompts the user to set the amount of questions in the test if not already set
    if (!amountIsSet)
    {
        amountOfQuestions = GetInt("Enter the number of questions you want to grade: ");
        amountIsSet = true;
    }

    // Prompts the user to set the weights for each question if not already set
    if (!weightIsSet)
    {
        weights = GetArray(amountOfQuestions, $"Enter {amountOfQuestions} weights: ");
        weightIsSet = true;
    }

    // Prompts the user to set the amount of earnable marks for each question if not set
    if (!marksPerQuestionIsSet)
    {
        marksPerQuestion = GetInt("How many marks can each question get? ");
        marksPerQuestionIsSet = true;
    }

    // Runs the grading process once the user set all the preferences
    // It can stop if the user chooses to change one of the preferences
    while (amountIsSet && weightIsSet && marksPerQuestionIsSet)
    {
        Run();
    }
}

// Method that runs the main grading program
void Run()
{
    DisplayHeader(); // Clears the console and displays the user's preferences
    earnedMarks = GetArray(amountOfQuestions, "\nNext Marks: "); // Prompts the user to set the current student's marks
    earnedGrade = Grade(weights, earnedMarks); // Calculates and stores the current student's grade
}

// Sets all the boolean preferences to the chosen state (true or false)
void SetPreferencesTo(bool value)
{
    amountIsSet = weightIsSet = marksPerQuestionIsSet = value;
}

// Function that returns the student grade based on the amount of marks earned and the weights of each question
float Grade(int[] weights, int[] marks)
{
    float totalOfPoints = 0; // will store the sum of the student's points (question weight * earned marks) 

    for (int i = 0; i < amountOfQuestions; i++)
    {
        totalOfPoints += weights[i] * marks[i];
    }

    return totalOfPoints / Sum(weights);
}

// Function that prompts the user to enter an array of integers
// In order to be more fluid, this function doesn't require the user to press enter, it will finish once the user enters a digit for each question
int[] GetArray(int amount, string prompt)
{
    Console.WriteLine(prompt);

    int[] integers = new int[amount];

    for (int i = 0; i < amount; i++)
    {
        ConsoleKeyInfo input = Console.ReadKey();

        // Handles specific keys for program control
        if (input.Key == ConsoleKey.Q) // Terminates the program
        {
            Console.WriteLine("\neaster egg");
            Environment.Exit(0);
        }
        if (input.Key == ConsoleKey.W) // Resets weights
        {
            weightIsSet = false;
            Console.WriteLine("\nWeights have been reset");
            break;
        }
        if (input.Key == ConsoleKey.M) // Resets the amount of marks for each question
        {
            marksPerQuestionIsSet = false;
            Console.WriteLine("\nMarks have been reset");
            break;
        }
        if (input.Key == ConsoleKey.R) // Resets the preferences and resets the program
        {
            SetPreferencesTo(false);
            Console.Clear();
            Console.WriteLine("\nAll the preferences have been reset");
            break;
        }

        // Checks if an input is a digit (0-9)
        if (char.IsDigit(input.KeyChar))
        {
            integers[i] = input.KeyChar - '0'; // Inserts the integer into the array at index position
        }
        else
        {
            Console.SetCursorPosition(Console.CursorLeft - 1, Console.CursorTop); // Moves the cursor backwards
            Console.Write(" ");                                                   // deletes the content and replaces it with a blank space
            Console.SetCursorPosition(Console.CursorLeft - 1, Console.CursorTop); // then moves the cursor forwards

            i -= 1; // Retries index expecting adequate input
        }
    }
    Console.WriteLine();

    return integers;
}

// Function that prompts the user to enter an integer
// This one expects the user to press enter
int GetInt(string text)
{
    Console.Write(text);

    string? input = Console.ReadLine();
    if (input == "Q" || input == "q") // Exits the program if the user enters 'Q' or 'q'
    {
        Environment.Exit(0);
        return 0;
    }
    else // Converts the input to an integer and returns it
    {
        return Convert.ToInt32(input);
    }
}

// Function that returns the sum of all the values in an integer array
int Sum(int[] array)
{
    int value = 0;

    for (int i = 0; i < array.Length; i++) // Iterates through the array and sums its integers
    {
        value += array[i];
    }

    return value;
}

// Function that clears the console window and displays the programs current state
void DisplayHeader()
{
    Console.Clear(); // Clears the console window

    // Displays the available commands
    Console.WriteLine("Q: quit    W: reset weights    M: reset marks    R: reset program\n");

    // Displays the program's current weights
    Console.Write("Weights: [ ");
    for (int i = 0; i < weights.Length; i++)
    {
        Console.Write($"{weights[i]} ");
    }
    Console.WriteLine("]");

    // Displays the entered marks
    Console.Write("Marks:   [ ");
    for (int i = 0; i < earnedMarks.Length; i++)
    {
        Console.Write($"{earnedMarks[i]} ");
    }
    Console.WriteLine("]");

    // Displays the student's grade according to their earned marks
    Console.WriteLine("Previous Grade: " + Math.Round(earnedGrade / marksPerQuestion, 2));
}