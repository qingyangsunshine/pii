#include<stdio.h>
#include<limits.h>

char *itobs(int n,char *ps);
void show_bstr(const char *str);//void�������÷������ں�������ֵ��λ���ϣ���ʾ����Ҫ����ֵ������
//���ڲ���λ��ʱ����ʾ�˺��������ܲ���

int main(void)
{
	char bin_str[CHAR_BIT * sizeof(int)+1];//int���ڴ�����ռ���ֽ���+1
	int number;
	puts("Enter integers and see them in binary");//���ַ����������Ļ������\0ֹͣ
	puts("Non-numeric input terminates program");
	while(scanf("%d",&number)==1)     //scanf�ķ���ֵ�ǰ���ָ���ĸ�ʽ����ȷ�������ݵĸ���
//����n����������ȷʱ������ֵΪn-1
	{
		itobs(number,bin_str);
		printf("%d is",number);
		show_bstr(bin_str);
		putchar('\n');
	}
	puts("Bye!");

	return 0;
}

char *itobs(int n,char *ps)
{
	int i;
	const static int size=CHAR_BIT*sizeof(int);//const����ֻ�������Ĺؼ��֣�����
	//�����ڶ���ʱͬʱ��ֵ������ָ���ǲ���ͨ��ָ�����ı䳣����ֵ��Ҳ���ܸı�ָ��ĵ�ַ
	//��������ͨ�������������ı�ֵ��ע�⣬ָ�뱾�����ָ������ݿ��Զ���ֻ����
	//int const*const p5;
	/*    constant��define������
	1��const���峣��ʱ�����ͣ�define����
	2��const���ڱ�������ʱ�����ã�define����Ԥ����׶�������
	3��defineֻ�Ǽ򵥵��滻û�����͵ļ��
	4��const�������¶��壬��define��ͨ��undefȡ��ĳ�����ŵĶ���
	*/

/*static
1�������α���ʱ��static���εľ�̬�ֲ�����ִֻ��һ�Σ������ӳ��˾ֲ��������������ڣ�
ֱ���������н����Ժ���ͷ�
2��static����ȫ�ֱ���ʱ�����ȫ�ֱ���ֻ���ڱ����з��ʣ�������extern�ⲿ����Ҳ������
3��static����һ�����������������ֻ���ڱ��ļ��е��ã����ܱ������ļ����á�static���εľֲ�����
�����ȫ�����ݿ�ľ�̬��������

*/

//CHAR_BIT��ʾchar���͵�λ��


for(i=size-1;i>=0;i--,n>>=1)
		ps[i]=(01&n)+'0';//����'0'��int����ת����char���ͣ�01&n�Ľ��Ϊ0��1
	ps[size]='\0';//'\0'���ַ����Ľ�����־��

/*
eg:  char str[]={'a','b','c'}
printf("%s\n",str)
�õ����Ÿ�ֵʱ�ᶪʧ'\0'.���Դ�ʱ�ַ��������޽�����־
�޸�Ϊ��char str1[5]={"abcd"}
		char str1[5]={'a','b','c','d','\0'}
		char str1[5]={'a','b','c','d'}

*/
	return ps;   
	//����������׵�ַ
}
void show_bstr(const char *str)
{
	int i=0;
	while(str[i])  // �ǲ���һ�����ַ�
	{
		putchar(str[i]);
		/*
		putchar��puts������
		putchar����ֻ�����ڵ����ַ����������һ��ֻ�����һ���ַ���puts()���׼����豸
		д�ַ���������
		*/
		if(++i%4==0 && str[i])
			putchar(' ');
		/*
		++i��i++������
		1�����ڸ�ֵ��䣬i++�ȸ�ֵ���1��++i�ȼ�1��ֵ
		i=1;y=i++;     ִ����ɺ�y=1;i=2
		i=1;y=++i;     ִ����ɺ�y=2;i=2
		2�������ж��������ʽ
		i++��ִ���ж��ټ�1
		++i�ȼ�1��ִ���ж�

		*/

	}

}
