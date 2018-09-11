#include<iostream>
#include<cmath>
using namespace std;

int** createmat(int n){
	int **m = new int*[n];
	for(int i=0;i<n;i++)
		m[i] = new int[n];
	return m;
}

int** add(int **A, int **B, int n){
	int **C = createmat(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C[i][j] = A[i][j] + B[i][j];
	return C;
}

int** sub(int **A, int **B, int n){
	int **C = createmat(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			C[i][j] = A[i][j] - B[i][j];
	return C;
}


void strassen(int **A, int **B, int **C, int n){
	if(n == 2){
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				for(int l=0;l<2;l++)
					C[i][j] += A[i][l]*B[l][j];
			}
	}
	else{
		int x = n/2;
		int **a = createmat(x);
		int **b = createmat(x);
		int **c = createmat(x);
		int **d = createmat(x);
		int **e = createmat(x);
		int **f = createmat(x);
		int **g = createmat(x);
		int **h = createmat(x);
		
		for(int i=0;i<n/2;i++)
			for(int j=0;j<n/2;j++){
				a[i][j] = A[i][j];
				e[i][j] = B[i][j];
				b[i][j] = A[i][j + n/2];
				f[i][j] = B[i][j + n/2];
				c[i][j] = A[i + n/2][j];
				g[i][j] = B[i + n/2][j];
				d[i][j] = A[i + n/2][j + n/2];
				h[i][j] = B[i + n/2][j + n/2];
			}

		//int p1[x][x],p2[x][x],p3[x][x],p4[x][x],p5[x][x],p6[x][x],p7[x][x];
		int **p1 = createmat(x);
		int **p2 = createmat(x);
		int **p3 = createmat(x);
		int **p4 = createmat(x);
		int **p5 = createmat(x);
		int **p6 = createmat(x);
		int **p7 = createmat(x);

		//p1 = a(f-h)
		strassen(a,sub(f,h,x),p1,x);
		//p2 = (a+b)*h
		strassen(add(a,b,x),h,p2,x);
		//p3 = (c + d)*e
		strassen(add(c,d,x),e,p3,x);
		//p4 = d*(g-e)
		strassen(d,sub(g,e,x),p4,x);
		//p5 = (a+d)*(e+h)
		strassen(add(a,d,x),add(e,h,x),p5,x);
		//p6 = (b-d)*(g+h)
		strassen(sub(b,d,x),add(g,h,x),p6,x);
		//p7 = (a-c)*(e+f)
		strassen(sub(a,c,x),add(e,f,x),p7,x);

		//int m1[x][x],m2[x][x],m3[x][x],m4[x][x];
		int **m1;
		int **m2;
		int **m3;
		int **m4;

		m1 = add(sub(add(p5,p4,x),p2,x),p6,x);  // m1 = p4+p5-p2+p6
		m2 = add(p1,p2,x);                      // m2 = p1+p2
		m3 = add(p3,p4,x);                      // m3 = p3+p4
		m4 = sub(sub(add(p1,p5,x),p3,x),p7,x);  // m4 = p1+p5-p3-p7

		for(int i=0;i<x;i++)
			for(int j=0;j<x;j++){
				C[i][j] = m1[i][j];
				C[i][j+x] = m2[i][j];
				C[i+x][j] = m3[i][j];
				C[i+x][j+x] = m4[i][j];
			}

	}
}

void display(int **mat, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n;
	cout<<"Enter the dimension of square matrix: ";
	cin>>n;
	int n0 = log2(n);
	if(log2(n) != n0)
		cout<<"Invalid Entry! Try no. in power of 2\n";
	else{
		//int A[n][n],B[n][n],C[n][n];
		int **A = createmat(n);
		int **B = createmat(n);
		int **C = createmat(n);
		cout<<"\nEnter the matrix1\n";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>A[i][j];
		cout<<"\nEnter the matrix2\n";
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>B[i][j];
		strassen(A,B,C,n);
		cout<<"\n\nThe RESULT is:\n\n";
		display(C,n);
	}
	return 0;
}
