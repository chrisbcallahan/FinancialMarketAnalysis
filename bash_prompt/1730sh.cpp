#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <sys/wait.h> 
#include <sys/types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdlib>
#include <fcntl.h>

using namespace std;

void printhelp() {
  cout << "GNU bash, version 4.1.2(1)-release (x86_64-redhat-linux-gnu) " << endl;
  cout << "These shell commands are defined internally.  Type `help' to see this list. " << endl;
  cout << "Type `help name' to find out more about the function `name'. " << endl;
  cout << "Use `info bash' to find out more about the shell in general. " << endl;
  cout << "Use `man -k' or `info' to find out more about commands not in this list. " << endl;
  cout << "" << endl;
  cout << "cd or cd [directory]" << endl;
  cout << "help or help [exit] or help [cd]" << endl;
  cout << "exit" << endl;                                                                                                                     
} // printhelp

void printhelpcd() {
  cout << "cd: cd [-L|-P] [dir]" << endl;
  cout << "    Change the shell working directory." << endl;
  cout << "" << endl;
  cout << "    Change the current directory to DIR.  The default DIR is the value of the" << endl;
  cout << "    HOME shell variable." << endl;
  cout << "" << endl;
  cout << "    The variable CDPATH defines the search path for the directory containing" << endl;
  cout << "    DIR.  Alternative directory names in CDPATH are separated by a colon (:)." << endl;
  cout << "    A null directory name is the same as the current directory.  If DIR begins" << endl;
  cout << "    with a slash (/), then CDPATH is not used." << endl;
  cout << "" << endl;
  cout << "    If the directory is not found, and the shell option `cdable_vars' is set," << endl;
  cout << "    the word is assumed to be  a variable name.  If that variable has a value," << endl;
  cout << "    its value is used for DIR." << endl;
  cout << "" << endl;
  cout << "    Options:" << endl;
  cout << "      -L  force symbolic links to be followed" << endl;
  cout << "      -P  use the physical directory structure without following symbolic" << endl;
  cout << "      links" << endl;
  cout << "" << endl;
  cout << "    The default is to follow symbolic links, as if `-L' were specified." << endl;
  cout << "" << endl;
  cout << "    Exit Status:" << endl;
  cout << "    Returns 0 if the directory is changed; non-zero otherwise." << endl;
} // printhelp

void printhelpexit() {
  cout << "exit: exit [n]" << endl;
  cout << "    Exit the shell." << endl;
  cout << "" << endl;
  cout << "    Exits the shell with a status of N.  If N is omitted, the exit status" << endl;
  cout << "    is that of the last command executed." << endl;
            
} // printhelp

void printbg() {
  cout << "bg: bg [job_spec ...]" << endl;
  cout << "    Move jobs to the background." << endl;
  cout << endl;    
  cout << "    Place the jobs identified by each JOB_SPEC in the background, as if they" << endl;
  cout << "    had been started with `&'.  If JOB_SPEC is not present, the shell's notion" << endl;
  cout << "    of the current job is used." << endl;
  cout << endl;
  cout << "    Exit Status:" << endl;
  cout << "    Returns success unless job control is not enabled or an error occurs." << endl;          
} // printhelp

void printcd() {
cout << "cd: cd [-L|-P] [dir]" << endl;
cout << "    Change the shell working directory." << endl;
cout << endl;   
cout << "    Change the current directory to DIR.  The default DIR is the value of the" << endl;
cout << "    HOME shell variable." << endl;
cout << endl;    
cout << "    The variable CDPATH defines the search path for the directory containing" << endl;
cout << "    DIR.  Alternative directory names in CDPATH are separated by a colon (:)." << endl;
cout << "   A null directory name is the same as the current directory.  If DIR begins" << endl;
cout << "    with a slash (/), then CDPATH is not used." << endl;
cout << endl;    
cout << "    If the directory is not found, and the shell option `cdable_vars' is set," << endl;
cout << "    the word is assumed to be  a variable name.  If that variable has a value," << endl;
cout << "    its value is used for DIR." << endl;
cout << endl;    
cout << "    Options:" << endl;
cout << "        -L  force symbolic links to be followed" << endl;
cout << "        -P  use the physical directory structure without following symbolic" << endl;
cout << "      links" << endl;
cout << endl;    
cout << "    The default is to follow symbolic links, as if `-L' were specified." << endl;
cout << endl;    
cout << "    Exit Status:" << endl;
cout << "    Returns 0 if the directory is changed; non-zero otherwise." << endl;
} // printhelp

