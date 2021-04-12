#include <iostream>
#include <cstring>
#include <cstdlib>
#include<string>
using namespace std;

class Dishes
{
	public:
		string dishname;
		double price;
		Dishes(){
			dishname="";
			price=0; 
		}
		Dishes(string dn, double pr)
		{
			dishname = dn;
			price = pr;
		}
};

class DishesNode
{
	public:
		Dishes dishes;
		DishesNode *next;
		DishesNode(string name, double price) : dishes(name, price)
		{
			next = NULL;
		}		
};

class FoodMenu
{
	private:
		DishesNode *head;
		DishesNode *tail;
		DishesNode *current;
		DishesNode *previous;
	public:
		FoodMenu()
		{
			head = NULL;
			tail = NULL;
			current = NULL;
			previous = NULL;
		}
		~FoodMenu()
		{
			while(head != NULL)
			{
				current = head;
				head = head->next;
				delete current;
			}
		}
		void addMenu(string dishName, double price)
		{	
			if(head == NULL)
			{	
				DishesNode *newDish = new DishesNode(dishName, price);
				head = newDish;
				tail = newDish;
				cout << endl;
				cout << "Dish named: " << dishName << " with price " << price << " successfully added\n";
				cout << endl;
			}
			else
			{	
				bool duplicateDish = false;
				current = head;
				while(current != NULL)
				{
					if(current->dishes.dishname == dishName)
					{
						duplicateDish = true;
						break;
					}
					else
					{
						current = current->next;
					}
				}
				if(!duplicateDish)
				{
					DishesNode *newDish = new DishesNode(dishName, price);
					tail->next = newDish;
					tail = newDish;
					cout << endl;
					cout << "Dish named	: " << dishName << " with price " << price << " successfully added\n";
					cout << endl;
				}
				else
				{
					cout << "ERROR - Duplicate dish in the Food Menu\n";
					cout << endl;
				}
				
			}
		}
		void deleteDish(string searchKey)
		{
			bool found = false;
			previous = NULL;
			current = head;
			while(current != NULL)
			{
				if(current->dishes.dishname == searchKey)
				{
					found = true;
					break;
				}
				else
				{
					previous = current;
					current = current->next;
				}
				
			}
			if(head == NULL)
			{
				cout << "ERROR - Food Menu is empty\n";
				cout << endl;
			}
			else if(!found)
			{
				cout << "ERROR - No dish named: " << searchKey << " in the Food Menu.\n";
				cout << endl;
			}
			else
			{
				if(current == head)
				{
					head = head->next;
					delete current;
				}
				else if(current == tail)
				{
					previous->next = NULL;
					tail = previous;
					delete current;
				}
				else
				{
					previous->next = current->next;
					delete current;
				}
			}
		}
		
		void showMenu()
		{
			current = head;
			if(head == NULL)
			{
				cout << "ERROR - Food Menu is empty\n";
				cout << endl;
			}
			else 
			{
				int counter = 1;
				while(current != NULL)
				{
					cout << "Dish No		: " << counter << endl;
					cout << "Dish Name	: " << current->dishes.dishname << endl;
					cout << "Price		: RM" << current->dishes.price << endl;
					cout << "----------------------------------------" << endl;
					cout << endl; 
					
					counter++;
					current = current->next;
				}
			}
		}
		
		void countMenu()
		{
			current = head;
			int counter = 0;
			if(head == NULL)
			{
				cout << "ERROR - Food Menu is empty\n";
				cout << endl;
			}
			else 
			{
				while(current != NULL)
				{
					counter++;
					current = current->next;	
				}	
			}
			
			cout << endl;
			cout << "Total number of dish in menu: " << counter << endl;
			cout << endl;
		}
		
