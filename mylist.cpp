#include "mylist.h"


template<typename T>
MyList<T>::MyList(){
		head = nullptr;
		curr = nullptr;
		last = nullptr;
}

template<typename T>
void MyList<T>::push_back(T x){
	shared_ptr<Node> t = make_shared<Node>(x);
	if(!head){
		head = t;
		last = t;
	}
	else{
		last->next = t;
		last = t;
	}
}


template<typename T>
typename MyList<T>::iterator& MyList<T>::iterator::operator ++ (int){
	node = node->next;
	return *this;
}

template<typename T>
MyList<T>::~MyList(){
	cout<<"MyList DTOR\n";
}

int main(){
	MyList<int> list;
	list.push_back(5);list.push_back(6);list.push_back(7);
}