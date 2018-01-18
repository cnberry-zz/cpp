#include <vector>
#include <algorithm>
#include <iostream>

#pragma once
namespace ds
{
    class graph {

	struct node_t {
		int _id;
		std::vector<std::vector<node_t>::iterator> _alist;

		node_t(int& i) : _id(i) {}										//constructor
		bool operator==(const int val) const {return val == this->_id;} //equal to int for node id search using std::find()
            
	};

    private:

        std::vector<node_t> _vlist;
		int _current_id;

    public:

		typedef std::vector<node_t>::iterator iterator;
		
        graph() {

            _current_id = 0;

        }

        ~graph() {
			//vector mangages deleting for all nodes
        }

		int addNode() {
			node_t v(_current_id);
			_current_id++;
			_vlist.push_back(v);
			return v._id; 
		}

		void addEdge(int id1, int id2) {
		
			iterator v1 = std::find(this->_vlist.begin(),this->_vlist.end(),id1);
			if ( v1 == _vlist.end() ) {
				std::cout << "id: " << id1 << " could not be found in vertex list. Not attempting to add edge"<<std::endl;
				return;
			}

			iterator v2 = std::find(this->_vlist.begin(),this->_vlist.end(),id2);
			if ( v2 == _vlist.end() ) {
				std::cout << "id: " << id1 << " could not be found in vertex list. Not attempting to add edge"<<std::endl;
				return;
			}

			//Add iterators to each others adjacency list (undirected)
			v1->_alist.push_back(v2);
			v2->_alist.push_back(v1);
		}

		// print adjancy list of each node in vertex list
		void print() {

			for (auto i : _vlist) {
				std::cout << i._id <<": ";
				for (auto j : i._alist) {
					std::cout << (*j)._id << " ";	
				}
				std::cout << std::endl;
			}

		}

		// print each node id using dfs traverse starting at id
		void dfsPrint(int id) {


		}


		// print each node id using bfs traverse starting at id
		void bfsPrint(int id) {



		}

    };
}