		void searchMenu(string searchKey)
		{
			bool found = false;
			current = head;
			if(head == NULL)
			{
				cout << "ERROR - Food Menu is empty\n";
				cout << endl;
			}
			else
			{
				while(current != NULL)
				{
					if(current->dishes.dishname == searchKey)
					{
						found = true;
						break;
					}
					else
					{
						current = current->next;
					}
							
				}
			}
			
			if(!found)
			{
				cout << "There is no dish named: " << searchKey << " in the Food Menu\n";
				cout << endl;
			}
			else
			{
				cout << "Dish name	: " << current->dishes.dishname << endl;
				cout << "Price		: " << current->dishes.price << endl;	
			}
		}
		void updateMenu(string searchKey)
		{
			bool found = false;
			current = head;
			if(head == NULL)
			{
				cout << "ERROR - Food Menu is empty\n";
				cout << endl;
			}
			else
			{
				while(current != NULL)
				{
					if(current->dishes.dishname == searchKey)
					{
						found = true;
						break;
					}
					else
					{
						current = current->next;
					}
							
				}
			}
			
			if(!found)
			{
				cout << "There is no dish named: " << searchKey << " in the Food Menu\n";
				cout << endl;
			}
			else
			{	
				int choice;
				do
				{
					cout << "1. Update dish name\n";
					cout << "2. Update dish price\n";
					cin >> choice;
				}while(choice != 1 && choice != 2);
				
				switch(choice)
				{
					
					case 1:
						{
							string updatedName;
							cout << "Enter the new dish name: ";
							cin.ignore();
							getline(cin, updatedName);
							
							current->dishes.dishname = updatedName;
							
							cout << endl;
							cout << "Successful update for dish name to " << updatedName << endl;
							cout << endl; 
							break;
						}
					case 2:
						{
							double updatedPrice;
							cout << "Enter the new dish price: ";
							cin >> updatedPrice;
							
							current->dishes.price = updatedPrice;
							cout << endl;
							cout << "Successful update for dish price to " << updatedPrice << endl;
							cout << endl; 
							break;		
						}
				}
				
			}
		}
		
		double checkMenu(string searchKey)
		{
			current = head;
			if(head == NULL)
			{
				cout << "ERROR - Food Menu is empty\n";
				cout << endl;
			}
			else
			{
				while(current != NULL)
				{
					if(current->dishes.dishname == searchKey)
					{
						return current->dishes.price;
					}
					else
					{
						current = current->next;
					}
							
				}
			}
			return 0;
		}

};

class Order
{
	public:
		Dishes dishes;
		int quantity;
		Order *next;
		Order(string name, double price, int quantity) : dishes(name, price)
		{
			next = NULL;
			this->quantity = quantity;
		}		
		
};

class OrderList
{
	private:
		Order *head;
		Order *tail;
		Order *current;
		Order *previous;
		double totalprice;
		string state;
	public:
		OrderList()
		{
			head=NULL;
			tail=NULL;
			current = NULL;
			previous = NULL;
			totalprice = 0;
			state = "Pending order";
		}
		~OrderList()
		{
			while(head != NULL)
			{
				current = head;
				head = head->next;
				delete current;
			}
			totalprice = 0;
			state = "";
		}
		void OrderDishes(FoodMenu &menu)
		{
			menu.showMenu();
			
			char reply;
			double price; // a variable use to store the price of food from food menu and 
					   // at the same time check whether the dish entered by customer is inside the menu
					   // if dish does not exist inside menu, the function checkMenu will return 0 else return price of the matched food
			 
			do
			{
				string dish; // as searchKey
				int quantity;
				cout << "Enter dish name: ";
				cin.ignore();
				getline(cin, dish);
				price = menu.checkMenu(dish);
				
				if(price)
				{
					if(head == NULL)
					{
						cout << "Enter quantity: ";
						cin >> quantity;
						Order *newOrder = new Order(dish, price, quantity);
						head = newOrder;
						tail = newOrder;
						state = "Unpaid";
					}
					else
					{
						bool duplicateDish = false;
						current = head;
						while(current != NULL)
						{
							if(current->dishes.dishname == dish)
							{
								duplicateDish = true;
								break;
							}
							else
							{
								current = current->next;
							}
						}
						if(!duplicateDish)
						{
							cout << "Enter quantity: ";
							cin >> quantity;
							Order *newOrder = new Order(dish, price, quantity);
							tail->next = newOrder;
							tail = newOrder;
						}
						else
						{
							cout << "ERROR - Duplicate dish in the Order\n";
							cout << "Select an action: \n";
							cout << "1. Enter new quantity\n";
							cout << "2. Return\n";
							int choice;
							cin >> choice;
							switch(choice)
							{
								case 1:
									{
										cout << "Enter new quantity: ";
										int newQuantity;
										cin >> newQuantity;
										current->quantity = newQuantity;
										break;
									}
								case 2:
									{
										break;
									}
							}
						}
					}
					
				}
				else
				{
					cout << "ERROR - No such dish named " << dish << " inside Food Menu\n";
					cout << endl;
				}
				
				cout << endl;
				cout << "Continue to order food? (y/n): ";
				cin >> reply;
				cout << endl;
				
			}while(reply == 'y' || reply == 'Y');
			
		}
		
