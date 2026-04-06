int Floor(BinaryTreeNode<int> *node, int input)
{
	if(!node) return -1;

	int floor = -1;
	BinaryTreeNode<int>* temp = node;
	while(temp!=NULL){
		if(temp->data == input){
			return input;
		}
		else if(temp->data > input){
			temp = temp->left;
		}
		else if(temp->data < input){
			floor = temp->data;
			temp = temp->right;
		}
	}

	return floor;
}
