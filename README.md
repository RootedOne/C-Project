# C Toolbox: A Collection of Small Utilities


<img width="7758" alt="Untitled" src="https://github.com/user-attachments/assets/20046d60-ed95-4ffb-a0b3-ee634bece8f2" />


## Project Overview

This C program is a "toolbox" containing 15 small, useful utilities implemented in C.  It presents a menu-driven interface allowing users to select and execute various functions, including a basic calculator, temperature converter, palindrome checkers, string comparison, and more. The program is designed to demonstrate fundamental C programming concepts, including input/output, data manipulation, loops, conditional statements, and basic algorithms. It's a great example of how to structure a simple interactive program in C.

**Note:** these are 15 selected options from full (50) options list:

*   1.1
*   1.2
*   2.6
*   2.12
*   2.13
*   3.16
*   3.19
*   3.20
*   4.31
*   4.32
*   4.35
*   5.35
*   5.36
*   5.42
*   6.46

## Menu Options

### Option 1: Basic Two-Integer Calculator

*   **Purpose:** This function takes two integer inputs from the user and performs addition, subtraction, multiplication, and division (if the second number is not zero) on them.

*   **Code Snippet:**
    ```c
    static void basic_calculator(void)
    {
        int a, b;

        printf("Enter the first integer : ");
        if (scanf("%d", &a) != 1) { puts("Input error."); return; } // Reads the first integer, exits on invalid input

        printf("Enter the second integer: ");
        if (scanf("%d", &b) != 1) { puts("Input error."); return; } // Reads the second integer, exits on invalid input

        printf("\nSum        : %d\n", a + b);  // Prints the sum of a and b
        printf("Difference : %d\n", a - b);  // Prints the difference of a and b
        printf("Product    : %d\n", a * b);    // Prints the product of a and b

        if (b != 0)
            printf("Division   : %.2f\n", (float)a / b); // Prints the result of a divided by b (as a float)
        else
            puts("Division   : Undefined (divide by zero)"); // Handles the case where b is zero

        flush_stdin(); // Clears the input buffer.
    }
    ```
*   **Execution Flow:**
    1.  The program prompts the user to enter the first integer.
    2.  `scanf` attempts to read the integer. If the input is invalid (not an integer), an error message is printed, and the function returns.
    3.  The program prompts the user to enter the second integer.
    4.  `scanf` attempts to read the integer. If the input is invalid, an error message is printed, and the function returns.
    5.  The program calculates and prints the sum, difference, and product of the two integers.
    6.  The program checks if the second integer is zero. If not, it calculates and prints the result of dividing the first integer by the second integer. If the second integer is zero, an "Undefined" message is printed.
    7.  `flush_stdin()` is called to clear any remaining characters from the input buffer.

*   **Data Structures/Algorithms:**  Simple integer variables and basic arithmetic operations.

### Option 2: Celsius to Fahrenheit Converter

*   **Purpose:** Converts a temperature from Celsius to Fahrenheit.