		void displayOrder()
		{
			if(head == NULL)
			{
				cout << "ERROR - Empty order list\n";
				cout << endl;
			}
			else
			{
				int counter = 1;
				totalprice = 0;
				current = head;
				while(current != NULL)
				{
					cout << endl;
					cout << "Dish No	: " << counter << endl;
					cout << "Dish Name	: " << current->dishes.dishname << endl;
					cout << "Quantity	: " << current->quantity << endl; 
					cout << "-----------------------------------\n";
					totalprice += (current->quantity * current->dishes.price);
					counter++;
					current = current->next;
				}
				
				cout << "Total price	:" << totalprice << endl;
				cout << endl;
			}
		}
		
		void deleteOrder(string searchKey)
		{
			bool found = false;
			previous = NULL;
			current = head;
			while(current != NULL)
			{
				if(current->dishes.dishname == searchKey)
				{
					found = true;
					break;
				}
				else
				{
					previous = current;
					current = current->next;
				}
				
			}
			if(head == NULL)
			{
				cout << "ERROR - Order is empty\n";
				cout << endl;
			}
			else if(!found)
			{
				cout << "ERROR - No dish name as: " << searchKey << " in the Order.\n";
				cout << endl;
			}
			else
			{
				if(current == head)
				{
					head = head->next;
					delete current;
				}
				else if(current == tail)
				{
					previous->next = NULL;
					tail = previous;
					delete current;
				}
				else
				{
					previous->next = current->next;
					delete current;
				}
				cout << "Dish " << searchKey << " has been successful deleted\n";
				cout << endl;
			}
		}
		
		void searchOrder(string searchKey)
		{
			bool found = false;
			current = head;
			if(head == NULL)
			{
				cout << "ERROR - Order is empty\n";
				cout << endl;
			}
			else
			{
				while(current != NULL)
				{
					if(current->dishes.dishname == searchKey)
					{
						found = true;
						break;
					}
					else
					{
						current = current->next;
					}
							
				}
			}
			
			if(!found)
			{
				cout << "Dish name as: " << searchKey << " is not in Order.\n"; 
				cout << endl;
			}
			else
			{
				cout << "Dish name	: " << current->dishes.dishname << endl;
				cout << "Price		: " << current->dishes.price << endl;
				cout << "Quantity	: " << current->quantity << endl;	
				cout << endl;
			}
		}
		
		void updateQuantity(string searchKey)
		{
			bool found = false;
			current = head;
			if(head == NULL)
			{
				cout << "ERROR - Order is empty\n";
				cout << endl;
			}
			else
			{
				while(current != NULL)
				{
					if(current->dishes.dishname == searchKey)
					{
						found = true;
						break;
					}
					else
					{
						current = current->next;
					}
							
				}
			}
			
			if(!found)
			{
				cout << "Dish name as: " << searchKey << " is not in Order.\n";
				cout << endl;
			}
			else
			{	
				cout << "Enter the new quantity: ";
				int newQuantity;
				cin >> newQuantity;
				
				
				current->quantity = newQuantity;
				cout << "Dish " << searchKey << "'s quantity has been successful updated to " << newQuantity << endl;
				cout << endl; 
			}
		}
		
		void deliverOrder()
		{
			if(head == NULL)
			{
				cout << "ERROR - Order is empty\n";
				cout << endl;
			}
			else
			{	
					cout << "Delivering Order.....\n";
					while(head != NULL)
					{
						current = head;
						int counter = 0;
						
						cout << endl;
						cout << "Dish Name	: " << current->dishes.dishname << endl;
						cout << "Quantity	: " << current->quantity << endl; 
						cout << "Delivered\n";
						cout << "-----------------------------------\n";
						
						head = head->next;
						delete current;
					}
			}
				
				cout << endl;
		}
		string displayState()
		{
			return state;
		}
		double getTotal()
		{
			return totalprice;
		}
		void updateStatus()
		{
			state = "Paid";
		}
		
};

class Person
{
	public:
		string name;
		string password;
		double balance;
		int custID;
		Person* next;
		OrderList my_order;
		Person(string name,string password, int custID)
		{
			this->name = name;
			this->password = password;
			this->custID = custID;
			balance = 0.0;
		}
		void addBalance(double topUp)
		{
			balance = balance + topUp;
		}
		void pay(double price)
		{
			if(balance >= price)
			{
				balance = balance - price;
				cout << "Successful payment - Balance: RM" << balance << endl << endl;
				my_order.updateStatus();
			}
			else 
			{
				cout << "Error - Not enough balance, please top-up\n";
				cout << endl;
			}
		}
};

