//Group no.:14
//Swarnapudi Ishwar:AP21110010379
//Biswant Chevul:AP21110010380
//Durganadh : AP21110010381
//Vedashree D: AP21110010382



#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

int i, n;
float prft;
float pp;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
public:
    char name[20], pass[10];
    float rate;
    float pr; int quant;
    char id[10];
public:
    void get();
    void get2();
    void show();
    int ID(char mid[10]);
    int profit(float pro);
    int stchk(char nm[30]);
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty)
{
    if (quant >= qty)
    {
        quant -= qty;
        int x;
        cout << "\n\nStock updated.\n";
        x = pr * qty;
        cout << "\n\nTotal price to be paid:" << x << endl;
        int y;
        y = pr - rate;
        cout << "Profit: " << profit(y);
    }
    else
        cout << "\n\nInsufficient stock";
    getchar();
}

void stock::refil(int qty)
{

    quant += qty;
    cout << "\n\nStock updated.";
    getchar();


}
int stock::ID(char mid[10])
{
    if (strcmp(mid, id) == 0)
        return 0;
    else
        return 1;
}

int stock::profit(float pro) {
    prft += pro;
    return prft;
}
/*int stock::stchk(char nm[30])
{
    if(strcmp(nm,name)==0)
        return 0;
    else
        return 1;
}*/
void stock::get()
{
    cin >> id >> name >> quant >> rate >> pr;
}
void stock::get2()

{
    cin >> id >> quant;
}

void stock::show()
{

    cout << "\n" << id << "\t\t\t" << name << "\t\t\t" << quant << "\t\t\t" << rate << "\t\t\t" << pr;
}
////////////////////



class Billing : public stock
{
    //Biswanth 

public:
    char Iname[50][50], name[30][30], pno[10][10];
    int totalitems;
    float Qty[3];
    float price[3];
    float vatprice[3];
    float tprice[3];
    void input();
    void output();

};
class vat :public Billing
{
    float vats;
public:
    void vatcal();
    void outputs();
};
void Billing::input()
{
    system("CLS");

    disp();
    for (int i = 0; i < 1; i++)
    {
        cout << "Enter name : ";
        cin >> name[i];
        cout << "Enter Phone Number : ";
        cin >> pno[i];
        cout << "\nEnter number of items  :";
        cin >> totalitems;
        system("CLS");
        for (int j = 0; j < totalitems; j++)
        {
            disp();
            cout << "\nEnter name of item " << j + 1 << ": ";
            cin >> Iname[j];
            cout << "Enter quantity : ";
            cin >> Qty[j];
            cout << "Enter price of " << Iname[j] << ": ";
            cin >> price[j];
            tprice[j] = Qty[j] * price[j];
            system("CLS");
        }
    }
}
int t;
void Billing::output()
{
    int a = 0;

    ifstream infile("COUNT.TXT");
    infile >> a >> prft;

    ofstream outfile("COUNT.TXT");
    a += 1;
    t = prft + t;
    outfile << a << t;
    outfile.close();

    {
        ofstream outfile("HIS.TXT", ios::app);
        outfile << endl << "Bill No.: " << a << endl;
        outfile << "------------------------------------------------------------------------" << endl;
        cout << "\n";
        cout << "\nName : " << name[0] << "\nPhone Number : " << pno[0] << endl;
        cout << "Name of Item\tQuantity   Price  Total Price\n";
        for (int i = 0; i < 1; i++)
        {
            outfile << "\nName : " << name[i] << "\nPhone Number : " << pno[i] << endl;
            for (int j = 0; j < totalitems; j++)
            {
                outfile << "\nItem Name: " << Iname[j] << "\n Qty: " << Qty[j] << " Price: " << tprice[j] << endl;
                cout << Iname[j] << "\t\t" << Qty[j] << "\t   " << price[j] << "\t   " << tprice[j] << '\n';
            }
        }

        outfile << "------------------------------------------------------------------------" << endl;
        outfile.close();
    }
}
void vat::vatcal()
{
    input();
    /*for (int i = 0; i < totalitems; i++)
    {
        if (price[i] <= 100.00)
        {
            vatprice[i] = tprice[i] + (0.03 * tprice[i]);
        }
        else
        {
            vatprice[i] = tprice[i] + (0.1 * tprice[i]);
        }
    }*/
    vatprice[0] = pr;
}
void vat::outputs()
{
    output();

    float cash = 0, sum = 0, qty = 0, sumt = 0;

    for (int i = 0; i < totalitems; i++)
    {
        sumt += tprice[i];
        sum += vatprice[i];
        qty += Qty[i];
    }
    stock o;
    cout << "\nTotal:";
    cout << "\n------------------------------------------------------------------------------";
    cout << "\n\tQuantity= " << qty << "\t\t Sum= " << sumt << "\tWith Vat:" << qty * (price - (price - 2));
    cout << "\n------------------------------------------------------------------------------";

pay:

    cout << "\n\n\t\t\t * * * * PAYMENT SUMMARY * * * * \n";
    cout << "\n\t\t\tTotal cash given : ";
    cin >> cash;

    if (cash >= sum)
        cout << "\n\t\t\tTotal cash repaid: " << cash - sum << '\n';
    else
    {
        cout << "\n\t\t\tCash given is less than total amount!!!";

        goto pay;
    }
    system("PAUSE");
}
/////////////////////






