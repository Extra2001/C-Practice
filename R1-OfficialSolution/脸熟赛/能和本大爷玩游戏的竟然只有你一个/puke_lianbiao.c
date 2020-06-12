#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char data[6];
	struct node *next;
}; 

char* pd(int num);
struct node* seek(struct node*start);
struct node *head1,*head2,*headtemp,*p1,*p2,*ptemp,*q1,*q2,*qtemp,*t1,*t2,*ttemp;
struct node *head10,*head20,*q10,*q20,*p10,*p20;
void init();



int main()
{
	
	//char a[6];
	int Q,K[1001];
	
	head10 = NULL;
	for(int i=1;i<=27;i++){
		p10=(struct node*)malloc(sizeof(struct node));
		scanf("%s",&(p10->data));
		p10->next=NULL;
		if(head10==NULL){
			head10=p10;
		}else{
			q10->next=p10;
		}
		q10=p10;
	}
	
	head20 = NULL;
	for(int i=1;i<=27;i++){
		p20=(struct node*)malloc(sizeof(struct node));
		scanf("%s",&(p20->data));
		p20->next=NULL;
		if(head20==NULL){
			head20=p20;
		}else{
			q20->next=p20;
		}
		q20=p20;
	}
	
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		scanf("%d",&K[i]);
	}
	
	for(int i=1;i<=Q;i++){
		init();
		char*jg=pd(K[i]);
		
		if(jg==NULL){
			t1=head1;
			while(t1!=NULL){
				printf("%s ",t1->data);
				t1=t1->next;
			}
			printf("\n");
			t2=head2;
			while(t2!=NULL){
				printf("%s ",t2->data);
				t2=t2->next;				
			}
			printf("\n");		
		}else{
			printf("%s\n",jg);			
		}
		
	}	
	    
	return 0;
    
}

void init(){
	head1 = NULL;
	struct node*temp00=head10;
	for(int i=1;i<=27;i++){
		p1=(struct node*)malloc(sizeof(struct node));
		strcpy(p1->data, temp00->data);
		p1->next=NULL;
		if(head1==NULL){
			head1=p1;
		}else{
			q1->next=p1;
		}
		q1=p1;
		temp00=temp00->next;
	}
	temp00=head20;
	head2 = NULL;
	for(int i=1;i<=27;i++){
		p2=(struct node*)malloc(sizeof(struct node));
		strcpy(p2->data, temp00->data);
		p2->next=NULL;
		if(head2==NULL){
			head2=p2;
		}else{
			q2->next=p2;
		}
		q2=p2;
		temp00=temp00->next;
	}
	
}

struct node* seek(struct node*start){
	if(start->next==NULL){
		return NULL;
	}
	struct node*temp = start->next;
	
	while(temp->next!=NULL&&(temp->data)[1]!=(start->data[1])){
		temp=temp->next;
	}
	if(temp->next==NULL&&(temp->data)[1]==(start->data[1])){
		//struct node*beifen=headtemp;
		headtemp=NULL;
		return temp;
	}else if((temp->data)[1]==(start->data[1])){
		struct node*beifen=temp->next;		
		temp->next=NULL;
		headtemp=beifen;
		return temp; 
	}else{
		return NULL;
	}
}

char* pd(int num){	
	headtemp=NULL;
	int turn =1;
	for(int i=1;i<=num;i++){
		if(turn==1){
			struct node*temp=head1->next;
			head1->next=NULL;
			if(headtemp==NULL){
				headtemp=head1;
				qtemp=head1;
			}
			else{
				head1->next=headtemp;
				headtemp=head1;
			}
			head1=temp;
			
			if(strcmp(headtemp->data,"JOKER")==0){
				
				if(head2->next==NULL||head2->next->next==NULL||head2->next->next->next==NULL||head2->next->next->next->next==NULL||head2->next->next->next->next->next==NULL){
					return "Zwin";
				}
				if(head1==NULL){
					head1=head2;
				}else{
					q1->next=head2;
				}
				q1=head2->next->next->next->next;
				head2=q1->next;
				q1->next=NULL;
				
			}else if(strcmp(headtemp->data,"joker")==0){
				if(head2->next==NULL||head2->next->next==NULL||head2->next->next->next==NULL){
					return "Zwin";
				}
				if(head1==NULL){
					head1=head2;
				}else{
					q1->next=head2;
				}
				q1=head2->next->next;
				head2=q1->next;
				q1->next=NULL;
				
			}else{
				struct node*headtempbeifen=headtemp;
				struct node*temp0=seek(headtemp);
				if(temp0==NULL){
					//continue;
				}else{					
					if(head1==NULL){
					head1=headtempbeifen;
					q1=temp0;
				    }else{
					q1->next=headtempbeifen;
					q1=temp0;
				    }
					
				}
				
			}
			turn=2;
			if(head1==NULL){
				return "Kurisuwin";
			}	
			
		}
		
		else if(turn==2){
			
			
			struct node*temp=head2->next;
			head2->next=NULL;
			if(headtemp==NULL){
				headtemp=head2;
				qtemp=head2;
			}
			else{
				head2->next=headtemp;
				headtemp=head2;
			}
			head2=temp;
			
			if(strcmp(headtemp->data,"JOKER")==0){
				
				if(head1->next==NULL||head1->next->next==NULL||head1->next->next->next==NULL||head1->next->next->next->next==NULL||head1->next->next->next->next->next==NULL){
					return "Kurisuwin";
				}
				if(head2==NULL){
					head2=head1;
				}else{
					q2->next=head1;
				}
				q2=head1->next->next->next->next;
				head1=q2->next;
				q2->next=NULL;
				
			}else if(strcmp(headtemp->data,"joker")==0){
				
				if(head1->next==NULL||head1->next->next==NULL||head1->next->next->next==NULL){
					return "Kurisuwin";
				}
				if(head2==NULL){
					head2=head1;
				}else{
					q2->next=head1;
				}
				q2=head1->next->next;
				head1=q2->next;
				q2->next=NULL;
				
			}else{
				struct node*headtempbeifen=headtemp;
				struct node*temp0=seek(headtemp);
				if(temp0==NULL){
					//continue;
				}else{
					if(head2==NULL){
					head2=headtempbeifen;
					q2=temp0;
				    }else{
					q2->next=headtempbeifen;
					q2=temp0;
				    }
				}
				
			}
			turn=1;
			if(head2==NULL){
				return "Zwin";
			}		
			
		}
	}
	
	return NULL;
	
}