void CustomerMenu(FoodMenu &menu, Person* &customer)
{
	int choice;
		do
		{
		
		
		cout << "===== CUSTOMER MENU =====\n";
		cout << "1. ADD ORDER\n";
		cout << "2. DELETE ORDER\n";
		cout << "3. DISPLAY ORDER\n";
		cout << "4. SEARCH ORDER\n";
		cout << "5. UPDATE ORDER\n";
		cout << "6. SHOW CUSTOMER STATUS\n";
		cout << "7. TOP-UP BALANCE\n";
		cout << "8. MAKE PAYMENT\n";
		cout << "9. RETURN\n";
		cout << endl;
		
		cout << "Enter action: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				{
					cout << endl << endl;
					cout << "===== ADDING ORDER =====\n";
					customer->my_order.OrderDishes(menu);
					cout << endl;
					break;
				}
			case 2:
				{
					string dish;
					cout << endl << endl;
					cout << "===== DELETING ORDER =====\n";
					cout << "Enter dish name: ";
					cin.ignore();
					getline(cin, dish);
					cout << endl;
					customer->my_order.deleteOrder(dish);
					cout << endl;
					break;
				}
			case 3:
				{
					cout << endl << endl;
					cout << "===== DISPLAYING ORDER =====\n";
					customer->my_order.displayOrder();
					cout << endl;
					break;
				}
			case 4:
				{
					string dish;
					cout << endl << endl;
					cout << "===== SEARCHING ORDER =====\n";
					cout << "Enter dish name: ";
					cin.ignore();
					getline(cin, dish);
					cout << endl;
					customer->my_order.searchOrder(dish);
					cout << endl;
					break;
				}
			case 5:
				{
					string dish;
					cout << endl << endl;
					cout << "===== UPDATING ORDER =====\n";
					cout << "Enter dish name: ";
					cin.ignore();
					getline(cin, dish);
					cout << endl;
					customer->my_order.updateQuantity(dish);
					cout << endl;
					break;
				}
			case 6:
				{
					cout << endl << endl;
					cout << "===== CUSTOMER STATUS =====\n";
					cout << "Customer name	: " << customer->name << endl;
					cout << "Customer ID	: " << customer->custID << endl;
					cout << "Balance		: RM" << customer->balance << endl;
					cout << "Order status	: " << customer->my_order.displayState() << endl;
					cout << endl;
					break;
				}
			case 7:
				{
					cout << endl << endl;
					double topUp;
					cout << "Enter the amount that desired to top-up: RM";
					cin >> topUp;
					customer->addBalance(topUp);
					cout << "Top-up successful - Balance: " << customer->balance << endl;
					cout << endl;
					break;
				}
			case 8:
				{
					cout << endl << endl;
					customer->my_order.displayOrder();
					customer->pay(customer->my_order.getTotal());
					cout << endl;
				}
			default:
				{
					break;
				}
		}
	}while(choice != 9);

}

class Customer
{
	private:
		Person* front;
		Person* rear;
		Person* current;
		int total;
	public:
		Customer()
		{
			front = NULL;
			rear = NULL;
			current = NULL;
			total = 0;
		}
		bool isEmpty()
		{
			return (front == NULL);
		}
		void registerCust(string name, string password)
		{
			
			if(isEmpty())
			{
				total++;
				Person* newNode = new Person(name, password, total);
				front = newNode;
				rear = newNode;
			}
			else
			{
				bool redundant = false;
				current = front;
				while(current != NULL)
				{
					if(current->name == name)
					{
						redundant = true;
						break;
					}
					else
					{
						current = current->next;
					}
				}
				
				if(!redundant)
				{
					total++;
					Person* newNode = new Person(name, password, total);
					rear->next = newNode;
					rear = newNode;
				}
				else
				{
					cout << "Error - the name already registered\n";
				}
			}
		}
		void login(FoodMenu &menu)
		{
			string name;
			string password;
			bool login = false;
			
			if(isEmpty())
			{
				cout << "Error - there is no customer in the list\n";
			}
			else
			{
				do
				{
					cout << "Enter name: ";
					cin.ignore();
					getline(cin, name);
					cout << "Enter password: ";
					cin.ignore();
					getline(cin, password);
					
					current = front;
					while(current != NULL)
					{
						if(current->name == name && current->password == password)
						{
							login = true;
							cout << "Successfully login\n";
							break;
							
						}
						else
						{
							current = current->next;
						}
					}
					
					if(!login)
					{
						cout << "Error - login failed\n";
					}
					else
					{
						CustomerMenu(menu, current);
					}
					
				}while(!login);
				
			}
		}
		void ServeCustomer()
		{
			if(isEmpty())
			{
				cout << "There is no customer\n";
				cout << endl;
			}
			else
			{
				if(front->my_order.displayState() == "Paid")
				{
					cout << "Customer left: " << total << endl;
					cout << "Next customer to serve is....\n";
					cout << "Customer name	:" << front->name << endl;
					cout << "Customer order	:\n";
					front->my_order.deliverOrder();
					
					current = front;
					front = front->next;
					total--;
					delete current;
				}
				else if(front->my_order.displayState() == "Unpaid")
				{
					cout << "Customer name	:" << front->name << endl;
					cout << "Status -  Unpaid\n";
					cout << "Haven't make payment\n";
				}
				else if(front->my_order.displayState() == "Pending order")
				{
					cout << "Customer name	:" << front->name << endl;
					cout << "Status - Pending order\n";
					cout << "No order yet\n";
				}
				
			}
		
		
		}
};


