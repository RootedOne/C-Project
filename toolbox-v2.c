 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
 #include <time.h>
 
 #ifdef _WIN32           /* Windows needs _stricmp / _stricmp */
 #   include <string.h>
 #endif
 
 /*--------------------------------------------------  helper */
 /* Flush any leftover characters after scanf() so that the   */
 /* next fgets() / getchar() starts clean.                    */
 static void flush_stdin(void)
 {
     int ch;
     while ((ch = getchar()) != '\n' && ch != EOF) { /* discard */ }
 }
 
 /*===================================================  MODULES */
 
 /* 1. Basic two‑integer calculator --------------------------- */
 static void basic_calculator(void)
 /* Reads two integers and prints +, -, *, / (if b != 0). */
 {
     int a, b;
 
     printf("Enter the first integer : ");
     if (scanf("%d", &a) != 1) { puts("Input error."); return; }
 
     printf("Enter the second integer: ");
     if (scanf("%d", &b) != 1) { puts("Input error."); return; }
 
     printf("\nSum        : %d\n", a + b);
     printf("Difference : %d\n", a - b);
     printf("Product    : %d\n", a * b);
 
     if (b != 0)
         printf("Division   : %.2f\n", (float)a / b);
     else
         puts("Division   : Undefined (divide by zero)");
 
     flush_stdin();
 }
 
 /* 2. Celsius to Fahrenheit converter ------------------------ */
 static void celsius_to_fahrenheit(void)
 /* Simple C → F conversion. */
 {
     double c;
     printf("Enter temperature in Celsius: ");
     if (scanf("%lf", &c) != 1) { puts("Input error."); return; }
 
     printf("\n%.2f C = %.2f F\n", c, c * 9.0 / 5.0 + 32.0);
     flush_stdin();
 }
 
 /* 3. Sum 1..n ------------------------------------------------ */
 static void sum_1_to_n(void)
 /* Adds numbers 1 through n with a loop. */
 {
     long n;
     long long sum = 0;
 
     printf("Enter a positive integer: ");
     if (scanf("%ld", &n) != 1 || n <= 0) { puts("Invalid input."); return; }
 
     for (long i = 1; i <= n; ++i) sum += i;
 
     printf("Sum of numbers 1 to %ld = %lld\n", n, sum);
     flush_stdin();
 }
 
 /* 4. Integer palindrome checker ----------------------------- */
 static void palindrome_checker(void)
 /* Reverses the digits of an integer and compares to original. */
 {
     long long x, rev = 0, orig;
 
     printf("Enter an integer: ");
     if (scanf("%lld", &x) != 1) { puts("Invalid input!"); return; }
     orig = x;
 
     while (x) {
         rev = rev * 10 + x % 10;
         x  /= 10;
     }
     printf("%lld %s a palindrome\n", orig,
            (orig == rev ? "is" : "is NOT"));
     flush_stdin();
 }
 
 /* 5. Sum of digits ------------------------------------------ */
 static void sum_of_digits(void)
 /* Adds decimal digits of (possibly negative) integer. */
 {
     long long n;
     printf("Enter an integer: ");
     if (scanf("%lld", &n) != 1) { puts("Invalid input!"); return; }
 
     n = llabs(n);                /* ignore sign */
     int sum = 0;
     do { sum += n % 10; } while (n /= 10);
 
     printf("Sum of digits = %d\n", sum);
     flush_stdin();
 }
 
 /* 6. Star triangle ------------------------------------------ */
 static void star_triangle(void)
 /* Prints a left‑aligned triangle of '*'. */
 {
     int h;
     printf("Enter the height of the triangle: ");
     if (scanf("%d", &h) != 1 || h <= 0) { puts("Invalid input."); return; }
 
     for (int r = 1; r <= h; ++r) {
         for (int c = 0; c < r; ++c) putchar('*');
         putchar('\n');
     }
     flush_stdin();
 }
 
 /* 7. Multiplication table (1‑10) ----------------------------- */
 static void multiplication_table(void)
 /* Classic 10×10 times table. */
 {
     puts("Multiplication Table (1 to 10)\n");
 
     printf("     ");
     for (int c = 1; c <= 10; ++c) printf("%4d", c);
     putchar('\n');
 
     printf("----");
     for (int c = 1; c <= 10; ++c) printf("----");
     putchar('\n');
 
     for (int r = 1; r <= 10; ++r) {
         printf("%4d|", r);
         for (int c = 1; c <= 10; ++c) printf("%4d", r * c);
         putchar('\n');
     }
 }
 
 /* 8. Perfect number checker --------------------------------- */
 static void perfect_number_checker(void)
 /* Checks if n equals the sum of its proper divisors. */
 {
     long long n;
     printf("Enter a positive integer: ");
     if (scanf("%lld", &n) != 1 || n <= 0) { puts("Invalid input."); return; }
     if (n == 1) { puts("1 is NOT a perfect number."); return; }
 
     long long sum = 1;
     for (long long i = 2; i * i <= n; ++i)
         if (n % i == 0) {
             sum += i;
             long long pair = n / i;
             if (pair != i) sum += pair;
         }
 
     printf("%lld %s a perfect number.\n", n,
            (sum == n ? "IS" : "is NOT"));
     flush_stdin();
 }
 
 /* 9. Compare two strings ------------------------------------ */
 static void compare_strings(void)
 /* Reads two lines and does a case‑sensitive strcmp. */
 {
     char a[1000], b[1000];
     printf("Enter the first string: ");  fgets(a, sizeof a, stdin);
     printf("Enter the second string: "); fgets(b, sizeof b, stdin);
 
     a[strcspn(a, "\n")] = '\0';  /* strip newline */
     b[strcspn(b, "\n")] = '\0';
 
     puts(strcmp(a, b) == 0 ? "Strings are equal"
                            : "Strings are NOT equal");
 }
 
 /* 10. Word palindrome checker ------------------------------- */
 static void word_palindrome_checker(void)
 /* Case‑insensitive palindrome test for a single word. */
 {
     char s[101];
     printf("Enter a word: ");
     if (scanf("%100s", s) != 1) { puts("Input error!"); return; }
 
     size_t l = 0, r = strlen(s) - 1;
     int ok = 1;
     while (l < r)
         if (tolower((unsigned char)s[l++]) !=
             tolower((unsigned char)s[r--])) { ok = 0; break; }
 
     printf("\"%s\" %s a palindrome\n", s, ok ? "is" : "is NOT");
     flush_stdin();
 }
 
 /* 11. Word counter in sentence ------------------------------ */
 static void word_counter(void)
 /* Counts (case‑insensitive) occurrences of a word in a sentence. */
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
 
 /* 12. Factorial -------------------------------------------- */
 static unsigned long long factorial(int n)
 /* Returns n! (0 if n < 0). Overflow not checked. */
 {
     if (n < 0) return 0;
     unsigned long long r = 1;
     for (int i = 2; i <= n; ++i) r *= i;
     return r;
 }
 static void factorial_interactive(void)
 /* Prompts for n and prints n!. */
 {
     int n;
     printf("Enter n: ");
     if (scanf("%d", &n) != 1) { puts("Invalid input!"); return; }
 
     if (n < 0) { puts("Factorial undefined for negatives."); return; }
     printf("%d! = %llu\n", n, factorial(n));
     flush_stdin();
 }
 
 /* 13. Random array sort demo ------------------------------- */
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
 
     srand((unsigned)time(NULL));
     for (int i = 0; i < SIZE; ++i) arr[i] = MIN + rand() % (MAX - MIN + 1);
 
     puts("Unsorted:");
     for (int i = 0; i < SIZE; ++i) printf("%4d", arr[i]);
     putchar('\n');
 
     qsort(arr, SIZE, sizeof arr[0], cmp_int);
 
     puts("Sorted:");
     for (int i = 0; i < SIZE; ++i) printf("%4d", arr[i]);
     putchar('\n');
 }
 
 /* 14. Show text file --------------------------------------- */
 static void show_file_contents(void)
 /* Reads a file path and dumps its contents to stdout. */
 {
     char fname[FILENAME_MAX];
     printf("Enter file path: ");
     if (!fgets(fname, sizeof fname, stdin)) return;
     fname[strcspn(fname, "\n")] = '\0';
 
     FILE *fp = fopen(fname, "r");
     if (!fp) { perror("open"); return; }
 
     int ch;
     while ((ch = fgetc(fp)) != EOF) putchar(ch);
     fclose(fp);
 }
 
 /* 15. Dynamic array & max ---------------------------------- */
 static void dynamic_array_max_demo(void)
 /* Copies sample data into malloc’d array and finds max element. */
 {
     const int sample[] = {34, 12, -9, 56, 2, 89, 3};
     size_t n = sizeof sample / sizeof sample[0];
 
     int *arr = malloc(n * sizeof *arr);
     if (!arr) { perror("malloc"); return; }
     for (size_t i = 0; i < n; ++i) arr[i] = sample[i];
 
     printf("Array: ");
     for (size_t i = 0; i < n; ++i) printf("%d ", arr[i]);
     putchar('\n');
 
     int max = arr[0];
     for (size_t i = 1; i < n; ++i) if (arr[i] > max) max = arr[i];
 
     printf("Largest value: %d\n", max);
     free(arr);
 }
 
 /*===================================================  MENU / MAIN */
 static void print_banner(void)
 /* Intro banner printed once. */
 {
     puts("==============================================");
     puts("                 C Toolbox                    ");
     puts("==============================================");
     puts("Welcome! This program was coded by Ali Khosh, 401655039.");
     puts("I hope it helps you.");
     puts("==============================================");
 }
 static void print_menu(void)
 /* Lists all 15 menu options. */
 {
     puts("\nChoose an option:");
     puts(" 1. Basic two-integer calculator");
     puts(" 2. Celsius to Fahrenheit converter");
     puts(" 3. Sum of numbers 1 to n");
     puts(" 4. Integer palindrome checker");
     puts(" 5. Sum of digits of an integer");
     puts(" 6. Star triangle printer");
     puts(" 7. 1x1..10x10 multiplication table");
     puts(" 8. Perfect-number checker");
     puts(" 9. Compare two strings");
     puts("10. Word palindrome checker");
     puts("11. Word counter in a sentence");
     puts("12. Factorial calculator");
     puts("13. Random array sort demo");
     puts("14. Show a text file's contents");
     puts("15. Dynamic array / max element demo");
     puts(" 0. Exit");
 }
 
 int main(void)
 /* Main loop: banner -> menu -> dispatcher -> repeat. */
 {
     print_banner();
 
     for (;;) {
         print_menu();
         printf("\nEnter choice (0-15): ");
 
         int ch;
         if (scanf("%d", &ch) != 1) {      /* bad input: clear and retry */
             puts("Input error.");
             flush_stdin();
             continue;
         }
         flush_stdin();                    /* remove leftover newline */
 
         if (ch == 0) { puts("Good-bye!"); break; }
         puts("");
 
         switch (ch) {
             case  1: basic_calculator();          break;
             case  2: celsius_to_fahrenheit();     break;
             case  3: sum_1_to_n();                break;
             case  4: palindrome_checker();        break;
             case  5: sum_of_digits();             break;
             case  6: star_triangle();             break;
             case  7: multiplication_table();      break;
             case  8: perfect_number_checker();    break;
             case  9: compare_strings();           break;
             case 10: word_palindrome_checker();   break;
             case 11: word_counter();              break;
             case 12: factorial_interactive();     break;
             case 13: random_sort_demo();          break;
             case 14: show_file_contents();        break;
             case 15: dynamic_array_max_demo();    break;
             default: puts("Invalid option.");     break;
         }
 
         puts("\n--- Press Enter to return to menu ---");
         getchar();    /* wait for user */
     }
     return 0;
 }