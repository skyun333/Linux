#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void sig_int(int signo){
	psignal(signo,"Received Signal :");
}

void sig_tstp(int signo){
	psignal(signo,"Received Signal :");
}

void handler_quit(int signo){
	printf("Good Bye %d\n!",signo);
	exit(0);
}

int main(void){
	int cnt=0;
	struct sigaction sigint;
	struct sigaction sigtstp;
	struct sigaction handlerquit;

	sigemptyset(&sigint.sa_mask);
	sigint.sa_flags=0;
	sigint.sa_handler=sig_int;
	
	sigemptyset(&sigtstp.sa_mask);
	sigtstp.sa_flags=0;
	sigtstp.sa_handler=sig_tstp;
	
	sigemptyset(&handlerquit.sa_mask);
	handlerquit.sa_flags=0;
	handlerquit.sa_handler=handler_quit;

	if(sigaction(SIGTSTP,&sigtstp,NULL)==-1){
		perror("sigaction");
		exit(0);
	}
	
	if(sigaction(SIGQUIT,&handlerquit,NULL)==-1){
		perror("sigaction");
		exit(0);
	}
	
	if(sigaction(SIGINT,&sigint,NULL)==-1){
		perror("sigaction");
		exit(0);
	}

	while(1){
		printf("Waiting for signal to be received! Count : %d\n",cnt);
		sleep(1);
		cnt++;
	}
	return 0;
}
			
