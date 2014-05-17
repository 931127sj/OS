#include<stdio.h>
#include<unistd.h>

int child_num;
int child_value;
int cnum;

int moveHanoi(char a,char b,char c,int n);
pid_t createChild(void);

int main(void)
{
        int n;
		pid_t pid;
		
        printf("Enter number of hanoi's floor : ");
        scanf("%d",&n);

// CODE2
		if(fork()){ // parents
			if(fork()){ // parents
				if(fork()){ // parents
					if(fork()){ // parents
						if(fork()){ // parents
							if(fork()){ // parents
								if(fork()){ // parents
									if(fork()){ // parents
										if(fork()){ // parents
											if(fork()){ // parents
											}else{ // Last child node (10)
												cnum = 10;
												moveHanoi('A', 'B', 'C', n);
											}
										}else{ // 9th child node
											cnum = 9;
											moveHanoi('A', 'B', 'C', n);
										}
									}else{ // 8th child node
										cnum = 8;
										moveHanoi('A', 'B', 'C', n);
									}
								}else{ // 7th child node
									cnum = 7;
									moveHanoi('A', 'B', 'C', n);
								}
							}else{ // 6th child node
								cnum = 6;
								moveHanoi('A', 'B', 'C', n);
							}
						}else{ // 5th child node
							cnum = 5;
							moveHanoi('A', 'B', 'C', n);
						}
		                      }else{ // 4th child node
						cnum = 4;
						moveHanoi('A', 'B', 'C', n);
        		              }
				}else{ // 3rd child node
					cnum = 3;
					moveHanoi('A', 'B', 'C', n);
				}
			}else{ // 2nd child node
				cnum = 2;
				moveHanoi('A', 'B', 'C', n);
			}
		}else{ // 1st child node
			cnum = 1;
			moveHanoi('A', 'B', 'C', n);
		}

/* CODE1
		  while(1){
			if(!pid){ // child node
			  	cnum += 1; // child node number
			  	child_value += moveHanoi('A', 'B', 'C', n); // do moveHanoi function and check end of child node's work
			}else{ // parents node
				if(child_num < 10) pid = createChild(); // do createChild function and check number of child node
			}
			if(child_value == 10) break; // made 10 childe node and end all child node's work
                  }
*/
        return 0;
}

int moveHanoi(char from,char temp,char to, int n) // Hanoi tower
{
          if(n==1)
          {
                printf("child%3d : from %c to %c move %d \n",cnum,from,to,1);
				return 1;
          }
          else
          {
                moveHanoi(from,to,temp,n-1);
                printf("child%3d : from %c to %c move %d \n",cnum,from,to,n);
                moveHanoi(temp,from,to,n-1);
          }
}

pid_t createChild(void){ // make child node
	child_num++; // check child node number
	return fork(); // fork system call
}
