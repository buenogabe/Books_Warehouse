#ifndef NODE
#define NODE
#include <cstddef>

template <class T>
class Node {
     public:
	Node();
	Node(T, Node*);
	~Node();
	T getData() const;
	void setData(T);
	Node* getNext() const;
	void setNext(Node*);
     private:
	T data_;
	Node* next_;
};
#endif

template<class T>
Node<T>::Node() : next_(NULL) {}

template <class T>
Node<T>::Node(T data, Node* next) : data_(data), next_(next) {}

template <class T>
Node<T>::~Node() {
     this->next_ = NULL;
}

template <class T>
T Node<T>::getData() const {
     return this->data_;
}

template <class T>
void Node<T>::setData(T data) {
     this->data_ = data;
}

template <class T>
Node<T>* Node<T>::getNext() const {
     return this->next_;
}

template <class T>
void Node<T>::setNext(Node* next) {
     this->next_ = next;
}
