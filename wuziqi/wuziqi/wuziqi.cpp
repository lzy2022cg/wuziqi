#include <stdio.h> //�����������ͷ�ļ�
#include "graphics.h" //ͼ�ο�ͷ�ļ�

//������
int main()
{
    int i, x, y;
    initgraph(640, 640); //��ͼ�οⴰ��

    fillrectangle(20, 20, 620, 620); //��������

    setlinestyle(0, 0); //���û�����ɫΪ��ɫ
    setlinecolor(BLACK); //���û�����ʽΪʵ�ߣ����߿��Ϊ0����

    for (i = 1; i <= 15; i++) //ѭ�����������ظ�������
    {
        line(40, 40 * i, 600,40 * i);             //����
        line(40 * i, 40, 40 * i, 600);            //����
    }

    MOUSEMSG msg; //���������Ϣ����

    int color = WHITE; //color����ǰ������ɫ��Ĭ��Ϊ��ɫ��
    setfillcolor(WHITE);

    while (1) //ʹ��whileѭ���ظ���ȡ�����Ϣ
    {
        msg = GetMouseMsg(); //��ȡ�����Ϣ

        if (msg.uMsg == WM_LBUTTONUP) //���������������Բ
        {
            //�����λ����40Ϊ��λȡ��
            x = (msg.x + 20) / 40 * 40;
            y = (msg.y + 20) / 40 * 40;

            if (x >= 40 && x <= 600 && y >= 40 && y <= 600)
            { //ֻ����40��600֮������
                fillcircle(x, y, 18); //�����Բ
            }

            if (WHITE == color)
            { //���������ɫΪ��ɫ���´��º���
                setfillcolor(BLACK);
                color = BLACK;
            }
            else if (BLACK == color)
            { //���������ɫΪ��ɫ���´��°���
                setfillcolor(WHITE);
                color = WHITE;
            }
        }
    }

    closegraph(); //�ر�ͼ�οⴰ��

    return 0;
}