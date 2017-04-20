#include<stdio.h>
#include<stdlib.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<conio.h>
#include<dos.h>



char user[100];
char password[100];

void login()
{
	int i,j;
	clrscr();
	textcolor(LIGHTGREEN);

	gotoxy(18,7);
	cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
	gotoxy(18,8);
	cprintf("±±±");
	gotoxy(56,8);
	cprintf("±±±");

	gotoxy(18,9);
	cprintf("±±±");
	gotoxy(56,9);
	cprintf("±±±");

	gotoxy(18,10);
	cprintf("±±±");
	gotoxy(56,10);
	cprintf("±±±");

	gotoxy(18,11);
	cprintf("±±±");
	gotoxy(56,11);
	cprintf("±±±");

	gotoxy(18,12);
	cprintf("±±±");
	gotoxy(56,12);
	cprintf("±±±");


	gotoxy(18,13);
	cprintf("±±±");
	gotoxy(56,13);
	cprintf("±±±");
	gotoxy(18,14);
	cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±");
	gotoxy(21,9);
	cprintf("Enter user name :");
	gets(user);
	gotoxy(21,11);
	cprintf("Enter password  :");
	gets(password);

	clrscr();

	textcolor(LIGHTBLUE+BLINK);
	cprintf("\n\n\n\n\n\nVERIFYING  ");

	for(i=0;i<60;i++)
	{
		textcolor(GREEN);
		cprintf("±");
		delay(25);
	}

	if(strcmpi(user,"NRAK")==0 && strcmpi(password,"KARN")==0)
	{

		clrscr();
		textcolor(LIGHTCYAN+BLINK);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±");
		printf("\n\t\t\t\t");
		cprintf("±±±                  ±±±");
		printf("\n\t\t\t\t");
		cprintf("±±± LOGIN SUCCESSFUL ±±±");
		printf("\n\t\t\t\t");
		cprintf("±±±                  ±±±");
		printf("\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±");
	}

	else
	{

		clrscr();
		textcolor(LIGHTRED+BLINK);
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±");
		printf("\n\t\t\t\t");
		cprintf("±±±                    ±±±");
		printf("\n\t\t\t\t");
		cprintf("±±± LOGIN UNSUCCESSFUL ±±±");
		printf("\n\t\t\t\t");
		cprintf("±±±                    ±±±");
		printf("\n\t\t\t\t");
		cprintf("±±±±±±±±±±±±±±±±±±±±±±±±±±");

		getch();
		login();

	}



}





class branch
{
	int branch_id;
	char branch_name[20];
	char branch_address[30];
	class branch*next;
	class staff*s[50];
	public:
		friend class staff;
		void create_db_branch();
		void new_branch();
		void display_branch_details();
		void delete_branch();
		void delete_branch_staff();

};
class branch branch1,*h_branch=NULL,*end_branch=NULL;

void branch::delete_branch()
{
	int id;
	class branch*temp;
	temp=h_branch;
	cout<<"\nEnter id of the branch you want to delete:";
	cin>>id;
	while(temp!=NULL)
	{
		if(temp->next->branch_id==id)
		{	
			temp->delete_branch_staff();
			temp->next=temp->next->next;
		}
		temp=temp->next;
	}
}


void branch::display_branch_details()
{
	int id;
	class branch *temp;
	temp=(class branch*)malloc(sizeof(class branch));
	temp=h_branch;
	cout<<"\nEnter branch id:";
	cin>>id;

	while(temp!=NULL)
	{
		if(temp->branch_id==id)
		{
			cout<<"\nBranch id:"<<temp->branch_id;
			cout<<"\nBranch name:"<<temp->branch_name;
			cout<<"\nBranch address:"<<temp->branch_address;
			getch();
			break;

		}
		temp=temp->next;
	}
	
	
}


void branch::new_branch()
{
	class branch*temp;
	temp=(class branch*)malloc(sizeof(class branch));
	temp->next=NULL;
	cout<<"\nEnter branch id:";
	cin>>temp->branch_id;
	cout<<"\nEnter branch_name:";
	gets(temp->branch_name);
	cout<<"\nEnter branch_address:";
	gets(temp->branch_address);
	if(h_branch==NULL)
	{
		h_branch=temp;
		end_branch=temp;
	}
	else
	{
		end_branch->next=temp;
		end_branch=temp;
	}
}


