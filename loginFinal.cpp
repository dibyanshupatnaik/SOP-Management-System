#include<iostream>
#include<fstream>
#include<windows.h>
#include"Contacts-1.h"
#include<ctype.h>
using namespace std;
class load
{
    char sap[16];
    public:
    ifstream iFile;
    ofstream oFile;

    void admin()
    {
    char inpu;

    admin_home:

    system("CLS");
    cout<<"View all SAP IDs along with respective Names (V)";
    cout<<"\nSearch directly by SAP ID (S)";
    cout<<"\nView shortlisted record (X)";
    cout<<"\nLogout (L)\n";

    cin>>inpu;
    inpu=toupper(inpu);

    if(inpu=='L')
    ;

    else if(inpu=='X')
    {
        char get_sap[12]; int c,cur;
        iFile.open("shortlist.txt");
        if(!iFile)
           {
               cout<<"\nNo records shortlisted! \n";
               goto hoponce;
           }

           while(!iFile.eof())
            {
            iFile>>get_sap;
            if(iFile.tellg()==-1)
                break;
            cout<<get_sap<<endl;
            }

        iFile.close();
            hoponce:
         cout<<"\nPress any key to continue... ";
         cin.get();
         cin.get();

        goto admin_home;
    }

    else if(inpu=='V')
    {
        char getcontent1[35];
        iFile.open("Index.txt");
        if(iFile.is_open())
        {
            while(! iFile.eof())
            {
                iFile.getline(getcontent1,35);
                cout << getcontent1 << endl;
            }
        }
        iFile.close();
        goto JUMP;

    }
    else if(inpu=='S')
    {
        JUMP:
        char search[16];
        char store[11];
        //char searchq[11];
        char contac[25]="contacts\\";
        char statem[27]="statements\\";
        char txt[]=".txt";
        cout<<"Enter SAP ID to search: ";
        cin>>search;
        strcpy(store,search);
        system("CLS");
        //strcpy(searchq,search);
        strcat(search,txt);
        strcat(statem,search);
        strcat(contac,search);

        //'search' troubleshoot like sap ID input of student

        char getcontent[55];

        iFile.open(contac);
        if(iFile.is_open())
        {
            while(! iFile.eof())
            {
                iFile.getline(getcontent,55);
                cout << getcontent << endl;
                cout.flush();
            }

        }
        iFile.close();

        iFile.open(statem);

         if(iFile.is_open()){

           while(! iFile.eof())
           {
                iFile.getline(getcontent,55);
                cout << getcontent << endl;
           }
         }
         iFile.close();

         cout << endl << endl << endl << endl << "Shortlist candidate? (y/n)" << endl;
         char sl;
         cin>>sl;
         sl=toupper(sl);
            if(sl=='Y')
            {
             char contain[11]; int flag=0;
             iFile.open("shortlist.txt");
             while(iFile)
                {
                    iFile>>contain;
                    if(strcmp(store,contain)==0)
                        flag=1;
                }
             iFile.close();

             if(flag)
                {
                    cout<<"\n\nCandidate already shortlisted! ";
                    goto hop;
                }

             oFile.open("shortlist.txt", ios::app);
             oFile.write(store,11);
             oFile<<endl;
             oFile.close();
             cout<<"\n\nCandidate successfully shortlisted! ";
            }
         hop:
         cout<<"Press any key to continue... ";
         cin.get();
         cin.get();
         goto admin_home;
    }
    }


