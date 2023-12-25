#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    Node *left1;
    Node *left2;
    Node *right1;
    Node *right2;
    string Name;
    string flatstatus;
    string lifestatus;
    string TelephoneNo;
    int flatno;
    double totalMain;
    Node *next;

    Node(string Name, string flatstatus, string lifestatus, int flatno, string TelephoneNo, double totalmain)
    {
        left = right = nullptr;
        left1 = left2 = right1 = right2 = nullptr;
        this->Name = Name;
        this->flatstatus = flatstatus;
        this->lifestatus = lifestatus;
        this->flatno = flatno;
        this->TelephoneNo = TelephoneNo;
        this->totalMain = 2500.0;
        next = nullptr;
    }

    void display()
    {
        cout << setw(35) << this->Name << setw(20) << this->flatno << setw(23) << this->flatstatus << setw(20) << this->lifestatus << setw(23) << this->TelephoneNo << setw(16) << this->totalMain << endl;
    }

    void displayno()
    {
        cout << setw(35) << this->Name << setw(20) << this->flatno << setw(23) << this->TelephoneNo << endl;
    }

    void displaystatus()
    {
        cout << setw(35) << this->Name << setw(20) << this->flatno << setw(23) << this->flatstatus << setw(20) << this->lifestatus << endl;
    }

    void displaymain()
    {
        if (this->totalMain == 0)
        {
            cout << setw(14) << this->flatno << setw(20) << "Paid" << endl;
        }
        else if (this->totalMain > 0)
        {
            cout << setw(14) << this->flatno << setw(17) << "Due:" << this->totalMain << endl;
        }
        else if (this->totalMain < 0)
        {
            cout << setw(14) << this->flatno << setw(20) << "Paid" << endl;
        }
        else
        {
            return;
        }
    }
};
class BinarySearchTree
{

public:
    Node *root;
    Node *root1;
    Node *head;
    Node *tail;
    Node *root2;
    int count = 0;
    stack<Node *> q;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    void create()
    {
        string Name, flatstatus, lifestatus, TelephoneNo;
        int flatno;
        float totalMain;
        int ch = 0;
        do
        {
            string Namef, Namem, Namel;
            cout << "Enter Flat number: ";
            cin >> flatno;
            Node *ptr1 = root;
            while (ptr1 != nullptr)
            {
                if (flatno == ptr1->flatno)
                {
                    cout << "!!!Flat number already exist!!!" << endl;
                    return;
                }
                else if (flatno < ptr1->flatno)
                {
                    ptr1 = ptr1->left;
                }
                else
                {
                    ptr1 = ptr1->right;
                }
            }
            cout << "Name" << endl;
            cout << "Enter first Name: ";
            cin >> Namef;
            cout << "Enter Middle Name: ";
            cin >> Namem;
            cout << "Enter last Name: ";
            cin >> Namel;
            Name = Namef + " " + Namem + " " + Namel;
            do
            {
                cout << "Enter are you owner or tenant: ";
                cin >> flatstatus;
                if (flatstatus == "owner" || flatstatus == "tenant")
                {
                    break;
                }
                else
                {
                    cout << "Enter correct one" << endl;
                }
            } while ((flatstatus == "owner" || flatstatus == "tenant") != true);
            do
            {
                cout << "Enter are you family or bachelor: ";
                cin >> lifestatus;
                if (lifestatus == "family" || lifestatus == "bachelor")
                {
                    break;
                }
                else
                {
                    cout << "Enter correct one" << endl;
                }
            } while ((lifestatus == "family" || lifestatus == "bachelor") != true);
            totalMain = 2500;
            do
            {
                cout << "Enter phone number: ";
                cin >> TelephoneNo;
                if (TelephoneNo.length() == 10)
                {
                    Node *temp = new Node(Name, flatstatus, lifestatus, flatno, TelephoneNo, totalMain);
                    if (root == nullptr)
                    {
                        root = temp;
                        count++;
                    }
                    else
                    {
                        Node *ptr = root;
                        while (ptr != nullptr)
                        {
                            if (temp->flatno < ptr->flatno)
                            {
                                if (ptr->left == nullptr)
                                {
                                    ptr->left = temp;
                                    count++;
                                    break;
                                }
                                else
                                {
                                    ptr = ptr->left;
                                }
                            }
                            else if (temp->flatno > ptr->flatno)
                            {
                                if (ptr->right == nullptr)
                                {
                                    ptr->right = temp;
                                    count++;
                                    break;
                                }
                                else
                                {
                                    ptr = ptr->right;
                                }
                            }
                            else
                            {
                                cout << "!!!!Already Exist!!!!" << endl;
                                break;
                            }
                        }
                    }
                    cout << "******Record stored succesfully******" << endl;
                }
                else
                {
                    cout << "Enter valid phone number" << endl;
                }
            } while (TelephoneNo.length() != 10);
            cout << "\nDo you want to add more Member's information ?\nPress '1' to continue\nPress '0' to exit :";
            cin >> ch;
            cout << endl;
        } while (ch != 0);
    }

public:
    void displayinfo()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << "Name"
                 << "\t"
                 << "Flat Number"
                 << "\t"
                 << "Flatstatus"
                 << "\t"
                 << "Lifestatus"
                 << "\t"
                 << "Phone number"
                 << "\t"
                 << "MAintainence" << endl;
            displayinfo(root);
        }
    }

