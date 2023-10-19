// for parallel
#include <cstdio>
#include <omp.h>

int main(int argc, char *argv[])
{
// region parallel begin
#pragma omp parallel num_threads(5)
    {
#pragma omp for
        {
            for (int i = 0; i < 10; i++)
            {
                printf("|task %d achieved by proc %d |\n", i, omp_get_thread_num());
            }
        }
    }

    return 0;
}