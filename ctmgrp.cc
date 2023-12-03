#include<stdio.h>
#include<stdlib.h>
float mean(int mid[],int frq[],int n){
	int sum=0,frqsum=0;
	for(int i=0;i<n;i++){
		sum+=mid[i]*frq[i];
	}
	for(int i=0;i<n;i++){
		frqsum+=frq[i];
	}
	return float(sum)/frqsum;
}
float median(int lintv[],int upintv[],int frq[],int cf[],int n){
	int frqsum=0,f,c,l,ht;
	for(int i=0;i<n;i++){
		frqsum+=frq[i];
	}
	int m=frqsum/2;
	for(int i=0;i<n;i++){
		if(cf[i]>m){
		    break;
		}
		f=frq[i+1];
		l=lintv[i+1];
		c=cf[i];
		ht=upintv[i+1]-lintv[i+1];
	}
	return l+ht*((m-c)/float(f));
}
float range(int lintv[],int upintv[],int n){
	float uprng=(upintv[(n-1)]+lintv[(n-1)])/2.0;
	float lwrng=(lintv[0]+upintv[0])/2.0;
	printf("%.2f,%.2f",uprng,lwrng);
	return uprng-lwrng;
}
float intquaratile(int lintv[],int upintv[],int frq[],int cf[],int n ){
	float frqsum=0.0,f3,f1,c3,c1,l3,l1,ht3,ht1,q3,iq3,q1,iq1;
	for(int i=0;i<n;i++){
		frqsum+=frq[i];
	}
	q3=(3*frqsum)/4.0;
	for(int i=0;i<n;i++){
		if(cf[i]>q3){
		    break;
		}
		f3=frq[i+1];
		l3=(lintv[i+1]+upintv[i])/2.0;
		c3=cf[i];
		ht3=upintv[i+1]-lintv[i+1];
	}
	iq3=l3+ht3*((q3-c3)/float(f3));
	q1=(frqsum)/4.0;
	for(int i=0;i<n;i++){
		if(cf[i]>q1){
		    break;
		}
		f1=frq[i+1];
		l1=(lintv[i+1]+upintv[i])/2.0;
		c1=cf[i];
		ht1=upintv[i+1]-lintv[i+1];
	}
	iq1=l1+ht1*((q1-c1)/float(f1));
	return iq3-iq1;
}
int main(){
	int lintv[20],upintv[20],frq[20],mid[20],cf[20],n;
	printf("\n Enter the no.of groups");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("\n Enter the %d lower boundary",i+1);
		scanf("%d",&lintv[i]);
		printf("\n Enter the %d upper boundary",i+1);
		scanf("%d",&upintv[i]);
		printf("\n Enter the %d frequency",i+1);
		scanf("%d",&frq[i]);
	}
	for(int i=0;i<n;i++){
			mid[i]=(lintv[i]+upintv[i])/2.0;	
		}
	float m=mean(mid,frq,n);
	printf("Mean is: %.2f",m);
	for(int i=0;i<n;i++){
		if(i==0)
		   cf[i]=frq[i];
		else
		   cf[i]=cf[i-1]+frq[i];
	}
	float md=median(lintv,upintv,frq,cf,n);
	printf("\n Median is : %.2f",md);
	float mode=(3*md)-(2*m);
	printf("\n Mode is : %.2f ",mode);
	float iqr=intquaratile(lintv,upintv,frq,cf,n);
	printf("\n Inter quaratile range is : %.2f ",iqr);
	float rng=range(lintv,upintv,n);
	printf("\n Range is : %.2f ",rng);
	}
