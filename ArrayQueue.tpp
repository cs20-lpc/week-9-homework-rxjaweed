template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    maxSize = i;
    frontIndex = 0;
    backIndex = -1;
    length = 0;
    buffer = new T[maxSize];
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    /*if (isEmpty())
    {
        throw string ("The array is empty");
    }*/
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    /*if (isEmpty())
    {
        throw string ("The array is empty");
    }*/

    backIndex = -1;
    frontIndex = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;

    buffer = new T[maxSize];

    for (int i = frontIndex; i <= backIndex; i++)
    {
       buffer[i] = copyObj.buffer[i];
       cout << copyObj.buffer[i] << endl;
    }
    
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    /*if (isEmpty())
    {
        throw string ("Can't dequeue from an empty array, the array is empty");
    }*/

    T value = buffer[frontIndex]; //this saves value of front element
    frontIndex++;
    this->length--;
    //cout << value << endl;

}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    /*if (this->length == maxSize)
    {
        throw string ("Array is too full, cannot enqueue anymore valus");
    }*/
    backIndex++; 
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    /*if (isEmpty())
    {
        throw string ("Array is empty, there are no values");
    }*/

    return buffer[frontIndex];
}

//I added this function to display elements:
template <typename T> 
void ArrayQueue<T>::display() {
    /*if (isEmpty())
    {
        throw string ("Array is empty, cannot display elements");
    }*/
    for (int i = frontIndex; i <= backIndex; i++)
    {
        cout << buffer[i] << endl;
    }
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