void printexport() {
cout << "export: export [-fn] [name[=value] ...] or export -p" << endl;
cout << "    Set export attribute for shell variables." << endl;
cout << endl;  
cout << "    Marks each NAME for automatic export to the environment of subsequently" << endl;
cout << "    executed commands.  If VALUE is supplied, assign VALUE before exporting." << endl;
cout << endl;
cout << "    Options:" << endl;
cout << "      -f  refer to shell functions" << endl;
cout << "      -n  remove the export property from each NAME" << endl;
cout << "      -p  display a list of all exported variables and functions" << endl;
cout << endl;
cout << "    An argument of `--' disables further option processing." << endl;
cout << endl;
cout << "    Exit Status:" << endl;
cout << "    Returns success unless an invalid option is given or NAME is invalid." << endl;     
} // printhelp

void printfg() {
cout << "fg: fg [job_spec]" << endl;
cout << "    Move job to the foreground." << endl;
cout << endl;
cout << "   Place the job identified by JOB_SPEC in the foreground, making it the" << endl;
cout << "    current job.  If JOB_SPEC is not present, the shell's notion of the" << endl;
cout << "    current job is used." << endl;
cout << endl;
cout << "    Exit Status:" << endl;
cout << "    Status of command placed in foreground, or failure if an error occurs." << endl;
} // printhelp

void printjobs() {
cout << "jobs: jobs [-lnprs] [jobspec ...] or jobs -x command [args]" << endl;
cout << "    Display status of jobs." << endl;
cout << endl;
cout << "    Lists the active jobs.  JOBSPEC restricts output to that job." << endl;
cout << "    Without options, the status of all active jobs is displayed." << endl;
cout << endl;
cout << "    Options:" << endl;
cout << "      -l  lists process IDs in addition to the normal information" << endl;
cout << "      -n  list only processes that have changed status since the last" << endl;
cout << "      notification" << endl;
cout << "      -p  lists process IDs only" << endl;
cout << "      -r  restrict output to running jobs" << endl;
cout << "      -s  restrict output to stopped jobs" << endl;
cout << endl;
cout << "    If -x is supplied, COMMAND is run after all job specifications that" << endl;
cout << "    appear in ARGS have been replaced with the process ID of that job's" << endl;
cout << "    process group leader." << endl;
cout << endl;
cout << "    Exit Status:" << endl;
cout << "    Returns success unless an invalid option is given or an error occurs." << endl;
cout << "    If -x is used, returns the exit status of COMMAND." << endl;
} // printhelp

void printkill() {
cout << "kill: kill [-s sigspec | -n signum | -sigspec] pid | jobspec ... or kill -l [sigspec]" << endl;
cout << "    Send a signal to a job." << endl;
cout << endl;  
cout << "    Send the processes identified by PID or JOBSPEC the signal named by" << endl;
cout << "    SIGSPEC or SIGNUM.  If neither SIGSPEC nor SIGNUM is present, then" << endl;
cout << "    SIGTERM is assumed." << endl;
cout << endl;  
cout << "    Options:" << endl;
cout << "      -s sig  SIG is a signal name" << endl;
cout << "      -n sig  SIG is a signal number" << endl;
cout << "      -l  list the signal names; if arguments follow `-l' they are" << endl;
cout << "      assumed to be signal numbers for which names should be listed" << endl;
cout << endl;  
cout << "    Kill is a shell builtin for two reasons: it allows job IDs to be used" << endl;
cout << "    instead of process IDs, and allows processes to be killed if the limit" << endl;
cout << "    on processes that you can create is reached." << endl;
cout << endl;   
cout << "    Exit Status:" << endl;
cout << "    Returns success unless an invalid option is given or an error occurs." << endl;
} // printhelp


