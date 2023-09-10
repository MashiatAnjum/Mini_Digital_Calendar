#include <iostream>
#include <string>
using namespace std;
struct node{
    string R_title;
    string R_description;
    int date;
    string month;
    node *next;
};
node* n = NULL;
void print(string month)      //travel 1st element untill last to print
{   node *temp=n;
    cout<<"\nReminder List of "<<month<<" : "<<endl;
    while(temp!=NULL){
    if(temp->month==month){
        cout<<endl;
        cout<<"Reminder title: "<<temp->R_title<<endl;
        cout<<"Reminder description: "<<temp->R_description<<endl;
        cout<<"Date: "<<temp->date<<endl;
        cout<<"Month: "<<temp->month<<endl;}
        temp=temp->next;     //updating to shift to next element
    }
}
void addNode(string title, string description, int date, string month){

 if (n==NULL){
    n=new node;
    n->R_title=title;
    n->R_description=description;
    n->date=date;
    n->month=month;
    n->next=NULL;
 }
 else{
    node *temp=n;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *last= new node;
    last->R_title=title;
    last->R_description=description;
    last->date=date;
    last->month=month;
    last->next=NULL;
    temp->next=last;
 }
}

void search_modifyNode(string title, int date, string month, string m_title, string m_description, int m_date, string m_month)
{
        node *temp=n;
        while(temp!=NULL){
        if(temp->date==date && temp->R_title==title && temp->month==month){
        temp->R_title=m_title;
        temp->R_description=m_description;
        temp->date=m_date;
        temp->month=m_month;}
        temp=temp->next;}
}
void removeNode(string title, int date, string month)
{
    if(n->date==date && n->R_title==title && n->month==month){       //removing 1st element
        node* cancel=n;
        n=n->next;
        delete cancel;
        return;
    }
    else{
    node *temp=n;
    while(temp->next!=NULL){
        if(temp->next->date==date && temp->next->R_title==title && temp->next->month==month){
            node *cancel=temp->next;
            temp->next=temp->next->next;
            delete cancel;}

        else temp=temp->next;
            }
        }
}
// checking the starting date
int the_begning_day (int value)
{
    int starting_day_number;
    if (value == 0) {
    starting_day_number = 1;
    }
    else if (value == 1){
    starting_day_number = 2;
    }
    else if (value == 2){
    starting_day_number = 3;
    }
    else if (value == 3){
    starting_day_number = 4;
    }
    else if (value == 4){
    starting_day_number = 5;
    }
    else if (value == 5) {
    starting_day_number = 6;
    }
    else if (value== 6){
    starting_day_number = 0;
        }
    return starting_day_number;
}


int Calender_row (int D_C_value, int D_N_value)//c=count,n=number
{
    //Rows for each month
    int row;
    if(D_C_value>=30){
        if (D_N_value==5 && D_C_value == 30){
            row = 5;
        }
        else if (D_N_value==5 && D_C_value == 31){
            row = 6;
        }
        else if (D_N_value==6 && (D_C_value == 31 || D_C_value == 30)){
            row = 6;
        }
        else row  = 5;
    }
    else{
        if (D_N_value == 0 && D_C_value==28) row = 4;
        else row = 5;
    }
    return row;
}

int Calender_column (int i, int row, int D_C_Value, int D_N_Value)
{
    //Columns for each month
    int column = 7;
    int remain_day;
    remain_day = (D_C_Value - (column-D_N_Value))%7;
    if(i==0){
    column = column-D_N_Value;
    }
    else if (i==row-1){
        if(remain_day==0){
                column = 7;
        }
        else if(remain_day==1){
                column = 1;
        }
        else if(remain_day==2){
                column = 2;
        }
        else if(remain_day==3){
                column = 3;
        }
        else if(remain_day==4){
                column = 4;
        }
        else if(remain_day==5){
                column = 5;
        }
        else if(remain_day==6){ column = 6;
        }
    }
    else column = 7;
    return column;
}


int Leap_year (int year)
{
    // check the year is leap year or not
    int Month_feb = 28;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                 Month_feb = 29;
        }
        else
            Month_feb = 29;
    }
    return Month_feb;
}


