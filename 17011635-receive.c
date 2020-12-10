#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sighandler(int signo, siginfo_t *si)
{
    if(si->si_code == SI_QUEUE) //si_code가 SI_QUEUE 인지를 확인
    {			
        printf("User RTS signal %d\n", si->si_pid);
        printf("Sig  Number %d\n",     si->si_signo);
        printf("User Data is %d\n",    si->si_value.sival_int);
        // 시그널이 큐잉되는지 확인
        getchar();
    }
}

int main()
{
    struct sigaction sigact;
    printf("My pid %d\n", getpid());
    // 시그널 핸들러를 등록
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags     = SA_SIGINFO;
    sigact.sa_restorer  = NULL; 
    sigact.sa_sigaction = sighandler; 
    //RTS시그널에 대한 핸들러를 설치 
    if (sigaction(SIGRTMIN, &sigact, 0) == 1)
    {
        printf("signal error\n");
        exit(0);
    }   
    while(1)
    {
        sleep(1);
    }   
}
