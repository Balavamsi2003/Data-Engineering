#include<stdio.h>
# include<stdlib.h>
float mean(int a[],int n){
	float sum=0.0;
	for(int i=0;i<n;i++)
	    sum+=a[i];
	return sum/n;
}
float median(int a[],int n){
	if(n%2==0)
	    return (a[n/2]+a[n/2-1])/2.0;
	else
	   return a[n/2];
}
float range(int a[],int n){
	return (a[n-1]-a[0])/2.0;
}
void bsort(int a[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void quaratile(int a[],int n){
	int q3,q1;
	if(n%2==0){
		 q3=a[(3*(n+1))/4];
		q1=a[(n+1)/4];
	}
	else{
		 q3=a[(3*n)/4];
		 q1=a[(n/4)];
	}
	float md=median(a,n);
	printf("\n %.2f",md);
	printf("\n %d %d",q3,q1);
	float iqr=(q3-q1);
	float lwhk=q1-(1.5*iqr);
	float upwhk=q3+(1.5*iqr);
	printf("\n %.2f %.2f",lwhk,upwhk);	
}
int mode(int a[],int n){
	int mxcnt=0,maxval=0;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(a[j]==a[i])
			   ++cnt;
		}
		if(cnt>=mxcnt){
			mxcnt=cnt;
			maxval=a[i];
		}
	}
	return maxval;
}
int main(){
	int data[50],n;
	printf("\n Enter th no.of elements");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	float m=mean(data,n);
	printf("\n %.2f",m);
	int mod=mode(data,n);
	printf("\n %d",mod);
	bsort(data,n);
	float md=median(data,n);
	printf("\n %.2f",md);
	float mrng=range(data,n);
	printf("\n %.2f",mrng);
	quaratile(data,n);
	
	
	
}
