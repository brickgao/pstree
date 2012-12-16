//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

int main() {
	int n;
    pid_t my_pid, ch_pid, fa_pid;
	freopen("list.txt", "w", stdout);
	cin >> n;
    for(int i = 0; i < n; i ++){
        ch_pid = fork();
        if(ch_pid == -1){
	   		 exit(1);
		}
        else{
      	    my_pid = getpid();
			fa_pid = getppid();
		   	cout << " " << fa_pid << " " << my_pid << endl;	
            wait(0); 
        }
    }
    return 0;
}
