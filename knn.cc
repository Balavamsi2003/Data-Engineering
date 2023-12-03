#include<stdio.h>
#include<stdlib.h>
int main(){
	int height[18]={158,158,158,160,160,163,163,160,163,165,165,165,168,168,168,170,170,170};
	int weight[18]={58,59,63,59,60,60,61,64,64,61,62,65,62,63,66,63,64,68};
	char tshirt[18]={'m','m','m','m','m','m','m','l','l','l','l','l','l','l','l','l','l','l'};
	int h=161,w=61;
	int dist[18];
	for(int i=0;i<18;i++){
		int d=(height[i]-h)+(weight[i]-w);
		if(d<0)
		   d=-1*d;
		dist[i]=d;
	}
	// sorting to find ranks
	for(int i=0;i<18;i++){
		for(int j=i+1;j<18;j++){
			if(dist[i]>dist[j]){
				int temp=dist[i];
				dist[i]=dist[j];
				dist[i]=temp;
				
				char t=tshirt[i];
				tshirt[i]=tshirt[j];
				tshirt[j]=t;
			}
		}
	}
	int k=5,mcnt=0,lcnt=0;
	for(int i=0;i<5;i++){
		if(tshirt[i]=='m')
		    mcnt+=1;
		else
		    lcnt+=1;
	}
	if(mcnt>lcnt)
	    printf("\n Tshirt size is medium");
	else
	   printf("\n Tshirt size is long");	
}
