#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int x[8]={2,2,8,5,7,6,1,4};
	int y[8]={10,5,4,8,5,4,2,9};
	int c1[8][2],c2[8][2];
	int p,q;
	float mx1=2,my1=5,mx2=6,my2=4,ox1,ox2,oy1,oy2,t1,t2;
	do{
		ox1=mx1;
		oy1=my1;
		ox2=mx2;
		oy2=my2;
		p=0,q=0;
	   for(int i=0;i<8;i++){
	   	    t1=(x[i]-mx1)+(y[i]-my1);
            if(t1<0){
		      t1=-1*t1;
		    }
 
            t2=(x[i]-mx2)+(y[i]-my2);
               if(t2<0){
		          t2=-1*t2;
		       }
	   	   if(t1<t2){
			c1[p][0]=x[i];
			c1[p][1]=y[i];
			p++;
			//printf("%.2f ",t1);
		}
		else{
			c2[q][0]=x[i];
			c2[q][1]=y[i];
			q++;
			//printf("%.2f ",t2);
		}
	}
	float s1x=0.0,s1y=0.0;
    for(int i=0;i<p;i++)
    {
        s1x+=c1[i][0];
        s1y+=c1[i][1];
    }
    mx1=s1x/p;
    my1=s1y/p;
 
    float s2x=0.0,s2y=0.0;
    for(int j=0;j<q;j++)
    {
        s2x+=c2[j][0];
        s2y+=c2[j][1];
    }
    mx2=s2x/q;
    my2=s2y/q;
    /*printf("Cluster 1:\n");
	for(int i=0;i<p;i++){
		for(int j=0;j<2;j++){
	    printf("%d ",c1[i][j]);
	}
	printf("\n");==
}
printf("Cluster 2:\n");
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
	   printf("%d ",c2[i][j]);
}
printf("\n");
}*/
}while(ox1!=mx1&&oy1!=my1&&ox2!=mx2&&oy2!=my2);
printf("Cluster 1:\n");
	for(int i=0;i<p;i++){
		for(int j=0;j<2;j++){
	    printf("%d ",c1[i][j]);
	}
	printf("\n");
}
printf("Cluster 2:\n");
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
	   printf("%d ",c2[i][j]);
}
printf("\n");
}
}
