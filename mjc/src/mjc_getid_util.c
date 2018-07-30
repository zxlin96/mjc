#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mjc.h"
#include "mjc_strutl.h"
#include "mjc_type.h"
#include "log.h"
#include "mjc_utl.h"

static U16 G_ORDER = 0;

U16 mjc_get_order()
{
    U16 order;

    //lock
    G_ORDER++;
    if (G_ORDER == 0)
    {
        G_ORDER = 1;
    }
    //unlock
    order = G_ORDER;
    return order;
}

/*
 * 将字符转换为数值
 * */
int mjc_c2i_util(char ch)
{
    DBG_PRINTF("================== mjc_c2i_util\n");
    // 如果是数字，则用数字的ASCII码减去48, 如果ch = '2' ,则 '2' - 48 = 2
    if (isdigit(ch))
        return ch - 48;

    // 如果是字母，但不是A~F,a~f则返回
    //if (ch < 'A' || (ch > 'F' && ch < 'a') || ch > 'z')
    if(!((ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F')))
        return -1;

    // 如果是大写字母，则用数字的ASCII码减去55, 如果ch = 'A' ,则 'A' - 55 = 10
    // 如果是小写字母，则用数字的ASCII码减去87, 如果ch = 'a' ,则 'a' - 87 = 10
    if (isalpha(ch))
        return isupper(ch) ? ch - 55 : ch - 87;

    return -1;
}

/*
 * 功能：将十六进制字符串转换为整型(int)数值
 * */
U16 mjc_hex2dec_util(char *hex)
{
    int len = 0;
    U16 num = 0;
    int temp = 0;
    int bits = 0;
    int i;

    DBG_PRINTF("====================> mjc_hex2dec_util\n");
    // 此例中 hex = "1de" 长度为3, hex是main函数传递的
    len = mjc_strlen(hex);

    for (i = 0, temp = 0; i < len; i++, temp = 0)
    {
        // 第一次：i=0, *(hex + i) = *(hex + 0) = '1', 即temp = 1
        // 第二次：i=1, *(hex + i) = *(hex + 1) = 'd', 即temp = 13
        // 第三次：i=2, *(hex + i) = *(hex + 2) = 'd', 即temp = 14
        temp = mjc_c2i_util(*(hex + i));
        if (temp == -1)
        {
            DBG_PRINTF("char to int error!!!\n");
            goto TAG_EXIT;
        }
        // 总共3位，一个16进制位用 4 bit保存
        // 第一次：'1'为最高位，所以temp左移 (len - i -1) * 4 = 2 * 4 = 8 位
        // 第二次：'d'为次高位，所以temp左移 (len - i -1) * 4 = 1 * 4 = 4 位
        // 第三次：'e'为最低位，所以temp左移 (len - i -1) * 4 = 0 * 4 = 0 位
        bits = (len - i - 1) * 4;
        temp = temp << bits;

        // 此处也可以用 num += temp;进行累加
        num = num | temp;
    }

    DBG_PRINTF("<==================== mjc_hex2dec_util");
    // 返回结果
    return num;
TAG_EXIT:
    return 0;
}