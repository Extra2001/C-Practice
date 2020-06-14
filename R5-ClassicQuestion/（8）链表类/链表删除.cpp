#include<stdio.h>
#include<stdlib.h>
struct stu_node
 {    int  num ; 
      float  score ;
      struct stu_node *next ;
 };
#define  LEN  sizeof(struct stu_node)
struct stu_node *creat( void )       //函数返回值为链表的头指针
{   struct stu_node  *p1, *p2, *head=NULL;       
     p1=p2=( struct stu_node *) malloc (LEN);  //令p1、p2指向新结点
    scanf("%d%f", &p1->num, &p1->score);   //输入新结点数据成员
    while ( p1->num != 0 )      //判断新结点的学号是否为0
    {    if ( head==NULL )     //若头指针为空，则令头指针指向表头结点
                head = p1;
          else                          
               p2->next = p1;    //否则令当前表尾结点指针成员指向新结点
          p2 = p1;                    //p2指向新的表尾结点
          p1 = ( struct stu_node *) malloc (LEN);     //p1指向新结点
          scanf("%d%f", &p1->num, &p1->score) ;
     }
    p2->next = NULL;         //表尾结点的指针成员赋空值
    free(p1);                         //释放p1指向的结点空间 
    return(head);                //返回头指针 
}
void list(struct stu_node *head)
{    struct stu_node *p;
     if (head==NULL)   printf("链表为空！\n"); 
     else
         {    printf("链表信息如下:\n");
               p=head;                //p赋值为head，即p指向表头结点
               while (p!=NULL)
                  {    printf("%d %5.2f\n", p->num, p->score);
                        p=p->next;          //令p指向下一个结点
                   }
          }
}
struct stu_node *del(struct stu_node *head,int num)
{
	struct stu_node *p1,*p2=NULL;
	if(head==NULL)
	printf("表头为空不能操作");
	else
	{
		p1=head;
		while((num!=p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(num==p1->num)
		{
			if(p1==head)head=p1->next;
			else
			p2->next=p1->next ;
			free(p1);
		}
		else printf("链表中不存在该结点"); 
	 } 
	 return head;
}
int main()
{
	struct stu_node *head;
	int num;
	head=creat();
	printf("输入的链表：\n");
	list(head);
	printf("请输入要删除的数:");
	scanf("%d",&num);
	head=del(head,num);
	printf("输出的链表：\n");
	list(head);
	return 0;
		 }		 
		 
		
 
 
 
 

