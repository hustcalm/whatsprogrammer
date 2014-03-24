#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main()
{
    struct rlimit rl;
    getrlimit(RLIMIT_CPU, &rl);

    rl.rlim_cur = 1;
    setrlimit(RLIMIT_CPU, &rl);

    while(1);

    return 0;
}
