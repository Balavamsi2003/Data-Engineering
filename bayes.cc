#include<stdio.h>
#include<stdlib.h>
int main(){
	char *dept[]={"sales","sales","sales","systems","systems","systems","systems","marketing","marketing","secretary","secretary"};
	char *status[]={"senior","junior","junior","junior","senior","junior","senior","senior","junior","senior","junior"};
	int lwr_age[11]={31,26,31,21,31,26,41,36,31,46,26};
	int upr_age[11]={35,30,35,25,35,30,45,40,35,50,30};
	int lwr_sal[11]={46,26,31,46,66,46,66,46,41,36,26};
	int upr_sal[11]={50,30,35,50,70,50,70,50,45,40,30};
	int count[11]={30,40,40,20,5,3,3,10,4,4,6};
	
	char **Department=dept;
	char **Status=status;
	int lage=26,upage=30,lsal=46,upsal=50;
	int snrcnt=0,jnrcnt=0,dscnt=0,djcnt=0,agscnt=0,agjcnt=0,salscnt=0,saljcnt=0;
	int a=0,b=0,c=0,d=0,e=0,f=0;
	float temp=0;
	for(int i=0;i<11;i++)
	    temp+=count[i];
	    
	for(int i=0;i<11;i++){
		if(*(Status+i)=="senior")
		     snrcnt+=count[i];
		else
		     jnrcnt+=count[i];
	}
	for(int i=0;i<11;i++){
		if(*(Department+i)=="systems"){
			if(*(Status+i)=="senior"){
				 a++;
			     dscnt+=count[i];
			 }
			else{
				 b++;
			     djcnt+=count[i];
		}
	}
		if(lwr_age[i]==lage&&upr_age[i]==upage){
			if(*(Status+i)=="senior"){
				  c++;
			      agscnt+=count[i];
			  }
			else{
				 d++;
			    agjcnt+=count[i];
		}
	}
		if(lwr_sal[i]==lsal&&upr_sal[i]==upsal){
			if(*(Status+i)=="senior"){
				e++;
			     salscnt+=count[i];
			 }
			else{
				 f++;
			    saljcnt+=count[i];
		}
	}
	}
	// If any category probability becomes 0 adding 1 to both junior and senior
	if(a==0||b==0||c==0||d==0||e==0||f==0){
		snrcnt+=1;
		jnrcnt+=1;
		dscnt+=1;
		djcnt+=1;
		agscnt+=1;
		agjcnt+=1;
		salscnt+=1;
		saljcnt+=1;
	}
	printf("%d %d %d %d %d %d %d %d",snrcnt,jnrcnt,dscnt,agscnt,salscnt,djcnt,agjcnt,saljcnt);
	printf("\n Probability of given employee is senior");
	float x=(dscnt*agscnt*salscnt)/(snrcnt*snrcnt*temp);
	printf("%.5f",x);
	printf("\n Probability of given employee is junior");
	float y=(djcnt*agjcnt*saljcnt)/(jnrcnt*jnrcnt*temp);
	printf("%.5f",y);
	if(x>y)
	    printf("\n Employee is senior");
	else
	    printf("\n Employee is junior");
	}
