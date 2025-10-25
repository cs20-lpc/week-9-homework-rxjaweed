template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr), length(0){


}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) : head(nullptr), last(nullptr), length(0) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    /*if (isEmpty())
    {
        throw string ("The Queue is empty");
    }*/
    //else 
    //{
        return last->value;
    //}
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (!isEmpty())
    {
        dequeue();
    }
    
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    clear();
    Node* current = copyObj.head;
    while (current != nullptr)
    {
        enqueue(current->value);
        current = current->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    /*if (isEmpty())
    {
        throw string ("This Queue is empty");
    }*/
  
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;

        if (head == nullptr)
        {
            last = nullptr;
        }
    
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* newNode = new Node(elem);
    if (isEmpty())
    {
        head = newNode;
        last = newNode;
    }
    else 
    {
        last->next = newNode;
        last = newNode;
    }
    length++;
}

template <typename T>
T LinkedQueue<T>::front() const {
    /*if (isEmpty())
    {
        throw string ("The Queue is empty");
    }*/
    
        return head->value;

}

template <typename T> //I added this for driver program to display full list
void LinkedQueue<T>::display() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " " << endl;
        current = current->next;
    }
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
