#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

stack<string> s;
queue<string> q;

void chuyenTrungToSangHauTo(string);
void tinhKetQuaHauTo();
int ganGiaTriChoToanTu(string);
int chuyenStringThanhSo(string);
string chuyenSoThanhString(int);
bool kiemTraSo(char);
void xuatQueue(queue<string>);
void xuatStack(stack<string>);

int main()
{
    string exp;
    cout << "Nhap vao 1 bieu thuc: ";
    getline(cin, exp);
    chuyenTrungToSangHauTo(exp);
    xuatQueue(q);
    tinhKetQuaHauTo();
    return 0;
}

bool kiemTraSo(char c)
{
    return (c >= '0' && c <= '9'); //tra ve true neu nhu c trong doan tu '0' den '9'
}

int ganGiaTriChoToanTu(string str)
{
    int n{};
    if (str == "+" || str == "-")
        n = 1;
    else if (str == "*" || str == "/")
        n = 2;
    else if (str == "(")
        n = 0;
    return n;
}

int chuyenStringThanhSo(string str)
{
    int n{};
    while (str.length())
    {
        int m = str[0] - '0';
        n = n * 10 + m;
        str.erase(str.begin() + 0);
    }
    return n;
}

string chuyenSoThanhString(int n)
{
    string str{};
    if (!n)
        str = "0";
    while (n)
    {
        int m = n % 10;
        str.insert(str.begin(), m + '0');
        n = n / 10;
    }
    return str;
}

void chuyenTrungToSangHauTo(string exp)
{
    bool KT = false;
    string c;
    while (exp.length()) //duyet den bao gio do dai bieu thuc = 0
    {
        if (kiemTraSo(exp[0])) //kiem tra ki tu dau tien cua bieu thuc la so
        {
            c.insert(c.begin() + c.length(), exp[0]); //them vao sau ki tu dau tien la so
            exp.erase(exp.begin() + 0);               //xoa ki tu dau tien
            if (!exp.length())                        //neu bieu thuc het va ket thuc la 1 so thi ta them truc tiep vao queue
            {
                q.push(c);
            }
            KT = true;
        }
        else
        {
            if (KT)
            {
                q.push(c); //push so vao trong queue
                c = "";    //set lai chuoi c
                KT = false;
            }
            //=====================xu li toan tu===========================

            if (exp[0] == '(') // toan tu dang xet la (, push vao stack
            {
                string c1 = "(";
                s.push(c1);
            }
            else if (exp[0] == ')') //toan tu dang xet la ), xet den bao gio gap toan tu ( thi dung
            {
                while (true)
                {
                    string c2 = s.top();
                    s.pop();
                    if (c2 == "(")
                    {
                        break;
                    }
                    else
                    {
                        q.push(c2);
                    }
                }
            }
            //toan tu dang xet la +,-,*,/
            else if (exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/')
            {
                string c1;
                c1.insert(c1.begin()+0,exp[0]);
                int k = ganGiaTriChoToanTu(c1);
                while (true)
                {
                    //neu stack empty
                    if (s.empty())
                    {
                        s.push(c1);
                        break;
                    }
                    string c2 = s.top();
                    int m = ganGiaTriChoToanTu(c2);
                    if (k > m)
                    {
                        s.push(c1);
                        break;
                    }
                    else
                    {
                        q.push(c2);
                        s.pop();
                    }
                }
            }
            exp.erase(exp.begin() + 0);
        }
    }
    while (!s.empty())
    {
        string c = s.top();
        s.pop();
        q.push(c);
    }
}

void xuatQueue(queue<string> q)
{
    string c;
    cout << "Bieu thuc hau to: ";
    while (!q.empty())
    {
        c = q.front();
        q.pop();
        cout << c << " ";
    }
    cout << endl;
}
void xuatStack(stack<string> s)
{
    string r;
    while (!s.empty())
    {
        r = s.top();
        s.top();
        cout << r << " ";
    }
}
void tinhKetQuaHauTo()
{
    string c;
    while(!q.empty())
    {
        c = q.front();//lay phan tu dau tien cua queue sau do pop no ra khoi queue
        q.pop();
        if(ganGiaTriChoToanTu(c))//neu c la toan tu
        {
            string c1 = s.top();//phan tu ngoai cung cua stack
            int s2 = chuyenStringThanhSo(c1);
            s.pop();//lay xong thi pop no ra
            c1 = s.top();//phan tu thu 2 ngoai cung cua stack
            int s1 = chuyenStringThanhSo(c1);
            s.pop();//lay xong thi pop no ra
            if(c == "+")
            {
                s2 = s1 + s2;
            }
            else if(c == "-")
            {
                s2 = s1 - s2;
            }
            else if(c == "*")
            {
                s2 = s1 * s2;
            }
            else if(c == "/")
            {
                s2 = s1/s2;
            }
            //sau khi co duoc kq thi doi sang string roi push vao stack
            c1 = chuyenSoThanhString(s2);
            s.push(c1);
        }
        else // neu c la toan hang thi push vao stack
        {
            s.push(c);
        }
    }
    //sau khi thuc hien xong queue rong va stack con 1 phan tu, lay top no ra, pop phan tu cuoi cung cua stack
    c = s.top();
    s.pop();
    cout << "Ket qua thu duoc: " << c << endl;
}