void addnew()
{
    system("cls");
    disp();
    getchar();
    system("cls");
    cout << "\nEnter the No. of Products that you wish to add: ";
    cin >> n;
    if (n != 0)
    {
        int j, l, sum = 0;
        fout.open("shop.txt", ios::binary | ios::app);
        for (i = 0; i < n; i++)
        {
            cout << "\n\nInput ID, Input the name, quantity, rate and price of item respectively\n\n";
            st.get();
            fout.write((char*)&st, sizeof(st));
            cout << "\n\nitem updated";
            cin.get();
        }
        cout << "\n\nStock Updated!!";
        fout.close();
        cin.get();
        system("cls");
        disp();
    }
    else
    {
        fout.close();
        cin.get();
        system("cls");
        cout << "\n\nNo items to be added";
    }
}




void withdraw()
{
    Billing ob;
    vat obj;
    system("cls");
    char temp[100]; int qty;
    int i = 0;
    long pos = 0;
    disp();
    cout << "\nEnter the product's ID " << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;
    obj.vatcal();
    obj.outputs();
    fio.open("shop.txt", ios::binary | ios::out | ios::in);
    while (fio)
    {
        pos = fio.tellp();
        fio.read((char*)&st, sizeof(st));
        if (st.ID(temp) == 0)
        {
            st.withd(qty);
            fio.seekp(pos);
            fio.write((char*)&st, sizeof(st));
            i++;
            break;
        }
    }
    if (i != 1)
        cout << "\n\n!!Record not found!!";
    fio.close();
    cin.get();
    system("cls");
    disp();
    getchar();
}




