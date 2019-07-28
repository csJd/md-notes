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
    cout << "           ****  欢迎来到通讯录管理系统1.0  ****";
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
            cout << "  是否保存更改? (输入'y'确定) :  ";
            cin >> op;
            if(op=='y') save();
            cout <<"  正在退出系统...  \n\n  再见~ \n";
            break;
        }
        if(cmd < 0 || cmd > 8)
            cout << "输入错误 请重新输入！\n";
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
	cout << "  #- 请按数字键选择功能 -#\n\n";
    cout << "  1. 从文件导入通讯录             2. 保存通讯录到文件\n";
    cout << "  3. 增加联系人                   4. 删除联系人\n";
    cout << "  5. 修改联系人                   6. 查找联系人\n";
    cout << "  7. 添加分组                     8. 显示通讯录\n";
    cout << "  0. 退出系统";
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
    cout << "      导入联系人成功，本次共导入 " << n << " 个联系人!";
	showline('+');
}

void save()
{
    ofstream fout("Friend.txt"), gout("Group.txt");
    gout.setf(ios::left), fout.setf(ios::left);

    int cur = 0;
    gout << setw(10) << "编号" << "组名\n";
    while(g[++cur] != "") gout << setw(10) << cur << g[cur] << endl;

    aNode *p = ab;
    fout << setw(10) << "姓名" <<setw(15) <<"拼音" << setw(6) << "性别" << setw(12)
         << "生日" << setw(13) << "电话1" << setw(13) << "电话2"
         << setw(12) << "所在地" << "分组\n";
    while(p = p->next)
    {
        fout << setw(10) << p->name << setw(15) << p->py << setw(6) << p->sex
             << setw(12) << p->bd<< setw(13) << p->tel1 << setw(13) << p->tel2
             << setw(12) << p->add << p->group << endl;
    }
	showline('+');
    cout << "  保存联系人成功!";
	showline('+');
}

void show()
{

    aNode *p = ab;
    cout.setf(ios::left);
	showline('-');
    cout << setw(10) << "姓名"  << setw(6) << "性别"<< setw(12)<< "生日" << setw(13)
         << "电话1"<< setw(13) << "电话2" << setw(12) << "所在地" << "分组";
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
    cout << "  请输入以下信息，缺失的输入'/':\n";
    cout << "  姓名：", cin>>p->name;
    cout << "\n  拼音：", cin>>p->py;
    cout << "\n  性别：", cin>>p->sex;
    cout << "\n  生日：", cin>>p->bd;
    cout << "\n  电话1：", cin>>p->tel1;
    cout << "\n  电话2：", cin>>p->tel2;
    cout << "\n  地址：", cin>>p->add;
    cout << "\n  分组编号：", cin>>p->group;
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
    cout << " 请选择：\n  1. 按姓名或拼音查找\n  2. 按电话查找\n  0. 返回主菜单";
	showline('=');
    cin >> op;
    while(op)
    {
		showline('-');
        if(op == 1)
        {
            cout << "  请输入姓名或拼音：", cin>>s;
            p = srh_na(s);
        }
        else
        {
            cout << "  请输入号码：", cin>>s;
            p = srh_tel(s);
        }
        if(p)
        {
            cout << " 您查找的联系人信息为：\n";
            cout << "  姓名：" << p->name;
            cout << "\n  性别：" << p->sex;
            cout << "\n  生日：" << p->bd;
            cout << "\n  电话1：" << p->tel1;
            cout << "\n  电话2：" << p->tel2;
            cout << "\n  地址：" << p->add;
            cout << "\n  分组：" << g[p->group];
        }
        else cout << "  未找到符合条件的联系人" ;
		showline('-');
		showline('=');
        cout << " 请选择：\n  1. 按姓名或拼音查找\n  2. 按电话查找\n  0. 返回主菜单";
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
    cout << "请输入要删除联系人的名字: ", cin>>s;
    p = srh_na(s);
    if(p)
    {
        cout << "确定要删除以下联系人吗? (输入'y'确定)\n";
        cout << " 姓名：" << p->name;
        cout << "\n 性别：" << p->sex;
        cout << "\n 生日：" << p->bd;
        cout << "\n 电话1：" << p->tel1;
        cout << "\n 电话2：" << p->tel2;
        cout << "\n 地址：" << p->add;
        cout << "\n 分组：" << g[p->group] << endl;
        cin >> op;
        if(op == 'y')
        {
            t = ab;
            while(t->next != p) t = t->next;
            t->next = p->next;
            delete p;
            cout << "删除成功!";
        }
    }
    else cout << "联系人不存在,请确认";
	showline('~');
}

void fix()
{
    string s;
    aNode *p;
	showline('#');
    cout << "请输入要修改的联系人的名字: ", cin>>s;
    p = srh_na(s);
    if(p)
    {
        cout << "请输入修改后的信息: \n";
        cout << " 姓名：" << p->name;
		cout << "\n 拼音：" << p->py<<"  ",cin >> p->py;
        cout << "\n 性别：" << p->sex<<"  ", cin >> p->sex;
        cout << "\n 生日：" << p->bd<<"  ", cin >> p->bd;
        cout << "\n 电话1：" << p->tel1<<"  ", cin >> p->tel1;
        cout << "\n 电话2：" << p->tel2<<"  ", cin >> p->tel2;
        cout << "\n 地址：" << p->add<<"  ", cin >> p->add;
        cout << "\n 分组：" << p->group<<"  ", cin >> p->group;
        cout << "\n修改成功！";
    }
    else cout << "联系人不存在,请确认";
	showline('#');
}

void addgrp()
{
    showline('+');
    cout<<"请输入要添加的分组名称：",cin>>s;
    g[gn++] = s;
    cout<<"  添加成功!\n  分组 "<<s<<" 的编号为 "<< gn-1;
    showline('+');
}
