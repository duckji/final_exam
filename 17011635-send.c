#include <signal.h>
#include <stdio.h>
 
int main(int argc, char **argv) //argv[1]은 보내고자 하는 프로세스의 PID
{				//argv[2]는 보내고자 하는 값
    union sigval sv;
    sv.sival_int = atoi(argv[2]);
    sigqueue(atoi(argv[1]), SIGTSTP, sv); //SIGTSTP 신호 전송
}