*   **Code Snippet:**
    ```c
    static void celsius_to_fahrenheit(void)
    {
        double c;
        printf("Enter temperature in Celsius: ");
        if (scanf("%lf", &c) != 1) { puts("Input error."); return; }  // Reads Celsius temperature, exits on invalid input

        printf("\n%.2f C = %.2f F\n", c, c * 9.0 / 5.0 + 32.0); // Performs conversion and prints result
        flush_stdin(); // Clears the input buffer.
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter a temperature in Celsius.
    2.  `scanf` attempts to read the temperature as a `double`. If the input is invalid, an error message is printed, and the function returns.
    3.  The program converts the Celsius temperature to Fahrenheit using the formula: `F = C * 9/5 + 32`.
    4.  The program prints the Celsius and Fahrenheit temperatures, formatted to two decimal places.
    5.  `flush_stdin()` is called.

*   **Data Structures/Algorithms:** `double` variable for storing temperature, basic arithmetic.

### Option 3: Sum of Numbers 1 to n

*   **Purpose:** Calculates the sum of all integers from 1 to a user-specified positive integer n.

*   **Code Snippet:**
    ```c
    static void sum_1_to_n(void)
    {
        long n;
        long long sum = 0;

        printf("Enter a positive integer: ");
        if (scanf("%ld", &n) != 1 || n <= 0) { puts("Invalid input."); return; } // Reads the integer, exits if invalid (not a positive integer)

        for (long i = 1; i <= n; ++i) sum += i; // Iterates from 1 to n, adding each number to the sum.

        printf("Sum of numbers 1 to %ld = %lld\n", n, sum); // Prints the result
        flush_stdin(); // Clears input buffer.
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter a positive integer.
    2.  `scanf` attempts to read the integer as a `long`. If the input is invalid (not an integer or less than or equal to 0), an error message is printed, and the function returns.
    3.  A `for` loop iterates from 1 to `n`, adding each number to the `sum` variable.
    4.  The program prints the value of `n` and the calculated `sum`.
    5.  `flush_stdin()` is called.

*   **Data Structures/Algorithms:** `long` for input `n`, `long long` for accumulating the `sum`, iterative addition.

### Option 4: Integer Palindrome Checker

*   **Purpose:** Checks if a given integer is a palindrome (reads the same forwards and backward).

*   **Code Snippet:**
    ```c
    static void palindrome_checker(void)
    {
        long long x, rev = 0, orig;

        printf("Enter an integer: ");
        if (scanf("%lld", &x) != 1) { puts("Invalid input!"); return; } // Reads the integer, exits on invalid input.
        orig = x; // Stores the original value for comparison

        while (x) {
            rev = rev * 10 + x % 10; // Reverses the digits of the number
            x  /= 10;
        }
        printf("%lld %s a palindrome\n", orig,
               (orig == rev ? "is" : "is NOT")); // Checks if the reversed number equals the original number, printing the corresponding result
        flush_stdin(); // Clears input buffer.
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter an integer.
    2.  `scanf` attempts to read the integer as a `long long`. If the input is invalid, an error message is printed, and the function returns.
    3.  The original value of the integer is stored in the `orig` variable.
    4.  A `while` loop reverses the digits of the integer.  In each iteration:
        *   The last digit of `x` is extracted using the modulo operator (`% 10`).
        *   This digit is added to the `rev` variable, effectively building the reversed number.
        *   `x` is divided by 10 to remove the last digit.
    5.  The program compares the original integer (`orig`) to the reversed integer (`rev`).
    6.  The program prints whether the integer is a palindrome or not.
    7.  `flush_stdin()` is called.

*   **Data Structures/Algorithms:** `long long` for the integer and its reversed representation, digit manipulation using modulo and division.

### Option 5: Sum of Digits

*   **Purpose:** Calculates the sum of the digits of a given integer (positive or negative).

*   **Code Snippet:**
    ```c
    static void sum_of_digits(void)
    {
        long long n;
        printf("Enter an integer: ");
        if (scanf("%lld", &n) != 1) { puts("Invalid input!"); return; } // Reads the input

        n = llabs(n);                /* ignore sign */ // Takes absolute value to ignore the sign
        int sum = 0;
        do { sum += n % 10; } while (n /= 10); // Extracts digits until the number is reduced to zero.

        printf("Sum of digits = %d\n", sum); // Outputs the result.
        flush_stdin(); // Clears the buffer.
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter an integer.
    2.  `scanf` attempts to read the integer as a `long long`. If the input is invalid, an error message is printed, and the function returns.
    3.  The absolute value of the integer is taken using `llabs` to handle negative numbers.
    4.  A `do-while` loop extracts and sums the digits of the integer. In each iteration:
        *   The last digit is extracted using the modulo operator (`% 10`).
        *   This digit is added to the `sum` variable.
        *   The integer is divided by 10 to remove the last digit.
    5.  The program prints the sum of the digits.
    6. `flush_stdin()` is called.

*   **Data Structures/Algorithms:** `long long` for the integer, `int` for the sum, digit extraction using modulo and division.

### Option 6: Star Triangle Printer

*   **Purpose:** Prints a left-aligned triangle of asterisks (*) with a height specified by the user.

*   **Code Snippet:**
    ```c
    static void star_triangle(void)
    {
        int h;
        printf("Enter the height of the triangle: ");
        if (scanf("%d", &h) != 1 || h <= 0) { puts("Invalid input."); return; } // Reads height from user

        for (int r = 1; r <= h; ++r) { // Outer loop for rows
            for (int c = 0; c < r; ++c) putchar('*'); // Inner loop prints stars for each row
            putchar('\n'); // Newline character at the end of each row
        }
        flush_stdin(); // Clears the input buffer.
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter the height of the triangle.
    2.  `scanf` attempts to read the height as an `int`. If the input is invalid (not an integer or less than or equal to 0), an error message is printed, and the function returns.
    3.  An outer `for` loop iterates from `r = 1` to `h` (height of the triangle). This loop controls the rows.
    4.  An inner `for` loop iterates from `c = 0` to `r - 1`. This loop prints the asterisks in each row. The number of asterisks in each row is equal to the row number.
    5.  `putchar('*')` prints an asterisk in the inner loop.
    6.  `putchar('\n')` prints a newline character at the end of each row, moving to the next line.
    7. `flush_stdin()` is called.

*   **Data Structures/Algorithms:** `int` for height, nested `for` loops for printing the triangle.

### Option 7: Multiplication Table (1-10)

*   **Purpose:** Prints a multiplication table from 1x1 to 10x10.

*   **Code Snippet:**
    ```c
    static void multiplication_table(void)
    {
        puts("Multiplication Table (1 to 10)\n");

        printf("     ");
        for (int c = 1; c <= 10; ++c) printf("%4d", c); // Prints the header row for the multiplication table (1-10)
        putchar('\n');

        printf("----");
        for (int c = 1; c <= 10; ++c) printf("----"); // Prints the seperator line between header and body
        putchar('\n');

        for (int r = 1; r <= 10; ++r) { // Main loop for rows (1-10)
            printf("%4d|", r); // Prints the row number
            for (int c = 1; c <= 10; ++c) printf("%4d", r * c); // Inner loop for printing values in row.
            putchar('\n');
        }
    }
    ```

*   **Execution Flow:**
    1.  The program prints a header indicating the multiplication table (1 to 10).
    2.  The program prints the header row with numbers from 1 to 10, formatted to occupy 4 spaces.
    3.  The program prints a separator line consisting of hyphens.
    4.  An outer `for` loop iterates from `r = 1` to 10. This loop controls the rows.
    5.  The row number is printed, followed by a vertical bar.
    6.  An inner `for` loop iterates from `c = 1` to 10. This loop calculates and prints the product of the row number (`r`) and the column number (`c`), formatted to occupy 4 spaces.
    7.  `putchar('\n')` prints a newline character at the end of each row.

*   **Data Structures/Algorithms:** Nested `for` loops for generating the table, basic multiplication.

### Option 8: Perfect Number Checker

*   **Purpose:** Checks if a given positive integer is a perfect number (a number equal to the sum of its proper divisors, excluding the number itself).

*   **Code Snippet:**
    ```c
    static void perfect_number_checker(void)
    {
        long long n;
        printf("Enter a positive integer: ");
        if (scanf("%lld", &n) != 1 || n <= 0) { puts("Invalid input."); return; } // Reads input from user.
        if (n == 1) { puts("1 is NOT a perfect number."); return; }  // Handles the special case of 1

        long long sum = 1;
        for (long long i = 2; i * i <= n; ++i) // Iterates through possible divisors of n
            if (n % i == 0) { // Checking whether i divides n (i is factor of n)
                sum += i; // adds i into the sum of factors.
                long long pair = n / i;
                if (pair != i) sum += pair; // If there is a pair i*k = n, also add k.
            }

        printf("%lld %s a perfect number.\n", n,
               (sum == n ? "IS" : "is NOT")); // Compares the sum of factors with n.
        flush_stdin(); // Clears the buffer.
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter a positive integer.
    2.  `scanf` attempts to read the integer as a `long long`. If the input is invalid (not an integer or less than or equal to 0), an error message is printed, and the function returns.
    3.  If the number is 1, the program prints that 1 is not a perfect number and returns.
    4.  The `sum` variable is initialized to 1 (since 1 is always a divisor).
    5.  A `for` loop iterates from `i = 2` to the square root of `n`. This is because if `i` is a divisor of `n`, then `n/i` is also a divisor. This optimization avoids checking divisors greater than the square root.
    6.  Inside the loop, it checks if `i` is a divisor of `n` (if `n % i == 0`).
    7.  If `i` is a divisor, it is added to the `sum`.
    8.  The program calculates the "pair" divisor `pair = n / i`. If `pair` is different from `i` (to avoid adding the same divisor twice when `i` is the square root of `n`), then `pair` is also added to the `sum`.
    9.  After the loop, the program compares the `sum` of the divisors to the original number `n`.
    10. The program prints whether the number is a perfect number or not.
    11. `flush_stdin()` is called.

*   **Data Structures/Algorithms:** `long long` for the integer and the sum of divisors, loop with square root optimization.

### Option 9: Compare Two Strings

*   **Purpose:** Compares two strings entered by the user, performing a case-sensitive comparison.

*   **Code Snippet:**
    ```c
    static void compare_strings(void)
    {
        char a[1000], b[1000];
        printf("Enter the first string: ");  fgets(a, sizeof a, stdin); // Read the first string
        printf("Enter the second string: "); fgets(b, sizeof b, stdin); // Read the second string

        a[strcspn(a, "\n")] = '\0';  /* strip newline */ // Remove the trailing newlines
        b[strcspn(b, "\n")] = '\0';

        puts(strcmp(a, b) == 0 ? "Strings are equal"  // Outputs whether the strings are equal
                               : "Strings are NOT equal");
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter the first string.
    2.  `fgets` reads the first string from the standard input into the `a` array.  It reads up to `sizeof a` characters or until a newline character is encountered.
    3.  The program prompts the user to enter the second string.
    4.  `fgets` reads the second string from the standard input into the `b` array.
    5.  The trailing newline character (if present) is removed from both strings using `strcspn` and setting the character at that index to `\0`.
    6.  `strcmp` compares the two strings. If the strings are identical, it returns 0. Otherwise, it returns a non-zero value.
    7.  The program prints "Strings are equal" if `strcmp` returns 0, and "Strings are NOT equal" otherwise.

*   **Data Structures/Algorithms:** Character arrays (`char[]`) to store the strings, `strcmp` function for string comparison.

### Option 10: Word Palindrome Checker

*   **Purpose:** Checks if a single word entered by the user is a palindrome (case-insensitive).

*   **Code Snippet:**
    ```c
    static void word_palindrome_checker(void)
    {
        char s[101];
        printf("Enter a word: ");
        if (scanf("%100s", s) != 1) { puts("Input error!"); return; } // Gets a word as input

        size_t l = 0, r = strlen(s) - 1; // Initializing left and right pointers
        int ok = 1;
        while (l < r) // while left pointer is before the right pointer
            if (tolower((unsigned char)s[l++]) !=
                tolower((unsigned char)s[r--])) { ok = 0; break; } // Comparing characters while ignoring cases.

        printf("\"%s\" %s a palindrome\n", s, ok ? "is" : "is NOT"); // Outputting results
        flush_stdin(); //Clears the input buffer.
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter a word.
    2.  `scanf("%100s", s)` reads the word from the standard input into the `s` array.  The `%100s` format specifier prevents buffer overflows by limiting the number of characters read to 100.
    3.  Two variables, `l` and `r`, are initialized to point to the beginning and end of the string, respectively.
    4.  The `ok` variable is initialized to 1 (true), indicating that the word is initially assumed to be a palindrome.
    5.  A `while` loop continues as long as `l` is less than `r`.
    6.  Inside the loop, the characters at the `l`th and `r`th positions are converted to lowercase using `tolower`. The `(unsigned char)` cast is crucial to avoid issues with character sets where `tolower` might have undefined behavior with signed `char` values.  The lowercase characters are then compared.
    7.  If the characters are not equal, the `ok` variable is set to 0 (false), and the loop is broken using `break`.
    8.  After the loop, the program prints whether the word is a palindrome or not, based on the value of the `ok` variable.
    9.  `flush_stdin()` is called.

*   **Data Structures/Algorithms:** Character array (`char[]`) to store the word, two-pointer approach, case-insensitive comparison using `tolower`.

### Option 11: Word Counter in Sentence

*   **Purpose:** Counts the number of times a specific word appears in a sentence (case-insensitive).

*   **Code Snippet:**
    ```c
    static void word_counter(void)
    {
        char sent[1024], word[128];
        printf("Enter a sentence:\n> ");
        if (!fgets(sent, sizeof sent, stdin)) return;

        printf("Enter the word to search for:\n> ");
        if (!fgets(word, sizeof word, stdin)) return;

        sent[strcspn(sent, "\n")] = '\0';
        word[strcspn(word, "\n")] = '\0';

        char tmp[1024];
        strcpy(tmp, sent);                     /* strtok needs writable copy */

        const char *del = " \t\n\r,.;:!?\"()[]{}<>-";
        int cnt = 0;
        for (char *tok = strtok(tmp, del); tok; tok = strtok(NULL, del))
    #ifdef _WIN32
            if (_stricmp(tok, word) == 0) ++cnt;
    #else
            if (strcasecmp(tok, word) == 0) ++cnt;
    #endif
        printf("The word \"%s\" appears %d time%s.\n",
               word, cnt, cnt == 1 ? "" : "s");
    }
    ```

*   **Execution Flow:**
    1.  The program prompts the user to enter a sentence.
    2.  `fgets` reads the sentence from the standard input into the `sent` array.
    3.  The program prompts the user to enter the word to search for.
    4.  `fgets` reads the word from the standard input into the `word` array.
    5.  The trailing newline character (if present) is removed from both the sentence and the word.
    6.  A copy of the sentence is made into the `tmp` array because `strtok` modifies the string it tokenizes.
    7.  The `strtok` function is used to tokenize the sentence, using delimiters defined in the `del` string (spaces, tabs, newlines, punctuation marks, etc.).
    8.  For each token (word) extracted from the sentence:
        *   The token is compared to the search word using `strcasecmp` (or `_stricmp` on Windows), which performs a case-insensitive comparison.
        *   If the token is equal to the search word, the counter `cnt` is incremented.
    9.  After all tokens have been processed, the program prints the search word and the number of times it appears in the sentence.
    10. `flush_stdin()` is called.

*   **Data Structures/Algorithms:** Character arrays (`char[]`) to store the sentence and the word, `strtok` for tokenizing, `strcasecmp` (or `_stricmp`) for case-insensitive string comparison.

### Option 12: Factorial Calculator

*   **Purpose:** Calculates the factorial of a non-negative integer.

*   **Code Snippet:**
    ```c
    static unsigned long long factorial(int n)
    /* Returns n! (0 if n < 0). Overflow not checked. */
    {
        if (n < 0) return 0; // Factorial undefined for negatives.
        unsigned long long r = 1;
        for (int i = 2; i <= n; ++i) r *= i; // Calculate the factorial
        return r;
    }
    static void factorial_interactive(void)
    /* Prompts for n and prints n!. */
    {
        int n;
        printf("Enter n: ");
        if (scanf("%d", &n) != 1) { puts("Invalid input!"); return; } // Read the number for factorial calculation.

        if (n < 0) { puts("Factorial undefined for negatives."); return; }
        printf("%d! = %llu\n", n, factorial(n)); // outputs the final result
        flush_stdin(); // Clears the input buffer.
    }
    ```

*   **Execution Flow:**
    1.  The `factorial_interactive` function is called.
    2.  The program prompts the user to enter an integer `n`.
    3.  `scanf` attempts to read the integer. If the input is invalid, an error message is printed, and the function returns.
    4.  The program checks if `n` is negative. If it is, an error message is printed, and the function returns.
    5.  The `factorial` function is called to calculate the factorial of `n`.
    6.  Inside the `factorial` function:
        *   If `n` is negative, it returns 0.
        *   It initializes `r` to 1.
        *   A `for` loop iterates from `i = 2` to `n`. In each iteration, `r` is multiplied by `i`.
        *   The function returns the calculated factorial.
    7.  The `factorial_interactive` function prints the value of `n` and its factorial.
    8. `flush_stdin()` is called.

*   **Data Structures/Algorithms:** `int` for input, `unsigned long long` for factorial result, iterative multiplication.  No overflow checking is done, which is a potential issue.

### Option 13: Random Array Sort Demo

*   **Purpose:** Demonstrates sorting an array of random integers using `qsort`.

*   **Code Snippet:**
    ```c
    static int cmp_int(const void *a, const void *b)
    /* qsort comparator for ints. */
    {
        int A = *(const int *)a, B = *(const int *)b;
        return (A > B) - (A < B);
    }
    static void random_sort_demo(void)
    /* Fills an array with random ints, prints before & after qsort. */
    {
        enum { SIZE = 20, MIN = 0, MAX = 999 };
        int arr[SIZE];

        srand((unsigned)time(NULL)); // Initializes the random number generator
        for (int i = 0; i < SIZE; ++i) arr[i] = MIN + rand() % (MAX - MIN + 1); // Fill array with random numbers

        puts("Unsorted:");
        for (int i = 0; i < SIZE; ++i) printf("%4d", arr[i]); // Print the unsorted array
        putchar('\n');

        qsort(arr, SIZE, sizeof arr[0], cmp_int); // Sort the array.

        puts("Sorted:");
        for (int i = 0; i < SIZE; ++i) printf("%4d", arr[i]); // Print the sorted array
        putchar('\n');
    }
    ```

*   **Execution Flow:**
    1.  The `random_sort_demo` function is called.
    2.  An array `arr` of size `SIZE` (20) is declared.
    3.  The random number generator is seeded using `srand((unsigned)time(NULL))`. This ensures that a different sequence of random numbers is generated each time the program is run.
    4.  A `for` loop iterates `SIZE` times, filling the array with random integers between `MIN` (0) and `MAX` (999).
    5.  The unsorted array is printed to the console.
    6.  The `qsort` function is called to sort the array.
        *   The arguments to `qsort` are:
            *   `arr`: The array to be sorted.
            *   `SIZE`: The number of elements in the array.
            *   `sizeof arr[0]`: The size of each element in the array (in bytes).
            *   `cmp_int`: A pointer to the comparison function.
    7.  The `cmp_int` function compares two integers and returns a negative value if `a` is less than `b`, a positive value if `a` is greater than `b`, and 0 if `a` is equal to `b`.  This function is required by `qsort`.
    8.  The sorted array is printed to the console.
    9. `flush_stdin()` is called (although it isn't strictly necessary since this function takes no user input).

*   **Data Structures/Algorithms:** Integer array, `qsort` function for sorting, random number generation.

### Option 14: Show Text File Contents

*   **Purpose:** Displays the contents of a text file specified by the user.

*   **Code Snippet:**
    ```c
    static void show_file_contents(void)
    /* Reads a file path and dumps its contents to stdout. */
    {
        char fname[FILENAME_MAX];
        printf("Enter file path: ");
        if (!fgets(fname, sizeof fname, stdin)) return; // Read the file path.
        fname[strcspn(fname, "\n")] = '\0'; // Removes the newline.

        FILE *fp = fopen(fname, "r"); // Opens the file.
        if (!fp) { perror("open"); return; } // If file doesn't exist, error message.

        int ch;
        while ((ch = fgetc(fp)) != EOF) putchar(ch); // Reads each character and prints it
        fclose(fp); // Close the file.
    }
    ```

*   **Execution Flow:**
    1.  The `show_file_contents` function is called.
    2.  The program prompts the user to enter the file path.
    3.  `fgets` reads the file path from the standard input into the `fname` array.
    4.  The trailing newline character (if present) is removed from the file path.
    5.  `fopen` attempts to open the file in read mode (`"r"`).
    6.  If `fopen` fails to open the file (e.g., the file does not exist or cannot be opened), it returns `NULL`. In this case, `perror("open")` is called to print an error message to the standard error stream, and the function returns.
    7.  If the file is successfully opened, a `while` loop reads characters from the file using `fgetc` until the end of the file (EOF) is reached.
    8.  Each character read from the file is printed to the standard output using `putchar`.
    9.  After all characters have been read, the file is closed using `fclose`.
    10. `flush_stdin()` is called (although it isn't strictly necessary since this function only reads from a file and does not use the `scanf` function)

*   **Data Structures/Algorithms:** Character array to store the file path, `FILE` pointer for file handling, `fopen`, `fgetc`, `putchar`, `fclose` for file operations.

### Option 15: Dynamic Array & Max

*   **Purpose:** Demonstrates dynamic memory allocation and finding the maximum element in an array.

*   **Code Snippet:**
    ```c
    static void dynamic_array_max_demo(void)
    /* Copies sample data into malloc’d array and finds max element. */
    {
        const int sample[] = {34, 12, -9, 56, 2, 89, 3};
        size_t n = sizeof sample / sizeof sample[0];

        int *arr = malloc(n * sizeof *arr); // Allocate memory for the array
        if (!arr) { perror("malloc"); return; }  // If memory allocation fails, error.
        for (size_t i = 0; i < n; ++i) arr[i] = sample[i]; // Copy data into allocated memory

        printf("Array: ");
        for (size_t i = 0; i < n; ++i) printf("%d ", arr[i]); // Output the array
        putchar('\n');

        int max = arr[0];
        for (size_t i = 1; i < n; ++i) if (arr[i] > max) max = arr[i]; // Find the largest element in the array

        printf("Largest value: %d\n", max); // Output the largest element
        free(arr); // Free allocated memory
    }
    ```

*   **Execution Flow:**
    1.  The `dynamic_array_max_demo` function is called.
    2.  A constant integer array `sample` is initialized with sample data.
    3.  The number of elements in the `sample` array is calculated and stored in the `n` variable.
    4.  `malloc` is called to dynamically allocate memory for an integer array of size `n`.  The result is stored in the `arr` pointer.
    5.  If `malloc` fails to allocate memory (e.g., due to insufficient memory), it returns `NULL`. In this case, `perror("malloc")` is called to print an error message to the standard error stream, and the function returns.
    6.  A `for` loop iterates `n` times, copying the elements from the `sample` array to the dynamically allocated `arr` array.
    7.  The contents of the `arr` array are printed to the console.
    8.  The `max
