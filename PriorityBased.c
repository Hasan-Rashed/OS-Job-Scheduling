#include<stdio.h>

void bubbleSort(int priority[], int n, int job[], int st[])
{
    for (int step = 0; step < n - 1; step++)
    {
        for (int i = 0; i < n - 1 - step; i++)
        {
            if (priority[i] > priority[i + 1])
            {
                // Sorting the priority
                int temp = priority[i];
                priority[i] = priority[i + 1];
                priority[i + 1] = temp;

                // Interchanging the job Number
                int jobTemp = job[i];
                job[i] = job[i + 1];
                job[i + 1] = jobTemp;

                // Interchanging the service time
                int stTemp = st[i];
                st[i] = st[i + 1];
                st[i + 1] = stTemp;
            }  
        }  
    }
}

int main()
{
    int job[10] = {0}, at[10] = {0}, st[10] = {0}, ft[10] = {0}, tat[10] = {0}, wt[10], priority[10] = {0};
    float totalTAT = 0, totalWT  = 0;
    int sum = 0, n;

    printf("Number of Job: ");
    scanf("%d", &n);

    job[n];

    for (int i = 0; i < n; i++)
    {
        job[i] = i + 1;
        
        printf("Service time for job[%d]: ", i + 1);
        scanf("%d", &st[i]);

        printf("Priority tiem for job[%d]: ", i + 1);
        scanf("%d", &priority[i]);

        printf("\n");
    }

    bubbleSort(priority, n, job, st);

    // Calculating the finish time
    for (int i = 0; i < n; i++)
    {
        ft[i] = sum + st[i];
        sum = ft[i];
    }

    // Calculating Turn around time and waiting time
    for (int i = 0; i < n; i++)
    {
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - st[i];

        totalTAT += tat[i];
        totalWT += wt[i];
    }

    printf("  Job\t Arrival time\t Service time\t Finih time\t TurnAroundTime_ft-at\t WaitingTime_tat-st\n");
    for (int i = 0; i < n; i++)
    {
        printf("job %d\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\n", job[i], at[i], st[i], ft[i], tat[i], wt[i]);
    }

    printf("Average turn around time: %.2f\n", totalTAT / n);
    printf("Average waiting time: %.2f\n", totalWT / n);

    return 0;
}