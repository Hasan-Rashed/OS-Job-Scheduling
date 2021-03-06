#include<stdio.h>

void bubbleSort(int array[], int size, int job[], int at[]) 
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

                // Interchanging the arrival Time
                int atTemp = at[i + 1];
                at[i + 1] = at[i + 2];
                at[i + 2] = atTemp;

                // Interchanging the job Number
                int jobTemp = job[i + 1];
                job[i + 1] = job[i + 2];
                job[i + 2] = jobTemp;
            }
        }
    }
}

int main()
{
    int job[10] = {0}, at[10] = {0}, st[10] = {0}, ft[10] = {0}, tat[10] = {0}, wt[10] = {0}, ra[10] = {0};
    float totalTAT = 0, totalWT  = 0;
    int sum = 0, n;

    printf("Number of Job: ");
    scanf("%d", &n);

    job[n];

    // Scanning Arrival time and Service time
    for (int i = 0; i < n; i++)
    {
        job[i] = i + 1;

        printf("Arrival time for job[%d]: ", i + 1);
        scanf("%d", &at[i]);

        printf("Service time for job[%d]: " , i + 1);
        scanf("%d", &st[i]);

        printf("\n");
    }

    // Copying Service Time to random array
    for (int i = 0; i < n - 1; i++)
    {
        ra[i] = st[i + 1];
    }

    // Sorting the Service Time as random array without index 1
    bubbleSort(ra, n - 1, job, at); // function to sort the service tiem and interchanging the job number and arrival time

    //Copying random array to service time from index 1
    for (int i = 1; i < n; i++)
    {
        st[i] = ra[i - 1];
    }

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