#include <iostream>
using namespace std;

template<typename T>
class Priority_Queue
{

    T* pq;
    int pq_size = 0;
    int* pr;
    int pr_size = 0;

    int min_pr = 0;
    int max_pr = 0;

    void sort()
    {
        for (int i = 1; i < this->pr_size; i++)
        {
            for (int j = 0; j < this->pr_size - i; j++)
            {
                if (this->pr[j] > this->pr[j + 1])
                {
                    int temp_pr = this->pr[j + 1];
                    this->pr[j + 1] = this->pr[j];
                    this->pr[j] = temp_pr;

                    T temp_pq = this->pq[j + 1];
                    this->pq[j + 1] = this->pq[j];
                    this->pq[j] = temp_pq;
                }
            }
        }
    }

public:

    bool empty()
    {
        return !this->pq_size;
    }

    int size()
    {
        return this->pq_size;
    }

    void push(T element, int priority)
    {
        T* temp_pq = new T[this->pq_size + 1];

        for (int i = 0; i < this->pq_size; i++) temp_pq[i] = this->pq[i];

        temp_pq[this->pq_size] = element;

        delete this->pq;

        this->pq_size++;

        this->pq = new T[this->pq_size];

        for (int i = 0; i < this->pq_size; i++) this->pq[i] = temp_pq[i];



        int* temp_pr = new int[this->pr_size + 1];

        for (int i = 0; i < this->pr_size; i++) temp_pr[i] = this->pr[i];

        temp_pr[this->pr_size] = priority;

        delete this->pr;

        this->pr_size++;

        this->pr = new int[this->pr_size];

        for (int i = 0; i < this->pr_size; i++) this->pr[i] = temp_pr[i];


        this->max_pr = this->pr[this->pr_size - 1];
        this->min_pr = this->pr[0];


        delete temp_pq;
        delete temp_pr;

        sort();
    }

    void pop_front()
    {
        T* temp_pq = new T[this->pq_size - 1];

        for (int i = 0; i < this->pq_size - 1; i++) temp_pq[i] = this->pq[i];

        delete this->pq;

        this->pq_size--;

        this->pq = new T[this->pq_size];

        for (int i = 0; i < this->pq_size; i++) this->pq[i] = temp_pq[i];



        int* temp_pr = new int[this->pr_size - 1];

        for (int i = 0; i < this->pr_size - 1; i++) temp_pr[i] = this->pr[i];

        delete this->pr;

        this->pr_size--;

        this->pr = new int[this->pr_size];

        for (int i = 0; i < this->pr_size; i++) this->pr[i] = temp_pr[i];


        this->max_pr = this->pr[this->pr_size - 1];
        this->min_pr = this->pr[0];


        delete temp_pq;
        delete temp_pr;
    }

    void pop_back()
    {
        T* temp_pq = new T[this->pq_size - 1];

        for (int i = 1; i < this->pq_size; i++) temp_pq[i - 1] = this->pq[i];

        delete this->pq;

        this->pq_size--;

        this->pq = new T[this->pq_size];

        for (int i = 0; i < this->pq_size; i++) this->pq[i] = temp_pq[i];



        int* temp_pr = new int[this->pr_size - 1];

        for (int i = 1; i < this->pr_size; i++) temp_pr[i - 1] = this->pr[i];

        delete this->pr;

        this->pr_size--;

        this->pr = new int[this->pr_size];

        for (int i = 0; i < this->pr_size; i++) this->pr[i] = temp_pr[i];


        this->max_pr = this->pr[this->pr_size - 1];
        this->min_pr = this->pr[0];


        delete temp_pq;
        delete temp_pr;
    }

    T front()
    {
        return this->pq[this->pq_size - 1];
    }

    T back()
    {
        return this->pq[0];
    }

    void swap(Priority_Queue pq1)
    {
        Priority_Queue temp_pq = pq1;
        pq1 = this->pq;
        this->pq = temp_pq;
    }

    void emplace_front(T element)
    {
        max_pr++;
        push(element, max_pr);
    }

    void emplace_back(T element)
    {
        min_pr--;
        push(element, min_pr);
    }

    ~Priority_Queue()
    {
        delete this->pq;
        delete this->pr;
    }

};

int main()
{
    Priority_Queue<int> pq;

    cout << "0) exit; 1) empty; 2) size; 3) push; 4) pop_front; 5) pop_back; 6) front; 7) back; 8) swap; 9) emplace_front; 10) emplace_back" << endl;

    while (true)
    {
        int temp;

        cout << "intput: ";
        cin >> temp;

        if (temp == 0) break;
        else if (temp == 1) cout << "output: " << pq.empty() << endl;
        else if (temp == 2) cout << "output: " << pq.size() << endl;
        else if (temp == 3)
        {
            int element, priority;

            cout << "element: ";
            cin >> element;

            cout << "priority: ";
            cin >> priority;

            pq.push(element, priority);
        }
        else if (temp == 4) pq.pop_front();
        else if (temp == 5) pq.pop_back();
        else if (temp == 6) cout << "output: " << pq.front() << endl;
        else if (temp == 7) cout << "output: " << pq.back() << endl;
        else if (temp == 8) cout << "output: you dont have another priority queue to swap!" << endl;
        else if (temp == 9)
        {
            int element;

            cout << "element: ";
            cin >> element;

            pq.emplace_front(element);
        }
        else if (temp == 10)
        {
            int element;

            cout << "element: ";
            cin >> element;

            pq.emplace_back(element);
        }
    }
}