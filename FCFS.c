/*First come first serve Scheduling Process*/
#include <stdio.h>
 
 struct process{
   int pno;
   int BT;
   int AT;
 }pro[3];

 struct temp{
   int pno;
   int BT;
   int AT;
   int CT;
   int TAT;
   int WT;
   int RT;
   int ET;
 }pro1[3];

int main() {

    int min,i,j,temp1,ideltime,sumBT=0;
   
    printf("Enter the details of each process: \n\n");
        for(i=0;i<3;i++) {
             pro[i].pno=i+1;
             printf("Process number for process1: %d \n",i+1);
             printf("Enter Burst time of process %d: ",i+1);
             scanf("%d",&pro[i].BT);
             printf("\n");
             printf("Enter the arival time of process %d: ",i+1);
             scanf("%d",&pro[i].AT);
             printf("\n\n");
        }

   //printf("----------------------------------------------\n");
   //printf(" Process I.D     Arrival Time      Burst Time \n");
   //printf("----------------------------------------------\n");
  // for(i=0;i<3;i++) {
  // printf("  %-2d             %-2d               %-2d    \n",pro[i].pno,pro[i].AT,pro[i].BT);
  // printf("                                              \n");
   //}

   
  int max=pro[0].AT;
  for(i=0;i<3;i++) {
      for(j=0;j<3;j++) {
        if(max<pro[j].AT) {
          max=pro[j].AT;
        }

      }
  }

   for(i=0;i<3;i++) {
       min=pro[i].AT;  
       for(j=0;j<3-i-1;j++) {
           if(min>pro[j].AT) {
            min=pro[j].AT;
            }          
       }
       pro1[i].AT=pro[j].AT;
       pro1[i].BT=pro[j].BT;
       pro1[i].pno=pro[j].pno;
       pro[j].AT=max;
     

   } 


   printf("----------------------------------------------\n");
   printf(" Process I.D     Arrival Time      Burst Time \n");
   printf("----------------------------------------------\n");
   for(i=0;i<3;i++) {
   printf("  %-2d             %-2d               %-2d    \n",pro1[i].pno,pro1[i].AT,pro1[i].BT);
   printf("                                              \n");
   }

   
  ideltime=pro1[0].AT-0;
  printf("%d is the idel time. \n",ideltime);

  temp1=0;  //CT
  while(temp1<3) {
      for(i=0;i<1;i++) {
      sumBT+=pro1[temp1].BT;
      
       }
  pro1[temp1].CT=ideltime+sumBT;
  temp1++;

  }
  
   for(i=0;i<3;i++) {  //TAT
    pro1[i].TAT=pro1[i].CT-pro1[i].AT;
  }
  
 
  pro1[0].WT=0;  //WT
  for(i=1;i<3;i++) {
    pro1[i].WT=pro1[i-1].CT-pro1[i].AT;
  }

 
  for(i=0;i<3;i++) {  //RT
    pro1[i].RT=pro1[i].WT;
  }

  for(i=0;i<3;i++) {   //ET
    pro1[i].ET=pro1[i].BT;
  }
  
  printf("------------------------------------------------------------------------------------------------------------------ \n");
  printf(" Process No.      AT         BT           CT         TAT           WT            RT           ET      \n");
  printf("                                                                                                                   \n");
  for(i=0;i<3;i++) {
  
  printf("                                                                                                        \n");
  printf("    %-2d             %-2d        %-2d          %-2d             %-2d           %-2d          %-2d           %-2d     \n",pro1[i].pno,pro1[i].AT,pro1[i].BT,pro1[i].CT,pro1[i].TAT,pro1[i].WT,pro1[i].RT,pro1[i].ET);
  }  
  

   

}