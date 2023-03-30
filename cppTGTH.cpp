//CREATED BY EZRA TIGAB  
            


#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct car                 //Global structure Declaration for cars
{
    char name[20];
    char model[20];
    char li_pla_num[20];    //li_pla_num means license plate number
    float max_speed;
    float price;
} info[9],check;   //this check structure vriable is for swappinr during selection top
int num;  //this is ti indicating number of cars
char test[20];     //Global variable declaration for checking different value when we search delete and count number of occurance
float value;          //to take value from the user when we find dlete and cuuont number of occurance
char option[8];    //this variable is for switch  on defferent function
void insertValues();
void read( );
void deleteByIndex();
void delete_the_last( );
void delete_by_condition( );
void find_min_max_speed();    //min_max_speed to express minimum of the car maxium speed
void find_max_price();
void average_price();
void average_max_speed();
void delete_min_price();
void delete_max_price();
void search_by_condition();
void write( );
void display(int);
int count_cars();
void count_occurrence();
void updateValues();
void top();
int main_menu();
inline void arrange(int, int );// This function is to arrange in order to select some tops
inline void say(int,int);   //this function is used to say not found and to tell the done of the tasfind
int data_type_check(int n);  //this function is to check the data type of the input especially for intiger
inline void display_by_Index(int i);   //This function is to display by index number
int main ()
{
    num=count_cars();

    cout<<"\t\t************************************************************\n"
        <<"\t\t* ******************************************************** *\n"
        <<"\t\t* *                WELCOME                               * *\n"
        <<"\t\t* *              TO OUR PROGRAM !!!!!!                   * *\n"
        <<"\t\t* *                                                      * *\n"
        <<"\t\t* ******************************************************** *\n"
        <<"\t\t************************************************************\n\n";

    do
    {
        main_menu();
        cin>>option;
        cin.ignore(1,'\n');

        switch(atoi(option))
        {
        case 1:
            insertValues();
            break;

        case 2:
            read();
            break;

        case 3:
            deleteByIndex();
            break;

        case 4:
            delete_the_last();
            break;

        case 5:
            delete_by_condition();
            break;

        case 6:
            find_min_max_speed();
            break;

        case 7:
            find_max_price();
            break;

        case 8:
            average_max_speed();
            break;

        case 9:
            average_price();
            break;

        case 10:
            delete_min_price();
            break;
        case 11:
            delete_max_price();
            break;

        case 12:
            search_by_condition();
            break;

        case 13:
            cout<<"\n   ****************************DISPLAYING ALL RECORD  ********************************\n\n";
            num=count_cars();
            display(num);
            cout<<"\n\n   **************************************SECTION BREAK***********************************\n";
            break;

        case 14:
            write();
            break;

        case 15:
            cout<<"\n\n   **************************************COUNTIMG NUMBER OF CARS ***********************************\n";
            cout<<"\tNumber of cars is : "<<count_cars()<<endl;
            cout<<"\n\n   **************************************SECTION BREAK***********************************\n";
            break;

        case 16:
            count_occurrence();
            break;

        case 17:
            updateValues();
            break;

        case 18:
            top();
            break;

        case 0:
            cout<<"\tYou are successfully exit\n\n";
            break;
        default:
            cout<<"\tInvalid in put";
        }
    }
    while(atoi(option)!=0);

    return 0;
}
int main_menu()
{
    cout<<"\n  ********************************** MAIN *************************************************"<<endl;
    cout<<"\tHere is the main menu of this program .You can do some task according to the menu\n";
    cout<<"\t\tEnter 1. To Enter Values\n"
        <<"\t\t      2. To to read information of some students from the notepad file   \n"
        <<"\t\t      3. To delete by index information of the car\n"
        <<"\t\t      4. To delete all information of the last car  \n"
        <<"\t\t      5. To delete information of some cars by using some condition\n"
        <<"\t\t      6. To find the information of a car with minimum max_speed\n"
        <<"\t\t      7. To find the information of a car with maximum price \n"
        <<"\t\t      8. To Calculate  average  max_speed of the cars\n"
        <<"\t\t      9. To Calculate average price of all cars\n"
        <<"\t\t      10.To delete all information of a car with minimum price\n"
        <<"\t\t      11.To delete all information of a car with maximum price\n"
        <<"\t\t      12.To Search information of some cars by using some condition\n"
        <<"\t\t      13.To display all information of the cars\n"
        <<"\t\t      14.To add  information of some students to the notepad file \n"
        <<"\t\t      15.To count number of cars\n"
        <<"\t\t      16.To count occurrence\n"
        <<"\t\t      17.To Update the information of some cars \n"
        <<"\t\t      18.To Select some top cars by their attribute\n"
        <<"\t\t      0. Or any other than Natural number To EXIT\n\n\tEnter Option: ->  \n\t---> ";
}
void insertValues( )
{
    cout<<"\n   ****************************INSERTING VALUE  ********************************\n\n";
    num=3;
    cout<<"\n\tPlease Insert the information of cars according to the order\n"<<endl<<"\t";

    for(int i=0; i<num; i++)
    {
        cout<<"\n\tPlease enter name of car "<<i+1<<"\n\t---> ";
        cin.getline(info[i].name,13);

        cout<<"\n\tEnter  model of the car\n\t---> ";
        cin.getline(info[i].model,13);

        cout<<"\n\tEnter  license number of the car\n\t---> ";
a:
        cin.getline(info[i].li_pla_num,13);

        for(int j=0; j<i; j++)
        {
            if(stricmp(info[i].li_pla_num,info[j].li_pla_num)==0)
            {
                cout<<"\tThe number you entered is token before please enter an other number \n\t---> ";
                goto a;      //this is to check weather the license plate number is taken before or not taken to make it unique
            }
        }
        do 	                                    //This is to make the price expected and to check its data type
        {
            cout<<"\n\tEnter  price of the car in  USA DOLLAR which is greater than $150\n\t---> ";
            cin>>info[i].price;

        }
        while(data_type_check(info[i].price)!=0||info[i].price<=150);

        do                                      //This is to make the max speed expected and to check its data type
        {
            cout<<"\n\tPlease enter maximum speed of the car\n\t---> ";
            cin>>info[i].max_speed;

        }
        while(data_type_check(info[i].max_speed)!=0||info[i].max_speed<=0);

    }
    cout<<"\n\tThe information of the car is Inserted...  Successfully \n\n\t";
    cout<<"The information of the cars you entered is :\n\n";
    num=count_cars();
    display(num);

}
void display(int num )
{
    int count1=0;                 //this counter variable is count3 is to check weather there is record or not
    for(int i=0; i<num; i++)               // and to display once those attributes like name  ,model... on the screen
    {
        if (info[i].name)
        {
            count1++;
            if (count1==1)
            {
                cout<<"\t______________________________________________________________________\n";
                cout<<"\t Name          model         number        price        max_speed \n";
                cout<<"\t______________________________________________________________________\n\t";
            }
            display_by_Index(i);
        }
    }
    if(!count1)
    {
        cout<<"\n\tThere is no any record available\n";
        cout<<" \t______________________________________________________________________\n\t";

    }
}
void deleteByIndex()
{
    cout<<"\n  ****************************DELETING BY ORDER NUMBER ********************************\n\n";
    int index;                                 /*At this index means not the same as index of array we use an index
                                           to express the number which the car exist*/
    if(num) //this condition is to check weather there is a record or not
    {
        do
        {
            num=count_cars();
            cout<<"\n\tEnter a valid Number which the car exist To delete  :\n\t---> ";
            cin>>index;
        }
        while(data_type_check(index)!=0 || index>=num || index<=0);
        index-=1;      //here is to get the array index number
        for(int i=0; i<num; i++)
        {
            if(i==index)
            {
                for(int j=i; j<num; j++)
                {
                    info[j]=info[j+1];
                }
                break;
            }
        }
        cout<<"\n\tYou have deleted...  Successfully "<<endl;
        num=count_cars();
        display(num);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  *******************************SECTION BREAK**********************************\n\n\n";

}
void updateValues()
{
    num=count_cars();
    cout<<"\n  ***************** UPDATIMG INFORMATION OF CARS ***********************************\n\n";
    if(num)
    {
        do
        {
            cout<<"\t\tWhat you want to update ? \n";
            cout<<"\t\tEnter  1. To update name\n"
                <<"\t\t       2. To update model\n"
                <<"\t\t       3. To update number\n"
                <<"\t\t       4. To update price\n"
                <<"\t\t       5. To update max_speed\n"
                <<"\t\t       6. To see the information of the cars\n"
                <<"\t\t       7. To return to the main menu\n\n\tEnter Option: ->  \n\t";
            cin>>option;
            cin.ignore(1,'\n');

            switch (atoi(option))
            {
            case 1:
                for(int i=0; i<num; i++)
                {
                    cout<<"\n\tPlease enter the new name of car "<<i+1<<"\n\t";
                    cin.getline(info[i].name,13);
                }
                cout<<"\n\tYou have updated successfully\n";
                cout<<"\t_____________________________________________________________________\n\t";
                break;

            case 2:
                for(int i=0; i<num; i++)
                {
                    cout<<"\n\tPlease enter the new model of car "<<i+1<<"\n\t";
                    cin.getline(info[i].model,13);
                }
                cout<<"\n\tYou have updated successfully\n";
                cout<<"\t_____________________________________________________________________\n\t";
                break;

            case 3:
                for(int i=0; i<num; i++)
                {
                    cout<<"\n\tPlease enter the new license plate number of car "<<i+1<<"\n\t";
c:
                    cin.getline(info[i].li_pla_num,13);

                    for(int j=0; j<i; j++)
                    {
                        if(!stricmp(info[j].li_pla_num,info[i].li_pla_num))
                        {
                            cout<<"\n\tThe number you entered is token before please enter an other number \n\t";
                            goto c;     //to make license plate number unique across the program
                        }
                    }
                }

                cout<<"\n\tYou have updated successfully\n";
                cout<<"\t_____________________________________________________________________\n\t";
                break;

            case 4:
                for(int i=0; i<num; i++)
                {
                    do 	                                                         //This is to make the price expected and to check its data type
                    {
                        cout<<"\n\tPlease enter  valid price of  car "<<i+1<<" in  USA DOLLAR which is greater than $150\n\t";
                        cin>>info[i].price;

                    }
                    while(data_type_check(info[i].price)!=0||info[i].price<=150);

                }

                cout<<"\n\tYou have updated successfully\n";
                cout<<"\t_____________________________________________________________________\n\t";
                break;

            case 5:
                for(int i=0; i<num; i++)
                {
                    do                         //This is to make the max speed expected and to check its data type
                    {
                        cout<<"\n\tPlease enter valid  maximum speed of car "<<i+1<<"\n\t";
                        cin>>info[i].max_speed;
                    }
                    while(data_type_check(info[i].max_speed)!=0||info[i].max_speed<=0);
                }
                cout<<"\n\tYou have updated successfully\n\n";
                cout<<"\t_____________________________________________________________________\n\t";
                break;
            case 6:
                cout<<"\n_______________________ALL INFORMATION OF THE CARS_______________________\n"<<endl;
                display(num);
                break;

            case 7:
                cout<<"\n\tYou are successfully return to the main menu\n";
                break;

            default:
                cout<<"\n\tInvalid input please enter valid number \n\n";
                break;
            }

        }
        while(atoi(option)!=7);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  *******************************SECTION BREAK*************************************\n\n\n";
}
void search_by_condition( )
{
    num=count_cars();
    cout<<"\n  *************************** SEARCHING  CARS BY THIER ATTRIBUTE *************************\n\n";
    if(num)
    {
        do
        {
            int count3=0;       //this counter variable is for weather we search is found or not and to display the attribute once
            cout<<"\t\tBy what you want to search ? \n"
                <<"\t\tEnter  1.To search by name \n"
                <<"\t\t       2.To search by model\n"
                <<"\t\t       3.To search by license plate number \n"
                <<"\t\t       4.To search by price\n"
                <<"\t\t       5.To search by max_speed\n"
                <<"\t\t       6.To return to the main menu\n\n\tEnter Option: ->  \n\t---> ";
            cin>>option;
            cin.ignore(1,'\n');

            switch (atoi(option))
            {
            case 1:
                cout<<"\n\tEnter the name you want to search\n\t---> ";
                cin.getline(test,15);
                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].name,test)==0)
                    {
                        count3++;
                        if (count3==1)
                        {
                            cout<<"\n\tThe information of cars you searched is :\n\n";
                            cout<<"\t______________________________________________________________________\n";
                            cout<<"\t Name          model         number        price        max_speed \n";
                            cout<<"\t______________________________________________________________________\n\t";
                        }                      /*here is condition to avoid the out put Name      model     number   price  max_speed
                                                  on the screen repeatedly and when there is no value we search */
                        display_by_Index(i);
                    }
                }
                if(!count3)
                {
                    cout<<"\n\t\tSorry not found\n\n";
                }
                break;

            case 2:
                cout<<"\n\tEnter model of the car you want to find \n\t---> ";
                cin.getline(test,15);

                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].model,test)==0)
                    {
                        count3++;
                        if (count3==1)
                        {
                            cout<<"\n\tThe information of cars you searched is :\n\n";
                            cout<<"\t______________________________________________________________________\n";
                            cout<<"\t Name          model         number        price        max_speed \n";
                            cout<<"\t______________________________________________________________________\n\t";
                        }
                        display_by_Index(i);
                    }
                }
                if(!count3)
                {
                    cout<<"\n\t\tSorry not found\n\n";
                }
                break;

            case 3:
                cout<<"\n\tEnter the number of the car you want to  search\n\t---> ";
                cin.getline(test,15);

                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].li_pla_num,test)==0)
                    {
                        count3++;
                        if (count3==1)
                        {
                            cout<<"\n\tThe information of cars you searched is :\n\n";
                            cout<<"\t______________________________________________________________________\n";
                            cout<<"\t Name          model         number        price        max_speed \n";
                            cout<<"\t______________________________________________________________________\n\t";
                        }
                        display_by_Index(i);
                    }
                }
                if(!count3)
                {
                    cout<<"\n\t\tSorry not found\n\n";
                }
                break;

            case 4:
                do
                {
                    cout<<"\n\tEnter valid price of the car in US DOLLAR which is greater than 150$ you want to  search\n\t---> ";
                    cin>>value;

                }
                while(data_type_check(value)!=0||value<=150);

                for(int i=0; i<num; i++)
                {
                    if (info[i].price==value)
                    {
                        count3++;
                        if (count3==1)
                        {
                            cout<<"\n\tThe information of cars you searched is :\n\n";
                            cout<<"\t______________________________________________________________________\n";
                            cout<<"\t Name          model         number        price        max_speed \n";
                            cout<<"\t______________________________________________________________________\n\t";
                        }
                        display_by_Index(i);
                    }
                }
                if(!count3)
                {
                    cout<<"\n\t\tSorry not found\n\n";
                }
                break;

            case 5:
                do
                {
                    cout<<"\n\tEnter the maximum speed of the car you want to  search\n\t---> ";
                    cin>>value;
                }
                while(data_type_check(value)!=0||value<=0);

                for(int i=0; i<num; i++)
                {
                    if (info[i].max_speed==value)
                    {
                        count3++;
                        if (count3==1)
                        {
                            cout<<"\n\tThe information of cars you searched is :\n\n";
                            cout<<"\t______________________________________________________________________\n";
                            cout<<"\t Name          model         number        price        max_speed \n";
                            cout<<"\t______________________________________________________________________\n\t";
                        }
                        display_by_Index(i);                                                        /*here if condition to avoid the out put Name      model     number   price  max_speed                                                                               on the screen repeatedly and when there is no value we search */
                    }
                }
                if(!count3)
                {
                    cout<<"\n\t\tSorry not found\n\n";
                }
                break;

            case 6:
                cout<<"\n\tYou are successfully return to the main menu\n";
                break;

            default:
                cout<<"\n\tINVALID INPUT please enter  valid number with the request\n\n";
            }
        }
        while(atoi(option)!=6);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }

    cout<<"\n\n  ***************************************SECTION BREAK**********************************\n\n\n";

}
void delete_by_condition()
{
    num=count_cars();
    cout<<"  ******************************  DELETING INFORMATIION OF CARS *******************************\n\n";
    if(num)
    {
        do
        {
            int count1=0;         //here counter variable is to check what we enter weather found or not found
            cout<<"\n\t\tBy what you want to delete \n"
                <<"\t\tEnter  1.To delete by name \n"
                <<"\t\t       2.To delete by model\n"
                <<"\t\t       3.To delete by license plate number \n"
                <<"\t\t       4.To delete by price\n"
                <<"\t\t       5.To delete by max_speed\n"
                <<"\t\t       6.To see the information of cars\n"
                <<"\t\t       7.To return to the main menu\n\n\tEnter Option: ->  \n\t---> ";
            cin>>option;
            cin.ignore(1,'\n');

            switch (atoi(option))
            {
            case 1:
                cout<<"\n\tEnter name of the car you want to  delete\n\t---> ";
                cin.getline(test,13);

                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].name,test)==0)
                    {
                        count1++;
                        for(int j=i; j<num; j++)
                        {
                            info[j]=info[j+1];
                        }
                        i--;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t\t you have deleted "<<count1<<" cars information successfully \n\t";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 2:
                cout<<"\n\tEnter model  of the car  you want to  delete\n\t---> ";
                cin.getline(test,13);

                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].model,test)==0)
                    {
                        count1++;
                        for(int j=i; j<num; j++)
                        {
                            info[j]=info[j+1];
                        }
                        i--;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t\t you have deleted "<<count1<<" cars information successfully \n\t";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 3:
                cout<<"\n\tEnter license plate number of the car  you want to  delete\n\t---> ";
                cin.getline(test,13);

                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].li_pla_num,test)==0)
                    {
                        count1++;
                        for(int j=i; j<num; j++)
                        {
                            info[j]=info[j+1];
                        }
                        i--;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t\t you have deleted "<<count1<<" cars information successfully \n\t";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 4:
                do
                {
                    cout<<"\n\tEnter valid price of the car in US DOLLAR which is greater than 150$ you want to  delete the car which it have\n\t---> ";
                    cin>>value;

                }
                while(data_type_check(value)!=0||value<=150);

                for(int i=0; i<num; i++)
                {
                    if (info[i].price==value)
                    {
                        count1++;
                        for(int j=i; j<num; j++)
                        {
                            info[j]=info[j+1];
                        }
                        i--;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t\t you have deleted "<<count1<<" cars information successfully \n\t";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 5:
                do
                {
                    cout<<"\n\tEnter the maximum speed of the car you want to  delete\n\t---> ";
                    cin>>value;
                }
                while(data_type_check(value)!=0||value<=0);

                for(int i=0; i<num; i++)
                {
                    if (info[i].max_speed==value)
                    {
                        count1++;
                        for(int j=i; j<num; j++)
                        {
                            info[j]=info[j+1];
                        }
                        i--;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t\t you have deleted "<<count1<<" cars information successfully \n\t";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 6:
                num=count_cars();
                display(num);
                break;

            case 7:
                cout<<"\n\tYou are successfully return to the main menu\n";
                break;

            default:
                cout<<"\n\tPlease enter valid number with the request\n";
            }
        }
        while(atoi(option)!=7);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  *********************************SECTION BREAK***********************************\n\n\n\n";

}
void count_occurrence()
{
    num=count_cars();
    cout<<"  ********************************** countING  OCCURANCE *****************************\n\n";
    if(num)
    {
        do
        {
            int count1=0;             //this counter variable is to check weather the option is found or not found and to count the number of value what we get
            cout<<"\n\t\tEnter 1.  To count by occurrence of name \n"
                <<"\t\t      2.  To count by occurrence of model\n"
                <<"\t\t      3.  To count by occurrence of license plate number\n"
                <<"\t\t      4.  To count by occurrence of their price \n"
                <<"\t\t      5.  To count by occurrence of their maximum speed \n"
                <<"\t\t      6.  To return to the main menu\n\n\tEnter Option: ->  \n\t---> ";

            cin>>option;
            cin.ignore(1,'\n');

            switch (atoi(option))
            {
            case 1:
                cout<<"\n\tEnter the name of the car\n\t---> ";
                cin.getline(test,13);

                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].name,test)==0)
                    {
                        count1++;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t"<<count1<<" cars have this name \n\n";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 2:
                cout<<"\n\tEnter model of  the car\n\t---> ";
                cin.getline(test,13);
                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].model,test)==0)
                    {
                        count1++;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t"<<count1<<" car have model of  "<<test<<"\n\n";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 3:
                cout<<"\n\tEnter license plate number of  the car\n\t---> ";
                cin.getline(test,13);
                for(int i=0; i<num; i++)
                {
                    if (stricmp(info[i].li_pla_num,test)==0)
                    {
                        count1++;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t"<<count1<<" car have license plate number  "<<test<<" \n\n";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 4:
                do
                {
                    cout<<"\n\tEnter valid price of the car in US DOLLAR which is greater than 150$ you want to count\n\t---> ";
                    cin>>value;

                }
                while(data_type_check(value)!=0||value<=150);

                for(int i=0; i<num; i++)
                {
                    if (info[i].price==value)
                    {
                        count1++;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t"<<count1<<" cars have price of "<<value<<"\n\n";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 5:
                count1=0;
                do
                {
                    cout<<"\n\tEnter the maximum speed of the car you want to  delete\n\t---> ";
                    cin>>value;
                }
                while(data_type_check(value)!=0||value<=0);

                for(int i=0; i<num; i++)
                {
                    if (info[i].max_speed==value)
                    {
                        count1++;
                    }
                }
                if(count1)
                {
                    cout<<"\n\t"<<count1<<" number of cars have maximum speed "<<value<<"\n\n";
                }
                else
                {
                    cout<<"\n\t\tSorry not found \n\t";
                }
                break;

            case 6:
                cout<<"\n\tYou are successfully returned to the main menu\n";
                break;

            default:
                cout<<"\n\tINVALID INPUT please enter valid input\n\n";
            }

        }
        while(atoi(option)!=6);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  **************************************SECTION BREAK*********************************\n\n\n";

}
void find_min_max_speed()
{
    num=count_cars();
    cout<<"\n  **************************SEARCHING CAR WITH MINMUM MAX_SPEED***************************\n\n";
    int k=info[0].max_speed,count3=0; //this counter variable is to avoid many times displaying the attribute like name, model ....on the screen
    if(num)
    {
        for(int i=0; i<num; i++)
        {
            if (0<info[i].max_speed&&info[i].max_speed<k)
            {
                k=info[i].max_speed;
            }
        }
        for(int i=0; i<num; i++)
        {
            if(info[i].max_speed==k)
            {
                count3++;
                if (count3==1)
                {
                    cout<<"\t______________________________________________________________________\n";
                    cout<<"\t Name          model         number        price        max_speed \n";
                    cout<<"\t______________________________________________________________________\n\t";
                }
                display_by_Index(i);
            }
        }
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  *******************************SECTION BREAK***************************************\n\n\n";

}
void find_max_price()
{
    num=count_cars();
    cout<<"\n  **************************** SEARCHING CAR WITH  MAXIMUM PRICE ***********************\n\n";
    int k=info[0].price,count3=0;   //this counter variable is to avoid many times displaying the attribute like name, model ....on the screen
    if(num)
    {
        for(int i=0; i<num; i++)
        {
            if (info[i].price>k)
            {
                k=info[i].price;
            }
        }
        for(int i=0; i<num; i++)
        {
            if(info[i].price==k)
            {
                count3++;
                if (count3==1)
                {
                    cout<<"\t______________________________________________________________________\n";
                    cout<<"\t Name          model         number        price        max_speed \n";
                    cout<<"\t______________________________________________________________________\n\t";
                }
                display_by_Index(i);
            }
        }
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  ****************************************SECTION BREAK*********************************\n\n\n";

}

int count_cars( )
{
    int count4=-1;     //thia counter variable is to count number of cars
    do
    {
        count4++;
    }
    while(strcmp(info[count4].name,""));

    return count4;
}
void average_price()
{
    num=count_cars();
    cout<<"\n  ********************************** CALCULATING average PRICE *****************************\n\n";
    int sum=0;//this counter variable is to count number of cars
    float average;
    if(num)
    {
        for(int i=0; i<num; i++)
        {
            if( info[i].price >0)
            {
                sum += info[i].price;
            }
        }
        average =sum*1.0/num*1.0;
        cout<<"\n\tThe average of the price of the cars is : ";
        cout<<average<<endl;
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  *******************************************SECTION BREAK*********************************\n\n\n";

}
void  top( )
{
    num=count_cars();
    cout<<"\n  ************************************SEARCHIMG THE TOP CAR  *******************************\n\n";
    int size;              //this variable is to take number of the top cars
    if(num)
    {

        do
        {
a:
            cout<<"\n\tBy what you want to select the top student\n"
                <<"\t\tEnter 1.to select by name\n"
                <<"\t\t      2.To select by model \n"
                <<"\t\t      3.To select by number \n"
                <<"\t\t      4.To select by price \n"
                <<"\t\t      5.To select by max_speed \n"
                <<"\t\t      6.To return to thr main menu\n\n\tEnter Option: ->  \n\t---> ";

            cin>>option;
            cin.ignore(1,'\n');

            switch(atoi(option))
            {
            case 1:
                for(int i=0; i<num; i++)
                {
                    for(int j=i+1; j<num; j++)
                    {
                        if (stricmp(info[i].name,info[j].name)>0)
                        {
                            arrange(i,j);    //call function to arrange
                        }
                    }
                }
                break;

            case 2:
                for(int i=0; i<num; i++)
                {
                    for(int j=i; j<num; j++)
                    {
                        if ((stricmp(info[i].model,info[j].model))>0)
                        {
                            arrange(i,j);
                        }
                    }
                }
                break;

            case 3:
                for(int i=0; i<num; i++)
                {
                    for(int j=i; j<num; j++)
                    {
                        if ((stricmp(info[i].li_pla_num,info[j].li_pla_num))>0)
                        {
                            arrange(i,j);
                        }
                    }
                }
                break;
            case 4:
                for(int i=0; i<num; i++)
                {
                    for(int j=i; j<num ; j++)
                    {
                        if ((info[i].price<info[j].price))
                        {
                            arrange(i,j);
                        }
                    }
                }
                break;

            case 5:
                for(int i=0; i<num; i++)
                {
                    for(int j=i+1; j<num ; j++)
                    {
                        if ((info[i].max_speed<info[j].max_speed))
                        {
                            arrange(i,j);
                        }
                    }
                }
                break;

            case 6:
                cout<<"\n\tYou are successfully return to the main menu\n";
                break;

            default :
                cout<<"\n\tINVALID INPUT please enter valid input\n";
                goto a;       //this is for default value to return up  and not enter to the display condition when it get default value
            }

            if(atoi(option)!=6)
            {
                do
                {
                    cout<<"\n\tPlease enter the number of cars you want \n\t---> ";
                    cin>>size;
                }
                while(data_type_check(size)!=0);

                cout<<"\n\t___________________ THE TOP "<<size<<" CAR INFORMATION ___________________\n\n";
                display(size);
                cout<<"\n\t_________________________________END____________________________________\n\n";
            }
        }
        while(atoi(option)!=6);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n*  ***************************************SECTION BREAK*********************************\n\n\n";

}
void  delete_max_price( )
{
    num=count_cars();
    cout<<"\n  ***********************************DELETING MAX PRICE ***********************************\n\n";
    int k=info[0].price;
    if(num)
    {
        for(int i=0; i<num; i++)
        {
            if (info[i].price>k)
            {
                k=info[i].price;
            }
        }

        for(int i=0; i<num; i++)
        {
            if(k==info[i].price)
            {
                for(int j=i; j<num; j++)
                {
                    info[j]=info[j+1];
                }
                i--;
            }
        }

        cout<<"\n\tYou have successfully deleted\n\n";
        num=count_cars();
        display(num);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  *******************************************SECTION BREAK********************************\n\n\n";
}
void average_max_speed()
{
    num=count_cars();
    cout<<"\n  *************************************CALCULATING average MAX SPEED ******************************\n\n";
    int sum=0, count1=0;//this counter variable is to count number of cars
    float average;
    if(num)
    {
        for(int i=0; i<=num; i++)
        {
            if(info[i].max_speed>0)
            {
                sum+=info[i].max_speed;
                count1++;
            }
        }
        average =sum*1.0/count1*1.0;

        cout<<"\tThe average of the max_speed of the cars is :";
        cout<<average<<"\n";
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  ******************************************SECTION BREAK*********************************\n\n\n";

}
void  delete_min_price( )
{
    num=count_cars();
    cout<<"  ************************************DELETING MIN PRICE **********************************\n\n";
    int k=info[0].price;
    if(num)
    {
        for(int i=0; i<num; i++)
        {
            if (info[i].price<k&&info[i].price>0)
            {
                k=info[i].price;
            }
        }

        for(int i=0; i<num; i++)
        {
            if(k==info[i].price&&k!=0)
            {
                for(int j=i; j<num; j++)
                {
                    info[j]=info[j+1];
                }
                i--;
            }
        }
        cout<<"\n\tYou have successfully deleted\n\n";
        num=count_cars();
        display(num);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  ************************************ SECTION BREAK **********************************\n\n\n";

}
void delete_the_last( )
{
    num=count_cars();
    cout<<"  ***************************************DELETING THE LAST CAR *******************************\n\n";
    if(num)
    {
        for(int i=num-1; i>=0; i--)
        {
            if(info[i].price!=0)
            {
                info[i]=info[i+1];
                break;
            }
        }
        cout<<"\tValues deleted...  Successfully "<<endl;
        num=count_cars();
        display(num);
    }
    else
    {
        cout<<"\n\t\t Sorry there is no any record  \n";
    }
    cout<<"\n\n  ******************************************SECTION BREAK***********************************\n\n\n";
}
void read( )
{
    cout<<"\n  **********************************READING FROM THE FILE  ***********************************\n\n";
    num=count_cars();
    int count1 = 0;
    ifstream filein;
    filein.open("cars.txt");
    cout<<"\tHere is the information of the cars from notepad file\n";
    for(int i=num; i<num+5-count1; i++)
    {
        filein.getline(info[i].name,20);
        filein.getline(info[i].model,23);
        filein.getline(info[i].li_pla_num,23);

        filein>>info[i].price;
        filein>>info[i].max_speed;
        for(int j=0; j<i; j++)
        {
            if(!stricmp(info[j].li_pla_num,info[i].li_pla_num))
            {
                i--;
                count1++;
            }
        }
        filein.ignore(1,'\n');
    }
    filein.close();

    num=count_cars();
    if(count1)
    {
        cout<<"\n\t"<<count1<<"  Record not read due to duplicated license number"<<endl;
    }
    display(num);
    cout<<"\n\n  *****************************************SECTION BREAK************************************\n\n\n";

}
void write( )
{
    cout<<"  ************************************WRITING TI THE FILE ***********************************\n\n";
    ofstream fileout;
    fileout.open("cars.txt");
    num=count_cars();
    for(int i=0; i<num; i++)
    {
        fileout<<info[i].name<<"\n";
        fileout<<info[i].model<<"\n";
        fileout<<info[i].li_pla_num<<"\n";
        fileout<<info[i].price<<"\n";
        fileout<<info[i].max_speed<<"\n";
    }
    fileout.close();

    cout<<" \tValues are Inserted...  Successfully to the notepad file"<<endl;
    cout<<"\n\n  ******************************************SECTION BREAK**********************************\n\n\n";

}
void arrange(int i, int j)
{
    check=info[i];                         //this function is to arrange arrows when it called during selection the top
    info[i]=info[j];                         //and to avoid  many times writing the swapping statements in different condition
    info[j]=check;
}
int data_type_check(int n)
{
    bool condi;
    int x;
    condi=cin.fail();                    //this function check the data type especially for intiger
    x=condi;
    cin.clear();
    cin.ignore(3,'\n');
    return x;
}
void display_by_Index(int i)
{
    cout<<"|"<<left<<setw(13)<<info[i].name;
    cout<<"|"<<left<<setw(13)<<info[i].model;                  //this function is to display the information by index when it called
    cout<<"|"<<left<<setw(13)<<info[i].li_pla_num;             //to avoid writing many times those display statement
    cout<<"|"<<left<<setw(13)<<info[i].price;
    cout<<"|"<<left<<setw(13)<<info[i].max_speed;
    cout<<endl<<"\t";
    cout<<"|-------------|-------------|-------------|-------------|-------------|\n\t";
}










