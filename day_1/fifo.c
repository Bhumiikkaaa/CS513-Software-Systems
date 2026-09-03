#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
	if(mkfifo("myfifo_from_c", 0666)== -1)
	{
		perror("mkfifo failed");
		return 1;
	}
	printf("FIFO created successfully\n");
	return 0;
}

