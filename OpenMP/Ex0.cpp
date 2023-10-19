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
#pragma omp parallel
    {
        // set thread id
        int id = omp_get_thread_num();
        // print thread id
        printf("|Hello from thread : %d |\n", id);
    }
    // parallel region end
    return 0;
}