void branch::create_db_branch()
{
	fstream f1;
	class branch*node;
	f1.open("Branch.dat",ios::in|ios::binary);  /* input from file   :: in*/

	f1.seekg(0);

	while(f1.read((char*)&branch1,sizeof(branch1)))
	{

	node=(class branch*)malloc(sizeof(class branch));
		node->branch_id=branch1.branch_id;
		strcpy(node->branch_name,branch1.branch_name);
		strcpy(node->branch_address,branch1.branch_address);
		node->next=NULL;
		if(h_branch==NULL)
		{
			h_branch=node;
			end_branch=node;
		}
		else
		{
			end_branch->next=node;
			end_branch=node;
		}

	}
	f1.close();


}


class staff
{
	 int staff_id;
	 char staff_name[20];
	 float staff_salary;
	 public:
		class branch *b;
		//class department *d;//cancelled for now;
		class staff*next;
		int b_id;
		void assign_to_branch();
		void delete_staff_from_branch();
		//void assign_to_department();
		int dept_id;
		void new_staff();
		void create_db_staff();
		void display_staff_details();
		void delete_staff();
		void update_salary();
		void update_branch();

};

class staff staff1,*h_staff=NULL,*end_staff=NULL;



void staff::update_branch()
{
	int id;
	class staff *temp;
	cout<<"\nEnter id of the staff whose branch is to be updated:\t";
	cin>>id;
	temp=h_staff;
	while(temp!=NULL)
	{
		if(temp->staff_id==id)
		{
			cout<<"\nEnter new branch id:\t";
			cin>>temp->b_id;
			temp->assign_to_branch();
			break;
		}
		temp=temp->next;
	}

}


void branch::delete_branch_staff()
{
	staff*temp;
	int i=0;
	do
	{
		temp=h_staff;
		while(temp!=NULL)
		{
			if(temp->next==this->s[i])
			{
				temp->next=temp->next->next;
				break;
			}
			temp=temp->next;
		}
		
		i++;

	}while(this->s[i]!=NULL);
}

void staff::update_salary()
{
	int id;
	class staff *temp;
	cout<<"\nEnter id of the staff whose salary is to be updated:\t";
	cin>>id;
	temp=h_staff;
	while(temp!=NULL)
	{
		if(temp->staff_id==id)
		{
			cout<<"\nEnter new salary:\t";
			cin>>temp->staff_salary;
			break;
		}
		temp=temp->next;
	}
}


void staff::delete_staff_from_branch()
{
	class branch*temp;
	temp=h_branch;
	int i;
	while(temp!=NULL)
	{
		if(temp->branch_id==this->b_id)
		{
			i=0;
			while(temp->s[i]!=NULL)
			{
				if(temp->s[i]==this)
				{
					temp->s[i]=NULL;
					break;
				}
			}
			break;
		}
		i++;
	}
}

void staff::delete_staff()
{
	int id;
	class staff*temp;
	temp=h_staff;
	cout<<"\nEnter id of the staff member you want to delete:\t";
	cin>>id;
	
	while(temp!=NULL)
	{
		if(temp->next->staff_id==id)
		{	
			temp->delete_staff_from_branch();
			temp->next=temp->next->next;
		}
		temp=temp->next;
	}

}


void staff::display_staff_details()
{
	int id;
	class staff*temp;
	temp=(class staff*)malloc(sizeof(class staff));
	temp=h_staff;
	cout<<"\nEnter staff id:";
	cin>>id;

	while(temp!=NULL)
	{
		if(temp->staff_id==id)
		{
			cout<<"\nStaff id:"<<temp->staff_id;
			cout<<"\nStaff name:"<<temp->staff_name;
			cout<<"\nSalary:"<<temp->staff_salary;
			cout<<"\nBranch id:"<<temp->b->branch_id;
			cout<<"\nDepartment id:"<<temp->dept_id;
			break;
		}
		temp=temp->next;
	}
	getch();
}

void staff::new_staff()
{
	class staff*temp;
	temp=(class staff*)malloc(sizeof(staff));
	cout<<"\nEnter staff id:";
	cin>>temp->staff_id;
	cout<<"\nEnter staff_name:";
	gets(temp->staff_name);
	cout<<"\nEnter salary:";
	cin>>temp->staff_salary;
	cout<<"\nEnter branch id:";
	cin>>temp->b_id;
	temp->assign_to_branch();
	temp->next=NULL;
	if(h_staff==NULL)
	{
		h_staff=temp;
		end_staff=temp;
	}
	else
	{
		end_staff->next=temp;
		end_staff=temp;
	}
}