void AdminMenu(FoodMenu &menu, Customer &customer)
{
	int choice;
	do
	{
		cout << "===== ADMIN MENU =====\n";
		cout << "1. ADD DISH\n";
		cout << "2. DELETE DISH\n";
		cout << "3. DISPLAY MENU\n";
		cout << "4. SEARCH MENU\n";
		cout << "5. UPDATE MENU\n";
		cout << "6. DELIVER ORDER\n";
		cout << "7. RETURN\n";
		cout << endl;
		
		cout << "Enter action: ";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				{
					string dishName;
					string dishID;
					double price;
					cout << endl << endl;
					cout << "===== ADDING DISH =====\n";
					cout << "Enter dish name: ";
					cin.ignore();
					getline(cin, dishName);
					cout << "Enter dish price: ";
					cin >> price;
					
					
					menu.addMenu(dishName, price);
					cout << endl;
					break;
				}
			case 2:
				{
					string dish;
					cout << endl << endl;
					cout << "===== DELETING DISH =====\n";
					cout << "Enter dish name: ";
					cin.ignore();
					getline(cin, dish);
					menu.deleteDish(dish);
					cout << endl;
					break;
				}
			case 3:
				{
					cout << endl << endl;
					cout << "===== SHOWING MENU =====\n";
					menu.showMenu();
					cout << endl;
					break;
				}
			case 4:
				{
					string dish;
					cout << endl << endl;
					cout << "===== SEARCHING DISH =====\n";
					cout << "Enter dish name: ";
					cin.ignore();
					getline(cin, dish);
					menu.searchMenu(dish);
					cout << endl;
					break;
				}
			case 5:
				{
					string dish;
					cout << endl << endl;
					cout << "===== UPDATING MENU =====\n";
					cout << "Enter dish name: ";
					cin.ignore();
					getline(cin, dish);
					menu.updateMenu(dish);
					cout << endl;
					break;
				}
			case 6:
				{
					cout << endl << endl;
					cout << "===== DELIVERING ORDER =====\n";
	
					customer.ServeCustomer();
					break;
				}
			default:
				{
					break;
				}
		}
		
	}while(choice != 7);
	
	
}


void loginRegisterMenu(Customer &customer, FoodMenu &menu)
{
	int reply;
	
	do
	{
		cout << "====== REGISTER OR LOGIN =====\n";
		cout << "1. REGISTER\n";
		cout << "2. LOGIN\n";
		cout << "3. EXIT\n";
		cout << endl;
		
		cin >> reply;
		
		switch(reply)
		{
			case 1:
				{
					string name;
					string password;
					cout << "Enter name: ";
					cin.ignore();
					getline(cin, name);
					cout << "Enter password: ";
					cin.ignore();
					getline(cin, password);
					customer.registerCust(name, password);
					break;
				}
			

			case 2:
				{
					customer.login(menu);
					break;
				}
				
			
			default:
				break;
		}
	}while(reply != 3);

}

int main()
{
	FoodMenu menu;
	Customer customer;
	int reply;
	do
	{
		cout << "====== FOOD ORDERING SYSTEM =====\n";
		cout << "1. ADMIN MENU\n";
		cout << "2. CUSTOMER MENU\n";
		cout << "3. EXIT\n";
		cout << endl;
		
		
		cin >> reply;
		
		switch(reply)
		{
			case 1:
				{
					AdminMenu(menu, customer);
					break;
				}
			case 2:
				{
					loginRegisterMenu(customer, menu);
					break;
				}
			default:
				{
					cout << "Thank you and have a nice day\n";
					break;
				}
		}
	}while(reply != 3);
	
	return 0;
	
}
