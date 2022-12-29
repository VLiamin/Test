#include <stdio.h>
#include <string.h> // Для strlen
#include <bits/types/time_t.h>
#include <time.h>

int compare(char*, char*);

int strcmpNew(const char* s1, const char* s2)
{
    while (*s1 != '\0' && (*s1 == *s2))
        s1++, s2++;
   // return *(const unsigned char*)s1 - *(const unsigned char*)s2;
    return *s1 - *s2;
}

#define N 80
int main(void)
{
    FILE *file;
    char arr[11][N];

    time_t start, end;

    file = fopen("/home/test/CLionProjects/test1/Ids", "r");
    int i = 0;
    while (fgets(arr[i], N, file) != NULL) {
        printf("%s", arr[i]);
        i++;
    }

    int f = 0;

    start = clock();

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                 f = strcmp(arr[j], arr[k]);
            }
        }
    }

    end = clock();
    printf("strcmp использовал %f.\n", difftime(end, start));


    start = clock();

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                f = compare(arr[j], arr[k]);
            }
        }
    }

    end = clock();
    printf("Compare использовал %f.\n", difftime(end, start));


    start = clock();

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                f = strcmpNew(arr[j], arr[k]);
            }
        }
    }

    end = clock();
    printf("strcmpNew использовал %f.\n", difftime(end, start));


    return 0;
}