private:
    void displayinfo(Node *node)
    {
        if (node != nullptr)
        {
            displayinfo(node->left);
            node->display();
            displayinfo(node->right);
        }
    }

public:
    void displayphoneno()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << "Name"
                 << "\t"
                 << "Flat Number"
                 << "\t"
                 << "Phone number" << endl;
            displayphoneno(root);
        }
    }

private:
    void displayphoneno(Node *node)
    {
        if (node != nullptr)
        {
            displayphoneno(node->left);
            node->displayno();
            displayphoneno(node->right);
        }
    }

public:
    void displaystatus()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << "Name"
                 << "\t"
                 << "Flat Number"
                 << "\t"
                 << "Flatstatus"
                 << "\t"
                 << "Lifestatus" << endl;
            displaystatus(root);
        }
    }

private:
    void displaystatus(Node *node)
    {
        if (node != nullptr)
        {
            displaystatus(node->left);
            node->displaystatus();
            displaystatus(node->right);
        }
    }

public:
    void displaymaint()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << "Flat number"
                 << "\t"
                 << "Maintainence" << endl;
            displaymaint(root);
        }
    }

private:
    void displaymaint(Node *node)
    {
        if (node != nullptr)
        {
            displaymaint(node->left);
            node->displaymain();
            displaymaint(node->right);
        }
    }

