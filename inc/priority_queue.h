#include <vector>


template <class T, class U>
class PriorityQueue
{
private:
    std::vector<T> proxyArray;
    std::vector<U> heap;

    void siftUp();
    void siftDown();
public:
    PriorityQueue(/* args */);
    ~PriorityQueue();

    void insert(const T newItem, const U key);
    T min() const;
    T deleteMin();
    void decreaseKey(const T element, const U newKey);
    bool isEmpty() const;
    bool contains(const T element) const;
};

template <class T, class U>
PriorityQueue<T, U>::PriorityQueue(/* args */)
{
}

template <class T, class U>
PriorityQueue<T, U>::~PriorityQueue()
{
}

template <class T, class U>
void PriorityQueue<T, U>::siftUp()
{

}

template <class T, class U>
void PriorityQueue<T, U>::siftDown()
{
    
}

template <class T, class U>
void PriorityQueue<T, U>::insert(const T newItem, const U key)
{

}

template <class T, class U>
U PriorityQueue<T, U>::min()
{
    
}

template <class T, class U>
U PriorityQueue<T, U>::deleteMin()
{
    
}

template <class T, class U>
void PriorityQueue<T, U>::decreaseKey()
{
    
}

template <class T, class U>
bool PriorityQueue<T, U>::isEmpty() const
{
    return heap.empty();
}
