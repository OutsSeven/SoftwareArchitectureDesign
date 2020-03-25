#include"p_DataBaseOp.h"

using namespace DBHelper;

int main(void)
{
	const string host = "localhost";  //因为是作为本机测试，所以填写的是本地IP
	const string user = "root";       //连接MySQL的用户名
	const string passwd = "abcdefg"; //你的用户密码
	const string db = "bookstore";      //所要连接的数据库的名字
	unsigned int port = 3306;           //这是MySQL的服务器的端口，如果没有修改过的话就是3306。
	const char* unix_socket = NULL;    


	DBConf dbc(host, user, passwd, db, "GBK", port);
	p_DataBaseOp dbo(dbc);
	/*OrderInfo ori1 = dbo.selectOrder("350802200003052010",true);
	OrderInfo ori2("ty", "3508", "A", "188", false, string("2020-03-25"));
	dbo.deleteOrder("350802200003052010", true);
	dbo.addOrder(ori2);*/
	//MaskInfo mi1("A", "N95", 200);
	//dbo.addMaskInfo(mi1);
	////dbo.deleteMaskInfo("A", "N95");
	//MaskInfo mi2 = dbo.selectMaskInfo("A", "N95");
	
	return 0;
}