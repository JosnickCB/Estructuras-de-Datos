#include <iostream>

template <typename T>
class node
{
	private:
		T key;
		node *left , *right;
	public:
		node( T );
		node* get_address( );
		node* get_left( );
		node* get_right( );
		T get_key( );
		void set_key( T );
		void set_left( node<T>* );
		void set_right( node<T>* );
		void print( );
};

template <typename T>
node<T>::node( T key )
{
	this->key = key;
	left = right = nullptr;
}

template <typename T>
node<T>* node<T>::get_address( )
{
	return this;
}

template <typename T>
node<T>* node<T>::get_left( )
{
	return left;
}

template <typename T>
node<T>* node<T>::get_right( )
{
	return right;
}

template <typename T>
void node<T>::set_left( node<T>* new_address )
{
	left = new_address;
}

template <typename T>
void node<T>::set_right( node<T>* new_address )
{
	right = new_address;
}

template <typename T>
void node<T>::set_key( T new_key )
{
	key = new_key;
}

template <typename T>
void node<T>::print( )
{
	std::cout << "<< Direccion :[" << this << "] ";
	std::cout << "Data :[" << key << "] - ";
	std::cout << "Left :[" << left << "] - ";
	std::cout << "Right :[" << right << "] >>\n";
}

template <typename T>
class avl
{
	private:
		node<T>* root;
		void insert( node<T>*& , T );
	public:
		avl();
		void insert( T );
		void print( );
};

template <typename T>
avl<T>::avl(){
	root = nullptr;
}

template <typename T>
void avl<T>::insert( node<T>*& root , T new_key)
{
	if(root == nullptr)
	{
		root = new node<T>(new_key);
	}
	else if( new_key < root->get_key() )
	{
		insert( root->get_left() , new_key );
	}
	else if( new_key > root->get_right() )
	{
		insert( root->get_right() , new_key );
	}else{
		std::cout << "Already exists" << std::endl;
	}
}

template <typename T>
void avl<T>::insert( T new_key)
{
	std::cout << "ROOT : "<< root << std::endl;
	if(root == nullptr){
		root = new node<T>( new_key );
	}else{
		if ( new_key < root->get_key() )
		{
			insert( root->get_left() , new_key );
		}else if ( new_key > root->get_key() )
		{
			insert( root->get_right() , new_key );
		}else{
			std::cout << "Already exists" << std::endl;
		}
	}
}

int main(int argc, char const *argv[]){
	node<int> my_node(2);
	node<int> the_node(3);
	my_node.print();
	the_node.print();
	//std::cout << my_node.get_left() << std::endl;
	my_node.set_right(the_node.get_address());
	my_node.print();
	avl<int> my_avl;
	my_avl.insert(6);
	return 0;
}