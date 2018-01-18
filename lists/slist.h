namespace lists
{    
    template<class T> 
    struct node {
        T data;
        node<T>* next;
    };

	template <class T>
	struct node_iter {
    	node<T>* current;

    	node_iter(node<T>* current): current(current) {}								// constructor from node_ptr
    	const node_iter& operator++() { current = current->next; return *this; } 		// pre increment
    	node_iter operator++(int) {node_iter result = *this; ++(*this); return result;} // post increment
        
    	T& operator*() { return current->data; }
	};

    template<class _Type>
    class slist {

    public:
        typedef node<_Type>* node_ptr;

    private:
        typedef node<_Type> _node;
        node_ptr _root;

    public:

        slist() 
		{
            _root = new _node();
            _root->next = nullptr;
        }

        ~slist() 
		{
            while (_root && _root->next) {
                remove_after(_root);
            }

            delete _root;

            _root = nullptr;
        }

		/* Iterator not working. Use node_ptr instead. Need to investigate 
        node_iter<_Type>& begin() {return &node_iter<_Type>(this->_root->next);}
        node_iter<_Type>& end() {return &node_iter<_Type>(nullptr); }
		*/

        node_ptr begin() {return this->_root->next;}
        node_ptr end() {return nullptr; }
            
		void print() 
		{
			for (node_ptr i = begin(); i != end(); i = i->next)
					std::cout << i->data << " ";
			std::cout << std::endl;
		}

        void push_front(const _Type& value) 
		{
			insert_after(_root,value);
        }

        void pop_front() 
		{
			remove_after(_root);
        }

		/* _root->...->node->insert->...->nullptr */
        void insert_after(node_ptr node, const _Type& value)
        {
			node_ptr inserted = new _node();
			inserted->data = value;
			inserted->next = node->next;
			node->next = inserted;
			
        }

		/* _root->...->node->remove->...->nullptr */
        void remove_after(node_ptr node)
        {
			node_ptr removed = node->next;
			node->next = removed->next; 

			delete removed;
			
        }

        void reverse()
        {
        }
    };
}