public:
    void search()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
            return;
        }
        int chs;
        cout << "1. Search by Flat Number\n2. Search by Phone Number\nEnter your choice: ";

        cin >> chs;
        if (chs == 1)
        {
            cout << "Enter the Flat number to search: ";
            int fno;
            cin >> fno;
            Node *ptr = root;
            while (ptr != nullptr)
            {
                if (fno == ptr->flatno)
                {
                    cout << "Found!" << endl;
                    cout << "Name: " << ptr->Name << endl;
                    cout << "Flat Number: " << ptr->flatno << endl;
                    cout << "Flat Status: " << ptr->flatstatus << endl;
                    cout << "Life Status: " << ptr->lifestatus << endl;
                    cout << "Phone Number: " << ptr->TelephoneNo << endl;

                    return;
                }
                else if (fno < ptr->flatno)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        if (chs == 2)
        {
            string phno;
            do
            {
                cout << "Enter the phone number to search: ";
                cin >> phno;
                if (phno.length() == 10)
                {
                    break;
                }
                else
                {
                    cout << "Enter a valid 10-digit Phone Number" << endl;
                }
            } while (phno.length() == 10);
            Node *ptr = root;
            while (ptr != nullptr)
            {
                if (phno == ptr->TelephoneNo)
                {
                    cout << "Found." << endl;
                    cout << " Name: " << ptr->Name << endl;
                    cout << " Flat number: " << ptr->flatno << endl;
                    cout << " Flatstatus: " << ptr->flatstatus << endl;
                    cout << " lifestatus: " << ptr->lifestatus << endl;
                    cout << " phone number: " << ptr->TelephoneNo << endl;
                    return;
                }
                else if (phno.compare(ptr->TelephoneNo) < 0)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
    }

public:
    void update()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << "Enter the Flat number to update: ";
            int fno;
            cin >> fno;
            Node *ptr = root;
            while (ptr != nullptr)
            {
                if (fno == ptr->flatno)
                {
                    cout << "Choose the field to update:\n";
                    cout << "1. Name\n";
                    cout << "2. Flat number\n";
                    cout << "3. Flat status\n";
                    cout << "4. Life status\n";
                    cout << "5. Telephone number\n";
                    cout << "0. Exit\n";
                    cout << "Enter your choice: ";

                    int ch1;
                    cin >> ch1;
                    if (ch1 == 1)
                    {
                        cout << "Name" << endl;
                        cout << "Enter first Name: ";
                        string Namef;
                        cin >> Namef;
                        cout << "Enter Middle Name: ";
                        string Namem;
                        cin >> Namem;
                        cout << "Enter last Name: ";
                        string Namel;
                        cin >> Namel;
                        ptr->Name = Namef + " " + Namem + " " + Namel;
                    }
                    else if (ch1 == 2)
                    {
                        cout << "Enter Flat number: ";
                        cin >> ptr->flatno;
                        Node *ptr1 = root;
                        while (ptr1 != nullptr)
                        {
                            if (ptr->flatno == ptr1->flatno)
                            {
                                cout << "The flat number provided is already in the record." << endl;

                                return;
                            }
                            else if (ptr->flatno < ptr1->flatno)
                            {
                                ptr1 = ptr1->left;
                            }
                            else
                            {
                                ptr1 = ptr1->right;
                            }
                        }
                    }
                    else if (ch1 == 3)
                    {
                        do
                        {
                            cout << "Enter are you owner or tenant: ";
                            cin >> ptr->flatstatus;
                            if (ptr->flatstatus == "owner" || ptr->flatstatus == "tenant")
                            {
                                break;
                            }
                            else
                            {
                                cout << "Enter correct one" << endl;
                            }
                        } while ((ptr->flatstatus == "owner" || ptr->flatstatus == "tenant") != true);
                    }
                    else if (ch1 == 4)
                    {
                        do
                        {
                            cout << "Are you a part of a family or living solo? :";
                            cin >> ptr->lifestatus;
                            if (ptr->lifestatus == "family" || ptr->lifestatus == "bachelor")
                            {
                                break;
                            }
                            else
                            {
                                cout << "Enter correct one" << endl;
                            }
                        } while ((ptr->lifestatus == "family" || ptr->lifestatus == "bachelor") != true);
                    }
                    else if (ch1 == 5)
                    {
                        do
                        {
                            cout << "Enter phone number: ";
                            cin >> ptr->TelephoneNo;
                            if (ptr->TelephoneNo.length() == 10)
                            {
                                break;
                            }
                            else
                            {
                                cout << "Enter a valid 10-digit Phone Number" << endl;
                            }
                        } while (ptr->TelephoneNo.length() != 10);
                    }
                    else if (ch1 == 0)
                    {
                        break;
                    }
                }
                else if (fno < ptr->flatno)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
    }

    void deleteNode()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << "Enter the flat number to delete: ";
            int fno;
            cin >> fno;
            root = deleteNode(root, fno);
            cout << "Deleted succesfully" << endl;
        }
    }

private:
    Node *deleteNode(Node *root, int fno)
    {
        if (root == nullptr)
            return root;
        if (fno < root->flatno)
            root->left = deleteNode(root->left, fno);
        else if (fno > root->flatno)
            root->right = deleteNode(root->right, fno);
        else
        {
            if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;
            Node *temp = getSuccessor(root->right);
            root->flatno = temp->flatno;
            root->Name = temp->Name;
            root->flatstatus = temp->flatstatus;
            root->lifestatus = temp->lifestatus;
            root->TelephoneNo = temp->TelephoneNo;
            root->totalMain = temp->totalMain;
            root->right = deleteNode(root->right, root->flatno);
        }
        return root;
    }

private:
    Node *getSuccessor(Node *node)
    {
        int flatno = node->flatno;
        string Name = node->Name;
        string flatstatus = node->flatstatus;
        string lifestatus = node->lifestatus;
        string TelephoneNo = node->TelephoneNo;
        double totalMain = node->totalMain;
        while (node->left != nullptr)
        {
            flatno = node->left->flatno;
            Name = node->left->Name;
            flatstatus = node->left->flatstatus;
            lifestatus = node->left->lifestatus;
            TelephoneNo = node->left->TelephoneNo;
            totalMain = node->left->totalMain;
            node = node->left;
        }
        return new Node(Name, flatstatus, lifestatus, flatno, TelephoneNo, totalMain);
    }

public:
    void sortBt(int choice)
    {
        Node *ptr;
        Node *temp;
        head = tail = root;
        q.push(tail);
        ptr = q.top();
        do
        {
            if (tail->left != nullptr)
            {
                temp = tail->left;
                q.top()->next = temp;
                q.push(temp);
            }
            if (tail->right != nullptr)
            {
                temp = tail->right;
                q.top()->next = temp;
                q.push(temp);
            }
            if (tail != nullptr)
            {
                tail = tail->next;
            }
        } while (tail != nullptr);
        if (choice == 3)
        {
            ptr = head;
            root1 = head;
            while (ptr->next != q.top()->next)
            {
                if (stol(ptr->TelephoneNo) < stol(ptr->next->TelephoneNo))
                {
                    ptr->right1 = ptr->next;
                    ptr = ptr->next;
                }
                else if (stol(ptr->TelephoneNo) > stol(ptr->next->TelephoneNo))
                {
                    ptr->left1 = ptr->next;
                    ptr = ptr->next;
                }
            }
        }
        else if (choice == 4)
        {
            ptr = head;
            root2 = head;
            int i = 0;
            while (ptr->next != q.top()->next)
            {
                if (!ptr->Name.compare(ptr->next->Name) && (int)ptr->Name.at(i) == (int)ptr->next->Name.at(i))
                {
                    i = i++;
                }
                else if ((int)ptr->Name.at(i) < (int)ptr->next->Name.at(i))
                {
                    ptr->right2 = ptr->next;
                    ptr = ptr->next;
                }
                else if ((int)ptr->Name.at(i) > (int)ptr->next->Name.at(i))
                {
                    ptr->left2 = ptr->next;
                    ptr = ptr->next;
                }
            }
        }
    }

public:
    void sort_phone(Node *ph_node)
    {
        if (ph_node == nullptr)
        {
            return;
        }
        sort_phone(ph_node->left1);
        cout << ph_node->TelephoneNo << "\t" << ph_node->Name << endl;
        sort_phone(ph_node->right1);
    }

    void sort_Name(Node *nm_node)
    {
        if (nm_node == nullptr)
        {
            return;
        }
        sort_Name(nm_node->left2);
        cout << nm_node->Name << "\t" << nm_node->TelephoneNo << endl;
        sort_Name(nm_node->right2);
    }

public:
    void maintenance()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
            return;
        }
        else
        {
            int ch6;
            cout << "╔══════════ Maintenance ══════════╗" << endl;
            cout << "│        For the Next 6 Months    │" << endl;
            cout << "├───────┬────────────┬────────────┤" << endl;
            cout << "│   #   │ Maintenance│   Cost     │" << endl;
            cout << "├───────┼────────────┼────────────┤" << endl;
            cout << "│   1   │ Housekeeping│    500     │" << endl;
            cout << "│   2   │ Parking    │    500     │" << endl;
            cout << "│   3   │ Watchmen   │    500     │" << endl;
            cout << "│   4   │ Gardener   │    500     │" << endl;
            cout << "│   5   │ Hall Clean.│    500     │" << endl;
            cout << "└───────┴────────────┴────────────┘" << endl;
            cout << "Total Maintenance Cost: 2500.0" << endl;
            cout << "1. Pay Maintenance" << endl;
            cout << "0. Exit" << endl;
            cout << "Enter your choice: ";

            cin >> ch6;
            if (ch6 == 1)
            {
                cout << "Enter the Flat number to pay Maintainence: ";
                int fno;
                cin >> fno;
                Node *ptr = root;
                while (ptr != nullptr)
                {
                    if (fno == ptr->flatno)
                    {
                        cout << "Enter the amount: ";
                        double amt;
                        cin >> amt;
                        ptr->totalMain = ptr->totalMain - amt;
                        if (ptr->totalMain == 0)
                        {
                            cout << "Paid.." << endl;
                            return;
                        }
                        else if (ptr->totalMain > 0)
                        {
                            cout << "Due Maintainence: " << ptr->totalMain << endl;
                            return;
                        }
                        else
                        {
                            cout << "The amount entered exceeds 2500" << endl;
                            cout << "Please take back the excess amount of " << (-2 * ptr->totalMain + ptr->totalMain) << " from the admin" << endl;
                            cout << "For inquiries, contact: 123*******" << endl;
                            cout << "Payment processed successfully." << endl;

                            return;
                        }
                    }
                    else if (fno < ptr->flatno)
                    {
                        ptr = ptr->left;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
                cout << "╔═══════════════════════════╗" << endl;
                cout << "║      No Records Found     ║" << endl;
                cout << "╚═══════════════════════════╝" << endl;
            }
            else if (ch6 == 0)
            {
                return;
            }
            else
            {
                cout << "Invalid choice" << endl;
            }
        }
    }
};
class Node1
{
public:
    Node1 *left;
    Node1 *right;
    std::string Namew;
    std::string aow;
    std::string present;
    std::string telephoneNo1;
    int Id;

