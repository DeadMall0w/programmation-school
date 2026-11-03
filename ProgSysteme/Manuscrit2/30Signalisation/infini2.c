#include <unistd.h>
#include <stdio.h>

int main() {
	printf("PID = %d\n", getpid());
	alarm(10) ;
	pause();
//	while(1) ;
	printf("Alarme reçue\n");
	return 0;
}
