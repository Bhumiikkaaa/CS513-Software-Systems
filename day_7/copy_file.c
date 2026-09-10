#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd1, fd2, n;
	char buffer[100];
	fd1 = open("file1", O_RDONLY);
	if(fd1 == -1)
	{
		return 1;
	}
	fd2 = open("file2", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd2 == -1)
	{
		close(fd1);
		return 1;
	}
	while((n = read(fd1, buffer, sizeof(buffer)))>0)
	{
		write(fd2, buffer, n);
	} 
	close(fd1);
	close(fd2);
	return 0;
}
