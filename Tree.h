#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
	Node *left;
	int info;
	Node *right;
		int maximumValueInLeftSubTree(Node *parent)//return the largest value in the tree
		{
			int temp;//temp variable to store the value before deleting the node
			if( hasRight() )//if it has right_child then
			{
				return right->maximumValueInLeftSubTree( this );//ask to right_child to return the value
			}
			else//if no more right_child then
			{
				temp = this->info;//store its value
				delete this;//delete this node
				parent->right = NULL;//and its parent's right_child to NULL as we have delete parent's right_child
			}
			return temp;//return the temp
			//here we are not going in its left because we are storing the max value in the right_child in parent, left_child and right_child
		}
	public:
		Node(int value)//normal constructor to initilise new node
		{
			this->left = NULL;//set left_child of node to NULL so that we can detact the end of the branch
			this->info = value;//set value to the information of the node
			this->right = NULL;//set right_child of node to NULL same as left_child
		}
		bool hasLeft()//returns true if a node has its left child otherwise false
		{
			if( this->left != NULL )//if node's left_child is not set to NULL then return true
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool hasRight()//returns true if a node has its right child otherwise false
		{
			if( this->right != NULL )//if right_child of node is not set to NULL then return true
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isLeft(Node *child)//this can be use as to detact some 'child' to check wheather it is the the left_child of the some another node
		{
			if( child == left)//if passed ( argument ) child is same as the node's left_child then return true means it is the left of this
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool isRight(Node *child)//check wheather it is right_child of this node or not
		{
			if( child == right)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		void addNode( int value )//use this function to append the tree family in auto arrange format
		{
			if( value < this->info )//if new node value is smaller than the parent node then
			{
				if( hasLeft() )//check if it has a left_child or not if yes
				{
					left->addNode( value );//then ask its left_child to add this new node in its family
				}
				else//otherwise 
				{
					left = new Node( value );//add this new node as its left_child
				}
			}
			else if ( value > this->info )//if new node value is greater than the parent node then
			{
				if( hasRight() )//check if it has right_child or not if yes
				{
					right->addNode( value );//then ask its right_child to add this new node its family
				}
				else//otherwise 
				{
					right = new Node( value );//add this new node as its right_child
				}
			}
		}
		bool contain( int value )//this function returns true if the passed 'value' is present in the tree otherwise false
		{
			//searching process
			if( this->info == value )//if this node's value is same as the passed value then
			{
				return true;//return true
			}
			else//otherwise
			{
				if( this->info > value )//if 'value' is smaller than the node value then it may be present in its left sub tree
				{
					if( hasLeft() )//if it has further left child then
					{
						left->contain( value );//ask its left child to search the value
					}
					else//otherwise the value is not present in the tree
					{
						return false;//hence return false
					}
				}
				else if( this->info < value )//if the value is greater than the node then
				{
					if( hasRight() )//check if it has any right_child or not if yes then
					{
						right->contain( value );//ask its right_child to search for the value
					}
					else//otherwise the value is not present in the tree as there is no more right child
					{
						return false;//return false
					}
				}
			}
		}
		bool replace( int oldValue, int newValue )//change the old value of node with new value if old value is present in the tree
		{
			if( this->info == oldValue )
			{
				this->info = newValue;
				return true;
			}
			else
			{
				if( this->info > oldValue )
				{
					left->replace( oldValue, newValue );
				}
				else
				{
					return false;
				}
				if( this->info < oldValue )
				{
					if( hasRight() )
					{
						right->replace( oldValue, newValue );
					}
					else
					{
						return false;
					}
				}
			}
		}
		bool removeNode( int nodeValue, Node *parent)//this will remove the node who's value is 'nodeValue' and its parent is 'parent'
		{
			if( this->info == nodeValue )//if we found the node
			{
				bool isLeftChild = parent->isLeft( this );//store if it is the left child of its parent
				bool isRightChild = parent->isRight( this );//store if it is the right child of its parent
				//we can have 3 cases while deleting a node from a BST tree
				//Case 1: when the deleting node has no further child
				if( !hasLeft() && !hasRight() )//check for no right and left child if has no child
				{
					if ( isLeftChild )//if it is left_child of its parent then
					{
						parent->left = NULL;//set parent left to NULL as we need to change the end of tree
						delete this;//now delete this node
						//order of setting parent's left and deleting the node can be any
					}
					else if ( isRightChild )//if it is the right_child of parent
					{
						parent->right = NULL;//set parent's right_child to NULL
						delete this;//delete this node
					}
				}
				//Case 2: one child ( Any of left or right )
				else if( ( hasLeft() && !hasRight() ) || ( !hasLeft() && hasRight() ) )//if it has one child
				{
					if( isLeftChild )//if this is the left child of its parent then
					{
						if( hasLeft() )//check if this node has left child or not if yes then
						{
							parent->left = this->left;//set parent's left child to this node's left child and
							delete this;//delete this node
						}
						else if( hasRight() )//check if this node has right child if yes then
						{
							parent->left = this->right;//set parent's left child to this node right child
							delete this;//delete this node
						}
					}
					else if( isRightChild )//if this is the right child of its parent then
					{
						if( hasLeft() )//check if this node has left child or not if yes then
						{
							parent->right = this->left;//set parent's right child to this node's left child and
							delete this;//delete this node
						}
						else if( hasRight() )//check if this node has right child if yes then
						{
							parent->right = this->right;//set parent's right child to this node right child
							delete this;//delete this node
						}
					}
				}
				//Case 3: Two children
				else if( hasLeft() && hasRight() )//check if this node has left_child as well as right child
				{
					this->info = left->maximumValueInLeftSubTree( this );//get the largest value if its left_child's family
					//and set to this node value and we have deleted the old node that had this largest value
					//in this way we have deleted a node and still managed the tree structure while deleting the node in between
				}
			}
			else//if we still not found out node then
			{
				if( nodeValue < this->info )//if this node's value is greater than the will deleted node's value
				{
					if( hasLeft() )//check if it has left child or not if yes then
					{
						left->removeNode( nodeValue, this );//ask its left_child to delete the node
					}
					else//otherwise
					{
						return false;//return false
					}
				}
				else if( nodeValue > this->info )//if this node's value is smaller than the will deleted node's value
				{
					if( hasRight() )//check if it has right_child or not if yes
					{
						right->removeNode( nodeValue, this );//then ask its right child to delete the node
					}
					else//otherwise return false as we did'nt find the node we wanted to delete
					{
						return false;
					}
				}
			}
		}
		std::vector<int>& preOrder()//returns a vector that has values of the tree in pre-order sequence(Parent -> Left -> Right)
		{
			static std::vector <int> preOrderValues;//to store the preorder
			preOrderValues.push_back( this->info );//push the parent into vector
			if( hasLeft() )//if it has left_child then
			{
				left->preOrder();//ask left child for preorder
			}
			if( hasRight() )//if it has right child then
			{
				right->preOrder();//ask right child for preorder
			}
			return preOrderValues;//at last return the preOrderValues that we have stored
		}
		std::vector<int>& inOrder()//returns a vector that has values of the tree in in-order sequence(Left -> Parent -> Right)
		{
			static std::vector <int> inOrderValues;
			if( hasLeft() )
			{
				left->inOrder();
			}
			inOrderValues.push_back( this->info );
			if( hasRight() )
			{
				right->inOrder();
			}
			return inOrderValues;
		}
  		std::vector<int>& postOrder()//returns a vector that has values of the tree in post-order sequence(Left-> Right -> Parent)
		{
			static std::vector <int> postOrderValues;
			postOrderValues.push_back( this->info );
			if( hasLeft() )
			{
				left->postOrder();
			}
			if( hasRight() )
			{
				right->postOrder();
			}
			return postOrderValues;
		}
		std::vector<int>& levelOrder()//returns a vector that has values of the tree in level-order sequence or Breadth first Search
		{
			static std::queue<Node*> nextNodes;//you can use vector as well insted of queue
			static std::vector<int> levelOrderValues;
			levelOrderValues.push_back(this->info);
			if( hasLeft() )
			{
				nextNodes.push( left );
			}
			if( hasRight() )
			{
				nextNodes.push( right );
			}
			if( nextNodes.size() != 0 )
			{
				Node *t = nextNodes.front();
				nextNodes.pop();
				t->levelOrder();
			}
			return levelOrderValues;
		}
};



