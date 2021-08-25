#include<stdio.h>

void bubbleSort(int array[], int size, int job[]) 
{
    for (int step = 0; step < size - 1; ++step) 
    {
        for (int i = 0; i < size - step - 1; ++i) 
        {
            if (array[i] > array[i + 1]) 
            {
                // Sorting the service time
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;

                // Interchanging the job Number
                int jobTemp = job[i];
                job[i] = job[i + 1];
                job[i + 1] = jobTemp;
            }
        }
    }
}

int main()
{
    int job[10] = {0}, at[10] = {0}, st[10] = {0}, ft[10] = {0}, tat[10] = {0}, wt[10] = {0}, priority[10] = {0};
    float totalTAT = 0, totalWT  = 0;
    int sum = 0, n;

    printf("Number of Job: ");
    scanf("%d", &n);

    job[n];

    // Scanning Service time and priority time
    for (int i = 0; i < n; i++)
    {
        job[i] = i + 1;

        printf("Service time for job[%d]: " , i + 1);
        scanf("%d", &st[i]);

        printf("Priority for job[%d]: ", i + 1);
        scanf("%d", &priority[i]);

        printf("\n");
    }

    // Sorting the Service Time as random array without index 1
    bubbleSort(st, n, job); // function to sort the service tiem and interchanging the job number

    //Calculating Finish Time
    sum = sum + at[0];
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

    printf("  Job\t Arrival time\t Service time\t Finish time\t Turn around time_ft-at\t waiting time_TAT-st\n\n");
    for(int i = 0; i < n; i++)
    {
        printf("job %d \t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\n", job[i], at[i], st[i], ft[i], tat[i], wt[i]);
    }

    printf("Average turn around time: %.2f\n", totalTAT / n);
    printf("Average waiting time: %.2f\n", totalWT / n);

    return 0;
}