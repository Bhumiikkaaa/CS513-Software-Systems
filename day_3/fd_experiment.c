#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd1, fd2, fd3;
	fd1 = creat("file1.txt",0644);
	printf("file1.txt ->FD = %d\n", fd1);
	fd2 = creat("file2.txt", 0644);
	printf("file2.txt -> FD =%d\n", fd2);
	fd3 = creat("file3.txt", 0644);
	printf("file3.txt -> FD = %d\n", fd3);
	close(fd2);
	printf("\nClosed FD %d (file2.txt)\n",fd2);
	int fd4 = creat("file4.txt", 0644);
	printf("file4.txt -> FD = %d\n", fd4);
	close(fd1);
	close(fd3);
	close(fd4);
	return 0;
} 
