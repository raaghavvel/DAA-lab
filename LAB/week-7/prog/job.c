//CH.SC.U4CSE24155
#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int profit;
    int deadline;
};

// Comparator for sorting jobs by profit (descending)
int compare(const void *a, const void *b) {
    struct Job *j1 = (struct Job *)a;
    struct Job *j2 = (struct Job *)b;
    return j2->profit - j1->profit;
}

void main() {
    int n = 14;

    int profits[] = {22, 19, 29, 28, 30, 21, 27, 25, 24, 26, 14, 27, 19, 11};
    int deadlines[] = {3, 3, 8, 6, 7, 5, 10, 4, 6, 12, 13, 2, 14, 1};

    struct Job jobs[14];

    // Initialize jobs
    for(int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        jobs[i].profit = profits[i];
        jobs[i].deadline = deadlines[i];
    }

    // Sort jobs by profit
    qsort(jobs, n, sizeof(struct Job), compare);

    // Find max deadline
    int max_deadline = 0;
    for(int i = 0; i < n; i++) {
        if(jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    int slot[max_deadline + 1];
    int result[max_deadline + 1];

    // Initialize slots
    for(int i = 0; i <= max_deadline; i++)
        slot[i] = 0;

    int total_profit = 0;

    // Job sequencing
    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline; j > 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobs[i].id;
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    // Output result
    printf("Selected Job Sequence:\n");
    for(int i = 1; i <= max_deadline; i++) {
        if(slot[i])
            printf("Job %d ", result[i]);
    }

    printf("\nTotal Profit: %d\n", total_profit);
}