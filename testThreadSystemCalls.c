#include "types.h"
#include "user.h"
#include "stat.h"

#define NUMOFTHREADS 7

void threadFunction(){
	printf(1, "Thread ID is  %d \n", getThreadID());
	sleep(100);
	exitThread();
}

int main ()
{

    int allThreadstID [NUMOFTHREADS];
    int joinstatus;
    for (int i=0; i< NUMOFTHREADS; i++){
        sleep(5);
        allThreadstID[i] = createThread(&threadFunction, malloc(4096));
    }

        printf(1, "before join\n");
        for (int i = 0; i < NUMOFTHREADS; i++) {
            sleep(70);

            joinstatus = joinThread(allThreadstID[i]);
            if (!joinstatus){
                printf(1, "Thread joined successfully.\n");
            } else{
                printf(1, "Thread joined failed. \n");
            }
        }
        printf(1, "after join \n");
        exit();

    return 0;
}
