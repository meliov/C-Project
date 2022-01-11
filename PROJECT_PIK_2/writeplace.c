#include "workplace.h"

product *head = NULL;
product *end = NULL;

product *CreateAndInputProdFIFO()
{


    product *temp = CreateDinamicStruct();
    if(temp == NULL)
    {
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        int flag_len, flag_id, flag;
         printf("Input product's number: ");
         //scanf("%s", temp->n_number);
         fflush(stdin);
         fgets(temp->n_number, S, stdin);
         temp->n_number[strlen(temp->n_number) -1] = '\0';
         fflush(stdin);
         if(flog == 1)//delete and add 1st fix
         {
             product *del = head;
             head = head->next;
             free(del);
             flog = 0;
         }
         product *temp_temp = head;
         flag_id = 0;
         flag_len = 0;
         flag = 0;
         while(temp_temp != NULL) //repeating check
         {
             //printf("\n%s\n", temp_temp->n_number);//test
             if(strcmp(temp->n_number, temp_temp->n_number) == 0)
             {
                 flag_id = 1;
                 printf("The current number already exists!\n");
                 //printf("\nDebug1:%s\n", temp_temp->n_number);
                 if(strlen(temp->n_number) != 12)
                 {
                     printf("Also it must contain 12 numbers!\n");
                     flag_len = 1;
                     flag = 1;
                 }
                 break;
             }
             temp_temp = temp_temp->next;
         }
         if(strlen(temp->n_number) != 12 && flag == 0)
         {
             printf("The number must contain 12 numbers!\n");
             flag_len = 1;
         }
         if(flag_id == 0 && flag_len == 0)
         {
             break;
         }

    }

    printf("Input name of product: ");
    fgets(temp->name,S,stdin);
    temp->name[strlen(temp->name)-1] = '\0';
    fflush(stdin);
    printf("Input product's price: ");
    scanf("%lf", &temp->price);

    printf("Input quantity of product: ");
    scanf("%d", &temp->quantity);


    printf("Date input must be DD.MM.YYYY!\n");
    int d_counter = 0;
    while(1)
    {
        int flag  = 0;
        int flag_len = 0, flag_dot = 0, flag_cor = 0;
        if(d_counter > 0)
        {
            flag = 1;
        }


        if(flag != 0)
        {
            printf("Date is not correct.\n");
            if(flag_len != 0)
            {
                printf("Too many symbols!\n");
            }
            if(flag_dot != 0)
            {
                printf("The delimiter must be '.'!\n");
            }
            if(flag_cor)
            {
                printf("Check the DD.MM.YYYY again!\n");
            }
        }
        printf("Input expire date: ");
        fflush(stdin);
        fgets(temp->date,S,stdin);
        temp->date[strlen(temp->date)-1] = '\0';
        fflush(stdin);
        d_counter++;
        if(strlen(temp->date) != 10)
        {
            flag_len = 1;
        }
        if(temp->date[2] != '.' || temp->date[5] != '.')//12.12.2021
        {
            flag_dot = 1;
        }
        char cdd[10], cmm[10], cyy[10];
        if(flag_dot == 0 && flag_len == 0)
        {
            int g = 0;
            for(int i = 0; i < strlen(temp->date); i++)
            {
                 g = i;
                if(temp->date[i] == '.')
                {
                    cdd[i] = '\0';
                    break;
                }
                cdd[i] = temp->date[i];


            }
            g++;
            int dd = atoi(cdd);
            //printf("\n%s - %d\n", cdd, dd);
            for(int i = g, j = 0; i < strlen(temp->date); i++,j++)
            {
                 g = i;

                if(temp->date[i]== '.')
                {
                    cmm[j] = '\0';
                    break;
                }
                 cmm[j] = temp->date[i];

            }
            g++;
            int mm = atoi(cmm);
            //printf("\n%s - %d\n", cmm, mm);
            for(int i = g, j = 0; i < strlen(temp->date); i++,j++)
            {
                cyy[j] = temp->date[i];
            }
            int yy = atoi(cyy);
           // printf("\n%s - %d\n", cyy, yy);
            if(dd < 1 || dd > 31)
            {
               flag_cor = 1;
               printf("Day not correct! %d must be between 1 and 31\n", dd);
            }
            if(mm < 1 || mm > 12)
            {
               flag_cor = 1;
               printf("Month not correct! %d must be between 1 and 12\n", mm);
            }
            if(yy < 2020 )
            {
               flag_cor = 1;
               printf("Damn this is like really old!Must be bigger than %d\n", yy);
            }
        }
        if(flag_len == 0 && flag_dot == 0 && flag_cor == 0)
            {
                break;
            }

    }

   temp->next = NULL;

    ///FIFO List
    if(head == NULL)//1 2 3 4 5 6 if flag == 1, prev->next = NULL, free curr
    {
        head = temp;
        end = head;
    }
    else
    {
        end->next = temp;
        end = end->next;
    }
   /* temp->next = head;
    head = temp;*///for debugging

   return head;
}
void PrintProduct(product *temp)
{
   int flag = 0;
   int counter = 1;
   printf("\n");
   while(temp != NULL)
   {
       printf("\n\tProduct %d: \n\n", counter);
       printf("Product %d number: %s\n",counter, temp->n_number);
       printf("Product %d name: %s\n",counter, temp->name);
       printf("Product %d price: %.2lf\n", counter, temp->price);
       printf("Product %d quantity: %d\n", counter, temp->quantity);
       printf("Product %d expire date: %s\n", counter, temp->date);
       counter++;
       flag++;
       temp = temp->next;
   }
   if(flag == 0)
   {
       printf("There are no available products!\n");
   }
}
product *CreateDinamicStruct()
{
    product *element = (product*)malloc(sizeof(product));
    if(element == NULL)
    {
        printf("Can't allocate memory\n");
        free(element);
        return NULL;
    }
    return element;
}
void printTarget(product *temp)
{
    int flag = 0;
    char num[S];
    printf("Insert ID Number: ");
    scanf("%s", num);
    if(strlen(num) != 12)
    {
        printf("Wrong ID! Must be 12 numbered!You are going back to the MENU!");
        return;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->n_number, num) == 0)
        {
           printf("\n\tProduct with ID - %s is:\n\n", num);
           printf("Product number: %s\n", temp->n_number);
           printf("Product name: %s\n", temp->name);
           printf("Product price: %.2lf\n", temp->price);
           printf("Product quantity: %d\n", temp->quantity);
           printf("Product expire date: %s\n", temp->date);
           flag++;
           break;
        }
        temp = temp->next;
    }
    if(flag == 0)
    {
        printf("There are no available products with the given ID!\n");
    }
}
int AddSubstractQuantity(product *h, int *n)
{

    product *toDelete = h;
    product *temp = h;
    char num[S];
    int target = 0;
    printf("Insert ID Number: ");
    scanf("%s", num);
    int flag = 0;
    if(strlen(num) != 12)
    {
        printf("Wrong ID! Must be 12 numbered!You are going back to the MENU!");
        return 0;
    }
    while(temp!=NULL)
    {
        target++;//counts the elements
        if(strcmp(temp->n_number, num) == 0)
        {
            flag = 1;
           break;
        }
        temp = temp->next;
    }
    if(flag == 0)
    {
        printf("ID not found!Going back to the MENU!\n");
        return 0;
    }
    int amount;
    int x;
    printf("\n\tCommand inserting\n");
    printf("To ADD press 1\nTo SUBTRACT press 2\nInsert here: ");
    scanf("%d", &x);
    if(x == 1)
    {
        printf("Insert the amount you want to add: ");
        scanf("%d", &amount);
        temp->quantity += amount;
        printf("Done!\n");
    }
    else if(x == 2)
    {
        printf("Insert the amount you want to subtract: ");
        scanf("%d", &amount);
        if(temp->quantity - amount == 0)
        {
            printf("The amount was enough to get the product out of stock. It will be removed from the storage.\n");///returns 1 to delete the first element
            if(target <= 1)
            {
                return 1;
            }
            else
            {
                temp = Target_Delete(toDelete,target,&n);
            }
        }
        else if(temp->quantity < amount)
        {
            printf("The quantity is too big! There are not so many available products!");
        }
        else
        {
            temp->quantity -= amount;
            printf("Done!\n");
        }
    }
    else
    {
        printf("Wrong option!You are going back to the MENU!\n");
    }
return 0;
}
void PrintExpired(product *temp)
{
    char date[S];
    int dd,yy,mm, ddp, mmp,yyp;
    int final_counter = 0;
    //product validation handling
    int d_counter = 0;
    while(1)
    {
        int flag  = 0;
        int flag_len = 0, flag_dot = 0, flag_cor = 0;
        if(d_counter > 1)
        {
            flag = 1;
        }


        if(flag != 0)
        {
            printf("Date is not correct.\n");
            if(flag_len != 0)
            {
                printf("Too many symbols!\n");
            }
            if(flag_dot != 0)
            {
                printf("The delimiter must be '.'!\n");
            }
            if(flag_cor)
            {
                printf("Check the DD.MM.YYYY again!\n");
            }
        }
        printf("Input expire date(dd.mm.yyyy): ");
        fflush(stdin);
        fgets(date,S,stdin);
        date[strlen(date)-1] = '\0';
        fflush(stdin);
        d_counter++;
        if(strlen(date) != 10)
        {
            flag_len = 1;
        }
        if(date[2] != '.' || date[5] != '.')
        {
            flag_dot = 1;
        }
        char cdd[10], cmm[10], cyy[10];
        if(flag_dot == 0 && flag_len == 0)
        {
            int g = 0;
            for(int i = 0; i < strlen(date); i++)
            {
                 g = i;
                if(date[i] == '.')
                {
                    cdd[i] = '\0';
                    break;
                }
                cdd[i] = date[i];


            }
            g++;
             dd = atoi(cdd);
            for(int i = g, j = 0; i < strlen(date); i++,j++)
            {
                 g = i;

                if(date[i]== '.')
                {
                    cmm[j] = '\0';
                    break;
                }
                 cmm[j] = date[i];

            }
            g++;
             mm = atoi(cmm);
            for(int i = g, j = 0; i < strlen(date); i++,j++)
            {
                cyy[j] = date[i];
            }
             yy = atoi(cyy);
            if(dd < 1 || dd > 31)
            {
               flag_cor = 1;
               printf("Day not correct! %d must be between 1 and 31\n", dd);
            }
            if(mm < 1 || mm > 12)
            {
               flag_cor = 1;
               printf("Month not correct! %d must be between 1 and 12\n", mm);
            }
            if(yy < 1700)
            {
               flag_cor = 1;
               printf("Damn this is like really old!Must be bigger than %d\n", yy);
            }
        }
        if(flag_len == 0 && flag_dot == 0 && flag_cor == 0)
            {
                break;
            }
    }//date handling
    while(temp!=NULL)
    {
        int final_flag = 0;
        int g = 0;
        char cdd[10], cmm[10], cyy[10];
            for(int i = 0; i < strlen(temp->date); i++)
            {
                 g = i;
                if(temp->date[i] == '.')
                {
                    cdd[i] = '\0';
                    break;
                }
                cdd[i] = temp->date[i];


            }
            g++;
             ddp = atoi(cdd);
            for(int i = g, j = 0; i < strlen(temp->date); i++,j++)
            {
                 g = i;

                if(temp->date[i]== '.')
                {
                    cmm[j] = '\0';
                    break;
                }
                 cmm[j] = temp->date[i];

            }
            g++;
             mmp = atoi(cmm);
            for(int i = g, j = 0; i < strlen(temp->date); i++,j++)
            {
                cyy[j] = temp->date[i];
            }
            yyp = atoi(cyy);
        if(yyp == yy )
        {
            if(mm == mmp)
            {
                if(ddp < dd)
                {
                    final_flag = 1;
                }
            }
            if(mmp < mm)
            {
                final_flag = 1;
            }
        }
        else if(yyp < yy)
        {
            final_flag = 1;
        }
        if(final_flag == 1)
        {
           printf("\n\tProduct below is expired:\n\n");
           printf("Product number: %s\n", temp->n_number);
           printf("Product name: %s\n", temp->name);
           printf("Product price: %.2lf\n", temp->price);
           printf("Product quantity: %d\n", temp->quantity);
           printf("Product man date: %s\n", temp->date);
           final_counter++;
        }
        temp = temp->next;
    }
    if(final_counter == 0){
        printf("\nDone!No expired products found!\n");
    }
    else
    {
        printf("\nDone!The count of the expired products is %d!\n", final_counter);
    }
}
product *Target_Delete(product *h, int target, int **n)
{
    int flag = 0;
    product *prev = h;
    product *curr = h;

    for(int i = 0; i < target - 1; i++)
    {
        prev = curr;
        curr = curr->next;
        if(curr->next == NULL)
        {
            flag =1;
            break;
        }
    }
    if(flag == 0){
        prev->next = curr->next; //hop skip jump
        free(curr);
        curr = NULL;
    }
    else//because if deleting last element of FIFO, the end pointer doesn't point to the last element anymore
    {
        prev->next = NULL;
        end = prev;
        free(curr);
        curr = NULL;
    }

    (**n)--;//because we want to reach the n from the main function, and n is actually the amount of elements we have input
    return h;
}
void BinFileWrite(product *temp)
{
    FILE *file;
    char fname[] = "fp.bin"; //if you want to input the name from the console, change here
    file = fopen(fname, "ab");
    int len1, len2, len3;
    len1 = strlen(temp->name);
    len2 = strlen(temp->date);
    len3 = strlen(temp->n_number);
    if(file == NULL)
    {
        printf("Can't open the file!\n");
        exit(EXIT_FAILURE);
    }
    if(fwrite(&len1,sizeof(int), 1, file) != 1)
    {
        perror("Write 1: ");
        exit(EXIT_FAILURE);
    }
    if(fwrite(temp->name, sizeof(char), len1, file) != len1)
    {
        perror("Write 2: ");
        exit(EXIT_FAILURE);
    }
    if(fwrite(&len2,sizeof(int), 1, file) != 1)
    {
        perror("Write 3: ");
        exit(EXIT_FAILURE);
    }
    if(fwrite(temp->date, sizeof(char), len2, file) != len2)
    {
        perror("Write 4: ");
        exit(EXIT_FAILURE);
    }
    if(fwrite(&len3,sizeof(int), 1, file) != 1)
    {
        perror("Write 5: ");
        exit(EXIT_FAILURE);
    }
    if(fwrite(temp->n_number, sizeof(char), len3, file) != len3)
    {
        perror("Write 6: ");
        exit(EXIT_FAILURE);
    }
    if(fwrite(&temp->quantity,sizeof(int), 1, file) != 1)
    {
        perror("Write 7: ");
        exit(EXIT_FAILURE);
    }
    if(fwrite(&temp->price,sizeof(double), 1, file) != 1)
    {
        perror("Write 8: ");
        exit(EXIT_FAILURE);
    }
    fclose(file);

}
product *BinFileRead(product *LIFO_head, int n)
{

    FILE *file;
    char fname[] = "fp.bin";
    file = fopen(fname, "rb");
    int len1, len2, len3;
   int counter = 0;
   while(1){
        product *temp = (product*)malloc(sizeof(product));
        if(temp == NULL)
        {
            perror("Can't allocate memory!\n");
            exit(EXIT_FAILURE);
        }
        if(file == NULL)
        {
            printf("Can't open the file!\n");
            exit(EXIT_FAILURE);
        }
        if(fread(&len1,sizeof(int), 1, file) != 1)
        {
            perror("Read 1: ");
            exit(EXIT_FAILURE);
        }
        if(fread(temp->name, sizeof(char), len1, file) != len1)
        {
            perror("Read 2: ");
            exit(EXIT_FAILURE);
        }
        temp->name[len1] = '\0';
        if(fread(&len2,sizeof(int), 1, file) != 1)
        {
            perror("Read 3: ");
            exit(EXIT_FAILURE);
        }
        if(fread(temp->date, sizeof(char), len2, file) != len2)
        {
            perror("Read 4: ");
            exit(EXIT_FAILURE);
        }
        temp->date[len2] = '\0';
        if(fread(&len3,sizeof(int), 1, file) != 1)
        {
            perror("Read 5: ");
            exit(EXIT_FAILURE);
        }
        if(fread(temp->n_number, sizeof(char), len3, file) != len3)
        {
            perror("Read 6: ");
            exit(EXIT_FAILURE);
        }
        temp->n_number[len3] = '\0';
        if(fread(&temp->quantity,sizeof(int), 1, file) != 1)
        {
            perror("Read 7: ");
            exit(EXIT_FAILURE);
        }
        if(fread(&temp->price,sizeof(double), 1, file) != 1)
        {
            perror("Read 8: ");
            exit(EXIT_FAILURE);
        }
        temp->next = LIFO_head;
        LIFO_head = temp;
        counter++;
        if(counter == n)
            break;
   }
    fclose(file);
  return LIFO_head;
}

