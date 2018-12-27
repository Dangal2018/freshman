////主菜单对应处理函数
//(1).添加收入
//函数名称:add_income
//函数功能:用户在主菜单选择1的时候调用此函数,用来添加收入信息的操作.
//处理流程:首先建立单链表.调用 input_info()函数,提示用户输入收入信息,并将输入的信息存储到单链表中,输入完成后返回到主菜单界面. 
void add_income()
{
	fi_data*p = (fi_data*) malloc(sizeof(fi_data));
	memset(p,0,sizeof(fi_data));
	p->next =NULL;
	input info(&(p->info) ;
	p->info.type =income;
	if(head == NULL)
	{
		head = p; 
	}
	else
	{
		get_last(head)->next = p;
	 } 
} 
//(2)查询收入明细
//函数名称：search_income
//函数功能：用户在主菜单中选择2的时候调用此函数，用来查询收入明细的操作。函数中调用search_data()来完成收入明细的查询. 
void search_income()
{
	search_data(income);
}
//(3)删除收入
//函数名称：delete_income
//函数功能：用户在主菜单中选择3的时候调用此函数，用来删除收入信息的操作。在函数中调用delete_data()来完成收入信息的删除. 
void delete_income()
{
	delete_data(income);
}
//(4)修改收入
//函数名称：updata_income()
//函数功能：用户在主菜单选择4的时候调用此函数，用来修改收入信息的操作。函数中调用update_data()来完成收入信息的修改. 
void update_income()
{
	update_data(income);
}
//(5)添加支出
//函数名称：add_payout
//函数功能：用户在主菜单选择5的时候调用此函数，用来添加支出信息的操作；
//处理流程：首先建立单链表，调用input_info()函数提示用户输入支出信息，并将输入的信息存储到单链表中，输入完成后返回到主菜单界面. 
void add_payout()
{
	fi_data *p = (fi_data*)malloc(sizeof(fi_data));
	memset(p,0,sizeof(fi_data));
	input_info(&(p->info));
	p->info.type =payout;
	if( head == NULL )
	{
		head = p;
	 } 
	 else
	 {
	 	get_last(head)->next =p;
	 }
 } 
// (6)查询支出明细
// 函数名称：search_payout
// 函数功能：用户在主菜单选择6的hi和调用此函数，用来查询支出明细的操作。函数中调用search_data()来完成支出明细的查询。
void search_payout()
{
	search_data(payout);
 } 
//(7)删除支出
//函数名称:delete_payout 
//函数名称:用户在主菜单选择7的时候调用此函数,用来删除支出信息的操作.函数中调用delete_data()来完成支出信息的删除. 
void delete_payout()
{
	delete_data(payout);
 } 
// (8)修改支出
// 函数名称：update_payout
// 函数功能：用户在主菜单选择8的时候调用此函数，用来修改支出信息的操作。函数调用update_data()来完成支出信息的修改. 
void update_payout()
{
	update_data(payout);
}
//(9)统计总收入总支出
//函数名称：count_total
//函数功能：用户在主菜单选择9的时候进行统计的操作，在单链表中，计算收入和支出的总和，将两者相减得到家庭收入的结余，并按一定的格式显示出来. 
void count_total()
{
	float total_income = 0.0;
	float total_payout = 0.0;
	fi_data *p = head;
	
	while(p != NULL)
	{
		if(p->info.type ==income)
		{
			total_income+=p->info.money;
		}
		else
		{
			total_payout += p->ingo.money;
		}
		p =p->next;
	}
	
	cout<<"+-----------------+-----------------+-----------------+"<<endl;
	cout<<"|	合计收入	|		合计支出	|		结余 	 |<<"<<endl;
	cout<<"+-----------------+-----------------+-----------------+"<<endl;
	cout<<total_income<<"			"<<total_payout<<"			"<<total_income-total_payout<<endl;
	cout<<"+-----------------+-----------------+-----------------+"<<endl;
	cout<<">按任意键返回主菜单...";
	fflush(stdin);
	getchar(); 
}
//(10)退出系统
//函数名称：quit
//函数功能：将单链表中的数据释放，退出系统. 
void quit()
{
	save_to_file();
	clear_data();
	exit(0);
}
