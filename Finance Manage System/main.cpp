#include"Finance Manage System.h"
#include<bits/stdc++.h>
using namespace std;
fi_data *head;					/*财务数据的头节点*/
char menu[] =
" ===========================================================\n "
"| 家庭财务管理系统                               |\n" 
"+----------------------------------------------------------+\n "
"| 收入管理                                       |\n"
"|		<1>添加收入                               |\n"
"|		<2>查询收入明细							  |\n"
"|		<3>删除收入                               |\n"
"|		<4>修改收入                               |\n"
"| 支出管理 									  |\n"
"|		<5>添加支出								  |\n"
"|		<6>查询支出明细                           |\n"
"|		<7>删除支出                               |\n"
"|		<8>修改支出                               |\n"
"| 统计                                           |\n"
"|		<9>统计总输入总支出						  |\n"
"+-----------------------------------------------------------+\n "
"  输入<0>退出系统								  |\n"
"+-----------------------------------------------------------+\n ";

void(*menu_fun[])()=
{
	quit,						/*退出系统*/ 
	add_income,					/*添加收入*/ 
	search_income,				/*查询收入明细*/ 
	delete_income,				/*删除收入*/ 
	update_income,				/*修改收入*/ 
	add_payout,				/*添加支出*/ 
	search_payout,				/*查询支出明细*/ 
	delete_payout,				/*删除支出*/ 
	update_payout,				/*修改支出*/ 
	count_total					/*统计总收入总支出*/ 
			 };			 
			 
			 
int main()
{
	int selected = 0;
	
	initialize();
	
	while(selected >=0 && selected <=MENU_COUNT)
	{
		system("cls");
		cout<<(menu);
		cout<<">请选择要进行的操作0-"<<MENU_COUNT;
		if((cin>>selected && selected !=1)  || selected < 0 || selected > MENU_COUNT)
		{
			cout<<">输入错误!请选择[ 0 -"<<MENU_COUNT<<"]之间的数字!按任意键重试...";
			fflush(stdin);
			getchar(); 
		 } 
		 else
		 {
		 	menu_fun[selected]();
		 }
		 selected = 0;
	 } 
 } 
 