void close_pipe(int pipefd [2]) {
  if (close(pipefd[0]) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  } // if
  if (close(pipefd[1]) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  } // if
} // close_pipe

struct job {
  vector< vector<string> > processes;
  int JID;
  int status;
};

int main(const int argc, const char * argv[]) {
  bool cont = true;
  setvbuf(stdout, NULL, _IONBF, 0);
  string homedir;
  bool home = false;
  string usrarg;
  vector<vector<string>> curjob; 
  
  signal(SIGQUIT, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGCHLD, SIG_IGN);

  while(cont) {
    //Mainly Parsing here 
    char buffer[BUFSIZ];
    bool background = false;
    string input;
    string segment;
    string stdin = "STDIN_FILENO";
    string stdout = "STDOUT_FILENO";
    string stderr = "STDERR_FILENO";
    bool trunc = false;
    int pip = 0;
    int i = 0;
    int pgid;
    vector<string> seglist;
    vector<vector<string>> inputp; 

    //Gets the present working directory and home directory
    int v = 0;
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    string pwd(cwd);
    
    while((v < 4) && (!home)) {
      size_t errFound = pwd.find("/");
      if(v < 3) {
        homedir.append(pwd, 0, errFound+1);
        pwd = pwd.substr(errFound+1);
      }
      else {
        homedir.append(pwd, 0, errFound);
        pwd = pwd.substr(errFound);
      }
      v++;
    }

    if(home) {
      pwd = "";
    }

    //Promtpts user for input & reads input
    cout << "1730sh:~" << pwd << "$ ";

    read(STDIN_FILENO, buffer, 128);

    usrarg = buffer;
    while(buffer[i]!='\0') {
      input += buffer[i];
      i++;
    }

    input = input.substr(0, input.length()-1);

    input[i+1] += '\0';
    istringstream temp(input);
    
    //Put input in a string vector seperated by pipes
    while(getline(temp, segment, '|')) {
      seglist.push_back(segment);
      pip++;
    }

    //Main parsing portion puts entries into a string vector
    for(int x = 0; x < pip; x++) {
      bool iore = false;
      int y = 0;
      bool instr = false;
      vector<string> trow;
      seglist[x].erase(seglist[x].begin(), find_if(seglist[x].begin(), seglist[x].end(), bind1st(not_equal_to<char>(), ' ')));

      istringstream tempsstr(seglist[x]);
      while(getline(tempsstr, segment, ' ')) {

        size_t errfound = segment.find_last_of("\\");
        if(errfound != string::npos) {
        segment.erase(errfound, 1);
        }

        errfound = segment.find("&");
        if(errfound != string::npos) {
          if(x == (pip-1)) {
            background = true;
            break;
          }
          else {
            break;
          }
        }

  // I/O redirection
  if(segment == string("<")) {
    getline(tempsstr, segment, ' ');
    stdin = segment;
    iore = true;
  }
  if(segment == string(">")) {
    getline(tempsstr, segment, ' ');
    stdout = segment;
    trunc = true;
    iore = true;
  }
  if(segment == string(">>")) {
    getline(tempsstr, segment, ' ');
    stdout = segment;
    iore = true;
  }
  if(segment == string("e>")) {
    getline(tempsstr, segment, ' ');
    stderr = segment;
    trunc = true;
    iore = true;
  }
  if(segment == string("e>>")) {
    getline(tempsstr, segment, ' ');
    stderr = segment;
    iore = true;
  }

        errfound = segment.find("\"");
        if(errfound != string::npos) {
          if(segment[errfound-1] != '\\') {
            segment.erase(errfound, errfound+1);
            if(instr == true) {
              trow.push_back(segment);
              instr = false;
            }
            else {
              trow.push_back(segment);
              instr = true;
              y++;
            }
          }
          else {
            segment.erase(errfound-1, errfound);
            trow.push_back(segment);
          }
        }
        else {
          if(instr == true) {
            trow.push_back(segment);
          }
          else {
            if(iore == false) {
            trow.push_back(segment);
            y++;
            }
          }
        } 
      }
      inputp.push_back(trow);
    }

    //Clears the buffer
    memset(&buffer[0], 0, sizeof(buffer));
    cin.clear(); 

    //Creates pipes if needed
    int ** pipefd = new int*[pip];

    for(int e = 0; e < pip; e++) {
      pipefd[e] = new int [2];
      // create pipe
      if (pipe(pipefd[e]) == -1) {
        perror("pipe");
      } // if
    }

    int status = -1000;
    for(uint x = 0; x < curjob.size(); x++) {
      int prgid;
      bool ex = false;
      string temp = curjob[x][0];
      istringstream iss(temp);
      iss >> prgid;
      if(waitpid(prgid, &status, WNOHANG) != 0) {
        cout << prgid << " ";

        /* Make your shell its process group leader */
        if (setpgid (getpid(), getpid()) < 0) {
          perror ("setpgid 1");
          exit (1);
        }
        if(tcsetpgrp(STDIN_FILENO, getpgrp()) == -1) {
          printf("Could not set PGID.n");
         return(EXIT_FAILURE);
        }  

        if(WIFEXITED(status)) {
          cout << "exited (" << WEXITSTATUS(status) << ")";
          ex = true;
        }
        else if(WIFSIGNALED(status)) {
          cout << "error (" << WTERMSIG(status) << ")";
          ex = true;
        }
        else if(WIFSTOPPED(status)) {
          cout << "Stopped";
          curjob[x][1] = "Stopped";
        }
        else if(WIFCONTINUED(status)) {
          cout << "Continued";
          curjob[x][1] = "Running";
        } 
        cout << "    " << curjob[x][2] << endl;
        if(ex) {
          curjob.erase(curjob.begin()+x);
        }
      }
    }  

    //Loop to execute programs seperated by pipes
    for(int x = 0; x < pip; x++) {
      const int arrglen = inputp[x].size(); 
      char** args = new char*[arrglen+1];
      vector<string> lsv(0);
      pid_t pid;
      pid = getpid();
      string argu;
      job currentJob;
      currentJob.processes = inputp;
      
      //Convert from char to string for execvp
      for(int y = 0; y < arrglen; y++) {
        args[y] = new char[100];
        strcpy(args[y], (char*)inputp[x][y].c_str());
        argu += inputp[x][y].c_str();
        argu += " ";
      }

      args[arrglen] = NULL;

      string sec;
      string ex(inputp[0][0]);
      string exx;
      string cd;
      string hlp;
      exx.append(ex, 0, 4);
      cd.append(ex, 0, 2);
      hlp.append(ex, 0, 6);
      string dx;
      string ta;
      string tdarg;


      if(arrglen > 1) {
        dx = inputp[0][1];
        sec.append(dx, 0, 7);
      }
      if(arrglen > 2) {
        ta = inputp[0][2];
        tdarg.append(ta, 0, 7);
      }

      setpgid(getpid(), getpid());
      tcsetpgrp(STDIN_FILENO, getpgrp());

      pid = -1000;
      //Checks to see if a built-in command is used.
      if(((exx == "exit") || (exx == "Exit")) & (x == 0)) {
        if(arrglen == 1) {
          return EXIT_SUCCESS;
        }
        else if(arrglen == 2) {
          istringstream buf(sec);
          int proid;
          buf >> proid;
          return proid;
        }  
      }
      else if((cd == "bg") & (x==0)) {
        if(arrglen < 0) {
          cout << "-bash: jobs: No JID entered." << endl;
        }
        else if(arrglen == 2) {
          istringstream buf(sec);
          int proid;
          buf >> proid;
          kill(proid, SIGCONT); 
          background = true;
        }
      }
      else if((cd == "fg") & (x==0)) {
        if(arrglen < 0) {
          cout << "-bash: jobs: No JID entered." << endl;
        }
        else if(arrglen == 2) {
          istringstream buf(sec);
          int proid;
          buf >> proid;
          kill(proid, SIGCONT);
        }

      }
      else if((cd == "cd") & (x == 0)) {
        if(arrglen == 1) {
          //chdir(homedir.c_str());
          chdir("/home/ugrads/zay");
          home = true;
        }
        else {
          struct stat s; 
          if(stat(args[1], &s) == 0) {
            if(s.st_mode & S_IFDIR) {
              chdir(args[1]);
              home = false;
            }
            else {
              cout << "-bash: cd: " << args[1] << ": Not a directory" << endl;
            }
          }
          else {
            cout << "-bash: cd: " << args[1] << ": No such file or directory" << endl;
          }
          homedir = "";
        }
      }
      else if((exx == "help") & (x == 0)) {
        if(arrglen == 1) {
          printhelp();
        }
        else if(sec == "cd") {
          printhelpcd();
        }
        else if(sec == "exit") {
          printhelpexit();
        }
        else if(sec == "bg") {
          printbg();
        }
        else if(sec == "export") {
          printexport();
        }
        else if(sec == "fg") {
          printfg();
        }
        else if(sec == "help") {
          printhelp();
        }
        else if(sec == "jobs") {
          printjobs();
        }
        else if(sec == "kill") {
          printkill();
        }
      }
      else if((exx == "jobs") & (x == 0)) {
        cout << "JID   " << "STATUS       " << "COMMAND" << endl;
        for(uint x = 0; x < curjob.size(); x++) {
          for(int y = 0; y < 3; y++) {
            cout << curjob[x][y];
            if(y == 0) {
              cout << " ";
            }
            else if(y == 1) {
              cout << "      ";
            }
          }
        }
      }
      else if((exx == "kill") & (x == 0)) {
        if(arrglen == 1) {
          cout << "kill: usage: kill [-s sigspec | -n signum | -sigspec] pid | jobspec ... or kill -l [sigspec]" << endl;
        }
        else if(arrglen == 2) {
          istringstream buf(dx);
          int proid;
          buf >> proid;
          kill(proid, SIGKILL);
        }
        else if(arrglen == 3) {
          istringstream buf(ta);
          int proid;
          buf >> proid;
          if(sec == "SIGHUP") {
            kill(proid, SIGHUP);
          }
          else if(sec == "SIGINT") {
            kill(proid, SIGINT);
          }
          else if(sec == "SIGKILL") {
            kill(proid, SIGKILL);
          }
          else if(sec == "SIGTERM") {
            kill(proid, SIGTERM);
          }
          else if(sec == "SIGSTOP") {
            kill(proid, SIGSTOP);
          }
          else if(sec == "SIGCONT") {
            kill(proid, SIGCONT);
          }
        }
      }
      else if((pid = fork()) < 0){
        cout << "Fork Error" << endl;
        exit(1);
      }
      
      //Checks for child
      if(pid == 0) {
        signal(SIGTSTP, SIG_DFL);  
        signal(SIGQUIT, SIG_DFL);
        signal(SIGTTIN, SIG_DFL);
        signal(SIGTTOU, SIG_IGN);
        signal(SIGINT, SIG_DFL);

        setpgid(0, 0);
        if(background == false) {
        tcsetpgrp(STDIN_FILENO, getpgrp());
        }
  
        int fd;
        //only one process in job
        if((x == 0) & (pip == 1)) {
          
          // I/O redirection for stdin 
          if(stdin != string("STDIN_FILENO")){
            if((fd = open(stdin.c_str(), O_RDONLY)) == -1) {
              perror("open");
            }
            if(dup2(fd, STDIN_FILENO) == -1) {
              perror("dup2");
            }
            close(fd);
          }  
        }
        
        // first process
        if((x == 0) & (pip > 1)) {
          // I/O redirection for stdin 
          if(stdin != string("STDIN_FILENO")) {
            if((fd = open(stdin.c_str(), O_RDONLY)) == -1) {
              perror("open");
            }
            if(dup2(fd, STDIN_FILENO) == -1) {
              perror("dup2");
            }
            close(fd);
          }
          if (dup2(pipefd[0][1], STDOUT_FILENO) == -1) {
            perror("dup2");
          } // if
          close_pipe(pipefd[0]);
        }
          
        // middle processes
        else if((x > 0) & (x!=(pip-1))) {
          if (dup2(pipefd[x-1][0], STDIN_FILENO) == -1) {
            perror("dup2");
          } // if
          if (dup2(pipefd[x][1], STDOUT_FILENO) == -1) {
            perror("dup2");
          } // if
          close_pipe(pipefd[x-1]);
          close_pipe(pipefd[x]);
        }
        
        //last process
        else if((x > 0) & (x==(pip-1))) {
          if (dup2(pipefd[x-1][0], STDIN_FILENO) == -1) {
            perror("dup2");
          } // if
          close_pipe(pipefd[x-1]);
        }
        
        //check if stdout was redirected
        if(stdout != string("STDOUT_FILENO")) {
          if(trunc) {
            if((fd = open(stdout.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1) { 
              perror("open");
            }
          }
          else {
            if((fd = open(stdout.c_str(), O_WRONLY | O_APPEND | O_CREAT, 0777)) == -1) {
              perror("open");
            }
          }
          if(dup2(fd, STDOUT_FILENO) == -1) {
            perror("dup2");
          }
          close(fd);
        }

        //check if stderr was redirected
        if(stderr != string("STDERR_FILENO")) {
          if(trunc) {
            if((fd = open(stderr.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1) { 
              perror("open");
            }
          }
          else {
            if((fd = open(stderr.c_str(), O_WRONLY | O_APPEND | O_CREAT, 0777)) == -1) {
              perror("open");
            }
          }
          if(dup2(fd, STDERR_FILENO) == -1) {
            perror("dup2");
          }
          close(fd);
        }

        if(execvp(args[0], args) == -1) {
          perror("exec");
          cout << "Child args no work" << endl;
          exit(1);
        }
      } else {
          if(pid > 0) {
            //Store PID of first process
            if(x == 0) {
              pgid = pid;
            }
        
            setpgid(pid, pgid);
            signal(SIGTTIN, SIG_IGN);
            tcsetpgrp(STDIN_FILENO, getpgid(pid));
            kill(pid, SIGCONT);

            //Closes the pipe
            if(x > 0) {
              close_pipe(pipefd[x-1]);
            }

            // Waits & then deletes dynamically allocated array
            int status = 0;
            string stat;

            if(background == false) {
      
            waitpid(pid, &status, WUNTRACED);
            cout << pid << " ";

            tcsetpgrp(STDIN_FILENO, getpgrp());
            
            if(WIFEXITED(status)) {
              cout << "exited (" << WEXITSTATUS(status) << ")";
            }
            else if(WIFSIGNALED(status)) {
              cout << "error (" << WTERMSIG(status) << ")";
            }
            else if(WIFSTOPPED(status)) {
              cout << "stopped (" << WSTOPSIG(status) << ")";
              int otemp = pid;
              vector<string> params;
              string spid;
              ostringstream ssc;
              ssc << otemp; 
              spid = ssc.str(); 
              params.push_back(spid); 
              params.push_back("Stopped");
              params.push_back(usrarg);
              curjob.push_back(params);
            }
            cout << "    " << argu << endl;
          }
          else {
           if(waitpid(pid, &status, WNOHANG) == 0) {
              if(x == 0) {
                int otemp = pid;
                vector<string> params;
                string spid;
                ostringstream ssc;
                ssc << otemp; 
                spid = ssc.str(); 
                params.push_back(spid); 
                params.push_back("Running");
                params.push_back(usrarg);
                curjob.push_back(params);
              }
              tcsetpgrp(STDIN_FILENO, getpgrp());
            }
          }
        }  
      }
      
      for(int u = 0; u <= arrglen; u++) {
        delete[] args[u];
      }
      args = NULL;
      delete[] args;
    }
    for(int u = 0; u < pip; u++) {
      delete pipefd[u];
    }
    pipefd = NULL;
    delete[] pipefd;
  } 
  return EXIT_SUCCESS;
}
