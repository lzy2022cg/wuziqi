#include <stdio.h> //基本输入输出头文件
#include "graphics.h" //图形库头文件

//五子棋
int main()
{
    int i, x, y;
    initgraph(640, 640); //打开图形库窗口

    fillrectangle(20, 20, 620, 620); //画填充矩形

    setlinestyle(0, 0); //设置画线颜色为黑色
    setlinecolor(BLACK); //设置画线样式为实线，画线宽度为0像素

    for (i = 1; i <= 15; i++) //循环：用于做重复的事情
    {
        line(40, 40 * i, 600,40 * i);             //横线
        line(40 * i, 40, 40 * i, 600);            //竖线
    }

    MOUSEMSG msg; //定义鼠标消息变量

    int color = WHITE; //color代表当前棋子颜色（默认为黑色）
    setfillcolor(WHITE);

    while (1) //使用while循环重复获取鼠标消息
    {
        msg = GetMouseMsg(); //获取鼠标消息

        if (msg.uMsg == WM_LBUTTONUP) //如果鼠标左键弹起则画圆
        {
            //鼠标点击位置以40为单位取整
            x = (msg.x + 20) / 40 * 40;
            y = (msg.y + 20) / 40 * 40;

            if (x >= 40 && x <= 600 && y >= 40 && y <= 600)
            { //只能在40到600之间下棋
                fillcircle(x, y, 18); //画填充圆
            }

            if (WHITE == color)
            { //如果棋子颜色为白色，下次下黑棋
                setfillcolor(BLACK);
                color = BLACK;
            }
            else if (BLACK == color)
            { //如果棋子颜色为黑色，下次下白棋
                setfillcolor(WHITE);
                color = WHITE;
            }
        }
    }

    closegraph(); //关闭图形库窗口

    return 0;
}