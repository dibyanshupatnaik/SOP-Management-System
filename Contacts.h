#ifndef CONTACTS_H
#define CONTACTS_H

#define YES 1
#define NO 0

using namespace std;

//list of classes

class contacts;

//definition of classes

class Contacts
{
public:
    char tele[11];
    char mail[30];


    void get_data()                                                                         //Function to get the data
    {
        char mail_re[30];
        cout << "Enter your cell phone number:\t";
        cin >> tele;
        do{
            cout << "Enter your mail ID:\t";
            cin >> mail;
            cout << "Confirm your mail ID:\t";
            cin >> mail_re;
        }while(strcmp(mail, mail_re) != 0);

    }

    bool chk_mail();                                                                        //Function to check the mail address

    bool chk_tele();                                                                        //Function to check telephone number
};

//definitions of undefined member functions

bool Contacts::chk_mail()
{
    int count = 0;
    bool check = NO;
    int pos = 0;
    for(int i = 0; i < strlen(mail); i++){
        if(mail[i] == '@'){                                                                 //checks for an @ character in the entered mail id
            check = YES;
            count++;
            if(count > 1){
                check = NO;
                break;
            }
            pos = i;
        }
    }
    count = 0;

    if(check == 0){
        return NO;
    }
    else{
        for(int i = pos + 1; i < strlen(mail); i++){                                        //requirement for email server
            if((mail[i] >= 65 && mail[i] <= 90) || (mail[i] >= 97 && mail[i] <= 122) || (mail[i]>= 45 && mail[i] <= 57 && mail[i] != 47) || mail[i] != ','){
                if(mail[i] == '.'){
                    if(mail[i + 1] >= 48 && mail[i + 1] <= 57 && mail[i + 1] == '\0'){
                        check = NO;
                    }
                    else
                        check = YES;
                }
                else
                    check = YES;
            }

            else{
                check = NO;
                break;
            }
        }

        for(int i = 0; i < pos; i++){                                                       //requirement for email name
            if((mail[i] >= 65 && mail[i] <= 90) || (mail[i] >= 94 && mail[i] <= 122) || (mail[i]>= 42 && mail[i] <= 57) || (mail[i]>= 33 && mail[i] <= 39)){
                if(mail[i] == '.'){
                    if(mail[i + 1] >= 48 && mail[i + 1] <= 57 && mail[i + 1] == '\0'){
                        check = NO;
                    }
                    else
                        check = YES;
                }
                else
                    check = YES;
            }

            else{
                check = NO;
                break;
            }
        }
    }

    return check;
}

bool Contacts::chk_tele()
{
    if(strlen(tele) != 10){                                                                 //A ten digit number
        return NO;
    }
    bool check = 0;
    for(int i = 0; i < 10; i++){
        if(tele[i] <= 57 && tele[i] >= 48)
            check = YES;
        else{
            check=NO;
            break;
        }
    }

    if(check == 0){
        return NO;
    }

    else if((*tele) == '9' || (*tele) == '8' || (*tele) == '7'){                            //Begins with digits 9, 8 or 7
        return YES;
    }

    else{
        return NO;
    }
}

#endif
