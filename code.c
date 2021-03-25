#include <stdio.h>
#include<string.h>
struct bookdetail
{
    char name[20];
    char author[20];
    char version[20];
    int publishing_year;
    float price;
};
void getinput(struct bookdetail list[], int n);
void display(struct bookdetail list[], int n);
void sort(struct bookdetail list[], int n);
void year(struct bookdetail list[80], int n);
void yearsort(struct bookdetail list[80],int n);
void sortname(struct bookdetail list[80],int n);
int main()
{
    struct bookdetail data[20];
    int n;
    printf("Enter the Numbers of Books: ");
    scanf("%d",&n);
    getinput(data,n);
    printf("\nBook Information \n");
    display(data,n);
    sort(data,n);
    printf("\n Price order of Book Information \n");
    display(data, n);
    year(data,n);
    yearsort(data,n);
    sortname(data,n);
    return 0;
} 

void getinput(struct bookdetail list[80], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\t=:Book %d Detail:=\n",i+1);
        printf("\nEnter the Book Name:\n");
        scanf("%s",list[i].name);
        printf("Enter the Author of Book:\n");
        scanf("%s",list[i].author);
        printf("Enter the version of Book:\n");
        scanf("%s",list[i].version);
        printf("Enter the publishing_year of Book:\n");
        scanf("%d",&list[i].publishing_year);
        printf("Enter the Price of Book:\n");
        scanf("%f",&list[i].price);
    } 
}

void display(struct bookdetail list[80], int n)
{
    int i,t=1;
    for(i=0;i<n;i++,t++)
    {
        printf("\n");
        printf("Book No.%d\n",t);
        printf("\t\tBook %d Name is =  %s \n",t,list[i].name);
        printf("\t\tBook %d Author is =  %s \n",t,list[i].author);
        printf("\t\tBook %d version is =  %s \n",t,list[i].version);
        printf("\t\tBook %d publishing_year is =  %d \n",t,list[i].publishing_year);
        printf("\t\tBook %d Price is =  %.2f \n",t,list[i].price);
        printf("\n");
    } 
}

void sort(struct bookdetail list[80], int n)
{
    int i,j;
    struct bookdetail temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1-i);j++)
        {
            if(list[j].price>list[j+1].price)
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            } 
        }
    }
}
void year(struct bookdetail list[80], int n)
{
    printf("\n Enter Year For Show That Particular Book Information \n");
    int i,y;
    scanf("%d",&y);
    for(i=0;i<n;i++)
    {
        if(list[i].publishing_year==y)
        {
            printf("\n");
            printf("\t\t Name is = %s \n",list[i].name);
            printf("\t\t Author is = %s \n",list[i].author);
            printf("\t\t version is = %s \n",list[i].version);
            printf("\t\t publishing_year is = %d \n",list[i].publishing_year);
            printf("\t\t Price is = %.2f \n",list[i].price);
            printf("\n");
            break;
        }
    }
}
void yearsort( struct bookdetail list[80],int n)
{
    int i,j;
    struct bookdetail temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1-i);j++)
        {
            if(list[j].publishing_year>list[j+1].publishing_year)
            {
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            } 
        }
    }
}
void sortname(struct bookdetail list[80],int n)
{
    int i,j;
    struct bookdetail temp[80];
    printf("\nYear increasing order _ author sorted order \n");
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
        if(strcmp(list[i].author,list[j].author)>0) 
        {
            strcpy(temp,list[i].author);
            strcpy(list[i].author,list[j].author);
            strcpy(list[j].author,temp);
        }
        }
    }
    for(i=0;i<n;i++)
    {
        printf(" \t %s \t \t \t  %d \n",list[i].author,list[i].publishing_year);
    }
}