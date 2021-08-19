#include<stdio.h>

int main()
{
    int at[10] = {0}, st[10] = {0}, ft[10] = {0}, tat[10] = {0}, wt[10] = {0};
    float totalTAT, totalWT;
    int sum = 0, n;

    printf("Number of job: ");
    scanf("%d", &n);

    // Arrival time and service time for each job
    for (int i = 0; i < n; i++) 
    {
        printf("Arrival time for job[%d]: ", i + 1);
        scanf("%d", &at[i]);

        printf("Service time for job[%d]: ", i + 1);
        scanf("%d", &st[i]);
        printf("\n");
    }

    // Calculating finish time
    sum += at[0];
    for (int i = 0; i < n; i++)
    {
        ft[i] = sum + st[i];
        sum = ft[i];
    }

    // Calculating waiting time and turn around time
    for (int i = 0; i < n; i++)
    {
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - st[i];

        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("Job\t Arrival time\t Service time\t Finish time\t Turn around time_ft-at\t waiting time_TAT-st\t\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("Job %d \t %d \t\t %d \t\t %d \t\t\t %d \t\t %d \n", i+1, at[i], st[i], ft[i], tat[i], wt[i]);
    }

    printf("total turn around time %d", totalTAT);
    printf("total waiting time %d", totalWT);
}