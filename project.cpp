#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<time.h>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<limits>
#include<dos.h>
#include<iomanip>
#include<algorithm>
//#include<chrono>

using namespace std;
//using namespace std::chrono;

int hdrscr();
class bank{
    protected:
    string first_name,last_name,father_firstname,mother_firstname,grandfather_firstname,father_lastname,mother_lastname,grandfather_lastname,username,password;
    string province,district,municipality,tole,email,mob_num,bank_accnum;
    char gender;
    int year,month,day,ward,acc_no,acc_type;
    float bank_balance;
    public:
        void DOB(){
            cin>>year>>month>>day;
            //getting the current date
//            system_clock::time_point now = system_clock::now();
//            time_t now_c = system_clock::to_time_t(now);
//            tm current_tm = *localtime(&now_c);
//            int currentYear = current_tm.tm_year + 1900; // Gregorian year
            time_t tim=time(0);
            tm* atime=localtime(&tim);
            int currentyear=atime->tm_year+1900+57;

            // Calculate the age in BS
            int age = (currentyear) - year ;

            if(cin.fail()||(age<18)||(month>12||month<=0)||(day>31||day<=0)){    //cin.fail() is used to check if the input is of the correct type. If it returns true, it means that the input is not an integer.
                cout<<"\n\t\t\t Invalid date";
                cin.clear(); // Clear error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout<<"\n\t\t\t Enter again\n\t\t";
                cout<<"\n\t\tEnter Your Date of Birth(year/month/day) in B.S. : ";
                DOB();
            }
        }
        void phone_number() {
            cout << "\n\t\t+977-";
            cin.clear();
            cin >> mob_num;
            if (mob_num.length() != 10 || !isNumeric(mob_num)) {
                cout << "\n\t\tInvalid mobile number.\n\t\tEnter again" ;
                phone_number();
            }
            bool found = checkIfPhoneNumberExists(mob_num);

            if (found) {
                cout << "\n\t\tThis mobile number is already used." << endl;
                cout << "\n\t\tEnter again: ";
                phone_number();
            }
        }
        bool isNumeric(const string &str) {
            return all_of(str.begin(), str.end(), ::isdigit);
        }
        bool checkIfPhoneNumberExists(const string &phone_number) {
            ifstream fin;
            fin.open("useridpw.txt");
            string line, mnum, p;
            bool found = false;

            while (getline(fin, line)) {
                stringstream iss(line);
                iss >> mnum >> p;
                if (mnum == phone_number) {
                    found = true;
                    break;
                }
            }
            fin.close();

            return found;
        }
        void bank_accnumber(){
                string bank_code="0112",random;    // no_of_acc is no of account , acc_type is account type
                string ran,a,b,c,d,e;
                srand(time(0));// Seed the random number generator with current time
                int randomNumber[5];
                for(int i=0;i<5;i++){
                    randomNumber[i] = rand()%10;
                }
                a=to_string(randomNumber[0]);
                b=to_string(randomNumber[1]);
                c=to_string(randomNumber[2]);
                d=to_string(randomNumber[3]);
                e=to_string(randomNumber[4]);
                random=a+b+c+d+e;
                //cout<<random<<endl;
                string account_type;
                account_type=to_string(acc_type);
                bank_accnum=bank_code+random+account_type;
            }
        void bank_accbalance(){
            bank_balance=0;
        }
        void search_display(){
        cout<<"\n\t\t_____________________________________________________________________________________________\n";
        cout<<"\t\t_____________________________________________________________________________________________\n";
        cout<<"\t\t                                              		            \n";
        cout<<"\t\t                                                  		        \n";
        cout<<"\t\t                                                                 \n";
        cout<<"\t\t        Name::\t\t\t"<<first_name<<" "<<last_name<<endl;
        cout<<"\t\t        Account No::\t\t"<<bank_accnum<<endl;
        cout<<"\t\t        Bank Balance::\t\t"<<bank_balance<<endl;
        cout<<"\t\t        Grand Father name::\t"<<grandfather_firstname<<" "<<grandfather_lastname<<endl;
        cout<<"\t\t        Father name::\t\t"<<father_firstname<<" "<<father_lastname<<endl;
        cout<<"\t\t        Mother name::\t\t"<<mother_firstname<<" "<<mother_lastname<<endl;
        cout<<"\t\t        Date of birth::\t\t"<<year<<"/"<<month<<"/"<<day<<"      \n";
        cout<<"\t\t        Mobile no::\t\t"<<mob_num<<"                             \n";
        cout<<"\t\t        Email::\t\t\t"<<email<<"                                 \n";
        cout<<"\t\t        Province::\t\t"<<province<<"                             \n";
        cout<<"\t\t        District::\t\t"<<district<<"                             \n";
        cout<<"\t\t        Address::\t\t"<<municipality<<"-"<<ward<<","<<tole<<"    \n";
        cout<<"\t\t        Gender::\t\t"<<gender<<"                                 \n";
        cout<<"\t\t_____________________________________________________________________________________________\n";
        cout<<"\t\t_____________________________________________________________________________________________\n\n\n\n\t\t\t\t\t";
        }
        bool isValidGmail(const string &email) {
            size_t position = email.find("@");
            return (position != string::npos && email.substr(position + 1) == "gmail.com");
        }
        void us_email(){
//            cin.ignore();
//            cin.clear();
//            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//            getline(cin,email);
            cin>>email;
            size_t position;
            position=email.find("@");
            if (isValidGmail(email)) {
                    //valid email
            }
            else {
                cout << "\n\t\tInvalid Email.\n\t\tEnter again\n\t\t";
                us_email(); // Prompt again for email if it's invalid
            }
        }
};
class admin:public bank{
public:
    void admin_login();
    void admin_page();
    void create_user();
    void search_user();
    void search_by_name(const string& name);
    void search_by_acc_num(const string& number);
    void tasks();
    void deposit(const string &name,const string& accnum,double money);
    void withdraw(const string& name, const string& accnum, double money);
    void edit_acc();
    void delete_acc(const string& name, const string& accnum);
    void cpy();
};
class user:public admin{
    string user_username,user_password;
    string current_password,new_password;
public:
    void user_login();
    void user_page();
    void user_information();
    void password();
    void change_password();
    void transaction_history();
    void user_display(const string& first_name,const string& last_name,const string& mob_num,float bank_balance,const string& bank_accnum,const string& grandfather_firstname,const string& grandfather_lastname,const string& father_firstname,const string& father_lastname,const string& mother_firstname,const string& mother_lastname,int year,int month,int day,const string& province,const string& district,const string& municipality,int ward,const string& tole,char gender,const string& email){
        cout<<"\n\t\t_____________________________________________________________________________________________\n";
        cout<<"\t\t_____________________________________________________________________________________________\n";
        cout<<"\t\t                                              		            \n";
        cout<<"\t\t                                                  		        \n";
        cout<<"\t\t                                                                 \n";
        cout<<"\t\t        Name::\t\t\t"<<first_name<<" "<<last_name<<endl;
        cout<<"\t\t        Account No::\t\t"<<bank_accnum<<endl;
        cout<<"\t\t        Bank Balance::\t\t"<<bank_balance<<endl;
        cout<<"\t\t        Grand Father name::\t"<<grandfather_firstname<<" "<<grandfather_lastname<<endl;
        cout<<"\t\t        Father name::\t\t"<<father_firstname<<" "<<father_lastname<<endl;
        cout<<"\t\t        Mother name::\t\t"<<mother_firstname<<" "<<mother_lastname<<endl;
        cout<<"\t\t        Date of birth::\t\t"<<year<<"/"<<month<<"/"<<day<<"      \n";
        cout<<"\t\t        Mobile no::\t\t"<<mob_num<<"                             \n";
        cout<<"\t\t        Email::\t\t\t"<<email<<"                                 \n";
        cout<<"\t\t        Province::\t\t"<<province<<"                             \n";
        cout<<"\t\t        District::\t\t"<<district<<"                             \n";
        cout<<"\t\t        Address::\t\t"<<municipality<<" "<<ward<<","<<tole<<"    \n";
        cout<<"\t\t        Gender::\t\t"<<gender<<"                                 \n";
        cout<<"\t\t_____________________________________________________________________________________________\n";
        cout<<"\t\t_____________________________________________________________________________________________\n\n\n\n\t\t\t\t\t";
    }
};

