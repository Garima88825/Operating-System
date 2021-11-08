#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buff[50];
    int n;
    int fd1=open("source.txt",O_RDONLY);
    int fd2=open("target.txt",O_WRONLY||O_CREAT);
    if(fd1 < 0)
	    printf("\nSource File not Opened Successfully.\n");
	
	if(fd2 < 0)
	    printf("\nTarget File not Opened Successfully.\n");
	
	while((n=read(fd1,buff,50))>0)
	{
        write(fd2,buff,n);
    }

	write(fd2,"\0",1);

	if(n < 0)
	    printf("\nFile could not read the content.\n");

	close(fd1);
    close(fd2);
    fd2=open("target.txt",O_RDONLY);
    printf("\nFile 1 has been Copied to File 2 and its Contents are\n");

	while((n=read(fd2,buff,49))>0)
	{
        buff[49]='\0';
        printf(buff);
    }
}










#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char** argv)
{
    char buf[100];
    int sourcefile,destfile;
    if(argc!=3)
    {
        write(STDOUT_FILENO,"\nINSUFFICIENT ARGUMENTS\nEnter <progname> <sourcefile> <destfile>\n\n",100);
        exit(1);
    }
    else
    {
        printf("Opening source file.\n\n");
        sourcefile=open(argv[1],O_RDONLY);
        if(sourcefile==-1)
        {
            perror("Error in opening source file !\n\n");
            exit(0);
        }
        else
        {
            printf("Opening destination file.\n\n");
            destfile=open(argv[2],O_WRONLY|O_CREAT,0641);
            if(destfile==-1)
            {
                perror("Error in opening destination file !\n\n");
                exit(0);
            }
            else
            {
                ssize_t n;
                while((n=read(sourcefile,buf,50)))
                {
                    write(destfile,n);
                }
                printf("Copying Done.\n\n");
                write(STDOUT_FILENO,"File copied.\n\n",20);
                close(sourcefile);
                close(destfile);
            }
        }
    }
    return 0;
}
