#include<stdio.h>
#include<stdlib.h>
struct stu_node
 {    int  num ; 
      float  score ;
      struct stu_node *next ;
 };
#define  LEN  sizeof(struct stu_node)
struct stu_node *creat( void )       //��������ֵΪ�����ͷָ��
{   struct stu_node  *p1, *p2, *head=NULL;       
     p1=p2=( struct stu_node *) malloc (LEN);  //��p1��p2ָ���½��
    scanf("%d%f", &p1->num, &p1->score);   //�����½�����ݳ�Ա
    while ( p1->num != 0 )      //�ж��½���ѧ���Ƿ�Ϊ0
    {    if ( head==NULL )     //��ͷָ��Ϊ�գ�����ͷָ��ָ���ͷ���
                head = p1;
          else                          
               p2->next = p1;    //�����ǰ��β���ָ���Աָ���½��
          p2 = p1;                    //p2ָ���µı�β���
          p1 = ( struct stu_node *) malloc (LEN);     //p1ָ���½��
          scanf("%d%f", &p1->num, &p1->score) ;
     }
    p2->next = NULL;         //��β����ָ���Ա����ֵ
    free(p1);                         //�ͷ�p1ָ��Ľ��ռ� 
    return(head);                //����ͷָ�� 
}
void list(struct stu_node *head)
{    struct stu_node *p;
     if (head==NULL)   printf("����Ϊ�գ�\n"); 
     else
         {    printf("������Ϣ����:\n");
               p=head;                //p��ֵΪhead����pָ���ͷ���
               while (p!=NULL)
                  {    printf("%d %5.2f\n", p->num, p->score);
                        p=p->next;          //��pָ����һ�����
                   }
          }
}
struct stu_node *insert(struct stu_node *head)
{
    struct stu_node *p0,*p1,*p2;
    p0=(struct stu_node *)malloc(LEN);
    p0->next =NULL;
    printf("����ѧ�źͳɼ���\n");
    scanf("%d %lf",&p0->num,&p0->score);
    getchar();
    if(head==NULL) head=p0;
    else
    {
    	               p1=head;
    	               while((p0->num>p1->num)&&(p1->next!=NULL))
    	               {
    	               	p2=p1; p1=p1->next ;}
    	               	if(p0->num <=p1->num )
						   {
						   	if(head==p1) head=p0;
						   	else p2->next =p0;
						   	p0->next =p1;
							} 
						else p1->next =p0;	
					   
	}
	return head;
}
int main()
{
	struct stu_node *head;
	head=creat();
	printf("���������\n");
	list(head);
	head=insert(head);
	list(head);
    return 0;
		 }		 
		 
		
 
 
 
 

