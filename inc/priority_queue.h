template <class T, class U>
class PriorityQueue
{
private:
    /* data */
public:
    PriorityQueue(/* args */);
    ~PriorityQueue();

    void insert(const T newItem, const U key);
    T deleteMin();
    void decreaseKey(T element, const U newKey);
    bool isEmpty() const;
};


