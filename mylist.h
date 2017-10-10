#include<iostream>
#include <memory>
using namespace std;

template<typename T>
class MyList{
	struct Node{
		T data;
		shared_ptr<Node> next;
		Node(T d, Node* n = nullptr):data(d),next(n){}
		~Node(){ std::cout<< "Deleting "<<data<<std::endl;}
	};

	shared_ptr<Node> head;
	shared_ptr<Node> curr;
	shared_ptr<Node> last;
	
public:
	MyList<T>();
	~MyList<T>();
	void push_back(T);
	
	class iterator{
		shared_ptr<Node> node;
		friend class MyList<T>;
	public:
		iterator& operator ++ (int);
		shared_ptr<Node> operator->(){return node;};
		
	};
};
