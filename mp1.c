#include <stdio.h>
#include <conio.h>
#include <string.h>
// Sudarshan Pendhari
struct mnt
{
    char macroname[50];
    int index;

} MNT[50];

FILE *fp, *inter, *fp2, *fp3;
char mdt[50][50], buff[50];
char bu[100];
char ch;
int idx = 0, mntc = 0;

int main()
{
    fp = fopen("in.txt", "r");
    inter = fopen("inter.dat", "w");
    fp2 = fopen("mdt.dat", "w");
    fp3 = fopen("mnt.dat", "w");
    // printing input file

    printf("\n\n Input File\n");
    printf("\n ======================================\n");
    while (!feof(fp))
    {
        ch = fgetc(fp);
        printf("%c", ch);
    }
    rewind(fp);
    do
    {
        fscanf(fp, "%s", buff); // reading word by word
        if (strcmp(buff, "START") == 0)
        {
            fprintf(inter, "%s", buff);
            fprintf(inter, "%s", " ");
            fscanf(fp, "%s", buff);
            fprintf(inter, "%s", buff);
            fprintf(inter, "%s", "\n");
        }
        else if (strcmp(buff, "MACRO") == 0)
        {
            fscanf(fp, "%s", buff);

            strcpy(MNT[mntc].macroname, buff);
            MNT[mntc].index = idx;
            // strcpy(mdt[idx],buff);
            //     idx++;
            mntc++;

            fscanf(fp, "%s", buff);
            const char c[] = " ";
            strcat(bu, buff);
            // strcat(bu,c);
            fscanf(fp, "%s", buff);
            strcat(bu, c);
            strcat(bu, buff);
            fscanf(fp, "%s", buff);
            strcat(bu, c);
            strcat(bu, buff);

            strcpy(mdt[idx], bu);
            strcpy(bu, " ");
            idx++;
            fscanf(fp, "%s", buff);
            strcpy(mdt[idx], buff);
            idx++;
        }
        else
        {
            int ismnm = 0;

            for (int i = 0; i < mntc; i++){
                if (strcmp(buff, MNT[i].macroname) == 0)
                {
                    ismnm = 1;
                    break;
                }
            }
            if (ismnm || strcmp(buff, "END") == 0)
            {
                fprintf(inter, "%s", buff);
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
                fprintf(inter, "%s", bu);
                strcpy(bu, " ");
            }
            fprintf(inter, "%s", "\n");
        }

    } while (strcmp(buff, "END") != 0);
    printf("\n\n MNT TABLE");
    printf("\n ======================================");
    printf("\nMacro Name\tStarting index");
    for (int i = 0; i < mntc; i++)
    {
        printf("\n %s  \t \t%d", MNT[i].macroname, MNT[i].index);
    }
    printf("\n\n MDT TABLE");
    printf("\n ======================================");
    printf("\nopcode\t\tIndex\n");
    for (int i = 0; i < idx; i++)
    {
        printf("\n %s\t\t%d ", mdt[i], i);
    }
    fclose(fp);
    fclose(inter);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
