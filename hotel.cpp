#include<iostream>

using namespace std;

class Hotel
{
    struct Node
    {
        int id, date;
        string name, roomtype;
        Node* next = nullptr;
    };
    
    public:
        Node* head = NULL;
        void insert(); //add room
        void menu(); //display options
        void update(); //update services
        void search(); //search for rooms
        void delt(); //remove room
        void sort(); //sorting rooms
        void show(); //show customer room details
        void list(); //room list
};

void Hotel ::menu()
{
    int choice;
    cout<<"\n\n\tWelcome to our hotel management system!\n"<<endl;
    cout<<"\t\t\tMenu\n";
    cout<<"Press 1 to add a new room."<<endl;
    cout<<"Press 2 to search for a room."<<endl;
    cout<<"Press 3 to update room's record."<<endl;
    cout<<"Press 4 to delete room."<<endl;
    cout<<"Press 5 to show added room's details."<<endl;
    cout<<"Press 6 to exit."<<endl;

    cin>> choice;
    switch(choice)
    {
        case 1: 
            insert();
            menu();
        case 2:
            search();
            menu();
        case 3:
            update();
            menu();
        case 4:
            delt();
            menu();
        case 5:
            sort();
            show();
            menu();

        default:
            cout<<"Please choose option 1 to 5";
            //menu();

    }
}

void Hotel :: insert()
{

    cout<<"\n\n\t\tHotel mangament system\n";
    /*allocates memory for and calls 
    the contructor to initialize a new node*/
    //only reference to that node is the pointer
    Node* new_node = new Node;

    cout<<"Enter room id:"<<endl;
    cin>> new_node ->id;
    cout<<"Enter name:"<<endl;
    cin>> new_node ->name;
    cout<<"Enter date:"<<endl;
    cin>>new_node ->date; 
    cout<<"Enter room type:(single/double/twin)"<<endl;
    cin>>new_node->roomtype;

    //if theres empty list
    if(head==NULL)
    {
        head = new_node;
    }
    //else pointer = head(a pointer) holding memory address
    else
    {
        Node* ptr = head;
        while(ptr->next !=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    cout<<"\nNew room inserted";
}

void Hotel :: search()
{
    cout<<"\n\n\t\tHotel management system\n";
    
    int t_id; //temp id

    //if theres empty list
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        cout<<"\nRoom ID: ";
        cin>>t_id;
        Node* ptr = head;
        //ptr->id pointing to the value of id
        while(ptr!=NULL)
        {
            if(t_id == ptr->id)
            {
                cout<<"Room ID: "<<ptr->id<<endl;
                cout<<"Name: "<<ptr->name<<endl;
                cout<<"Date: "<<ptr->date<<endl;
                cout<<"Room type: "<<ptr->roomtype<<endl;
                break;
            }
            //break;
            ptr=ptr->next;
        }
    }
}

void Hotel ::update()
{
    cout<<"\n\n\t\tHotel Managment system\n";

    int t_id;

    if(head ==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        cout<<"\n\nRoom ID:";
        cin>>t_id;
        Node *ptr = head;
        while(ptr!=NULL)
        {
            if(t_id == ptr->id)
            {
                cout<<"Room ID: ";
                cin>>ptr->id;              
                cout<<"Name: ";
                cin>>ptr->name;                
                cout<<"Date: ";
                cin>>ptr->date;
                cout<<"Room type: ";
                cin>>ptr->roomtype;

                cout<<"Update record sucessfully"<<endl;
            }
            ptr = ptr ->next;
        }
    }
}

//delete room record
void Hotel ::delt()
{
    cout<<"\n\n\t\tHotel Managment system\n";

    int t_id;

    if(head ==NULL)
    {
        cout<<"Linked list is empty"<<endl;
    }
    else
    {
        cout<<"\n\nRoom ID:";
        cin>>t_id;
        /*if room id is found at the beginning of the list, 
        proceed with deletion*/
        if(t_id = head ->id)
        {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout<<"Delete room record sucessfully."<<endl;
        }
        //if not found continue go through list till the room is found
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while(ptr!= NULL)
            {
                //if found
                if(t_id== ptr->id)
                {
                    pre->next = ptr->next;
                    delete ptr;
                    cout<<"Delete room record sucessfully\n";
                    break;
                }
                //continue loop through the list
                //save ptr to pre
                pre = ptr;
                //make current ptr point to ptr next element
                ptr = ptr->next;
            }
        }
    }
}
//show all taken room details
void Hotel :: show()
{
    Node* ptr = head;
    while(ptr!= NULL)
    {
        cout<<"\nRoomID "<<ptr->id;
        cout<<"\nName "<<ptr->name;
        cout<<"\nDate "<<ptr->date;        
        cout<<"\nRoom type "<<ptr->roomtype;
        ptr=ptr->next;
    }
}

void Hotel:: sort()
{
    if(head == NULL)
    {
        cout<<"List is empty";
        menu();
    }

    int count = 0; 
    int t_date, t_id;
    string t_name, t_roomtype;

    Node* ptr = head;
    //loop through the list to get how many room (count)
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    //With the amount of room(count)
    //Outter for loop will go through the list n times till all elements is sorted
    for(int i =1; i<=count; i++)
    {
        Node *ptr = head;
        /*Inner for loop will check current node with next node
        and switch if the current node > than next node
        go through each element 1 time*/
        for(int j= 1; j <count; j++)
        {
                //sort from small to large
                if(ptr->id > ptr->next->id)
                {
                    //create temp variables to hold data
                    t_id= ptr->id;
                    t_name= ptr->name;                    
                    t_date= ptr->date;                    
                    t_roomtype = ptr->roomtype;
                    //save data to current node
                    ptr->id = ptr->next->id;
                    ptr->name = ptr->next->name;
                    ptr->date = ptr->next->date;
                    ptr->roomtype = ptr->next->roomtype;
                    //save data to next node
                    ptr->next->id = t_id;
                    ptr->next->name = t_name;
                    ptr->next->date = t_date;
                    ptr->next->roomtype = t_roomtype;                    
                }
                ptr = ptr->next; 
                
        }
       
    }
}

int main()
{
    Hotel h;

    h.menu();

}
