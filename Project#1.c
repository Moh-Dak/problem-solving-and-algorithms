#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int ReadRoundsNumber(const char *message)
{
    char buffer[64];
    char *end;
    long value;

    while (1)
    {
        printf("%s", message);

        if (fgets(buffer, sizeof buffer, stdin) == NULL)
        {
            exit(EXIT_FAILURE); /* EOF or read error */
        }

        errno = 0;
        value = strtol(buffer, &end, 10);

        if (end == buffer) /* no digits at all */
        {
            printf("Not a number, try again.\n");
        }
        else if (errno == ERANGE) /* overflowed long */
        {
            printf("Number too large, try again.\n");
        }
        else if (*end != '\n' && *end != '\0') /* trailing junk like "5abc" */
        {
            printf("Invalid input, try again.\n");
        }
        else if (value < 1 || value > 10)
        {
            printf("Enter a number between 1 and 10.\n");
        }
        else
        {
            return (int)value;
        }
    }
}