void staff::assign_to_branch()
{
	class branch*temp;
	temp=(class branch*)malloc(sizeof(class branch));
	temp=h_branch;
	while(temp!=end_branch)
	{
		if(this->b_id==temp->branch_id)
		{
			for(int i=0;i<50;i++)
			{
				if(temp->s[i]==NULL)
				{
					temp->s[i]=this;
					break;
				}
			}
			break;
		}
		temp=temp->next;
	}
}


void staff::create_db_staff()
		{
			fstream f2;
			class staff*node;
			f2.open("Staff.dat",ios::in|ios::binary);  /* input from file   :: in*/

			f2.seekg(0);

			while(f2.read((char*)&staff1,sizeof(staff1)))
			{

				node=(class staff*)malloc(sizeof(class staff));
				node->staff_id=staff1.staff_id;
				strcpy(node->staff_name,staff1.staff_name);
				node->staff_salary=staff1.staff_salary;
				node->b_id=staff1.b_id;
				node->assign_to_branch();
				node->dept_id=staff1.dept_id;
				node->next=NULL;
				if(h_staff==NULL)
				{
					h_staff=node;
					end_staff=node;
				}
				else
				{
					end_staff->next=node;
					end_staff=node;
				}

		    }
			f2.close();


		};


class department
{
	int department_id;
	char department_name[20];
	public:
			class staff*supervisor;
			int s_id;
			class department*next;
			void create_db_department();
			friend class staff;
			void new_department();
			void delete_department();
			void display_department();
			void change_supervisor();

};
class department department1,*h_department=NULL,*end_department=NULL;



void department::change_supervisor()
{
	int id;
	class department *temp;
	cout<<"\nEnter id of the department whose supervisor is to be updated:\t";
	cin>>id;
	temp=h_department;
	while(temp!=NULL)
	{
		if(temp->department_id==id)
		{
			cout<<"\nEnter new supervisor id:\t";
			cin>>temp->s_id;
			break;
		}
		temp=temp->next;
	}

}



void department::display_department()
{
	int id;
	class department*temp;
	temp=(class department*)malloc(sizeof(class department));
	temp=h_department;
	cout<<"\nEnter department id :\t";
	cin>>id;
	while(temp!=NULL)
	{
		if(temp->department_id==id)
		{
			cout<<"\nDepartment id:"<<temp->department_id;
			cout<<"\nDepartment name:"<<temp->department_name;
			break;
		}
		temp=temp->next;
	}
	getch();
}


void department::delete_department()
{
	int id;
	class department*temp;
	temp=h_department;
	cout<<"\nEnter id of the department you want to delete:\t";
	cin>>id;
	while(temp!=NULL)
	{
		if(temp->next->department_id==id)
		{	
			temp->next=temp->next->next;
		}
		temp=temp->next;
	}

}


void department::new_department()
{
	class department*temp;
	temp=(class department*)malloc(sizeof(class department));
	cout<<"\nenter department id:";
	cin>>temp->department_id;
	cout<<"\nEnter department name:";
	gets(temp->department_name);
	cout<<"\nenter supervisor id:";
	cin>>temp->s_id;
	temp->next=NULL;
	if(h_department==NULL)
	{
		h_department=temp;
		end_department=temp;
	}
	else
	{
		end_department->next=temp;
		end_department=temp;
	}
}


void department::create_db_department()
{
			fstream f3;
			class department*node;
			f3.open("Department.dat",ios::in|ios::binary);  /* input from fidepartment:: in*/

			f3.seekg(0);

		while(f3.read((char*)&department1,sizeof(department1)))
			{

				node=(class department*)malloc(sizeof(class department));
				node->department_id=department1.department_id;
				strcpy(node->department_name,department1.department_name);
				node->s_id=department1.s_id;
				node->next=NULL;
				if(h_department==NULL)
				{
					h_department=node;
					end_department=node;
				}
				else
				{
					end_department->next=node;
					end_department=node;
				}

		    }
			f3.close();


}

class supplier
{
	int supplier_id;
	char supplier_name[20];
	public:
		class supplier*next;
		class items*i[100];
		void new_supplier();
		void display_supplier_details();
		void delete_supplier();
		void create_db_supplier();
		friend class items;

};

class supplier supplier1,*h_supplier=NULL,*end_supplier=NULL;

