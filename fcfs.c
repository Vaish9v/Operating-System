#include<stdio.h>
#include<stdlib.h>

#define Max 1000


struct Process{
    int a;
    int b;
    int t;
    int w;
};


void main(){
    int i,sum=0,n,k,j,small=0,ta,w;
    float at,aw;
    struct Process temp,S[Max],K[Max];
    
    printf("Enter no. of Process\n");
    scanf("%d",&n);
    
    printf("=======================\n");
    printf("PROCESS\tARRIVAL\tBURST\n");    
    for(k=0;k<n;k++){
        printf("%d\t",k+1);
        scanf("%d%d",&S[k].a,&S[k].b);
    }
    printf("=======================\n");
    
    // Sorting Processes
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(S[j].a>S[j+1].a){
              temp=S[j];
              S[j]=S[j+1];
              S[j+1]=temp;
            }
        }
    }
    
    // Printing Formatted output(sorted processes)
    printf("=======================\n");
    printf("|PROCESS|ARRIVAL|BURST|\n");
    printf("+-------+-------+-----+\n");
    for(i=0;i<n;i++){
		printf("|%4d   |%4d   |%3d  |\n",i+1,S[i].a,S[i].b);
		sum+=S[i].b;
		K[i]=S[i];
    }
    printf("+-------+-------+-----+\n");
    printf("=======================\n");
    
    
	printf("+");
	
	
	for(i=0;i<n;i++) 
		printf("---+");
	printf("\n");
    int C[n+1];
	j=0;
	
	//FCFS Logic
	//sum is total burst time
	
	for(i=0;i<sum;i){  
		C[j]=i;
		j++;        
		printf("| %d ",small+1);
		if(K[small].b!=0){
			i+=K[small].b;
		 	K[small].b=0;    
			K[small].t=i-K[small].a;
			K[small].b=999;
		
		}
		small+=1;
	}   

	C[j]=sum;
	printf("|\n");
	printf("+");	
	for(i=0;i<n;i++)
		printf("---+");		
	printf("\n");

	for(i=0;i<=n;i++){		
		if(C[i]<10)
			printf("%d   ",C[i]);
		else
			printf("\b%d   ",C[i]);
	}	
	printf("\n");
	
	//Calculating turnaround time and waiting time
	for(i=0;i<n;i++){
		ta+=K[i].t;
		S[i].w=K[i].t-S[i].b;
		w+=S[i].w;
	}
	printf("============================================\n");
	printf("|PROCESS|ARRIVAL|BURST|TURN AROUND|WAITING|\n");
	printf("+-------+-------+-----+-----------+-------+\n");
	for(i=0;i<n;i++){
		printf("|%4d   |%4d   |%3d  |%6d     |%4d   |\n",i+1,S[i].a,S[i].b,K[i].t,S[i].w);
	}
	printf("+-------+-------+-----+-----------+-------+\n");
	printf("============================================\n");
	
	at=(float)ta/n;
	aw=(float)w/n;
	printf("Average Turnaround: %f\n",at);
	printf("Average waiting: %f\n",aw);
}





/** Execution Trial **/
/*
Enter no. of Process
5
=======================
PROCESS	ARRIVAL	BURST
1		0		10
2		2		1	
3		3		2
4		6		1
5		7		5
=======================
=======================
|PROCESS|ARRIVAL|BURST|
+-------+-------+-----+
|   1   |   0   | 10  |
|   2   |   2   |  1  |
|   3   |   3   |  2  |
|   4   |   6   |  1  |
|   5   |   7   |  5  |
+-------+-------+-----+
=======================
+---+---+---+---+---+
| 1 | 2 | 3 | 4 | 5 |
+---+---+---+---+---+
0  10  11  13  14  19   
============================================
|PROCESS|ARRIVAL|BURST|TURN AROUND|WAITING|
+-------+-------+-----+-----------+-------+
|   1   |   0   | 10  |    10     |   0   |
|   2   |   2   |  1  |     9     |   8   |
|   3   |   3   |  2  |    10     |   8   |
|   4   |   6   |  1  |     8     |   7   |
|   5   |   7   |  5  |    12     |   7   |
+-------+-------+-----+-----------+-------+
============================================
Average Turnaround: 9.800000
Average waiting: 6.000000

*/
