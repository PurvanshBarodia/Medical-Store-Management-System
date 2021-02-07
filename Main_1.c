#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fm,*fs,*fc,*fme,*fb,*fsu,*fs1, *fd;
	int choice=0, p_found = 0, len, z=0;
	char username[50], password[50], string11[50], encryptedpassword[50];
	fd = fopen("Home_Screen.txt","r");
			char ch1 = fgetc(fd);
			while (ch1 != EOF)
			{
				printf("%c",ch1);
				ch1 = fgetc(fd);
			}
	fclose (fd);
	printf ("\n\n");
	printf ("Enter user name: ");
	scanf ("%s",&username);
	printf ("Enter Password: ");
	scanf ("%s",&password);
	len = strlen (password);
	for(z=0; z<len; z++){
 		encryptedpassword[z]=password[z]+3;
		}
	//printf (encryptedpassword);
	if  (strstr(username, "Guest")){
		fd = fopen("User_EncryptedPasswords.txt","r");
		fscanf (fd,"%s",string11);
		//printf (string11);
		fscanf (fd,"%s",string11);
	}
	if (strstr(string11,encryptedpassword)){
		printf ("Login Succesful!!!");
	
	char ch;
	

	
		Main_Menu:
			system("cls");
			fm = fopen("Main_Menu.txt","r");
			ch = fgetc(fm);
			while (ch != EOF)
			{
				printf("%c",ch);
				ch = fgetc(fm);
			
			}
			printf("\n");
			fclose(fm);
		    printf("Enter your Chocice Number: ");
		    scanf("%d",&choice);
		    
		    if (choice == 1)
		    {
		    	Supplier_Menu:
		    	system("cls");
		        fs = fopen("Supplier_Menu.txt","r");
		    	ch = fgetc(fs);
			    while (ch != EOF)
			{
		    	printf("%c",ch);
			    ch = fgetc(fs);
		    }
		        printf("\nEnter your Chocice Number: ");
		        scanf("%d",&choice);
		        cs1:
		        if (choice == 1)
		       {
		        	char s_name[30], s_cno[10], s_id[3], s_city[30], s_email [30], s[300];
		        	int cs;
		        	fs = fopen("Add_Supplier_1.txt","a");
					printf ("\n\nSupplier ID:"); scanf ("%s",&s_id);
					fprintf (fs,"%s\t",s_id);
					printf ("Supplier Name:"); scanf ("%s",&s_name);
					fprintf (fs,"%s\t",s_name);
					printf ("Contact Number:"); scanf ("%s",&s_cno);
					fprintf (fs,"%s\t",s_cno);
					printf ("City:"); scanf ("%s",&s_city);
					fprintf (fs,"%s\t",s_city);
					printf ("Email ID:"); scanf ("%s",&s_email);
					fprintf (fs,"%s\n",s_email);
					printf ("\nFile is saved succesfully!!!\n");
					fclose (fs);
					printf ("\nEnter 1 to add another supplier, 2 to go supplier menu, 3 to go to main menu:");
					scanf ("%d",&cs);
					if (cs == 1){
					goto cs1;}
					else if (cs == 2){
					goto Supplier_Menu;}
					else if (cs == 3){
					goto Main_Menu;}
					
		       }
		        else if (choice == 2)
		        {
		        	char s_no[30], string [30];
		        	int s_found = 0, i = 0, us = 0, t = 0;
		        	us1:
		        		s_found = 0, i = 0, us = 0, t = 0;
					printf ("\nEnter unique 5 digit supplier number to update details:");
					us11:
		        	scanf ("%s",&s_no);
		        	if (strlen (s_no)!=5){
		        	printf("\nIvalid number!! Enter unique 5 digit supplier number to update details:");
		        	goto us11;}
		        	fs = fopen("Add_Supplier_1.txt","a+");
		        	while (!feof(fs)){
		        		fscanf (fs,"%s",string);
		        		if (strstr(string,s_no)!=0){
		        			s_found = 1;
		        			break;
		        		}
		        	}
		        	if (s_found == 1){
		        	int len = 0;
					FILE *tp; 
		        	char u_var [30];
		        	system ("cls");
		        	printf ("\t***Update Supplier ID [%s]***\n\n", s_no);
		        	printf ("\nEnter 1 to update name, 2 to update contact number, 3 to update city, 4 to update Email ID: ");
		        	scanf ("%d",&t);
		        	printf ("\n");
		        	switch (t){
		        		case 1: 
		        			tp = fs;
			        		fscanf (fs,"%s",string);
			        		printf ("Current Name: %s", string);
			        		//len = strlen (string);
			        		printf ("\nEnter new name:");
			        		scanf ("%s",&u_var);
			        		//fprintf (tp,"%s",string);
			        		//printf (string);
			        		fprintf (tp,"%s",u_var);
			        		printf ("\nName has been updated!!\n");
			        		break;
		        		case 2:
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
			        		printf ("Current Contact number: %s", string);
			        		len = strlen (string);
			        		printf ("\nEnter updated Contact:");
			        		scanf ("%s",&u_var);
			        		//fscanf (tp,"%s",string);
			        		//printf (string);
			        		fprintf (tp,"%s",u_var);
			        		printf ("\nContact has been updated!!\n");
			        		break;
			        	case 3:
			        		fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
			        		printf ("Current City: %s", string);
			        		len = strlen (string);
			        		printf ("\nEnter new City:");
			        		scanf ("%s",&u_var);
			        		//fscanf (tp,"%s",string);
			        		//printf (string);
			        		//fprintf (tp,"%s",u_var);
			        		printf ("\nCity has been updated!!\n");
			        		break;
			        	case 4:
			        		fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
			        		printf ("Current Email ID: %s", string);
			        		len = strlen (string);
			        		printf ("\nEnter new Email ID:");
			        		scanf ("%s",&u_var);
			        		//fscanf (tp,"%s",string);
			        		//printf (string);
			        		//fprintf (tp,"%s",u_var);
			        		printf ("\nEmail ID has been updated!!\n");
			        		break;
					}
					fclose (fs);
		        }
		        else{
		        	printf ("Invalid Supplier ID");
				}
				printf ("\n\nEnter 1 to update another supplier, 2 to go to supplier menu, 3 to go to main menu: ");
				scanf ("%d",&us);
				if (us == 1){
					goto us1;}
					else if (us == 2){
					goto Supplier_Menu;}
					else if (us == 3){
					goto Main_Menu;}
		        }
		        
		       	else if (choice == 3)
		        {
		        	
		        	char s_no[30], string [30];
		        	int s_found = 0, i = 0, xs = 0;
		        	xs1:
		        		s_found = 0; i = 0, xs = 0;
		        	printf ("\nEnter unique 5 digit supplier number to search details:");
		        	s1:
		        	scanf ("%s",&s_no);
		        	if (strlen (s_no)!=5){
		        	printf("\nIvalid number!! Enter unique 5 digit supplier number to search details:");
		        	goto s1;}
		        	fs = fopen("Add_Supplier_1.txt","r");
		        	while (!feof(fs)){
		        		fscanf (fs,"%s",string);
		        		if (strstr(string,s_no)!=0){
		        			s_found = 1;
		        			break;
		        		}
		        	}
		        	if (s_found == 1)
		        	{
		        		printf ("\n ***Suppier Details***");
		        		while (i<4){
		        			fscanf (fs,"%s",string);
							printf ("\n");
							switch (i){
								case 0: printf ("Name:"); break;
								case 1: printf ("Contact number:"); break;
								case 2: printf ("City:"); break;
								case 3: printf ("Email ID:");break;}
							printf (string);
		        			i++;
		        	}
		        }
		        else{
		        	printf ("Supplier not found, please check another");
				}
		        	fclose (fs);
		        	printf ("\n\nEnter 1 to search another supplier search, 2 to go to supplier menu, 3 to go to main menu: ");
		        	scanf ("%d",&xs);
					if (xs == 1){
					goto xs1;}
					else if (xs == 2){
					goto Supplier_Menu;}
					else if (xs == 3){
					goto Main_Menu;}
		        
		        	
		    }
		    
		    else if (choice == 4)
		    {
		    int ys = 0;
		    system("cls");
		    printf ("\n\t***Supplier Details***\n\n");
			printf ("SuppID  Name    Contact \tCity \tEmail ID\n");
			fs = fopen("Add_Supplier_1.txt","r");
			ch = fgetc(fs);
			while (ch != EOF)
			{
				printf("%c",ch);
				ch = fgetc(fs);
			
			}
			printf("\n");
			fclose(fs);
			printf ("\n\nEnter 1 to go to supplier menu, 2 to go to main menu: ");
		        	scanf ("%d",&ys);
					if (ys == 1){
					goto Supplier_Menu;}
					else if (ys == 2){
					goto Main_Menu;}
			}
		        
		        else if (choice == 5)
		        {
		         goto Main_Menu;
				}
			   fclose (fs);
		    } 
		    else if (choice == 2)
		    {
		        Customer_Menu:
		    	system("cls");
		        fs = fopen("Customer_Menu.txt","r");
		    	ch = fgetc(fs);
			    while (ch != EOF)
			{
		    	printf("%c",ch);
			    ch = fgetc(fs);
		    }
		        printf("\nEnter your Chocice Number: ");
		        scanf("%d",&choice);
				cc1:
		        if (choice == 1)
		        {
		        	char c_name[30], c_cno[10], c_id[3], c_city[30], c_email [30], c[300];
		        	int ccs;
		        	fs = fopen("Add_Customer_1.txt","a");
					printf ("\n\nContact Number (10 digit mobile number):"); scanf ("%s",&c_cno);
					fprintf (fs,"%s\t",c_cno);
					printf ("Customer ID:"); scanf ("%s",&c_id);
					fprintf (fs,"%s\t",c_id);
					printf ("Customer Name:"); scanf ("%s",&c_name);
					fprintf (fs,"%s\t",c_name);
					printf ("City:"); scanf ("%s",&c_city);
					fprintf (fs,"%s\t",c_city);
					printf ("Emai ID:"); scanf ("%s",&c_email);
					fprintf (fs,"%s\n",c_email);
					printf ("File saved succesfully!!!\n");
					fclose (fs);
					printf ("\nEnter 1 to Add another Customer, 2 to go customer menu, 3 to go to main menu:");
					scanf ("%d",&ccs);
					if (ccs == 1){
					goto cc1;}
					else if (ccs == 2){
					goto Customer_Menu;}
					else if (ccs == 3){
					goto Main_Menu;}
		        }
		        else if (choice == 2)
		        {
				char s_no[30], string [30];
		        	int s_found = 0, i = 0, us = 0, t = 0;
		        	cus1:
		        		s_found = 0, i = 0, us = 0, t = 0;
					printf ("\nEnter unique 10 digit customer mobile number to update details:");
					cus11:
		        	scanf ("%s",&s_no);
		        	if (strlen (s_no)!=10){
		        	printf("\nIvalid number!! Enter 10 digit customer mobile number to update details:");
		        	goto cus11;}
		        	fs = fopen("Add_Customer_1.txt","a+");
		        	while (!feof(fs)){
		        		fscanf (fs,"%s",string);
		        		if (strstr(string,s_no)!=0){
		        			s_found = 1;
		        			break;
		        		}
		        	}
		        	if (s_found == 1){
		        	int len = 0;
					FILE *tp; 
		        	char u_var [30];
		        	system ("cls");
		        	printf ("\t***Update Customer [%s]***\n\n",s_no);
		        	printf ("\nEnter 1 to update customer ID, 2 to update name, 3 to update city, 4 to update Email ID: ");
		        	scanf ("%d",&t);
		        	printf ("\n");
		        	switch (t){
		        		case 1: 
		        			tp = fs;
			        		fscanf (fs,"%s",string);
			        		printf ("Current ID: %s", string);
			        		len = strlen (string);
			        		printf ("\nEnter new customer ID:");
			        		scanf ("%s",&u_var);
			        		//fscanf (tp,"%s",string);
			        		//printf (string);
			        		fprintf (tp,"%s",u_var);
			        		printf ("\nCustomer ID has been updated!!\n");
			        		break;
		        		case 2:
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
			        		printf ("Current customer name: %s", string);
			        		len = strlen (string);
			        		printf ("\nEnter new contact number:");
			        		scanf ("%s",&u_var);
			        		//fscanf (tp,"%s",string);
			        		//printf (string);
			        		//fprintf (tp,"%s",u_var);
			        		printf ("\nCustomer name has been updated!!\n");
			        		break;
			        	case 3:
			        		fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
			        		printf ("Current City: %s", string);
			        		len = strlen (string);
			        		printf ("\nEnter updated City:");
			        		scanf ("%s",&u_var);
			        		//fscanf (tp,"%s",string);
			        		//printf (string);
			        		//fprintf (tp,"%s",u_var);
			        		printf ("\nCity has been updated!!\n");
			        		break;
			        	case 4:
			        		fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
		        			fscanf (fs,"%s",string);
			        		printf ("Current Email ID: %s", string);
			        		len = strlen (string);
			        		printf ("\nEnter updated Email ID:");
			        		scanf ("%s",&u_var);
			        		//fscanf (tp,"%s",string);
			        		//printf (string);
			        		//fprintf (tp,"%s",u_var);
			        		printf ("\nEmail ID has been updated!!\n");
			        		break;
					}
		        }
		        else{
		        	printf ("Customer mobile number not found!!");
				}
				printf ("\n\nEnter 1 to update another customer, 2 to go to customer menu, 3 to go to main menu: ");
				scanf ("%d",&us);
				if (us == 1){
					goto cus1;}
					else if (us == 2){
					goto Supplier_Menu;}
					else if (us == 3){
					goto Main_Menu;}
		        }
		        else if (choice == 3)
		        {
		    		char s_no[30], string [30];
		        	int s_found = 0, i = 0, cs = 0;
		        	cxs1:
		        		s_found = 0; i = 0, cs = 0;
		        	printf ("\nEnter 10 digit customer mobile number to search details:");
		        	cuss1:
		        	scanf ("%s",&s_no);
		        	if (strlen (s_no)!=10){
		        		system ("cls");
		        	printf("\nIvalid number!! Enter unique 10 digit customer mobile number to search details:");
		        	goto cuss1;}
		        	fs = fopen("Add_Customer_1.txt","r");
		        	while (!feof(fs)){
		        		fscanf (fs,"%s",string);
		        		if (strstr(string,s_no)!=0){
		        			s_found = 1;
		        			break;
		        		}
		        	}
		        	if (s_found == 1)
		        	{
		        		printf ("\n ***Customer Details***");
		        		while (i<4){
		        			fscanf (fs,"%s",string);
							printf ("\n");
							switch (i){
								case 0: printf ("Customer ID: "); break;
								case 1: printf ("Name:"); break;
								case 2: printf ("City:"); break;
								case 3: printf ("Email ID:");break;}
							printf (string);
		        			i++;
		        	}
		        }
		        else{
		        	printf ("Customer not found, please check another");
				}
		        	fclose (fs);
		        	printf ("\n\nEnter 1 to search another customer, 2 to go to customer menu, 3 to go to main menu: ");
		        	scanf ("%d",&cs);
					if (cs == 1){
					goto cxs1;}
					else if (cs == 2){
					goto Customer_Menu;}
					else if (cs == 3){
					goto Main_Menu;}
		    }
		    
		    else if (choice == 4)
		    {
		    int ys = 0;
		    system("cls");
		    printf ("\n\t***Customer Details***\n\n");
			printf ("CustMobile  Name    CustID \tCity \tEmail ID\n");
			fs = fopen("Add_Customer_1.txt","r");
			ch = fgetc(fs);
			while (ch != EOF)
			{
				printf("%c",ch);
				ch = fgetc(fs);
			
			}
			printf("\n");
			fclose(fs);
			printf ("\n\nEnter 1 to go to Customer menu, 2 to go to main menu: ");
		        	scanf ("%d",&ys);
					if (ys == 1){
					goto Customer_Menu;}
					else if (ys == 2){
					goto Main_Menu;}
			}
		        else if (choice == 5)
		        {
		         goto Main_Menu;
				}
		        fclose (fc);
			}
		    else if (choice == 3)
		    {
		    	Medicine_Menu:
		    	system("cls");
		        fs = fopen("Medicine_Menu.txt","r");
		    	ch = fgetc(fs);
			    while (ch != EOF)
			{
		    	printf("%c",ch);
			    ch = fgetc(fs);
		    }
		        printf("\nEnter your Chocice Number: ");
		        scanf("%d",&choice);
		        mcs1:
		        if (choice == 1)
		        {
		        char m_name[30], m_id[10], m_cat[30], m_supp[30], m_stock[30], m_price[30], s[300];
		        	int cs, amount, qua;
		        	fs = fopen("Add_Medicine_1.txt","a");
		        	printf ("\n\nMedicine Name:"); scanf ("%s",&m_name);
					fprintf (fs,"%s\t",m_name);
					printf ("Medicine ID:"); scanf ("%s",&m_id);
					fprintf (fs,"%s\t",m_id);
					printf ("Supplier Name:"); scanf ("%s",&m_supp);
					fprintf (fs,"%s\t",m_supp);
					printf ("Category:"); scanf ("%s",&m_cat);
					fprintf (fs,"%s\t",m_cat);
					printf ("Stock:"); scanf ("%s",&m_stock);
					fprintf (fs,"%s\t",m_stock);
					printf ("Price per unit:"); scanf ("%s",&m_price);
					fprintf (fs,"%s\n",m_price);
					printf ("File is saved succesfully!!!\n");
					fclose (fs);
					printf ("\nEnter 1 to Add another medicine, 2 to go medicine menu, 3 to go to main menu:");
					scanf ("%d",&cs);
					if (cs == 1){
					goto mcs1;}
					else if (cs == 2){
					goto Medicine_Menu;}
					else if (cs == 3){
					goto Main_Menu;}	
		    }
				else if (choice == 2)
		        {
		        	char c_mno[30], string [300], m_name[30], string1 [300], b_price[30], b_mname[30], b_cname[30], b_cid[30], b_cmobile[30];
		        	int s_found = 0, m_found, t_var, qua, amount;
		        	t_billing:
		        		s_found = 0, m_found = 0, t_var = 0, qua = 0, amount = 0;
		        	system ("cls");
		        	printf ("Enter Customer Mobile Number:");
		        	cmo1:
		        	scanf ("%s",&c_mno);
		        	if (strlen (c_mno)!=10){
		        	printf("\nIvalid mobile number!! Enter 10 digit customer mobile number:");
		        	goto cmo1;}
		        	fs = fopen("Add_Customer_1.txt","r");
		        	while (!feof(fs)){
		        		fscanf (fs,"%s",string);
		        		if (strstr(string,c_mno)!=0){
		        			s_found = 1;
		        			break;
		        		}
		        }
		        if (s_found == 1){
		        	strcpy(b_cmobile,string);
		        	//b_cmobile = string;
		        	fscanf (fs,"%s",string);
		        	strcpy(b_cid,string);
		        	//b_cid = string;
		        	fscanf (fs,"%s",string);
		        	strcpy(b_cname,string);
		        	//b_cname = string;
		        	printf ("\nEnter medicine name:");
		    		scanf ("%s",m_name);
		    		fs = fopen("Add_Medicine_1.txt","r");
		        	while (!feof(fs)){
		        		fscanf (fs,"%s",string1);
		        		if (strstr(string1,m_name)!=0){
		        			m_found = 1;
		        			break;
		        		}
		        }
		        if (m_found == 1){
		        	int ab;
		        	strcpy(b_mname,string1);
					//b_mname = string1;
		        	printf ("\n\nMedicine Name:%s",b_mname);
		        	fscanf (fs,"%s",string1);
		        	fscanf (fs,"%s",string1);
		        	fscanf (fs,"%s",string1);
		        	fscanf (fs,"%s",string1);
		        	fscanf (fs,"%s",string1);
		        	strcpy(b_price,string1);
		        	//b_price = string1;
		        	printf("\nPrice: %s", b_price);
		        	printf ("\nEnter quantity: ");
		        	scanf ("%d",&qua);
		        	printf ("\nEnter 1 to display and print the bill: ");
		        	scanf ("%d",&ab);
		        	if (ab == 1){
		        		system ("cls");
		        		printf ("\t\t\t ***Customer Invoice***");
		        		printf ("\n\n\nCustomer name: %s",b_cname);
		        		printf ("\tCutomer ID: %s",b_cid);
		        		printf ("\tCustomer mobile: %s", b_cmobile);
		        		printf ("\n\nMedicine Name: %s",b_mname);
		        		printf ("\tPrice:%s",b_price);
		        		printf ("\tQuantity:%d",qua);
		        		amount = atoi(b_price);
		        		amount = qua * amount;
		        		printf ("\n\n\n\t\t\t\t\t Total Amount:<<<%d>>>",amount);
					}
					int final = 0;
					printf ("\n\nEnter 1 to save the bill in text file, 2 to go to billing page, 3 to go to medicine page, 4 to go to main menu:");
					scanf ("%d",&final);
					switch (final){
						case 1:
							fs1 = fopen("Add_Billing_1.txt","a");
							fprintf (fs1,"%s\t",b_cname);
							fprintf (fs1,"%s\t",b_cid);
							fprintf (fs1,"%s\t",b_cmobile);
							fprintf (fs1,"%s\t",b_mname);
							fprintf (fs1,"%s\t",b_price);
							fprintf (fs1,"%d\t",qua);
							fprintf (fs1,"%d\n",amount);
							printf ("\n[Bill saved to file]");
							fclose (fs1);
							break;
						case 2:
							goto t_billing;
							break;
						case 3:
							goto Medicine_Menu;
							break;
						case 4:
							goto Main_Menu;
							break;
					}
					int ij = 0;
					printf ("\n\n\nEnter 1 to go to billing page, 2 to go to main page:");
					scanf ("%d",&ij);
					if (ij == 1)
					goto t_billing;
					if (ij == 2)
					goto Main_Menu;
				}
				else{
					printf ("\nMedine not in found stock, enter 1 to go to medicine menu, 2 to go to billing page:");
					scanf ("%d",&t_var);
					if (t_var == 1){
						goto Medicine_Menu;
					}
					else if (t_var == 2){
						goto Billing_Menu;
					}
				}
			}
				else{
					printf ("Customer mobile number not found");
					printf ("\nEnter 1 to go to customer menu, 2 to go to billing page:");
					scanf ("%d",&t_var);
					if (t_var == 1){
						goto Customer_Menu;
					}
					else if (t_var == 2){
						goto Billing_Menu;
					}
					
				}
		    }
		        else if (choice == 3)
		        {
		        	int ys = 0;
		    system("cls");
		    printf ("\n\t***Medicine Stock Details***\n\n");
			printf ("Name   MID   \tMSUPP     \tMCAT   \tMSTOCK \tMPRICE\n");
			fs = fopen("Add_Medicine_1.txt","r");
			ch = fgetc(fs);
			while (ch != EOF)
			{
				printf("%c",ch);
				ch = fgetc(fs);
			
			}
			printf("\n");
			fclose(fs);
			printf ("\n\nEnter 1 to go to medicine menu, 2 to go to main menu: ");
		        	scanf ("%d",&ys);
					if (ys == 1){
					goto Medicine_Menu;}
					else if (ys == 2){
					goto Main_Menu;}
		        }
		        else if (choice == 4)
		        {
		         goto Main_Menu;
				}
				fclose (fme);
		   }
			else if (choice == 4)
		    {
		    	int ys = 0;
		    	Billing_Menu:
		    	system("cls");
		        fs = fopen("Billing_Menu.txt","r");
		    	ch = fgetc(fs);
			    while (ch != EOF)
			{
		    	printf("%c",ch);
			    ch = fgetc(fs);
		    }
		        printf("\nEnter your Choice Number: ");
		        scanf("%d",&choice);
		    	if (choice == 1){
		    	system ("cls");
		        goto t_billing;
		    }
		        else if (choice == 2){
		        	system ("cls");
		    printf ("\n\t***billing Details***\n\n");
			printf ("Name    ID \tMoile    \tMname  \tPrice  \tQuntity Total\n");
			fs = fopen("Add_Billing_1.txt","r");
			ch = fgetc(fs);
			while (ch != EOF)
			{
				printf("%c",ch);
				ch = fgetc(fs);
			
			}
			printf("\n");
			fclose(fs);
			printf ("\n\nEnter 1 to go to Billing menu, 2 to go to main menu: ");
		        	scanf ("%d",&ys);
					if (ys == 1){
					goto Billing_Menu;}
					else if (ys == 2){
					goto Main_Menu;}
		        	
				}
				else if (choice == 3)
				goto Main_Menu;
			}
		}
		else{
			printf ("\n\nInvalid username or password.. Contact Admin for help!!");
		}
                return 0;
}
	

