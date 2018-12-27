//1.常量定义 
#define MAX_NAME 11    		/*家庭成员姓名最大长度*/ 
#define MAX_DETAIL 21  		/*备注最大长度*/ 
#define MENU_COUNT 9 		/*菜单选项个数*/

#define DATA_FILE "fs.dat"  /*数据文件文件名*/
//2.数据结构定义
//(1)自定义枚举类型fi_type,用来表示收入和支出
typedef enum _fi_type
{
	income =  1; 									/*收入*/
	payout = -1; 									/*支出*/ 
 } fi_type;
// (2)存储家庭财务信息的结构体fi_into
typedef struct _fi_info
{
	int year;										/*年*/
	int month;										/*月*/
	fi_type type; 									/*数据类型*/
	char name[MAX_NAME];							/*家庭成员姓名*/
	float money;									/*收入或支出金额*/
	char detail[MAX_DETAIL];						/*备注*/ 
} fi_info;
//(3)存储财务数据结构的结构体fi_data
typedef struct _fi_data
{
	fi_info info;									/*财务数据*/ 
	struct _fi_data *next; 							/*指向下一个节点的指针*/ 
} fi_data;
//3.函数声明
//(1)主菜单对应的处理函数
void add_income();									/*添加收入*/	 
void search_income();								/*查询收入明细*/ 
void delete_income();								/*删除收入*/ 
void update_income();								/*修改收入*/ 
void add_payout(); 									/*添加支出*/
void search_payout();           					/*查询支出明细*/
void delete_payout();								/*删除支出*/ 
void update_payout();								/*修改支出*/
void count_total(); 								/*统计总收入总支出*/
void quit();										/*退出系统*/
//(2)主要处理函数
void search_data(fi_type type); 					/*查询处理*/ 
void delete_data(fi_type type);						/*删除处理*/
void updata_data(fi_type type);						/*更新处理*/
//(3)辅助函数
void initialize();									/*系统初始化*/
void save_to_file();								/*将财务数据保存到文件*/
void clear_data();									/*清空链表中的数据*/
fi_data *get_last();								/*得到财务数据链表的最后一个节点*/
fi_data *get_previous(fi_data *p);					/*取得财务节点p的前一个节点*/
void input_info(fi_info *info);						/*输入财务数据信息*/
void show_info(fi_data *p[],int count);				/*显示财务数据*/ 