void login_page(){
    system("cls");
    hdrscr();
    int choice;
    here:
    cout<<"\n\n\t\t"<<char(201);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(187)<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(186)<<"\t\t\t        Enter your login type:          \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [1] Admin                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [2] User                         \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [3] Exit                        \t\t "<<char(186)<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(200);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(188)<<endl<<endl;

    choice=getch();        //data input
    switch(choice)
    {
    case '1':{
        system("cls");
        admin ad_obj;
        ad_obj.admin_login();
        break;
    }
    case '2':{
        system("cls");
        user us_obj;
        us_obj.user_login();
        break;
    }
    case '3':{
        exit(0);
    }
    default:
        system("cls");
        cout<<"\n\t\tInvalid choice! Try again\n";
        system("pause");
        system("cls");
        goto here;

    }
}
int hdrscr(){
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 16;
    cfi.dwFontSize.X = 10;                   // Width of each character in the font
    cfi.dwFontSize.Y = 21.5;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_BOLD;
    wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    return 1;
}
void admin::admin_login(){
    here1:
    string admin_username,admin_password;
    char ch;
    cout<<"\n\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }
    cout<<"\t\t\t\t\t\t\t                 Admin Login Page:               ";
    cout<<"\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }
    cout<<"\n\n\t\t\t        Enter username: ";cin>>admin_username;cout<<"\n\n";
    cout<<"\t\t\t       Enter password: ";
        while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!admin_password.empty()) {
                admin_password.pop_back();
                cout << "\b \b";
            }
        } else {
            admin_password += ch;
            cout << '*';
        }
    }
    string aname,apass;
    ifstream pass("admin.txt");
    pass.seekg(0,ios::beg);
    bool authenticated = false;
    while (pass >> aname >> apass) {
        if (aname == admin_username && apass == admin_password) {
            authenticated = true;
            break; // Match found, no need to continue searching
        }
    }

    if (authenticated) {
        cout << "\n\n\n\t\t\tAuthentication successful.\n\n";
        cout<<"\n\n\t\t\t\tLogging ";
        for(int i=0;i<5;i++)
        {
            cout<<".";
            Sleep(500);
        }
        admin_page();
    }
    else
    {
        char a;
        MessageBeep(MB_OK);
        cout<<"\n\n\t\t\t\tAuthentication failed.\n\n";
        cout<<"\n\n\t\t\t\tDo you want to try again?";
        cout<<"\n\n\t\t\t\tEnter y for yes and n for no\n";
        cout<<"\n\n\t\t\t\t";
        a=getch();
        if(a=='Y'||a=='y'){
            system("cls");
            goto here1;
        }
        else if(a=='N'||a=='n'){
            login_page();
        }
        else{
            exit(0);
        }
    }
}
void user::user_login(){
        here1:
    char ch;
    cout<<"\n\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }
    cout<<"\t\t\t\t\t\t\t                 User Login Page:               ";
    cout<<"\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }
    cout<<"\n\n\t\t\t        Enter username: ";cin>>user_username;cout<<"\n\n";
    cout<<"\t\t\t       Enter password: ";
        while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!user_password.empty()) {
                user_password.pop_back();
                cout << "\b \b";
            }
        } else {
            user_password += ch;
            cout << '*';
        }
    }
    string uname,upass;
    ifstream pass("useridpw.txt");
    pass.seekg(0,ios::beg);
    bool authenticated = false;
    while (pass >> uname >> upass) {
        if (uname == user_username && upass == user_password) {
            authenticated = true;
            break; // Match found, no need to continue searching
        }
    }

    if (authenticated) {
        cout << "\n\n\n\t\t\tAuthentication successful.\n\n";
        cout<<"\n\n\t\t\t\tLogging ";
        for(int i=0;i<4;i++)
        {
            cout<<".";
            Sleep(500);
        }
        user_page();
    }
    else
    {
        char a;
        MessageBeep(MB_OK);
        cout << "\n\n\t\t\tAuthentication failed.\n\n";
        cout<<"\n\t\t\tDo you want to try again?";
        cout<<"\n\n\t\t\tEnter y for yes and n for no\n";
        cout<<"\n\n\t\t\t";
        a=getch();
        if(a=='Y'||a=='y'){
            system("cls");
            goto here1;
        }
        else if(a=='N'||a=='n'){
            login_page();
        }
        else{
            exit(0);
        }
    }
}
void admin::create_user(){
    system("cls");
    cout<<"\n\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }
    cout<<"\t\t\t\t\t\t\t                 Admin  Mode:               ";
    cout<<"\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }
    cout<<"\n\t\tFor Account Creating";
    cout<<"\n\n\t\tChoose type of Account you want to create : ";
    cout<<"\n\t\t\t[1] Fixed Deposit Account";
    cout<<"\n\t\t\t[2] Current Account";
    cout<<"\n\t\t";
    actp:
    cin>>acc_type;
    if(acc_type!=1&&acc_type!=2){
        cout<<"\n\t\tInvalid input.Please enter again. \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        goto actp;
    }
    cout<<"\n\n\t\tEnter Your first name : ";
    cin>>first_name;
    cout<<"\n\t\tEnter Your last name : ";
    cin>>last_name;
    cout<<"\n\t\tEnter Your Grandfather's first name : ";
    cin>>grandfather_firstname;
    cout<<"\n\t\tEnter Your Grandfather's last name : ";
    cin>>grandfather_lastname;
    cout<<"\n\t\tEnter Your Father's first name : ";
    cin>>father_firstname;
    cout<<"\n\t\tEnter Your Father's last name : ";
    cin>>father_lastname;
    cout<<"\n\t\tEnter Your Mother's first name : ";
    cin>>mother_firstname;
    cout<<"\n\t\tEnter Your Mother's last name : ";
    cin>>mother_lastname;
    cout<<"\n\t\tEnter Your Date of Birth(year/month/day) in B.S. : ";
    DOB();
    cout<<"\n\t\tEnter Your province name : ";
    cin>>province ;
    cout<<"\n\t\tEnter Your District name : ";
    cin>>district;
    cout<<"\n\t\tEnter Your Municipality name : ";
    cin>>municipality;
    cout<<"\n\t\tEnter Your ward number : ";
    do {
        if (cin >> ward) {
            // Input is a valid integer
            break;
        } else {
            cout << "\n\t\tInvalid input! Please enter an integer." << endl;
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            cout<<"\n\t\t";
        }
    } while (true);
    cout<<"\n\t\tEnter Your tole name : ";
    cin>>tole;
    cout<<"\n\t\tEnter Your Gender (m/f) : ";
    while (!(cin >> gender) || (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f')) {
        std::cout << "\n\t\tInvalid input! Please enter 'M' or 'F'.\n";
        std::cin.clear();  // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
        std::cout << "\n\t\tEnter your gender (M or F): ";
    }
    cout<<"\n\t\tEnter your Mobile number : ";
    phone_number();
    cout<<"\n\t\tEnter your Email address : ";
    us_email();
    bank_accnumber();
    bank_accbalance();

    search_display();
    yaha:
    cout<<"\n\n\t\t Do you want to edit? (y || n) ";
    char jawaf;
    jawaf=getch();
    if(jawaf=='y'||jawaf=='Y'){
        create_user();
    }
    else if(jawaf=='n'||jawaf=='N'){
        //now writting this data in a file
        ofstream userdat;
        userdat.open("projectuserdata.txt",ios::app);
        userdat<<first_name;
        userdat<<" ";
        userdat<<last_name;
        userdat<<" ";
        userdat<<"+977-"<<mob_num;
        userdat<<" ";
        userdat<<bank_balance;
        userdat<<" ";
        userdat<<bank_accnum;
        userdat<<" ";
        userdat<<grandfather_firstname;
        userdat<<" ";
        userdat<<grandfather_lastname;
        userdat<<" ";
        userdat<<father_firstname;
        userdat<<" ";
        userdat<<father_lastname;
        userdat<<" ";
        userdat<<mother_firstname;
        userdat<<" ";
        userdat<<mother_lastname;
        userdat<<" ";
        userdat<<year;
        userdat<<" ";
        userdat<<month;
        userdat<<" ";
        userdat<<day;
        userdat<<" ";
        userdat<<province;
        userdat<<" ";
        userdat<<district;
        userdat<<" ";
        userdat<<municipality;
        userdat<<" ";
        userdat<<ward;
        userdat<<" ";
        userdat<<tole;
        userdat<<" ";
        userdat<<gender;
        userdat<<" ";
        userdat<<email;
        userdat<<endl;
        userdat.close();

        //for creating text file for specific person to track transaction
        //***************yaaaaaaaaaa****************************************************************
        ofstream off;
        string filename;
        filename="+977-"+mob_num+".txt";
        off.open(filename);
//        off<<first_name;
//        off<<" ";
//        off<<last_name;
//        off<<" ";
//        off<<"+977-"<<mob_num;
//        off<<" ";
        off<<"d ";
        off<<bank_balance<<" ";
        time_t tim=time(0);
        tm* atime=localtime(&tim);
        int cyear=atime->tm_year+1900;
        /* 1900 is added in year because in tm structure the year is counted fromm 1900 so the counted year should be
        added wirh 1900 to get current year */
        int cmonth=atime->tm_mon+1;//since month represent from 0(jan) to 11(dec)
        int cday=atime->tm_mday;
        int chour=atime->tm_hour;
        int cminu=atime->tm_min;
        off<<cyear<<" "<<cmonth<<" "<<cday<<" "<<chour<<" "<<cminu;
        off<<endl;
        off.close();

        //setting user id pw
        string us_name,us_pass;
        us_name=mob_num;
        us_pass=first_name;
        ofstream userid;
        userid.open("useridpw.txt",ios::out|ios::app);
        userid<<us_name;
        userid<<" ";
        userid<<us_pass;
        userid<<endl;
        userid.close();
        cout<<"\n\t\t\tAccount created sucessfully";
    }
    else{
        cout<<"\n\t\tInvalid input.Please enter again.";
        goto yaha;
    }
    getch();
    admin_page();

}
void admin::admin_page(){
    system("cls");
    cout<<"\n\n\t\t"<<char(201);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(187)<<endl;
    for(int i=0;i<1;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(186)<<"\t\t\t        Admin Page                      \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t      Select Task                       \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [1] Create Account              \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [2] Search Acc                  \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [3] Tasks                       \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [4] Logout                      \t\t "<<char(186)<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(200);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(188)<<endl<<endl;
    cout<<char(205);
    char ch=getch();
    switch(ch){
        case '1':{
            create_user();
            break;
        }
        case '2':{
            search_user();
            break;
        }
        case '3':{
            tasks();
            break;
        }
        case '4':{
            system("cls");
            cout<<"\n\n\t\tLogging out";
            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(500);
            }
            login_page();
        }
        default:{
            cout<<"\n\n\t\tInvalid Input. Try Again ";
            cout<<"\n\t\t( Press any key to continue )";
            getch();
            admin_page();
        }
    }
}
void user::user_page(){
        system("cls");
    cout<<"\n\n\t\t"<<char(201);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(187)<<endl;
    for(int i=0;i<1;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(186)<<"\t\t\t        User Page                       \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t      Select Task                       \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [1] My Information              \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [2] Transaction History         \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [3] Change Password             \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [4] Logout                      \t\t "<<char(186)<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(200);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(188)<<endl<<endl;
    cout<<char(205);
    char ch=getch();
    switch(ch){
        case '1':{
            user_information();
            break;
        }
        case '2':{
            transaction_history();
            break;
        }
        case '3':{
            change_password();
//            password();
            break;
        }
        case '4':{
            system("cls");
            cout<<"\n\n\t\tLogging out";
            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(500);
            }
            login_page();
        }
        default:{
            cout<<"\n\n\t\tInvalid Input. Try Again ";
            cout<<"\n\t\t( Press any key to continue )";
            getch();
            user_page();
        }
    }
}
void admin::search_user(){
    system("cls");
    cout<<"\n\n\t\t"<<char(201);
    for(int i=0;i<88;i++)
    {
        cout<<char(205);
    }
    cout<<char(187);
    cout<<"\n\t\t"<<char(186)<<"\t\t\t             Admin Mode :                \t\t\t "<<char(186);
    cout<<"\n\t\t"<<char(186);
    for(int i=0;i<88;i++)
    {
        cout<<char(205);
    }
    cout<<char(186);
    cout<<"\n\t\t"<<char(186)<<"\t\t\t           Search Page                  \t\t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                          \t\t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [1] Search By Name                \t\t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                          \t\t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [2] Search By Account Number      \t\t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                          \t\t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [3] Back                          \t\t\t "<<char(186)<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(200);
    for(int i=0;i<88;i++)
    {
        cout<<char(205);
    }
    cout<<char(188)<<endl;
    char ch;
    bool validInput = false;
    while (!validInput) {
        ch = getch();

        if (ch=='1'||ch=='2'||ch=='3') {
            validInput = true;
        }
        else {
            cout << "Invalid input. Please enter a valid integer: ";
        }
    }
    switch(ch){
        case '1':{
            string uname;
            cout<<"\n\t\tEnter User 1st name : ";
            cin>>uname;
            search_by_name(uname);
            break;
        }
        case '2':{
            string unumber;
            cout<<"\n\t\tEnter User Bank Account Number : ";
            cin.clear();
            cin>>unumber;
            search_by_acc_num(unumber);
            break;
        }
        case '3':{
            admin_page();
        }
    }
}
void admin::search_by_name(const string& name) {
    ifstream userdat;
    userdat.open("projectuserdata.txt", ios::in);
    int count=0;
    bool found = false;
    string line;
    while (getline(userdat, line)) {
        stringstream iss(line);
        iss >> first_name;
        if (name == first_name) {
            count++;
            iss >> last_name >> mob_num >> bank_balance >> bank_accnum >> grandfather_firstname >> grandfather_lastname
               >> father_firstname >> father_lastname >> mother_firstname >> mother_lastname >> year >> month >> day
               >> province >> district >> municipality >> ward >> tole >> gender >> email;

            // Display the information of the matching user
            //cout<<"\n\t\t\t\tUser : "<<count;
            //this->search_display();
            // Display other user information here...
            //cout << endl;
        }
    }
    userdat.close();
    ifstream ser;
    ser.open("projectuserdata.txt",ios::in);
    string sline;
    if(count>=2){
        string num;
        cout<<"\n\t\tEnter mobile number :\n\t\t+977-";
        cin>>num;
        string totnum="+977-"+num;
        cout<<totnum;
        while (getline(ser, sline)) {
            stringstream iss(sline);
            iss >> first_name>>last_name>>mob_num;
            if ( totnum == mob_num ) {
                found = true;
                iss >> bank_balance >> bank_accnum >> grandfather_firstname >> grandfather_lastname
                >> father_firstname >> father_lastname >> mother_firstname >> mother_lastname >> year >> month >> day
                >> province >> district >> municipality >> ward >> tole >> gender >> email;
                this->search_display();
            }
        }
    }
    ser.close();

    if (!found) {
        cout << "\n\t\tNo user found with that name" << endl;
    }
    char ans;
    cout<<"\n\n\t\tDo you want to continue (y/n) ? ";
    cin>>ans;
    if(ans=='y'||ans=='Y')
        search_user();
    else if(ans=='n'||ans=='N')
        admin_page();
    else
        cout<<"\n\t\tInvalid input";
}
void admin::search_by_acc_num(const string& number){
        ifstream userdat;
        userdat.open("projectuserdata.txt", ios::in);
        string line;
        bool found=false;
        while (getline(userdat, line)) {
            stringstream ss(line);

            // Read the bank_accnumber from the stringstream and compare it
            ss >> first_name >> last_name >> mob_num >> bank_balance >> bank_accnum;

            if (bank_accnum == number) {
                    found = true ;
                // Read the rest of the data from the stringstream
                ss >> grandfather_firstname >> grandfather_lastname >> father_firstname >> father_lastname >> mother_firstname >> mother_lastname >> year >> month >> day >> province >> district >> municipality >> ward >> tole >> gender >> email;
                this->search_display();
            }
        }
        userdat.close();
        if (!found) {
            cout << "\n\t\tNo user found with that Account Number" << endl;
        }
        char ans;
        h1:
        cout<<"\n\n\t\tDo you want to continue (y/n) ? ";
        //cin>>ans;
        ans=getch();
        if(ans=='y'||ans=='Y')
            search_user();
        else if(ans=='n'||ans=='N')
            admin_page();
        else
            cout<<"\n\t\tInvalid input.Try again.";
            goto h1;
}
void admin::tasks(){
    system("cls");
    cout<<"\n\n\t\t"<<char(201);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(187)<<endl;
    for(int i=0;i<1;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(186)<<"\t\t\t        Admin                           \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t      Select Task                       \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [1] Deposit Money               \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [2] Withdraw Money              \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [3] Delete Account              \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t                                        \t\t "<<char(186)<<endl;
    cout<<"\t\t"<<char(186)<<"\t\t\t        [4] Go Back                     \t\t "<<char(186)<<endl;
    for(int i=0;i<11;i++)
    {
        cout<<"\t\t"<<char(186)<<"\t\t\t\t\t\t\t\t\t\t "<<char(186)<<endl;
    }
    cout<<"\t\t"<<char(200);
    for(int i=0;i<80;i++)
    {
        cout<<char(205);
    }
    cout<<char(188)<<endl<<endl;
    cout<<char(205);
    char ch=getch();
    switch(ch){
        case '1':{
            string name,accnum;
            double money;
            cout<<"\n\n\t\tEnter user 1st name : ";
            cin>>name;
            cout<<"\n\t\tEnter Account number : ";
            cin>>accnum;
            cout<<"\n\t\tEnter amount of money to be deposited : ";
            cin>>money;
            deposit(name,accnum,money);
            tasks();
            break;
        }
        case '2':{
            string name,accnum;
            double money;
            cout<<"\n\n\t\tEnter user 1st name : ";
            cin>>name;
            cout<<"\n\t\tEnter Account number : ";
            cin>>accnum;
            bool validinput=false;
            while(!validinput){
                cout<<"\n\t\tEnter amount of money to withdraw : ";
                if(cin>>money){
                    validinput=true;
                    // Check for any remaining characters in the input buffer
                    if (std::cin.peek() != '\n') {
                        validinput = false;
                        std::cout << "Invalid input. Please enter a valid amount." << std::endl;
                        // Clear the input buffer to remove invalid input
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                else{
                    cout << "\t\tInvalid input. Please enter a valid amount." << std::endl;
                    // Clear the error flag to allow further input attempts
                    std::cin.clear();
                    // Clear the input buffer to remove invalid input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            //cin>>money;
            withdraw(name,accnum,money);
            tasks();
            break;

        }
        case '3':{
            string name,accnum;
            cout<<"\n\n\t\tEnter user 1st name : ";
            cin>>name;
            cout<<"\n\t\tEnter Account number : ";
            cin>>accnum;
            delete_acc(name,accnum);
            tasks();
            break;
            break;
        }
        case '4':{
            admin_page();
            break;
        }
        default:{
            cout<<"\n\n\t\tInvalid Input. Try Again ";
            cout<<"\n\t\t( Press any key to continue )";
            getch();
            tasks();
            break;
        }
    }
}
void admin::deposit(const string& name, const string& accnum, double money) {
        ifstream userdat;
        ofstream updatedUserdat;
        userdat.open("projectuserdata.txt", ios::in);
        updatedUserdat.open("temp1_userdata.txt", ios::out | ios::app);
        if (!userdat.is_open() || !updatedUserdat.is_open()) {
            std::cerr << "Error opening files!" << endl;
            return;
        }
        bool found = false;
        string line;

        while (getline(userdat, line)) {
            stringstream iss(line);
            iss>>first_name>>last_name>>mob_num>>bank_balance>>bank_accnum>> grandfather_firstname >> grandfather_lastname
               >> father_firstname >> father_lastname >> mother_firstname >> mother_lastname >> year >> month >> day
               >> province >> district >> municipality >> ward >> tole >> gender >> email;
            if (name == first_name && accnum == bank_accnum) {
                found = true;
                string naam=mob_num+".txt";
                ofstream wrt;
                wrt.open(naam,ios::out | ios::app);
                wrt<<"d "<<money<<" ";
                time_t tim=time(0);
                tm* atime=localtime(&tim);
                int cyear=atime->tm_year+1900;
                /* 1900 is added in year because in tm structure the year is counted fromm 1900 so the counted year should be
                added wirh 1900 to get current year */
                int cmonth=atime->tm_mon+1;//since month represent from 0(jan) to 11(dec)
                int cday=atime->tm_mday;
                int chour=atime->tm_hour;
                int cminu=atime->tm_min;
                wrt<<cyear<<" "<<cmonth<<" "<<cday<<" "<<chour<<" "<<cminu;
                wrt<<endl;
                wrt.close();
                bank_balance += money;
                updatedUserdat << first_name << " " << last_name << " " << mob_num << " " << bank_balance << " " << bank_accnum << " " << grandfather_firstname << " " << grandfather_lastname
                    << " " << father_firstname << " " << father_lastname << " " << mother_firstname << " " << mother_lastname << " " << year << " " << month << " " << day
                    << " " << province << " " << district << " " << municipality << " " << ward << " " << tole << " " << gender << " " << email << endl;
            }
            else {
                updatedUserdat << line << endl;
            }
        }

        userdat.close();
        updatedUserdat.close();
        // Rename the updated file to the original file
        remove("projectuserdata.txt");
        rename("temp1_userdata.txt", "projectuserdata.txt");
        if (found) {
            cout << "\n\t\tDeposit successful." << endl;
        }
        else {
            cout << "\n\t\tNo user found with that name and account number." << endl;
        }
        h1:
        char ans;
        cout<<"\n\n\t\tDo you want to continue (y/n) ? ";
        ans=getch();
        if(ans=='y'||ans=='Y')
            tasks();
        else if(ans=='n'||ans=='N')
            admin_page();
        else
            cout<<"\n\t\tInvalid input.Try again.";
            goto h1;
}
void admin::withdraw(const string& name, const string& accnum, double money){
        ifstream padhne;
        ofstream lekhne;
        padhne.open("projectuserdata.txt", ios::in);
        lekhne.open("temp2_userdata.txt", ios::out | ios::app);
        if (!padhne.is_open() || !lekhne.is_open()) {
            std::cerr << "Error opening files!" << endl;
            return;
        }
        bool found = false;
        string line;

        while (getline(padhne, line)) {
            stringstream iss(line);
            iss>>first_name>>last_name>>mob_num>>bank_balance>>bank_accnum>> grandfather_firstname >> grandfather_lastname
                >> father_firstname >> father_lastname >> mother_firstname >> mother_lastname >> year >> month >> day
                >> province >> district >> municipality >> ward >> tole >> gender >> email;
            if (name == first_name && accnum == bank_accnum) {
                found = true;
                if(bank_balance<money){
                    cout<<"\n\t\tInsufficient fund.\n\t\t(Press any key to continue)";
                    getch();
                    padhne.close();
                    lekhne.close();
                    remove("temp2_userdata.txt");
                    tasks();
                }
                else{
                    float bankbal=bank_balance;
                    //for transaction history
                    string naam=mob_num+".txt";
                    ofstream wrt;
                    wrt.open(naam,ios::out | ios::app);
                    wrt<<"w "<<money<<" ";
                    time_t tim=time(0);
                    tm* atime=localtime(&tim);
                    int cyear=atime->tm_year+1900;
                    /* 1900 is added in year because in tm structure the year is counted fromm 1900 so the counted year should be
                    added wirh 1900 to get current year */
                    int cmonth=atime->tm_mon+1;//since month represent from 0(jan) to 11(dec)
                    int cday=atime->tm_mday;
                    int chour=atime->tm_hour;
                    int cminu=atime->tm_min;
                    wrt<<cyear<<" "<<cmonth<<" "<<cday<<" "<<chour<<" "<<cminu;
                    wrt<<endl;
                    wrt.close();
                    bankbal -= money;
                    lekhne << first_name << " " << last_name << " " << mob_num << " " << bankbal << " " << bank_accnum << " " << grandfather_firstname << " " << grandfather_lastname
                    << " " << father_firstname << " " << father_lastname << " " << mother_firstname << " " << mother_lastname << " " << year << " " << month << " " << day
                    << " " << province << " " << district << " " << municipality << " " << ward << " " << tole << " " << gender << " " << email << endl;
                }
            }
            else {
                lekhne << line << endl;
            }
        }

        padhne.close();
        lekhne.close();
        // Rename the updated file to the original file
        remove("projectuserdata.txt");
        rename("temp2_userdata.txt","projectuserdata.txt");
        if (found) {
            cout << "\n\t\tWithdraw successful." << endl;
        }
        else {
            cout << "\n\t\tNo user found with that name and account number." << endl;
        }
        h2:
        char ans;
        cout<<"\n\n\t\tDo you want to continue (y/n) ? ";
        ans=getch();
        if(ans=='y'||ans=='Y')
            tasks();
        else if(ans=='n'||ans=='N')
            admin_page();
        else
            cout<<"\n\t\tInvalid input.Try Again.";
            goto h2;
}
void admin::delete_acc(const string& name,const string& accnum){
        ifstream userdat;
        ofstream updatedUserdat;
        userdat.open("projectuserdata.txt", ios::in);
        updatedUserdat.open("temp3_userdata.txt", ios::out | ios::app);
        bool found = false;
        string line,temp_uname;
        while (getline(userdat, line)) {
            stringstream iss(line);
            iss>>first_name>>last_name>>mob_num>>bank_balance>>bank_accnum>> grandfather_firstname >> grandfather_lastname
               >> father_firstname >> father_lastname >> mother_firstname >> mother_lastname >> year >> month >> day
               >> province >> district >> municipality >> ward >> tole >> gender >> email;
            if (name == first_name && accnum == bank_accnum) {
                found = true;
                ifstream fin;
                ofstream fout;
                fin.open("useridpw.txt", ios::in);
                fout.open("temp4_useridpw.txt", ios::out | ios::app);
                bool found = false;
                string line,zname,zpassword;
                while (getline(fin, line)) {
                    stringstream iss(line);
                    iss>>zname>>zpassword;
                    string totnum="+977-"+zname;
                    if(totnum==mob_num){
                        temp_uname=zname;
                        found=true;
                    }
                    else{
                        fout << zname << " " << zpassword<<endl ;
                    }
                }
                fin.close();
                fout.close();
                // Rename the updated file to the original file
                remove("useridpw.txt");
                rename("temp4_useridpw.txt", "useridpw.txt");
                string naam=mob_num+".txt";
                const char* filenaam=naam.c_str();
                remove(filenaam);
            }
               //********************************************************************************************
            else{
                updatedUserdat << first_name << " " << last_name << " " << mob_num << " " << bank_balance << " " << bank_accnum << " " << grandfather_firstname << " " << grandfather_lastname
                    << " " << father_firstname << " " << father_lastname << " " << mother_firstname << " " << mother_lastname << " " << year << " " << month << " " << day
                    << " " << province << " " << district << " " << municipality << " " << ward << " " << tole << " " << gender << " " << email << endl;
            }
        }
        userdat.close();
        updatedUserdat.close();
//        // Rename the updated file to the original file
        remove("projectuserdata.txt");
        rename("temp3_userdata.txt", "projectuserdata.txt");
//        //now deleting from useridpw.txt also
//        ifstream fin;
//        ofstream fout;
//        fin.open("useridpw.txt",ios::in);
//        fout.open("temp19.txt",ios::out|ios::app);
//        string sline,uuname,uupassword;
//        while(getline(fin,sline)){
//            stringstream fiss(line);
//            fiss>>uuname>>uupassword;
//            if(uuname==temp_uname){
//            }
//            else{
//                fout<<uuname<<" "<<uupassword<<endl;
//            }
//        }
//        fin.close();
//        fout.close();
//        ifstream fi("temp19.txt");
//        ofstream fo("useridpw.txt");
//        string cpy;
//        while (getline(fi, line)) {
//                fo << line << endl; // Write the line to the destination file
//        }
//        fi.close();
//        fo.close();
//        remove("temp.txt");
        if(found){
                cout<<"\n\t\tAccount deleted.";
        }
        else{
            cout << "\n\t\tNo user found with that name and account number." << endl;
        }
        char ans;
        cout<<"\n\n\t\tDo you want to continue (y/n) ? ";
        cin>>ans;
        if(ans=='y'||ans=='Y')
            tasks();
        else if(ans=='n'||ans=='N')
            admin_page();
        else
            cout<<"\n\t\tInvalid input";
}

void user::user_information(){
    ifstream fin;
    fin.open("projectuserdata.txt" , ios::in);
    string line,fname,lname,mnum,gfname,glname,ffname,flname,mfname,mlname;
    string prov,district,muni,tol,mail;
    int yr,m,d,wno;
    string accnum;
    float balance;
    char gen;
    while (getline(fin, line)) {
        stringstream iss(line);
        iss >> fname >> lname >> mnum >> balance >> accnum >> gfname >>glname>>ffname>>flname>>mfname>>mlname>>yr>>m>>d>>prov>>district>>muni>>wno>>tol>>gen>>mail ;
        string totnum="+977-"+user_username;
        if(totnum==mnum){
            user_display(fname,lname,mnum,balance,accnum,gfname,glname,ffname,flname,mfname,mlname,yr,m,d,prov,district,muni,wno,tol,gen,mail);
        }
    }
    fin.close();
    getch();
    user_page();
}
void user::change_password() {
    system("cls");
    cout << "\n\n\t\tEnter your Current Password : ";
    cin >> current_password;
    ifstream userdat;
    userdat.open("useridpw.txt", ios::in);
    string line, uname, upassword;
    bool password_matched = false;

    while (getline(userdat, line)) {
        stringstream iss(line);
        iss >> uname >> upassword;;

        if (uname == user_username && current_password == upassword) {
            password_matched = true;
            break; // Exit the loop if password matches
        }
    }
    userdat.close();

    if (password_matched) {
        here:
        cout << "\n\n\t\tEnter your New Password : ";
        cin >> new_password;
        char ans;
        cout<<"\n\t\tAre you sure ( Y | N ) ?";
        cin>>ans;
        heh:
        if(ans=='y'||ans=='Y'){
            ifstream userdat;
            ofstream updateduserdat;
            userdat.open("useridpw.txt",ios::in);
            updateduserdat.open("tempidpw.txt", ios::out | ios::app);
            string line,uid,upw;
            while(getline(userdat,line)){
                stringstream iss(line);
                iss>>uid>>upw;
                if(uid==user_username){
                    updateduserdat<<uid<<" "<<new_password<<endl;
                }
                else{
                    updateduserdat<<line<<endl;
                }
            }
            userdat.close();
            updateduserdat.close();
//            remove("useridpw.txt");
//            if (remove("useridpw.txt") != 0) {
//                    cout << "Error deleting original file." << endl; getch();
//                  //  return;
//            }
//            rename("temp_useridpw.txt","useridpw.txt");
            ifstream fin("tempidpw.txt");
            ofstream fout("useridpw.txt");
            string cpy;
            while (getline(fin, line)) {
                fout << line << endl; // Write the line to the destination file
            }
            fin.close();
            fout.close();
            remove("tempidpw.txt");
            cout<<"\n\t\tPassword changed successfully.\n\t\t(Press any key to continue) ";
            getch();
            user_page();
         }
        else if(ans=='n'||ans=='N'){
           // user_page();
           return;
        }
        else{
            cout<<"\n\t\tInvalid Input.\n\t\tTry again";
            goto heh;
        }
    }
        // Optionally, you can add validation for new_password here.
    else {
        cout << "\n\t\tIncorrect Password";
        cout << "\n\t\tDo you want to try again ( y | n )?";
        char answw;
        cin >> answw;
        if (answw == 'y' || answw == 'Y') {
            change_password();
        } else if (answw == 'n' || answw == 'N') {
           return;
           // user_page();
            // Redirect to user_page or handle the logic as needed
        } else {
            cout << "\n\t\tInvalid Input";
            cout << "\n\t\t(Press any key to continue)";
            cin.ignore(); // Clear the newline character from input buffer
            cin.get();    // Wait for user to press Enter
            change_password();
        }
    }
}
void user::transaction_history(){
    system("cls");
    cout<<"\n\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }
    cout<<"\t\t\t\t\t\t\t                 Transaction History :               ";
    cout<<"\n\t\t";
    for(int i=0;i<90;i++)
    {
        cout<<char(205);
    }

    string filenaam="+977-"+user_username+".txt";
    ifstream re;
    re.open(filenaam);
    string line;
    char action;
    float amt;
    int pyear,pmonth,pday,phour,pminute;
    int lines=0;
    while (getline(re, line)) {
            stringstream iss(line);
            iss>>action>>amt>>pyear>>pmonth>>pday>>phour>>pminute;
            lines++;
            if(action=='d'&&amt>0){
                cout<<"\n\t\t Deposited amount : "<<amt<<" at "<<pyear<<" "<<pmonth<<" "<<pday<<"  ::  "<<" "<<phour<<":"<<pminute;
            }
            else if(action=='w'){
                cout<<"\n\t\t withdrawn amount : "<<amt<<" at "<<pyear<<" "<<pmonth<<" "<<pday<<"  ::  "<<" "<<phour<<":"<<pminute;
            }
            else{
               // cout<<"\n\t\t No Transaction has occured ";
            }
    }
    if(lines==1){
        cout<<"\n\t\t No Transaction has occured .";
    }
    re.close();
    cout<<"\n\n\t\tPress any key  to continue ";
    char key;
    key=getch();
    user_page();
}

int main(){
     cout<<"Developed by Kripesh and teams";
    cout<<"All right reserverd";
    login_page();
    return 0;

}
