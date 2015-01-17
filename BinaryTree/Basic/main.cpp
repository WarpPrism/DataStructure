#include <iostream>
#include <cstdlib>
#include "BTree.h"
using namespace std;

char getCommand();
bool doCommand(char c, BTree T);
void Instruction();
void ATree();
void Info();
void Heart();

int main() {
	cout << endl;
	Info();
	cout << "This program is a testing program for binary tree." << endl;
	cout << "And the first thing you need to do is initiallizing the Tree." << endl;
	ATree();
	BTree T;
	BTreeNode *start;
	cout << "Now please input the root value." << endl;
	start = T.createBTree();
	T.setRoot(start);
	cout << "Congratulations!" << endl;
	cout << "The Tree is initialized now." << endl;
	Instruction();
	while (doCommand(getCommand(), T));
    // delete start;
	// system("pause");
	T.deleteroot(start);
	T.~BTree();
	return 0;
}

char getCommand() {
	char c;
	bool check = false;
	cout << "Please input a character as a command." << endl;
	do {
		cin >> c;
		if (c == 'I' || c == 'i' || c == 'P' || c == 'p' ||
			c == 'O' || c == 'o' || c == 'S' || c == 's' ||
			c == 'H' || c == 'h' || c == 'Q' || c == 'q' ||
			c == 'L' || c == 'l' || c == 'F' || c == 'f' ||
			c == 'T' || c == '~' || c == '?') {
			cout << "Command is legal." << endl;
			check = true;
		}
		else {
			cout << "Command undefined!" << endl
				<< "Please Input again!" << endl;
			check = false;
		}
	} while (!check);
	return c;
}

bool doCommand(char c, BTree T) {
	bool ifcontinue = true;
	switch (c) {
	case 'F':
    case 'f':
        cout << "==> Search the tree to find the data." << endl;
        cout << "Please input the data you want to search." << endl;
        cout << "And you will get the address of the data." << endl;
        int t;
        BTreeNode *r;
        cin >> t;
        r = T.getRoot();
        // cout << r << endl;
        cout << "Address: " << T.findData(t, r) << endl;
        if (T.findData(t, r) == 0) {
        	cout << "As you see, the address is 0. So data " << t << " doesn't exist." << endl;
        }
        break;
	case 'I':
		cout << "==> Recursion InOrder Traversal." << endl;
		T.inOrder();
		break;
	case 'i':
		cout << "==> Not Recursion Inorder Traversal." << endl;
		T.NotReInOrder();
		break;
	case 'P':
		cout << "==> Recursion PreOrder Traversal." << endl;
		T.preOrder();
		break;
	case 'p':
		cout << "==> Not Recursion PreOrder Traversal." << endl;
		T.NotRePreOrder();
		break;
	case 'O':
		cout << "==> Recursion PostOrder Traversal." << endl;
		T.postOrder();
		break;
	case 'o':
		cout << "==> Not Recursion PostOrder Traversal." << endl;
		T.NotRePostOrder();
		break;
	case 'S':
	case 's':
		cout << "==> BTree Size." << endl;
		cout << T.BTreeSize() << endl;
		break;
	case 'L':
	case 'l':
		cout << "==> BTree Leaves." << endl;
		cout << T.BTreeLeaves() << endl;
		break;
	case 'H':
	case 'h':
		cout << "==> BTree Height." << endl;
		cout << T.BTreeHeight() << endl;
		break;
	case '?':
		Instruction();
		break;
	case 'Q':
	case 'q':
		cout << "End the Test." << endl;
		// Heart();
		ifcontinue = false;
		break;
	case 'T':
	    ATree();
	    cout << endl;
	    cout << "So many bugs````" << endl;
	    break;
	case '~':
	    // Info();
	    Heart();
	    cout << "Can I join into your Life?" << endl;
	    cout << "Can I chat with you?" << endl;
	    cout << "Can I love you?" << endl;
	    break;
	default:
		break;
	}
	return ifcontinue;
}

void Instruction() {
	cout << "============================================================" << endl;
	cout << "Help Screen" << endl;
	cout << "Valid Command:" << endl;
	cout << "F or f ==> Search the tree to find the data." << endl;
	cout << "I ==> Recursion InOrder Traversal." << endl;
	cout << "i ==> Not Recursion Inorder Traversal." << endl;
	cout << "P ==> Recursion PreOrder Traversal." << endl;
	cout << "p ==> Not Recursion PreOrder Traversal." << endl;
	cout << "O ==> Recursion PostOrder Traversal." << endl;
	cout << "o ==> Not Recursion PostOrder Traversal." << endl;
	cout << "S or s ==> BTree Size." << endl;
	cout << "L or l ==> BTree Leaves." << endl;
	cout << "H or h ==> BTree Height." << endl;
	cout << "Q or q ==> Quit The Program." << endl;
	cout << "? ==> This Help Screen." << endl;
	cout << "~ ==> `````````````" << endl;
	cout << "============================================================" << endl;
}

void ATree() {
    cout << "            /_\\" << endl;
    cout << "           /_\\_\\" << endl;
    cout << "          /_/_/_\\" << endl;
    cout << "          /_\\_\\_\\" << endl;
    cout << "         /_/_/_/_\\" << endl;
    cout << "         /_\\_\\_\\_\\     Just For Fun! @_@" << endl;
    cout << "        /_/_/_/_/_\\" << endl;
    cout << "        /_\\_\\_\\_\\_\\" << endl;
    cout << "       /_/_/_/_/_/_\\" << endl;
    cout << "       /_\\_\\_\\_\\_\\_\\" << endl;
    cout << "      /_/_/_/_/_/_/_\\" << endl;
    cout << "           [___]" << endl;
}

void Info() {
    cout << "|=======================================|" << endl;
    cout << "|                                       |" << endl;
    cout << "|              Binary Tree              |" << endl;
    cout << "|           Author:WarpPrism            |" << endl;
    cout << "|               2014.12.1               |" << endl;
    cout << "|                                       |" << endl;
    cout << "|=======================================|" << endl;
}

void Heart() {
	cout << "         niwe            gpod            " << endl;
	cout << "      sqstruesdq      jvswarmqwe         " << endl;
	cout << "     ogivemepassideslonmayigetint        " << endl;
	cout << "     woyourheartbemygirlfriendokw        " << endl;
	cout << "     eijustwanttobeyoursideandgir        " << endl;
	cout << "      rvemewhatihaveletusstepint         " << endl;
	cout << "       jtusdfcvghjdfgasdfgvfert          " << endl;
	cout << "        vsasdwvbcaniownyourhea           " << endl;
	cout << "         byouarebeautifulrigh            " << endl;
	cout << "          dtvbhfransfergniet             " << endl;
	cout << "            cdqwesdvfgbnsd               " << endl;
	cout << "              eswasdwssd                 " << endl;
	cout << "                 ader                    " << endl;
	cout << "                  y                      " << endl;
}
