/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Filename:m998.c
 * Author:   Packy Zhou
 *
 *Description: ����Ա��¼ģ��
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * ������:admin_show_window
 * ��  ��:����Ա��½��ģ��
 * ��  ��:   char glyname[64] ����Ա�û���
 *           char glypwd[64]  ����Ա����
 * ��  ��:   ��
 *
 * ����ֵ: ����Ա���������
 */
int admin_show_window()
{
    char glyname[64]=gly1;
    char glypwd[64]=gly2;
    char name[64];
    char pwd[64];
   system("cls");
   printf("\n                   ����Ԥ������ϵͳ");
   printf("\n                ------------------------- ");
    printf("\n                        ����Աģʽ");
    printf("\n                         ���ڵ�¼");
    printf("\n                ------------------------- ");
   printf("\n����Ա�˺ţ�");
   fflush(stdin);
   gets(name);
   printf("\n����Ա���룺");
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
 * ������:admin_call_back
 * ��  ��:����Ա��̨����ģ��
 * ��  ��:
 *           int cmd ����Ա���������
 * ��  ��:   ��
 * ����ֵ:   0
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
    printf("\nWARRNING:����Ա���������!");
    printf("\n  ��ѡ����Ҫִ�е����");
   printf("\n   1:���µ�¼");
   printf("\n   0:����");
   printf("\n������(0-1):");
   scanf("%d",&cmd);
   if(cmd == 1)
    m998();
    else if(cmd == 0)
    m0();
    return 0;
}
/*
 * ������:adminOpe
 * ��  ��:����Ա������ģ��
 * ��  ��:  int cmd
 * ��  ��:  ��
 * ����ֵ: ����Ա���������
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
