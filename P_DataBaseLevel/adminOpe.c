 /*���ݿ��е�����
        string _name;//ԤԼ������
        string _id;//ԤԼ�����֤��
        string _place;//ԤԼ��ԤԼ�����
        string _phone;//ԤԼ�˵绰����
        bool _rec;//�Ƿ���ҪԤԼƾ֤
        Date _date;//ԤԼ����ʱ��
        */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *Description: ����Ա����ģ��
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "adminOpe.h"
#include "admin.h"
#include <stdio.h>
int adminOpe_show_window()
{
   int cmd=0;
   system("cls");
   printf("\n                   ����Ԥ������ϵͳ");
   printf("\n                         (v2.80)        ");
   printf("\n                ------------------------- ");
   printf("\n                        ����Աģʽ");
   printf("\n                         ��¼�ɹ�");
   printf("\n                ------------------------- ");
   printf("\n   ��ӭ�㣬����Ա��");
   printf("\n   ��ѡ����Ҫִ�е����");
   printf("\n   1:���ݲ�ѯ");
   printf("\n   2:�����޸�");
   printf("\n   3:����ȷ��");
   printf("\n   0:����������");
   printf("\n   ������(0-3):");
   fflush(stdin);
   scanf("%d",&cmd);
   return cmd;
}
/*
 * ������:adminOpe_call_back
 * ��  ��:����Ա���ĺ�̨����ģ��
 * ��  ��:
 *           int cmd ����Ա���������
 * ��  ��:   ��
 * ����ֵ:   ����Ա���������
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
 * ������:query
 * ��  ��:��ѯ���ݿ��е���Ϣ
 * ��  ��:   ���ݿ��е���Ϣ
 */
void query() {

}

/*
 * ������:change
 * ��  ��:�޸����ݿ��е���Ϣ
 */

void change(){
}


/*
 * ������:adminOpe
 * ��  ��:����Ա������ģ��
 * ��  ��:  int cmd
 * ��  ��:  ��
 * ����ֵ: ����Ա���������
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
