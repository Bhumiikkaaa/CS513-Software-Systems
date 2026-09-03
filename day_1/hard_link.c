#include <stdio.h>
#include <unistd.h>
int main()
{
	if(link("hard_link.txt","hard_link_from_c.txt")==-1)
	{
		perror("Link failed");
		return 1;
	}
	printf("Hard link created successfully\n");
	return 0;
}