    void sapid()
    {
        char name[40];

        int chk = 0;
        system("CLS");
        cout<<"Disclaimer: Your unique SAP ID will save your personal details against it.\nTherefore, please enter your details accurately as you will not be able to edit this later.\n";
        cout<<"\nEnter your Name:\t";
        cin.ignore();
        cin.getline(name,40);
        cout<<"Enter Sap ID:\t";
        START:

        cin>>sap;

        for(int i = 0; i < 11; i++){
            if(sap[i] >= 48 && sap[i] <= 57){

                if(i == 0 && sap[i] == '7'){
                    chk = 1;
                }
            }
            else
                chk = 0;
        }
        if(chk == 0){
            cout << "Enter a valid Sap ID:\t";
            goto START;
        }
        if(sap)
        {
            char t[]=".txt";
            iFile.open("Index.txt");
            {
                bool flag=0;
                char check[12];
                while(!iFile.eof())
                {
                    iFile>>check;
                    if(strcmp(check,sap)==0)
                    flag=1;
                    break;
                }
            if(flag)
            {
                cout<<"\nDetails for SAP already exist!\n"<<endl << "Re-enter your Sap ID:\t";
                goto START;
            }

            }
            iFile.close();

            oFile.open("Index.txt", ios::app);
            oFile<<sap << endl<< name << endl<<endl;
            oFile.close();

            char newcont[25]="contacts\\";
            char newstatement[27]="statements\\";
            strcat(sap,t);
            strcat(newcont, sap);
            oFile.open(newcont);
            {
                Contacts x;
                START2:
                x.get_data();
                if(x.chk_mail() && x.chk_tele())
                {
                    oFile<<x.mail<<endl;
                    oFile<<x.tele<<endl;

                }
                else
                {
                    cout<<"Invalid parameters entered! Try again! \n";
                    goto START2;
                }
            }
            oFile.close();

            strcat(newstatement, sap);
            char sop[1000]; unsigned int len;
            oFile.open(newstatement);
            {
                system("CLS");
                cout<<"Hi "<<name<<". Enter your SOP details\n";
                cout<<"\nEnter your skill set : ";
                cin.ignore();
                gets(sop); len=strlen(sop); oFile<<"Skill-set: "; oFile.write(sop,len); oFile<<endl;

                cout<<"\nEnter your past experiences/achievements : ";
                gets(sop); len=strlen(sop); oFile<<"Achievements: "; oFile.write(sop,len); oFile<<endl;

                cout<<"\nEnter your reason for applying for this : ";
                gets(sop); len=strlen(sop); oFile<<"Reason: "; oFile.write(sop,len); oFile<<endl;


            }
            oFile.close();

            cout << endl << endl << endl << endl << "Data saved. Press any key to continue..." << endl;
            cin.get();
        }


    }
};
int main()
{
  //Username and Password to validate credentials
	const string USERNAME = "admin";
	const string PASSWORD = "mpstmeadmin";
	//strings in which admin will enter username and password
	string username, password;

	int check=0;
    char ch;
    load l;

    cout<<"\t\t\tWelcome to Student SOP Management Console \n\n\n";

 	do{

        system("CLS");
        cout<<"1. Admin\n\n2. Student\n\n3. Exit\n\n";
        cin>>ch;
        switch(ch)
        {
            case '1':       //Admin has View registry, View details, View shortlisted
                do{
                    cout << "\nEnter Username : ";
                    cin >> username;
                    //Checking if username length is less than 4 characters then display an error message
                    if(username.length() < 4)
                    {
                        system("CLS");
                        cout << "\nUsername length must be atleast 4 characters long.\n";
                        check=10;
                    }
                    else  //if username length is greater than 3
                    {
                    //promprting user for password
                        cout << "Enter Password : ";
                        cin >> password;
                        //Checking if password length is less than 6 characters then display an error message
                        if(password.length() < 6)
                        {
                            system("CLS");
                            cout << "\nPassword length must be atleast 6 characters long.\n";
                            check=10;
                        }
                        else //if password length is greater than 5
                        {
                            //Checking if user's entered credentials are equal to actual USERNAME and PASSWORD
                            if(username == USERNAME && password == PASSWORD)
                            {
                                system("CLS");
                                cout << "Welcome Admin\n" << endl;
                                check=0;
                            }
                            else
                            {
                                system("CLS");
                                char choose;
                                cout << "\nInvalid login details\n" << endl;
                                cout<<"\nGo back to login page? (y/n): ";
                                cin>>choose;
                                if(choose=='y'||choose=='Y')

                                check=10;
                            }
                        }
                    }
                }while(check==10);
                l.admin();
                break;

            case '2':
                    l.sapid();
                    break;
            case '3':
                ch='3';
                break;
            default:
                cout<<"\nInvalid choice! Choose again...\n";

                break;
        }

        system("CLS");
    }while(ch!='3');

	return 0;
}
