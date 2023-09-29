#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "missing memory arg \n");
        exit(1);
    }
    long long megabytes = atoi(argv[1]);
    long long arr_size = megabytes * 1024 * 1024;  // Calculate array size in bytes
    char *arr = (char *)malloc(arr_size);
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    printf("memory size  %lld bytes\n", arr_size);

    // Touch each byte in the array
    while (1) {
        for (long long i = 0; i < arr_size; i++)
            arr[i] += 1;
    }

    free(arr);
    return 0;
}
