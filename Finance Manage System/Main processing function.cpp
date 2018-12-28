#include<bits/stdc++.h>
//(1)查询处理
//函数名称；search_data
//函数功能；用于处理收入和支出（在调用过程中有参数决定）的查询操作。
//处理流程；
//1.提示用户按照指定格式输入要查询的年月，如果用户输入错误，则给出提示信息;如果用户输入正确，则在单链表中查找该年月的收入信息。
//2.如果查找成果能够，判断查询结果个数是否小于 9，调用函数 show_info()显示找到的收入信息;如果大于9，按空格进行翻页操作。
//3.如果没有找到任何信息，系统给出提示信息。
//4.提示用户是否继续查询，如果用户输入“Y”或“y”，则再次进行查询操作;否则，返回主菜单界面。
void search_data(fi_type type)
{
	int year = 0;
	int month = 0;
	fi_data *p =NULL;
	fi_data *result[9] ={NULL};
	int count = 0;
	char input = ' ';
	
	while(1)
	{
		printf(">请输入要查询的年月（例如；2009/1）");
		if(scanf("%d/%d",&year,&month) !=2)
		{
			printf(">输入错误。\n");
		}
		else
		{
			p = head;
			count = 0;
			memset(result, 0, sizeof(fi_data*));
			while(p != NULL)
			{
				if(p->info.year == year
				   && p->info.month == month
				   && p->info.type == type)
			{
				if (count < 9)
				{
					result[count] = p;
					count++; 
				}
				else
				{
					show_info(result, count);
					printf(">输入空格并回车翻页。其他键退出。");
					fflush(stdin);
					input = getchar();
					if (input ==' ')
					{
					                          	memset(result, 0, sizeof(fi_data*));
					                          	count = 0;
					                          	result[count] = p;
					                          	count++;
					} 
					else
					{
						break;
					}
				}
				   }
				   p = p->next;
			}
			if (count != 0)
			{
				show_info(result, count);
			}
			else
			{
				printf(">没有找到数据。\n");
			}
			printf(">继续查找其他数据? (y or n)");
			fflush(stdin);
			input = getchar();
			if (input == 'y' || input == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
 } 
 //(2)删除处理
 //函数名称；delete_data
 //函数功能；用于处理收入与支出（在调用过程中由参数决定）的删除操作。
 //处理流程；
 //1.提示用户输入要删除收入的年月，然后根据用户输入的年月信息在单链表中查找相关信息。
 //2.如果查找成功，且查找到的数据小于9，则直接调用 show_info()函数显示查找到的收入信息;如果查到的数据大于9条信息，则按空格键翻页。
 //3.最后提示用户输入要删除的收入信息的序号，完成删除的操作。
 //4.如果查找不成功，则给出相应的提示信息。
 //5.提示用户是否继续删除的操作，如果用户输入“Y”或“y”，则在进行查找操作;否则，返回主菜单界面。
 void delete_data(fi_type type)
 {
 	int year = 0;
 	int month = 0;
 	fi_data *p =NULL;
 	fi_data *pre = NULL;
 	fi_data *result[9] = {NULL};
 	int count = 0;
 	char input = ' ';
 	int i = 0;
 	
 	while(1)
	 {
	 	printf(">请输入要查询的年月（例如；2009/1)");
	 	if (scanf("%d/%d",&year, &month) != 2)
	 	{
	 		printf(">输入错误。\n");
		 }
		 else
		 {
		 	p = head;
		 	count = 0;
		 	memset(result, 0, sizeof(fi_data*));
		 	while(p != NULL)
		 	{
		 		if (p->info.year == year
				    && p->info.month == month
					&& p->info.type == type)
				{
					if (count < 9)
					{
					     result[count] = p;
						 count++;	
					}
				else
				{
					show_info(result, count);
					printf(">输入空格并回车翻页。输入对应的序号删除。其他键退出。"); 
					fflush(stdin);
					input = getchar();
					if (input == ' ')
					{
						memset(result, 0, sizeof(fi_data*));
						count = 0;
						result[count] = p;
						count++;
					 }
				     else if (input >='1' && input <= 48 + count)
				     {
				     	i = input - 49;
				     	pre = get_previous(result[i]);
				     	if (pre == NULL)
						 {
				     		head = head->next;
						 }
						 else
						 {
						 	pre->next = result[i]->next;
						 }
						 free(result[i]);
						 for (; i < count - 1; i++)
						 {
						 	result[i] = result[i+1];
						 }
						 result[i] = p;
						 printf(">删除成功。\n");
					 }
					 else
					 {
					 	break;
					 }
				}
					}
					p =p->next;
			 }
			 if (count != 0)
			 {
			 	show_info(result, count);
			 	printf(">输入对应的序号删除。其他键退出。");
				fflush(stdin);
				input = getchar();
				if (input >= '1' && input <= 48 +count)
				{
					i= input - 49;
					pre = get_previous(result[i]);
					if (pre == NULL)
					{
						head = head->next;
					}
					else
					{
						pre->next = result[i]->next;
					}
					free(result[i]);
					for (; i<count - 1;i++)
					{
						result[i] = result[i++];
					}
					result[i] = NULL;
					count--;
					printf(">删除成功。\n");
				} 
			 }
			 else
			 {
			 	printf(">没有找到数据。\n");
			 }
			 printf(">继续查找其他数据？（y or n)");
			 fflush(stdin);
			 input = getchar();
			 if (input == 'y' || input =='Y')
			 {
			 	continue;
			  } 
			  else
			  {
			  	break;
			  }
		 }
	 }
  } 
//(3)更新处理
//函数名称；update_data
//函数功能；用于处理收入喝支出（在调用过程中由参数决定）的更新操作。
//处理流程；
//1.首先提示用户输入要更新收入或支出的年月，然后根据用户输入的年月信息在单链表中查找相关信息。
//2.如果查找成功，且查找到的数据小于9，则直接调用 show_info()函数显示查找到的收入或支出信息;如果大于9，则按空格键翻页。
//3,。最后提示用户输入要更新的收入或支出信息的序号，调用input_info()函数输入更新的收入或支出信息，完成更新操作。
//4.如果查找不成功，则给出相应的提示信息。
//5.提示用户是否继续更新操作，如果用户输入“Y”或“y”，则再次进行查询操作;否则，返回主菜单界面。
void update_data(fi_type type)
{
	int year = 0;
	int month = 0;
	fi_data *p = NULL;
	fi_data *pre = NULL;
	fi_data *result[9] ={NULL};
	int count = 0;
	char input = ' ';
	int i=0;
	
	while(1){
		printf(">请输入要查询的年月（例如；2001/1）");
		if (scanf("%d/%d",&year, &month) !=2)
		{
			printf(">输入错误。\n");
		}
		else
		{
			p = head;
			count = 0;
			memset(result, 0, sizeof(fi_data*));
			while(p != NULL)
			{
				if (p->info.year == year
				&& p->info.month == month
				&& p->info.type == type)
				{
					if (count < 9)
					{
						result[count] = p;
						count++;
					}
					else
					{
						show_info(result, count);
						printf(">输入空格并回车翻页。输入对应的序号修改。其他键退出。");
						fflush(stdin);
						input = getchar();
						if ( input == ' ')
						{
							memset(result, 0, sizeof(fi_data*));
							count = 0;
							result[count] = p;
							count++;
						 } 
						 else if (input >= '1' && input <= 48 + count)
						 {
						 	i= input -49;
						 	input_info(&(result[i]->info));
						 	printf(">修改成功。\n");
						 	p = get_previous(p);
						 }
						 else
						 {
						 	break;
						 }
					}
				}
				p = p->next;
			}
			if (count != 0)
			{
				show_info(result, count);
				printf(">输入对应的序号修改。其他键退出");
				fflush(stdin);
				input = getchar();
				if (input >= '1' && input <= 48 + count)
				{
					i= input - 49;
					input_info(&(result[i]->info));
					show_info(result, count);
					printf(">修改成功。\n");
				 } 
			}
			else
			{
				printf(">没有找到数据。\n");
			}
			printf(">继续查找其他数据？（y or n）");
			fflush(stdin);
			input = getchar();
			if (input == 'y' || input == 'Y')
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
 } 
