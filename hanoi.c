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
											}else{
												cnum = 10;
												moveHanoi('A', 'B', 'C', n);
											}
										}else{
											cnum = 9;
											moveHanoi('A', 'B', 'C', n);
										}
									}else{
										cnum = 8;
										moveHanoi('A', 'B', 'C', n);
									}
								}else{
									cnum = 7;
									moveHanoi('A', 'B', 'C', n);
								}
							}else{
								cnum = 6;
								moveHanoi('A', 'B', 'C', n);
							}
						}else{
							cnum = 5;
							moveHanoi('A', 'B', 'C', n);
						}
                    }else{
						cnum = 4;
						moveHanoi('A', 'B', 'C', n);
                    }
				}else{
					cnum = 3;
					moveHanoi('A', 'B', 'C', n);
				}
			}else{
				cnum = 2;
				moveHanoi('A', 'B', 'C', n);
			}
		}else{
			cnum = 1;
			moveHanoi('A', 'B', 'C', n);
		}

/*
		  while(1){
			if(!pid){
			  	cnum += 1;
			  	child_value += moveHanoi('A', 'B', 'C', n);
			}else{
				pid = createChild();
			}
			if(child_value == 10) break;
	      }
*/

        return 0;
}

int moveHanoi(char from,char temp,char to, int n)
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

pid_t createChild(void){
	child_num++;
	return fork();
}
