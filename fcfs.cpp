#include <iostream>
using namespace std;

int main()
{
    int size = 3;
    int Arrival[size];
    int Burst[size];
    int index[size];
    int NBurst[size];
    for (int i = 0; i < size; i++) 
    {
        cout << "Enter Arrival time: ";
        cin >> Arrival[i];
        cout<< "Enter Burst time: ";
        cin >> Burst[i];
    }

    cout << "Arrival Time: ";
    for (int i = 0; i < size; i++) 
    {
        cout << Arrival[i] << " ";
    }

    cout<<endl;
    cout << "Burst Time: ";
    for(int i=0; i < size ; i++)
    {
        cout << Burst[i] << " ";
    }
    cout<<endl;
    int k;
    for(int step=0; step<size-1; step++)
    {
        for(int i=0; i<size-step-1; i++)
        {
            if(Arrival[i] > Arrival[i+1])
            {
                k=0;
                int temp = Arrival[i];
                Arrival[i]=Arrival[i+1];
                Arrival[i+1] = temp;
            }
            if(k=0) index[step]= i+1;
            else index[step]=i;
        }
    }

    cout << "Sorted Arrival Time: ";
    for (int i = 0; i < size; i++) 
    {
        cout << Arrival[i] << " ";
    }
    cout<<endl;

    cout << " Sorted Index num ";
    for (int i = 0; i < size; i++) 
    {
        cout << index[i] << " "; 
    }
    cout<<endl;

    return 0;
}