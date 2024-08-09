#include <bits/stdc++.h>
using namespace std;
class Heap
{
private:
    int size;
    int capacity;
    int *arr;

public:
    Heap(int c)
    {
        size = 0;
        capacity = c;
        arr = new int[c];
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int getSize()
    {
        return size;
    }
    int parent(int i)
    {
        return ((i - 1) / 2);
    }
    int lChild(int i)
    {
        return 2 * i + 1;
    }
    int rChild(int i)
    {
        return 2 * i + 2;
    }
    int getMax()
    {
        return arr[0];
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "OVERFLOW";
            return;
        }
        int index = size;
        size++;
        arr[index] = val;
        while (index > 0)
        {
            if (arr[index] > arr[parent(index)])
            {
                swap(arr[index], arr[parent(index)]);
            }
            index = parent(index);
        }
    }
    void _delete()
    {
        arr[0] = arr[size - 1];
        size--;
        int index = 0;
        while (index < size)
        {
            if (lChild(index) >= size && rChild(index) >= size)
            {
                break;
            }
            if (lChild(index) < size && rChild(index) >= size)
            {
                if (arr[index] < arr[lChild(index)])
                {
                    swap(arr[index], arr[lChild(index)]);
                }
                break;
            }
            if (arr[index] < max(arr[lChild(index)], arr[rChild(index)]))
            {
                int larger;
                if (arr[lChild(index)] > arr[rChild(index)])
                {
                    larger = lChild(index);
                }
                else
                {
                    larger = rChild(index);
                }
                swap(arr[index], arr[larger]);
                index = larger;
            }
            else
            {
                break;
            }
        }
    }
    void _delete(int pos)
    {
        size--;
        arr[pos] = arr[size];
        int index = pos;
        while (index < size)
        {
            if (lChild(index) >= size && rChild(index) >= size)
            {
                break;
            }
            if (lChild(index) < size && rChild(index) >= size)
            {
                if (arr[index] < arr[lChild(index)])
                {
                    swap(arr[index], arr[lChild(index)]);
                }
                break;
            }
            if (arr[index] < max(arr[lChild(index)], arr[rChild(index)]))
            {
                int larger;
                if (arr[lChild(index)] > arr[rChild(index)])
                {
                    larger = lChild(index);
                }
                else
                {
                    larger = rChild(index);
                }
                swap(arr[index], arr[larger]);
                index = larger;
            }
            else
            {
                break;
            }
        }
    }
    void changeKey(int pos, int newVal)
    {
        arr[pos] = newVal;
        int index = pos;
        while (index < size)
        {
            if (lChild(index) >= size && rChild(index) >= size)
            {
                break;
            }
            if (lChild(index) < size && rChild(index) >= size)
            {
                if (arr[index] < arr[lChild(index)])
                {
                    swap(arr[index], arr[lChild(index)]);
                }
                break;
            }
            if (arr[index] < max(arr[lChild(index)], arr[rChild(index)]))
            {
                int larger;
                if (arr[lChild(index)] > arr[rChild(index)])
                {
                    larger = lChild(index);
                }
                else
                {
                    larger = rChild(index);
                }
                swap(arr[index], arr[larger]);
                index = larger;
            }
            else
            {
                break;
            }
        }
    }
    int extractMax()
    {
        int val = arr[0];
        size--;
        arr[0] = arr[size];
        heapify(0);
        return val;
    }
    void heapify(int pos)
    {
        int larger = pos;
        if (lChild(pos) < size && arr[pos] < arr[lChild(pos)])
        {
            larger = lChild(pos);
        }
        if (rChild(pos) < size && arr[larger] < arr[rChild(pos)])
        {
            larger = rChild(pos);
        }
        if (larger != pos)
        {
            swap(arr[pos], arr[larger]);
            heapify(larger);
        }
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    Heap h(10);
    h.insert(1);
    h.insert(5);
    h.insert(6);
    h.insert(70);
    h.insert(10);
    h.insert(9);
    h.insert(21);
    // h._delete();
    // cout << "max is -> " << h.extractMax() << endl;
    // h._delete(2);
    // h.changeKey(0, 1);
    h.print();

    // cout << endl;
    // cout << h.getSize();

    return 0;
}
