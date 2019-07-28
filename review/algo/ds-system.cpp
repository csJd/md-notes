#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

typedef struct aNode
{
    int no, group;
    string name, sex, bd, tel1, tel2, add, py;
    aNode* next;
}*addrBook;

addrBook ab;
int n, cur, t,gn;
char flag;
string s, g[N];

void showline(char c);
void showmenu();
void open();
void save();
void show();
void add();
void del();
void fix();
void srh();
void addgrp();

int main()
{
    int cmd;
    char op;
	showline('=');
    cout << "           ****  ��ӭ����ͨѶ¼����ϵͳ1.0  ****";
	showline('=');
    gn = n = 0, ab = new aNode, ab->next = NULL;
    while(1)
    {
		showmenu();
        cin >> cmd;
        if(cmd == 1) open();
        if(cmd == 2) save();
        if(cmd == 3) add();
        if(cmd == 4) del();
        if(cmd == 5) fix();
        if(cmd == 6) srh();
        if(cmd == 7) addgrp();
        if(cmd == 8) show();
        if(cmd == 0)
        {
            cout << "  �Ƿ񱣴����? (����'y'ȷ��) :  ";
            cin >> op;
            if(op=='y') save();
            cout <<"  �����˳�ϵͳ...  \n\n  �ټ�~ \n";
            break;
        }
        if(cmd < 0 || cmd > 8)
            cout << "������� ���������룡\n";
    }
    return 0;
}

void showline(char c)
{
	puts("");
	for(int i=0; i<39 ; ++i)
		printf("%c ",c);
	puts("");
}

void showmenu()
{
	showline('=');
	cout << "  #- �밴���ּ�ѡ���� -#\n\n";
    cout << "  1. ���ļ�����ͨѶ¼             2. ����ͨѶ¼���ļ�\n";
    cout << "  3. ������ϵ��                   4. ɾ����ϵ��\n";
    cout << "  5. �޸���ϵ��                   6. ������ϵ��\n";
    cout << "  7. ��ӷ���                     8. ��ʾͨѶ¼\n";
    cout << "  0. �˳�ϵͳ";
    showline('=');
}


void open()
{

    ifstream fin("Friend.txt"), gin("Group.txt");
    gn = 1;
    getline(gin, s);
    while(gin >> n >> s) g[n] = s,gn++;
    n = 0;
    getline(fin, s);
    aNode *p = new aNode;
    while(fin >> p->name)
    {
		fin >> p->py >> p->sex >> p->bd >> p->tel1 >> p->tel2
		    >> p->add >> p->group;
        p->next = ab->next;
        ab->next = p;
        ++n;
        p = new aNode;
    }
	showline('+');
    cout << "      ������ϵ�˳ɹ������ι����� " << n << " ����ϵ��!";
	showline('+');
}

void save()
{
    ofstream fout("Friend.txt"), gout("Group.txt");
    gout.setf(ios::left), fout.setf(ios::left);

    int cur = 0;
    gout << setw(10) << "���" << "����\n";
    while(g[++cur] != "") gout << setw(10) << cur << g[cur] << endl;

    aNode *p = ab;
    fout << setw(10) << "����" <<setw(15) <<"ƴ��" << setw(6) << "�Ա�" << setw(12)
         << "����" << setw(13) << "�绰1" << setw(13) << "�绰2"
         << setw(12) << "���ڵ�" << "����\n";
    while(p = p->next)
    {
        fout << setw(10) << p->name << setw(15) << p->py << setw(6) << p->sex
             << setw(12) << p->bd<< setw(13) << p->tel1 << setw(13) << p->tel2
             << setw(12) << p->add << p->group << endl;
    }
	showline('+');
    cout << "  ������ϵ�˳ɹ�!";
	showline('+');
}

void show()
{

    aNode *p = ab;
    cout.setf(ios::left);
	showline('-');
    cout << setw(10) << "����"  << setw(6) << "�Ա�"<< setw(12)<< "����" << setw(13)
         << "�绰1"<< setw(13) << "�绰2" << setw(12) << "���ڵ�" << "����";
	showline('-');
    while(p = p->next)
    {
        cout << setw(10) << p->name  << setw(6) << p->sex << setw(12) << p->bd << setw(13)
             << p->tel1 << setw(13) << p->tel2 << setw(12) << p->add << g[p->group];
		if(p->next) puts("");
    }
	showline('-');
}

