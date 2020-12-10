

#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char **argv){
	pid_t pid;
	int i=0;
	union sigval sval;
	for(i=0;i<10;i++){//눈으로 확인하기 위해 for문으로 돌려준다.
	
		sval.sival_int =17011621;//해당 union구조체의 보낼 데이터를 학번으로 설정한다.
		sigqueue(atoi(argv[1]),SIGRTMIN,sval);
	}
}


