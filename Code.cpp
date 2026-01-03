#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class TaskManager;
class Task
{

    private :
    string name;
    int priority;
    string deadlineDate;
    string deadlineTime;

    Task *next;
    friend class TaskManager;
    public:
    // Task(string n, int p, string dDate, string dTime)
    // {
    //     name = n;
    //     priority = p;
    //     deadlineDate = dDate;
    //     deadlineTime = dTime;
    // }for more efficiency . I used chatgpt to know it
    Task(string n, int p, string dDate, string dTime) 
        : name(n), priority(p), deadlineDate(dDate), deadlineTime(dTime), next(nullptr) {}
};
class TaskManager 
{
    private:
        Task* head;
    
        void printLine(int width = 60) const 
        {
            cout << string(width, '-') << "\n";
        }
    
    public:
        TaskManager()
        {
            head=nullptr;
        }

        ~TaskManager() 
        {
            Task *temp = head;
            while (temp != nullptr) 
            {
                Task *nextT = temp->next;
                delete temp;
                temp = nextT;
            }
        }

        void addTask(const string& name, int priority, const string& deadlineDate, const string& deadlineTime);
        void deleteTask (const string & name);
        void editTask(const string & name);
        void viewTasks() const;                 //constant function is used for not to modify the data.
        void viewTasksSortedByDeadline() const; //simlly.
};

void  TaskManager :: addTask(const string& name, int priority, const string& deadlineDate, const string& deadlineTime)
{
        Task* n = new Task(name, priority, deadlineDate, deadlineTime);
        if (!head || priority < head->priority) 
        {
            n->next = head;
            head = n;
        } 
        else 
        {
            Task* temp = head;
            while (temp->next && temp->next->priority <= priority) {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }

        cout << "\n✅ Task \"" << name << "\" added successfully!\n";
}

void TaskManager :: deleteTask (const string & name)
{
    if (head == nullptr)
    {
        cout << "\n⚠️  No tasks to delete.\n";
        return ;
    }

    if (head-> name == name)
    {
        Task * temp = head;
        head = head -> next;
        delete temp;
        cout << "\n🗑️ Task \"" << name << "\"  deleted successfully! \n";
        return;
    }

    Task * prev = head;
    while (prev -> next && prev -> next -> name != name) 
    {
        prev = prev -> next;
    }

    if (prev -> next == nullptr) 
    {
        cout << "\n❌  Task  \""<< name << "\" not found. \n";
    }
    else 
    {
        Task * temp = prev -> next ;
        prev -> next = temp -> next;
        delete temp;
        cout << "\n🗑️  Task  \"" << name << "\" deleted successfully! \n";
    }
}

void TaskManager :: editTask(const string& name)
{
    Task * temp1=head;
    while(temp1 && temp1->name!=name)//for finding the Task to edit
    {
        temp1=temp1->next;
    }
    if(temp1==nullptr)
    {
        cout<<"\n ❌ Task \""<< name <<" not found.\n";
        return;
    }
    cout<<"\n Editing Task name :"<< name <<"\n";
    string newName,newDD,newDT;
    int newP;
    cout << "Enter new name (or press Enter to keep same): ";
    getline(cin, newName);
    if (!newName.empty()) temp1->name = newName;
    cout << "Enter new priority (or -1 to keep same): ";
    cin >> newP;
    cin.ignore();
    if (newP != -1) 
    {
        temp1->priority = newP;
    }
    cout << "Enter new deadline date (or press Enter to keep same): ";
    getline(cin, newDD);
    if (!newDD.empty()) 
    {
        temp1->deadlineDate = newDD;
    }
    cout << "Enter new deadline time (or press Enter to keep same): ";
    getline(cin, newDT);
    if (!newDT.empty()) 
    {
        temp1->deadlineTime = newDT;
    }
    cout << "\n✏️ Task updated. Reordering list...\n";
    // Reordering the Tasks.
    Task* temp2 = head;
    head = nullptr;
    while (temp2) 
    {
        Task* next = temp2->next;
        addTask(temp2->name, temp2->priority, temp2->deadlineDate, temp2->deadlineTime);
        delete temp2;
        temp2 = next;
    }
}

void  TaskManager :: viewTasks() const
{
        if (!head) {
            cout << "\n📭 No tasks available.\n";
            return;
        }

        cout << "\n📝 Your Daily Tasks (sorted by priority):\n";
        printLine();
        cout << left << setw(25) << "Task Name"
             << setw(10) << "Priority"
             << setw(15) << "Deadline Date"
             << setw(10) << "Deadline Time" << "\n";
        printLine();

        Task* temp = head;
        while (temp) {
            cout << left << setw(25) << temp->name << setw(10) << temp->priority<< setw(15) << temp->deadlineDate << setw(10) << temp->deadlineTime << "\n";
            temp = temp->next;
        }
        printLine();

}

void TaskManager:: viewTasksSortedByDeadline() const 
{
    if (!head) 
    {
        cout << "\n📭 No tasks available.\n";
        return;
    }

    vector<Task*> taskList;
    Task* current = head;
    while (current) 
    {
        taskList.push_back(current);
        current = current->next;
    }

    sort(taskList.begin(), taskList.end(), [](Task* a, Task* b) 
    {
        if (a->deadlineDate == b->deadlineDate)
            return a->deadlineTime < b->deadlineTime;
        return a->deadlineDate < b->deadlineDate;
    });

    cout << "\n📅 Your Tasks (sorted by deadline):\n";
    printLine();
    cout << left << setw(25) << "Task Name"
         << setw(10) << "Priority"
         << setw(15) << "Deadline Date"
         << setw(10) << "Deadline Time" << "\n";
    printLine();

    for (Task* task : taskList) 
    {
        cout << left << setw(25) << task->name
             << setw(10) << task->priority
             << setw(15) << task->deadlineDate
             << setw(10) << task->deadlineTime << "\n";
    }

    printLine();
}
int main ()
{
    TaskManager tm;
    int choice;
    string name, deadlineDate, deadlineTime;
    int priority;

    do {
        cout << "\n📋 ==== Daily Task Manager ====\n";
        cout << "1️⃣  Add Task\n";
        cout << "2️⃣  Delete Task\n";
        cout << "3️⃣  Edit Task\n";
        cout << "4️⃣  View All Tasks by Priority\n";
        cout << "5️⃣  View All Tasks by Deadline\n";
        cout << "6️⃣  Exit\n";
        cout << "👉 Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
            case 1:
                cout << "\nEnter task name: ";
                getline(cin, name);
                cout << "Enter priority (1 = highest): ";
                cin >> priority;
                cin.ignore();
                cout << "Enter deadline date (YYYY-MM-DD): ";
                getline(cin, deadlineDate);
                cout << "Enter deadline time (HH:MM): ";
                getline(cin, deadlineTime);
                tm.addTask(name, priority, deadlineDate, deadlineTime);
                break;

            case 2:
                cout << "\nEnter task name to delete: ";
                getline(cin, name);
                tm.deleteTask(name);
                break;

            case 3:
                cout << "\nEnter task name to edit: ";
                getline(cin, name);
                tm.editTask(name);
                break;

            case 4:
                tm.viewTasks();
                break;

            case 5:
                tm.viewTasksSortedByDeadline();
                break;

            case 6:
                cout << "\n👋 Exiting Task Manager. Stay productive!\n";
                break;

            default:
                cout << "\n❗ Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}