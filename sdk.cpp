// Solving Problems with Programming
// Professor Keneth Bauer
//
// Sudoku
//
// Student Name José Luis Enríquez Flores
// Student Number A01630238
//&
// Student Name Jorge Samir Godinez Lara
// Student Number A01630155
#include<iostream>
#include<string>
#include <fstream>
#include <algorithm>
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define PURPLE "\x1b[35m"
#define SKY "\x1b[36m"
#define WHITE "\x1b[37m"
using namespace std;
int mat[9][9];
int i,j,ii,jj;
int check;
int cuad, comp, a, f, c, ci, cj, y, z;
int ret, ded;
string ans;
int auth[9][9];
int end(int mat[9][9])
{
	int result;
	for (int r=0;r<=8;r++)
	{
		for(int m=0;m<=8;m++)
		{
			result=result+mat[r][m];
		}
	}
		if (result==405)
	{
		cout<<GREEN<<"Congratulations. You did it!"<<endl;
		return 1;
	}
}
void instructions()
{
	cout<<" "<<endl;
	cout<<GREEN<<"Instructions: Each puzzle consists of a 9x9 grid containing given clues in various places."<<endl;
	cout<<"The object is to fill all empty squares so that the numbers 1 to 9 appear exactly once in each row, column and 3x3 box."<<WHITE<<endl;
	cout<<"Obtained from: "<<BLUE<<"http://www.conceptispuzzles.com/?uri=puzzle/sudoku/rules"<<WHITE<<endl;
	cout<<" "<<endl;
}
int cuadro(int mat[9][9])
{
	if(mat[i][j]!=0)
	{
	int o, p, s, ss, dd, d, m;
	a=0;
	s=(i/3)*3;
	ss=s+2;
	d=(j/3)*3;
	dd=d+2;
	for(o=s;o<=ss;o++)
	{
		for(p=d;p<=dd;p++)
		{
		if(mat[i][j]==mat[o][p])
			{
				a=a+1;
			}
		}
	}
	if(a>1)
	{
		cout<<RED<<"The entered value already exists in the box 3X3:"<<(s+3)/3<<","<<(d+3)/3<<"."<<WHITE<<endl;
		cout<<YELLOW<<"Please enter a different number."<<WHITE<<endl;
	}
	return a;
	}
}
int original(int auth[9][9])
{
	if(auth[i][j]>0)
	{
		cout<<RED<<"The space chosen contains an original value that can not be changed."<<WHITE<<endl;
		return 1;
	}
}
int comparacion (int mat[9][9])
{
	if(mat[i][j]!=0)
	{
	 ci=0;
	 cj=0;
	 y=i;
	 z=j;
	 comp=mat[i][j];
	do{
		c=0;
		f=0;
		for (int w=0;w<9;w++)
		   {
			   ci=comp-mat[y][w];
			   if (ci==0)
				   {
					   f=f+1;
				   }
		   }
		for (int w=0;w<9;w++)
		   {
			   cj=comp-mat[w][z];
			   if (cj==0)
				   {
					   c=c+1;
				   }
		   }
		if (f>1 or c>1)
		{
			if (f>1)
			   {
			   cout<<RED<<"There is a repeated value in this row, you need to change it."<<WHITE<<endl;
			   }
			if (c>1)
			   {
			   cout<<RED<<"There is a repeated value in this column, you need to change it."<<WHITE<<endl;	
			   }
			cout<<YELLOW<<"Please enter a different number."<<WHITE<<endl;
			cin>>mat[i][j];
		}
	}while(f>1 or c>1);
	}
}
void funcion (int mat[9][9])
{
   do{
		   if (mat[i][j]<0 or mat[i][j]>9)
		   {

				cout<<RED<<"The entered  is not valid."<<WHITE<<endl;
				cout<<YELLOW<<"Please enter an integer value between 1 and 9 inclusive or 0 if you want to escape."<<WHITE<<endl;
				cin>>mat[i][j];   
  
		   }
	   }while(mat[i][j]<0 or mat[i][j]>9);  
}
void print(int mat[9][9])
{
	for(i=0; i<=8;i++)
				{
					for(j=0;j<=8;j++)
					{
						if(mat[i][j]==0)
						{
							cout<<BLACK<<mat[i][j]<<BLUE<<" | ";
						}
						else
						{
								cout<<WHITE<<mat[i][j]<<BLUE<<" | "<<WHITE;	
						}
					}cout<<endl;
					for(int n=0;n>=8;n++)
					{
						cout<<"-";
					}cout<<endl;
				}
}
int main(int argc, char* argv[]) {
  string filename;
  switch(argc)
    {
    case 1:
      cout << "Please provide the parameters to the program, you must enter a filename to initiate the Sudoku." << endl;
      exit(1);
    case 2:
      filename = argv[1];
      break;
    default:
      cout << "Please provide the parameters to the program, you must enter a filename to initiate the Sudoku." << endl;
      exit(1);
    }
  ifstream infile(filename.c_str()); // the c_str() is to convert from string to char*
  int cell;
  if(infile.good()){
    for(int r = 0; r < 9 ; r++)
	{
	for(int c = 0; c < 9 ; c++)
		{
		infile >> cell;
		mat[r][c] = cell;
		auth[r][c]=cell;
		}
    }
  } else {
    cout << "Something is wrong with the input file" << endl;
  }

  cout<<"Welcome to "<<SKY<<"S"<<BLUE<<"U"<<PURPLE<<"D"<<RED<<"O"<<YELLOW<<"K"<<GREEN<<"U"<<WHITE<<"LAND."<<endl;
  instructions();
	for(i=0; i<=8;i++)
	{
		for(j=0;j<=8;j++)
		{
			if(mat[i][j]==0)
			{
				cout<<BLACK<<mat[i][j]<<PURPLE<<" | ";
			}
			else{
					cout<<WHITE<<mat[i][j]<<PURPLE<<" | "<<WHITE;	
				}
		}cout<<endl;
			for(int n=0;n>=8;n++)
			{
				cout<<"-";
			}cout<<endl;
	}
do{
	cout<<"What do you want to do next?"<<endl;
	cout<<"Game rules --> rules."<<endl;
	cout<<"Change a number --> change."<<endl;
	cout<<"Delete a number --> delete."<<endl;
	cout<<"Print saved sudoku --> print."<<endl;
	cout<<"End game --> quit."<<YELLOW<<endl;
	end(mat);
	check=end(mat);
	if (check==1)
	{
		return 0;
	}
	cin>>ans;
	if(ans=="rules")
	{
		instructions();
	}
	else if (ans=="change")
	{
		int save;
			do{
			   cout<<WHITE<<"Select the row you want to modify . "<<WHITE<<endl;;
			   cin>>ii;
			   if (ii<=0 or ii>9)
				   do{
					   cout<<RED<<"The row that you want to modify does not exist."<<WHITE<<endl;
					   cout<<YELLOW<<"Please enter another row number."<<WHITE<<endl;
					   cin>>ii;
				   }while(ii<=0 or ii>9);
			   i=ii-1;
			   cout<<"Select the column you want to modify . "<<endl;
			   cin>>jj;
				 if (jj<=0 or jj>9)
				   do{
					   cout<<RED<<"The column you want to modify does not exist."<<WHITE<<endl;
					   cout<<YELLOW<<"Please enter another column number."<<WHITE<<endl;
					   cin>>jj;
				   }while(jj<=0 or jj>9);
				j=jj-1;
				ded=original(auth);
			}while(ded==1);
			save=mat[i][j];
			cout<<YELLOW<<"Enter the new value: "<<WHITE<<endl;  
		do{
			cin>>mat[i][j];
			if (mat[i][j]==0)
			{
				mat[i][j]=save;
			}
			else
			{
			funcion(mat);
			ret=comparacion(mat);//
			comparacion(mat);//
			a=cuadro(mat);
			if (mat[i][j]==0)
			{
				mat[i][j]=save;
			}
			}
		}while(a>1);
			funcion(mat);
			print (mat);
	}
	else if (ans=="delete")
	{
			do{
		   cout<<WHITE<<"Select the row you want to delete. "<<WHITE<<endl;;
           cin>>ii;
		   if (ii<=0 or ii>9)
			   do{
				   cout<<RED<<"The row that you want to modify does not exist."<<WHITE<<endl;
				   cout<<YELLOW<<"Please enter another row number."<<endl;
				   cin>>ii;
			   }while(ii<=0 or ii>9);
		   i=ii-1;
           cout<<WHITE<<"Select the column you want to modify."<<endl;
           cin>>jj;
		     if (jj<=0 or jj>9)
			   do{
				   cout<<RED<<"The column you want to modify does not exist."<<endl;
				   cout<<YELLOW<<"Please enter another column number."<<WHITE<<endl;
				   cin>>jj;
			   }while(jj<=0 or jj>9);
		   j=jj-1;
		   ded=original(auth);
			}while(ded==1);
			mat[i][j]=0;
	print(mat);
	}
	else if (ans=="print")
	{
		print(mat);
	}
	else if(ans!="quit")
	{
		cout<<RED<<"The option that has been entered is invalid ."<<endl;
		cout<<YELLOW<<" Please enter a valid option."<<WHITE<<endl;
	}
}while(ans!="quit");
	
	return 0;
}