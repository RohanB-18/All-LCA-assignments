#include <stdio.h>

int main() {
    int year, m, d, i, start;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char *names[12] = {"January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December"};

    printf("Enter the year: ");
    scanf("%d", &year);

  
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        days[1] = 29;

    
    i = year - 1;
    start = (1 + i * 365 + i / 4 - i / 100 + i / 400) % 7;

    for (m = 0; m < 12; m++) {
        printf("\n   %s %d\n", names[m], year);
        printf("Su Mo Tu We Th Fr Sa\n");

        for (i = 0; i < start; i++)
            printf("   ");

        for (d = 1; d <= days[m]; d++) {
            printf("%2d ", d);
            start++;
            if (start == 7) {
                printf("\n");
                start = 0;
            }
        }
        printf("\n");
    }
    return 0;
}