void add()
{
    aNode *p = new aNode;
	showline('+');
    cout << "  ������������Ϣ��ȱʧ������'/':\n";
    cout << "  ������", cin>>p->name;
    cout << "\n  ƴ����", cin>>p->py;
    cout << "\n  �Ա�", cin>>p->sex;
    cout << "\n  ���գ�", cin>>p->bd;
    cout << "\n  �绰1��", cin>>p->tel1;
    cout << "\n  �绰2��", cin>>p->tel2;
    cout << "\n  ��ַ��", cin>>p->add;
    cout << "\n  �����ţ�", cin>>p->group;
    p->next = ab->next;
    ab->next = p;
	showline('+');
}

aNode* srh_na(string s)
{
    aNode *p = ab;
    while(p = p->next)
        if(p->name == s || p->py == s) break;
    return p;
}

aNode* srh_tel(string s)
{
    aNode *p = ab;
    while(p = p->next)
        if(p->tel1 == s || p->tel2 == s) break;
    return p;
}

void srh()
{
    int op;
    string s;
    aNode *p;
	showline('=');
    cout << " ��ѡ��\n  1. ��������ƴ������\n  2. ���绰����\n  0. �������˵�";
	showline('=');
    cin >> op;
    while(op)
    {
		showline('-');
        if(op == 1)
        {
            cout << "  ������������ƴ����", cin>>s;
            p = srh_na(s);
        }
        else
        {
            cout << "  ��������룺", cin>>s;
            p = srh_tel(s);
        }
        if(p)
        {
            cout << " �����ҵ���ϵ����ϢΪ��\n";
            cout << "  ������" << p->name;
            cout << "\n  �Ա�" << p->sex;
            cout << "\n  ���գ�" << p->bd;
            cout << "\n  �绰1��" << p->tel1;
            cout << "\n  �绰2��" << p->tel2;
            cout << "\n  ��ַ��" << p->add;
            cout << "\n  ���飺" << g[p->group];
        }
        else cout << "  δ�ҵ�������������ϵ��" ;
		showline('-');
		showline('=');
        cout << " ��ѡ��\n  1. ��������ƴ������\n  2. ���绰����\n  0. �������˵�";
		showline('=');
        cin >> op;
    }
    cout << endl;
}

void del()
{
    string s;
    aNode *p, *t;
    char op;
	showline('~');
    cout << "������Ҫɾ����ϵ�˵�����: ", cin>>s;
    p = srh_na(s);
    if(p)
    {
        cout << "ȷ��Ҫɾ��������ϵ����? (����'y'ȷ��)\n";
        cout << " ������" << p->name;
        cout << "\n �Ա�" << p->sex;
        cout << "\n ���գ�" << p->bd;
        cout << "\n �绰1��" << p->tel1;
        cout << "\n �绰2��" << p->tel2;
        cout << "\n ��ַ��" << p->add;
        cout << "\n ���飺" << g[p->group] << endl;
        cin >> op;
        if(op == 'y')
        {
            t = ab;
            while(t->next != p) t = t->next;
            t->next = p->next;
            delete p;
            cout << "ɾ���ɹ�!";
        }
    }
    else cout << "��ϵ�˲�����,��ȷ��";
	showline('~');
}

void fix()
{
    string s;
    aNode *p;
	showline('#');
    cout << "������Ҫ�޸ĵ���ϵ�˵�����: ", cin>>s;
    p = srh_na(s);
    if(p)
    {
        cout << "�������޸ĺ����Ϣ: \n";
        cout << " ������" << p->name;
		cout << "\n ƴ����" << p->py<<"  ",cin >> p->py;
        cout << "\n �Ա�" << p->sex<<"  ", cin >> p->sex;
        cout << "\n ���գ�" << p->bd<<"  ", cin >> p->bd;
        cout << "\n �绰1��" << p->tel1<<"  ", cin >> p->tel1;
        cout << "\n �绰2��" << p->tel2<<"  ", cin >> p->tel2;
        cout << "\n ��ַ��" << p->add<<"  ", cin >> p->add;
        cout << "\n ���飺" << p->group<<"  ", cin >> p->group;
        cout << "\n�޸ĳɹ���";
    }
    else cout << "��ϵ�˲�����,��ȷ��";
	showline('#');
}

void addgrp()
{
    showline('+');
    cout<<"������Ҫ��ӵķ������ƣ�",cin>>s;
    g[gn++] = s;
    cout<<"  ��ӳɹ�!\n  ���� "<<s<<" �ı��Ϊ "<< gn-1;
    showline('+');
}
