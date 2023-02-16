#include <stdio.h>
#include <string.h>
#include "SList.h"

int num=101,serialNo,cabin,phone,age;;
char name[30],symptom[30];

Slist *head = NULL;

int main()
{
    int c,i,q;
    printf("\nHospital Management System\n\n\n");

    while(c!=6)
    {
        printf("**Enter your choice**\n\n1. Add Information\n2. View Information\n3. Search\n4. Edit Information\n5. Delete Information\n6. Exit\n\nOption = ");
        scanf("%d",&c);//choice for option
        printf("\n");
        if(c==1)//add
        {
            add();
        }
        else if(c==2)//view
        {
            view();
        }
        else if(c==3)//search
        {
            search();
        }
        else if(c==4)//edit
        {
            edit();
        }
        else if(c==5)//delete
        {
            del();
        }
        else if(c==6)//exit
        {
            exit(0);
        }
        else
        {
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}

//Adding the records in the list
void add()
{
    printf("\n\n");
    int n;
    printf("How many entry do you want to add = ");
    scanf("%d",&n);
    while(n--)
    {
        Slist *ptr = NULL;
        while ((getchar()) != '\n');
        printf("\nEnter patient's Name : ");
        scanf("%[^\n]%*c", name);
        printf("\nEnter symptom : ");
        scanf("%[^\n]%*c", symptom);
        printf("\nEnter the age : ");
        scanf("%d",&age);
        printf("\nEnter cabin no : ");
        scanf("%d",&cabin);
        printf("\nEnter phone number : ");
        scanf("%d",&phone);
        printf("\n");

        ptr = CreateNode(ptr);
        strcpy(ptr->name,name);
        strcpy(ptr->symptom,symptom);
        ptr->serialNo = num;
        ptr->cabin = cabin;
        ptr->phone = phone;
        ptr->age = age;
        Insert(&head,ptr);
        num++;
    }
}

//To view the Inserted records
void view()
{
    if(is_empty(head) == 1)
    {
        printf("List is empty");
        return;
    }
    Slist *np = head;

    LIST_FOREACH(np,head)
    {
        printf("Serial Number : %d\n",np->serialNo);
        printf("Name : %s\n",np->name);
        printf("Symptom : %s\n",np->symptom);
        printf("Cabin no : %d\nPhone number = %d\nAge=%d\n\n",np->cabin,np->phone,np->age);
    }
}


//To edit the inserted record
void edit()
{
    if(is_empty(head) == 1)
    {
        printf("List is empty");
        return;
    }
    int q,p,n = num;
    do
    {
        printf("What do you want to edit ?\n");
        printf("Enter your option\n");
        printf("1.Name\n2.Symptom\n3.Age\n4.Cabin\n5.Phone no.\n6.Exit\n\n");
        printf("Option = ");
        scanf("%d",&q);
        printf("\n\n");

        if(q == 6)
        {
            return;
        }

        Slist *ptr = NULL;
        if(q<=5)
        {
            printf("Enter the serial no of that patient = ");
            scanf("%d",&p);//serial number
            if(p<=(n-1))
            {
                if(q==1)
                {
                    printf("Enter the new name = ");
                    while ((getchar()) != '\n');
                    scanf("%[^\n]%*c", name);
                    LIST_FOREACH(ptr,head)
                    {
                        if(ptr->serialNo == p)
                        {
                            strcpy(ptr->name,name);
                            break;
                        }
                    }

                }
                else if(q==2)
                {
                    printf("Enter the new Symptom = ");
                    while ((getchar()) != '\n');
                    scanf("%[^\n]%*c", symptom);
                    LIST_FOREACH(ptr,head)
                    {
                        if(ptr->serialNo == p)
                        {
                            strcpy(ptr->symptom,symptom);
                            break;
                        }
                    }

                }
                else if(q==3)
                {
                    printf("Enter the new Age = ");
                    scanf("%d",&age);
                    LIST_FOREACH(ptr,head)
                    {
                        if(ptr->serialNo == p)
                        {
                            ptr->age = age;
                            break;
                        }
                    }

                }

                else if(q==4)
                {
                    printf("Enter the new Cabin no = ");
                    scanf("%d",&cabin);

                    LIST_FOREACH(ptr,head)
                    {
                        if(ptr->serialNo == p)
                        {
                            ptr->cabin = cabin;
                            break;
                        }
                    }
                }

                else if(q==5)
                {
                    printf("Enter the new Phone no = ");
                    scanf("%d",&phone);

                    LIST_FOREACH(ptr,head)
                    {
                        if(ptr->serialNo == p)
                        {
                            ptr->phone = phone;
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("\n\nInvalid Serial \nTry Again !!\n\n");
            }
        }
        else
        {
            printf("\n\nInvalid option\nTry Again!!\n\n");
        }
    }
    while(q!=0);

}

//Search the by serialNo,Name,Symptoms,Cabin no,ph. no and age.
void search()
{
    if(is_empty(head) == 1)
    {
        printf("List is empty");
        return;
    }

    int s,h,f;
    Slist *ptr = head;
    char c[30];
    do
    {
        printf("By what do you want to search ?\n");
        printf("1.Serial no.\n2.Name\n3.Symptom\n4.Cabin no.\n5.Phone no.\n6.Age\n7.Exit\n\nOption = ");
        scanf("%d",&h);

        if(h==1)
        {
            printf("Enter Serial number of the patient = ");
            scanf("%d",&s);
            LIST_FOREACH(ptr,head)
            {
                if(ptr->serialNo == s)
                {
                    printf("\n");
                    printf("Serial Number : %d\n",ptr->serialNo);
                    printf("Name : ");
                    puts(ptr->name);
                    printf("Symptom : ");
                    puts(ptr->symptom);
                    printf("Cabin no : %d\nPhone number : %d\nAge : %d",ptr->cabin,ptr->phone,ptr->age);
                    printf("\n\n");
                    break;
                }
                else if(ptr->next == NULL)
                {
                    printf("\n\nEnd of List or Not Found\n\n");
                }
            }
        }
        else if(h==2)
        {
            printf("Enter your name = ");
            while ((getchar()) != '\n');
            scanf("%[^\n]%*c", c);
            LIST_FOREACH(ptr,head)
            {
                if(strcmp(ptr->name, c) == 0)
                {
                    printf("\n");
                    printf("Serial Number : %d\n",ptr->serialNo);
                    printf("Name : ");
                    puts(ptr->name);
                    printf("Symptom : ");
                    puts(ptr->symptom);
                    printf("Cabin no : %d\nPhone number : %d\nAge : %d",ptr->cabin,ptr->phone,ptr->age);
                    printf("\n\n");
                    //break;
                }
                else if(ptr->next == NULL)
                {
                    printf("\n\nEnd of List or Not Found\n\n");
                }
            }


        }
        else if(h==3)
        {
            printf("Enter Symptom = ");
            while ((getchar()) != '\n');
            scanf("%[^\n]%*c", c);
            LIST_FOREACH(ptr,head)
            {
                if(strcmp(ptr->symptom, c) == 0)
                {
                    printf("\n");
                    printf("Serial Number : %d\n",ptr->serialNo);
                    printf("Name : ");
                    puts(ptr->name);
                    printf("Symptom : ");
                    puts(ptr->symptom);
                    printf("Cabin no : %d\nPhone number : %d\nAge : %d",ptr->cabin,ptr->phone,ptr->age);
                    printf("\n\n");
                    //break;
                }
                else if(ptr->next == NULL)
                {
                    printf("\n\nEnd of List or Not Found\n\n");
                }
            }

        }
        else if(h==4)
        {
            printf("Enter Cabin number = ");
            scanf("%d",&f);
            LIST_FOREACH(ptr,head)
            {
                if(ptr->cabin == f)
                {
                    printf("\n");
                    printf("Serial Number : %d\n",ptr->serialNo);
                    printf("Name : ");
                    puts(ptr->name);
                    printf("Symptom : ");
                    puts(ptr->symptom);
                    printf("Cabin no : %d\nPhone number : %d\nAge : %d",ptr->cabin,ptr->phone,ptr->age);
                    printf("\n\n");
                    break;
                }
                else if(ptr->next == NULL)
                {
                    printf("\n\nEnd of List or Not Found\n\n");
                }
            }
        }
        else if(h==5)
        {
            printf("Enter Phone number = ");
            scanf("%d",&f);
            LIST_FOREACH(ptr,head)
            {
                if(ptr->phone == f)
                {
                    printf("\n");
                    printf("Serial Number : %d\n",ptr->serialNo);
                    printf("Name : ");
                    puts(ptr->name);
                    printf("Symptom : ");
                    puts(ptr->symptom);
                    printf("Cabin no : %d\nPhone number : %d\nAge : %d",ptr->cabin,ptr->phone,ptr->age);
                    printf("\n\n");
                    break;
                }
                else if(ptr->next == NULL)
                {
                    printf("\n\nEnd of List or Not Found\n\n");
                }
            }

        }
        else if(h==6)
        {
            printf("Enter Age = ");
            scanf("%d",&f);
            LIST_FOREACH(ptr,head)
            {
                if(ptr->age == f)
                {
                    printf("\n");
                    printf("Serial Number : %d\n",ptr->serialNo);
                    printf("Name : ");
                    puts(ptr->name);
                    printf("Symptom : ");
                    puts(ptr->symptom);
                    printf("Cabin no : %d\nPhone number : %d\nAge : %d",ptr->cabin,ptr->phone,ptr->age);
                    printf("\n\n");
                }
                else if(ptr->next == NULL)
                {
                    printf("\n\nEnd of List or Not Found\n\n");
                }
            }
        }
        else if(h==7)
        {
            return;
        }
        else
            printf("\n\nInvalid input\n\n");

    }
    while(h!=0);

}

//function to delete node or specific value of node/record
void del()
{
    if(is_empty(head) == 1)
    {
        printf("List is empty");
        return;
    }
    int f,h;
    Slist *ptr = head,*np;
    do
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Symptom\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\n7.Exit\n\nOption = ");
        scanf("%d",&h);
        printf("\n");

        void disp()
        {
            printf("\n\nEnter the serial number of the patient that you want to delete = ");
            scanf("%d",&f);
        }

        if(h==1)
        {
            disp();
            deleteNode(&head,f);
        }
        else if(h==2)
        {
            disp();
            LIST_FOREACH(np,head)
            {
                if(np->serialNo == f)
                {
                    strcpy(np->name,"Cleared");
                    break;
                }
            }
        }
        else if(h==3)
        {
            disp();
            LIST_FOREACH(np,head)
            {
                if(np->serialNo == f)
                {
                    strcpy(np->symptom,"Cleared");
                    break;
                }
            }
        }
        else if(h==4)
        {
            disp();
            LIST_FOREACH(np,head)
            {
                if(np->serialNo == f)
                {
                    np->age = 0;
                    break;
                }
            }
        }
        else if(h==5)
        {
            disp();
            LIST_FOREACH(np,head)
            {
                if(np->serialNo == f)
                {
                    np->cabin = 0;
                    break;
                }
            }
        }
        else if(h==6)
        {
            disp();
            LIST_FOREACH(np,head)
            {
                if(np->serialNo == f)
                {
                    np->phone = 0;
                    break;
                }
            }
        }
        else if(h==7)
        {
            return;
        }

    }
    while(h != 0);

}