    Node1(int Id, std::string Namew, std::string aow, std::string telephoneNo1, std::string present)
    {
        left = right = nullptr;
        this->Namew = Namew;
        this->aow = aow;
        this->Id = Id;
        this->telephoneNo1 = telephoneNo1;
        this->present = "Not there";
    }

    void display()
    {
        std::cout << std::setw(35) << this->Namew << std::setw(20) << this->Id << std::setw(15) << this->aow << std::setw(25) << this->telephoneNo1 << std::setw(18) << this->present << std::endl;
    }
};

class BST
{
    Node1 *root;

public:
    BST()
    {
        root = nullptr;
    }
    void create1()
    {
        string Namew, aow, present, telephoneNo1;
        int Id;
        int ch;
        do
        {
            string Namef, Namem, Namel;
            cout << "Name" << endl;
            cout << "Enter first Name: ";
            cin >> Namef;
            cout << "Enter Middle Name: ";
            cin >> Namem;
            cout << "Enter last Name: ";
            cin >> Namel;
            Namew = Namef + " " + Namem + " " + Namel;
            cout << "Enter Id: ";
            cin >> Id;
            Node1 *ptr1 = root;
            while (ptr1 != nullptr)
            {
                if (Id == ptr1->Id)
                {
                    cout << "ID already exist" << endl;
                    return;
                }
                else if (Id < ptr1->Id)
                {
                    ptr1 = ptr1->left;
                }
                else
                {
                    ptr1 = ptr1->right;
                }
            }
            do
            {
                cout << "For housekeeping, enter 'HK'\n-------------------\n"
                     << "For parking duties, enter 'PK'\n-------------------\n"
                     << "For watchman duties, enter 'WM'\n-------------------\n"
                     << "For gardening work, enter 'GR'\n-------------------\n"
                     << "For hall cleaning, enter 'HC'\n-------------------" << endl;
                cout << "Enter the area of work: ";
                cin >> aow;
                if (aow == "HK" || aow == "PK" || aow == "WM" || aow == "GR" || aow == "HC")
                {
                    break;
                }
                else
                {
                    cout << "Please enter a correct option" << endl;
                }

            } while (aow != "HK" && aow != "PK" && aow != "WM" && aow != "GR" && aow != "HC");
            present = "Not there";
            do
            {
                cout << "Enter phone number: ";
                cin >> telephoneNo1;
                if (telephoneNo1.length() == 10)
                {
                    Node1 *temp1 = new Node1(Id, Namew, aow, telephoneNo1, present);
                    if (root == nullptr)
                    {
                        root = temp1;
                    }
                    else
                    {
                        Node1 *ptr = root;
                        while (ptr != nullptr)
                        {
                            if (temp1->Id < ptr->Id)
                            {
                                if (ptr->left == nullptr)
                                {
                                    ptr->left = temp1;
                                    break;
                                }
                                else
                                {
                                    ptr = ptr->left;
                                }
                            }
                            else if (temp1->Id > ptr->Id)
                            {
                                if (ptr->right == nullptr)
                                {
                                    ptr->right = temp1;
                                    break;
                                }
                                else
                                {
                                    ptr = ptr->right;
                                }
                            }
                            else
                            {
                                cout << "Already marked as present!" << endl;

                                break;
                            }
                        }
                    }
                }
                else
                {
                    cout << "Please enter a valid 10-digit phone number." << endl;
                }
            } while (telephoneNo1.length() != 10);
            cout << "\nWould you like to add more information for Helpers?\nPress '1' to continue\nPress '0' to exit: ";

            cin >> ch;
            cout << endl;
        } while (ch != 0);
    }

public:
    void displayinfo1()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << setw(30) << "Name" << setw(25) << "ID" << setw(20) << "Area of work" << setw(20) << "Phone number" << setw(20) << "is there" << endl;
            displayinfo1(root);
        }
    }

