#include<stdio.h>
#include<conio.h>
#include<string.h>
// Sudarshan Pendhari
char instr[50][50];
char buff[50],bu[50];
FILE *fp,*expand,
struct mnt
{
	char macroname[50];
	int index;
}MNT[2]={{"ABC",0},{"MNO",2}};
char MDT[4][50]={{"MOVEM AREG, A"},{"MEND"},{"ADD AREG, A"},{"MEND"}};

int main()
{

    fp=fopen("inter.dat","r");
    expand=fopen("expand.dat","w");
    printf("\n INTERMEDIATE CODE");
    printf("\n ======================================");
   
     while (!feof(fp))
    {
        ch = fgetc(fp);
        printf("%c", ch);
    }
    rewind(fp);
    do{
     fscanf(fp, "%s", buff);
     if (strcmp(buff, "START") == 0)
        {
            fprintf(expand, "%s", buff);
            fprintf(expand, "%s", " ");
            fscanf(fp, "%s", buff);
            fprintf(expand, "%s", buff);
            fprintf(expand, "%s", "\n");
        }
     else{
          if(strcmp(buff, "END") == 0){
            fprintf(expand, "%s", buff);
            break;   
          }
            else
        {
            int mdte = -1;
            for (int i = 0; i < 2; i++){
                if (strcmp(buff, MNT[i].macroname) == 0)
                {   
               
                    mdte =MNT[i].index ;
                    printf("%d",mdte,"\n");
                    break;
                }
            }
            if (mdte!=-1)
            {
               while(strcmp(MDT[mdte],"MEND")!=0){
               //  fprintf(expand, "%s", MDT[mdte]);
                mdte++;
               }
            }
            else
            {
                const char c[] = " ";
                strcat(bu, buff);
                strcat(bu, c);
                fscanf(fp, "%s", buff);
                strcat(bu, c);
                strcat(bu, buff);
                fscanf(fp, "%s", buff);
                strcat(bu, c);
                strcat(bu, buff);
                fprintf(expand, "%s", bu);
                strcpy(bu, " ");
            }
            fprintf(expand, "%s", "\n");
        }
     }
    }while(strcmp(buff, "END") != 0);
     fclose(expand);
     fclose(fp);
     return 0;
     // getch();
}

