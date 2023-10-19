// exercise : master section single
#include <cstdio>
#include <omp.h>

int main(int argc, char *argv[])
{
// introduce the parallel region with 4 threads
#pragma omp parallel num_threads(4)
    {
        // presence of the threads
        printf("I am thread %d\n", omp_get_thread_num());
// the threads is synchronized
#pragma omp barrier
        // create a sections
#pragma omp sections
        {
// section 1 first task
#pragma omp section
            {printf("Section 1 achieved by proc %d\n", omp_get_thread_num());
    }
// section 2 second task
#pragma omp section
    {
        printf("Section 2 achieved by proc %d\n", omp_get_thread_num());
    }
}
// section 3 third task for the fastest thread
#pragma omp single
{
    printf(" I am the proc %d I am the fastest\n", omp_get_thread_num());
}
// section 4 fourth task for the boss thread
#pragma omp master
{
    printf("I am the master proc %d I am the boss of the procs\n", omp_get_thread_num());
}
}
}