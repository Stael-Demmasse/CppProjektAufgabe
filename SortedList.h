/*
 * Stack.h
 *
 *  Created on: 13.12.2023
 *      Author: User
 */


#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_

#include<concepts>
#include<memory>
#include<iostream>

using namespace std;

template<typename T>

concept to = std::totally_ordered<T>;

template<to T>

class SortedList {

private:

	class ListItem{

	public:

		  T value;

		  unique_ptr<ListItem> lNext;

		  ListItem(T value, unique_ptr<ListItem> lNext = nullptr){

		  }


	};

	unique_ptr<ListItem> head;

	void rekInsert(const unique_ptr<ListItem>& lAct);



public:
	SortedList();
	virtual ~SortedList()= default;
	SortedList(const SortedList &other);
	SortedList(SortedList &&other)=default;
	SortedList& operator=(const SortedList &other);
	SortedList& operator=(SortedList &&other)=default;


	void insert(const T& value);

	T getFist();

	bool isEmpty();

};

// konstruktor fuer neue ListItem
template<to T>
 SortedList<T>::ListItem::ListItem(T value, unique_ptr<ListItem> lNext ): value{value}, lNext { move(lNext)} {


}

//konstruktor fuer leere liste
template<to T>
 SortedList<T>::SortedList() : head { nullptr } {


}

//template<to T>
//inline SortedList<T>::~SortedList() {
//}


//kopie construktor
template<to T>
 SortedList<T>::SortedList(const SortedList &other) {

	rekInsert(other.head);
}



//template<to T>
//inline SortedList<T>::SortedList(SortedList &&other) {
//}

template<to T>
 SortedList& SortedList<T>::operator =(const SortedList &other) {

	if(this == &other){

		return *this;
	}
	rekInsert(other.head);

	return *this;

}

template<to T>
 void SortedList<T>::rekInsert(const unique_ptr<ListItem> &lAct) {


	   if (!lAct || value < lAct->value) {
	            auto newElement = make_unique<ListItem<T>>(value);
	            newElement->next = move(lAct);
	            lAct = move(newElement);
	        } else {
	            rekInsert(lAct->next, value);
	        }



}

//template<to T>
//inline SortedList& SortedList<T>::operator =(SortedList &&other) {
//}

template<to T>
 void SortedList<T>::insert(const T& value) {

	 rekInsert(head, value);

}

template<to T>
 T SortedList<T>::getFist() const {
	   if (!head) {
	            throw std::out_of_range("getFirst: empty List");
	        }
	        return head->value;

}
template<to T>
bool SortedList<T>::isEmpty() const {
       return !head;
   }

friend std::ostream& operator<<(std::ostream& os, const SortedList& list) {
       auto lAct = list.head.get();
       while (lAct) {
           os << lAct->data << " ";
           lAct = lAct->next.get();
       }
       return os;
   }

#endif /* SORTEDLIST_H_ */
