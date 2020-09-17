#ifndef LINKEDLIST
#define LINKEDLIST

#include "Node.h"

template <class T>
class LinkedList {
     public:
	LinkedList();
	~LinkedList();
     T data() const;
     void insert(T);
     long length() const;
     int advance();
     void resetIterator();
     
     private:
	Node<T>* head_;
	Node<T>* tail_;
	Node<T>* iterator_;
	long length_;
};

template <class T>
LinkedList<T>::LinkedList() {
     head_ = NULL;
     iterator_ = NULL;
     tail_ = NULL;
     length_ = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
     Node<T>* temp;
     while(head_) {
	temp = head_;
	head_ = head_->getNext();
	delete temp;
     }
     head_ = NULL;
     iterator_ = NULL;
     tail_ = NULL;
     length_ = 0;
}

template <class T>
T LinkedList<T>::data() const {
     return iterator_->getData();
}

template <class T>
void LinkedList<T>::insert(T data) {
Node<T>* temp = new Node<T>(data, NULL);
     if(head_ == NULL) {
	head_ = temp;
	tail_ = temp;
	iterator_ = head_;
	length_++;
     }
     else {
	tail_->setNext(temp);
	tail_ = temp;
	length_++;
     }
}

template <class T>
long LinkedList<T>::length() const {
     return length_;
}

template <class T>
int LinkedList<T>::advance() {
     if(iterator_ == NULL)
	return -1;
     else {
	iterator_ = iterator_->getNext();
	return 0;
	}
}

template <class T>
void LinkedList<T>::resetIterator() {
     iterator_ = head_;
}

#endif