void supplier::new_supplier()
{
	class supplier*temp;
	temp=(class supplier*)malloc(sizeof(class supplier));
	cout<<"\nEnter supplier_id:";
	cin>>temp->supplier_id;
	cout<<"\nEnter supplier name:";
	gets(temp->supplier_name);
	temp->next=NULL;
	if(h_supplier==NULL)
	{
		h_supplier=temp;
		end_supplier=temp;
	}
	else
	{
		end_supplier->next=temp;
		end_supplier=temp;
	}

}

void supplier::display_supplier_details()
{
	int id;
	class supplier*temp;
	temp=(class supplier*)malloc(sizeof(class supplier));
	temp=h_supplier;
	cout<<"\nEnter supplier id of the desired supplier:";
	cin>>id;
	while(temp!=NULL)
	{
		if(temp->supplier_id==id)
		{
			cout<<"\nSupplier ID:"<<temp->supplier_id;
			cout<<"\nSupplier Name:"<<temp->supplier_name;
			break;
		}
		temp=temp->next;
	}
	getch();
}


void supplier::delete_supplier()
{
	int id;
	class supplier*temp;
	temp=h_supplier;
	cout<<"\nEnter id of the supplier you want to delete:";
	cin>>id;
	while(temp!=NULL)
	{
		if(temp->next->supplier_id==id)
		{	
			temp->next=temp->next->next;
		}
		temp=temp->next;
	}

}


void supplier::create_db_supplier()
		{
			fstream f4;
			class supplier*node;
			f4.open("Supplier.dat",ios::in|ios::binary);  /* input from fidepartment:: in*/

			f4.seekg(0);

		while(f4.read((char*)&supplier1,sizeof(supplier1)))
			{

				node=(class supplier*)malloc(sizeof(class supplier));
				node->supplier_id=supplier1.supplier_id;
				strcpy(node->supplier_name,supplier1.supplier_name);
				node->next=NULL;
				if(h_supplier==NULL)
				{
					h_supplier=node;
					end_supplier=node;
				}
				else
				{
					end_supplier->next=node;
					end_supplier=node;
				}

		    }
			f4.close();


		};


class items
{
	public:
	int item_id;
	char item_name[20];
	float price;
	int quantity;
	int s_id;
	char category[20];
		items*next;
		void create_db_items();
		supplier*s;
		void assign_to_supplier();
	      //	virtual void new_product();
		void make_bill();
		void out_of_stock();
		void delete_product();
		void display_product();
};
class items items1,*h_items=NULL,*end_items=NULL;



class crockery:public items
{
	public:
	 
	void new_product()
	{ 
		class crockery*temp;
		temp=(class crockery*)malloc(sizeof(class crockery));
		temp->next=NULL;
		cout<<"\nEnter id of new item:";
		cin>>temp->item_id;
		cout<<"\nEnter name of new item:";
		gets(temp->item_name);
		cout<<"\nEnter price per piece:";
		cin>>temp->price;
		cout<<"\nenter quantity in pieces:";
		cin>>temp->quantity;
	}

};

class grocery:public items
{
	public:
	
	void new_product()
	{	
		class grocery*temp;
		temp=(class grocery*)malloc(sizeof(class grocery));
		temp->next=NULL;
		cout<<"\nEnter id of new product:";
		cin>>temp->item_id;
		cout<<"\nEnter name :";
		gets(temp->item_name);
		cout<<"\nEnter price per kg:";
		cin>>temp->price;
		cout<<"\nEnter quantity in kgs.:";
		cin>>temp->quantity;
	}
};

class generalitems:public items
{
	public:
	
	class generalitems*temp;
	
	void new_product()
	{ 
		//class generalitems*temp;
		
		temp=(class generalitems*)malloc(sizeof(class generalitems));
		
		temp->next=NULL;
		
		cout<<"\nEnter id of new product:";
		
		cin>>temp->item_id;
		
		cout<<"\nEnter name:";
		
		gets(temp->item_name);
		
		cout<<"\nEnter price per pack:";
		
		cin>>temp->price;
		
		cout<<"\nEnter quantity in packs:";
		
		cin>>temp->quantity;
	 }
};

class crockery crockery1,*h_crockery=NULL,*end_crockery=NULL;


class generalitems generalitems1,*h_generalitems=NULL,*end_generalitems=NULL;


class grocery grocery1,*h_grocery=NULL,*end_grocery=NULL;



