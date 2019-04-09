#include <stdio.h>
#include <conio.h>

void Insert(char);
void PrintOnScreen();
char Get();
void CopyToFile();

int i,j,frame,count=0,flag=0,fault=0,n,k,p,position;                        /*declaring variables as global so that they can be accessed anywhere in the code*/
char yes,string[30],memory[10],temp_value,ch,fname[15];
FILE* fp;
/*
Count->        tells if the page frame is full. 
fname->        file name in which you want to copy the results.
frame->        number of frames.
fault->        number of page faults. 
string->       reference string (page requests).
memory->       cache where the page requests are stored.Used later to print on screen an copy to file.
temp_value->   Stores the temporary value when there is a need to swap.
ch->           to accept/store pages and copy them to file.
i,j,k,p->      loop variables.
count->        counts the number of frames that are occupied.
flag->         indicates if the requested page already exists in the memory.
n->            number of page requests.
position->     identify from which position we need to swap or update.
yes->          If user wants to try again when there is an error in opening file.
*/

void main() {
     start:
     clrscr(); 
  
     printf("LEAST RECENTLY USED PAGE ALGORITHM.\n\n");  
     printf("\n");   
     printf("Enter the number of frames:- \n");                           
     scanf("%d",&frame);                                                  /*Accepting the number of frames from user*/  
     printf("Enter the number of page requests:- \n");
     scanf("%d",&n);                                                      /*Accepting the number of page requests from user*/
     n++;
                                                                 /*length increased by one because the last character of the string will be null character*/
     printf("Enter the page requests.Do not use space.Enter a continious string:- \n");
      for(i=0;i<n;i++) {                                          
          scanf("%c",&string[i]);                                          /*Accepting page requests from user*/
      }

      for(i=0;i<frame;i++) {                                               /*initializing  memory to some default value*/
          memory[i]=' ';                                    
      }

      printf("Enter the file name where you want to copy the content:- \n");
      scanf("%s",&fname);

      fp=fopen(fname,"w");                                                 /*open file for writing purpose*/
      if(fp!=NULL) {
         printf("File opened successfuly. \n");
         printf("Processing input.Please wait");
         sleep(1);
         printf(".");
         sleep(1);
         printf(".");
         sleep(1);
         printf(".");
         fprintf(fp,"LEAST RECENTLY USED PAGE ALGORITHM. \n");
         for(i=0;i<n;i++) {  
             Get();                                                        /*Accepting the page values one by one from the reference string*/
             Insert(string[i]);                                                     /*Inserts the reference string*/
             PrintOnScreen();                                              /*prints the result on screen*/
             CopyToFile();                                                 /*Enters data in the file*/                                          
       }
        fprintf(fp,"Number of page faults: %d \n",fault-1);               /*Prints the number of page faults in file*/
        printf("Number of page faults: %d \n",fault-1);  
        printf("Data entered successfully.\n");                 /*Prints the number of page faults on screen*/

        fclose(fp);                                                         /*closes file*/
        printf("File closed successfully. \n");
     } 
     else {
        printf("Error in opening file.\n");
        printf("To try again enter Y.Else enter any other character.\n");
        scanf("%c",&yes);
        if(yes=='Y' || yes=='y') {
           goto start;
        }  
    }
 
  getch();
  
}

char Get() {                                                          /*returns ith position in the string.*/

    return string[i];
}

void Insert(char) { 
                                                                     /*Function to insert the pag request*/
     flag=0;                                                         /*Flag tells if the page alrady exists in the memory. By default we consider the page doesnt exist in memory. Hence flag=0*/
     position=0;                                                     /*If the page already exists, this tell the position. Default value 0*/

     if(count<frame) {                                               /*If the frame is not full yet*/
        for(j=0;j<frame;j++) {                                       /*Searches if the page already exists in the memory. If yes, flag=1; and exit the loop.*/
            if(memory[j]==string[i]) {
               flag=1; 
               temp_value=memory[j];                                 /*temp_value stores the value at that position*/
               position=j;
               break;
            }
        }
        if(flag==1) {                                                /*If page exists, Update its position*/
            for(k=position;k<frame-1;k++) {
                memory[k]=memory[k+1];
            }
            memory[k]=string[i];
        }
        else {                                                      /*If page doesnt exist, add it to the memory.*/
            memory[count]=string[i];
            count++;   
            fault++;
        }
    }
    else {                                                         /*If the memory is already full.Flag and postion already declared 0.*/
        for(j=0;j<frame;j++) {                                     /*Search if the page requested already exists*/
            if(memory[j]==string[i]) {                     
               flag=1;
               temp_value=string[i];                               
               position=j;
               break;  
            }
        }
        if(flag==1) {                                              /* If it exists,update its position.*/
            for(k=position;k<frame-1;k++) {   
                memory[k]=memory[k+1];
            }
               memory[k]=string[i];
        }
        else {                                                    /*If the page doesnt exist already, Add it.And remove the first page(least recently used in the memory*/
            fault++;
            for(k=0;k<frame-1;k++) {
                memory[k]=memory[k+1];
            }
            memory[k]=string[i];
        }
    }

}
    
void PrintOnScreen() {                                              /*Prints the memory.*/
   
     for(p=0;p<=frame;p++) {
         printf(" %1c ",memory[p]);  
     }
     printf("\n");

     return;
}

void CopyToFile() {                                               /*copies the content to the file.*/

     for(p=0;p<frame;p++) { 
        fprintf(fp," %1c ",memory[p]);
     }
     fprintf(fp,"\n");

    return;
}
