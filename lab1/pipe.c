#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<errno.h>

int pipe_args(int argc, char *argv[]) {

  int fd[2];
  int idx = 1;
  int err = 0;
  
  for (; idx < argc - 1; idx++) {
    errno = 0;
    err = pipe(fd);
    if (err == -1) {
      perror("error pipe");
      return errno;
    }

    pid_t pid = fork();
    errno = 0;
    if (pid < 0) {
      perror("error fork");
      return errno;
    }
    
    else if (pid == 0) {
      
      close(fd[0]);

      errno = 0;
      err = dup2(fd[1], 1);
      if (err == -1) {
	      perror("error dup2");
	      return errno;
      }
      
      close(fd[1]);
      
      errno = 0;
      err = execlp(argv[idx], argv[idx], (char*)0);
      if (err == -1) {
	      errno = ECHILD;
	      perror("error execlp");
	      return errno;
      }
      
    }
    else {
      close(fd[1]);

      errno = 0;
      err = dup2(fd[0], 0);
      if (err == -1) {
	      perror("error: dup2");
	      return errno;
      }
      close(fd[0]);
                  
      errno = 0;
      err = wait(NULL);
      if (err == -1) {
	      perror("error with wait");
	      return errno;
      }
            
      
    }
  }

  
  errno = 0;
  err = execlp(argv[idx], argv[idx], (char*)0);
  if (err == -1) {
    perror("error : execlp");
    return errno;
  }

    return 0;
}


  
int main(int argc, char *argv[]) {


   int ret;


   errno = 0;
   if (argv[1] == NULL) {
     errno = EINVAL;
     perror("error: requires at least one argument");
     ret = errno;
   }

   else {
     ret = func(argc, argv);
   }
    return ret;
}