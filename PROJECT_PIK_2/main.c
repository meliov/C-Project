#include "workplace.h"


int main()
{
    int n;
    int terminator;
    char termin[s];
    product *info;
    printf("Input number of the elements you want to input: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
          printf("\n\tProduct %d: \n\n", i+1);
          info = CreateAndInputProdFIFO();
    }
    do
    {
        printf("\n\n\tC O M M A N D\t M E N U \n\n");
        printf("If you want to exit - press something different from {1 , 2 , 3 , 4 }\n");
        printf("To add more products press 1\nTo print expired products press 2\nTo change the quantity of a product(add/subtract)- press 3\nTo print information of a product press 4\nInsert here: ");
        scanf("%s", termin);
        terminator = atoi(termin);

        if(terminator != 1 && terminator != 2 && terminator != 3 && terminator != 4)
        {
            terminator = 0;
        }

        //print
        if(terminator == 4)
        {
            int x;
            printf("For displaying  all available products press 1\nFor displaying a single product press 2\nInsert here: ");
            scanf("%d", &x);
            if(x == 1)
            {
                PrintProduct(info);
            }
            else if(x == 2)
            {
                printTarget(info);
            }
            else
            {
                printf("Not correct operation! You will be sent back to the MENU\n");
            }
        }
        else if(terminator == 1) //add a product
        {
            int a;
            printf("Input number of elements you want to add: ");
            scanf("%d", &a);
            n += a;// we must keep track on the elements count
            for(int i = 0; i < a; i++)
            {
                printf("\n\t\tInputing new product %d: \n", i+1);
                info = CreateAndInputProdFIFO();
                printf("Done!\n");
            }

        }

        // add/substract quantity
        else if(terminator == 3)
        {
            int y = AddSubstractQuantity(info, &n);
            if(y == 1)//frees it here because it had a bug
            {
                product *togo = info;
                info = info->next;
                free(togo);
                n--;
                flog = 1;//for fixing a bug where deleting the first item doesn't allow us to add more products
            }

        }
        else if(terminator == 2)
        {
            PrintExpired(info);
        }

    }
    while(terminator != 0);
    //file write
    product *collector = NULL;//new list to collect the data from the files
    printf("You will get the information stored in a Binary file\n");
    while(info != NULL)
    {
        BinFileWrite(info);
        info = info->next;
    }
    //file read
    collector = BinFileRead(collector, n);
    printf("\n\tCONTENT OF BINARY FILE: \n\n");
    PrintProduct(collector);
    sleep(5);
    exit(EXIT_SUCCESS);
    //if you have problem with reading the file, delete the content of the file itself, really irritating tho ;(
}
