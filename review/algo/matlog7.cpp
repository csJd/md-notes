#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1005;
int a[N][N], b[N][N], c[N][N];



int main()
{
	printf("%f\n", log2(7));
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
			for(int j = 0;j < n; ++j)
				scanf("%d", &a[i][j]);

		for(int i = 0; i < n; ++i)
			for(int j = 0;j < n; ++j)
				scanf("%d", &b[i][j]);

	}
    return 0;
}


//Last modified :  2015-11-08 10:27 CST
/*
#include <iostream>

using namespace std;

const int N=4;  //常量N用来定义矩阵的大小

void main()

{

         //函数声明部分

         voidstrassen(int n,float A[][N],float B[][N],float C[][N]);

         voidinput(int n,float p[][N]);

         voidoutput(int n,float C[][N]);

 

         //定义三个矩阵A,B,C

         floatA[N][N],B[N][N],C[N][N];

 

         //输入矩阵A,B

         cout<<"现在录入矩阵A[N][N]："<<endl;

         input(N,A);

         cout<<endl<<"现在录入矩阵B[N][N]:"<<endl;

         input(N,B);

 

         //调用strassen函数计算

         strassen(N,A,B,C);

 

         //输出计算结果

         output(N,C);

}

 

//矩阵输入函数

void input(int n,float p[][N])

{

         inti,j;

         for(i=0;i<n;i++)

         {

                   cout<<"请输入第"<<i+1<<"行"<<endl;

                   for(j=0;j<n;j++)

                   {

                            cin>>p[i][j];

                   }

         }

}

 

//矩阵输出函数

void output(int n,float C[][N])

{

         inti,j;

         cout<<"输出矩阵："<<endl;

         for(i=0;i<n;i++)

         {

                   cout<<endl;

                   for(j=0;j<n;j++)

                   {

                            cout<<C[i][j]<<"";

                   }

         }

         cout<<endl;

}

 

//按通常的矩阵乘法计算C=AB的子算法(仅作2阶)

void MATRIX_MULTIPLY(float A[][N],floatB[][N],float C[][N])

{

         inti,j,k;

         for(i=0;i<2;i++)

         {

                   for(j=0;j<2;j++)

                   {

                            //计算完一个C[i][j]，下一个应重新赋值为零

                            C[i][j]=0;

 

                            for(k=0;k<2;k++)

                            {

                                     C[i][j]=C[i][j]+A[i][k]*B[k][j];

                            }

                   }

         }

}

 

//矩阵加法函数

void MATRIX_ADD(int n,float X[][N],floatY[][N],float Z[][N])

{

         inti,j;

         for(i=0;i<n;i++)

         {

                   for(j=0;j<n;j++)

                   {

                            Z[i][j]=X[i][j]+Y[i][j];

                   }

         }

}

 

//矩阵减法函数

void MATRIX_SUB(int n,float X[][N],floatY[][N],float Z[][N])

{

         inti,j;

         for(i=0;i<n;i++)

         {

                   for(j=0;j<n;j++)

                   {

                            Z[i][j]=X[i][j]-Y[i][j];

                   }

         }

}

 

//strassen函数（递归）

void strassen(int n,float A[][N],floatB[][N],float C[][N])

{

         floatA11[N][N],A12[N][N],A21[N][N],A22[N][N];

         floatB11[N][N],B12[N][N],B21[N][N],B22[N][N];

         floatC11[N][N],C12[N][N],C21[N][N],C22[N][N];

         floatM1[N][N],M2[N][N],M3[N][N],M4[N][N],M5[N][N],M6[N][N],M7[N][N];

         floatAA[N][N],BB[N][N],MM1[N][N],MM2[N][N];

 

         inti,j;

 

         if(n==2)

         {

                   //按通常的矩阵乘法计算C=AB

                  MATRIX_MULTIPLY(A,B,C);

         }

         else

         {

                   //将矩阵A和B分为四块

                   for(i=0;i<n/2;i++)

                   {

                            for(j=0;j<n/2;j++)

                            {

                                     A11[i][j]=A[i][j];

                                     A12[i][j]=A[i][j+n/2];

                                     A21[i][j]=A[i+n/2][j];

                                     A22[i][j]=A[i+n/2][j+n/2];

 

                                     B11[i][j]=B[i][j];

                                     B12[i][j]=B[i][j+n/2];

                                     B21[i][j]=B[i+n/2][j];

                                     B22[i][j]=B[i+n/2][j+n/2];

                            }

                   }

 

                   //计算M1，...M7

                   //M1=A11(B12-B22)

                   MATRIX_SUB(n/2,B12,B22,BB);

                   strassen(n/2,A11,BB,M1);

 

                   //M2=(A11+A12)B22

                   MATRIX_ADD(n/2,A11,A12,AA);

                   strassen(n/2,AA,B22,M2);

 

                   //M3=(A21+A22)B11

                   MATRIX_ADD(n/2,A21,A22,AA);

                   strassen(n/2,AA,B11,M3);

 

                   //M4=A22(B21-B11)

                   MATRIX_SUB(n/2,B21,B11,BB);

                   strassen(n/2,A22,BB,M4);

 

                   //M5=(A11+A22)(B11+B22)

                   MATRIX_ADD(n/2,A11,A22,AA);

                   MATRIX_ADD(n/2,B11,B22,BB);

                   strassen(n/2,AA,BB,M5);

 

                   //M6=(A12-A22)(B21+B22)

                   MATRIX_SUB(n/2,A12,A22,AA);

                   MATRIX_ADD(n/2,B21,B22,BB);

                   strassen(n/2,AA,BB,M6);

 

                   //M7=(A11-A21)(B11+B12)

                   MATRIX_SUB(n/2,A11,A21,AA);

                   MATRIX_ADD(n/2,B11,B12,BB);

                   strassen(n/2,AA,BB,M7);

 

                   //计算C11，C12，C21，C22

                   //C11=M5+M4-M2+M6

                   MATRIX_ADD(N/2,M5,M4,MM1);

                   MATRIX_SUB(N/2,M2,M6,MM2);

                   MATRIX_SUB(N/2,MM1,MM2,C11);

 

                   //C12=M1+M2

                   MATRIX_ADD(N/2,M1,M2,C12);

 

                   //C21=M3+M4

                   MATRIX_ADD(N/2,M3,M4,C21);

 

                   //C22=M5+M1-M3-M7

                   MATRIX_ADD(N/2,M5,M1,MM1);

                   MATRIX_ADD(N/2,M3,M7,MM2);

                   MATRIX_SUB(N/2,MM1,MM2,C22);

 

                   //计算结果送回C[N][N]

                   for(i=0;i<n/2;i++)

                   {

                            for(j=0;j<n/2;j++)

                            {

                                     C[i][j]=C11[i][j];

                                     C[i][j+n/2]=C12[i][j];

                                     C[i+n/2][j]=C21[i][j];

                                     C[i+n/2][j+n/2]=C22[i][j];

                            }

                   }

         }

}
*/ 