int The_calendar(int starting_day, string month, int day_count)
{
    int row, column=7;
    int Ending_day;

    row = Calender_row(day_count, starting_day);
    int** Jan = new int*[row];

    for (int i = 0; i < row; i++){
        column = Calender_column(i, row, day_count, starting_day);
        Jan[i] = new int [column];
    }
    //Setting dates
    column = 7;
    int day = 1;
    for (int i = 0; i < row; i++){
        column = Calender_column(i, row, day_count, starting_day);
        for (int j = 0; j < column; j++){
            Jan[i][j] = day;
            day++;
        }
    }
    //printing
    column = 7;
    cout << "------------" << month << "-------------" << endl;
    cout<< "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    for (int i = 0; i < row; i++){
        column = Calender_column(i, row, day_count, starting_day);
        if(i==row-1) Ending_day = column-1; //last day of the month

        for (int j = 0; j < column; j++){
            if(i==0&&j==0&&column<7){
                if(starting_day==1){
                        cout <<string( 5, ' ' );
                }
                else if(starting_day==2){
                        cout <<string( 10, ' ' );
                }
                else if(starting_day==3){
                        cout <<string( 15, ' ' );
                }
                else if(starting_day==4){
                        cout <<string( 20, ' ' );
                }
                else if(starting_day==5){
                        cout <<string( 25, ' ' );
                }
                else{ cout<<string( 30, ' ' );
                }
            }
            if(n==NULL)
                {cout<< Jan[i][j];
                if(Jan[i][j]<10){
                    cout << "    ";}
                else cout << "   ";}
            else{                                   //for printing *
            node *temp=n;
            while(temp!=NULL){
                if(Jan[i][j]==temp->date && month==temp->month)
                cout <<"\b*";
                temp=temp->next;}
                cout<< Jan[i][j];
                if(Jan[i][j]<10){
                cout << "    ";}
                else cout << "   ";
                }
        }
        cout << endl;
    }
    for (int i = 0; i < row; i++){
            delete [] Jan[i];}
            delete [] Jan;
    cout << endl << endl;
    return Ending_day;
}
void Remainder_Menu()
{
    string title, description,month;
    int date;
    int option;

    do{
    cout<<"\nSelect an option (1-4) : ";
    cin>>option;

    if(option==1){
                cout<<"Reminder title: ";
                cin.ignore();
                getline(cin,title);

                cout<<"Reminder description: ";
                getline(cin,description);

                cout<<"Date: ";
                cin>>date;
                cout<<"Month: ";
                cin>>month;
                addNode(title,description,date,month);
            }
        else if(option==2){
                if(n!=NULL){
                cout<<"Search Reminder title to modify: ";
                cin.ignore();
                getline(cin,title);

                cout<<"Search Date to modify: ";
                cin>>date;
                cout<<"Search Month to modify: ";
                cin>>month;
                cout<<"Enter Updates: \n";
                string m_title, m_description;
                int m_date;
                string m_month;
                cout<<"Reminder Title Update: ";
                cin.ignore();
                getline(cin,m_title);
                 cout<<"Reminder description Update: ";
                getline(cin,m_description);
                cout<<"Date Update: ";
                cin>>m_date;
                cout<<"Month Update: ";
                cin>>m_month;

                search_modifyNode(title,date,month,m_title,m_description,m_date,m_month);}
            else cout<<"\nNothing in list to update\n";
        }
        else if(option==3){
                if(n!=NULL){
                cout<<"Reminder title to be removed: ";
                cin.ignore();
                getline(cin,title);

                cout<<"Date to be removed: ";
                cin>>date;
                cout<<"Month to be removed: ";
                cin>>month;
                removeNode(title,date,month);}
                else cout<<"\nNothing in list to remove\n";
        }
        else if(option==4){
            cout<<"Which Month's remainder to be displayed: ";
            cin>>month;
            print(month);
            }
        else return;
    }while(option!=0);
}
int main()
{

    // Taking inputs from the users
    cout << " Input Month Name and Day Name using small letters " << endl;
    cout<<endl;
    int year;
    string start_day;
    cout << "Enter Year: ";
    cin >> year;
    cout<<endl;
    cout << "Enter the starting day of the year: ";
    cin >> start_day;
    cout << endl;
    cout << "Output: " << endl;
    cout<<endl;

   //First Day of the Year
    int strting_date = 0;
    if(start_day=="sunday"){
      strting_date = 0;
    }
    else if(start_day=="monday"){
            strting_date = 1;
    }
    else if(start_day=="tuesday"){
            strting_date = 2;
    }
    else if(start_day=="wednesday"){
            strting_date = 3;
    }
    else if(start_day=="thursday"){
            strting_date= 4;
    }
    else if(start_day=="friday"){
            strting_date = 5;
    }
    else {
            strting_date = 6;
    //Printing the Calender
    cout << "\t     " << year<< endl;
    cout<<endl;
    }
    string month[12]={"january","february","march","april","may","june","july","august","september","october","november","december"};
    int last_day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    last_day[1]=Leap_year(year);
    int New_Strting_Day;
    for(int i=0;i<12;i++){
        if(i==0)
        New_Strting_Day = The_calendar(strting_date,month[i],last_day[i]);
        else
        New_Strting_Day = The_calendar(the_begning_day(New_Strting_Day),month[i],last_day[i]);
    }

    cout << "------------****Remainder****-------------" << endl<<endl;
    cout<<"Press (1) to Add reminder"<<endl;
    cout<<"Press (2) to Update reminder"<<endl;
    cout<<"Press (3) to Delete a specific reminder"<<endl;
    cout<<"Press (4) to View all the reminders of a specific month"<<endl;
    cout<<"Press (0) to Exit and show Updated Calendar "<<endl;
    Remainder_Menu();

     cout << "\n\n------------****Updated Calender****-------------" << endl<<endl;
        for(int i=0;i<12;i++){
        if(i==0)
        New_Strting_Day = The_calendar(strting_date,month[i],last_day[i]);
        else
        New_Strting_Day = The_calendar(the_begning_day(New_Strting_Day),month[i],last_day[i]);
    }
}