void items::assign_to_supplier()
{
	class supplier *temp;
	temp=(class supplier*)malloc(sizeof(class supplier));
	temp=h_supplier;
	while(temp!=end_supplier)
	{
		if(temp->supplier_id==this->s_id)
		{
			for(int j=0;j<50;j++)
			{
				if(temp->i[j]==NULL)
				{
					temp->i[j]=this;
					break;
				}
			}
			break;
		}
		temp=temp->next;
	}
}





void items::create_db_items()
		{
			fstream f5;
			class generalitems*node1;
			class grocery*node2;
			class crockery*node3;
			//class items*node;
			f5.open("Items.dat",ios::in|ios::binary);  /* input from fidepartment:: in*/

			f5.seekg(0);

			while(f5.read((char*)&items1,sizeof(items1)))
			{
			
				if(strcmp(items1.category,"generalitems")==0)
				{
					node1=(class generalitems*)malloc(sizeof(class generalitems));
					node1->item_id=generalitems1.item_id;
					strcpy(node1->item_name,generalitems1.item_name);
					node1->s_id=generalitems1.s_id;
					node1->assign_to_supplier();
					node1->next=NULL;
					if(h_generalitems==NULL)
					{
						h_generalitems=node1;
						end_generalitems=node1;
					}
					else
					{
						end_generalitems->next=node1;
						end_generalitems=node1;
					}
				}
			
				else if(strcmp(items1.category,"crockery")==0)
				{
				node3=(class crockery*)malloc(sizeof(class crockery));
					node3->item_id=crockery1.item_id;
					strcpy(node3->item_name,crockery1.item_name);
					node3->s_id=crockery1.s_id;
					node3->assign_to_supplier();
					node3->next=NULL;
					if(h_crockery==NULL)
					{
						h_crockery=node3;
						end_crockery=node3;
					}
					else
					{
						end_crockery->next=node3;
						end_crockery=node3;
					}
				}
			
				else if(strcmp(items1.category,"grocery")==0)
				{
					node2=(class grocery*)malloc(sizeof(class grocery));
					node2->item_id=grocery1.item_id;
					strcpy(node2->item_name,grocery1.item_name);
					node2->s_id=grocery1.s_id;
					node2->assign_to_supplier();
					node2->next=NULL;
					
					if(h_grocery==NULL)
					{
						h_grocery=node2;
						end_grocery=node2;
					}
					else
					{
						end_grocery->next=node2;
						end_grocery=node2;
					}
				}



		    }
			f5.close();


		}
	

void items::make_bill()
	{
		class items bill[20];
		float sum=0;
		int q;
		class crockery *temp1;
		class grocery *temp2;
		class generalitems *temp3;
		char it[20],cat[20];
		int choice=1,i=0;
		do
		{
			cout<<"\nEnter item name:";
			gets(it);
			cout<<"\nEnter category:";
			gets(cat);
			cout<<"\nEnter quantity:";
			cin>>q;
			if(strcmpi(cat,"crockery")==0)
			{	temp1=h_crockery;
				while(temp1!=NULL)
				{
					if(strcmpi(temp1->item_name,it)==0)
						{
							if(q>temp1->quantity)
							{
								cout<<"\nRequested item not in stock";getch();
							}
							else
							{
							bill[i].item_id=temp1->item_id;
							strcpy(bill[i].item_name,temp1->item_name);
							bill[i].price=(temp1->price)*bill[i].quantity;
							sum+=bill[i].price;
							}
						}
				}

			}
			else if(strcmpi(cat,"grocery")==0)
			{	temp2=h_grocery;
				while(temp2!=NULL)
				{
					if(strcmpi(temp2->item_name,it)==0)
						{
							if(q>temp2->quantity)
							{
								cout<<"\nRequested item not in stock";getch();
							}
							else
							{
								bill[i].item_id=temp2->item_id;
								strcpy(bill[i].item_name,temp2->item_name);
								bill[i].price=(temp1->price)*bill[i].quantity;
								sum+=bill[i].price;
							}
						}
				}

			}
			else if(strcmpi(cat,"generalitems")==0)
			{	temp3=h_generalitems;
				while(temp3!=NULL)
				{
					if(strcmpi(temp3->item_name,it)==0)
						{
							if(q>temp3->quantity)
							{
								cout<<"\nRequested item not in stock";getch();
							}
							else
							{
								bill[i].item_id=temp3->item_id;
								strcpy(bill[i].item_name,temp3->item_name);
								bill[i].price=(temp1->price)*bill[i].quantity;
								sum+=bill[i].price;
							}
						}
				}

			}
		
			i++;
			cout<<"\nDo you want to enter more items?(1/0)";
			cin>>choice;
		
		}while(choice==1);
		
		
		for (int j=0;j<=i;j++)
		{
			cout<<"\nItem id:"<<bill[j].item_id;
			cout<<"\nItem name:";
			puts(bill[j].item_name);
			cout<<"\nQuantity:"<<bill[j].quantity;
			cout<<"\nCost:"<<bill[j].price;
		}
		cout<<"\nTotal cost:"<<sum;
		
		getch();
	}


	
