/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/



#include<iostream>
#include<string.h>
using namespace std;
 
 class Employee
 {
 	int id;
 	char name[20];
 	int sal;
 public:
 	Employee()
 	{
 		this->id=0;
 		strcpy(this->name,"\0");
 		this->sal=0;
 	}
 	Employee(int id,char* name,int sal)
 	{
 		this->id=id;
 		strcpy(this->name,"name");
 		this->sal=sal;
 	}
 	void setname(char* name)
 	{
 		strcpy(this->name,"name");
 	}
 	char* getname()
 	{
 		return this->name;
 	}
 	
 	void setid(int id)
 	{
 		this->id=id;
 	}
 	int getid()
 	{
 	return this->id;
 	}
 	void setsal(int sal)
 	{
 		this->sal=sal;
 	}
 	int getsal()
 	{
 	return this->sal;
 	}
 	friend ostream& operator<<(ostream& o ,const Employee& e);
 	friend istream& operator>>(istream& i,Employee& e);
 	
 	bool operator!=(Employee e)
 	{
 	   return(this->id!=e.id);
 	    
 	}
 	};
 	
 	ostream& operator<<(ostream& o,const Employee& e)
 	{
 		o<<e.id<<endl;
 		o<<e.name<<endl;
 		o<<e.sal<<endl;
 		return o;
 	}
 	
 	istream& operator >>(istream& i,Employee& e)
 	{
 		int id,sal;
 		char name[20];
 		cout<<"enter employee id"<<endl;
 		
 		i>>id;
 		e.setid(id);
 		cout<<"enter employee name"<<endl;
 		i>>name;
 		e.setname(name);
 		cout<<"enter employee sal"<<endl;
 		i>>sal;
 		e.setsal(sal);
 		return i;
 	}
 		
 	
 	class node
 	{
 	  Employee data;
 	  node* next;
 	   public:
 	   node(Employee e)
 	   {
 	   	this->data=e;
 	   	this->next=NULL;
 	   }
 	   void setdata(Employee data)
 	   {
 	   	this->data=data;
 	   }
 	   Employee getdata()
 	   {
 	   	return this->data;
 	   }
 	   void setnext(node* n)
 	   {
 	   	this->next=n;
 	   }
 	   node* getnext()
 	   {
 	   	return this->next;
 	   }
 	   
 	  
 	  };
 	  
 	  class sll
 	  {
 	  	node* start;
 	  	public:
 	  	sll()
 	  	{
 	  		this->start=NULL;
 	  	}
 	  	
 	  	void addBegin(Employee e)
 	  	{
 	  		node * nn=new node(e);
 	  		if(nn==NULL)
 	  		{
 	  			cout<<"memeory allocation error"<<endl;
 	  		}
 	  		
 	  		if(start=NULL)
 	  		{
 	  			this->start=nn;
 	  		}
 	  		else
 	  		{
 	  			nn->setnext(start);
 	  			start=nn;
 	  		}
 	  		
 	  	}
 	  	
    void addAtEnd(Employee data)
 	  	{
 	  		node * nn=new node(data);
 	  		if(start==NULL)
 	  		{
 	  		this->start=nn;
 	  		}
 	  		else
 	  		{
 	  			node* ep=this->start;
 	  			
 	  			while(ep->getnext()!=NULL)
 	  			{
 	  				ep=ep->getnext();
 	  			}
 	  			
 	  			ep->setnext(nn);
 	  			
 	  			
 	  		}
 	  	}
 	  	
 	  	void removeBegin()
 	  	{
 	  	
 	  	Employee data;
 	  		if(start==NULL)
 	  		{
 	  			cout<<"link list is empty"<<endl;
 	  		}
 	  		else
 	  		{
 	  			node * temp;
 	  			temp=this->start;
 	  			this->start=start->getnext();
 	  			data=temp->getdata();
 	  			delete temp;
 	  		}
 	  	}
 	  	
 	    void removeEnd()
 	    {
 	    	if(start==NULL)
 	    	{
 	    		cout<<"link list is empty"<<endl;
 	    	}
 	    	else
 	    	{
 	    	  node* ep=start;
 	    	  node * temp=start;
 	    	  while(ep->getnext()->getnext()!=NULL)
 	    	  {
 	    	  	ep=ep->getnext();
 	    	  }
 	    	  
 	    	  temp=ep->getnext();
 	    	  Employee e=temp->getdata();
 	    	  ep->setnext(NULL);
 	    	  delete temp;
 	    	   
 	    	}
 	    	

 	    }
 	    
	 	    void searchById(Employee e)
	 	    {
	 	    	Employee data;
	 	    	node* ep=start;
	 	    	while(ep->getdata()!=e)
	 	    	{
	 	    		cout<<"data not found"<<endl;
	 	    		ep=ep->getnext();
	 	    	}
	 	    	
	 	    	      cout<<"data found"<<endl;
	 	    	      data=ep->getdata();
	 	    	      
	 	    	
	 	    	
	 	  }
 	  	
 	  	void display()
 	  	{
 	  		node* ep=start;
 	  		while(ep->getnext()!=NULL)
 	  		{
 	  			cout<<ep->getdata()<<endl;
 	  			ep=ep->getnext();
 	  		}
 	  		cout<<ep->getdata()<<endl;
 	  	}
 	  	
 	  };
 	
 	int main()
 	{
 	int ch,id;
 	Employee e;
 	sll l;
 		do
 		{
 			cout<<"enter 1 to add employee at begning"<<endl;
 			cout<<"enter 2 to add employee at end"<<endl;
 			cout<<"enter 3 to remove employee at begning"<<endl;
 			cout<<"enter 4 to remove employee at end"<<endl;
 			cout<<"enter 5 to search employee by id"<<endl;
 			cout<<"enter 6 to display ALl employee information "<<endl;
 			cout<<"enter 7 to exit"<<endl;
 			cout<<"enter the choice"<<endl;
 			cin>>ch;
 			switch(ch)
 			{
 			 case 1:
	 			 cout<<"Enter employee info"<<endl;
	 			 cin>>e;
	 			 l.addBegin(e);
 			 	 break;
 			case 2: 
 				 cout<<"Enter employee info"<<endl;
	 			 cin>>e;
	 			 l.addAtEnd(e);
 			 	 break;
 			case 3:
 				 l.removeBegin();
 				 break;
 			case 4:
 				l.removeEnd();
 				break;
 			case 5:
 				cout<<"enter employee id to remove"<<endl;	
 				cin>>id;
 				e.setid(id);
 				l.searchById(e);
 				break;
 				
 			 case 6:
 			 	l.display();
 				 break;
 			 case 7:
 			 	exit(0);
 			 	break;
 			 }
 			
 		}while(ch!=7);
 		}
 			

