#include <stdio.h>
#include <unistd.h>
int main()
{
	if(symlink("hard_link.txt", "soft_link_from_c.txt")==-1)
	{
		perror("symlink failed");
		return 1;
	}
	printf("Soft link created successfully!\n");
	return 0;
}
