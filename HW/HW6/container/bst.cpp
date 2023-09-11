#include <iostream>
#include "bst.h"

using namespace std;

void BST::Insert(int key) {
  Node* z = new Node(key);

  Node* x = this->root;
  Node* y = NULL;

  while (x != NULL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  // found the location - insert z with parent y
  z->parent = y;

  if (y == NULL) {
    root = z;
  }
  else if (z->key < y->key) {
    y->left = z;
  }
  else {
    y->right = z;
  }
}

// #include <iostream>

// // swap
// void swap(int *a, int *b){
//   int temp = *b;
//   *b = *a ;
//   *a = temp; 
// }

// int main() {
//     int one = 8;
//     int two = 4;
//     int *a = &one;
//     int *b = &two;
    
//     std::cout << "a: " << *a << " b: " << *b << '\n';
    
//     std::cout << "After swapping: \n";
    
//     swap(a, b) ;
    
//     std::cout << "a: " << *a << " b: " << *b;
// }

//pointer가 들어가면 그 u (address장소) 에 다른 값이 들어갈뿐이다. address는 같은 variable이 지칭하는 상태로 유지됨 (위의 swap fn으로 생각해보자)
void BST::transplant(Node* u, Node* v) {
    //Node replacement: u is replaced by v 
    if (u->parent == NULL) {
        root = v; // If u is the root, set v as the new root
    } else if (u == u->parent->left) {
        u->parent->left = v; // If u is the left child of its parent, set v as the new left child
    } else {
        u->parent->right = v; // If u is the right child of its parent, set v as the new right child
    }

    // Parent Pointer update 
    // v가 vaild한 node이면 u를 replace할 수 있게 된다. 
    if (v != NULL) {
        v->parent = u->parent; // Update the parent pointer of v to point to u's parent
    }
}


void BST::Delete(Node* z) {
  Node* y;

	if (z->left == NULL) {
		transplant(z, z->right);
	}
  else if (z->right == NULL) {
		transplant(z, z->left);
	}
  else { // 여기서 delete와 transplant에 들어가는 parameter들은 pointer이기 때문에 그 address
		y = Minimum(z->right);
		if (y->parent != z) { // y is not the immediate right child of z , we need to adjust the structure to ensure BST property 
			transplant(y, y->right); // y에 붙어있는 y->right을 먼저 떼줘야 y의 subtree를 아래서 설정할 수 있음 
			y->right = z->right;   // y의 right child를 z의 right child로 설정함. 
			y->right->parent = y;   // parent 관계를 재 설정 
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}

void BST::Preorder(Node* node) {
  if (node != NULL) {
    cout << node->key << " ";
    Preorder(node->left);
    Preorder(node->right);
  } 
}

void BST::Inorder(Node* node) {
  if (node != NULL) {
    Inorder(node->left);
    cout << node->key << " ";
    Inorder(node->right);
  } 
}

void BST::Postorder(Node* node) {
  if (node != NULL) {
    Postorder(node->left);
    Postorder(node->right);
    cout << node->key << " ";
  } 
}

BST::Node* BST::Search(Node* node, int key) {
  if (node == NULL || key == node->key) {
    return node;
  }

  if (key < node->key)
    return Search(node->left, key);
  else
    return Search(node->right, key);
}

BST::Node* BST::Maximum(Node* node) {
  while (node->right != NULL) {
    node = node->right;
  }
  return node;
}

BST::Node* BST::Minimum(Node* node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

BST::Node* BST::Successor(Node* x) {
  if (x->right != NULL) {
    return Minimum(x->right);
  }

  Node* y = x->parent;
  while (y != NULL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

BST::Node* BST::Predecessor(Node* x) {
  if (x->left != NULL) {
    return Maximum(x->left);
  }

  Node* y = x->parent;
  while (y != NULL && x == y->left) {
    x = y;
    y = y->parent;
  }
  return y;
}

void BST::_print(Node* root, string indent, bool last) {
  if (root != NULL) {
    cout << indent;
    if (last) {
      cout << "└────";
      indent += "     ";
    } else {
      cout << "├────";
      indent += "|    ";
    }

    cout << root->key << endl;

    _print(root->left, indent, false);
    _print(root->right, indent, true);
  }
}

void BST::Print() {
  if (GetRoot() != NULL)
    _print(GetRoot(), "", true);
}
