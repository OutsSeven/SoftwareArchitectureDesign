 /*数据库中的数据
        string _name;//预约人姓名
        string _id;//预约人身份证号
        string _place;//预约人预约购买地
        string _phone;//预约人电话号码
        bool _rec;//是否需要预约凭证
        Date _date;//预约购买时间
        */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *Description: 管理员管理模块
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "adminOpe.h"
#include "admin.h"
#include <stdio.h>
int adminOpe_show_window()
{
   int cmd=0;
   system("cls");
   printf("\n                   口罩预定管理系统");
   printf("\n                         (v2.80)        ");
   printf("\n                ------------------------- ");
   printf("\n                        管理员模式");
   printf("\n                         登录成功");
   printf("\n                ------------------------- ");
   printf("\n   欢迎你，管理员：");
   printf("\n   请选择你要执行的命令：");
   printf("\n   1:数据查询");
   printf("\n   2:数据修改");
   printf("\n   3:数据确认");
   printf("\n   0:返回主界面");
   printf("\n   请输入(0-3):");
   fflush(stdin);
   scanf("%d",&cmd);
   return cmd;
}
/*
 * 函数名:adminOpe_call_back
 * 功  能:管理员中心后台处理模块
 * 输  入:
 *           int cmd 管理员输入的命令
 * 输  出:   无
 * 返回值:   管理员输入的命令
 */
int adminOpe_call_back(int cmd)
{
    if (cmd == 1)
    {
        query();
    }

    else if (cmd == 2)
       change();
    else if (cmd == 3)
        cmd = 0;

    return cmd;
}
/*
 * 函数名:query
 * 功  能:查询数据库中的信息
 * 输  出:   数据库中的信息
 */
void query() {

}

/*
 * 函数名:change
 * 功  能:修改数据库中的信息
 */

void change(){
}


/*
 * 函数名:adminOpe
 * 功  能:管理员操作主模块
 * 输  入:  int cmd
 * 输  出:  无
 * 返回值: 管理员输入的命令
 */
int adminOpe()
{
    int cmd=0;
    while(1)
    {
        cmd = adminOpe_show_window();
        adminOpe_call_back(cmd);
        if(CMD_M999_EXIT==cmd)
        {
            break;
        }

    }
    return 0;
}
