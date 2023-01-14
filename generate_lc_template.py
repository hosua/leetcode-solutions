import sys
import os
import argparse

EXT='.cc'

"""
Generates file with common leetcode templates (or no template)
"""
if __name__ == "__main__":
    template = ""
    parser = argparse.ArgumentParser(description='lc generator',
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    
    parser.add_argument('-f', '--filename', required=True)
    parser.add_argument('-t','--tree', action='store_true', help='generate tree template')
    parser.add_argument('-sll','--singly-linked-list', action='store_true', help='generate singly linked list template')

    args = parser.parse_args()

    flags = {
            'filename':args.filename,
            'tree':args.tree,
            'sll':args.singly_linked_list,
    }

    filename = flags['filename']
    filename += EXT

    if flags['tree']:
        template += """// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
"""
    if flags['sll']:
        template += """// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 """
 


    output = """#include <bits/stdc++.h>
using namespace std;
""" + template + """
class Solution {
public:
};

int main(){
Solution sol;

}"""
    output.replace('\\n', '\n').replace('\\t', '\t')
    # print(output)

    if os.path.exists(os.path.basename(filename)):
        print(f"Error: \"{filename}\" already exists.")
    else:
        with open(filename, "w") as f:
            f.write(output)

        print(f"Created \"{filename}\"")

