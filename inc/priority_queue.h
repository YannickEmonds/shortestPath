#pragma once

#include <vector>
#include <unordered_map>
#include <cstddef>
#include <algorithm>
#include <exception>


template <class T, class U>
class PriorityQueue
{
private:
    std::unordered_map<T, std::size_t> addressMap;
    std::vector<T> addressArray;
    std::vector<U> heap;
    std::size_t size;

    void siftUp(const std::size_t pos);
    void siftDown(const std::size_t pos);
public:
    PriorityQueue();
    PriorityQueue(const std::vector<T> handles, 
                  const std::vector<U> elements);
    ~PriorityQueue();

    void insert(const T newItem, const U key);
    U min() const;
    U deleteMin();
    void decreaseKey(const T element, const U newKey);
    bool isEmpty() const;
    bool contains(const T element) const;
    std::size_t PQsize() const;
};

template <class T, class U>
PriorityQueue<T, U>::PriorityQueue()
{
    size = 0;
}

template <class T, class U>
PriorityQueue<T, U>::PriorityQueue(const std::vector<T> handles, 
                                   const std::vector<U> elements)
{
    if (handles.size() != elements.size())
    {
        throw std::runtime_error("Sizes do not coincide. Abort.");
    }
    heap = elements;
    addressArray = handles;
    size = addressArray.size();
    for (std::size_t i=0; i<size; ++i)
    {
        addressMap[addressArray[i]] = i;
    }

    for (std::size_t i=size/2; i>=0; --i)
    {
        siftDown(i);
    }
}

template <class T, class U>
PriorityQueue<T, U>::~PriorityQueue()
{
}

template <class T, class U>
void PriorityQueue<T, U>::siftUp(const std::size_t pos)
{
    const std::size_t parent_pos = (pos-1)/2;
    // compare to parent elements
    if (pos == 0 or heap[parent_pos] <= heap[pos])
    {
        return;
    }

    std::iter_swap(heap.begin() + parent_pos, heap.begin() + pos);
    std::iter_swap(addressArray.begin() + parent_pos, addressArray.begin() + pos);
    addressMap[addressArray[parent_pos]] = parent_pos;
    addressMap[addressArray[pos]] = pos;

    siftUp(parent_pos);
}

template <class T, class U>
void PriorityQueue<T, U>::siftDown(const std::size_t pos)
{
    const std::size_t leftChildIndex = 2*pos + 1;
    const std::size_t rightChildIndex = leftChildIndex + 1;
    if (leftChildIndex > size-1)    // has no children
    {
        return;
    }

    std::size_t idx = rightChildIndex;
    if (rightChildIndex > size-1 or heap[leftChildIndex] < heap[rightChildIndex])
    {
        idx = leftChildIndex;
    }

    if (heap[pos] > heap[idx])
    {
        std::iter_swap(heap.begin() + pos, heap.begin() + idx);
        std::iter_swap(addressArray.begin() + pos, addressArray.begin() + idx);
        addressMap[addressArray[pos]] = pos;
        addressMap[addressArray[idx]] = idx;
        siftDown(idx);
    }
}

template <class T, class U>
void PriorityQueue<T, U>::insert(const T newItem, const U key)
{
    heap.push_back(key);
    addressArray.push_back(newItem);
    addressMap[newItem] = size;
    size++;
    siftUp(size-1);
}

template <class T, class U>
U PriorityQueue<T, U>::min() const
{
    return heap.front();
}

template <class T, class U>
U PriorityQueue<T, U>::deleteMin()
{
    const U result = heap.front();
    heap[0] = heap.back();
    addressArray[0] = addressArray.back();
    addressMap[addressArray[0]] = 0;
    size--;
    siftDown(0);
    return result;
}

template <class T, class U>
void PriorityQueue<T, U>::decreaseKey(const T element, const U newKey)
{
    heap[addressMap[element]] = newKey;
    siftUp(addressMap[element]);
}

template <class T, class U>
bool PriorityQueue<T, U>::isEmpty() const
{
    return heap.empty();
}

template <class T, class U>
bool PriorityQueue<T, U>::contains(const T handle) const
{
    return addressMap.contains(handle);
}

template <class T, class U>
std::size_t PriorityQueue<T, U>::PQsize() const
{
    return size;
}