void items::out_of_stock()
{
	class items *temp1;
	class items *temp2;
	class items*temp3;
	cout<<"\n\n\t\t\t\tOut of Stock Products\n\n";
	cout<<"\n\t\t\tGeneral items";
	temp1=h_generalitems;
	while(temp1!=NULL)
	{
		if(temp1->quantity<=20)
		{
			cout<<endl<<temp1->item_id<<"\t"<<temp1->item_name;
		}
		temp1=temp1->next;
	}
	cout<<"\n\t\t\tGrocery";
	temp2=h_grocery;
	while(temp2!=NULL)
	{
		if(temp2->quantity<=20)
		{
			cout<<endl<<temp2->item_id<<"\t"<<temp2->item_name;
		}
		temp2=temp2->next;
	}
	cout<<"\n\t\t\tCrockery";
	temp3=h_crockery;
	while(temp3!=NULL)
	{
		if(temp3->quantity<=20)
		{
			cout<<endl<<temp3->item_id<<"\t"<<temp3->item_name;
		}
		temp3=temp3->next;
	}
	
	getch();
}



void items::display_product()
{
		int id;
		char cat[20];
		class items *temp1;
		class items *temp2;
		class items*temp3;
		cout<<"\nEnter item id:";
		cin>>id;
		cout<<"\nEnter category:";
		gets(cat);

		if(strcmpi(cat,"generalitems")==0)
		{
			temp1=h_generalitems;
			while(temp1!=NULL)
			{
				if(temp1->item_id==id)
				{
					cout<<"\nItem id:"<<temp1->item_id<<"\nItem name:"<<temp1->item_name<<"\nQuantity:"<<temp1->quantity<<"\nPrice:"<<temp1->price;
				}
				temp1=temp1->next;
			}


		}

		else if(strcmpi(cat,"crockery")==0)
		{
			temp2=h_grocery;
			while(temp2!=NULL)
			{
				if(temp2->item_id==id)
				{
					cout<<"\nItem id:"<<temp2->item_id<<"\nItem name:"<<temp2->item_name<<"\nQuantity:"<<temp2->quantity<<"\nPrice:"<<temp2->price;

				}
				temp2=temp2->next;
			}

		}

		else if(strcmpi(cat,"grocery")==0)
		{
			temp3=h_crockery;
			while(temp3!=NULL)
			{
				if(temp3->item_id==id)
				{
					cout<<"\nItem id:"<<temp3->item_id<<"\nItem name:"<<temp3->item_name<<"\nQuantity:"<<temp3->quantity<<"\nPrice:"<<temp3->price;
				}
				temp3=temp3->next;
			}

		}
		
		getch();
}


class customer  /*Done*/
{
	int customer_id;
	char customer_name[20];

	public:
	class customer *next;
			void create_db_customer();
			void new_customer();
			void display_customer();
};


class customer customer1,*h_customer=NULL,*end_customer=NULL;


void customer::display_customer()
{
	int id;
	class customer*temp;
	temp=(class customer*)malloc(sizeof(class customer));
	temp=h_customer;
	cout<<"\nEnter customer id of the desired customer:";
	cin>>id;
	while(temp!=NULL)
	{
		if(temp->customer_id==id)
		{
			cout<<"\nCustomer id:"<<temp->customer_id;
			cout<<"\nCustomer name:"<<temp->customer_name;
			break;
		}
		temp=temp->next;
	}
	
	getch();
}





