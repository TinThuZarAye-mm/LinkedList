//	LinkedBag340.cpp
//	Created by: CSC340

/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/


#include<cstddef>
#include<cstdlib>
#include"LinkedBag.h"


//RemoveSecondNode340
template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    Node<ItemType>* removeNode = headPtr;
    return remove(removeNode->getItem());
}

//addEnd340
template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType & addNode) {
    Node<ItemType>* newNode = new Node<ItemType>();

    newNode->setItem(addNode);
    Node<ItemType>* temp = headPtr;

    while (temp->getNext() != NULL){
        temp = temp->getNext();
    }

    temp->setNext(newNode);
    itemCount++;
    return true;
}

//getCurrentSize340Iterative
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    Node<ItemType> *temp = headPtr;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->getNext();
    }
    return count;
}

//getCurrentSize340Recursive
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    Node<ItemType>* temp = headPtr;
    if(temp == NULL){
        temp = headPtr;
        return 0;
    } else{
        temp = temp->getNext();
        return (getCurrentSize340RecursiveHelper(temp));
    }
}// getCurrentSize340Recursive with helper

//getCurrentSize340RecursiveHelper
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType> *temp) const {
    int count = 0;
    if (temp == NULL) {
        temp = headPtr;
        return 0;
    } else {
        count++;
        return count + getCurrentSize340RecursiveHelper(temp->getNext());
    }
}

//getCurrentSize340RecursiveNoHelper
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    int count = 0;
    static Node<ItemType> *temp = headPtr;
    if (temp == NULL) {
        temp = headPtr;
        return 0;
    } else {
        temp = temp->getNext();
        count++;
        return (count + getCurrentSize340RecursiveNoHelper());
    }
}

//getFrequencyOf340Recursive
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType & entry) const {
    static Node<ItemType> *temp = headPtr;
    if (temp == NULL) {
        temp = headPtr;
        return 0;
    } else {
        return (getFrequencyOf340RecursiveHelper(temp, entry));
    }
}

//getFrequencyOf340RecursiveHelper
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType> *temp, const ItemType & entry) const {
    int count = 0;
    if (temp == NULL) {
        temp = headPtr;
        return 0;
    } else if (temp->getItem() == entry) {
        count++;
        return (count + getFrequencyOf340RecursiveHelper(temp->getNext(), entry));
    } else {
        return ( getFrequencyOf340RecursiveHelper(temp->getNext(), entry));
    }
}

//getFrequencyOF340RecursiveNoHelper
template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType & entry) const {
    int count = 0;
    static Node<ItemType> *temp = headPtr;
    if (temp == NULL) {
        temp = headPtr;
        return 0;
    } else if (temp->getItem() == entry) {
        temp = temp->getNext();
        count++;
        return (count + getFrequencyOf340RecursiveNoHelper(entry));
    } else {
        temp = temp->getNext();
        return (count + getFrequencyOf340RecursiveNoHelper(entry));
    }
}

//removeRandom340
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
    Node<ItemType>* temp = headPtr;
    Node<ItemType>* temp2 = temp->getNext();
    int ram;
    if(temp == NULL){
        return 0;
    }

    for(int i = 1 ; i <= getCurrentSize340Iterative()  ; i++){
        ram = rand() % getCurrentSize340Iterative() + 1 ;
    }
    for(int i = 1 ; i <= (ram - 2) ; i++) {
        temp = temp->getNext();
    }

    ItemType removeItem = temp2->getItem();
    remove(removeItem);
    return removeItem;
}

























