
#include <stdio.h>
#include "LibPro.h"

int main()
{
    FILE *fp;
    B i[500];

    fp = fopen("newinput.txt", "r");
    int j = 0;
    while (1)
    {

        fscanf(fp, "%d %s %d %d  %s %d", &i[j].Sno, i[j].Author, &i[j].price, &i[j].no_p, i[j].Book_Type, &i[j].No_Of_Copies);
        if (feof(fp))
            break;
        j++;
    }
    fclose(fp);

    Bubblesort(i, j);

    int l = 0;
    int r = j - 1;
    quicksort(i, l, r);

    fp = fopen("newinput.txt", "w");
    for (int k = 0; k < j; k++)
    {
        fprintf(fp, "%d %s %d %d  %s %d\n", i[k].Sno, i[k].Author, i[k].price, i[k].no_p, i[k].Book_Type, i[k].No_Of_Copies);
    }
    fclose(fp);

    char enter[10];
    printf("Enter Book Name to Search \n");



        scanf(" %s", enter);
        /* BFSS(enter,j,i);
        RK(enter, i, j);

    SelectionSort(i,j);
     fp = fopen("newinput.txt", "w");
    for (int k = 0; k < j; k++)
    {
        fprintf(fp, "%d %s %d %d  %s %d\n", i[k].Sno, i[k].Author, i[k].price, i[k].no_p, i[k].Book_Type, i[k].No_Of_Copies);
    }
    fclose(fp);


*/
}
