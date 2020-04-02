/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Filename:m998.c
 * Author:   Packy Zhou
 *
 *Description: 管理员登录模块
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * 函数名:admin_show_window
 * 功  能:管理员登陆主模块
 * 输  入:   char glyname[64] 管理员用户名
 *           char glypwd[64]  管理员密码
 * 输  出:   无
 *
 * 返回值: 管理员输入的命令
 */
int admin_show_window()
{
    char glyname[64]=gly1;
    char glypwd[64]=gly2;
    char name[64];
    char pwd[64];
   system("cls");
   printf("\n                   口罩预定管理系统");
   printf("\n                ------------------------- ");
    printf("\n                        管理员模式");
    printf("\n                         正在登录");
    printf("\n                ------------------------- ");
   printf("\n管理员账号：");
   fflush(stdin);
   gets(name);
   printf("\n管理员密码：");
   fflush(stdin);
   gets(pwd);
   if(strcmp(name,glyname)==0&&
      strcmp(pwd,glypwd)==0)
      {
          return 1;
      }

   else return 0;
}

/*
 * 函数名:admin_call_back
 * 功  能:管理员后台处理模块
 * 输  入:
 *           int cmd 管理员输入的命令
 * 输  出:   无
 * 返回值:   0
 */
int admin_call_back(int cmd)
{
    if(1 == cmd)
    {
        m999();
    }
    else if(0 == cmd)
    {
        adminlog_error();
    }
    return 0;
}
int adminlog_error()
{
    int cmd=0;
    printf("\nWARRNING:管理员或密码错误!");
    printf("\n  请选择你要执行的命令：");
   printf("\n   1:重新登录");
   printf("\n   0:返回");
   printf("\n请输入(0-1):");
   scanf("%d",&cmd);
   if(cmd == 1)
    m998();
    else if(cmd == 0)
    m0();
    return 0;
}
/*
 * 函数名:adminOpe
 * 功  能:管理员操作主模块
 * 输  入:  int cmd
 * 输  出:  无
 * 返回值: 管理员输入的命令
 */
int adminlog()
{
    int cmd =0;
    while(1)
    {
        cmd = admin_show_window();

        admin_call_back(cmd);
            break;
    }

    return cmd;
}
