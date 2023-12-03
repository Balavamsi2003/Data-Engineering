#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float min(int a[],int n){
	int m=a[0];
	for(int i=0;i<n;i++){
		if(a[i]<m)
		  m=a[i];
	}
	return m;
}
float max(int a[],int n){
	int m=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>m)
		  m=a[i];
	}
	return m;
}
float mean(int a[],int n){
	float sum=0.0;
	for(int i=0;i<n;i++)
	    sum+=a[i];
	return sum/n;
}
double STD(int a[],int n){
	float m=mean(a,n);
	double var=0.0;
	for(int i=0;i<n;i++)
	    var+=pow((a[i]-m),2);
	return sqrt(var/n);
}
int count(int a){
	int cnt=0;
	while(a>0){
		a=a/10;
		cnt++;
	}
	return cnt;
}
void min_max_norm(int a[],int n){
	float mi=min(a,n);
	float ma=max(a,n);
	float norm[n];
	for(int i=0;i<n;i++){
		norm[i]=(a[i]-mi)/(ma-mi);
	}
	for(int i=0;i<n;i++){
		printf("\n %d %.2f",a[i],norm[i]);
	}	
}
void zscore_norm(int a[],int n){
	float m=mean(a,n);
	double s=STD(a,n);
	double norm[n];
	for(int i=0;i<n;i++){
		norm[i]=(a[i]-m)/(s);
	}
	for(int i=0;i<n;i++){
		printf("\n %d %lf",a[i],norm[i]);
	}	
}
void decimal_scaling_norm(int a[],int n){
	double norm[n];
	for(int i=0;i<n;i++){
		int digcnt=count(a[i]);
		norm[i]=(a[i])/(pow(10,digcnt));
	}
	for(int i=0;i<n;i++){
		printf("\n %d %lf",a[i],norm[i]);
	}	
}
int main(){
	int data[50],n;
	printf("\n Enter th no.of elements");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&data[i]);
	}
	printf("\n Min-max normalisation technique");
	min_max_norm(data,n);
	printf("\n Z-score normalisation technique");
	zscore_norm(data,n);
	printf("\n Decimal-scaling normalisation technique");
	decimal_scaling_norm(data,n);
}