void customer::new_customer()
{
	class customer*temp;
	temp=(class customer*)malloc(sizeof(class customer));
	cout<<"\nenter customer_id:";
	cin>>temp->customer_id;
	cout<<"\nEnter customer name:";
	gets(temp->customer_name);
	temp->next=NULL;
	if(h_customer==NULL)
	{
		h_customer=temp;
		end_customer=temp;
	}
	else
	{
		end_customer->next=temp;
		end_customer=temp;
	}
}




void customer::create_db_customer()
{
	fstream f6;
	class customer*node;
	f6.open("Customer.dat",ios::in|ios::binary);  /* input from fidepartment:: in*/

	f6.seekg(0);

	while(f6.read((char*)&customer1,sizeof(customer1)))
	{

		node=(class customer*)malloc(sizeof(class customer));
		node->customer_id=customer1.customer_id;
		strcpy(node->customer_name,customer1.customer_name);
		node->next=NULL;
		if(h_customer==NULL)
		{
			h_customer=node;
			end_customer=node;
		}
		else
		{
			end_customer->next=node;
			end_customer=node;
		}

	}
	
	f6.close() ;
};

	
	
	
	
	
void working()
{
	clrscr();

	int option0=0, option1=0, option2=0, option3=0, option4=0, option5=0, option6=0;  /*For the Switch case*/
	int check0=0, check1=0, check2=0, check3=0, check4=0, check5=0 ,check6=0; /*For Do While loops*/

	int branch_id_to_view, department_id_to_view, staff_id_to_view; /*ID for Display*/

	int branch_id_to_delete, department_id_to_delete, staff_id_to_delete; /*ID for Deletion*/

	int department_supervisor_id_to_change, staff_id_to_change_salary; /*ID for Modification*/

	char found_staff_id_to_change_salary, found_dept_id_to_change_supervisor; /*found flag for modification*/
	char cat[20];//category for items;
	do
	{
		cout<<"What would you like work with:\n";
		cout<<"1) Customer\n2) Branch\n3) Staff\n4) Department\n5) Items\n6) Supplier\n";
		cout<<"\n\n\nEnter you choice please:\t";
		cin>>option0;

		switch(option0)
		{
			case 1:
			{
				do
					{
						clrscr();

						cout<<"\n\nWhat would you like to do?:\n";
						cout<<"\n1) Insert New Customer\n2) Display Customer Details";

						cout<<"\n\n\nEnter you choice please:\t";
						cin>>option1;

						switch(option1)
						{
							case 1:
							{ clrscr();

									cout<<"\n\n\t\t\t\tInsert New Customer\n\n";
									customer1.new_customer();
									break;
							}

							case 2:
							{
								clrscr();
									customer1.display_customer();
									break;
							}

							default:
							{
								clrscr();
									cout<<"\n\n\t\t\t\tWrong Choice Try Again";
							}
						}

						clrscr();

						cout<<"\n\nWould you like to work more in Customer?(1/0):\t";
						cin>>check1;


					}while(check1==1);

					break;

			}
			case 2:	do
					{
						clrscr();

						cout<<"\n\nWhat would you like to do?:\n";
						cout<<"\n1) Insert New Branch\n2) Display Branch Details\n3) Delete Branch";

						cout<<"\n\n\nEnter you choice please:\t";
						cin>>option2;

						switch(option2)
						{


							case 1:
							{
									clrscr();
									cout<<"\n\n\t\t\t\tInsert New Branch\n\n";
									branch1.new_branch();
									break;
							}


							case 2:
							{
									clrscr();
									branch1.display_branch_details();
									break;
							}

							case 3:
							{
									clrscr();
									branch1.delete_branch();
									break;
							}

							default:
							{
								clrscr();
								cout<<"\n\n\t\t\t\tWrong Choice Try Again";

							}


						}
						
						clrscr();
						
						

						cout<<"\n\nWould you like to work more in Branch?(1/0):\t";
						cin>>check2;
					} while (check2==1);

					break;
					case 3:	do
					{

						clrscr();

						cout<<"\n\nWhat would you like to do?:\n";
						cout<<"\n1) Insert New Staff\n2) Display Staff Details\n3) Delete Staff\n4) Update Salary\n5) Update Branch";

						cout<<"\n\n\nEnter you choice please:\t";
						cin>>option3;

						switch(option3)
						{
							case 1:
							{
								clrscr();
								cout<<"\n\n\t\t\t\tInsert New Staff\n\n";
								staff1.new_staff();
								break;
							}

							case 2:
							{
								clrscr();
								staff1.display_staff_details();
								break;
							}


							case 3:
							{
								clrscr();
								staff1.delete_staff();
								break;
							}
							case 4:
							{
								clrscr();
								staff1.update_salary();
								break;
							}


							case 5:
							{
										clrscr();
										staff1.update_branch();
										break;
							}


							default:
							{
								clrscr();
								cout<<"\n\n\t\t\t\tWrong Choice Try Again";
							}
						}



						clrscr();

						cout<<"\n\nWould you like to work more in Staff?(1/0):\t";
						cin>>check3;



					} while (check3==1);

					break;




				case 4: do
					{

						cout<<"\n\nWhat would you like to do?:\n";
						cout<<"\n1) Insert New Department\n2) Display Department Details\n3) Delete Department\n4) Change Supervisor";

						cout<<"\n\n\nEnter you choice please:\t";
						cin>>option4;

						switch(option4)
						{

							case 1:
							{
								clrscr();
								cout<<"\n\n\t\t\t\tInsert New Department\n\n";
								department1.new_department();
								break;
							}
							
							case 2:
							{
								clrscr();
								department1.display_department();
								break;
							}

							case 3:
							{
								clrscr();
								department1.delete_department();
								break;
							}
							case 4:
							{
								clrscr();
								department1.change_supervisor();
								break;
							}
							default:
							{
								clrscr();
								cout<<"\n\n\t\t\t\tWrong Choice Try Again";
							}

						}

						clrscr();

						cout<<"\n\nWould you like to work more in Department?(1/0):\t";
						cin>>check4;


					} while (check4==1);

					break;




			/*Items case*/ /*Full left*/
			case 5:	do
					{
						cout<<"\n\nWhat would you like to do?:\n";
						cout<<"\n1) Insert New Product\n2) Display a Product\n3) Display the Products which are Out of Stock\n4) Make Bill";

						cout<<"\n\n\nEnter you choice please:\t";
						cin>>option5;

						switch(option5)
						{

							case 1:
							{
								clrscr();
								cout<<"\n\n\t\t\t\tInsert New Product\n\n";
								cout<<"\nEnter category:";
								gets(cat);
								if(strcmpi(cat,"generalitems")==0)
								{
									generalitems1.new_product();
								}
								else if(strcmpi(cat,"crockery")==0)
								{
									crockery1.new_product();
								}
								else if(strcmpi(cat,"grocery")==0)
								{
									grocery1.new_product();
								}
								break;
							}
							case 2:
							{
								clrscr();
								items1.display_product();
								break;
							}
							case 3:
							{
								clrscr();
								items1.out_of_stock();
								break;
							}
							case 4:
							{
								clrscr();
								items1.make_bill();
								break;
							}
							default:clrscr();
									cout<<"\n\n\t\t\t\tWrong Choice Try Again";
						
						}



						clrscr();

						cout<<"\n\nWould you like to work more in Items?(1/0):\t";
						cin>>check5;
					

					} while (check5==1);

					break;

					case 6:	do
					{


						clrscr();

						
						cout<<"\n\nWhat would you like to do?:\n";
						cout<<"\n1) Insert New Supplier\n2) Display Supplier Details\n3) Delete Supplier";
						
						cout<<"\n\n\nEnter you choice please:\t";
						cin>>option6;

						switch(option6)
						{
							

							case 1:	
							{
									clrscr();
									cout<<"\n\n\t\t\t\tInsert New Branch\n\n";
									supplier1.new_supplier();
									break;
							}
							

							case 2:	
							{
									clrscr();
									supplier1.display_supplier_details();
									break;
							}

							case 3: 
							{
									clrscr();
									supplier1.delete_supplier();
									break;
							}

							default:
							{
								clrscr();
								cout<<"\n\n\t\t\t\tWrong Choice Try Again";
						
							}


						}
						
						clrscr();
						cout<<"\n\nWould you like to work more in Supplier?(1/0):\t";
						cin>>check6;
					} while (check6==1);

					break;


		}

		clrscr();

		cout<<"\n\nWould you like to do more?(1/0):\t";
		cin>>check0;

	}while(check0==1);


}





void main()
{
	clrscr();
	class branch br;
	class department dept;
	class staff st;
	class supplier supp;
	class customer cust;
	class items it;
	
	//login();
	
	br.create_db_branch();
	dept.create_db_department();
	st.create_db_staff();
	supp.create_db_supplier();
	it.create_db_items();
	cust.create_db_customer();
	working();
}





