#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    string fname[100], lname[100], fullName[100], findFirst[100], findLast[100];
    string keyword;
    string contact[100];
    int choice,i(0),num,temp;
    bool found(false);

    do{
    system("cls");
    system("color 0B");
    cout << "\n\n\t\tCONTACT SAVER";
    cout << "\n\n\t1. Add Contact\n\t2. Search "
			"Contact\n\t3. Show Contact\n\t4. Edit Contact\n\t5. Exit\n\t> ";       //MENU
	cin >> choice;

    switch (choice) {
		case 1:                                                                     //ADD CONTACT OPTION
            system("cls");
			cout << "\n\n\tEnter First Name : ";
	        cin >> fname[i];
            cout << "\n\tEnter Last Name : ";
            cin >> lname[i];
            cout << "\n\tEnter Phone Number : ";
            cin >> contact[i];
            findFirst[i] = fname[i];
            findLast[i] = lname[i];
            fullName[i] = (fname[i].append("  ")).append(lname[i]); //concatenation of first name and last name
            i++;        
			break;
        case 2:                                                                     //SEARCH CONTACT OPTION
			cout << "\n\tEnter a name: ";
            cin >> keyword;
            for(int j = 0; j < i; j++){
                if(keyword == findFirst[j] || keyword == findLast[j]){
                    found = true;
                    temp = j;
                    break;
                }
            }
            if(found == true){
                system("cls");
                cout << "\n\n\tFull Name : " << fullName[temp];
                cout << "\n\n\tContact: " << contact[temp] << endl;
                found = false;
                system("pause > 0");
                break;
                }
            else{
                cout << "Contact Not Found!" << endl;
                system("pause > 0");
            }
			break;
        case 3:                                                                      //DISPLAY/SHOW CONTACT OPTION
                system("cls");
                cout << "\tContact List\n";
                if(i == 0){
                    cout << "No Contact Found!\n";}
                else{
                    for(int j = 0; j < i; j++)
                        cout << j+1 << ". " << setw(20) << left << fullName[j] << setw(15) << left << contact[j] <<endl;
                }
                system("pause > 0");
                break;
        case 4:                                                                     //EDIT CONTACT OPTION
                system("cls");
                cout << "\tContact List\n";
                if(i == 0){
                    cout << "No Contact Found!\n";}
                else{
                    for(int j = 0; j < i; j++)
                        cout << j+1 << ". " << setw(20) << left << fullName[j] << setw(15) << left << contact[j] <<endl;
                }
                do{   
                    cout << "\n\tSelect which contact you would like to edit\n\t>";
                    cin >> choice;
                    if(choice < 1 || choice > i)
                    {
                        cout << "\n\tThe contact you entered doesn't exist, please try again\n";
                    }
                }while(choice < 1 || choice > i);
                contact[choice - 1].clear();
                fullName[choice - 1].clear();
                fname[choice - 1].clear();
                lname[choice - 1].clear();
                findFirst[choice - 1].clear();
                findLast[choice - 1].clear();

                system("cls");
			cout << "\n\n\tEnter First Name : ";
	        cin >> fname[choice - 1];
            cout << "\n\tEnter Last Name : ";
            cin >> lname[choice - 1];
            cout << "\n\tEnter Phone Number : ";
            cin >> contact[choice - 1];
            findFirst[choice - 1] = fname[choice - 1];
            findLast[choice - 1] = lname[choice - 1];
            fullName[choice - 1] = (fname[choice - 1].append("  ")).append(lname[choice - 1]);
            system("cls");
            cout << "Contact Updated!" << endl;
            system("pause > 0");
                break;
        case 5:                                                             //EXIT
                goto end;
            default :
                system("cls");
                cout << "Invalid Input!" << endl;
                system("pause > 0");
                    break;
		}
	}while(choice != 5);
    end:
    return 0;
}