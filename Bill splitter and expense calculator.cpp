#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#define m 20
using namespace std;
class person
{
	protected:
		char name[m];
		float paid[m],htp[m],total,tpaid,thtp;
    public:
    	int code;
    	person()
    	{
    		for(int i=0;i<m;i++)
    		{
    			paid[i]=htp[i]=0;
			}
			total=0;
			tpaid=0;
			thtp=0;
		}
    	void read(char a[m],int c)
		{
			strcpy(name,a);
			code=c;
		}
		int check(char b[m],int c)
		{
			int i=0;
			if(!strcmp(name,b))
			{
			    cout<<"Enter different name."<<endl;
			    i+=1;
		    }
		    if(code==c)
		    {
		    	cout<<"Enter different code."<<endl;
		    	i+=2;
			}
			return i;
		}
		void displayname()
		{
			cout<<name;
		}
		void displaycode()
		{
			cout<<name<<"\t-\t"<<code<<endl;
		}
		void amountpaid(float i,int r)
		{
			paid[r]=i;
		}
		void amounthtp(float j,int r)
		{
			htp[r]=j;
		}
		void calculate(int r)
		{
			for(int i=0;i<r;i++)
			{
				tpaid+=paid[i];
				total+=htp[i];
			}
			thtp=total-tpaid;
		}
		void showarray(int i)
		{
			cout<<paid[i]<<"-"<<htp[i]<<setw(10);
		}
		void showtotal()
		{
			cout<<total;
		}
		void showpaid()
		{
			cout<<tpaid;
		}
		void showhtp()
		{
			cout<<thtp;
		}
};
void line()
    {
            for(int i=1;i<41;i++)
          cout<<"--";

     cout<<"\n";
   }
int main()
{
	int n;
	cout<<"Enter the no. of peoples : ";
	cin>>n;
	person p[n];
	char name[20];
	int code,i,j,k;
	cout<<"Enter the names with a numeric integral code : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" - ";
		cin>>name;
		cin>>code;
		for(j=0;j<i;j++)
		{
			k=p[j].check(name,code);
			if(k==1)
			cin>>name;
			else if(k==2)
			cin>>code;
			else if(k==3)
			cin>>name>>code;
		}
		p[i].read(name,code);
	}
	cout<<"Person's name with their name code (Use these codes for entries) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" -\t";
		p[i].displaycode();
	}
	line();
	char reason[m][m];
	i=0;
	int n1,n2;
	float bill[m],tbill=0,paid,part;
	line();
	line();
	cout<<i+1<<"-Enter Reason ( if finished write 'end' ) : ";
	cin>>reason[i];
	while(strcmp(reason[i],"end\0"))
	{
		bill[i]=0;
		cout<<"    Enter no. of peoples who paid (if all paid equally then enter 0 ) : ";
		jump1 : cin>>n1;
		if(n1==0)
		{
			cout<<"      Enter amount paid per person : ";
			jump2: cin>>paid;
			for(k=0;k<n;k++)
			{
			    p[k].amountpaid(paid,i);
			    bill[i]+=paid;
		    }
		}
		else if(n1>0&&n1<=n)
		{
		    for(j=0;j<n1;j++)
		    {
				cout<<"      Enter namecode of person : ";
			    jump3: cin>>code;
				for(k=0;k<n;k++)
				{
					if(p[k].code==code)
					break;
				}
				if(k==n)
				{
					cout<<"      ERROR! : Enter a valid namecode : ";
					goto jump3;
				}
				cout<<"      Enter amount paid by "<<code<<" : ";
			    jump4: cin>>paid;
			    for(k=0;k<n;k++)
			    {
				    if(p[k].code==code)
					{
                        p[k].amountpaid(paid,i);
						break;
					}
		    	}
			    bill[i]+=paid;
		    }
	    }
		else
		{
			cout<<"    ERROR! : Enter a valid number : ";
            goto jump1;
		}
		cout<<"    Enter no. of peoples whose amount is paid (for all, enter 0 or "<<n<<" ): ";
		jump5: cin>>n2;
		if(n2==0||n2==n)
		{
			for(k=0;k<n;k++)
		    p[k].amounthtp(bill[i]/n,i);
		}
		else if(n2>0&&n2<n)
		{
		    for(j=0;j<n2;j++)
			{
				cout<<"      Enter name code of person : ";
				jump6: cin>>code;
				for(k=0;k<n;k++)
				{
					if(p[k].code==code)
					break;
				}
				if(k==n)
				{
					cout<<"      ERROR! : Enter a valid namecode : ";
					goto jump6;
				}
		        for(k=0;k<n;k++)
		        {
		        	if(p[k].code==code)
					{
                        p[k].amounthtp(bill[i]/n2,i);
						break;
					}
				}
		    }
		}
		else
		{
			cout<<"    ERROR! : Enter a valid number : ";
			goto jump5;
		}
	    tbill+=bill[i];
	    i++;
	    cout<<i+1<<"-Enter Reason ( if finished enter 'end' ) : ";
		cin>>reason[i];
	}
	int r=i;
	for(i=0;i<n;i++)
	{
	    p[i].calculate(r);
    }
    cout<<setw(20)<<"Reason"<<setw(20);
    for(i=0;i<n;i++)
    {
        p[i].displayname();
        cout<<setw(12);
    }
    cout<<setw(20)<<"Bills  "<<endl;
    for(i=0;i<r;i++)
    {
    	cout<<setw(20)<<reason[i]<<setw(20);
    	for(j=0;j<n;j++)
    	{	
    		cout<<setw(13);
    	    p[j].showarray(i);
    	    cout<<setw(13);
        }
        cout<<setw(20)<<bill[i]<<endl;
	}
	cout<<setw(20)<<"Total Expenses"<<setw(20);
	for(i=0;i<n;i++)
	{
		p[i].showtotal();
		cout<<setw(12);
	}
	cout<<setw(20)<<tbill<<endl;
	cout<<setw(20)<<"Paid"<<setw(20);
	for(i=0;i<n;i++)
	{
		p[i].showpaid();
		cout<<setw(12);
	}
	cout<<endl;
	cout<<setw(20)<<"Have to Pay"<<setw(20);
	for(i=0;i<n;i++)
	{
		p[i].showhtp();
		cout<<setw(12);
	}
	cout<<endl;
	return 0;
}
