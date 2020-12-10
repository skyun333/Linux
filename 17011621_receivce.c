
#include <signal.h>
#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
void rtsig_handler(int signo, siginfo_t* si, void* p)
{
	if (si->si_code == SI_QUEUE)
	{
		printf("Realtime Signal pid=%d\n", si->si_pid);//RTS로 받은 pid를 출력한다.
		printf("Received data=%d\n", si->si_value.sival_int);
	}
	else {
		printf("THIS IS NOT Realtime Signal! %d\n", signo);

	}
	sleep(2);
}

int main(int argc, char* argv[])
{
	struct sigaction sigact;

	printf("pid=%d\n", getpid());//receive하는 이프로그램의 pid를 출력한다. 이 정보를 이용하여 send측에서 데이터를 전송하게 된다.

	
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = rtsig_handler;

	if (sigaction(SIGRTMIN, &sigact, 0) == 1)
	{
		printf("sigaction fail\n");
		exit(0);
	}

	while (1)
		sleep(1);
	return 0;

}
