/* Shortest Job First (Premptive)*/

#include<stdio.h>
#include<stdlib.h>

#define Max 1000
#define Stop -999

struct Process{
    int a;
    int b;
    int t;
    int w;
};

void main(){
    int i,sum=0,n,j,k,small=0,ta,w;
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
	
	//Sorting Processes w.r.t. arrival time
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(S[j].a>S[j+1].a){
              temp=S[j];
              S[j]=S[j+1];
              S[j+1]=temp;
            }
        }
    }
    
    //Displaying Sorted process
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
    for(i=0;i<sum;i++)
    	printf("---+");
    printf("\n");
    
    
    //SJF logic
    for(i=0;i<sum;i++){
        for(k=0;K[k].a<=i&&k<n;k++){
            if(K[small].b>K[k].b){
                if(K[k].b>0)
                    small=k;
                }
         }
      printf("| %d ",small+1);
        if(K[small].b!=0){
             K[small].b--;
             if(K[small].b==0){
                K[small].t=i+1-K[small].a;
				K[small].b=999;
             }
        }
    }
	printf("|\n");
	printf("+");
	for(i=0;i<sum;i++)
		printf("---+");		
	printf("\n");
	for(i=0;i<=sum;i++)
		if(i<10)
			printf("%d   ",i);
		else
			printf("\b%d   ",i);	
	printf("\n");
	
	
	//Waiting time and Turnaroud time calculation
	for(i=0;i<n;i++){
		ta+=K[i].t;
		S[i].w=K[i].t-S[i].b;
		w+=S[i].w;
	}
	
	//Formatted output
	printf("===========================================\n");
	printf("|PROCESS|ARRIVAL|BURST|TURN AROUND|WAITING|\n");
	printf("+-------+-------+-----+-----------+-------+\n");
    for(i=0;i<n;i++){
        printf("|%4d   |%4d   |%3d  |%6d     |%4d   |\n",i+1,S[i].a,S[i].b,K[i].t,S[i].w);
    }
	printf("+-------+-------+-----+-----------+-------+\n");
	printf("===========================================\n");
	
	at=(float)ta/n;
	aw=(float)w/n;
	printf("Average Turnaround: %f\n",at);
	printf("Average waiting: %f\n",aw);

}
/** Execution Trail **/
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
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| 1 | 1 | 2 | 3 | 3 | 1 | 4 | 5 | 5 | 5 | 5 | 5 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19   
===========================================
|PROCESS|ARRIVAL|BURST|TURN AROUND|WAITING|
+-------+-------+-----+-----------+-------+
|   1   |   0   | 10  |    19     |   9   |
|   2   |   2   |  1  |     1     |   0   |
|   3   |   3   |  2  |     2     |   0   |
|   4   |   6   |  1  |     1     |   0   |
|   5   |   7   |  5  |     5     |   0   |
+-------+-------+-----+-----------+-------+
===========================================
Average Turnaround: 5.600000
Average waiting: 1.800000
*/

