#include "sys.h"
#include "usart.h"
//C��
#include "string.h"
#include "stdlib.h"

#include "rgb.h"

#pragma import(__use_no_semihosting)
//��׼����Ҫ��֧�ֺ���
struct __FILE
{
    int handle;

};

FILE __stdout;
//����_sys_exit()�Ա���ʹ�ð�����ģʽ
_sys_exit(int x)
{
    x = x;
}
//�ض���fputc����
int fputc(int ch, FILE* f)
{
    while((USART1->SR & 0X40) == 0); //ѭ������,ֱ���������
    USART1->DR = (u8) ch;
    return ch;
}

void UART1_Config(u32 bound)
{
    //GPIO�˿�����
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);	//ʹ��USART1��GPIOAʱ��

    //USART1_TX   GPIOA.9
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//�����������
    GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.9

    //USART1_RX	  GPIOA.10��ʼ��
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
    GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.10

    //Usart1 NVIC ����
    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3 ; //��ռ���ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		//�����ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
    NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ���

    //USART ��ʼ������

    USART_InitStructure.USART_BaudRate = bound;//���ڲ�����
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;//�ֳ�Ϊ8λ���ݸ�ʽ
    USART_InitStructure.USART_StopBits = USART_StopBits_1;//һ��ֹͣλ
    USART_InitStructure.USART_Parity = USART_Parity_No;//����żУ��λ
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//�շ�ģʽ

    USART_Init(USART1, &USART_InitStructure); //��ʼ������1
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);//�������ڽ����ж�
    USART_Cmd(USART1, ENABLE);                    //ʹ�ܴ���1

}
uint8_t rx_buf[100];
uint8_t rx_len;
void USART1_IRQHandler(void)                	//����1�жϷ������
{
	uint8_t dat;
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
    {
        dat = USART_ReceiveData(USART1);	//��ȡ���յ�������
//		USART_SendData(USART1, dat);
		if(dat == '*')	
		{
		//R123G123B213*
//			printf("%s %d", rx_buf, rx_len);
			ParseCmd(rx_buf, rx_len);
			memset(rx_buf, 0, rx_len);
			rx_len = 0;
		}
		else
		{
			rx_buf[rx_len++] = dat;
		}	
	}
}


void ParseCmd(char *rx_buf, size_t len)
{
    uint8_t R_Num, G_Num, B_Num;    
    char R_Str[20], G_Str[20], B_Str[20];
    char *R, *G, *B;

    len = strlen(rx_buf);
    R = strstr(rx_buf, "R");
    G = strstr(rx_buf, "G");
    B = strstr(rx_buf, "B");

    strncpy(R_Str, R+1, G-R-1);
    R_Str[G-R-1] = '\0';
    strncpy(G_Str, G+1, B-G-1);
    G_Str[B-G-1] = '\0';
    strncpy(B_Str, B+1, len - (B - rx_buf)-1);
    B_Str[len - (B - rx_buf)-1] = '\0';
//    printf("R:-%s-,\r\nG:-%s-,\r\nB:-%s-,\r\n", R_Str, G_Str, B_Str);

    R_Num = atoi(R_Str);
    G_Num = atoi(G_Str);
    B_Num = atoi(B_Str);
//    printf("%d %d %d", R_Num, G_Num, B_Num);

	SetDutyCycle(R_LED, R_Num);
	SetDutyCycle(G_LED, G_Num);
	SetDutyCycle(B_LED, B_Num);
}

