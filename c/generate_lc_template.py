import sys
import os
import argparse

EXT='.c'

"""
Generates file with common leetcode templates (or no template)
"""
if __name__ == "__main__":
    template = ""
    parser = argparse.ArgumentParser(description='lc generator',
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    
    parser.add_argument('file')
    parser.add_argument('-t','--tree', action='store_true', help='generate tree template')
    parser.add_argument('-sll','--singly-linked-list', action='store_true', help='generate singly linked list template')

    args = parser.parse_args()

    flags = {
            'file':args.file,
            'tree':args.tree,
            'sll':args.singly_linked_list,
    }
    
    filename = flags['file']
    filename += EXT

    if flags['tree']:
        template += """// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
};
"""
    if flags['sll']:
        template += """// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
 };
 """
 


    output = """#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
""" + template + """

int main(){

}
"""
    output.replace('\\n', '\n').replace('\\t', '\t')
    # print(output)

    if os.path.exists(os.path.basename(filename)):
        print(f"Error: \"{filename}\" already exists.")
    else:
        with open(filename, "w") as f:
            f.write(output)

        print(f"Created \"{filename}\"")

