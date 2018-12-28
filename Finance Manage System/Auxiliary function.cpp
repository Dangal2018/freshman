#include<bits/stdc++.h>
//(1)系统初始化
//函数名称： initialize
//函数功能；系统初始化操作，包括数据文件和单链表的初始化。
void initialize()
{
	FILE *fp = NULL;
	fi_data *p = NULL;
	fi_data *last = NULL;
	int count = 0;
	
	/*判断数据文件是否存在，如果不存在则创建一个文件*/
	fp = fopen(DATA_FILE, "rb");
	if (fp == NULL)
	{
		fp = fopen(DATA_FILE, "w");/*创建文件*/
		fclose(fp);
		return; 
	 }
	 
	 p = (fi_data*)malloc(sizeof(fi_data));
	 memset(p, 0, sizeof(fi_data));
	 p->next = NULL;
	 
	 while(fread(&(p->info),sizeof(fi_info), 1, fp) == 1)
	 {
	 	if (head == NULL)/*链表为空*/
		 {
		 	head = p;/*将头节点指向p*/ 
		  }
		  else
		  {
		  	last = get_last(); /*头节点不为空时，在链表中找到最后一个*/
			last->next = p;  /*将b连到最后一个节点之后*/ 
		  }
		  count++;
		  fseek(fp, count *sizeof(fi_info), SEEK_SET); /*将文件指针指到下一个*/
		  p = (fi_data*)malloc(sizeof(fi_data));
		  memset(p, 0, sizeof(fi_data));
		  p->next = NULL;
	  }
	  free(p);
	  p = NULL;
	  fclose(fp);
 }
 //(2)将财务数据保存到文件
 //函数名称：save_to_file
 //函数功能：将单链表中的数据保存到文件
 void save_to_file()
 {
 	FILE *fp = fopen(DATA_FILE, "wb");
 	fi_data *p = head;
	 
	 while(p != NULL)
	 {
	 	fwrite(&(p->info),sizeof(fi_info), 1, fp);
	 	fseek(fp, 0, SEEK_END);
	 	p = p->next;
	   }  
	   fclose(fp);
	 } 
//(3)清空链表中的数据
//函数名称：clear_data
//函数功能：退出系统时调用该函数，清空单链表中的数据
void clear_data()
{
	fi_data *p = NULL;
	
	while (head != NULL)/*链表不为空*/
	{
		if (head->next!=NULL)/*如果链表中有2条以上的数据*/
		{
			p = head;
			head = head->next;/*头节点向后移动一位*/
			free(p);/*释放原来的头节点*/
			p = NULL; 
		 }
		 else/*清楚链表中最后一个节点*/
		 {
		 	free(head);
		 	head = NULL;
		  }
	 }
 }
 //(4)去最后一个节点
 //函数名称：get_last
 //函数功能：取得收入或支出数据链表的最后一个节点。
 fi_data *get_last()
 {
 	fi_data *p =head;
 	if (p == NULL)
 	{
 		return p;
	 }
	 while((p != NULL) && (p->next != NULL))
	 {
	 	p= p->next;
	 }
	 return p;
  }
//(5)取参数p的前一个节点
//函数名称：get_previous
//函数功能：取得收入或支出数据节点p的前一个节点。
fi_data *get_previous(fi_data *p)
{
	fi_data *previous = head;
	while(previous != NULL)
	{
		if (previous->next == p)
		{
			break;
		}
		previous = previous->next;
	}
	return previous;
 }
 //(6)输入收入或支出数据信息
 //函数名称：input_info
 //函数功能：提示用户按指定格式输入收入或支出信息
 void input_info(fi_info *info)
 {
 	printf(">请输入年月 （YYYY/M):");
 	scanf("%d/%d", &(info->year), &(info->month));
 	
 	printf(">请输入家庭成员姓名 （最大长度为 %d）:", MAX_NAME - 1);
 	scanf("%s", info->name);
 	
 	printf(">请输入金额：");
	scanf("%f", &(info->money));
	
	printf(">请输入备注 （最大长度为 %d):", MAX_DETAIL -1);
	scanf("%s", info->detail); 
  }
//(7)显示收入或支出数据
//函数名称：show_info
//函数功能：按指定格式显示收入或支出信息
void show_info(fi_data* p[], int count)
{
	int i = 0;
	
	printf("+---+---------+------+------------+------------+----------------------+\n");
	printf("|No.|  年-月 |  类型  |  姓名  |  金额  |   备注   |\n");
	printf("+---+---------+------+------------+------------+----------------------+\n");
	for (i = 0; i < count; i++ )
	{
	printf("|%3d| %4d-%02d | %4s | %-10s | %10.2f | %-20s |\n",i+1,p[i]->info.year, p[i]->info.month,p[i]->info.type == income ? "收入": "支出",p[i]->info.name,p[i]->info.money,p[i]->info.detail);		
	printf("+---+---------+------+------------+------------+-----------------------+\n");
	}
}

 
