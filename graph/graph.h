#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#pragma once
namespace ds
{
    class graph {

	struct node_t {
		int id;
		bool visited;
		std::vector<std::vector<node_t>::iterator> alist;

		node_t(int i) : id(i),visited(false) {}							//constructor - must take id
		//~node_t() { std::cout << "~" << this->id << std::endl;}			//DEBUG destructor - see how many copies there are!
		bool operator==(const int val) const {return val == this->id;} //equal to int for node id search using std::find()
            
	};

    private:

        std::vector<node_t> _vlist;
		int _current_id;

    public:

		typedef std::vector<node_t>::iterator iterator;
		
        graph() : _current_id(0) {

        }

		/*
        ~graph() {
			//vector mangages deleting for all nodes
        }
		*/

		iterator begin() {
			return this->_vlist.begin();
		}

		iterator end() {
			return this->_vlist.end();
		}

		int addNode() {
			/// This will show the vector grow each time a node is added this
			//expains why we see the node destructor called during addNode.
			//the vector starts with capacity of 0. then 1. then 2. then 4.
			//std::cout << "cap: " << _vlist.capacity() << std::endl;
			this->_vlist.emplace_back(_current_id);
			return _current_id++; 
		}

		void addEdge(int id1, int id2) {
		
			iterator it1 = std::find(this->begin(),this->end(),id1);
			iterator it2 = std::find(this->begin(),this->end(),id2);

			//Add iterators to each others adjacency list (undirected)
			it1->alist.push_back(it2);
			it2->alist.push_back(it1);
		}

		// print adjancy list of each node in vertex list
		void print() {

			for (auto &i : this->_vlist) {
				std::cout << "    " << i.id << ": ";
				for (auto &j : i.alist) {
					std::cout << j->id << " ";	
				}
				std::cout << std::endl;
			}

		}

		void clearVisited() {
			
			for (auto &i : this->_vlist) {
				i.visited = false;
			}

		}

		// print each node id using dfs traverse starting at id
		void dfsPrint(int id) {
			// Find id in vlist, then recurese over each node in alist.
			iterator it = std::find(this->begin(),this->end(),id);
			
			std::cout << "dfs : ";	
			dfsRecurse(it);
			std::cout << std::endl;

			// reset graph for next traverse
			this->clearVisited();

		}

		void dfsRecurse(iterator& it) {

			// terminal condition for loops
			if ( it->visited ) { 
				return;
			}

			// "visitor" function - just print node
			std::cout << it->id << " ";
			it->visited = true;

			for (auto i : it->alist) {
				dfsRecurse(i);
			}
				
		}


		// print each node id using bfs traverse starting at id
		void bfsPrint(int id) {
			std::queue<iterator> q;
			iterator it = std::find(this->begin(),this->end(),id);

			std::cout << "bfs : ";	
			q.push(it);
			while ( not q.empty() ) {

				it = q.front();
				q.pop();
				if ( not it->visited ) {
					// "visitor" - just print
					std::cout << it->id << " ";
					it->visited = true;
					for (auto &i : it->alist) {
						q.push(i);
					}
				}

			}
			std::cout << std::endl;	

			// reset graph for next traverse
			this->clearVisited();
		}

    };
}