void disp()
{
    system("cls");
    int i = 1;
    cout << "\n===================================================================================";
    cout << "\n=========================\tTHE STOCK ITEMS ARE\t==========================";
    cout << "\n===================================================================================\n";
    cout << "\nID NO.\t\t\tMEDICINE NAME\t\tSTOCK AVAILABLE\t\t Rate\t\t PRICE";
    cout << "\n===================================================================================\n";

    fin.open("shop.txt", ios::binary);
    while (!fin.eof())
    {
        fin.read((char*)&st, sizeof(st));
        if (!fin.eof())
        {
            if (fin.tellg() < 0)
            {
                i = 0;
                break;
            }
            st.show();
        }
    }
    if (i == 0)
    {
        cout << "\n\n\t\t\t!!Empty record room!!";
        getchar();
    }
    fin.close();

}
void refill()
{
    //system("cls");
    char temp[100]; int qty;
    int i = 0;
    long pos = 0;
    disp();
    cout << "\n\nEnter the products ID \n" << endl;
    cin >> temp;
    cout << "\n\nEnter quantity: \n" << endl;
    cin >> qty;
    fio.open("shop.txt", ios::binary | ios::out | ios::in);
    while (fio)
    {
        pos = fio.tellp();
        fio.read((char*)&st, sizeof(st));
        if (st.ID(temp) == 0)
        {

            st.refil(qty);
            fio.seekp(pos);
            fio.write((char*)&st, sizeof(st));
            i++;
            break;
        }
    }
    if (i != 1)
        cout << "\n\n!!Record not found!!";
    fio.close();
    system("cls");
    cin.get();
    disp();
    cin.get();


}
void remove()
{
    system("cls");
    disp();
    int i = 0;
    char temp[30];
    cout << "\n\t\t\t\tDelete Record";
    cout << "\n\nEnter the ID of the product:";
    cin >> temp;
    fout.open("temp.txt", ios::binary);
    fin.open("shop.txt", ios::binary);
    while (!fin.eof())
    {
        fin.read((char*)&st, sizeof(st));
        if (!fin.eof())
            if (st.ID(temp) == 0)
            {
                st.show();
                cout << "\n\n\t\tRecord deleted";
                i++;
            }
            else
                fout.write((char*)&st, sizeof(st));
    }
    if (i == 0)
        cout << "\n\n!!Record not found!!";
    fin.close();
    fout.close();
    remove("shop.txt");
    rename("temp.txt", "shop.txt");
}
int main()
{
    char pass[10], pass2[10];
    int i, j;
    /*cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO SRM MEDICAL STORE MANAGEMENT ============|";
    getchar();
    system("cls");*/
    cout << "\n\n\t\t=========================================";
    cout << "\n\t\t     MEDICAL STORE MANAGEMENT SYSTEM\n";
mainmenu:
    cout << "\t\t=========================================";
    cout << "\n\n\t\t1. Medical Stock Record Managment System\n\n\t\t2. Customer Menu\n\n\t\t3. Employee Menu";
    cout << "\n\n\t\t=========================================\n";
    cout << "\n\t\t--> Enter Your Choice : ";
    cin >> j;
    switch (j)
    {
    case 1:
    {

    dealermenu:
        system("CLS");
        cout << "\t\t=========================================";
        cout << "\n\t\t\t Medical Stock Record\n";
        cout << "\t\t=========================================";
        cout << "\n\t\t1. Add new product\n\t\t2.Display stock\n\t\t3.Refill\n\t\t4.Remove an item \n\t\t5.Profit \n\t\t6.Main Menu";
        cout << "\n\n\t\t============== END OF MENU ===============";
        cout << "\n\n\t\tEnter your Choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            addnew();
            getchar();
            goto dealermenu;
        }
        case 2:
        {

            system("cls");
            disp();
            getchar();
            getchar();
            system("cls");
            goto dealermenu;
        }
        case 3:
        {
            system("cls");
            disp();
            refill();
            goto dealermenu;
        }
        case 4:
        {
            system("cls");
            remove();
            goto dealermenu;
        }
        case 5:
        {
            system("cls");
            cout << prft << endl;
            Sleep(1000);
            getchar();
            goto dealermenu;
        }
        case 6:
        {
            system("cls");
            cout << "\n\n\n\t\t\tSRM MEDICAL STORE MANAGMENT SYSTEM";
            goto mainmenu;
        }
        }

    }

    
    case 2: {
    custmenu:
        vat obj;
        char opt, ch;
        int a = 1;
        ifstream fin;
        system("cls");
        cout << "\n\n\t\t=========================================";
        cout << "\n\t\t\t    CUSTOMER MENU";
        cout << "\n\t\t=========================================";
        cout << "\n\t\t1. Purchase\n\t\t2. Display stock\n\t\t3. Bill\n\t\t4. Clear Records\n\t\t5. Main Menu:";
        cout << "\n\t\t============== END OF MENU ===============";
        cout << "\n\n\t\tEnter your Choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            withdraw();
            getchar();
            goto custmenu;
        }
        case 2:
        {
            system("cls");
            disp();
            getchar();
            getchar();
            system("cls");
            goto custmenu;
        }
        case 3:
        {
            system("cls");
            cout << "\n\n\n\t\t\tSRM MEDICAL STORE MANAGMENT SYSTEM";
            fin.open("HIS.TXT", ios::in);
            while (fin.get(ch))
            {
                cout << ch;
            }
            fin.close();
            system("PAUSE");
            getchar();
            goto custmenu;
        }
        case 4:
        {
            system("cls");
            cout << "\n\n\n\t\t\tSRM MEDICAL STORE MANAGMENT SYSTEM";
            remove("COUNT.TXT");
            remove("HIS.TXT");
            a = 1;
            cout << "\n\tPrevious Data Cleared!" << endl;
            system("PAUSE");
            getchar();
            goto custmenu;

        }
        case 5:
        {
            system("cls");
            getchar();
            goto mainmenu;
        }

        }
    }
    case 3:
    {

    empmenu:
        system("cls");
        cout << "\n\n\t\t=========================================";
        cout << "\n\t\t\t    EMPLOYEE MENU";
        cout << "\n\t\t=========================================";
        cout << "\n\t\t1.Display stock\n\t\t2.Refill\n\t\t3.MAIN MENU";
        cout << "\n\t\t============== END OF MENU ===============";
        cout << "\n\n\t\tEnter your Choice : ";
        cin >> i;
        switch (i)
        {
        case 1:
        {
            disp();
            system("pause");
            getchar();
            goto empmenu;
        }
        case 2:
        {
            refill();
            goto empmenu;
        }
        case 3:
        {
            system("cls");
            cout << "\n\n\t\t=========================================";
            cout << "\n\t\t\t   Thank You!!\n";
            getchar();
            goto mainmenu;
        }
        }
    }

}
getchar();
}