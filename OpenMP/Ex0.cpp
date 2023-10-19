// library supported by OpenMP library
#include <cstdio>
// OpenMP library
#include <omp.h>
using namespace std;
// main function
int main(int argc, char *argv[])
{
    // set number of threads
    omp_set_num_threads(6);
    // parallel region begin
#pragma omp parallel num_threads(3)
    {
        int id = omp_get_thread_num();
        printf("|all threads : %d |Hello World from thread %d\n",
               omp_get_num_threads(), id);
    }
    // parallel region end
    printf("***********************************************************\n");
    // parallel region begin
#pragma omp parallel
    {
        // set thread id
        int id = omp_get_thread_num();
        // print thread id
        printf("|all threads : %d |Hello World from thread %d\n", omp_get_num_threads(), id);
    }
    // parallel region end
    return 0;
}