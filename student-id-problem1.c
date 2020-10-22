#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
        pid_t pid;
        pid=fork(); // 현재 부모 프로세스의 PID
        if(pid>0){ // 만약 정상적으로 반환이 되었다면,
                pid=fork();// 자식 프로세스로 한번 들어간 뒤
                printf("Child PID is %d,",getpid()); //자식 프로세서의 PID 정보
                printf("Parent PID is %d\n",getppid()); //부모 프로세서 PID정보
        }
	sleep(3);
	printf("Parent PID is %d",getppid());
}