private:
    void displayinfo1(Node1 *node1)
    {
        if (node1 != nullptr)
        {
            displayinfo1(node1->left);
            node1->display();
            displayinfo1(node1->right);
        }
    }

public:
    void mark()
    {
        if (root == nullptr)
        {
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
        else
        {
            cout << "Enter your ID to mark your presence at work: ";

            int Id1;
            cin >> Id1;
            Node1 *ptr = root;
            while (ptr != nullptr)
            {
                if (Id1 == ptr->Id)
                {
                    do
                    {
                        cout << "Mark your attendance ('present' or 'absent'): ";

                        cin >> ptr->present;
                        if (ptr->present == "present")
                        {
                            cout << "Information successfully saved!" << endl;

                            break;
                        }
                        else
                        {
                            cout << "Enter correct one" << endl;
                        }
                    } while (ptr->present != "present");
                    return;
                }
                else if (Id1 < ptr->Id)
                {
                    ptr = ptr->left;
                }
                else
                {
                    ptr = ptr->right;
                }
            }
            cout << "╔═══════════════════════════╗" << endl;
            cout << "║      No Records Found     ║" << endl;
            cout << "╚═══════════════════════════╝" << endl;
        }
    }

public:
    void delete1()
    {
        if (root == nullptr)
        {
            cout << "No records found at the moment." << endl;
        }
        else
        {
            cout << "Enter the Id of helper to delete: ";
            int Id1;
            cin >> Id1;
            root = delete1(root, Id1);
            cout << "Deleted succesfully" << endl;
        }
    }

private:
    Node1 *delete1(Node1 *root, int Id1)
    {
        if (root == nullptr)
            return root;
        if (Id1 < root->Id)
            root->left = delete1(root->left, Id1);
        else if (Id1 > root->Id)
            root->right = delete1(root->right, Id1);
        else
        {
            if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;
            Node1 *temp = getSuccessor(root->right);
            root->Id = temp->Id;
            root->Namew = temp->Namew;
            root->aow = temp->aow;
            root->telephoneNo1 = temp->telephoneNo1;
            root->present = temp->present;
            root->right = delete1(root->right, root->Id);
        }
        return root;
    }

private:
    Node1 *getSuccessor(Node1 *node1)
    {
        int Id = node1->Id;
        string Namew = node1->Namew;
        string aow = node1->aow;
        string telephoneNo1 = node1->telephoneNo1;
        string present = node1->present;
        while (node1->left != nullptr)
        {
            Id = node1->left->Id;
            Namew = node1->left->Namew;
            aow = node1->left->aow;
            telephoneNo1 = node1->left->telephoneNo1;
            present = node1->left->present;
            node1 = node1->left;
        }
        return new Node1(Id, Namew, aow, telephoneNo1, present);
    }
};
class Hall1
{
public:
    int hall_number;
    int price;
    std::string date;
    std::string Name, phonenumber;
    Hall1 *next;
    Hall1 *prev;

