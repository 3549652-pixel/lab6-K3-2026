#include <stdio.h>

int main() {
    int i, j, n, m;
    int r1, r2, c1, c2;
    int minI, minJ, maxI, maxJ;
    int found, sumPoints;
    int b[20][20];
    int points[20][5];
    double a[20][20];
    double temp, minimum, maximum;

    // Завдання 920. Поміняти місцями елементи відносно побічної діагоналі.
    printf("\nЗавдання 920\n");
    printf("Введіть розмір квадратної матриці (1-20): ");
    scanf("%d", &n);
    if (n < 1 || n > 20) return 0;

    printf("Введіть елементи матриці:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i + j < n - 1) {
                temp = a[i][j];
                a[i][j] = a[n - 1 - j][n - 1 - i];
                a[n - 1 - j][n - 1 - i] = temp;
            }
        }
    }

    printf("Матриця після заміни:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%8.2f", a[i][j]);
        }
        printf("\n");
    }

    // Завдання 934. Знайти елементи A[i][j], які дорівнюють i + j.
    printf("\nЗавдання 934\n");
    printf("Введіть кількість рядків і стовпців (до 20): ");
    scanf("%d%d", &n, &m);
    if (n < 1 || n > 20 || m < 1 || m > 20) return 0;

    printf("Введіть елементи матриці за умовою завдання:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    found = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (b[i][j] == (i + 1) + (j + 1)) {
                printf("A[%d][%d] = %d\n", i + 1, j + 1, b[i][j]);
                found = 1;
            }
        }
    }
    if (found == 0) {
        printf("Таких елементів немає.\n");
    }

    // Завдання 960. Сума балів третього спортсмена-п'ятиборця.
    printf("\nЗавдання 960\n");
    printf("Введіть бали 20 спортсменів у 5 видах спорту:\n");
    for (i = 0; i < 20; i++) {
        printf("Спортсмен %d (5 балів): ", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &points[i][j]);
        }
    }

    sumPoints = 0;
    for (j = 0; j < 5; j++) {
        sumPoints += points[2][j];
    }
    printf("Сума балів третього спортсмена: %d\n", sumPoints);

    // Завдання 1004. Поміняти місцями найбільший і найменший елементи.
    printf("\nЗавдання 1004\n");
    printf("Введіть кількість рядків і стовпців (до 20): ");
    scanf("%d%d", &n, &m);
    if (n < 1 || n > 20 || m < 1 || m > 20) return 0;

    printf("Введіть елементи матриці:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    minimum = a[0][0];
    maximum = a[0][0];
    minI = 0;
    minJ = 0;
    maxI = 0;
    maxJ = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (a[i][j] < minimum) {
                minimum = a[i][j];
                minI = i;
                minJ = j;
            }
            if (a[i][j] > maximum) {
                maximum = a[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    temp = a[minI][minJ];
    a[minI][minJ] = a[maxI][maxJ];
    a[maxI][maxJ] = temp;

    printf("Матриця після заміни:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%8.2f", a[i][j]);
        }
        printf("\n");
    }

    // Завдання 955. Сума двох елементів третього стовпця
    // і добуток двох елементів другого рядка.
    printf("\nЗавдання 955\n");
    printf("Введіть кількість рядків (2-20) і стовпців (3-20): ");
    scanf("%d%d", &n, &m);
    if (n < 2 || n > 20 || m < 3 || m > 20) return 0;

    printf("Введіть елементи матриці:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Введіть номери двох різних рядків для третього стовпця: ");
    scanf("%d%d", &r1, &r2);
    if (r1 < 1 || r1 > n || r2 < 1 || r2 > n || r1 == r2) return 0;
    printf("Сума: %.2f\n", a[r1 - 1][2] + a[r2 - 1][2]);

    printf("Введіть номери двох різних стовпців для другого рядка: ");
    scanf("%d%d", &c1, &c2);
    if (c1 < 1 || c1 > m || c2 < 1 || c2 > m || c1 == c2) return 0;
    printf("Добуток: %.2f\n", a[1][c1 - 1] * a[1][c2 - 1]);

    return 0;
}