    Hall1(int price1, std::string datee, std::string name, std::string phoneno, int hall__number)
    {
        hall_number = hall__number;
        price = price1;
        date = datee;
        Name = name;
        phonenumber = phoneno;
        prev = next = nullptr;
    }
};

class BookHall1
{
private:
    Hall1 *head;
    Hall1 *temp;
    Hall1 *rear;

public:
    BookHall1()
    {
        head = nullptr;
        temp = nullptr;
        rear = nullptr;
    }
    bool isempty()
    {
        if (head == nullptr)
            return true;
        else
            return false;
    }
    void Book1()
    {
        Hall1 *h1 = new Hall1(0, "", "", "", 0);
        cout << "There are two available halls in our society:" << endl;
        cout << "Hall\tCapacity\tRent for One Day" << endl;
        cout << "1\t100\t\t$5000" << endl;
        cout << "2\t400\t\t$10000" << endl;
        cout << "You can only book a hall within the next 15 days." << endl;
        cout << "Please enter the Hall number you wish to book:" << endl;

        int Hallnumber;
        cin >> Hallnumber;
        switch (Hallnumber)
        {
        case 1:
        {
            cout << "Welcome! Let's book the hall for your special event." << endl;
            cout << "Please provide your name for the booking." << endl;
            cout << "Enter your first name: ";
            string Namef1;
            cin >> Namef1;
            cout << "Enter Middle Name: ";
            string Namem1;
            cin >> Namem1;
            cout << "Enter last Name: ";
            string Namel1;
            cin >> Namel1;
            string name1 = Namef1 + " " + Namem1 + " " + Namel1;
            string phoneno1;
            do
            {
                cout << "Enter phone your number: ";
                cin >> phoneno1;
                cin.ignore();
                if (phoneno1.length() == 10)
                {
                }
                else
                {
                    cout << "Please enter a valid 10-digit phone number." << endl;
                }
            } while (phoneno1.length() != 10);
            cout << "Enter the date in the format day/month/year (00/00/0000):" << endl;
            string date1;
            cin >> date1;
            temp = head;
            if (temp == nullptr)
            {
                h1 = new Hall1(5000, date1, name1, phoneno1, 1);
                cout << "Hall 1 has been successfully booked for " << date1 << "!" << endl;
                break;
            }
            else
            {
                while (temp != nullptr)
                {
                    if (date1 == temp->date)
                    {
                        cout << "Sorry, this date is already booked for Hall 1. Please choose another date." << endl;
                        temp = temp->next;
                        return;
                    }
                    else
                    {
                        h1 = new Hall1(5000, date1, name1, phoneno1, 1);
                        cout << "Hall 1 has been successfully booked for " << date1 << "!" << endl;
                        break;
                    }
                }
                break;
            }
        }

        case 2:
        {
            cout << "Welcome! Let's book the hall for your special event." << endl;
            cout << "Please provide your name for the booking." << endl;
            cout << "Enter your first name: ";
            string Namef2;
            cin >> Namef2;
            cout << "Enter your middle name: ";
            string Namem2;
            cin >> Namem2;
            cout << "Enter your last name: ";
            string Namel2;
            cin >> Namel2;
            string name2 = Namef2 + " " + Namem2 + " " + Namel2;

            string phoneno2;
            do
            {
                cout << "Enter your phone number: ";
                cin >> phoneno2;
                if (phoneno2.length() == 10)
                {
                    // Valid phone number length
                }
                else
                {
                    cout << "Please enter a valid 10-digit phone number." << endl;
                }
            } while (phoneno2.length() != 10);

            cout << "Enter the date in the format day/month/year (00/00/0000):" << endl;

            string date2;
            cin >> date2;
            temp = head;
            if (temp == nullptr)
            {
                h1 = new Hall1(10000, date2, name2, phoneno2, 2);
                cout << " Hall Successfully Booked! " << endl;
                break;
            }
            else
            {
                while (temp != nullptr)
                {
                    if (date2 == temp->date)
                    {
                        cout << "Oops! The hall is already booked for this date. Please choose another date." << endl;
                        temp = temp->next;
                        return;
                    }
                    else
                    {
                        h1 = new Hall1(10000, date2, name2, phoneno2, 2);
                        cout << " Hall Successfully Booked! " << endl;
                        break;
                    }
                }
                break;
            }
        }
        default:
            cout << "Oops! It looks like there was a hiccup in your selection." << endl;
        }
        if (h1->hall_number != 0)
        {
            if (isempty())
                head = h1;
            else
            {
                temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                h1->prev = temp;
                temp->next = h1;
            }
        }
    }
    void deleteBooking()
    {
        if (isempty())
            cout << "No bookings are scheduled at the moment. Enjoy a quiet day!" << endl;
        else
        {
            cout << " Current Bookings " << endl;
            cout << "Name: " << head->Name << endl;
            cout << "Contact Number: " << head->phonenumber << " | Hall Number: " << head->hall_number << endl;
            cout << "Booking Price: " << head->price << endl;
            cout << "Date: " << head->date << endl;
            if (head->next == nullptr)
                rear = head;
            head = head->next;
            cout << "Booking successfully removed. " << endl;
        }
    }
    void display()
    {
        if (isempty())
            cout << "No bookings are there" << endl;
        else
        {
            cout << "bookings are: " << endl;
            temp = head;
            cout << setw(30) << "Name" << setw(30) << "phone number" << setw(30) << "booked hall number" << setw(15) << "rent" << setw(20) << "date" << endl;
            while (temp != nullptr)
            {
                cout << setw(35) << temp->Name << setw(22) << temp->phonenumber << setw(23) << temp->hall_number << setw(25) << temp->price << setw(20) << temp->date << endl;
                cout << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    BinarySearchTree tree;
    BST b;
    BookHall1 bh1;
    int ch;
    cout << "***************** Welcome to Vishwakarma Society *****************" << endl;
    cout << "Total number of flats: 30" << endl;
    int ch1;
    do
    {
        cout << "--------------------------------------" << endl;
        cout << "| 1) Admin                           |" << endl;
        cout << "| 2) Society Member                  |" << endl;
        cout << "| 3) Other than society-related person|" << endl;
        cout << "| 4) Helpers                         |" << endl;
        cout << "| 0) Exit                            |" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Enter who you are: ";

        cin >> ch1;
        if (ch1 == 1)
        {
            string password;
            cout << "Enter password: ";
            cin >> password;
            if (password == "hope")
            {
                do
                {
                    cout << "*********************************************\n\t\t MENU \n*********************************************\n"
                         << "1.  Add a Society Member's record\n"
                         << "2.  Phone Directory of Society Member\n"
                         << "3.  Update Society Member Information\n"
                         << "4.  Display Society Member about Status\n"
                         << "5.  Display Society Member Information\n"
                         << "6.  Search Society Member Information\n"
                         << "7.  Delete Society Member Information\n"
                         << "8.  Maintenance\n"
                         << "9.  Booking\n"
                         << "10.  Display Maintenance Information\n"
                         << "11.  Add a Helper's record\n"
                         << "12.  Delete Helper's Information\n"
                         << "13.  Display Helper's Information\n"
                         << "0.  Exit.\n*********************************************" << endl;
                    cout << "Enter your choice: ";

                    cin >> ch;
                    cin.ignore();
                    if (ch == 0)
                    {
                        break;
                    }
                    switch (ch)
                    {
                    case 1:
                        tree.create();
                        break;
                    case 2:
                        cout << "Let's Explore Your Options:\n1. Display Information\n2. Search Records\n3. Sort by Phone Number\n4. Sort by Name\n0. Exit" << endl;
                        cout << "Enter your choice: ";

                        int n;
                        cin >> n;
                        do
                        {
                            if (n == 1)
                            {
                                cout << "----------------------------------------------------------------------------------------------------------------" << endl;
                                tree.displayphoneno();
                                cout << "-------------------------------------------------------------------------------------------------------------" << endl;
                                break;
                            }
                            else if (n == 2)
                            {
                                tree.search();
                                break;
                            }
                            else if (n == 3)
                            {
                                tree.sortBt(3);
                                tree.sort_phone(tree.root1);
                                break;
                            }
                            else if (n == 4)
                            {
                                tree.sortBt(4);
                                tree.sort_Name(tree.root2);
                                break;
                            }
                        } while (n != 0);
                        break;
                    case 3:
                        tree.update();
                        break;
                    case 4:
                        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
                        tree.displaystatus();
                        cout << "---------------------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    case 5:
                        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        tree.displayinfo();
                        cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    case 6:
                        tree.search();
                        break;
                    case 7:
                        tree.deleteNode();
                        break;
                    case 8:
                        tree.maintenance();
                        break;
                    case 9:
                        int ch8;
                        cout << "What would you like to do?\n1. Book a Hall\n2. Display Booked Dates\n3. Delete a Booking\n0. Exit" << endl;
                        cout << "Enter your choice: ";

                        cin >> ch8;
                        if (ch8 == 1)
                        {
                            bh1.Book1();
                        }
                        else if (ch8 == 2)
                        {
                            cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
                            bh1.display();
                            cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                        else if (ch8 == 3)
                        {
                            bh1.deleteBooking();
                        }
                        else if (ch8 == 0)
                        {
                            cout << "For further information, please contact the administrator at\nPhone Number: 987*******" << endl;
                        }
                        else
                        {
                            cout << "Invalid choice.." << endl;
                        }
                        break;
                    case 10:
                        cout << "--------------------------------------------------------------------------------------" << endl;
                        tree.displaymaint();
                        cout << "--------------------------------------------------------------------------------------" << endl;
                        break;
                    case 11:
                        b.create1();
                        break;
                    case 12:
                        b.delete1();
                        break;
                    case 13:
                        cout << "--------------------------------------------------------------------------------------------------------------" << endl;
                        b.displayinfo1();
                        cout << "---------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    default:
                        cout << "Invalid Option" << endl;
                        break;
                    }
                } while (ch != 0);
            }
            else
            {
                cout << "Wrong password!!" << endl;
                cout << "-------------------" << endl;
            }
        }
        else if (ch1 == 2)
        {
            string password;
            cout << "Enter password: ";
            cin >> password;
            if (password == "vishwakarma@123")
            {
                do
                {
                    cout << "\t\t Welcome to Vishwakarma Society Management System \n";
                    cout << "*****************************************************\n";
                    cout << "1. Fetch Phone Numbers\n";
                    cout << "2.  Explore About Status\n";
                    cout << "3.  Get Information Insights\n";
                    cout << "4.  Seek Information\n";
                    cout << "5.  Schedule Bookings\n";
                    cout << "6.  Manage Maintenance\n";
                    cout << "7.  View Maintenance Overview\n";
                    cout << "8.  Discover Helpers' Information\n";
                    cout << "0.  Exit\n";
                    cout << "*****************************************************\n";
                    cout << "Enter your choice: ";

                    cin >> ch;
                    cin.ignore();
                    if (ch == 0)
                    {
                        break;
                    }
                    switch (ch)
                    {
                    case 1:
                        cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        tree.displayphoneno();
                        cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    case 2:
                        cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        tree.displaystatus();
                        cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    case 3:
                        cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        tree.displayinfo();
                        cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    case 4:
                        tree.search();
                        break;
                    case 5:
                        int ch2;
                        cout << "Options:\n1. Book the Hall\n2. Display Booked Dates\n0. Exit" << endl;
                        cout << "Enter your choice: ";

                        cin >> ch2;
                        if (ch2 == 1)
                        {
                            bh1.Book1();
                        }
                        else if (ch2 == 2)
                        {
                            cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
                            bh1.display();
                            cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                        else if (ch2 == 0)
                        {
                            cout << "For further information, please contact the administrator at\nPhone Number: 987*******" << endl;
                        }
                        else
                        {
                            cout << "Invalid choice.." << endl;
                        }
                        break;
                    case 6:
                        tree.maintenance();
                        break;
                    case 7:
                        cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        tree.displaymaint();
                        cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    case 8:
                        cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        b.displayinfo1();
                        cout << "----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        break;
                    default:
                        cout << "Invalid Option" << endl;
                        break;
                    }
                } while (ch != 0);
            }
            else
            {
                cout << "Wrong password!!" << endl;
            }
        }
        else if (ch1 == 3)
        {
            int ch2;
            cout << "Options:\n1. Book the Hall\n2. Display Booked Dates\n0. Exit" << endl;
            cout << "Enter your choice: ";

            cin >> ch2;
            if (ch2 == 1)
            {
                bh1.Book1();
            }
            else if (ch2 == 2)
            {
                cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
                bh1.display();
                cout << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else if (ch2 == 0)
            {
                cout << "For further information, please contact the administrator at\nPhone Number: 987*******" << endl;
            }
            else
            {
                cout << "Invalid choice.." << endl;
            }
        }
        else if (ch1 == 4)
        {
            string password1;
            cout << "Enter password: ";
            cin >> password1;
            if (password1 == "hope")
            {
                int ch10;
                cout << "Would you like to mark yourself as present?\nPress 1 for Yes\nPress 0 for No" << endl;
                cout << "Enter your choice: ";

                cin >> ch10;
                if (ch10 == 1)
                {
                    b.mark();
                }
                else if (ch10 == 0)
                {
                    cout << "For further information, please contact the administrator at\nPhone Number: 987*******" << endl;
                }
                else
                {
                    cout << "Invalid choice.." << endl;
                }
            }
            else
            {
                cout << "Wrong password!!" << endl;
                cout << "-------------------" << endl;
            }
        }
        else if (ch1 == 0)
        {
            cout << "Thank you for being a part of the Vishwakarma Society experience." << endl;
            cout << "Have a wonderful day!" << endl;

            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    } while (ch1 != 0);
    return 0;
}
